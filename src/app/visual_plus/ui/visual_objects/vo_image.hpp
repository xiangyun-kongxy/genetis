#ifndef __vo_image_hpp__
#define __vo_image_hpp__

#include "../visual_object.hpp"

namespace vp
{
    
class vo_image : public visual_object {
public:
    DECLARE_TYPE(visual_object, vo_image);
public:
    vo_image(string path, wxRect rect);
    ~vo_image();
public:
    virtual void on_draw(wxPaintDC* dc) override;
protected:
    wxBitmap* m_bitmap;
};

}

#endif