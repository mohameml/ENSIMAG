#ifndef _DVECTOR_H_
#define _DVECTOR_H_

/**
 * \file Dvector.h
 * \brief Vector of double
 * \author Arnaud Ibakuyumcu Benjamin Lebit
 * \version 3.0 (Subclass of Darray + scalar multiplication)
 * \date 23 February 2016
 *
 * \details The user could use vector of double in his project
 * \details Scale multiplication is available
 */

#include "Darray.h"

/**
 * \class Dvector
 * \brief Class which represent vectors of double
 *
 * \details This class manage the creation and utilisation of vector of double
 * \details All the classic operators
 */

class Dvector : public Darray{
public:
    //CONSTRUCTORS & DESTRUCTOR//

    /**
     * \fn Dvector()
     * \brief Constructor by default.
     *
     * This array is null
     */
    Dvector();
    /**
     * \fn Dvector(Darray const& tab)
     * \brief Conversion Array -> Vector
     *
     * \details It's necessary for Darray operator used with Dvector
     *
     * \param[in] Darray tab : The array to convert
     */
    Dvector(Darray const& tab);
    /**
     * \fn Dvector(int length, double value = 0.)
     * \brief Constructor with arguments
     *
     * \param[in] int length : The length of the vector
     * \param[in] double value : Value of the composants (default 0)
     *
     */
    explicit Dvector(int length, double value = 0.);
    /**
     * \fn Dvector(Dvector const& copie)
     * \brief Constructor by copy
     *
     * \details explicit to force compiler not to use the constructor with v * 2.2
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

};

// EXTERN METHOD //

/**
 * \fn double operator * (Dvector const& v1, Dvector const& v2)
 * \brief Multiplication scalar with two vector
 *
 * \param[in] Dvector : v1
 * \param[in] Dvector : v2
 *
 * \throw invalid_argument : if size is different or equal to 0
 *
 * \return double : v1.v2
 */
double operator * (Dvector const& v1, Dvector const& v2);

#endif // _DVECTOR_H_
