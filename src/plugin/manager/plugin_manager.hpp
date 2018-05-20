//
//  plugin_manager.hpp
//  plugin
//
//  Created by xiangyun.kong on 10/3/17.
//  Copyright © 2017 孔祥云. All rights reserved.
//

#ifndef plugin_manager_hpp
#define plugin_manager_hpp

#include <stdio.h>

#include <lib/object/object.hpp>
#include <plugin/plugin/plugin.hpp>

#include <mutex>

using namespace kxy;
using namespace std;

namespace pf {
    
    class plugin_manager {
    private:
        friend class plugin;
        plugin_manager();
        ~plugin_manager();

    public:
        static plugin_manager* instance();

    private:
        void add_plugin(ptr<plugin> pl);
        void rm_plugin(ptr<plugin> pl);
        void active_plugin(ptr<plugin> pl);
        void suspend_plugin(ptr<plugin> pl);

    public:
        list<ptr<plugin>> get_all_plugin();
        ptr<plugin> find_plugin(ptr<identifier> id);
        list<ptr<plugin>> search_plugin(ptr<identifier> id);
        
        long version() const;

        bool is_actived(ptr<identifier> id);
        bool has_task(ptr<identifier> id);

    private:
        set<ptr<plugin>> m_plugins;
        static plugin_manager* g_plugin_manager;
        
        long m_version;
    };
}

#endif /* plugin_manager_hpp */
