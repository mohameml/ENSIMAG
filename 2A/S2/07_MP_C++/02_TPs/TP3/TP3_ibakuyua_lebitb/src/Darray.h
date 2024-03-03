#ifndef _DARRAY_H
#define _DARRAY_H

/**
 * \file Darray.h
 * \brief Array of double
 * \author Arnaud Ibakuyumcu Lebit Benjamin
 * \version 1.0
 * \date 23 february 2016
 *
 * \details The user could use an array of double.
 * \details Permit to create the subclasses Dvector and Dmatrix.
 */

/**
 * \class Darray
 * \brief Class which represent array of double.
 *
 * \details This class manage the creation and utilisation of array of double.
 * \details Contain all the necessary operators to implement Dmatrix and Dvector
 */

#include <iostream>

class Darray {
private:
    bool static srandIsNotInit; /**< To Init srand only once*/
    int static precision; /**< Precision of the double */
    int length; /**< The size of the array*/
    double *array; /**< The array of double */
public:
    //CONSTRUCTORS & DESTRUCTOR//

    /**
     * \fn Darray()
     * \brief Constructor by default.
     *
     * This array is null
     */
    Darray();
    /**
     * \fn Darray(int length, double value = 0.)
     * \brief Constructor with arguments
     *
     * \param[in] int length : The length of the array
     * \param[in] double value : Value of the composants (default 0)
     *
     */
    explicit Darray(int length, double value = 0.);
    /**
     * \fn Darray(Darray const& copie)
     * \brief Constructor by copy
     *
     * \details explicit to avoid problem with compiler which wants to convert a double in Darray
     *
     * \param[in] Darray copie : The array of double to immitate.
     *
     */
    Darray(Darray const& copie);
    /**
     * \fn Darray(std::string)
     * \brief Constructor with a file parsing
     *
     * \param[in] string fichier : The file to parse
     *
     * \throw Exception invalid_argument if file doesn't exist
     *
     */
    Darray(std::string const& fichier);
    /**
     * \fn ~Darray()
     * \brief Destructor
     *
     */
    inline ~Darray(){
        delete [] array;
    }

    //OPERATORS//

    /**
     * \fn double& operator()(int i) const
     * \brief Access operator
     *
     * \details Const because even if we can change value of vect[i], we don't change value of vect(ptr)
     *
     * \throw invalid_argument : if index is wrong
     *
     * \param[in] int i : Which element you want, in range [0,size-1]
     *
     * \return double& : The reference of i-eme element of array of double
     */
    double& operator()(int i) const;

    /**
     * \fn Darray& operator+=(Darray const& v)
     * \brief Addition with a Darray (or a double)
     *
     * \param[in] Darray v or double d
     *
     * \throw invalid_argument : if size is different
     *
     * \return *this + v or *this + d depends on the argument
     */
    Darray& operator+=(Darray const& v);
    Darray& operator+=(double const& d);

    /**
     * \fn Darray& operator-=(Darray const& v)
     * \brief Subtraction with a Darray (or a double)
     *
     * \param[in] Darray v or double d
     *
     * \throw invalid_argument : if size is different
     *
     * \return *this - v or *this - d depends on the argument
     */
    Darray& operator-=(Darray const& v);
    Darray& operator-=(double const& d);

    /**
     * \fn Darray& operator*=(double const& d)
     * \brief Multiplication with a double
     *
     * \param[in] double : d
     *
     * \return *this * d
     */
    Darray& operator*=(double const& d);

    /**
     * \fn Darray& operator/=(double const& d)
     * \brief Division with a double
     *
     * \param[in] double : d
     *
     * \throw invalid_argument : if there is a division by 0
     *
     * \return *this / d
     */
    Darray& operator/=(double const& d);


    /**
     * \fn Darray& operator=(Darray const& copie)
     * \brief Redefinition of the operator =
     *
     * \param[in] Darray copie : The array of double to immitate
     *
     */
    Darray& operator=(const Darray &copie);

    /**
     * \fn bool operator==(Darray const& v)
     * \brief Test if the array is equal with the object
     *
     * \param[in] Darray v : The array to test
     *
     * \return bool : (*this == v) (for the values)
     */
    bool operator==(Darray const& v) const ;

    /**
     * \fn bool operator!=(Darray const& v)
     * \brief Test if the array isn't equal with the object
     *
     * \param[in] Darray v : The array to test
     *
     * \details Inline function
     *
     * \return bool : (*this != v) (for the values)
     */
    inline bool operator!=(Darray const& v) const{
        return !((*this)==v);
    }

    //METHODS (with getters and setter)//

    /**
     * \fn double* getArray()
     * \brief Get the pointeur array
     *
     * \details Function inline
     *
     * \return double* : array
     */
    inline double * getArray() const {
        return array;
    }

    /**
     * \fn void static setPrecision(int precision)
     * \brief Set the precision desired (static method)
     *
     * \details Function inline
     *
     * \param[in] int prec : The precision that the user wants (default 53)
    */
    inline void static setPrecision(int prec=53){
        precision = prec;
    }
    /**
     * \fn int static getPrecision()
     * \brief Get the curent precision (static method)
     *
     * \details Function inline
     *
     * \return int : The precision of Dvector class
     */
    inline int static getPrecision(){
        return precision;
    }

    /**
     * \fn int size() const
     * \brief Length of the array
     *
     * \details Function inline
     *
     * \return int : The length of the array
     */
    inline int size() const {
        return length;
    }

    /**
     * \fn void display(std::ostream& str) const
     * \brief Display in a flux the array of double
     *
     * \param[out] ostream str : Stream in which we want to display the array
     */
    void display(std::ostream& str) const;

    /**
     * \fn int fillRandomly() const
     * \brief Fill ramdomly the array
     *
     * \details Simulation of a Uniform distribution in [0,1].
     * \details const because the value of vect don't change
     */
    void fillRandomly() const;

    /**
     * \fn void resize(int size, double value=0)
     * \brief Permit to resize a array
     *
     * \param[in] int size : new size of your Darray
     * \param[in] double value : value of component if you increase the size (default 0)
     */
    void resize(int size, double value=0);

};

// EXTERN METHODS //

/**
 * \fn Darray operator+(const Darray& v, const double& d)
 * \brief Addition between a array and a double
 *
 * \param[in] Darray or double : Left member
 * \param[in] Darray or double : Right member
 *
 * \details Inline is used
 *
 * \return Darray : v + d
 */
Darray operator+(const Darray& v, const double& d);
inline Darray operator+(const double& d, const Darray& v){
    return (v+d);
}

/**
 * \fn Darray operator-(const Darray& v, const double& d)
 * \brief Subtraction between a array and a double
 *
 * \param[in] double or Darray : Left member
 * \param[in] double or Darray : Right member
 *
 * \details Inline is used
 *
 * \return v - d or d - v depends on the argument
 */
inline Darray operator-(const Darray& v, const double& d){
    return (v+(-d));
}
Darray operator-(const double& d, const Darray& v);

/**
 * \fn Darray operator*(const Darray& v, const double& d)
 * \brief Multiplication between a array and a double
 *
 * \param[in] double or Darray : Left member
 * \param[in] double or Darray : Right member
 *
 * \details Inline is used
 *
 * \return v * d
 */
Darray operator*(const Darray& v, const double& d);
inline Darray operator*(const double& d,const Darray& v){
    return (v*d);
}

/**
 * \fn Darray operator/(const Darray& v, const double& d)
 * \brief Division of a array by a double
 *
 * \param[in] Darray v : Left member
 * \param[in] double d : Right member
 *
 * \return v / d
 */
Darray operator/(const Darray& v, const double& d);

/**
 * \fn Darray operator+(const Darray& v1, const Darray& v2)
 * \brief Addition between two arrays
 *
 * \param[in] Darray v1 : Left member
 * \param[in] Darray v2 : Right member
 *
 * \throw invalid_argument : if size is different
 *
 * \return v1 + v2
 */
Darray operator+(const Darray& v1, const Darray& v2);

/**
 * \fn Darray operator-(const Darray& v1, const Darray& v2)
 * \brief Subtraction between two arrays
 *
 * \param[in] Darray v1 : Left member
 * \param[in] Darray v2 : Right member
 *
 * \throw invalid_argument : if size is different
 *
 * \return v1 - v2
 */
Darray operator-(const Darray& v1, const Darray& v2);

/**
 * \fn Darray operator-(const Darray& v)
 * \brief Opposate of a array
 *
 * \param[in] Darray v
 *
 * \return -v
 */
Darray operator-(const Darray& v);

/**
 * \fn std::ostream operator<<(std::ostream& str, const Darray& v)
 * \brief Write a Darray in a stream
 *
 * \param[in] ostream str : The stream in which we want write the Darray
 * \param[in] Darray v   : The Darray
 *
 * \return ostream : str contained v
 *
 */
std::ostream& operator<<(std::ostream& str, const Darray& v);

/**
 * \fn std::istream& operator>>(std::istream& str, const Darray& v)
 * \brief Write a Darray thanks to a stream
 *
 * \param[in] istream str : The stream where there is the data
 * \param[in] Darray v : The array to fill ( not resizable )
 *
 * \return istream : str
 *
 */
std::istream& operator>>(std::istream& str, const Darray& v);

#endif // _DARRAY_H
