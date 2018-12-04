#ifndef __graph_h__
#define __graph_h__

#include <wx/wx.h>

using namespace std;

namespace vp {

class graph {
public:
     graph(wxRect rect);

     wxRect get_rect() const;
     void set_rect(wxRect& rect);

     bool hit_check(wxPoint& point) const;

protected:
     wxRect m_rect;
};

}

#endif

