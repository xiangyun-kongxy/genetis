#ifndef __document_hpp__
#define __document_hpp__

#include <lib/object/object.hpp>
#include <visual_object/visual_object.hpp>
#include <map>
#include <string>

using namespace kxy;
using namespace std;

namespace vp {

class view;
class visual_object;

class document : public object {
public:
    DECLARE_TYPE(object, document);

public:
    document(const string name);

public:
    void set_view(view* view);
    view* get_view();
    map<string, ptr<visual_object>>* get_objects();
    void add_object(ptr<visual_object> obj);

protected:
    map<string, ptr<visual_object>> m_objects;
    view* m_view;
    string m_name;
};

}

#endif
