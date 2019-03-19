#ifndef __visual_object_hpp__
#define __visual_object_hpp__

#include <wx/wx.h>

#include <visual_object/object/pi_protocol.hpp>
#include <visual_object/visual/visual.hpp>

namespace vp {

class visual_object : public visual, public object {
public:
    DECLARE_TYPE(object, visual_object);

public:
    visual_object(const string& name) {
        m_name = name;
    }

public:
    virtual string name()const override {
        return m_name;
    }

public:
    virtual void on_destroy_other(ptr<visual_object> vo) = 0;
    virtual void on_destroy_other(ptr<pi_protocol> obj) = 0;

protected:
    string m_name;
};

}

#endif
