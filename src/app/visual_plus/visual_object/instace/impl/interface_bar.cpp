#include <visual_object/instace/interface_bar.hpp>
#include <lib/macro/warn.hpp>
#include <window/view.hpp>
#include <visual_object/instace/resizer.hpp>

using namespace kxy;
namespace vp {

interface_bar::interface_bar(ptr<document> doc, 
        const string& name, int pos, int size) :
    visual_object_base(doc, name) {
    m_pos = pos;
    m_size = size;
    m_is_visable = true;

    m_left = new resizer(m_doc, this, pos, 400);
    m_right = new resizer(m_doc, this, pos + size, 400);
    m_left->set_cursor(wxCURSOR_SIZEWE);
    m_right->set_cursor(wxCURSOR_SIZEWE);
    m_doc->add_object(m_left);
    m_doc->add_object(m_right);
    on_move(0, 0);
}

void interface_bar::on_resize() {
}

bool interface_bar::contain(long x, long unused(y)) {
    return x >= m_pos && x <= m_pos + m_size;
}

bool interface_bar::intersect(wxRect& rect) {
    return !(rect.GetRight() < m_pos || rect.GetLeft() > m_pos + m_size);
}

list<ptr<connector>> interface_bar::get_connector() {
    return list<ptr<connector>>();
}

void interface_bar::set_focus(bool focus) {
    int x = 0, y = 0;
    m_doc->get_view()->rtransform(x, y);
    wxSize size = m_doc->get_view()->get_client_size();
    
    m_left->set_pos(m_pos, y + size.y / 2);
    m_right->set_pos(m_pos + m_size, y + size.y / 2);

    if (focus) {
        m_left->set_visable(true);
        m_right->set_visable(true);
    } else {
        m_left->set_visable(false);
        m_right->set_visable(false);
    }
}

void interface_bar::resize(ptr<resizer> pr, int dx, int unused(dy)) {
    int x = 0, y = 0;
    
    if (pr == m_left) {
        if (m_size - dx <= 0) {
            m_pos += m_size - 1;
            m_size = 1;
        } else {
            m_pos += dx;
            m_size -= dx;
        }
    } else if (pr == m_right) {
        if (m_size + dx <= 0) {
            m_size = 1;
        } else {
            m_size += dx;
        }
    }
}

void interface_bar::on_destroy_other(ptr<visual_object> unused(vo)) {
}

void interface_bar::on_destroy_other(ptr<pi_protocol> unused(obj)) {
}

void interface_bar::on_move(long dx, long unused(dy)) {
    m_pos += dx;

    int x = 0, y = 0;
    m_doc->get_view()->rtransform(x, y);
    wxSize size = m_doc->get_view()->get_client_size();
    m_left->set_pos(m_pos, y + size.y / 2);
    m_right->set_pos(m_pos + m_size, y + size.y / 2);
}

bool interface_bar::on_draw(ptr<dc> pdc) {
    int x = 0, y = -2, dw = 0, dh = 4;
    int w, h;
    pdc->get_size(w, h);
    m_doc->get_view()->rtransform(x, y, dw, dh);

    pdc->draw_rect(m_pos, y-2, m_size, h + dh+4, 0);
    return true;
}

}

