#ifndef __ui_hpp__
#define __ui_hpp__

#include <lib/object/managed_object.hpp>

using namespace kxy;

namespace vp {

class ui : public managed_object {
public:
    DECLARE_TYPE(managed_object, ui);
public:
    virtual bool on_mouse_move() = 0;
    virtual bool on_mouse_down() = 0;
    virtual bool on_mouse_up() = 0;
    virtual bool on_mouse_move_in() = 0;
    virtual bool on_mouse_move_out() = 0;

    virtual bool on_key_down() = 0;
    virtual bool on_key_up() = 0;

    virtual bool on_click_menu() = 0;

    virtual bool on_draw() = 0;
};

}

#endif

