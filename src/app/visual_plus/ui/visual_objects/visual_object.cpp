#include "../visual_object.hpp"

namespace vp {

static string random_name() {
    char name[32];
    snprintf(name, 31, "unnamed-%d", rand());
    return name;
}

visual_object::visual_object(const string& name, const wxRect& rect) :
graph(rect), managed_object(name) {

}

visual_object::visual_object(const wxRect& rect) :
graph(rect), managed_object(random_name()) {

}

vo_status visual_object::get_status() const {
    return m_status;
}

void visual_object::set_status(vo_status status) {
    m_status = status;
}

}