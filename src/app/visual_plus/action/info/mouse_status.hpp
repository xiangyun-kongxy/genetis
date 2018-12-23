#ifndef __mouse_status_hpp__
#define __mouse_status_hpp__

#include <lib/object/object.hpp>
using namespace kxy;

namespace vp {

class mouse_status : public object {
public:
    DECLARE_TYPE(object, mouse_status);
public:
    int x;
    int y;
    int key_bit;
};

}

#endif

