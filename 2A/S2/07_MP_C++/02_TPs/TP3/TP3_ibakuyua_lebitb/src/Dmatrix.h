#ifndef TP3_IBAKUYUA_LEBITB_DMATRIX_H
#define TP3_IBAKUYUA_LEBITB_DMATRIX_H

/**
 * \file Dmatrix.h
 * \brief Matrix of double
 * \author Arnaud Ibakuyumcu Benjamin Lebit
 * \version 1.0
 * \date 3 March 2016
 *
 * \details The user could use matrix of double in his project.
 * \details Classic operators are available.
 */

#include "Darray.h"
#include "Dvector.h"

/**
 * \class Dmatrix
 * \brief Class which represent matrix of double
 *
 * \details This class manage the creation and utilisation of double matrix
 * \details All the classic operators are availables
 * \details Transpose and Cholesky algorithm is available
 */

class Dmatrix : public Darray {

private:
    int n; /**<Number of row*/
    int m; /**<Number of col*/

public:
    // CONSTRUCTORS & DESTRUCTOR//

    /**
     * \fn Dmatrix()
     * \brief Constructor by default
     *
     * This matrix is null
     */
    Dmatrix();
    /**
     * \fn explicit Dmatrix(int n, int m, double value = 0.)
     * \brief Constructor with arguments
     *
     * \param[in] int n : The number of rows
     * \param[in] int m : The number of columns
     * \param[in] double value : Value of composants (default 0)
     *
     */
    Dmatrix(int n, int m, double value = 0.);
    /**
     * \fn Dmatrix(Dmatrix const& copie)
     * \brief Constructor by copie
     *
     * \param[in] Dmatrix copie : The matrix to immitate
     *
     */
    Dmatrix(Dmatrix const& copie);
    /**
     * \fn Dmatrix(Darray const& copie)
     * \brief Conversion Array matrix(n,1)
     *
     * \param[in] Darray copie : The array to convert
     *
     */
    Dmatrix(Darray const& copie);
    /**
     * \fn ~Dmatrix()
     * \brief Destructor
     *
     */
    ~Dmatrix();

    // GETTERS //
    /**
     * \fn int lines()
     * \brief The number of lines of the matrix
     *
     * \details function inline
     *
     * \return int : N the number of lines
     */
    inline int lines() const{
        return n;
    }
    /**
     * \fn int columns()
     * \brief The number of columns of the matrix
     *
     * \details function inline
     *
     * \return int : N the number of columns
     */
    inline int columns() const{
        return m;
    }

    // OPERATORS OVERLOADED //

    /**
     * \fn double operator()(int i, int j)
     * \brief Access operator
     *
     * \param[in] int i : Number of the line
     * \param[in] int j : Number of the column
     *
     * \throw invalid_argument : if index is invalid
     *
     * \return double& : The reference of the matrix[i,j]
     */
    double& operator()(int i, int j) const;

    /**
     * \fn Dmatrix& operator=(const Dmatrix &copie)
     * \brief Equal operator overloaded
     *
     * \param[in] Dmatrix copie : Matrix to copy
     *
     */
    Dmatrix&operator=(const Dmatrix &copie);

    // EXTRACTION METHODS //

    /**
     * \fn Dvector line (int pos)
     * \brief Extract the line at position pos
     *
     * \param[in] int pos : The line position
     *
     * \throw invalid_argument : if index is invalid
     *
     * \return Dvector : The pos-eme line
     */
    Dvector line(int pos) const;

    /**
     * \fn Dvector column (int pos)
     * \brief Extract the column at position pos
     *
     * \param[in] int pos : The column position
     *
     * \throw invalid_argument : if index is invalid
     *
     * \return Dvector : The pos-eme column
     */
    Dvector column(int pos) const;

    // OTHERS METHODS //

    /**
     * \fn Dmatrix& transpose()
     * \brief Transpose the matrix
     *
     * \throw invalid_argument : if the matrix is not a square matrix
     *
     * \details Return Dmatrix& to be chainable
     * \details Algorithm is in place for square matrix
     * \details Cost O(1/2 * n^2)
     * \details Algorithm for general matrix is in comments
     */
    Dmatrix& transpose();

    /**
     * \fn Dmatrix& cholesky()
     * \brief Cholesky algorithm for symetric positive definite matrix
     *
     * \throw invalid_argument : if the matrix is not a square matrix
     * \throw invalid_argument : if the matrix is not symetric
     * \throw invalid_argument : if the matrix is not positive definite
     *
     * \details Algorithm in place
     * \details Cost O(n^2)
     *
     */
    Dmatrix& cholesky();

    /**
     * \fn matDisplay(std::ostream& flux)
     * \brief display a matrix vision in a stream
     *
     *
     * \param[in] std::ostream flux : the stream
     */
    void matDisplay(std::ostream& flux) const;

};

// EXTERN FUNCTION //
/**
 * \fn Dmatrix operator*(const Dmatrix &a, const Dmatrix &b)
 * \brief Matrix multiplication
 *
 * \throw invalid_argument : if sizes are invalid for the multiplication
 *
 * \param[in] Dmatrix a : Left matrix
 * \param[in] Dmatrix b : Right matrix
 *
 * \return Dmatrix : ab
 */
Dmatrix operator*(const Dmatrix &a, const Dmatrix &b);

/**
 * \fn Dvector operator*(const Dmatrix &a, const Dvector &x)
 * \brief Matrix multiplication with a vector
 *
 * \throw invalid argument : if sizes are invalid for the multiplication
 *
 * \param[in] Dmatrix a : Left matrix
 * \param[in] Dvector x : Right vector
 *
 * \return Dvector : ax
 */
Dvector operator*(const Dmatrix &a, const Dvector &x);

#endif //TP3_IBAKUYUA_LEBITB_DMATRIX_H
