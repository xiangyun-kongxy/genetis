#ifndef __pi_mixer_hpp__
#define __pi_mixer_hpp__

#include <core/pi_slot.hpp>

namespace vp {
    
class pi_mixer : public pi_protocol {
public:
    DECLARE_TYPE(pi_protocol, pi_mixer);
protected:
    list<ptr<pi_slot>> m_params;
    void* m_flow;
    ptr<pi_type> m_ret_type;
};

}

#endif
