/**
 * \file Dvector.cpp
 * \brief Class Dvector implementation
 * \author Arnaud Ibakuyumcu Benjamin Lebit
 * \version 2.0 (Operators added and simplification access with operator ())
 * \date 8 February 2016
 *
 */
#include "Dvector.h"
#include <iomanip> // Pour setprecision
#include <fstream> // Pour les fichiers
#include <stdlib.h> // Pour srand et rand
#include <time.h>   // Pour time
#include <string.h> // Pour memcpy
#include <stdexcept> // Pour invalid_argument

/* Pas besoin des deux derniers includes en c++11 */

using namespace std;

// Initialisation of static element precision
int Dvector::precision = 53;
bool Dvector::srandIsNotInit = true;

// CONSTRUCTORS & DESTRUCTOR //

Dvector::Dvector() {
    vect = NULL;       // nullptr en c+++11
    length = 0;
    //cout << "\n ** Default constructor used";
}

Dvector::Dvector(int length, double value) {
    // Mise en place de la taille
    this->length = length;
    // Mise en place du vecteur
    vect = new double[length];
    for (int i=0; i<length; i++){
        vect[i] = value;
    }
    //cout << "\n ** Constructor with fields used";
}

Dvector::Dvector(Dvector const &copie) {
    /*
    // Nouvelle taille du vecteur
    this->length = copie.size();
    // Allocation du nouveau vecteur
    vect = new double[size()];
    // Remplissage du nouveau vecteur
    for (int i = 0; i < size(); i++){
        vect[i] = copie.vect[i];
    }
     */
    this->vect = NULL;
    (*this) = copie;
    //cout << "\n ** Copy constructor used";
}

Dvector::Dvector(std::string const &fichier) {
    // Ouverture du fichier en mode [in]
    ifstream file;
    file.open(fichier.c_str());
    // Si le fichier n'existe pas
    if (!file.is_open() || file.eof()){
        length = 0;
        vect = NULL;
    }else {
        // Calcul de la taille
        double d;
        length = -1;
        while (!file.eof()) {
            file >> d; // Lecture de double en double
            length++;
        }
        // Remplissage du vecteur
        vect = new double[length];
        // Permet d'enlever l'état EOF du fichier
        file.clear();
        file.seekg(0, ios::beg); // On se remet au début du fichier
        /*for (int i = 0; i < length; i++) {
            file >> vect[i];
        }
         */
        file >> (*this);

        file.close();
    }
    //cout << "\n ** Constructor with a file used";
}

Dvector::~Dvector() {
    delete [] vect; // Attention à la désallocation d'un tableau
    //cout <<"\n ** Destructor used";
}

// OPERATORS //

double &Dvector::operator()(int i) const{
    if (i < 0 || i >= size()) {
        throw invalid_argument("You are trying to access a vector element not in [0,size-1]");
    }
    return vect[i];
}

Dvector &Dvector::operator+=(Dvector const &v) {
    if (size() != v.size()){
        throw invalid_argument("You are trying to make an operation with two vectors with two different size");
    }
    for (int i = 0; i < size(); i++) {
        vect[i] += v(i);
    }
    return *this;
}

Dvector &Dvector::operator+=(double const &d) {
    for(int i = 0; i < size(); i++){
        vect[i] += d;
    }
    return *this;
}

Dvector &Dvector::operator-=(Dvector const &v) {
    (*this) +=(-v);
    return *this;
}

Dvector &Dvector::operator-=(double const &d) {
    (*this)+=(-d);
    return *this;
}

Dvector &Dvector::operator*=(double const &d) {
    for(int i = 0; i<size(); i++){
        vect[i] *= d;
    }
    return *this;
}

Dvector &Dvector::operator/=(double const &d) {
    // You can't divide by zero
    if (d==0){
        throw invalid_argument("You are trying to divide by zero");
    }
    *this *= (1/d);
    return *this;
}

bool Dvector::operator==(Dvector const &v) const {
    if (size() != v.size()){
        return false;
    }
    for(int i = 0; i<size(); i++){
        if (vect[i] != v(i)){
            return false;
        }
    }
    return true;
}

bool Dvector::operator!=(Dvector const &v) const {
    return !((*this) == v);
}

// EXTERN FUNCTIONS

Dvector operator+(const Dvector &v, const double &d){
    Dvector result(v);
    result += d;
    return result;
}

Dvector operator+(const double &d, const Dvector &v){
    // d + v = v + d
    return v + d;
}

Dvector operator-(const Dvector &v, const double &d) {
    return v + (-d);
}

Dvector operator-(const double &d, const Dvector &v) {
    return (-v) + d;
}

Dvector operator*(const Dvector &v, const double &d) {
    Dvector result(v);
    result *= d;
    return result;
}

Dvector operator*(const double &d, const Dvector &v) {
    return v * d;
}


Dvector operator/(const Dvector &v, const double &d) {
    Dvector result(v);
    result /= d;
    return result;
}

Dvector operator+(const Dvector &v1, const Dvector &v2) {
    Dvector resultat(v1);
    resultat += v2;
    return resultat;
}

Dvector operator-(const Dvector &v1, const Dvector &v2) {
    Dvector resultat(v1);
    resultat -= v2;
    return resultat;
}

Dvector operator-(const Dvector &v) {
    Dvector resultat(v.size());
    for (int i = 0; i<resultat.size(); i++){
        resultat(i) = -v(i);
    }
    return resultat;
}

Dvector &Dvector::operator=(Dvector const &copie) {
    // IMPLEMENTATION 1 //
    /*
    // Nouvelle taille du vecteur
    length = copie.size();
    delete [] vect;
    // Allocation du nouveau vecteur
    vect = new double[size()];
    // Remplissage du nouveau vecteur
    for(int i = 0; i<size(); i++){
        vect[i] = copie(i);
    }
    return *this ;
     */

    // IMPLEMENTATION 2 //
    length = copie.size();
    delete [] vect;
    vect = new double[size()];
    memcpy(vect, copie.vect, size() * sizeof(double));
    return *this;
}

std::ostream& operator<<(std::ostream &str, const Dvector &v) {
    v.display(str);
    return str;
}

std::istream &operator>>(std::istream &str, const Dvector &v) {
    for (int i = 0; i<v.size(); i++) {
        str >> v(i);
    }
    return str;
}

// METHODS //

void Dvector::display(std::ostream &str) const {
    for(int i=0; i < size(); i++){
        // Met la précision au maximum pour un double IEEE754
        str << setprecision(precision) << vect[i] << "\n";
    }
}

int Dvector::size() const{
    return length;
}

void Dvector::fillRandomly() const {
    if (srandIsNotInit) {
        srand(time(NULL));
        srandIsNotInit = false;
    }
    for (int i = 0; i<size(); i++){
        vect[i] = (double(rand()))/RAND_MAX;
    }
}

void Dvector::setPrecision(int prec) {
    precision = prec;
}

int Dvector::getPrecision() {
    return precision;
}

double *Dvector::getVect() {
    return vect;
}

void Dvector::resize(int size, double value) {
    if (size < length) {
        length = size;
    }
    else{
        double *vect2 = new double[size];
        for(int i = 0; i<this->size(); i++){
            vect2[i] = vect[i];
        }
        for(int i = this->size(); i<size; i++){
            vect2[i] = value;
        }
        length = size;
        delete [] vect;
        vect = vect2;
    }
}
