#ifndef __visual_hpp__
#define __visual_hpp__

#include <lib/object/object.hpp>
#include <lib/object/ptr.hpp>
#include <visual_object/visual/style/style.hpp>
#include <document/document.hpp>

#include <map>
#include <string>
#include <list>

using namespace std;
using namespace kxy;

namespace vp {
    
class visual : public object {
public:
    DECLARE_TYPE(object, visual);
public:
    visual(ptr<document> doc);

public:
    virtual bool on_draw(ptr<dc> pdc);

    virtual bool on_mouse_wheel(long x, long y, long ds, long flag);
    virtual bool on_mouse_up(long x, long y, long flag);
    virtual bool on_mouse_down(long x, long y, long flag);
    virtual bool on_mouse_move_in(long x, long y, long flag);
    virtual bool on_mouse_move_out(long x, long y, long flag);
    virtual bool on_mouse_move(long x, long y, long flag);
    virtual bool on_mouse_dclick(long x, long y, long flag);

    virtual bool on_key_up(long key, long flag);
    virtual bool on_key_down(long key, long flag);
    virtual bool on_char(long key, long flag);
public:
    virtual void on_move(long dx, long dy) = 0;
    virtual void on_resize() = 0;
    virtual void set_focus(bool focus) = 0;

    virtual bool contain(long x, long y) = 0;
    virtual bool intersect(wxRect& rect) = 0;

public:
    bool is_visable() const;
    void set_visable(bool is_visable);

    long get_layer() const;
    void set_layer(long layer);

    ptr<visual> get_parent() const;
    void set_parent(ptr<visual> parent);

protected:
    wxMouseState m_mouse_status;
    map<string, ptr<style>> m_styles;
    ptr<document> m_doc;
    long m_layer;
    ptr<visual> m_parent;
    bool m_is_visable;
};

}

#endif
