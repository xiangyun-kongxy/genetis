#ifndef __symmetry_hpp__
#define __symmetry_hpp__

#include <learning/pattern_learning/nerve_pattern_aware.hpp>

namespace mind {

    class symmetry : public nerve_pattern_aware {
    public:
        virtual ptr<nerve_pattern> discover(long focus, 
                                            ptr<nerve_net> net) {
            return nullptr;
        }
    };

}

#endif

