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
    virtual void on_mouse_down(wxMouseEvent* evt) override;
    virtual void on_mouse_move(wxMouseEvent* evt) override;
    virtual void on_mouse_up(wxMouseEvent* evt) override;

protected:
    enum edge {
        LEFT    = 1,
        TOP     = 2,
        RIGHT   = 4,
        BOTTOM  = 8,
    };
    bool m_resizing;
    long m_resize_edges;
    wxPoint m_resize_cur_pos;
};

}

#endif
