#ifndef __managed_object_hpp__
#define __managed_object_hpp__

#include <lib/object/object.hpp>
#include <lib/object/ptr.hpp>
#include <list>

using namespace std;

namespace kxy {

class managed_object : public object {
public:
    DECLARE_TYPE(object, managed_object);

public:
    managed_object(const string& name);

public:
    virtual string name() const override;

protected:
    string m_name;

public:
    static ptr<object> get_by_id(string id);
    static ptr<object> get_by_name(string name);
    static list<ptr<object>> get_by_type(string type);
};

typedef managed_object mobject;

}

#endif
