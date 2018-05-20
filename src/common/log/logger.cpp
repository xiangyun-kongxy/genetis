//
//  logger.cpp
//  common
//
//  Created by 孔祥云 on 10/21/17.
//  Copyright © 2017 xiangyun.kong. All rights reserved.
//

#include "logger.hpp"

#include <plugin/manager/thread_manager.hpp>

#include <log.hpp>

#include <unistd.h>

using namespace pf;

namespace kxy {
    
    logger::logger(FILE* fd, log_level level) {
        m_fd = fd;
        m_level = level;
        pthread_create(&m_thread, nullptr, logger::_commit_log, this);
    }
    
    logger::~logger() {
        pthread_cancel(m_thread);
        _commit_log(this);
        fclose(m_fd);
    }
    
    void logger::debug(const string& msg) {
        if (logs::get_logger("debug") != this) {
            logs::get_logger("debug")->debug(msg);
        }

        if (m_level >= LL_DEBUG) {
            string plugin_name = "none";
            string task_name = "none";
            ptr<plugin> pl = thread_manager::instance()->current_plugin();
            if (pl != nullptr) {
                plugin_name = pl->name();
            }
            ptr<event> evt = thread_manager::instance()->current_task();
            if (evt != nullptr) {
                task_name = evt->name();
            }

            pthread_t thread;
            timeval now;
            thread = pthread_self();
            gettimeofday(&now, nullptr);
            
            _log(now, thread, LL_DEBUG, plugin_name, task_name, msg);
        }
    }
    
    void logger::info(const string& msg) {
        if (logs::get_logger("info") != this) {
            logs::get_logger("info")->info(msg);
        }

        if (m_level >= LL_INFO) {
            string plugin_name = "none";
            string task_name = "none";
            ptr<plugin> pl = thread_manager::instance()->current_plugin();
            if (pl != nullptr) {
                plugin_name = pl->name();
            }

            ptr<event> evt = thread_manager::instance()->current_task();
            if (evt != nullptr) {
                task_name = evt->name();
            }

            pthread_t thread;
            timeval now;
            thread = pthread_self();
            gettimeofday(&now, nullptr);

            _log(now, thread, LL_INFO, plugin_name, task_name, msg);
        }
    }
    
    void logger::warn(const string& msg) {
        if (logs::get_logger("warn") != this) {
            logs::get_logger("warn")->warn(msg);
        }

        if (m_level >= LL_WARN) {
            string plugin_name = "none";
            string task_name = "none";
            ptr<plugin> pl = thread_manager::instance()->current_plugin();
            if (pl != nullptr) {
                plugin_name = pl->name();
            }
            ptr<event> evt = thread_manager::instance()->current_task();
            if (evt != nullptr) {
                task_name = evt->name();
            }

            pthread_t thread;
            timeval now;
            thread = pthread_self();
            gettimeofday(&now, nullptr);

            _log(now, thread, LL_WARN, plugin_name, task_name, msg);
        }
    }
    
    void logger::error(const string& msg) {
        if (logs::get_logger("error") != this) {
            logs::get_logger("error")->error(msg);
        }
        
        if (m_level >= LL_ERROR) {
            string plugin_name = "none";
            string task_name = "none";
            ptr<plugin> pl = thread_manager::instance()->current_plugin();
            if (pl != nullptr) {
                plugin_name = pl->name();
            }
            ptr<event> evt = thread_manager::instance()->current_task();
            if (evt != nullptr) {
                task_name = evt->name();
            }

            pthread_t thread;
            timeval now;
            thread = pthread_self();
            gettimeofday(&now, nullptr);
            
            _log(now, thread, LL_ERROR, plugin_name, task_name, msg);
        }
    }
    
    void logger::_log(const timeval& tv, pthread_t thread, log_level level,
                      const string& plugin_name, const string& task_name,
                      const string& msg) {
        static const char* level_mapping[] = {
            "debug",
            "info",
            "warn",
            "error",
        };

        char tb[32];
        strftime(tb, 32, "%F %T", localtime(&tv.tv_sec));
        
        char log_buf[MAX_LOG_LINE_SIZE + 1] = "";
        snprintf(log_buf, MAX_LOG_LINE_SIZE,
#ifdef OS_MACOSX
                 "[%5s][%s %06d][%016lx][%-16s][%-20s]%s\n",
#else
                 "[%5s][%s %06ld][%016lx][%-16s][%-20s]%s\n",
#endif
                 level_mapping[level], tb, tv.tv_usec, (long)thread,
                 plugin_name.c_str(), task_name.c_str(), msg.c_str());
        
        do {
            lock_guard<mutex> _(m_mutex);
            m_buf += log_buf;
        } while (0);
    }
    
    void* logger::_commit_log(void *param) {
        ptr<logger> logger = (class logger*)param;
        
        while (1) {
            do {
                lock_guard<mutex> _(logger->m_mutex);
                
                if (logger->m_buf.length() > 0) {
                    fwrite(logger->m_buf.c_str(), logger->m_buf.length(), 1, logger->m_fd);
                    fflush(logger->m_fd);
                    logger->m_buf = "";
                }
            } while (0);
            sleep(SYNC_LOG_LATENCY);
        }
    }
    
}

