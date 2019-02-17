#ifndef __vo_box_hpp__
#define __vo_box_hpp__

#include <ui/visual_object.hpp>

namespace vp {

class vo_box : public visual_object {
public:
    DECLARE_TYPE(visual_object, vo_box);
public:
    vo_box(ptr<vo_document> doc, const wxRect& rect);

public:
    virtual bool contain(const wxPoint& pos) override;

public:
    virtual void on_draw(wxPaintDC* dc) override;
    virtual void on_mouse_down(wxMouseEvent* evt) override;
    virtual void on_mouse_move(wxMouseEvent* evt) override;
    virtual void on_mouse_up(wxMouseEvent* evt) override;
    virtual void on_mouse_move_out(wxMouseEvent* evt) override;

private:
    wxRect get_future_rect();
    long get_pos_edges(wxPoint pos);

protected:
    enum edge {
        LEFT    = 1,
        TOP     = 2,
        RIGHT   = 4,
        BOTTOM  = 8,
    };
    bool m_resizing;
    long m_resize_edges;
    wxPoint m_mouse_cur_pos;
    bool m_moving;
};

}

#endif
