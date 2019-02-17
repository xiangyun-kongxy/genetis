#include "vo_box.hpp"
#include <action/info/mouse_status.hpp>
#include <container/content.hpp>
#include <windows/vo_view.hpp>

namespace vp {

vo_box::vo_box(ptr<vo_document> doc, const wxRect& rect)
    : visual_object(doc, rect) {
    m_resizing = false;
    m_moving = false;
}

bool vo_box::contain(const wxPoint& pos) {
    return rect().Contains(pos);
}

void vo_box::on_draw(wxPaintDC* dc) {
    dc->DrawRoundedRectangle(rect(), 2.0);

    if (this->m_resizing) {
        wxPen oldPen = dc->GetPen();
        wxBrush oldBrush = dc->GetBrush();

        wxPen newPen(oldPen.GetColour(), oldPen.GetWidth(), wxPENSTYLE_DOT);
        dc->SetPen(newPen);
        dc->SetBrush(wxNullBrush);
        dc->DrawRoundedRectangle(get_future_rect(), 2.0);

        dc->SetBrush(oldBrush);
        dc->SetPen(oldPen);
    }
}

void vo_box::on_mouse_down(wxMouseEvent* evt) {
    wxPoint pos = evt->GetPosition();
    long edges = get_pos_edges(pos);
    if (edges != 0) {
        m_resizing = true;
        m_resize_edges = edges;
        m_mouse_cur_pos = pos;
        this->get_document()->get_view()->capture_mouse_event(this);
    } else {
        m_moving = true;
        m_mouse_cur_pos= pos;
        this->get_document()->get_view()->capture_mouse_event(this);
        this->get_document()->get_view()->SetCursor(wxCURSOR_CLOSED_HAND);
    }
}
void vo_box::on_mouse_move(wxMouseEvent* evt) {
    wxPoint pos = evt->GetPosition();

    if (m_resizing) {
        m_mouse_cur_pos = pos;
        this->get_document()->get_view()->Refresh();
    } else if (m_moving) {
        wxRect rect = this->rect();
        rect.x += pos.x - m_mouse_cur_pos.x;
        rect.y += pos.y - m_mouse_cur_pos.y;
        m_mouse_cur_pos = pos;
        set_placement(rect);
        this->get_document()->get_view()->Refresh();
    } else {
        long edges = get_pos_edges(pos);

        vo_view* view = this->get_document()->get_view();
        if (edges == LEFT || edges == RIGHT)
            view->SetCursor(wxCURSOR_SIZEWE);
        else if (edges == TOP || edges == BOTTOM)    
            view->SetCursor(wxCURSOR_SIZENS);
        else if (edges == (TOP | LEFT) || edges == (BOTTOM | RIGHT))
            view->SetCursor(wxCURSOR_SIZENWSE);
        else if (edges == (TOP | RIGHT) || edges == (BOTTOM | LEFT))
            view->SetCursor(wxCURSOR_SIZENESW);
        else 
            view->SetCursor(wxCURSOR_OPEN_HAND);
    }
}

void vo_box::on_mouse_up(wxMouseEvent* evt) {
    wxPoint pos = evt->GetPosition();
    if (m_resizing) {
        m_mouse_cur_pos = pos;
        wxRect newRect = this->get_future_rect();
        set_placement(newRect);
        this->get_document()->get_view()->release_mouse_event(this);
        this->get_document()->get_view()->SetCursor(wxCURSOR_ARROW);
        this->get_document()->get_view()->Refresh();
        m_resizing = false;
    } else if (m_moving) {
        wxRect rect = this->rect();
        rect.x += pos.x - m_mouse_cur_pos.x;
        rect.y += pos.y - m_mouse_cur_pos.y;
        m_mouse_cur_pos = pos;
        m_moving = false;
        set_placement(rect);
        this->get_document()->get_view()->release_mouse_event(this);
        this->get_document()->get_view()->SetCursor(wxCURSOR_ARROW);
        this->get_document()->get_view()->Refresh();
    }
}

void vo_box::on_mouse_move_out(wxMouseEvent* evt) {
    this->get_document()->get_view()->SetCursor(wxCURSOR_ARROW);
}

wxRect vo_box::get_future_rect() {
    wxRect rect = this->rect();
    if (m_resizing) {
        if ((m_resize_edges & LEFT) != 0) {
            rect.width += rect.x - m_mouse_cur_pos.x;
            rect.x = m_mouse_cur_pos.x;
        }
        if ((m_resize_edges & RIGHT) != 0) {
            rect.width = m_mouse_cur_pos.x - rect.x;
        }
        if ((m_resize_edges & TOP) != 0) {
            rect.height += rect.y - m_mouse_cur_pos.y;
            rect.y = m_mouse_cur_pos.y;
        }
        if ((m_resize_edges & BOTTOM) != 0) {
            rect.height = m_mouse_cur_pos.y - rect.y;
        }
    }
    return rect;
}

long vo_box::get_pos_edges(wxPoint pos) {
    wxRect rect = this->rect();
    long style = 0;
    if (abs(pos.x - rect.x) <= 4)
        style |= LEFT;
    else if (abs(pos.x - rect.x - rect.width) <= 4)
        style |= RIGHT;
    if (abs(pos.y - rect.y) <= 4)
        style |= TOP;
    else if (abs(pos.y - rect.y - rect.height) <= 4)
        style |= BOTTOM;

    return style;
}

}
