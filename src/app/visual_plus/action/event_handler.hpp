#ifndef __ui_hpp__
#define __ui_hpp__

#include <wx/wx.h>

namespace vp {

class event_handler {
public:
  virtual void on_mouse_move(wxMouseEvent* evt) {}
  virtual void on_mouse_down(wxMouseEvent* evt) {}
  virtual void on_mouse_up(wxMouseEvent* evt) {}
  virtual void on_mouse_dbclict(wxMouseEvent* evt) {}
  virtual void on_mouse_move_in(wxMouseEvent* evt) {}
  virtual void on_mouse_move_out(wxMouseEvent* evt) {}

  virtual void on_key_down(wxKeyEvent* evt) { evt->Skip(); }
  virtual void on_key_up(wxKeyEvent* evt) { evt->Skip(); }
  virtual void on_key_char(wxKeyEvent* evt) {}

  virtual void on_click_menu(wxMenuEvent* evt) {}

  virtual void on_draw(wxPaintDC* dc) {}
};

}

#endif

