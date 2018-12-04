#include "frame.hpp"
#include <visual_plus/ui/visual_objects/vo_image.hpp>

namespace vp {

    wxBEGIN_EVENT_TABLE(frame, wxFrame)
        EVT_MOUSE_EVENTS(frame::on_mouse_event)
        EVT_PAINT(frame::on_paint)
    wxEND_EVENT_TABLE()

    frame::frame() : wxFrame(nullptr, wxID_ANY, "visual plus") {
        image = new vo_image("/Users/kongxiangyun/Pictures/tfsprivate.jpg", wxRect(0, 0, 200, 200));
    }

    void frame::on_mouse_event(wxMouseEvent& evt) {
        m_mouse_event = "mouse";
        m_mouse_pos = evt.GetPosition();
        if (evt.Moving() || evt.Dragging()) {
            m_mouse_event += " move";
        }
        if (evt.LeftIsDown()) {
            m_mouse_event += " left";
        }
        if (evt.RightIsDown()) {
            m_mouse_event += " right";
        }
        if (evt.MiddleIsDown()) {
            m_mouse_event += " middle";
        }
        this->Refresh(false);
    }

    void frame::on_paint(wxPaintEvent& evt) {
        wxPaintDC dc(this);
        image->on_draw(&dc);
    }
}
