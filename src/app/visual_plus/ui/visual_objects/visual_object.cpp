#include "../visual_object.hpp"

namespace vp {

static string random_name() {
    char name[32];
    snprintf(name, 31, "unnamed-%d", rand());
    return name;
}

visual_object::visual_object(ptr<vo_document> doc, const string& name, const wxRect& rect) :
managed_object(name) {
    m_rect = rect;
    m_doc = doc;
}

visual_object::visual_object(ptr<vo_document> doc, const wxRect& rect) :
managed_object(random_name()) {
    m_rect = rect;
    m_doc = doc;
}

wxRect visual_object::rect() {
    return m_rect;
}

void visual_object::set_placement(const wxRect& rect) {
    m_rect = rect;
    if (m_layout != nullptr) {
        m_layout->resize(rect.x, rect.y, rect.width, rect.height);
        m_layout->apply();
    }
}

ptr<vo_document> visual_object::get_document() {
    return m_doc;
}

ptr<box_layout> visual_object::get_layout() {
    return m_layout;
}

void visual_object::set_layout(ptr<box_layout> layout) {
    m_layout = layout;
    set_placement(m_rect);
}

list<ptr<visual_object>> get_vo(ptr<box_layout> layout) {
    list<ptr<visual_object>> vos;
    for (ptr<object> obj : layout->get_objects()) {
        if (obj->is_kind_of("visual_object"))
            vos.push_back(obj);
        else if (obj->is_kind_of("box_layout")) {
            for (ptr<visual_object> vo : get_vo(obj))
                vos.push_back(vo);
        }
    }
    return vos;
}

list<ptr<visual_object>> visual_object::get_children() {
    if (m_layout != nullptr)
        return get_vo(m_layout);
    return list<ptr<visual_object>>();
}

}