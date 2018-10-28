#ifndef __matrix_hpp__
#define __matrix_hpp__

#include <lib/object/reference.hpp>
#include <lib/object/ptr.hpp>

using namespace kxy;

namespace vp {

class matrix : public reference {
public:
    matrix();
    matrix(double cr00, double cr10, double cr01, double cr11);

public:
    double* operator[](int i);

public:
    void add_transform(ptr<matrix> transform);

private:
    // |m_cr00, m_cr10|
    // |m_cr01, m_cr11|
    // m_cr[00,01,10,11]
    double m_cr[4];
};

}

#endif
