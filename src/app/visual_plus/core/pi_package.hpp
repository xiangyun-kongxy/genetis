#ifndef __pi_package_hpp__
#define __pi_package_hpp__

#include <core/pi_protocol.hpp>
#include <list>

using namespace std;

namespace vp {

class pi_package : public pi_protocol {
public:
    DECLARE_TYPE(pi_protocol, pi_package);
protected:
    list<ptr<pi_protocol>> m_children;
    list<ptr<pi_protocol>> m_ports;
};

}

#endif

