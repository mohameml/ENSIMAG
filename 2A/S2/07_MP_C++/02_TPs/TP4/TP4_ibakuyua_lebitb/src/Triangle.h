#ifndef SRC_TRIANGLE_H
#define SRC_TRIANGLE_H

/**
 * \file Triangle.h
 * \brief Contain the class for a triangle
 * \author Ibakuyumcu Arnaud and Lebit Benjamin
 * \version 1.0
 * \date 15 March 2016
 *
 * \details Header of the class triangle
 * \details Composated with three Points
 */


#include "Point.h"

/**
 * \class Triangle
 * \brief Class which permit to represent a triangle
 *
 * \details (Composated with three Points)
 * \details Template class
 */
template <typename Type = double> class Triangle {
private:
    Point<Type> P1; /**< First point */
    Point<Type> P2; /**< Second point */
    Point<Type> P3; /**< Third point */
public:
    // CONSTRUCTOR //
    /**
     * \fn Triangle()
     * \brief Constructor by default
     *
     * \details The tree points are (0,0) in double
     */
    Triangle();

    /**
     * \fn Triangle(Point p1, Point p2, Point p3)
     * \brief Constructor with arguments
     *
     * \param Point p1 : First point
     * \param Point p2 : Second point
     * \param Point p3 : Third point
     *
     * \details Permit to set the three points
     */
    Triangle(Point<Type> p1, Point<Type> p2, Point<Type> p3);

    // GETTER //
    /**
     * \fn Point p1()
     * \brief First Point of the Triangle
     *
     * \return Point : this->P1
     *
     * \details Inline function
     */
    inline Point<Type> p1() const{
        return P1;
    }
    /**
     * \fn Point p2()
     * \brief Second Point of the Triangle
     *
     * \return Point : this->P2
     *
     * \details Inline function
     */
    inline Point<Type> p2() const{
        return P2;
    }
    /**
     * \fn Point p3()
     * \brief Third Point of the Triangle
     *
     * \return Point : this->P3
     *
     * \details Inline function
     */
    inline Point<Type> p3() const{
        return P3;
    }

    //TRANSFORMATION//
    /**
     * \fn void transformer(double m11, double m12, double m21, double m22)
     * \brief Affine transformation X' = XM for each point
     *
     * \param double m11 : Element 1,1 of matrice transformation
     * \param double m12 : Element 1,2 of matrice transformation
     * \param double m21 : Element 2,1 of matrice transformation
     * \param double m22 : Element 2,2 of matrice transformation
     *
     * \details inline function
     */
    inline void transformer(double m11, double m12, double m21, double m22){
        P1.transformer(m11,m12,m21,m22);
        P2.transformer(m11,m12,m21,m22);
        P3.transformer(m11,m12,m21,m22);
    }

    /**
     * \fn void deplacer(double dx, double dy)
     * \brief Deplacement transformation for each point
     *
     * \param double dx : X Deplacement
     * \param double dy : Y Deplacement
     *
     * \details inline function
     */
    inline void deplacer(double dx, double dy){
        P1.deplacer(dx,dy);
        P2.deplacer(dx,dy);
        P3.deplacer(dx,dy);
    }

    /**
     * \fn void tourner(double angle, const Point<Type>& pt)
     * \brief Rotation with an angle angle around the point pt for each point
     *
     * \param double angle : The angle of rotation in radian
     * \param Point pt : The point of rotation
     *
     * \details inline function
     */
    inline void tourner(double angle, const Point<Type>& pt){
        P1.tourner(angle,pt);
        P2.tourner(angle,pt);
        P3.tourner(angle,pt);
    }
};

/**
 * \fn std::ostream& operator<<(std::ostream& flux, const Triangle<Type>& tr)
 * \brief Permit to display a Triangle in a flux
 *
 * \param std::ostream& flux : The flux
 * \param Triangle<Type> tr : The triangle to display
 *
 * \return std::ostream& : The flux changed
 */
template <typename Type>
std::ostream& operator<<(std::ostream& flux, const Triangle<Type>& tr);

#include "Triangle.tpp"

#endif //SRC_TRIANGLE_H
