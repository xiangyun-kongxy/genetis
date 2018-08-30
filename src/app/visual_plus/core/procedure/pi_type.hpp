#ifndef __pi_type_hpp__
#define __pi_type_hpp__

#include <core/lang_protocol.hpp>

namespace vp {

class pi_type : public lang_protocol {
public:
    DECLARE_TYPE(lang_protocol, pi_type);
public:
    virtual int size() = 0;

};

}

#endif

