#ifndef __visual_object_hpp__
#define __visual_object_hpp__

#include <wx/wx.h>

#include <visual_object/object/pi_protocol.hpp>
#include <visual_object/visual/visual.hpp>
#include <visual_object/depend/depend.hpp>

namespace vp {

class visual_object : public visual, depend {
public:
    DECLARE_TYPE(visual, visual_object);

public:
    visual_object(ptr<document> doc, const string& name) : visual(doc) {
        m_name = name;
    }

public:
    virtual string name()const override {
        return m_name;
    }

protected:
    string m_name;
};

}

#endif
