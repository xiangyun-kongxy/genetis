#ifndef __layout_hpp__
#define __layout_hpp__

#include <lib/object/object.hpp>

using namespace kxy;

namespace vp {

class layout : public object {
public:
    DECLARE_TYPE(object, layout);
public:
    virtual void apply() = 0;
};

}

#endif // __layout_hpp__
