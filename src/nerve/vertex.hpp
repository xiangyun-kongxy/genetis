#ifndef __vertex_h__
#define __vertex_h__

#include <lib/object/reference.hpp>
#include <lib/object/ptr.hpp>

#include <map>

#include "edge.hpp"

using namespace std;
using namespace kxy;

namespace mind {

    class vertex : public reference {

    protected:
        long m_barren;
        map<long, ptr<edge>> m_edges;
    };

}

#endif

