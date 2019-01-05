#if !defined(__visual_object_hpp__)
#define __visual_object_hpp__

#include "vo_status.hpp"
#include "graph.hpp"
#include <lib/object/managed_object.hpp>
#include <visual_plus/arithmetic/layout/bounded/box_layout.hpp>
#include <visual_plus/action/event_handler.hpp>
#include <visual_plus/container/vo_document.hpp>
#include <map>

using namespace std;
using namespace kxy;

namespace vp {

class visual_object;
typedef visual_object* (*vo_creator)(ptr<vo_document> doc);

class visual_object : public event_handler, public graph, public managed_object {
public:
    DECLARE_TYPE(managed_object, visual_object);

public:
    visual_object(const string& name, const wxRect& rect);
    visual_object(const wxRect& rect);
    virtual vo_creator get_creator() = 0;

public:
    vo_status get_status() const;
    void set_status(vo_status status);

    ptr<vo_document> get_document();
    void set_document(ptr<vo_document> doc);

protected:
    vo_status m_status;
    ptr<vo_document> m_doc;
    ptr<box_layout> m_children;
};

} // namespace vp

#endif //__visual_object_hpp__
