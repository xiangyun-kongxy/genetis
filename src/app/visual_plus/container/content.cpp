#include "content.hpp"

namespace vp {

content::~content(){

}

ptr<visual_object> content::get_cur_selected() {
    if (m_selected.size() > 0) {
        return m_selected.back();
    }
    return nullptr;
}

ptr<visual_object> content::get_select_history(int prev_num) {
    if (m_selected.size() > prev_num - 1) {
        list<ptr<visual_object>>::iterator i;
        for (i = m_selected.begin(); prev_num > 0; ++i) 
            --prev_num;
        return *i;
    }
    return nullptr;
}

ptr<command> content::get_cur_cmd() {
    return m_history->get_cur_cmd();
}

ptr<cmd_history> content::get_cmd_history() {
    return m_history;
}

ptr<mouse_status> content::get_cur_mouse() {
    if (m_mouse_history.size() > 0) {
        return m_mouse_history.back();
    }
    return nullptr;
}

ptr<mouse_status> content::get_mouse_history(int prev_num) {
    if (m_mouse_history.size() > prev_num - 1) {
        list<ptr<mouse_status>>::iterator i;
        for (i = m_mouse_history.begin(); prev_num > 0; ++i)
            --prev_num;
        return *i;
    }
    return nullptr;
}

ptr<keyboard_status> content::get_cur_keyboard() {
    if (m_keyboard_history.size() > 0) 
        return m_keyboard_history.back();
    return nullptr;
}
ptr<keyboard_status> content::get_keyboard_history(int prev_num) {
    if (m_keyboard_history.size() > prev_num - 1) {
        list<ptr<keyboard_status>>::iterator i;
        for (i = m_keyboard_history.begin(); prev_num > 0; ++i)
            --prev_num;
        return *i;
    }
    return nullptr;
}

void content::set_var(const string& name, ptr<object> value) {
    m_ex_var[name] = value;
}

ptr<object> content::get_var(const string& name) {
    return m_ex_var[name];
}

}
