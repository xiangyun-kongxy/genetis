#ifndef __pi_convert_hpp__
#define __pi_convert_hpp__

#include <core/pi_value.hpp>

namespace vp {

class pi_convert : public pi_value {
public:
    DECLARE_TYPE(pi_value, pi_convert);
protected:
    ptr<pi_value> m_src;
    ptr<pi_type> m_output_type;
};

}

#endif
