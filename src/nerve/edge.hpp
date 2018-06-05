#ifndef __edge_h__
#define __edge_h__

#include <lib/object/reference.hpp>
#include <lib/object/ptr.hpp>

#include <nerve/relation.hpp>

using namespace kxy;

namespace mind {

    class edge : public reference {
    protected:
        long m_begin;
        long m_end;
        relation m_relation;
    };

    // concepts:
    //
    // subject
    // set of subjects
    //
    // status
    // causation
    //
    // exist in set
    // not exist in set

}

#endif

