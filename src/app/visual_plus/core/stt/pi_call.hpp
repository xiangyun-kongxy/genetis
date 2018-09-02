#ifndef __pi_call_hpp__
#define __pi_call_hpp__

#include <core/pi_stt.hpp>

#include <list>
using namespace std;

namespace vp {

class pi_mixer;

class pi_call : public pi_stt {
public:
    DECLARE_TYPE(pi_stt, pi_call);
protected:
    ptr<pi_mixer> m_mixer;
    ptr<pi_value> m_obj;
    list<ptr<pi_value>> m_inputs;
};

}

#endif
