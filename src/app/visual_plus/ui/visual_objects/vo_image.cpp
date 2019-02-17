
#include "vo_image.hpp"

namespace vp {

void __attribute__((constructor)) __init_image_handlers__() {
    wxImage::AddHandler(new wxJPEGHandler);
    wxImage::AddHandler(new wxPNGHandler);
}

vo_image::vo_image(ptr<vo_document> doc, const string& path, const wxRect& rect) :
visual_object(doc, rect) {
    wxImage image(path);
    double scale_width = (double) image.GetWidth() / rect.GetWidth();
    double scale_height = (double) image.GetHeight() / rect.GetHeight();
    double scale = scale_width > scale_height ? scale_width : scale_height;
    m_bitmap = new wxBitmap(image, -1, scale);
}

vo_image::~vo_image() {
}

bool vo_image::contain(const wxPoint& pos) {
    return rect().Contains(pos);
}

void vo_image::on_draw(wxPaintDC* dc) {
    dc->DrawBitmap(*m_bitmap, rect().GetTopLeft());
}

}
