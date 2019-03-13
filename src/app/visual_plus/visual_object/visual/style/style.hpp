#ifndef __style_hpp__
#define __style_hpp__

#include <visual_object/visual/dc/dc.hpp>
#include <lib/object/ptr.hpp>
#include <lib/object/object.hpp>

using namespace kxy;

namespace vp {

class style : public object {
public:
    DECLARE_TYPE(object, style);
public:
    virtual void apply(ptr<dc> pdc) = 0;
};

}

#endif
