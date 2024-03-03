#ifndef SRC_POINT_H
#define SRC_POINT_H

#include <iostream>
/**
 * \file Point.h
 * \brief Class of bidimensional point
 * \author Ibakuyumcu Arnaud and Lebit Benjamin
 * \version 1.0
 * \date 14 March 2016
 *
 * \details Header of the class point in two dimension
 * \details It's a template class
 */

/**
 * \class Point
 * \brief Class which represent a point in two dimension
 *
 * \details It's a template class (double by default)
 */
template <typename Type = double> class Point {
private:
    // In Maj because there is the same name for the getter
    Type X; /**< First coordinate */
    Type Y; /**< Second coordinate */

public:
    // CONSTRUCTOR //
    /**
     * \fn Point(Type x = 0, Type y = 0)
     * \brief constructor
     *
     * \param Type x : The first coordinate
     * \param Type y : The second coordinate
     *
     * \details The coordinates are 0 by default
     */
    Point(const Type &x = 0, const Type &y = 0);

    // GETTER //
    /**
     * \fn Type x()
     * \brief First coordinate of the point
     *
     * \return Type : this->X
     *
     * \details Inline function
     */
    inline Type x() const{
        return X;
    }
    /**
     * \fn Type y()
     * \brief Second coordinate of the point
     *
     * \return Type : this->Y
     *
     * \details Inline function
     */
    inline Type y() const{
        return Y;
    }

    //METHOD TRANSFORMATION//
    /**
     * \fn void transformer(double m11, double m12, double m21, double m22)
     * \brief Affine transformation X' = XM
     *
     * \param double m11 : Element 1,1 of matrice transformation
     * \param double m12 : Element 1,2 of matrice transformation
     * \param double m21 : Element 2,1 of matrice transformation
     * \param double m22 : Element 2,2 of matrice transformation
     */
    void transformer(double m11, double m12, double m21, double m22);

    /**
     * \fn void deplacer(double dx, double dy)
     * \brief Deplacement transformation
     *
     * \param double dx : X Deplacement
     * \param double dy : Y Deplacement
     *
     * \details inline function
     */
    inline void deplacer(double dx,double dy){
        X += dx;
        Y += dy;
    }

    /**
     * \fn void tourner(double angle, const Point<Type>& pt)
     * \brief Rotation with an angle angle around the point pt
     * 
     * \param double angle : The angle of rotation in radian
     * \param Point pt : The point of rotation
     * 
     */
    void tourner(double angle, const Point<Type>& pt);
};

/**
 * \fn std::ostream& operator<<(std::ostream& flux, const Point<Type> point)
 * \brief Permit to display a Point in a flux
 *
 * \param std::ostream& flux : The flux
 * \param Point<Type> point : The point to display
 *
 * \return std::ostream& : The flux changed
 */
template <typename Type>
std::ostream& operator<<(std::ostream& flux, const Point<Type> point);

// Hint to separe implementation and definition
#include "Point.tpp"

#endif //SRC_POINT_H
