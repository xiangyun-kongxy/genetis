#ifndef __pi_slot_hpp__
#define __pi_slot_hpp__

#include <core/lang_protocol.hpp>
#include <core/procedure/pi_type.hpp>

namespace vp
{

class pi_slot : public lang_protocol {
public:
    DECLARE_TYPE(lang_protocol, pi_slot);
public:
    virtual string compile() const override;
protected:
    ptr<pi_type> m_type;
};

}

#endif

