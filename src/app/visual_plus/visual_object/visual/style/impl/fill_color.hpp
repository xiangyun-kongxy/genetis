#ifndef __fill_color_hpp__
#define __fill_color_hpp__

#include <visual_object/visual/style/fill.hpp>

namespace vp {
    
class fill_color : public fill {
public:
    DECLARE_TYPE(fill, fill_color);
public:
    fill_color(const wxColor& color) {
        m_color = new wxColor(color);
        m_brush = nullptr;
    }
public:
    virtual wxGraphicsBrush* get_brush(ptr<dc> pdc) override {
        if (m_brush == nullptr) {
            m_brush = new wxGraphicsBrush(
                    pdc->get_context()->CreateBrush(wxBrush(*m_color)));
        }
        return m_brush;
    }
private:
    wxGraphicsBrush* m_brush;
    wxColor* m_color;
};

}

#endif
