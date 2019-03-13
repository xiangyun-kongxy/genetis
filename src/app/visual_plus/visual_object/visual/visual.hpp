#ifndef __visual_hpp__
#define __visual_hpp__

#include <lib/object/ptr.hpp>
#include <visual_object/visual/style/style.hpp>

#include <map>
#include <string>
#include <list>

using namespace std;
using namespace kxy;

namespace vp {
    
class visual {
public:
    virtual bool on_draw(ptr<dc> pdc) = 0;

    virtual bool on_mouse_up(long x, long y, long flag) = 0;
    virtual bool on_mouse_down(long x, long y, long flag) = 0;
    virtual bool on_mouse_move_in(long x, long y, long flag) = 0;
    virtual bool on_mouse_move_out(long x, long y, long flag) = 0;
    virtual bool on_mouse_move(long x, long y, long flag) = 0;
    virtual bool on_mouse_click(long x, long y, long flag) = 0;
    virtual bool on_mouse_dclick(long x, long y, long flag) = 0;

    virtual bool on_key_up(long key, long flag) = 0;
    virtual bool on_key_down(long key, long flag) = 0;
    virtual bool on_char(long key, long flag) = 0;
public:
    virtual void on_resize() = 0;
    virtual bool contain(long x, long y) = 0;
    virtual bool intersect(wxRect& rect) = 0;
    virtual list<wxPoint> get_connect_points() = 0;
protected:
    map<string, ptr<style>> m_styles;
};

}

#endif
