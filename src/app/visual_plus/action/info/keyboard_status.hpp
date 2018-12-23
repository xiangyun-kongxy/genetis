#ifndef __keyboard_status_hpp__
#define __keyboard_status_hpp__

#include <lib/object/object.hpp>
using namespace kxy;

namespace vp {

class keyboard_status : public object {
public:
    DECLARE_TYPE(object, keyboard_status);
public:
    int key;
    int status_bit;
};

}

#endif

