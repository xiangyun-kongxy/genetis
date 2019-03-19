#ifndef __interface_bar_hpp__
#define __interface_bar_hpp__

#include <visual_object/visual_object.hpp>

namespace vp {

class interface_bar : public visual_object {
public:
    DECLARE_TYPE(visual_object, interface_bar);

public:
    interface_bar(const string& name, int pos, int size);

public:
    virtual bool on_draw(ptr<dc> pdc) override;
public:
    virtual void on_resize() override;
    virtual bool contain(long x, long y) override;
    virtual bool intersect(wxRect& rect) override;
    virtual list<wxPoint> get_connect_points() override;
    virtual list<wxPoint> get_resize_points() override;

    virtual void on_destroy_other(ptr<visual_object> vo) override;
    virtual void on_destroy_other(ptr<pi_protocol> obj) override;

private:
    int m_pos;
    long m_size;
};

}

#endif
