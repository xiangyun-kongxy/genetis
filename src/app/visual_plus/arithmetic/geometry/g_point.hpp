#ifndef __g_point_hpp__
#define __g_point_hpp__

#include <lib/object/object.hpp>
#include <lib/object/ptr.hpp>
#include <arithmetic/geometry/coord.h>

using namespace kxy;

namespace vp {

class g_point : public object {
public:
    DECLARE_TYPE(object, g_point);
public:
    coord absolute_coord(const coord& relative) const {
        coord r = {relative.x + m_coord.x, relative.y + m_coord.y};
        return r;
    }

    coord local_coord() const {
        return m_coord;
    }

public:
    void move(const coord& d) {
        m_coord = absolute_coord(d);
    }

    void move_to(const coord& d) {
        m_coord = d;
    }

protected:
    coord m_coord;
};

}

#endif
