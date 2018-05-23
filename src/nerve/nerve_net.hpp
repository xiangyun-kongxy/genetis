#ifndef __nerve_net_hpp__
#define __nerve_net_hpp__

#include <nerve/edge.hpp>

#include <map>

using namespace std;

namespace mind {

    class nerve_net : public reference {
    protected:
        multimap<long, ptr<edge>> m_edges;
    };

}

#endif

