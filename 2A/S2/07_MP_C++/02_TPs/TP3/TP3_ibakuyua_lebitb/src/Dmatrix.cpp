/**
 * \file Dmatrix.cpp
 * \brief Class Dmatrix implementation
 * \author Arnaud Ibakuyumcu Benjamin Lebit
 * \version 1.0
 * \date 3 March 2016
 *
 */
#include "Dmatrix.h"
#include <stdexcept>
#include <cmath>
#include <iomanip>

using namespace std;

////////////////////////////////////////////////////
// Fonction utilisée dans l'algorithme de cholesky
// Inline pour éviter des pertes de temps
inline double sumChol(Dmatrix const& A, int i,int k){
    double r(0);
    for(int s = 0; s < k; s++){
        r += A(i,s)*A(k,s);
    }
    return r;
}
///////////////////////////////////////////////////
//IMPLEMENTATION DE Dmatrix.h
///////////////////////////////////////////////////

Dmatrix::Dmatrix() : Darray() {
    this->n = 0;
    this->m = 0;
}

Dmatrix::Dmatrix(int n, int m, double value) : Darray(n*m,value) {
    this->n = n;
    this->m = m;
}

Dmatrix::Dmatrix(Dmatrix const &copie) : Darray(copie){
    this->n = copie.n;
    this->m = copie.m;
}

Dmatrix::Dmatrix(Darray const &copie) : Darray(copie.size()){
    this->n = copie.size();
    this->m = 1;
    for (int i = 0; i < copie.size(); i++) {
        (*this)(i,0) = copie(i);
    }
}

Dmatrix::~Dmatrix() {
}

double& Dmatrix::operator()(int i, int j) const{
    if (i < 0 || j < 0 || i >= lines() || j >= columns()){
        throw invalid_argument("You're trying to access an element with invalid index");
    }
    return Darray::operator()(j+i*columns());
    // (*this)(j+i*columns()); ne fonctionne pas
}

Dmatrix &Dmatrix::operator=(const Dmatrix &copie) {
    if (this != &copie) {
        n = copie.n;
        m = copie.m;
        Darray::operator=(copie);
    }
    /*if (this != &copie) {
        length = copie.size();
        n = copie.n;
        m = copie.m;
        delete[] array;
        array = new double[size()];
        memcpy(array, copie.array, size() * sizeof(double));
    }*/
    return *this;
}
Dvector Dmatrix::line(int pos) const {
    if (pos < 0 || pos >= this->lines()){
        throw invalid_argument("You're trying to extract an invalid index line");
    }
    Dvector v(this->columns());
    for(int j = 0; j < v.size(); j++) {
        v(j) = (*this)(pos, j);
    }
    return v;
}

Dvector Dmatrix::column(int pos) const{
    if (pos < 0 || pos >= this->columns()){
        throw invalid_argument("You're trying to extract an invalid index column");
    }
    Dvector v(this->lines());
    for(int i = 0; i < v.size(); i++) {
        v(i) = (*this)(i,pos);
    }
    return v;
}

Dmatrix &Dmatrix::transpose() {
    // MATRICE CARRE : Algorithme en place
    if (lines() != columns()) {
        throw invalid_argument("You're trying to transpose a matrix which is not a square matrix");
    }
    double buf;
    for (int i = 0; i < lines(); i++){
        for (int j = 0; j < i; j++){
            buf = (*this)(i,j);
            (*this)(i,j) = (*this)(j,i);
            (*this)(j,i) = buf;
        }
    }
    return *this;

    // MATRICE RECTANGULAIRE
    /*Dmatrix buf(*this);
    // Change the dimension to avoid problem
    // with operator ()
    this->n = this->m;
    this->m = buf.n;
    // Transposition
    for (int i = 0; i < buf.lines(); i++){
        for (int j = 0; j < buf.columns(); j++){
            (*this)(j,i) = buf(i,j);
        }
    }
    return *this;
     */
}

Dmatrix &Dmatrix::cholesky() {
    if (this->lines() != this->columns()){
        throw invalid_argument("You're trying to decompose with cholesky a not square matrix");
    }
    // Verifie si la matrice est symétrique
    for (int i = 0; i < lines(); i++){
        for (int j = 0; j < i; j++){
            if ((*this)(i,j) != (*this)(j,i)){
                throw invalid_argument("You're trying to decompose with cholesky a not symetric matrix");
            }
        }
    }
    // Remplissage du triangle inférieur
    double val;
    for (int k = 0; k < columns(); k++){
        val = (*this)(k,k) - sumChol((*this),k,k);
        if (val < 0){
            throw invalid_argument("You're trying to decompose with cholesky a not positive definite matrix");
        }
        (*this)(k,k) = sqrt(val);
        for (int i = k+1; i < lines(); i++){
            (*this)(i,k) = ((*this)(i,k) - sumChol((*this),i,k))/(*this)(k,k);
        }
        // Remplissage du triangle supérieur = 0
        for (int i = 0; i < k; i++){
            (*this)(i,k) = 0;
        }
    }
    return (*this);
}

void Dmatrix::matDisplay(std::ostream &flux) const {
    for (int i = 0; i<lines(); i++){
        flux << "| ";
        for (int j = 0; j<columns(); j++){
            flux << setprecision(getPrecision()) << " (" << (*this)(i,j) << ") ";
        }
        flux << "|\n";
    }
}

Dmatrix operator*(const Dmatrix &a, const Dmatrix &b) {
    if (a.columns() != b.lines()){
        throw invalid_argument("You're trying to multiplicate two matrix with wrong size");
    }
    Dmatrix result(a.lines(),b.columns());
    for (int i = 0; i<result.lines(); i++){
        for (int j = 0; j<result.columns(); j++){
            result(i,j) = a.line(i)*b.column(j);
        }
    }
    return result;
}

Dvector operator*(const Dmatrix &a, const Dvector &x) {
    if (a.columns() != x.size()){
        throw invalid_argument("You're trying to multiplicate a matrix and a vector with wrong size");
    }
    Dvector resultat;
    Dmatrix b(x);
    resultat = (a*b).column(0);

    return resultat;
}
