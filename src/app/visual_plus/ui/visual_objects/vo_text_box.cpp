#include "vo_text_box.hpp"

namespace vp {
    vo_text_box::vo_text_box(ptr<vo_document> doc, const string& text, const wxRect& rect) :
        visual_object(doc, rect) {
            m_text = text;
    }

    void vo_text_box::on_draw(wxPaintDC* dc) {
        dc->DrawText(m_text, rect().GetLeftTop());
    }

    bool vo_text_box::contain(const wxPoint& pos) {
        return rect().Contains(pos);
    }

}