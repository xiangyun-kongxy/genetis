//
//  function_manager.hpp
//  plugin
//
//  Created by xiangyun.kong on 10/18/17.
//  Copyright © 2017 孔祥云. All rights reserved.
//

#ifndef function_manager_hpp
#define function_manager_hpp

#include <stdio.h>

#include <plugin/plugin/plugin.hpp>

#include <mutex>

using namespace kxy;
using namespace std;

namespace pf {

    class function_manager {
    private:
        friend class plugin_manager;
        function_manager();
        ~function_manager();
        
    public:
        static function_manager* instance();
        bool is_actived(ptr<identifier> id);

    private:
        void add_function(ptr<plugin> owner, ptr<function> func);
        void rm_function(ptr<function> func);
        void active_function(ptr<function> func);
        void suspend_function(ptr<function> func);

    private:
        struct function_info {
            ptr<function> func;
            bool is_active;
            ptr<plugin> provider;

            bool operator == (const ptr<function>& func) {
                return this->func->name() == func->name() &&
                    this->func->provider() == func->provider();
            }
            
            bool operator == (const ptr<identifier>& id) {
                return id->match(func);
            }
        };

        typedef typename list<function_info>::iterator liit;

        template<class ty>
        liit find(liit begin, liit end, ty cmp) {
            liit cur = begin;
            while (cur != end) {
                if (*cur == cmp)
                    break;
                ++cur;
            }
            return cur;
        }

    private:
        list<function_info> m_functions;
        static function_manager* g_function_manager;
    };
    
}

#endif /* function_manager_hpp */
