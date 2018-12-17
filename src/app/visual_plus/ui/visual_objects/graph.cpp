
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

}