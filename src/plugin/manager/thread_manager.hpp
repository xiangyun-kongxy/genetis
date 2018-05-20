//
//  thread_manager.hpp
//  plugin
//
//  Created by xiangyun.kong on 10/27/17.
//  Copyright © 2017 孔祥云. All rights reserved.
//

#ifndef thread_manager_hpp
#define thread_manager_hpp

#include <stdio.h>

#include <lib/thread/thread.hpp>
#include <lib/lock/spinlock.hpp>

#include <plugin/plugin/plugin.hpp>

using namespace kxy;

namespace pf {

    class thread_manager {
    private:
        friend class plugin;

        thread_manager();
        ~thread_manager();

    public:
        static thread_manager* instance();

    private:
        pthread_t create_thread_for_plugin(ptr<plugin> owner);
        void delete_thread(pthread_t thread);
        void suspend_thread(pthread_t thread);
        void resume_thread(pthread_t thread);

    public:
        void enable_help_thread(ptr<plugin> pl);
        void disable_help_thread(ptr<plugin> pl);

    public:
        ptr<plugin> current_plugin();
        ptr<event> current_task();

    private:
        static void __destroy_thread_context(void*);

    private:
        map<pthread_t, ptr<thread>> m_threads;
        static thread_manager* g_thread_manager;

        pthread_key_t m_thread_context_key;
    };
    
}

#endif /* thread_manager_hpp */
