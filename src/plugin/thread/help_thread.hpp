//
//  help_thread.hpp
//  plugin
//
//  Created by xiangyun.kong on 10/27/17.
//  Copyright © 2017 孔祥云. All rights reserved.
//

#ifndef help_thread_h
#define help_thread_h

#include "plugin_thread.hpp"

#include <unistd.h>

#include <lib/thread/thread.hpp>
#include <lib/container/cqueue.hpp>

#include <plugin/response/response.hpp>
#include <plugin/event/event.hpp>
#include <plugin/event/simple_event.hpp>
#include <plugin/plugin/plugin.hpp>

#include <messages.hpp>

#include <mutex>

using namespace std;
using namespace kxy;

namespace pf {

    class help_thread : public plugin_thread {
    public:
        DECLARE_TYPE(thread, OBJ_HELP_THREAD);

    public:
        help_thread() : plugin_thread(nullptr, nullptr) {
        }

        virtual ~help_thread() {
            kill_thread();
        }

    public:
        virtual void* run_once() override {
            if (get_task())
                do_task();
            return nullptr;
        }

        void add_helping(ptr<plugin> plugin, ptr<cqueue<ptr<object>>> pool) {
            lock_guard<mutex> _(m_mutex);

            m_helping[plugin] = pool;
        }

        void rm_helping(ptr<plugin> plugin) {
            lock_guard<mutex> _(m_mutex);

            m_helping.erase(plugin);
        }

        long helping_count() {
            lock_guard<mutex> _(m_mutex);
            return m_helping.size();
        }

    protected:
        bool get_task() {
            m_cur_task = nullptr;
            m_owner = nullptr;
            do {
                lock_guard<mutex> _(m_mutex);

                container::iterator i;
                for (i = m_helping.begin(); i != m_helping.end(); ++i) {
                    if (i->second->size() > 0) {
                        m_cur_task = i->second->try_pop();
                        if (m_cur_task != nullptr) {
                            m_owner = i->first;
                            break;
                        }
                    }
                }
            } while (0);

            return m_cur_task != nullptr;
        }

    protected:
        typedef map<ptr<plugin>, ptr<cqueue<ptr<object>>>> container;

        mutex m_mutex;
        container m_helping;
    };
    
}


#endif /* help_thread_h */
