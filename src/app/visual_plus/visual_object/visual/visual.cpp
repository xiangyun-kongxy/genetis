#include "visual.hpp"

namespace vp {

bool visual::on_draw(ptr<dc> pdc) {
    return false;
}

bool visual::on_mouse_up(long x, long y, long flag) {
    return false;
}

bool visual::on_mouse_down(long x, long y, long flag) {
    return false;
}

bool visual::on_mouse_move_in(long x, long y, long flag) {
    return false;
}
bool visual::on_mouse_move_out(long x, long y, long flag) {
    return false;
}

bool visual::on_mouse_move(long x, long y, long flag) {
    return false;
}

bool visual::on_mouse_click(long x, long y, long flag) {
    return false;
}

bool visual::on_mouse_dclick(long x, long y, long flag) {
    return false;
}

bool visual::on_key_up(long key, long flag) {
    return false;
}

bool visual::on_key_down(long key, long flag) {
    return false;
}

bool visual::on_char(long key, long flag) {
    return false;
}

}

