#ifndef __frame_h__
#define __frame_h__

#include <string>
#include <ui/visual_objects/vo_image.hpp>

using namespace std;

namespace vp {

class main_frame : public wxFrame {
public:
    main_frame();

public:
    void on_mouse_event(wxMouseEvent& evt);
    void on_paint(wxPaintEvent& evt);
    void on_exit(wxCommandEvent& evt);

public:
    wxDECLARE_EVENT_TABLE();
};
}
#endif

