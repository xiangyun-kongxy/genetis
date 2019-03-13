#ifndef __pi_protocol_hpp__
#define __pi_protocol_hpp__

#include <lib/object/object.hpp>
#include <lib/object/ptr.hpp>
using namespace kxy;

namespace vp {

class pi_protocol : public object {
public:
    DECLARE_TYPE(object, pi_protocol);
public:
    virtual string compile() const = 0;
    virtual string name() const override = 0;
protected:
    ptr<pi_protocol> m_parent;
    string m_comment;
};

}

#endif

