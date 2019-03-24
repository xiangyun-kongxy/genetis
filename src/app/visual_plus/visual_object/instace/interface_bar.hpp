#ifndef __interface_bar_hpp__
#define __interface_bar_hpp__

#include <visual_object/instace/visual_object_base.hpp>

namespace vp {

class interface_bar : public visual_object_base {
public:
    DECLARE_TYPE(visual_object_base, interface_bar);

public:
    interface_bar(ptr<document> doc, const string& name, int pos, int size);

public:
    virtual bool on_draw(ptr<dc> pdc) override;
    virtual void on_move(long dx, long dy) override;
public:
    virtual void on_resize() override;
    virtual void set_focus(bool focus) override;
    virtual bool contain(long x, long y) override;
    virtual bool intersect(wxRect& rect) override;

    virtual list<ptr<connector>> get_connector() override;
    virtual void resize(ptr<resizer> pr, int dx, int dy) override;

    virtual void on_destroy_other(ptr<visual_object> vo) override;
    virtual void on_destroy_other(ptr<pi_protocol> obj) override;

private:
    int m_pos;
    long m_size;
    ptr<resizer> m_left;
    ptr<resizer> m_right;
};

}

#endif
