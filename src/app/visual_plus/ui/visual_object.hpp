#if !defined(__visual_object_hpp__)
#define __visual_object_hpp__

#include "vo_status.hpp"
#include "graph.hpp"
#include <lib/object/managed_object.hpp>
#include <arithmetic/layout/bounded/box_layout.hpp>
#include <action/event_handler.hpp>
#include <container/vo_document.hpp>
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
    visual_object(ptr<vo_document> doc, const string& name, const wxRect& rect);
    visual_object(ptr<vo_document> doc, const wxRect& rect);

public:
    wxRect rect();
    virtual void set_placement(const wxRect& rect);

    ptr<box_layout> get_layout();
    void set_layout(ptr<box_layout> layout);

    list<ptr<visual_object>> get_children();

    ptr<vo_document> get_document();

private:
    wxRect m_rect;
    ptr<vo_document> m_doc;
    ptr<box_layout> m_layout;
};

} // namespace vp

#endif //__visual_object_hpp__
