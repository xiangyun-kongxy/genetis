#ifndef __graph_h__
#define __graph_h__

#include <wx/wx.h>

using namespace std;

namespace vp {

class graph {
public:
     virtual bool contain(const wxPoint& pos) = 0;
};

}

#endif

