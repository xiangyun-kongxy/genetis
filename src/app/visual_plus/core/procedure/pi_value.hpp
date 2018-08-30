#ifndef __pi_value_hpp__
#define __pi_value_hpp__

#include <lib/object/ptr.hpp>
#include <core/lang_protocol.hpp>
#include <core/procedure/pi_type.hpp>

namespace vp {
    
class pi_value : public lang_protocol {
public:
    DECLARE_TYPE(lang_protocol, pi_value);
public:
    ptr<pi_type> value_type() const = 0;
};

}

#endif
