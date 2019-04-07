#ifndef __dc_hpp__
#define __dc_hpp__

#include <lib/object/object.hpp>
#include <wx/dcbuffer.h>
#include <wx/graphics.h>

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
    wxGraphicsContext* get_context();
    void set_brush(wxBrush* brush);
    void set_brush(wxGraphicsBrush* brush);
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
