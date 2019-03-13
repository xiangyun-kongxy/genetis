#ifndef __interface_bar_hpp__
#define __interface_bar_hpp__

#include <visual_object/visual_object.hpp>

namespace vp {

class interface_bar : public visual_object {
public:
    DECLARE_TYPE(visual_object, interface_bar);
public:
    virtual bool on_draw(ptr<dc> pdc) override;
public:
    virtual void on_resize() override;
    virtual bool contain(long x, long y) override;
    virtual bool intersect(wxRect& rect) override;
    virtual list<wxPoint> get_connect_points() override;

private:
    wxPoint m_pos;
    long m_size;
};

}

#endif
