#include <visual_object/instace/interface_bar.hpp>

namespace vp {

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

bool interface_bar::on_draw(ptr<dc> pdc) {
    // TODO
    return false;
}

}

