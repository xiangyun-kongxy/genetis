#ifndef __box_layout_hpp__
#define __box_layout_hpp__

#include <lib/object/ptr.hpp>
#include "../layout.hpp"
#include <wx/wx.h>
#include <list>

using namespace kxy;
using namespace std;

namespace vp {

class visual_object;

class box_layout : public layout {
public:
    DECLARE_TYPE(layout, box_layout);

public:
    virtual void resize(int x, int y, int width, int height) = 0;
public:
    virtual void add(ptr<visual_object> vo, int position) = 0;
    virtual void add(ptr<box_layout> box, int position) = 0;
    virtual list<ptr<object>> get_objects() = 0;
};

}

#endif // __box_layout_hpp__
