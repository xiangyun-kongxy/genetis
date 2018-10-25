#include <lib/object/managed_object.hpp>
#include <lib/container/cqueue.hpp>
#include <mutex>
#include <map>
#include <string>
#include <list>

using namespace std;

namespace kxy {

static map<string, ptr<object>> managed_object_ids;
static map<string, ptr<object>> managed_object_names;
static cqueue<ptr<object>> fresh_objects;
static std::mutex lock;

static void sort_objects();

managed_object::managed_object() {
    fresh_objects.push(this);
}

ptr<object> managed_object::get_by_id(string id) {
    sort_objects();
    return managed_object_ids[id];
}

ptr<object> managed_object::get_by_name(string name) {
    sort_objects();
    return managed_object_names[name];
}

list<ptr<object>> managed_object::get_by_type(string type) {
    sort_objects();
    list<ptr<object>> result;
    map<string,ptr<object>>::iterator i;
    for (i = managed_object_ids.begin(); i != managed_object_ids.end(); ++i) {
        if (i->second->is_kind_of(type))
            result.push_back(i->second);
    }
    return result;
}

void sort_objects() {
    ptr<object> obj = nullptr;
    do {
        obj = fresh_objects.try_pop();
        if (obj != nullptr) {
            lock.lock();
            managed_object_ids[obj->id()] = obj;
            managed_object_names[obj->name()] = obj;
            lock.unlock();
        }
    } while (obj != nullptr);
}

}
