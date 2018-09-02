#ifndef __pi_stt_hpp__
#define __pi_stt_hpp__

#include <core/pi_mixer.hpp>

namespace vp {

class pi_stt : public pi_protocol {
public:
    DECLARE_TYPE(pi_protocol, pi_stt);
protected:
    ptr<pi_protocol> m_opt;
    ptr<pi_mixer> m_opd;
    list<pi_value>> m_inputs;
}

}

#endif

