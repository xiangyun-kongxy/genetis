#ifndef __frame_h__
#define __frame_h__

#include <wx/wx.h>
#include <string>
#include <visual_plus/ui/visual_objects/vo_image.hpp>

using namespace std;

namespace vp {

class frame : public wxFrame {
public:
    frame();

public:
    void on_mouse_event(wxMouseEvent& evt);
    void on_paint(wxPaintEvent& evt);

public:
    wxDECLARE_EVENT_TABLE();

private:
    wxPoint m_mouse_pos;
    string m_mouse_event;
    ptr<vo_image> image; 
};
}
#endif

