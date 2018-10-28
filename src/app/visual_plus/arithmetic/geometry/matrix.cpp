#include "matrix.hpp"

namespace vp {

matrix::matrix() : 
    matrix(1.0, 0.0, 0.0, 1.0) {
}

matrix::matrix(double cr00, double cr10, 
               double cr01, double cr11) {
    this->m_cr[0] = cr00;
    this->m_cr[1] = cr01;
    this->m_cr[2] = cr10;
    this->m_cr[3] = cr11;
}

double* matrix::operator[](int i) {
    return m_cr + i * 2;
}

void matrix::add_transform(ptr<matrix> transform) {
    matrix(m_cr[0] * transform->m_cr[0] + m_cr[2] * transform->m_cr[1],
           m_cr[1] * transform->m_cr[0] + m_cr[3] * transform->m_cr[1],
           m_cr[0] * transform->m_cr[2] + m_cr[2] * transform->m_cr[3],
           m_cr[1] * transform->m_cr[2] + m_cr[3] * transform->m_cr[3]);
}

}

