#ifndef __dc_hpp__
#define __dc_hpp__

#include <lib/object/object.hpp>
#include <wx/dcbuffer.h>

using namespace kxy;

namespace vp {
    
class dc : public object {
public:
    DECLARE_TYPE(object, dc);
public:
    dc(wxWindow* win);
    virtual ~dc();

private:
    wxAutoBufferedPaintDC* m_dc;
};

}

#endif
