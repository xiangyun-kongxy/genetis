#ifndef __frame_h__
#define __frame_h__

#include <wx/wx.h>
#include <app/visual_plus/ui/ui.hpp>

namespace vp {

class frame : public wxFrame, public ui {
public:
  frame(const string& name);
  virtual string name() const override;

public:
  void on_mouse_event(wxMouseEvent& evt);
  void on_paint(wxPaintEvent& evt);

public:
  wxDECLARE_EVENT_TABLE();

private:
  string m_name;
  wxPoint m_mouse_pos;
  string m_mouse_event;
};
}
#endif

