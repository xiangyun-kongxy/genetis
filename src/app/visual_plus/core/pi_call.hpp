#ifndef __pi_call_hpp__
#define __pi_call_hpp__

#include <core/pi_value.hpp>

namespace vp {

class pi_call : public pi_value {
public:
    DECLARE_TYPE(pi_value, pi_call);
protected:
    ptr<pi_mixer> m_mixer;
    ptr<pi_value> m_obj;
    list<ptr<pi_value>> m_inputs;
};

}

#endif
