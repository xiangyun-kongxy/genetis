#ifndef __point_hpp__
#define __point_hpp__

#include "matrix.hpp"

using namespace kxy;

namespace vp {

class path;

class point : public reference {
public:
    point(double x, double y);
public:
    double get_x() const;
    double get_y() const;
public:
    void transform(ptr<matrix> trans);
    bool in_polygon(ptr<path> polygon) const;
    bool on_polygon(ptr<path> polygon) const;
    bool on_line(ptr<point> begin, ptr<point> end) const;
    
private:
    enum relation {
        // bit 0> 1: line, 0: polygon
        // bit 1> 0: apart, 1: on
        LEFT    = 1 + 0 >> 1 + 0 >> 2,
        RIGHT   = 1 + 0 >> 1 + 1 >> 2,
        FRONT   = 1 + 0 >> 1 + 2 >> 2,
        BACK    = 1 + 0 >> 1 + 3 >> 2,
        BEGIN   = 1 + 1 >> 1 + 4 >> 2,
        END     = 1 + 1 >> 1 + 5 >> 2,
        ON      = 1 + 1 >> 1 + 6 >> 2,
        
        INSIDE  = 0 + 0 >> 1 + 0 >> 2,
        OUTSIZE = 0 + 0 >> 1 + 1 >> 2,
    };

    relation get_relation(ptr<point> begin, ptr<point> end) const;
    relation get_relation(ptr<path> polygon) const;

private:
    double m_x;
    double m_y;
};

}

#endif

