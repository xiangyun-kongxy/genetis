#include <visual_object/instace/resizer.hpp>
#include <visual_object/instace/visual_object_base.hpp>
#include <lib/macro/warn.hpp>
#include <window/view.hpp>

using namespace kxy;
namespace vp {

resizer::resizer(ptr<document> doc, ptr<visual_object_base> parent, int x, int y) :
    visual_object(doc, "noname") {
    set_parent(parent);
    set_pos(x, y);
    m_cursor = wxCURSOR_ARROW;
}

bool resizer::on_draw(ptr<dc> pdc) {
    pdc->draw_rect(m_rect.x, m_rect.y, m_rect.width, m_rect.height, 0);
    return true;
}

void resizer::set_pos(int x, int y) {
    int sx = x - resizer_size / 2;
    int sy = y - resizer_size / 2;
    m_rect = wxRect(sx, sy, resizer_size, resizer_size);
}

void resizer::on_move(long dx, long dy) {
    m_rect.SetX(m_rect.x + dx);
    m_rect.SetY(m_rect.y + dy);
    ((ptr<visual_object_base>)m_parent)->resize(this, dx, dy);
}

bool resizer::on_mouse_move_out(long unused(x), long unused(y), 
        long unused(flag)) {
    m_doc->get_view()->set_cursor(wxCURSOR_ARROW);
    return true;
}

bool resizer::on_mouse_move_in(long unused(x), long unused(y), 
        long unused(flag)) {
    m_doc->get_view()->set_cursor(m_cursor);
    return true;
}

void resizer::on_resize() {

}

void resizer::set_focus(bool unused(focus)) {
}

bool resizer::contain(long x, long y) {
    return m_rect.Contains(x, y);
}

bool resizer::intersect(wxRect& rect) {
    return m_rect.Intersects(rect);
}


void resizer::on_destroy_other(ptr<visual_object> unused(vo)) {

}

void resizer::on_destroy_other(ptr<pi_protocol> unused(obj)) {

}

void resizer::set_cursor(wxStockCursor cursor) {
    m_cursor = cursor;
}

}
