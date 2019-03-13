#include "view.hpp"
#include <visual_object/visual_object.hpp>

namespace vp {

wxBEGIN_EVENT_TABLE(view, wxWindow)
    EVT_MOUSE_EVENTS(view::on_mouse_event)
    EVT_KEY_DOWN(view::on_key_down)
    EVT_KEY_UP(view::on_key_up)
    EVT_CHAR(view::on_char)
    EVT_COMMAND(wxID_ANY, wxEVT_COMMAND_BUTTON_CLICKED, view::on_command)
    EVT_PAINT(view::on_draw)
wxEND_EVENT_TABLE();

static ptr<visual_object> get_mouse_processor(
        const map<string, ptr<visual_object>>*, const wxPoint& pos);

view::view(ptr<document> doc, wxWindow* parent) :
    wxWindow(parent, wxID_ANY) {
    m_doc = doc;
}

void view::on_mouse_event(wxMouseEvent& evt) {
    long x = evt.GetX();
    long y = evt.GetY();
    ptr<visual_object> processor;
    if (m_mouse_processor != nullptr) 
        processor = m_mouse_processor;
    else {
        processor = get_mouse_processor(m_doc->get_dataobjects(), 
                evt.GetPosition());
    }
    if (processor == nullptr) {
        if (m_mouse_last_processor != nullptr)
            m_mouse_last_processor->on_mouse_move_out(x, y, 0);
        m_mouse_last_processor = nullptr;
        return;
    }

    if (evt.Moving() || evt.Dragging()) {
        if (m_mouse_last_processor != processor) {
            processor->on_mouse_move_in(x, y, 0);
            if (m_mouse_last_processor != nullptr)
                m_mouse_last_processor->on_mouse_move_out(x, y, 0);
        }
        processor->on_mouse_move(x, y, 0);
    } else if (evt.ButtonDown())
        processor->on_mouse_down(x, y, 0);
    else if (evt.ButtonUp())
        processor->on_mouse_up(x, y, 0);
    else if (evt.ButtonDClick())
        processor->on_mouse_dclick(x, y, 0);

    m_mouse_last_processor = processor;
}
void view::on_key_down(wxKeyEvent& evt) {
}
void view::on_key_up(wxKeyEvent& evt) {
}
void view::on_char(wxKeyEvent& evt) {
}
void view::on_command(wxCommandEvent& evt) {
}

void view::on_draw(wxPaintEvent& evt) {
    ptr<dc> pdc = new dc(this);
    wxRect area = GetClientRect();
    map<string, ptr<visual_object>>* objects = m_doc->get_dataobjects();
    for (pair<string, ptr<visual_object>> vo : *objects) {
            vo.second->on_draw(pdc);
    }
}

void view::capture_mouse_event(ptr<visual_object> processor) {
    if (m_mouse_processor == nullptr)
        m_mouse_processor = processor;
}

void view::release_mouse_event(ptr<visual_object> processor) {
    if (m_mouse_processor == processor)
        m_mouse_processor = nullptr;
}

void view::capture_key_event(ptr<visual_object> processor) {
    if (m_key_processor == nullptr)
        m_key_processor = processor;
}

void view::release_key_event(ptr<visual_object> processor) {
    if (m_key_processor == processor)
        m_key_processor = nullptr;
}

ptr<document> view::get_document() const {
    return m_doc;
}

static ptr<visual_object> get_mouse_processor(
        const map<string, ptr<visual_object>>* vo, const wxPoint& pos) {
    map<string, ptr<visual_object>>::const_iterator i;
    for (i = vo->begin(); i != vo->end(); ++i) {
        ptr<visual_object> obj = i->second;
        if (obj->contain(pos.x, pos.y)) {
            return obj;
        }
    }
    return nullptr;
}

}
