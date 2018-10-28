#include "point.hpp"
#include <app/visual_plus/arithmetic/geometry/path.hpp>
#include <lib/math/math.hpp>

using namespace kxy;

namespace vp {

point::point(double x, double y) {
    this->m_x = x;
    this->m_y = y;
}

double point::get_x() const {
    return m_x;
}

double point::get_y() const {
    return m_y;
}

void point::transform(ptr<matrix> trans) {
    point(m_x * (**trans)[0][0] + m_y * (**trans)[0][1],
          m_x * (**trans)[1][0] + m_y * (**trans)[1][1]);
}

bool point::in_polygon(ptr<path> polygon) const {
    // TODO:
    
    return polygon != nullptr;
}

bool point::on_polygon(ptr<path> polygon) const {
    list<path::arc_point> points = polygon->get_points();
    if (points.size() < 2)
        return false;

    ptr<point> begin, end;
    list<path::arc_point>::const_iterator i = points.begin();

    begin = (*i).first;
    for (++i; i != points.end(); ++i) {
        end = (*i).first;
        if (on_line(begin, end))
            return true;
        begin = end;
    }
    return false;
}

bool point::on_line(ptr<point> begin, ptr<point> end) const {
    return cmp((m_y-begin->m_y)*(end->m_x-begin->m_x), 
            (m_x-begin->m_x)*(end->m_y-begin->m_y)) == 0 &&
            (m_x-begin->m_x)*(m_x-end->m_x) < 0 &&
            (m_y-begin->m_y)*(m_y-end->m_y) < 0;
}

}
