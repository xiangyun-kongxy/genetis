
#include "../graph.hpp"

namespace vp {

graph::graph(wxRect rect) {
    m_rect = rect;
}

wxRect graph::get_rect() const {
    return m_rect;
}

void graph::set_rect(wxRect& rect) {
    m_rect = rect;
}

bool graph::hit_check(wxPoint& point) const {
    return m_rect.Contains(point);
}

}