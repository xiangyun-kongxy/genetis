#ifndef __pi_mixer_hpp__
#define __pi_mixer_hpp__

#include <visual_object/object/pi_slot.hpp>
#include <visual_object/object/pi_flow.hpp>

#include <list>
using namespace std;

namespace vp {
    
class pi_mixer : public pi_value {
public:
    DECLARE_TYPE(pi_value, pi_mixer);
protected:
    list<ptr<pi_slot>> m_params;
    ptr<pi_flow> m_flow;
    ptr<pi_type> m_ret_type;
};

}

#endif
