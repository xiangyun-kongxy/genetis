#ifndef __document_hpp__
#define __document_hpp__

#include <lib/object/object.hpp>
#include <lib/object/ptr.hpp>
#include <list>
#include <string>

using namespace kxy;
using namespace std;

namespace vp {

class view;
class visual;

class document : public object {
public:
    DECLARE_TYPE(object, document);

public:
    document(const string& name);

public:
    void set_view(view* view);
    view* get_view();
    const list<ptr<visual>>& get_objects();
    void add_object(ptr<visual> obj);

protected:
    list<ptr<visual>> m_objects;
    view* m_view;
    string m_name;
};

}

#endif
