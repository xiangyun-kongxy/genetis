#ifndef __lang_protocol_hpp__
#define __lang_protocol_hpp__

#include <lib/object/object.hpp>
using namespace kxy;

namespace vp {

class lang_protocol : public object {
public:
    DECLARE_TYPE(object, lang_protocol);
public:
    virtual string compile() const = 0;
};

}

#endif

