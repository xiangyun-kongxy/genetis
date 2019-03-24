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
        ptr<interface_bar> obj = new interface_bar(m_win->get_document(), "", 0, 0);
    }

    virtual void undo() override {
    }

    virtual string to_string() override {
        return "#class@cmd_new_interface_bar";
    }
};

}

#endif
