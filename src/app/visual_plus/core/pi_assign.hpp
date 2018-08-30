#ifndef __pi_assign_hpp
#define __pi_assign_hpp

#include <core/pi_value.hpp>

namespace vp {

class pi_assign : public pi_value {
public:
    DECLARE_TYPE(pi_value, pi_assign);
protected:
    ptr<pi_slot> m_slot;
    ptr<pi_value> m_value;
};

}

#endif
