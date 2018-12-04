#ifndef __cmd_hpp__
#define __cmd_hpp__

#include <lib/object/managed_object.hpp>

using namespace kxy;

namespace vp {

class command : public managed_object {
public:
    DECLARE_TYPE(managed_object, command);
public:
    virtual bool can_undo() const = 0;
    virtual void perform() = 0;
    virtual void undo() = 0;
    virtual string to_string() = 0;
};

}

#endif // __cmd_hpp__
