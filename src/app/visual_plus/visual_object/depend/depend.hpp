#ifndef __depend_hpp__
#define __depend_hpp__

#include <lib/object/ptr.hpp>

using namespace kxy;
namespace vp {

class visual_object;
class pi_protocol;

class depend {
public:
    virtual void on_destroy_other(ptr<visual_object> vo) = 0;
    virtual void on_destroy_other(ptr<pi_protocol> obj) = 0;
};

}

#endif
