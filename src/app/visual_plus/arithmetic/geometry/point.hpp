#ifndef __point_hpp__
#define __point_hpp__

#include <wx/wx.h>
#include <lib/object/reference.hpp>

using namespace kxy;

namespace vp {

class point : public reference, public wxPoint2DInt {
public:
    point(int x, int y);
public:
    int get_x() const;
    int get_y() const;
};

}

#endif

