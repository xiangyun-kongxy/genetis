//
//  log_service.cpp
//  common
//
//  Created by 孔祥云 on 10/21/17.
//  Copyright © 2017 xiangyun.kong. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#include <lib/init/initializer.hpp>

#include <log.hpp>

#include <map>

using namespace std;

namespace kxy {
    
#define CUR_LOG_LEVEL       LL_INFO
    
    map<string, ptr<logger>>* g_log_stores = nullptr;
    
    void __uninit_log_stores() {
        g_log_stores->clear();
    }
    
    void init_log_stores(const string& log_path) {
        g_log_stores = new map<string, ptr<logger>>;
        
        FILE* pf;
        if (log_path == "stdout") {
            logs::set_logger("debug", stdout, CUR_LOG_LEVEL);
            logs::set_logger("info", stdout, CUR_LOG_LEVEL);
            logs::set_logger("warn", stdout, CUR_LOG_LEVEL);
            logs::set_logger("error", stdout, CUR_LOG_LEVEL);
            pf = fopen("/dev/null", "a");
            logs::set_logger("bus", pf, CUR_LOG_LEVEL);
        } else {
            pf = fopen((log_path + "/debug.log").c_str(), "a");
            logs::set_logger("debug", pf, CUR_LOG_LEVEL);
            
            pf = fopen((log_path + "/info.log").c_str(), "a");
            logs::set_logger("info", pf, CUR_LOG_LEVEL);
            
            pf = fopen((log_path + "/warn.log").c_str(), "a");
            logs::set_logger("warn", pf, CUR_LOG_LEVEL);
            
            pf = fopen((log_path + "/error.log").c_str(), "a");
            logs::set_logger("error", pf, CUR_LOG_LEVEL);

            pf = fopen((log_path + "/bus.log").c_str(), "a");
            logs::set_logger("bus", pf, CUR_LOG_LEVEL);
        }
        
        register_uninitializer("uninitialize logstores", __uninit_log_stores);
    }
    
    ptr<logger> logs::get_logger(const string &name) {
        return (*g_log_stores)[name];
    }
    
    void logs::set_logger(const string &name, FILE* file, kxy::log_level level) {
        (*g_log_stores)[name] = new logger(file, level);
    }
    
    
    const char* filename(const char* path) {
        const char* pc;
        while ((pc = strchr(path, '/')) != nullptr) {
            path = pc + 1;
        }
        return path;
    }
    
}
