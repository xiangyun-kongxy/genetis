#ifndef __pi_flow_hpp__
#define __pi_flow_hpp__

#include <visual_object/object/stt/pi_begin.hpp>
#include <visual_object/object/stt/pi_end.hpp>

#include <lib/object/ptr.hpp>
#include <list>

using namespace std;
using namespace kxy;

namespace vp {

class pi_flow : public pi_protocol {
public:
    DECLARE_TYPE(pi_protocol, pi_flow);
protected:
    ptr<pi_begin> m_begin;
    ptr<pi_end> m_end;
    list<ptr<pi_stt>> m_nodes;
};

}

#endif

