#ifndef __graph_h__
#define __graph_h__

#include "point.hpp"
#include <lib/object/ptr.hpp>
#include <wx/wx.h>

using namespace std;
using namespace kxy;

namespace vp {

class graph : public reference {
public:
     virtual void draw() = 0;
     virtual bool in(ptr<point> pt) = 0;
     virtual void set_transform(wxAffineMatrix2D& mat) = 0;
};

}

#endif

