/**
 * copyright @2016. all rights reserved.
 *
 * @since:  11:01 PM 8/10/16
 * @author: xiangyun kong
 *
 * description:
 *
 */

#ifndef PLUGIN_TRG_ON_ROUTING_EVENT_H
#define PLUGIN_TRG_ON_ROUTING_EVENT_H

#include <plugin/manager/plugin_manager.hpp>

#include <bus/bus.hpp>
#include <bus/schedule/event_router/router.hpp>

#include <lib/thread/thread.hpp>

#include <log.hpp>

using namespace std;
using namespace kxy;

namespace pf {
    
    class on_route : public executor {
    public:
        DECLARE_TYPE(executor, EXE_ON_ROUTE)
        
    public:
        virtual ptr<response> run(ptr<plugin> owner, ptr<event> evt) override {
            router* rt = (router*)thread::get_thread_attr("bus_scheduler");
            if (rt == nullptr) {
                rt = new router;
                thread::set_thread_attr("bus_scheduler", rt);
            }
            
            long version = (long)thread::get_thread_attr("bus_sequence");
            if (version != plugin_manager::instance()->version()) {
                rt->update_plugins();
                version = plugin_manager::instance()->version();
                thread::set_thread_attr("bus_sequence", (void*)version);
            }
            
            rt->schedule(evt);

            char log_buf[128];
            snprintf(log_buf, 128, "%-20s %16s -> %-16s", evt->name().c_str(),
                     evt->deliver()->name().c_str(),
                     evt->destination()->name().c_str());
            info_log("bus", log_buf);

            return nullptr;
        }
    };
    
}

#endif // PLUGIN_TRG_ON_ROUTING_EVENT_H

