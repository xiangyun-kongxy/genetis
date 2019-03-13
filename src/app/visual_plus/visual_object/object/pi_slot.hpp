#ifndef __pi_slot_hpp__
#define __pi_slot_hpp__

#include <visual_object/object/pi_value.hpp>

namespace vp
{

class pi_slot : public pi_value {
public:
    DECLARE_TYPE(pi_value, pi_slot);
protected:
    ptr<pi_type> m_type;
};

}

#endif

