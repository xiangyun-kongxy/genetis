#include "point.hpp"
#include <lib/math/math.hpp>

using namespace kxy;

namespace vp {

point::point(int x, int y) :
    wxPoint2DInt(x, y) {
}

int point::get_x() const {
    return m_x;
}

int point::get_y() const {
    return m_y;
}

}
