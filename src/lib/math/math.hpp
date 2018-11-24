#ifndef __math_hpp__
#define __math_hpp__

#include <math.h>

namespace kxy {

    #define ZERO    1e-6

    static int cmp(double a, double b) {
        if (fabs(a-b) < ZERO)
            return 0;
        else if (a < b)
            return -1;
        else 
            return 1;
    }

}

#endif

