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
    return INSIDE == get_relation(polygon);
}

bool point::on_polygon(ptr<path> polygon) const {
    return ON == get_relation(polygon);
}

bool point::on_line(ptr<point> begin, ptr<point> end) const {
    return ON == get_relation(begin, end);
}

point::relation point::get_relation(ptr<point> begin, ptr<point> end) const {
    double x1 = end->get_x() - begin->get_x();
    double y1 = end->get_y() - begin->get_y();
    double x2 = this->get_x() - begin->get_x();
    double y2 = this->get_y() - begin->get_y();
    double dp = x1 * x2 + y1 * y2;
    if (cmp(dp, ZERO) == 1) {
        return RIGHT;
    } else if (cmp(dp, ZERO) == -1) {
        return LEFT;
    } else {
        if (cmp(x2, ZERO) == 0 && cmp(y2, ZERO) == 0) { 
            return BEGIN;
        } else if (cmp(x2, x1) == 0 && cmp(y2, y1) == 0) {
            return END;
        } else if (cmp(x1 * x2, ZERO) == 1 && cmp(x2, x1) == 1) {
            return FRONT;
        } else if (cmp(x1 * x2, ZERO) == -1 && cmp(fabs(x1), fabs(x2)) == 1) {
            return BACK;
        } else {
            return ON;
        }
    }
}

point::relation point::get_relation(ptr<path> polygon) const {
    list<path::arc_point> points = polygon->get_points();
    if (points.size() <= 2 || !polygon->is_close())
        return INVALID;

    ptr<point> begin, end;
    list<path::arc_point>::const_iterator i = points.begin();
    point::relation r = INVALID;

    begin = (*i).first;
    for (++i; i != points.end(); ++i) {
        end = (*i).first;
        point::relation l = get_relation(begin, end);
        if (l == ON) {
            return l;
        }

        if (r == INVALID) {
            r = l;
        } else if (r != l) {
            return OUTSIDE;
        } else {
            r = l;
        }

        begin = end;
    }

    if (r != get_relation(begin, (*i).first)) {
        return OUTSIDE;
    } else {
        return INSIDE;
    }
}

}
