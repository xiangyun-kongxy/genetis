#ifndef __g_line_hpp__
#define __g_line_hpp__

#include <lib/object/object.hpp>
#include <lib/object/ptr.hpp>
#include <arithmetic/geometry/g_point.hpp>

namespace vp {

class g_line : public object {
public:
    DECLARE_TYPE(object, g_line);
public:
    list<ptr<g_point>> m_pos;
};

}

#endif
