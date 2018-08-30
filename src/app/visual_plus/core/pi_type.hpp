#ifndef __pi_type_hpp__
#define __pi_type_hpp__

#include <list>
#include <lib/object/ptr.hpp>
#include <core/pi_protocol.hpp>

namespace vp {

class pi_slot;
class pi_mixer;

class pi_type : public pi_protocol {
public:
    DECLARE_TYPE(pi_protocol, pi_type);
protected:
    list<ptr<pi_slot>> m_attrs;
    list<ptr<pi_mixer>> m_mixers;
};

}

#endif

