/**
 * \file Dvector.cpp
 * \brief Class Dvector implementation
 * \author Arnaud Ibakuyumcu Benjamin Lebit
 * \version 3.0 (Subclass of Darray + Scalar multiplication)
 * \date 23 February 2016
 *
 */
#include "Dvector.h"
#include <stdexcept>

using namespace std;


Dvector::Dvector() : Darray() {
}

Dvector::Dvector(int length, double value) : Darray(length,value) {
}

Dvector::Dvector(Darray const &tab) : Darray(tab) {
}

Dvector::Dvector(Dvector const &copie) : Darray(copie){
}

Dvector::Dvector(std::string const &fichier) : Darray(fichier) {
}


Dvector::~Dvector(){
}

double operator*(Dvector const &v1, Dvector const &v2) {
    double r = 0;
    if (v1.size() != v2.size() || v1.size() == 0){
        throw invalid_argument("You are trying to make a scalar multiplication with two vectors with different size or equal to 0");
    }
    for (int i = 0; i<v1.size(); i++){
        r += v1(i)*v2(i);
    }
    return r;
}
