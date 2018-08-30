#ifndef __pi_value_hpp__
#define __pi_value_hpp__

#include <lib/object/ptr.hpp>
#include <core/pi_protocol.hpp>
#include <core/pi_type.hpp>

namespace vp {
    
class pi_value : public pi_protocol {
public:
    DECLARE_TYPE(pi_protocol, pi_value);
public:
    virtual ptr<pi_type> value_type() const = 0;
};

}

#endif
