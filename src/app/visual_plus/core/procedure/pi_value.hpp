#ifndef __pi_value_hpp__
#define __pi_value_hpp__

#include <core/lang_protocol.hpp>

namespace vp {
    
class pi_value : public lang_protocol {
public:
    DECLARE_TYPE(lang_protocol, pi_value);
public:
    virtual string compile() override;
};

}

#endif
