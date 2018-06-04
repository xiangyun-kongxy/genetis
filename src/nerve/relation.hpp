#ifndef __relation_hpp__
#define __relation_hpp__

namespace mind {

    enum relation {
        R_RAW,

        R_EQUAL,

        // subject ~ subject
        R_CONTAIN,
        R_PART_OF,

        // subject ~ attribute
        R_HAS,

        // attribute ~ value
        R_BE,

        R_KIND_OF,

        R_CAUSATION,
    };

    // concepts:
    // subject
    // set of subjects
    // exist in set
    // relation
    // status: values of attributes
}

#endif

