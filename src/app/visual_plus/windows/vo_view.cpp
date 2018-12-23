#include "vo_view.hpp"
#include <visual_plus/ui/visual_object.hpp>

namespace vp {

wxBEGIN_EVENT_TABLE(vo_view, wxWindow)
    EVT_MOUSE_EVENTS(vo_view::on_mouse_event)
    EVT_KEY_DOWN(vo_view::on_key_down)
    EVT_KEY_UP(vo_view::on_key_up)
    EVT_CHAR(vo_view::on_char)
    EVT_COMMAND(wxID_ANY, wxEVT_COMMAND_BUTTON_CLICKED, vo_view::on_command)
    EVT_PAINT(vo_view::on_draw)
wxEND_EVENT_TABLE();

vo_view::vo_view(ptr<vo_document> doc, wxWindow* parent) :
    wxWindow(parent, wxID_ANY) {
    m_doc = doc;
}

void vo_view::on_mouse_event(wxMouseEvent& evt) {
}
void vo_view::on_key_down(wxKeyEvent& evt) {
}
void vo_view::on_key_up(wxKeyEvent& evt) {
}
void vo_view::on_char(wxKeyEvent& evt) {
}
void vo_view::on_command(wxCommandEvent& evt) {
}

void vo_view::on_draw(wxPaintEvent& evt) {
    wxPaintDC dc(this);
    wxRect area = GetClientRect();
    map<string, ptr<visual_object>>* objects = m_doc->get_dataobjects();
    for (pair<string, ptr<visual_object>> vo : *objects) {
        if (area.Intersects(vo.second->get_rect())) {
            vo.second->on_draw(&dc);
        }
    }
}

ptr<vo_document> vo_view::get_document() const {
    return m_doc;
}

}