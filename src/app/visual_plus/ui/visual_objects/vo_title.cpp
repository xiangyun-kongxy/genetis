#include "vo_title.hpp"
#include <arithmetic/layout/bounded/grid_layout.hpp>

namespace vp {

    vo_title::vo_title(ptr<vo_document> doc, const wxRect& rect,
        ptr<vo_image> type, ptr<vo_text_box> name) :
        vo_box(doc, rect) {
            ptr<box_layout> layout = new grid_layout(3, 4, {8, 16, 1}, {8, 16, 8, 1});
            layout->add((ptr<visual_object>)type, 5);
            layout->add((ptr<visual_object>)name, 7);
            set_layout(layout);
    }

    bool vo_title::contain(const wxPoint& pos) {
        return rect().Contains(pos);
    }

    void vo_title::on_draw(wxPaintDC* dc) {
        vo_box::on_draw(dc);

        dc->DrawRoundedRectangle(rect(), 2.0);
        for (ptr<visual_object> vo : get_children()) {
            vo->on_draw(dc);
        }
    }


}
