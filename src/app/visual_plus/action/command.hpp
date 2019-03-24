#ifndef __cmd_hpp__
#define __cmd_hpp__

#include <lib/object/object.hpp>

using namespace kxy;

namespace vp {

class view;

class command : public object {
public:
    DECLARE_TYPE(object, command);

public:
    command(view* win) {
        m_win = win;
    }
public:
    virtual bool can_undo() const = 0;
    virtual void perform() = 0;
    virtual void undo() = 0;
    virtual string to_string() = 0;
protected:
    view* m_win;
};

}

#endif // __cmd_hpp__
