
#include "vo_image.hpp"

namespace vp {

void __attribute__((constructor)) __init_image_handlers__() {
    wxImage::AddHandler(new wxJPEGHandler);
}

vo_image::vo_image(string path, wxRect rect) :
visual_object(rect) {
    wxImage image(path);
    double scale_width = (double) image.GetWidth() / rect.GetWidth();
    double scale_height = (double) image.GetHeight() / rect.GetHeight();
    double scale = scale_width > scale_height ? scale_width : scale_height;
    m_bitmap = new wxBitmap(image, -1, scale);
}

vo_image::~vo_image() {
}

void vo_image::on_draw(wxPaintDC* dc) {
    dc->DrawBitmap(*m_bitmap, m_rect.GetTopLeft());
}

}
