#include "frame.hpp"

namespace vp {

    wxBEGIN_EVENT_TABLE(frame, wxFrame)
        EVT_MOUSE_EVENTS(frame::on_mouse_event)
        EVT_PAINT(frame::on_paint)
    wxEND_EVENT_TABLE()

    frame::frame(const string& name) : wxFrame(nullptr, wxID_ANY, "visual plus") {
        m_name = name;
    }

    string frame::name() const {
        return m_name;
    }

    void frame::on_mouse_event(wxMouseEvent& evt) {
        m_mouse_event = "mouse";
        m_mouse_pos = evt.GetPosition();
        if (evt.Moving()) 
            m_mouse_event += " move";
        this->Refresh(false);
    }

    void frame::on_paint(wxPaintEvent& evt) {
        wxPaintDC dc(this);
        dc.DrawText(m_mouse_event, m_mouse_pos);
    }
}
