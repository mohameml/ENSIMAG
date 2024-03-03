/**
 * \file Dvector.cpp
 * \brief Class Dvector implementation
 * \author Arnaud Ibakuyumcu Benjamin Lebit
 * \version 1.0
 * \date 3 February 2016
 *
 */
#include "Dvector.h"
#include <iomanip> // Pour setprecision
#include <fstream> // Pour les fichiers
#include <stdlib.h> // Pour le rand, srand
#include <time.h>   // Pour time

/* Les deux derniers includes peuvent être supprimé en c++11 */

using namespace std;

// Initialisation of static element precision
int Dvector::precision = 53;

Dvector::Dvector() {
    vect = NULL;     // nullptr en c++11
    length = 0;
    cout << "\n ** Default constructor used";
}

Dvector::Dvector(int length, double value) {
    // Mise en place de la taille
    this->length = length;
    // Mise en place du vecteur
    vect = new double[length];
    for (int i=0; i<length; i++){
        vect[i] = value;
    }
    cout << "\n ** Constructor with fields used";
}

Dvector::Dvector(Dvector const &copie) {
    // Nouvelle taille du vecteur
    this->length = copie.size();
    // Allocation du nouveau vecteur
    vect = new double[size()];
    // Remplissage du nouveau vecteur
    for (int i = 0; i < size(); i++){
        vect[i] = copie.vect[i];
    }
    cout << "\n ** Copy constructor used";
}

Dvector::Dvector(std::string fichier) {
    // Ouverture du fichier en mode [in]
    ifstream file;
    file.open(fichier.c_str());
    // Si le fichier n'existe pas
    if (!file.is_open()){
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
        for (int i = 0; i < length; i++) {
            file >> vect[i];
        }
        file.close();
    }
    cout << "\n ** Constructor with a file used";
}

Dvector::~Dvector() {
    delete [] vect; // Attention à la désallocation d'un tableau
    cout <<"\n ** Destructor used";
}

Dvector &Dvector::operator=(Dvector const &copie) {
    // Nouvelle taille du vecteur
    length = copie.size();
    delete vect;
    // Allocation du nouveau vecteur
    vect = new double[size()];
    // Remplissage du nouveau vecteur
    for(int i = 0; i<size(); i++){
        vect[i] = copie.vect[i];
    }
    return *this ;
}

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
    srand(time(NULL));
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
