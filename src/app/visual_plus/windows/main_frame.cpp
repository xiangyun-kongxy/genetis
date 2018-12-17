#include "main_frame.hpp"
#include <visual_plus/ui/visual_objects/vo_image.hpp>
#include <lib/macro/warn.hpp>

namespace vp {

    wxBEGIN_EVENT_TABLE(main_frame, wxFrame)
        EVT_MOUSE_EVENTS(main_frame::on_mouse_event)
        EVT_PAINT(main_frame::on_paint)
        EVT_MENU(wxID_CLOSE_ALL, main_frame::on_exit)
    wxEND_EVENT_TABLE()

    main_frame::main_frame() : wxFrame(nullptr, wxID_ANY, "visual plus", wxDefaultPosition, wxDefaultSize, wxRESIZE_BORDER) {
        wxAcceleratorEntry ac_entries[1];
        ac_entries[0].Set(wxACCEL_CMD, 'q', wxID_CLOSE_ALL);
        SetAcceleratorTable(wxAcceleratorTable(1, ac_entries));
    }

    void main_frame::on_exit(wxCommandEvent& evt) {
        Close();
    }

    void main_frame::on_mouse_event(wxMouseEvent& evt) {
    }

    void main_frame::on_paint(wxPaintEvent& evt) {
        disable_warn_unused(evt);
        wxPaintDC dc(this);
    }
}
