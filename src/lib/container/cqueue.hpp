//
//  cqueue.h
//  lib
//
//  Created by 孔祥云 on 11/10/16.
//  Copyright © 2016 孔祥云. All rights reserved.
//

#ifndef cqueue_h
#define cqueue_h

#include <sys/fcntl.h>
#include <semaphore.h>
#include <queue>

#include <lib/object/object.hpp>
#include <lib/lock/spinlock.hpp>

#ifdef OS_MACOSX
#include <lib/lock/sem_osx.hpp>
#endif

using namespace std;

namespace kxy {
    
    template<typename ty>
    class cqueue : public object {
    public:
        DECLARE_TYPE(object, OBJ_CQUEUE);
        
    public:
        cqueue() {
            m_sem = sem_open(to_string((long)this).c_str(), O_CREAT, 0644, 0);
        }
        
        virtual ~cqueue() {
        }
        
    public:
        void push(ty value) {
            m_mutex.lock();
            if (0 == sem_post(m_sem)) {
                m_container.push(value);
            }
            m_mutex.unlock();
        }
        
        ty pop() {
            ty result = ty();
            struct timespec ts;
            if (clock_gettime(CLOCK_REALTIME, &ts) != -1) {
                ts.tv_sec += 1;
                if (sem_timedwait(m_sem, &ts) == 0) {
                    m_mutex.lock();
                    if (m_container.size() > 0) {
                        result = m_container.front();
                        m_container.pop();
                    }
                    m_mutex.unlock();
                }
            }
            return result;
        }

        ty try_pop() {
            ty result = ty();
            m_mutex.lock();
            if (m_container.size() > 0) {
                result = m_container.front();
                m_container.pop();
            }
            m_mutex.unlock();
            return result;
        }

        ty front() {
            ty result;
            m_mutex.lock();
            if (m_container.size() > 0) {
                result = m_container.front();
            }
            m_mutex.unlock();
            return result;
        }

        long size() {
            return m_container.size();
        }
        
    private:
        spin_mutex m_mutex;
        queue<ty> m_container;
        
        sem_t* m_sem;
    };
}

#endif /* cqueue_h */
