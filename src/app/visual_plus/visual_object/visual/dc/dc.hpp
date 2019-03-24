#ifndef __dc_hpp__
#define __dc_hpp__

#include <lib/object/object.hpp>
#include <wx/dcbuffer.h>

using namespace kxy;

namespace vp {
    
class view;

class dc : public object {
public:
    DECLARE_TYPE(object, dc);
public:
    dc(view* win);
    virtual ~dc();

public:
    void draw_rect(int x, int y, int w, int h, int r);

public:
    int get_w();
    int get_h();
    void get_size(int& w, int& h);

private:
    wxAutoBufferedPaintDC* m_dc;
    view* m_view;
};

}

#endif
