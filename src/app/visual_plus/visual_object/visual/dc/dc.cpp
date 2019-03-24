#include "dc.hpp"
#include <window/view.hpp>

namespace vp {

dc::dc(view* win) {
    m_dc = new wxAutoBufferedPaintDC((wxWindow*)win);
    m_view = win;
}

dc::~dc() {
    char buf[64];
    int x = m_view->m_mouse_rpos.x;
    int y = m_view->m_mouse_rpos.y;
    m_view->rtransform(x, y);
    sprintf(buf, "dx:%d dy:%d sc:%lf | x:%d y:%d", 
            m_view->get_dx(), m_view->get_dy(), m_view->get_scale(),
            x, y);
    m_dc->DrawText(buf, 0, 0);
    delete m_dc;
}

void dc::draw_rect(int x, int y, int w, int h, int r) {
    m_view->transform(x, y, w, h, r);
    m_dc->DrawRoundedRectangle(x, y, w, h, r);
}

int dc::get_w() {
    return m_view->get_client_size().x;
}

int dc::get_h() {
    return m_view->get_client_size().y;
}

void dc::get_size(int& w, int& h) {
    wxSize size = m_view->get_client_size();
    w = size.x;
    h = size.y;
}

}
