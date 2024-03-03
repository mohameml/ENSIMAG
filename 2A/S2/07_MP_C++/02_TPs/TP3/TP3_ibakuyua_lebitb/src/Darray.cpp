/**
 * \file Darray.cpp
 * \brief Class Darray implementation
 * \author Arnaud Ibakuyumcu Benjamin Lebit
 * \version 1.0
 * \date 23 February 2016
 *
 */
#include "Darray.h"
#include <iomanip> // Pour setprecision
#include <fstream> // Pour les fichiers
#include <stdlib.h> // Pour srand et rand
#include <time.h>   // Pour time
#include <string.h> // Pour memcpy
#include <stdexcept> // Pour invalid_argument

/* Pas besoin des deux derniers includes en c++11 */

using namespace std;

// Initialisation of static element precision
bool Darray::srandIsNotInit = true;
int Darray::precision = 53;

// CONSTRUCTORS & DESTRUCTOR //

Darray::Darray() {
    array = NULL;       // nullptr en c+++11
    length = 0;
    //cout << "\n ** Default constructor used";
}

Darray::Darray(int length, double value) {
    // Mise en place de la taille
    this->length = length;
    // Mise en place du arrayeur
    array = new double[length];
    for (int i=0; i<length; i++){
        array[i] = value;
    }
    //cout << "\n ** Constructor with fields used";
}

Darray::Darray(Darray const &copie) {
    /*
    // Nouvelle taille du arrayeur
    this->length = copie.size();
    // Allocation du nouveau arrayeur
    array = new double[size()];
    // Remplissage du nouveau arrayeur
    for (int i = 0; i < size(); i++){
        array[i] = copie.array[i];
    }
     */
    this->array = NULL;
    (*this) = copie;
    //cout << "\n ** Copy constructor used";
}

Darray::Darray(std::string const &fichier) {
    // Ouverture du fichier en mode [in]
    ifstream file;
    file.open(fichier.c_str());
    // Si le fichier n'existe pas
    if (!file.is_open() || file.eof()){
        length = 0;
        array = NULL;
    }else {
        // Calcul de la taille
        double d;
        length = -1;
        while (!file.eof()) {
            file >> d; // Lecture de double en double
            length++;
        }
        // Remplissage du arrayeur
        array = new double[length];
        // Permet d'enlever l'état EOF du fichier
        file.clear();
        file.seekg(0, ios::beg); // On se remet au début du fichier
        /*for (int i = 0; i < length; i++) {
            file >> array[i];
        }
         */
        file >> (*this);

        file.close();
    }
    //cout << "\n ** Constructor with a file used";
}

// OPERATORS //

double &Darray::operator()(int i) const{
    if (i < 0 || i >= size()) {
        throw invalid_argument("You are trying to access a array element not in [0,size-1]");
    }
    return array[i];
}

Darray &Darray::operator+=(Darray const &v) {
    if (size() != v.size()){
        throw invalid_argument("You are trying to make an operation with two arrays with two different size");
    }
    for (int i = 0; i < size(); i++) {
        array[i] += v(i);
    }
    return *this;
}

Darray &Darray::operator+=(double const &d) {
    for(int i = 0; i < size(); i++){
        array[i] += d;
    }
    return *this;
}

Darray &Darray::operator-=(Darray const &v) {
    (*this) +=(-v);
    return *this;
}

Darray &Darray::operator-=(double const &d) {
    (*this)+=(-d);
    return *this;
}

Darray &Darray::operator*=(double const &d) {
    for(int i = 0; i<size(); i++){
        array[i] *= d;
    }
    return *this;
}

Darray &Darray::operator/=(double const &d) {
    // You can't divide by zero
    if (d==0){
        throw invalid_argument("You are trying to divide by zero");
    }
    *this *= (1/d);
    return *this;
}

Darray &Darray::operator=(const Darray &copie) {
    // IMPLEMENTATION 1 //
    /*
    // Nouvelle taille du arrayeur
    length = copie.size();
    delete [] array;
    // Allocation du nouveau arrayeur
    array = new double[size()];
    // Remplissage du nouveau arrayeur
    for(int i = 0; i<size(); i++){
        array[i] = copie(i);
    }
    return *this ;
     */

    // IMPLEMENTATION 2 //
    if (this != &copie) {
        length = copie.size();
        delete[] array;
        array = new double[size()];
        memcpy(array, copie.array, size() * sizeof(double));
    }
    return *this;
}

bool Darray::operator==(Darray const &v) const {
    if (size() != v.size()){
        return false;
    }
    for(int i = 0; i<size(); i++){
        if (array[i] != v(i)){
            return false;
        }
    }
    return true;
}

// EXTERN FUNCTIONS

Darray operator+(const Darray &v, const double &d){
    Darray result(v);
    result += d;
    return result;
}

Darray operator-(const double &d, const Darray &v) {
    return (-v) + d;
}

Darray operator*(const Darray &v, const double &d) {
    Darray result(v);
    result *= d;
    return result;
}

Darray operator/(const Darray &v, const double &d) {
    Darray result(v);
    result /= d;
    return result;
}

Darray operator+(const Darray &v1, const Darray &v2) {
    Darray resultat(v1);
    resultat += v2;
    return resultat;
}

Darray operator-(const Darray &v1, const Darray &v2) {
    Darray resultat(v1);
    resultat -= v2;
    return resultat;
}

Darray operator-(const Darray &v) {
    Darray resultat(v.size());
    for (int i = 0; i<resultat.size(); i++){
        resultat(i) = -v(i);
    }
    return resultat;
}

std::ostream& operator<<(std::ostream &str, const Darray &v) {
    v.display(str);
    return str;
}

std::istream &operator>>(std::istream &str, const Darray &v) {
    for (int i = 0; i<v.size(); i++) {
        str >> v(i);
    }
    return str;
}

// METHODS //

void Darray::display(std::ostream &str) const {
    for(int i=0; i < size(); i++){
        // Met la précision au maximum pour un double IEEE754
        str << setprecision(precision) << array[i] << "\n";
    }
}

void Darray::fillRandomly() const {
    if (srandIsNotInit) {
        srand(time(NULL));
        srandIsNotInit = false;
    }
    for (int i = 0; i<size(); i++){
        array[i] = (double(rand()))/RAND_MAX;
    }
}

void Darray::resize(int size, double value) {
    if (size < length) {
        length = size;
    }
    else{
        double *array2 = new double[size];
        for(int i = 0; i<this->size(); i++){
            array2[i] = array[i];
        }
        for(int i = this->size(); i<size; i++){
            array2[i] = value;
        }
        length = size;
        delete [] array;
        array = array2;
    }
}
