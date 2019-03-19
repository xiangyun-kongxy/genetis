#include <visual_object/instace/interface_bar.hpp>

namespace vp {

interface_bar::interface_bar(const string& name, int pos, int size) :
    visual_object(name) {
    m_pos = pos;
    m_size = size;
}

void interface_bar::on_resize() {
}

bool interface_bar::contain(long x, long y) {
    // TODO
    return false;
}

bool interface_bar::intersect(wxRect& rect) {
    // TODO
    return false;
}

list<wxPoint> interface_bar::get_connect_points() {
    // TODO
    return list<wxPoint>();
}

list<wxPoint> interface_bar::get_resize_points() {
    // TODO
    return list<wxPoint>();
}

void interface_bar::on_destroy_other(ptr<visual_object> vo) {
    (void) vo;
}

void interface_bar::on_destroy_other(ptr<pi_protocol> obj) {
    (void) obj;
}

bool interface_bar::on_draw(ptr<dc> pdc) {
    int w, h;
    pdc->get_size(w, h);
    pdc->draw_rect(m_pos, -1, m_size, h + 2, 0);

    return true;
}

}

