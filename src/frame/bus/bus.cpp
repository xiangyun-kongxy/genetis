//
// Created by 孔祥云 on 8/10/16.
//

#include "bus.hpp"

#include <bus/executor/exe_on_route.hpp>

namespace pf {
    
    bus::bus() {
        m_router = new on_route;
    }
    
    ptr<response> bus::do_task(ptr<event> evt) {
        if (evt != nullptr) {
            m_router->run(this, evt);
        }
        return nullptr;
    }
    
}
