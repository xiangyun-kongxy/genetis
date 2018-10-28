#ifndef __path_hpp__
#define __path_hpp__

#include <app/visual_plus/arithmetic/geometry/point.hpp>
#include <list>

using namespace std;

namespace vp {

class path : public reference {
public:
    // pair<point on path, control point of the first>
    typedef pair<ptr<point>, ptr<point>> arc_point;

public:
    void move_to(ptr<point> pt);
    void line_to(ptr<point> pt, ptr<point> ctrl = nullptr);
    void close_path();

public:
    list<arc_point> get_points() const;
    bool is_close() const;
    
private:
    list<arc_point> m_points;
    bool m_closed;
};

}

#endif

