/**
 * copyright @2016. all rights reserved.
 *
 * @since:  11:10 8/19/16
 * @author: xiangyun kong
 *
 * description:
 *
 */

#include "thread.hpp"

#include <string>

using namespace std;

#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>

#include <lib/convert/type_convert.hpp>

namespace kxy {
    
    thread::thread() {
        string name;
        name = l2s((long)this) + ".changing";
        m_status_changing = sem_open(name.c_str(), O_CREAT, 0644, 0);
        name = l2s((long)this) + ".changed";
        m_status_changed = sem_open(name.c_str(), O_CREAT, 0644, 0);
        change_status(pending);
        pthread_create(&m_thread, nullptr, thread::thread_func, this);
    }
    
    thread::~thread() {

    }

    void* thread::thread_func(void *param) {
        thread* obj= (thread*)param;
        while (obj->status() != stopped) {
            obj->update_status();
            if (obj->status() == running) {
                obj->run_once();
            } else {
                sem_wait(obj->m_status_changing);
            }
        }
        return (void*)obj->m_thread;
    }
    
    long thread::pause() {
        if (m_status == running) {
            change_status(pausing);
            wait_status();
            return 0;
        }
        return -1;
    }
    
    long thread::resume() {
        if (m_status == paused || m_status == pending) {
            change_status(resuming);
            wait_status();
            return 0;
        }
        return -1;
    }
    
    void thread::update_status() {
        long old_status = status();

        long exchange = pausing;
        m_status.compare_exchange_strong(exchange, paused);

        exchange = resuming;
        m_status.compare_exchange_strong(exchange, running);

        exchange = stopping;
        m_status.compare_exchange_strong(exchange, stopped);
        
        if (status() != old_status) {
            sem_post(m_status_changed);
        }
    }

    void thread::change_status(thread_status s) {
        m_status = s;
        if (s == pausing || s == resuming || s == stopping) {
            sem_post(m_status_changing);
        }
    }

    void thread::wait_status() {
        while (true) {
            thread_status s = status();
            if (s == pending || s == paused || s == running || s == stopped) {
                break;
            }
            sem_wait(m_status_changed);
        }
    }

    void thread::kill_thread() {
        if (m_thread != 0) {
            change_status(stopping);
            wait_status();
            m_thread = 0;
        }
    }

    thread_status thread::status() {
        return (thread_status)(long)m_status;
    }
    
    pthread_t thread::thread_id() const {
        return m_thread;
    }
    
}