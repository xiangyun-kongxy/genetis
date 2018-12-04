#if !defined(__visual_object_hpp__)
#define __visual_object_hpp__

#include "vo_status.hpp"
#include "graph.hpp"
#include <lib/object/managed_object.hpp>
#include <visual_plus/arithmetic/layout/bounded/box_layout.hpp>
#include <visual_plus/action/event_handler.hpp>
#include <map>

using namespace std;
using namespace kxy;

namespace vp {

class visual_object : public event_handler, public graph, public managed_object {
public:
    DECLARE_TYPE(managed_object, visual_object);

public:
    visual_object(const string& name, const wxRect& rect);
    visual_object(const wxRect& rect);

public:
    vo_status get_status() const;
    void set_status(vo_status status);

protected:
    vo_status m_status;
    ptr<box_layout> child;
};

} // namespace vp

#endif //__visual_object_hpp__
