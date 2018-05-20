//
//  plugin_thread.hpp
//  plugin
//
//  Created by xiangyun.kong on 10/27/17.
//  Copyright © 2017 孔祥云. All rights reserved.
//

#ifndef plugin_thread_h
#define plugin_thread_h


#include <unistd.h>

#include <lib/thread/thread.hpp>
#include <lib/container/cqueue.hpp>

#include <plugin/response/response.hpp>
#include <plugin/event/event.hpp>
#include <plugin/event/simple_event.hpp>
#include <plugin/plugin/plugin.hpp>

#include <messages.hpp>

using namespace std;
using namespace kxy;

namespace pf {

    class plugin_thread : public thread {
    public:
        DECLARE_TYPE(thread, OBJ_PLUGIN_THREAD);

    public:
        plugin_thread(ptr<cqueue<ptr<object>>> pool, ptr<plugin> owner) {
            m_owner = owner;
            m_pool = pool;
            m_cur_task = nullptr;
        }

        virtual ~plugin_thread() {
            change_status(stopping);
            wait_status();
        }

    public:
        virtual void* run_once() override {
            m_cur_task = m_pool->pop();
            if (m_cur_task != nullptr)
                do_task();
            return nullptr;
        }

        ptr<cqueue<ptr<object>>> pool() const {
            return m_pool;
        }

        ptr<plugin> owner() const {
            return m_owner;
        }

        ptr<object> cur_task() const {
            return m_cur_task;
        }

    protected:
        void update_thread_task() {
            void *old;
            old = set_thread_attr("current_plugin", &m_owner);
            if (old != nullptr)
                ptr<plugin> old_plugin = *(ptr<plugin>*)old;
            old = set_thread_attr("current_task", &m_cur_task);
            if (old != nullptr)
                ptr<event> old_task = *(ptr<event>*)old;
        }

        void do_task() {
            update_thread_task();

            ptr<response> rsp = m_owner->do_task(m_cur_task);
            if (rsp != nullptr) {
                extern ptr<plugin> g_ps;
                g_ps->tasks()->push(rsp);
            }
        }

    protected:
        ptr<cqueue<ptr<object>>> m_pool;
        ptr<plugin> m_owner;
        ptr<event> m_cur_task;
    };

}

#endif /* plugin_thread_h */
