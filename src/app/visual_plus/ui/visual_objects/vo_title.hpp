#ifndef __vo_title_hpp__
#define __vo_title_hpp__

#include <ui/visual_objects/vo_text_box.hpp>
#include <ui/visual_objects/vo_image.hpp>
#include <ui/visual_objects/vo_box.hpp>

namespace vp {

    class vo_title : public vo_box {
    public:
        vo_title(ptr<vo_document> doc, const wxRect& rect,
                ptr<vo_image> type, ptr<vo_text_box> name);
    public:
        virtual bool contain(const wxPoint& pos) override;

    public:
        virtual void on_draw(wxPaintDC* dc) override;

    };

}

#endif
