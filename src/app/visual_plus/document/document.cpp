#include "document.hpp"
#include <window/view.hpp>
#include <visual_object/visual_object.hpp>

namespace vp {

document::document(const string name) {
    m_view = nullptr;
    m_name = name;
}

void document::set_view(view* view) {
    if (m_view != nullptr)
        delete m_view;
    m_view = view;
}

view* document::get_view() {
    return m_view;
}

map<string, ptr<visual_object>>* document::get_dataobjects() {
    return &m_objects;
}

}
