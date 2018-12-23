#ifndef __vo_box_hpp__
#define __vo_box_hpp__

#include <visual_plus/ui/visual_object.hpp>

namespace vp {

class vo_box : public visual_object {
public:
    DECLARE_TYPE(visual_object, vo_box);
public:
    vo_box(const wxRect& rect);
    virtual vo_creator get_creator() override;

public:
    virtual void on_draw(wxPaintDC* dc) override;

};

}

#endif