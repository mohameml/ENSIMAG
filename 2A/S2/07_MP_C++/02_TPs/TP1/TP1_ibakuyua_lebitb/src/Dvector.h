#ifndef _DVECTOR_H_
#define _DVECTOR_H_

/**
 * \file Dvector.h
 * \brief Vector of double
 * \author Arnaud Ibakuyumcu Benjamin Lebit
 * \version 1.0
 * \date 3 February 2016
 *
 * \details The user could use vector of double in his project
 */

#include <string>
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
    int static precision; /**< Precision of the double */
    double *vect; /**< The vector of double*/
    int length;   /**< The length of vector*/
public:
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
    Dvector(std::string fichier);
    /**
     * \fn ~Dvector()
     * \brief Destructor
     *
     */
    ~Dvector();

    /**
     * \fn Dvector& operator=(Dvector const& copie)
     * \brief Redefinition of the operator =
     *
     * \param[in] Dvector copie : The vector of double to immitate
     *
     */
    Dvector& operator=(Dvector const& copie);

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
     * \fn int fillRandomly()
     * \brief Fill ramdomly the vector
     *
     * \details Simulation of a Uniform distribution in [0,1].
     * \details const because the value of vect don't change.
     */
    void fillRandomly() const;
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

};

#endif // _DVECTOR_H_
