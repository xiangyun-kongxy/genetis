#include "dc.hpp"
#include <window/view.hpp>

namespace vp {

dc::dc(view* win) {
    m_dc = new wxAutoBufferedPaintDC(win);
    m_view = win;
}

dc::~dc() {
    delete m_dc;
}

void dc::draw_rect(int x, int y, int w, int h, int r) {
    transform(x, y, w, h, r);
    m_dc->DrawRoundedRectangle(x, y, w, h, r);
}

int dc::get_w() {
    int w, h;
    m_view->GetClientSize(&w, &h);
    return w;
}

int dc::get_h() {
    int w, h;
    m_view->GetClientSize(&w, &h);
    return h;
}

void dc::get_size(int& w, int& h) {
    m_view->GetClientSize(&w, &h);
}

void dc::transform(int& x, int& y, int& w, int& h, int& r) {
    int dx = m_view->get_dx();
    int dy = m_view->get_dy();
    double scale = m_view->get_scale();

    x += dx;
    y += dy;

    x *= scale;
    y *= scale;
    w *= scale;
    h *= scale;
    r *= scale;
}

void dc::transform(int& x, int& y, int& w, int& h) {
    int dx = m_view->get_dx();
    int dy = m_view->get_dy();
    double scale = m_view->get_scale();

    x += dx;
    y += dy;

    x *= scale;
    y *= scale;
    w *= scale;
    h *= scale;
}

void dc::transform(int& x, int& y) {
    int dx = m_view->get_dx();
    int dy = m_view->get_dy();
    double scale = m_view->get_scale();

    x += dx;
    y += dy;

    x *= scale;
    y *= scale;
}

void dc::transform(int& x, int& y, int& r) {
    int dx = m_view->get_dx();
    int dy = m_view->get_dy();
    double scale = m_view->get_scale();

    x += dx;
    y += dy;

    x *= scale;
    y *= scale;
    r *= scale;
}

}
