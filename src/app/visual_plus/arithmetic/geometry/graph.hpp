#ifndef __graph_h__
#define __graph_h__

#include <app/visual_plus/arithmetic/geometry/path.hpp>
using namespace std;

namespace vp {

class graph {
public:
     virtual void draw();

public:
     virtual void transform(ptr<matrix> mat);
     virtual bool contain(ptr<point> pt);

public:
     virtual list<ptr<path>> get_paths();
};

}

#endif

