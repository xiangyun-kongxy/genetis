#ifndef __keyboard_status_hpp__
#define __keyboard_status_hpp__

#include <lib/object/managed_object.hpp>
using namespace kxy;

namespace vp {

class keyboard_status : public managed_object {
public:
    DECLARE_TYPE(managed_object, keyboard_status);
public:
    int key;
    int status_bit;
};

}

#endif

