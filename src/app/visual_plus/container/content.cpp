#include "content.hpp"

namespace vp {

ptr<visual_object> content::get_cur_selected() {
    if (m_selected.size() > 0) {
        return m_selected.back();
    }
	return nullptr;
}

ptr<visual_object> content::get_select_history(int prev_num) {
    if (m_selected.size() > prev_num - 1) {
        list<ptr<visual_object>>::const_iterator i;
    }
	return nullptr;
}

ptr<command> content::get_cur_cmd() {
	return nullptr;
}

ptr<cmd_history> content::get_cmd_history() {
	return nullptr;
}

ptr<mouse_status> content::get_cur_mouse() {
	return nullptr;
}

ptr<mouse_status> content::get_mouse_history(int prev_num) {
	return nullptr;
}

ptr<keyboard_status> content::get_cur_keyboard() {
	return nullptr;
}
ptr<mouse_status> content::get_keyboard_history(int prev_num) {
	return nullptr;
}

void content::set_var(const string& name, ptr<object> value) {
}
ptr<object> content::get_var(const string& name) {
	return nullptr;
}

}
