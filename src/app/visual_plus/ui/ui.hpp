#ifndef __ui_hpp__
#define __ui_hpp__

#include <lib/object/managed_object.hpp>

using namespace kxy;

namespace vp {

class ui : public managed_object {
public:
  DECLARE_TYPE(managed_object, ui);

public:
  virtual void on_mouse_move();
  virtual void on_mouse_down();
  virtual void on_mouse_up();
  virtual void on_mouse_move_in();
  virtual void on_mouse_move_out();

  virtual void on_key_down();
  virtual void on_key_up();

  virtual void on_click_menu();

  virtual void on_draw();
};

}

#endif

