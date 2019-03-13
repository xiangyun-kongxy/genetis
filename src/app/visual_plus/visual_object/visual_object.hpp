#ifndef __visual_object_hpp__
#define __visual_object_hpp__

#include <wx/wx.h>

#include <visual_object/object/pi_protocol.hpp>
#include <visual_object/visual/visual.hpp>

namespace vp {

class visual_object : public visual, public object {
public:
    DECLARE_TYPE(object, visual_object);
public:
    virtual void on_destroy_other(ptr<visual_object> vo) = 0;
    virtual void on_destroy_other(ptr<pi_protocol> obj) = 0;
};

}

#endif
