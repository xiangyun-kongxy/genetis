#include "visual_object.hpp"

namespace vp {

void visual_object::draw() { 
    multimap<int, ptr<graph>>& graphs = m_graphs[m_status]; 
    for(pair<int, ptr<graph>> value : graphs) {
        value.second->draw();
    }
}

bool visual_object::in(ptr<point> pt) {
    multimap<int, ptr<graph>>& graphs = m_graphs[m_status]; 
    for (pair<int, ptr<graph>> value : graphs) {
        if (value.second->in(pt)) 
            return true;
    }
    return false;
}

void visual_object::set_transform(wxAffineMatrix2D& mat) {
    map<vo_status, multimap<int, ptr<graph>>>::iterator i;
    for (i = m_graphs.begin(); i != m_graphs.end(); ++i) {
        for (pair<int, ptr<graph>> value : i->second) {
            value.second->set_transform(mat);
        }
    }
}

vo_status visual_object::get_status() const {
    return m_status;
}

void visual_object::set_status(vo_status status) {
    m_status = status;
}

}