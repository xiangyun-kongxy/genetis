#include "vo_box.hpp"
#include <visual_plus/action/info/mouse_status.hpp>
#include <visual_plus/container/content.hpp>
#include <visual_plus/windows/vo_view.hpp>

namespace vp {

vo_box::vo_box(const wxRect& rect)
    : visual_object(rect) {
}

visual_object* create_vo_box(ptr<vo_document> doc) {
    ptr<content> ctt = doc->get_content();
    ptr<mouse_status> ms = ctt->get_cur_mouse();
    return new vo_box(wxRect(ms->x, ms->y, 50, 20));
}

vo_creator vo_box::get_creator() {
    return create_vo_box;
}

void vo_box::on_draw(wxPaintDC* dc) {
    dc->DrawRoundedRectangle(m_rect, 2.0);
}

void vo_box::on_mouse_down(wxMouseEvent* evt) {
    wxPoint pos = evt->GetPosition();
    long style = 0;
    if (abs(pos.x - m_rect.x) <= 2)
        style |= LEFT;
    else if (abs(pos.x - m_rect.x - m_rect.width) <= 2)
        style |= RIGHT;
    if (abs(pos.y - m_rect.y) <= 2)
        style |= TOP;
    else if (abs(pos.y - m_rect.y - m_rect.height) <= 2)
        style |= BOTTOM;

    if (style != 0) {
        m_resizing = true;
        m_resize_edges = style;
        m_resize_cur_pos = pos;
        this->get_document()->get_view()->capture_mouse_event(this);
    }
}
void vo_box::on_mouse_move(wxMouseEvent* evt) {
    if (m_resizing) {
        m_resize_cur_pos = evt->GetPosition();
        this->get_document()->get_view()->release_mouse_event(this);
    }
}

void vo_box::on_mouse_up(wxMouseEvent* evt) {
    if (m_resizing) {
        m_resizing = false;

        wxRect rect = m_rect;
        m_resize_cur_pos = evt->GetPosition();
        if ((m_resize_edges & LEFT) != 0) {
            rect.width += rect.x - m_resize_cur_pos.x;
            rect.x = m_resize_cur_pos.x;
        }
        if ((m_resize_edges & RIGHT) != 0) {
            rect.width = m_resize_cur_pos.x - rect.x;
        }
        if ((m_resize_edges & TOP) != 0) {
            rect.height += rect.y - m_resize_cur_pos.y;
            rect.y = m_resize_cur_pos.y;
        }
        if ((m_resize_edges & BOTTOM) != 0) {
            rect.height = m_resize_cur_pos.y - rect.y;
        }
        this->set_rect(rect);
        this->get_document()->get_view()->release_mouse_event(this);
    }
}

}
