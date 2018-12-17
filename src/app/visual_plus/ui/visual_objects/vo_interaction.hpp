#ifndef __vo_interaction_hpp__
#define __vo_interaction_hpp__

#include "../visual_object.hpp"

namespace vp {

class vo_interaction : public visual_object {
public:
    DECLARE_TYPE(visual_object, vo_interaction);
    
public:
    // resize by mouse
    // pre set focus when mouse over
    // set focus when mouse down
    // move object with mouse move
    // 
};

}

#endif