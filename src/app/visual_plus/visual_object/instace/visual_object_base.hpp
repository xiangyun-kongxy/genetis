#ifndef __visual_object_base_hpp__
#define __visual_object_base_hpp__

#include <visual_object/visual_object.hpp>
#include <visual_object/instace/resizer.hpp>
#include <visual_object/instace/connector.hpp>

namespace vp {

class visual_object_base : public visual_object {
public:
    DECLARE_TYPE(visual_object, visual_object_base);
public:
    visual_object_base(ptr<document> doc, const string& name) : 
        visual_object(doc, name) {
    }
public:
    virtual list<ptr<connector>> get_connector() = 0;
    virtual void resize(ptr<resizer> pr, int dx, int dy) = 0;
};

}

#endif
