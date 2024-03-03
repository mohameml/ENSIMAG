/**
 * \file Point.tpp
 * \brief Implementation of Point.h
 * \author Ibakuyumcu Arnaud and Lebit Benjmain
 * \version 1.0
 * \date 14 March 2016
 */

#include <math.h>
#include "Point.h"

template <typename Type>
Point<Type>::Point(const Type &x, const Type &y) {
    this->X = x;
    this->Y = y;
}

template <typename Type>
std::ostream &operator<<(std::ostream &flux, const Point<Type> point) {
    flux << point.x() << " " << point.y();
    return flux;
}

template <typename Type>
void Point<Type>::transformer(double m11, double m12, double m21, double m22) {
    double buf = X;
    X = buf * m11 + Y * m21;
    Y = buf * m12 + Y * m22;
}

template <typename Type>
void Point<Type>::tourner(double angle, const Point<Type> &pt) {
    // With pt as origine
    deplacer(-pt.x(),-pt.y());
    // Transformation with rotation matrix
    double buf1 = cos(angle);
    double buf2 = sin(angle);
    transformer(buf1,buf2,-buf2,buf1);
    // Return to the original spatial system
    deplacer(pt.x(),pt.y());
}
