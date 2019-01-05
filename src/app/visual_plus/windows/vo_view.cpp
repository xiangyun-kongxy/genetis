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

static ptr<visual_object> get_mouse_processor(
        const map<string, ptr<visual_object>>*, const wxPoint& pos);

vo_view::vo_view(ptr<vo_document> doc, wxWindow* parent) :
    wxWindow(parent, wxID_ANY) {
    m_doc = doc;
}

void vo_view::on_mouse_event(wxMouseEvent& evt) {
    ptr<visual_object> processor;
    if (m_mouse_processor != nullptr) 
        processor = m_mouse_processor;
    else {
        processor = get_mouse_processor(m_doc->get_dataobjects(), 
                evt.GetPosition());
    }
    if (processor == nullptr)
        return;

    if (evt.Moving() || evt.Dragging()) {
        if (m_mouse_last_processor != processor) {
            processor->on_mouse_move_in(&evt);
            if (m_mouse_last_processor != nullptr)
                m_mouse_last_processor->on_mouse_move_out(&evt);
        }
        processor->on_mouse_move(&evt);
    } else if (evt.ButtonDown())
        processor->on_mouse_down(&evt);
    else if (evt.ButtonUp())
        processor->on_mouse_up(&evt);
    else if (evt.ButtonDClick())
        processor->on_mouse_dbclict(&evt);

    m_mouse_last_processor = processor;
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

void vo_view::capture_mouse_event(ptr<visual_object> processor) {
    if (m_mouse_processor == nullptr)
        m_mouse_processor = processor;
}

void vo_view::release_mouse_event(ptr<visual_object> processor) {
    if (m_mouse_processor == processor)
        m_mouse_processor = nullptr;
}

void vo_view::capture_key_event(ptr<visual_object> processor) {
    if (m_key_processor == nullptr)
        m_key_processor = processor;
}

void vo_view::release_key_event(ptr<visual_object> processor) {
    if (m_key_processor == processor)
        m_key_processor = nullptr;
}

ptr<vo_document> vo_view::get_document() const {
    return m_doc;
}

}
