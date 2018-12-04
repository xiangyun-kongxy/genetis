
#include "vo_image.hpp"

namespace vp {

vo_image::vo_image(string path, wxRect rect) :
visual_object(rect) {
    wxImage image(rect.GetWidth(), rect.GetHeight());
    wxImage::AddHandler(new wxPNGHandler);
    wxImage::AddHandler(new wxJPEGHandler);
    image.LoadFile(path, wxBITMAP_TYPE_ANY);
    double scale = (double) image.GetWidth() / (double)rect.GetWidth();
    m_bitmap = new wxBitmap(image, -1, scale);
}

vo_image::~vo_image() {
}

void vo_image::on_draw(wxPaintDC* dc) {
    dc->DrawBitmap(*m_bitmap, m_rect.GetTopLeft());
}

}