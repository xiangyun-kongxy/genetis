#ifndef __pi_slot_hpp__
#define __pi_slot_hpp__

#include <core/pi_protocol.hpp>
#include <core/pi_type.hpp>

namespace vp
{

class pi_slot : public pi_protocol {
public:
    DECLARE_TYPE(pi_protocol, pi_slot);
public:
    virtual string compile() const override;
protected:
    ptr<pi_type> m_type;
};

}

#endif

