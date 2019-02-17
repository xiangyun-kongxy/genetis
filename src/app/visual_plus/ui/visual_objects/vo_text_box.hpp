#ifndef __vo_text_box_hpp__
#define __vo_text_box_hpp__

#include <ui/visual_object.hpp>

namespace vp {

    class vo_text_box : public visual_object {
    public:
        vo_text_box(ptr<vo_document> doc, const string& text, const wxRect& rect);

    public:
        virtual void on_draw(wxPaintDC* dc) override;

    public:
        virtual bool contain(const wxPoint& pos) override;

    protected:
        string m_text;
    };

}

#endif
