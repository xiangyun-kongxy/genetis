#ifndef __cmd_history_hpp__
#define __cmd_history_hpp__

#include "command.hpp"
#include <lib/object/object.hpp>
using namespace kxy;

namespace vp {


class cmd_history : public object {
public:
    DECLARE_TYPE(object, cmd_history);

public:
    struct cmd_node {
        cmd_node* parent;
        cmd_node* left;
        cmd_node* right;
        ptr<command> cmd;
    };
public:
    cmd_history();
    virtual ~cmd_history();
public:
    ptr<command> get_cur_cmd() const;
    ptr<command> get_oldest_cmd() const;
    ptr<command> get_prev_cmd(ptr<command> cur) const;
    list<ptr<command>> get_next_cmd(ptr<command> cur) const;
public:
    virtual void new_cmd(ptr<command> cmd);
    virtual void undo();
    virtual void redo();
    virtual void redo(ptr<command> cmd);
    virtual void goto_status(ptr<command> cmd);

private:
    void remove(cmd_node* root);
    cmd_node* find(ptr<command> cmd, cmd_node* in) const;
    bool is_ancestor(cmd_node* ancestor, cmd_node* child) const;
    cmd_node* new_node(ptr<command> cmd);
protected:
    cmd_node* m_root;
    cmd_node* m_head;
};

}

#endif // __cmd_history_hpp__
