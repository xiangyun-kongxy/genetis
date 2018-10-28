#include "path.hpp"

namespace vp {

void path::move_to(ptr<point> pt) {
    m_points.clear();
    m_points.push_back(arc_point(pt, pt));
    m_closed = false;
}

void path::line_to(ptr<point> pt, ptr<point> ctrl /*= nullptr*/) {
    if (ctrl == nullptr)
        ctrl = pt;
    m_points.push_back(arc_point(pt, ctrl));
}

void path::close_path() {
    m_closed = true;
}

list<path::arc_point> path::get_points() const {
    return m_points;
}

bool path::is_close() const {
    return m_closed;
}

}

