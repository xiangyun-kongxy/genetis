#include "cmd_history.hpp"

namespace vp {

cmd_history::cmd_history() {
    m_root = nullptr;
    m_head = nullptr;
}

cmd_history::~cmd_history() {
    remove(m_root);
}

ptr<command> cmd_history::get_cur_cmd() const {
    if (m_head != nullptr)
        return m_head->cmd;
    return nullptr;
}

ptr<command> cmd_history::get_oldest_cmd() const {
    if (m_root != nullptr)
        return m_root->cmd;
    return nullptr;
}

ptr<command> cmd_history::get_prev_cmd(ptr<command> cur) const {
    cmd_node* node = find(cur, m_root);
    if (node != nullptr && node->parent != nullptr)
        return node->parent->cmd;
    return nullptr;
}
list<ptr<command>> cmd_history::get_next_cmd(ptr<command> cur) const {
    list<ptr<command>> cmds;
    cmd_node* node = find(cur, m_root);
    if (node != nullptr) {
        node = node->left;
        while (node != nullptr) {
            cmds.push_back(node->cmd);
            node = node->right;
        }
    }
    return cmds;
}
void cmd_history::new_cmd(ptr<command> cmd) {
    cmd_node* node = new_node(cmd);
    if (m_root == nullptr) {
        m_root = node;
    } else if (m_head->left == nullptr) {
        m_head->left = node;
    } else {
        cmd_node* old = m_head->left;
        while (old->right != nullptr)
            old = old->right;
        old->right = node;
    }
    m_head = node;
}

void cmd_history::undo() {
    if (m_head != m_root) {
        m_head->cmd->undo();
        m_head = m_head->parent;
    }
}

void cmd_history::redo() {
    if (m_head != nullptr && m_head->left != nullptr && 
            m_head->left->right == nullptr) {
        m_head = m_head->left;
        m_head->cmd->perform();
    }
}

void cmd_history::redo(ptr<command> cmd) {
    if (m_head != nullptr) {
        cmd_node* node = m_head->left;
        while (node != nullptr) {
            if (node->cmd == cmd) {
                m_head = node;
                m_head->cmd->perform();
            }
            node = node->right;
        }
    }
}

void cmd_history::goto_status(ptr<command> cmd) {
    cmd_node* node = find(cmd, m_root);
    if (node != nullptr) {
        while (m_head != node) {
            if (is_ancestor(m_head, node)) {
                cmd_node* child = m_head->left;
                while (child != node && !is_ancestor(child, node))
                    child = child->right;
                redo(child->cmd);
            } else {
                undo();
            }
        }
    }
}

void cmd_history::remove(cmd_node* root) {
    if (root != nullptr) {
        cmd_node* node = root->left;
        while (node != nullptr) {
            remove(node);
            node = node->right;
        }
        delete root;
    }
}

bool cmd_history::is_ancestor(cmd_node* ancestor, cmd_node* child) const {
    while (child != nullptr) {
        if (child == ancestor) {
            return true;
        }
        child = child->parent;
    }
    return false;
}

cmd_history::cmd_node* cmd_history::find(ptr<command> cmd, cmd_node* in) const {
    if (in != nullptr) {
        if (in->cmd == cmd)
            return in;
        cmd_node* node = find(cmd, in->left);
        if (node != nullptr)
            return node;
        return find(cmd, in->right);
    }
    return nullptr;
}

cmd_history::cmd_node* cmd_history::new_node(ptr<command> cmd) {
    cmd_node* node = new cmd_node;
    node->cmd = cmd;
    node->left = nullptr;
    node->right = nullptr;
    node->parent = m_head;
    return node;
}

}

