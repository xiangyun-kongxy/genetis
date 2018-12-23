#include "vo_box.hpp"
#include <visual_plus/action/info/mouse_status.hpp>
#include <visual_plus/container/content.hpp>

namespace vp {

vo_box::vo_box(const wxRect& rect)
    : visual_object(rect) {
}

visual_object* create_vo_box(ptr<vo_document> doc) {
    ptr<content> ctt = doc->get_content();
    ptr<mouse_status> ms = ctt->get_cur_mouse();
    return new vo_box(wxRect(ms->x, ms->y, 50, 20));
}

vo_creator vo_box::get_creator() {
    return create_vo_box;
}

void vo_box::on_draw(wxPaintDC* dc) {
    dc->DrawRoundedRectangle(m_rect, 2.0);
}

}