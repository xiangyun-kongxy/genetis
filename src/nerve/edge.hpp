#ifndef __edge_h__
#define __edge_h__

#include <lib/object/reference.hpp>
#include <lib/object/ptr.hpp>

using namespace kxy;

namespace mind {

    class edge : public reference {
    protected:
        long m_start;
        long m_end;
        long digree;
    };

}

#endif
