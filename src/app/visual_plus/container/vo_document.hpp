#ifndef __document_hpp__
#define __document_hpp__

#include <lib/object/managed_object.hpp>
#include <map>
#include <string>

using namespace kxy;
using namespace std;

namespace vp {

class vo_view;
class content;
class visual_object;

class vo_document : public managed_object {
public:
    DECLARE_TYPE(managed_object, vo_document);

public:
    vo_document(const string name);

public:
    void set_view(vo_view* view);
    vo_view* get_view();

    ptr<content> get_content();

    map<string, ptr<visual_object>>* get_dataobjects();

protected:
    map<string, ptr<visual_object>> m_objects;
    ptr<content> m_content;
    vo_view* m_view;
};

}

#endif