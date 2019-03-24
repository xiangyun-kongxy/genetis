#include "document.hpp"
#include <window/view.hpp>
#include <visual_object/visual/visual.hpp>

namespace vp {

document::document(const string& name) {
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

const list<ptr<visual>>& document::get_objects() {
    return m_objects;
}

void document::add_object(ptr<visual> obj) {
    list<ptr<visual>>::iterator i = m_objects.begin();
    while(i != m_objects.end() && (*i)->get_layer() <= obj->get_layer()) {
        ++i;
    }
    m_objects.insert(i, obj);
}

}
