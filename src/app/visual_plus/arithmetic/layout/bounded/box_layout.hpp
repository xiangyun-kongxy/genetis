#ifndef __box_layout_hpp__
#define __box_layout_hpp__

#include <visual_plus/ui/visual_object.hpp>
#include "../layout.hpp"

namespace vp {

class box_layout : public layout {
public:
    virtual void add(ptr<visual_object> vo, int position) = 0;
    virtual void add(ptr<box_layout> box, int position) = 0;

    virtual wxSize min_size() const = 0;
};

}

#endif // __box_layout_hpp__
