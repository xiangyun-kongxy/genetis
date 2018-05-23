#ifndef __nerve_pattern_aware_hpp__
#define __nerve_pattern_aware_hpp__

#include <learning/pattern_learning/nerve_pattern.hpp>

#include <nerve/nerve_net.hpp>
#include <nerve/vertex.hpp>

namespace mind {
    
    class nerve_pattern_aware {
    public:
        virtual ptr<nerve_pattern>
            discover(ptr<vertex> focus, ptr<nerve_net> net) = 0;
    };

}

#endif

