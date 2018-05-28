#ifndef __vertex_cluster_hpp__
#define __vertex_cluster_hpp__

#include <nerve/vertex.hpp>

namespace mind {

    class vertex_cluster : public vertex {
    protected:
        list<long> m_vertexs;
        long m_cluster_type;
    }
}

#endif

