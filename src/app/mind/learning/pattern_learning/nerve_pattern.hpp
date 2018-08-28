#ifndef __nerve_pattern_hpp__
#define __nerve_pattern_hpp__

#include <nerve/edge.hpp>

#include <lib/object/reference.hpp>
#include <lib/object/ptr.hpp>

#include <map>

using namespace std;
using namespace kxy;

namespace mind {

    class nerve_pattern : public reference {
    protected:
        /// key-vlaue: vertex(barren) - edge object
        multimap<long, ptr<edge>> m_edges;
    };

}

#endif

