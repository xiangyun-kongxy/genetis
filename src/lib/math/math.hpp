#ifndef __math_hpp__
#define __math_hpp__

#include <math.h>

namespace kxy {

static int cmp(double a, double b) {
    if ((a-b)*(a-b) < 1e-12)
        return 0;
    else if (a < b)
        return -1;
    else 
        return 1;
}

}

#endif

