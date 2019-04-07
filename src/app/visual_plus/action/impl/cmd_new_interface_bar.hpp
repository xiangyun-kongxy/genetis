#ifndef __cmd_new_interface_bar_hpp__
#define __cmd_new_interface_bar_hpp__

#include <action/command.hpp>
#include <window/view.hpp>
#include <visual_object/instace/interface_bar.hpp>

namespace vp {

class cmd_new_interface_bar : public command {
public:
    DECLARE_TYPE(command, cmd_new_interface_bar);

public:
    cmd_new_interface_bar(view* win) : command(win) {
    }
public:
    virtual bool can_undo() const override {
        return true;
    }

    virtual void perform() override {
        wxPoint pos = m_win->get_mouse_pos();
        m_win->transform(pos.x, pos.y);
        m_obj = new interface_bar(m_win->get_document(), "", pos.x, 64);
        m_win->get_document()->add_object(m_obj);
    }

    virtual void undo() override {
    }

    virtual string to_string() override {
        return "#class@cmd_new_interface_bar";
    }

public:
    ptr<interface_bar> m_obj;
};

}

#endif
