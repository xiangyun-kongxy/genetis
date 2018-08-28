#ifndef __pi_slot_hpp__
#define __pi_slot_hpp__

#include <lib/object/ptr.hpp>
#include <core/lang_protocol.hpp>
#include <core/procedure/pi_value.hpp>

namespace vp
{

class pi_slot : public lang_protocol {
public:
    DECLARE_TYPE(lang_protocol, pi_slot);
public:
    virtual string compile() override;
protected:
    ptr<lang_protocol> m_type;
    ptr<pi_value> m_value;
};

}

#endif

