#ifndef __connnector_hpp__
#define __connnector_hpp__

#include <visual_object/visual_object.hpp>

namespace vp {

class visual_object_base;

enum connect_type {
    ct_in  = 1,
    ct_out = 2,
    ct_all = 3,
};

enum connector_style {
    cs_point,
    cs_pin,
};


class connector : public visual_object {
public:
    DECLARE_TYPE(visual_object, connector);
public:
    connector(ptr<document> doc, ptr<visual_object_base> parent, int x, int y,
            wxDirection dir = wxALL, 
            connect_type type = ct_all, 
            connector_style style = cs_point);
public:
    virtual bool on_draw(ptr<dc> pdc) override;
    virtual void on_move(long dx, long dy) override;
    virtual void on_resize() override;
public:
    virtual void set_focus(bool focus) override;
    virtual bool contain(long x, long y) override;
    virtual bool intersect(wxRect& rect) override;

    virtual void on_destroy_other(ptr<visual_object> vo) override;
    virtual void on_destroy_other(ptr<pi_protocol> obj) override;
public:
    void set_pos(int x, int y);
protected:
    connect_type m_type;
    connector_style m_style;
    wxDirection m_direction;
    wxPoint m_pos;
};

}

#endif
