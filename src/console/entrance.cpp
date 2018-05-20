//
//  entance.cpp
//  console
//
//  Created by 孔祥云 on 11/4/17.
//  Copyright © 2017 孔祥云. All rights reserved.
//

#include <console/terminal.hpp>
#include <lib/fs/kv.hpp>
#include <common/log/logger.hpp>
#include <plugin/manager/plugin_manager.hpp>

using namespace pf;

int main(int argc, char** argv) {
    init_log_stores("stdout");
    init_kv_storage("/mind/data");
    plugin_manager::init();

    ptr<terminal> term = new terminal;
    term->init();
    term->resume();
    
    term->command_loop();
    return 0;
}
