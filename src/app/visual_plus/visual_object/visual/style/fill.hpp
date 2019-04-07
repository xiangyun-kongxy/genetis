#ifndef __fill_h__
#define __fill_h__

#include "style.hpp"

namespace vp {

class fill : public style {
public:
    DECLARE_TYPE(style, fill);
public:
    virtual void apply(ptr<dc> pdc) override {
        pdc->set_brush(get_brush(pdc));
    }
public:
    virtual wxGraphicsBrush* get_brush(ptr<dc> pdc) = 0;
};

}

#endif
