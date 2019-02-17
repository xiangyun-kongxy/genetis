#include "vo_document.hpp"
#include "content.hpp"
#include <windows/vo_view.hpp>
#include <ui/visual_object.hpp>

namespace vp {

vo_document::vo_document(const string name)
    : managed_object(name) {
    m_view = nullptr;
    m_content = new content;
}

void vo_document::set_view(vo_view* view) {
    if (m_view != nullptr)
        delete m_view;
    m_view = view;
}

vo_view* vo_document::get_view() {
    return m_view;
}

ptr<content> vo_document::get_content() {
    return m_content;
}

map<string, ptr<visual_object>>* vo_document::get_dataobjects() {
    return &m_objects;
}

}
