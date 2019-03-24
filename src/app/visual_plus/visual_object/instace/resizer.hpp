#ifndef __resizer_hpp__
#define __resizer_hpp__

#include <visual_object/visual_object.hpp>

namespace vp {

static const long resizer_size = 8L;

class visual_object_base;

class resizer : public visual_object {
public:
    DECLARE_TYPE(visual_object, connector);

public:
    resizer(ptr<document> doc, ptr<visual_object_base> parent, int x, int y);
public:
    virtual bool on_draw(ptr<dc> pdc) override;
    virtual void on_move(long dx, long dy) override;
    virtual bool on_mouse_move_out(long x, long y, long flag) override;
    virtual bool on_mouse_move_in(long x, long y, long flag) override;
public:
    virtual void set_focus(bool focus) override;
    virtual void on_resize() override;
    virtual bool contain(long x, long y) override;
    virtual bool intersect(wxRect& rect) override;

    virtual void on_destroy_other(ptr<visual_object> vo) override;
    virtual void on_destroy_other(ptr<pi_protocol> obj) override;

public:
    void set_pos(int x, int y);
    void set_cursor(wxStockCursor cursor);
private:
    wxRect m_rect;
    wxStockCursor m_cursor;
};

}

#endif

