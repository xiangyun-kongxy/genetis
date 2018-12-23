#ifndef __content_hpp__
#define __content_hpp__

#include <list>
#include <map>
#include <string>
#include <lib/object/managed_object.hpp>
#include <visual_plus/ui/visual_object.hpp>
#include <visual_plus/action/cmd_history.hpp>
#include <visual_plus/action/info/mouse_status.hpp>
#include <visual_plus/action/info/keyboard_status.hpp>

using namespace kxy;
using namespace std;

namespace vp {

class content : public object {
public:
    DECLARE_TYPE(object, content);

public:
    virtual ~content();

public:
    ptr<visual_object> get_cur_selected();
    ptr<visual_object> get_select_history(int prev_num);

    ptr<command> get_cur_cmd();
    ptr<cmd_history> get_cmd_history();

    ptr<mouse_status> get_cur_mouse();
    ptr<mouse_status> get_mouse_history(int prev_num);

    ptr<keyboard_status> get_cur_keyboard();
    ptr<keyboard_status> get_keyboard_history(int prev_num);

    void set_var(const string& name, ptr<object> value);
    ptr<object> get_var(const string& name);

private:
    list<ptr<visual_object>> m_selected;
    ptr<cmd_history> m_history;
    list<ptr<mouse_status>> m_mouse_history;
    list<ptr<keyboard_status>> m_keyboard_history;
    map<string, ptr<object>> m_ex_var;
};

}

#endif

