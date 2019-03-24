#include "visual.hpp"
#include <lib/macro/warn.hpp>
#include <window/view.hpp>
#include <window/mouse_const.hpp>
#include <atomic>

using namespace kxy;
namespace vp {

static std::atomic_long g_cur_layer(0L);

visual::visual(ptr<document> doc) {
    m_doc = doc;
    m_parent = nullptr;
    m_is_visable = false;
    m_layer = g_cur_layer++;
}

bool visual::is_visable() const {
    return m_is_visable;
}

void visual::set_visable(bool is_visable) {
    m_is_visable = is_visable;
}

long visual::get_layer() const {
    return m_layer;
}

void visual::set_layer(long layer) {
    m_layer = layer;
}

ptr<visual> visual::get_parent() const {
    return m_parent;
}

void visual::set_parent(ptr<visual> parent) {
    m_parent = parent;
}

bool visual::on_draw(ptr<dc> unused(pdc)) {
    return false;
}

bool visual::on_mouse_wheel(long unused(x), long unused(y), 
        long unused(ds), long unused(flag)) {
    return false;
}

bool visual::on_mouse_up(long x, long y, long flag) {
    (void) flag;
    if (m_mouse_status.LeftIsDown()) {
        long dx = x - m_mouse_status.GetX();
        long dy = y - m_mouse_status.GetY();
        if (dx != 0 || dy != 0) {
            on_move(dx, dy);
        }
        m_mouse_status.SetLeftDown(false);
        m_doc->get_view()->release_mouse_event(this);
        return true;
    } else {
        return false;
    }
}

bool visual::on_mouse_down(long x, long y, long flag) {
    if (flag == flag_left_button) {
        m_mouse_status.SetLeftDown(true);
        m_mouse_status.SetX(x);
        m_mouse_status.SetY(y);
        m_doc->get_view()->capture_mouse_event(this);
        return true;
    } else {
        return false;
    }
}

bool visual::on_mouse_move(long x, long y, long flag) {
    (void) flag;
    if (m_mouse_status.LeftIsDown()) {
        long dx = x - m_mouse_status.GetX();
        long dy = y - m_mouse_status.GetY();
        if (dx != 0 || dy != 0) {
            m_mouse_status.SetX(x);
            m_mouse_status.SetY(y);
            on_move(dx, dy);
        }
        return true;
    } else {
        return false;
    }
}

bool visual::on_mouse_move_in(long unused(x), long unused(y), 
        long unused(flag)) {
    return false;
}
bool visual::on_mouse_move_out(long unused(x), long unused(y), 
        long unused(flag)) {
    return false;
}

bool visual::on_mouse_dclick(long unused(x), long unused(y), 
        long unused(flag)) {
    return false;
}

bool visual::on_key_up(long unused(key), long unused(flag)) {
    return false;
}

bool visual::on_key_down(long unused(key), long unused(flag)) {
    return false;
}

bool visual::on_char(long unused(key), long unused(flag)) {
    return false;
}

}

