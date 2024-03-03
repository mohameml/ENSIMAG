#ifndef _DVECTOR_H_
#define _DVECTOR_H_

/**
 * \file Dvector.h
 * \brief Vector of double
 * \author Arnaud Ibakuyumcu Benjamin Lebit
 * \version 2.0 (Operators added)
 * \date 8 February 2016
 *
 * \details The user could use vector of double in his project
 */

#include <iostream>


/**
 * \class Dvector
 * \brief Class which represent vectors of double
 *
 * \details This class manage the creation and utilisation of vector of double
 *
 */

class Dvector {

private:
    bool static srandIsNotInit; /**< To Init srand only once*/
    int static precision; /**< Precision of the double */
    double *vect; /**< The vector of double*/
    int length;   /**< The length of vector*/
public:

    //CONSTRUCTORS & DESTRUCTOR//

    /**
     * \fn Dvector()
     * \brief Constructor by default.
     *
     * This vector is null
     */
    Dvector();
    /**
     * \fn Dvector(int length, double value = 0.)
     * \brief Constructor with arguments
     *
     * \param[in] int length : The length of the vector
     * \param[in] double value : Value of the composants (default 0)
     *
     */
    Dvector(int length, double value = 0.);
    /**
     * \fn Dvector(Dvector const& copie)
     * \brief Constructor by copy
     *
     * \param[in] Dvector copie : The vector of double to immitate.
     *
     */
    Dvector(Dvector const& copie);
    /**
     * \fn Dvector(std::string)
     * \brief Constructor with a file parsing
     *
     * \param[in] string fichier : The file to parse
     *
     * \throw Exception invalid_argument if file doesn't exist
     *
     */
    Dvector(std::string const& fichier);
    /**
     * \fn ~Dvector()
     * \brief Destructor
     *
     */
    ~Dvector();

    //OPERATORS//

    /**
     * \fn double& operator()(int i) const
     * \brief Access operator
     *
     * \details Const because even if we can change value of vect[i], we don't change value of vect(ptr)
     *
     * \param[in] int i : Which element you want, in range [0,size-1]
     *
     * \return double& : The reference of i-eme element of vector of double
     */
    double& operator()(int i) const;

    /**
     * \fn Dvector& operator+=(Dvector const& v)
     * \brief Addition with a Dvector (or a double)
     *
     * \param[in] Dvector v or double d
     *
     * \return *this + v or *this + d depends on the argument
     */
    Dvector& operator+=(Dvector const& v);
    Dvector& operator+=(double const& d);

    /**
     * \fn Dvector& operator-=(Dvector const& v)
     * \brief Subtraction with a Dvector (or a double)
     *
     * \param[in] Dvector v or double d
     *
     * \return *this - v or *this - d depends on the argument
     */
    Dvector& operator-=(Dvector const& v);
    Dvector& operator-=(double const& d);

    /**
     * \fn Dvector& operator*=(double const& d)
     * \brief Multiplication with a double
     *
     * \param[in] double : d
     *
     * \return *this * d
     */
    Dvector& operator*=(double const& d);

    /**
     * \fn Dvector& operator/=(double const& d)
     * \brief Division with a double
     *
     * \param[in] double : d
     *
     * \return *this / d
     */
    Dvector& operator/=(double const& d);


    /**
     * \fn Dvector& operator=(Dvector const& copie)
     * \brief Redefinition of the operator =
     *
     * \param[in] Dvector copie : The vector of double to immitate
     *
     */
    Dvector& operator=(Dvector const& copie);

    /**
     * \fn bool operator==(Dvector const& v)
     * \brief Test if the vector is equal with the object
     *
     * \param[in] Dvector v : The vector to test
     *
     * \return bool : (*this == v) (for the values)
     */
    bool operator==(Dvector const& v) const ;

    /**
     * \fn bool operator!=(Dvector const& v)
     * \brief Test if the vector isn't equal with the object
     *
     * \param[in] Dvector v : The vector to test
     *
     * \return bool : (*this != v) (for the values)
     */
    bool operator!=(Dvector const& v) const ;

    //METHODS (with getters and setter)//

    /**
     * \fn void display(std::ostream& str) const
     * \brief Display in a flux the vector of double
     *
     * \param[out] ostream str : Stream in which we want to display the vector
     */
    void display(std::ostream& str) const;
    /**
     * \fn int size() const
     * \brief Length of the vector
     *
     * \return int : The length of the vector
     */
    int size() const;
    /**
     * \fn int fillRandomly() const
     * \brief Fill ramdomly the vector
     *
     * \details Simulation of a Uniform distribution in [0,1].
     * \details const because the value of vect don't change
     */
    void fillRandomly() const;

    /**
     * \fn double* getVect()
     * \brief Get the pointeur vect
     *
     * \return double* : vect
     */
    double * getVect();

    /**
     * \fn void static setPrecision(int precision)
     * \brief Set the precision desired (static method)
     *
     * \param[in] int prec : The precision that the user wants (default 53)
    */
    void static setPrecision(int prec=53);
    /**
     * \fn int static getPrecision()
     * \brief Get the curent precision (static method)
     *
     * \return int : The precision of Dvector class
     */
    int static getPrecision();

    /**
     * \fn void resize(int size, double value=0)
     * \brief Permit to resize a vector
     *
     * \param[in] int size : new size of your Dvector
     * \param[in] double value : value of component if you increase the size (default 0)
     */
    void resize(int size, double value=0);

};

// EXTERN METHODS //

/**
 * \fn Dvector operator+(const Dvector& v, const double& d)
 * \brief Addition between a vector and a double
 *
 * \param[in] Dvector or double : Left member
 * \param[in] Dvector or double : Right member
 *
 * \return Dvector : v + d
 */
Dvector operator+(const Dvector& v, const double& d);
Dvector operator+(const double& d, const Dvector& v);

/**
 * \fn Dvector operator-(const Dvector& v, const double& d)
 * \brief Subtraction between a vector and a double
 *
 * \param[in] double or Dvector : Left member
 * \param[in] double or Dvector : Right member
 *
 * \return v - d or d - v depends on the argument
 */
Dvector operator-(const Dvector& v, const double& d);
Dvector operator-(const double& d, const Dvector& v);

/**
 * \fn Dvector operator*(const Dvector& v, const double& d)
 * \brief Multiplication between a vector and a double
 *
 * \param[in] double or Dvector : Left member
 * \param[in] double or Dvector : Right member
 *
 * \return v * d
 */
Dvector operator*(const Dvector& v, const double& d);
Dvector operator*(const double& d,const Dvector& v);

/**
 * \fn Dvector operator/(const Dvector& v, const double& d)
 * \brief Division of a vector by a double
 *
 * \param[in] Dvector v : Left member
 * \param[in] double d : Right member
 *
 * \return v / d
 */
Dvector operator/(const Dvector& v, const double& d);

/**
 * \fn Dvector operator+(const Dvector& v1, const Dvector& v2)
 * \brief Addition between two vectors
 *
 * \param[in] Dvector v1 : Left member
 * \param[in] Dvector v2 : Right member
 *
 * \return v1 + v2
 */
Dvector operator+(const Dvector& v1, const Dvector& v2);

/**
 * \fn Dvector operator-(const Dvector& v1, const Dvector& v2)
 * \brief Subtraction between two vectors
 *
 * \param[in] Dvector v1 : Left member
 * \param[in] Dvector v2 : Right member
 *
 * \return v1 - v2
 */
Dvector operator-(const Dvector& v1, const Dvector& v2);

/**
 * \fn Dvector operator-(const Dvector& v)
 * \brief Opposate of a vector
 *
 * \param[in] Dvector v
 *
 * \return -v
 */
Dvector operator-(const Dvector& v);

/**
 * \fn std::ostream operator<<(std::ostream& str, const Dvector& v)
 * \brief Write a Dvector in a stream
 *
 * \param[in] ostream str : The stream in which we want write the Dvector
 * \param[in] Dvector v   : The Dvector
 *
 * \return ostream : str contained v
 *
 */
std::ostream& operator<<(std::ostream& str, const Dvector& v);

/**
 * \fn std::istream& operator>>(std::istream& str, const Dvector& v)
 * \brief Write a Dvector thanks to a stream
 *
 * \param[in] istream str : The stream where there is the data
 * \param[in] Dvector v : The vector to fill ( not resizable )
 *
 * \return istream : str
 *
 */
std::istream& operator>>(std::istream& str, const Dvector& v);

#endif // _DVECTOR_H_
