#include <visual_object/instace/connector.hpp>
#include <visual_object/instace/visual_object_base.hpp>

namespace vp {

connector::connector(ptr<document> doc, ptr<visual_object_base> parent, 
        int x, int y, wxDirection dir, 
        connect_type type, 
        connector_style style) : visual_object(doc, "noname") {
    set_parent(parent);
    m_direction = dir;
    m_type = type;
    m_style = style;
    m_pos.x = x;
    m_pos.y = y;
}

bool connector::on_draw(ptr<dc> pdc) {
    if (m_style == cs_point) {
        pdc->draw_rect(m_pos.x - 1, m_pos.y - 1, 3, 3, 0);
    } else if (m_style == cs_pin) {
        switch(m_direction) {
        case wxUP:
            pdc->draw_rect(m_pos.x - 3, m_pos.y - 3, 6, 3, 0);
            break;
        case wxBOTTOM:
            pdc->draw_rect(m_pos.x - 3, m_pos.y, 6, 3, 0);
            break;
        case wxLEFT:
            pdc->draw_rect(m_pos.x - 3, m_pos.y - 3, 3, 6, 0);
            break;
        case wxRIGHT:
            pdc->draw_rect(m_pos.x, m_pos.y - 3, 3, 6, 0);
            break;
        default:
            break;
        }
    }
    return true;
}

void connector::on_move(long dx, long dy) {
    set_pos(dx + m_pos.x, dy + m_pos.y);
}

void connector::on_resize() {
}

void connector::set_focus(bool focus) {
}

bool connector::contain(long x, long y) {
    if (m_style == cs_point) {
        return wxRect(m_pos.x - 1, m_pos.y - 1, 3, 3).Contains(x, y);
    } else if (m_style == cs_pin) {
        switch(m_direction) {
        case wxUP:
            return wxRect(m_pos.x - 3, m_pos.y - 3, 6, 3).Contains(x, y);
        case wxBOTTOM:
            return wxRect(m_pos.x - 3, m_pos.y, 6, 3).Contains(x, y);
        case wxLEFT:
            return wxRect(m_pos.x - 3, m_pos.y - 3, 3, 6).Contains(x, y);
        case wxRIGHT:
            return wxRect(m_pos.x, m_pos.y - 3, 3, 6).Contains(x, y);
        default:
            return false;
        }
    } else {
        return false;
    }
}

bool connector::intersect(wxRect& rect) {
    if (m_style == cs_point) {
        return wxRect(m_pos.x - 1, m_pos.y - 1, 3, 3).Intersects(rect);
    } else if (m_style == cs_pin) {
        switch(m_direction) {
        case wxUP:
            return wxRect(m_pos.x - 3, m_pos.y - 3, 6, 3).Intersects(rect);
        case wxBOTTOM:
            return wxRect(m_pos.x - 3, m_pos.y, 6, 3).Intersects(rect);
        case wxLEFT:
            return wxRect(m_pos.x - 3, m_pos.y - 3, 3, 6).Intersects(rect);
        case wxRIGHT:
            return wxRect(m_pos.x, m_pos.y - 3, 3, 6).Intersects(rect);
        default:
            return false;
        }
    } else {
        return false;
    }
}

void connector::on_destroy_other(ptr<visual_object> vo) {
    if (vo == get_parent()) {
        reduce();
    }
}

void connector::on_destroy_other(ptr<pi_protocol> obj) {
}

void connector::set_pos(int x, int y) {
    m_pos.x = x;
    m_pos.y = y;
}

}
