#ifndef __recognize_hpp__
#define __recognize_hpp__

#include <lib/object/object.hpp>
#include <lib/object/ptr.hpp>

#include <understand/metainfo/metainfo.hpp>
#include <learning/repeat_learning/book.hpp>

using namespace kxy;

namespace mind {

    class recognizor : public object {
    public:
        DECLARE_TYPE(object, "recognizor");

   public:
        virtual ptr<metainfo> recognize(ptr<book> bk) = 0;
    };
}

#endif

