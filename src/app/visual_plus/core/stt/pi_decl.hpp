#ifndef __pi_decl_hpp__
#define __pi_decl_hpp__

#include <core/pi_value.hpp>
#include <core/pi_mixer.hpp>

#include <list>
using namespace std;

namespace vp {

class pi_decl : public pi_value {
public:
    DECLARE_TYPE(pi_value, pi_decl);
protected:
    ptr<pi_type> m_type;
    ptr<pi_mixer> m_init;
    list<ptr<pi_value>> m_inputs;
};

}

#endif
