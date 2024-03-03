#ifndef SRC_MAILLAGE_H
#define SRC_MAILLAGE_H

/**
 * \file Maillage.h
 * \brief Contain the class for a maillage
 * \author Ibakuyumcu Arnaud and Lebit Benjmain
 * \version 1.0
 * \date 15 March 2016
 *
 * \details Header of the class Maillage
 * \details Composated with multiple Triangle
 */


#include <list>
#include "Triangle.h"

/**
 * \class Maillage
 * \brief Class which permit to represent a Maillage of Triangle
 *
 * \details Template Class (Type (double of float) and Container)
 * \details Need template template (I visited stackoverflow.com)
 */

template<typename Type = double, template<typename = Triangle<Type>, typename = std::allocator<Triangle<Type> > > class Cont = std::list>
class Maillage {
private:
    Cont<> conteneur; /**< The container */
public:
    //CONSTRUCTOR //
    /**
     * \fn Maillage()
     * \brief Constructor by default
     *
     * \details n = m = 0
     * \details contenair = null
     */
    Maillage();

    /**
     * \fn Maillage(int m, int n, const Point<Type>& origine)
     * \brief Constructor with arguments
     *
     * \param int m : Number of horizontal segment
     * \param int n : Number of vertical segment
     *
     * \details Create the maillage for n in vertical, m in horizontal
     * \details The origine is the left bottom point
     * \details Use the container Cont and the type Type
     */
    Maillage(int m, int n, const Point<Type>& origine);

    /**
     * \fn Maillage(const Point<Type>& p1, const Point<Type>& p2, const Point<Type>& p3, const Point<Type>& p4, int m, int n )
     * \brief Constructor with a rectangle in argument
     *
     * \param Point<Type> p1 : First point of the rectangle
     * \param Point<Type> p2 : Second point of the rectangle
     * \param Point<Type> p3 : Third point of the rectangle
     * \param Point<Type> p4 : Fourth point of the rectangle
     * \param int m : Number of segment between p1 and p2
     * \param int n : Number of segment between p2 and p3
     *
     * \throw invalid_argument : If it isn't a rectangle
     *
     * \details Create the maillage in the rectangle
     */
    Maillage(const Point<Type>& p1, const Point<Type>& p2, const Point<Type>& p3, const Point<Type>& p4, int m, int n );

    //GETTER //
    /**
     * \fn Cont getCont()
     * \brief Getter for the container
     *
     * \return Cont : the container
     *
     * \details Inline function
     */
    //inline Cont getCont() const {
      //  return conteneur;
    //}


    //ITERATOR//
    /**
     * \fn Cont::iterator beginiter()
     * \brief const iterator on the begining of container
     *
     * \return Cont::iterator : conteneur.begin()
     *
     * \details Inline function
     * \details Need typename to precise that it's a typename and not a namespace
     */
    inline typename Cont<>::const_iterator beginiter()const{
        return conteneur.begin();
    }
    /**
     * \fn Cont::iterator enditer()
     * \brief const iterator on the end of container
     *
     * \return Cont::iterator : conteneur.end()
     *
     * \details Inline function
     */
    inline typename Cont<>::const_iterator enditer()const{
        return conteneur.end();
    }

    //TRANSFORMATION//
    /**
     * \fn void transformer(double m11, double m12, double m21, double m22)
     * \brief Affine transformation X' = XM for each point of each triangle
     *
     * \param double m11 : Element 1,1 of matrice transformation
     * \param double m12 : Element 1,2 of matrice transformation
     * \param double m21 : Element 2,1 of matrice transformation
     * \param double m22 : Element 2,2 of matrice transformation
     */
    void transformer(double m11, double m12, double m21, double m22);

    /**
     * \fn void deplacer(double dx, double dy)
     * \brief Deplacement transformation for each point of each triangle
     *
     * \param double dx : X Deplacement
     * \param double dy : Y Deplacement
     *
     * \details inline function
     */
    void deplacer(double dx, double dy);

    /**
     * \fn void tourner(double angle, const Point<Type>& pt)
     * \brief Rotation with an angle angle around the point pt for each point of each triangle
     *
     * \param double angle : The angle of rotation in radian
     * \param Point pt : The point of rotation
     *
     * \details inline function
     */
    void tourner(double angle, const Point<Type>& pt);

    // Friend method to display a maillage (need to access to the container)
    /**
     * \fn std::ostream& operator<<(std::ostream& flux, const Maillage<T,C>& mail)
     * \brief Permit to display a maillage
     *
     * \param std::ostream flux : The stream which will be writted in
     * \param Maillage<T,C> mail : The Maillage to display
     *
     * \return std::ostream : The stream
     *
     * \details Friend function
     * \details Depend on the template<typename T, typename C>
     */
    template<typename T, template<typename, typename> class C>
    friend std::ostream& operator<<(std::ostream& flux, Maillage<T,C>& mail);
};

#include "Maillage.tpp"


#endif //SRC_MAILLAGE_H
