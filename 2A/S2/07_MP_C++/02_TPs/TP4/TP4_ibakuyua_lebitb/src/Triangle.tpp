/**
 * \file Triangle.tpp
 * \brief Implementation of the class Triangle
 * \author Ibakuyumcu Arnaud and Lebit Benjamin
 * \version 1.0
 * \date 15 March 2016
 */

#include "Triangle.h"

template <typename Type>
Triangle<Type>::Triangle() {
    P1 = Point<Type>();
    P2 = Point<Type>();
    P3 = Point<Type>();
}

template <typename Type>
Triangle<Type>::Triangle(Point<Type> p1, Point<Type> p2, Point<Type> p3) {
    P1 = p1;
    P2 = p2;
    P3 = p3;
}

template <typename Type>
std::ostream &operator<<(std::ostream &flux, const Triangle<Type> &tr) {
    flux << tr.p1() << "\n" << tr.p2() << "\n" << tr.p3() << "\n" << tr.p1();
    return flux;
}
