#ifndef __density_hpp__
#define __density_hpp__

#include <learning/pattern_learning/nerve_pattern_aware.hpp>

namespace mind {

    class density : public nerve_pattern_aware {
    public:
        virtual ptr<nerve_pattern> discover(long focus, 
                                            ptr<nerve_net> net) {
            return nullptr;
        }
    };

}

#endif

