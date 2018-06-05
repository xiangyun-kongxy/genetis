#ifndef __relation_hpp__
#define __relation_hpp__

namespace mind {

    enum relation {
        R_RAW,

        R_EQUAL,

        R_KIND_OF,

        R_CAUSATION,

        // subject ~ subject
        R_CONTAIN,
        R_PART_OF,

        // subject ~ attribute
        R_HAS,

        // attribute ~ value
        R_BE,

        // suject ~ action
        R_CAN,
    };

    // concepts:
    // subject
    // set of subjects
    // exist in set
    // relation
    // status: values of attributes
    // 
    // special objects:
    // time / sequence
    // quantity
    //
    // high level special objects:
    // myself
    //
}

#endif

