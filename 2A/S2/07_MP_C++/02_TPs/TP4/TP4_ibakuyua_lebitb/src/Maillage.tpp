/**
 * \file Maillage.tpp
 * \brief Implementation of the class Maillage
 * \author Ibakuyumcu Arnaud and Lebit Benjamin
 * \version 1.0
 * \date 15 March 2016
 */

#include <deque>
#include <math.h>
#include <stdexcept>
#include "Maillage.h"

// INTERMEDIARY FUNCTION //
template <typename Type>
double dist(Point<Type> p1, Point<Type> p2){
    return sqrt((p1.x()-p2.x())*(p1.x()-p2.x())+(p1.y()-p2.y())*(p1.y()-p2.y()));
}

// IMPLEMENTATION OF MAILLAGE CLASS //

template <typename Type, template<typename = Triangle<Type>,typename = std::allocator<Triangle<Type> > > class Cont>
Maillage<Type,Cont>::Maillage() {
    conteneur = Cont<>();
}

template <typename Type, template<typename = Triangle<Type>,typename = std::allocator<Triangle<Type> > > class Cont>
Maillage<Type,Cont>::Maillage(int m, int n, const Point<Type> &origine) {
    // Création d'un maillage de 2*n*m triangles
    conteneur = Cont<>();
    // Remplissage du maillage
    Type decX(origine.x());
    Type decY(origine.y());
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            //Remplissage de chaque carré
            // Premier triangle du carré (i,j)
            conteneur.push_back(Triangle<Type>(Point<Type>(decX + j, decY + i),
                                               Point<Type>(decX + j, decY + i + 1),
                                               Point<Type>(decX + j + 1, decY + i)));
            // Deuxième triangle du carré (i,j)
            conteneur.push_back(Triangle<Type>(Point<Type>(decX + j + 1, decY + i + 1),
                                               Point<Type>(decX + j, decY + i + 1),
                                               Point<Type>(decX + j + 1, decY + i)));
        }
    }
}

template <typename Type, template<typename = Triangle<Type>,typename = std::allocator<Triangle<Type> > > class Cont>
Maillage<Type,Cont>::Maillage(const Point<Type>& p1, const Point<Type>& p2, const Point<Type>& p3, const Point<Type>& p4, int m, int n ){
    // Etape de construction du maillage à l'origine avec des segments de taille 1
    // D'après l'énoncé : le rectangle est p1-p2-p3-p4-p1

    // 0) Test : Cas du point
    // A) Test : Est-ce un rectangle ?
    // A1) Colinéarité des cotés opposés de même longueur
    if ((fabs(p1.x()-p2.x()-p4.x()+p3.x()) > 0.000001)
        || (fabs(p1.y()-p2.y()-p4.y()+p3.y()) > 0.000001)
        || (fabs(p1.x()-p4.x()-p2.x()+p3.x()) > 0.000001)
        || (fabs(p1.y()-p4.y()-p2.y()+p3.y()) > 0.000001)){
        throw std::invalid_argument("You're trying to create a Maillage with a figure which is not a rectangle");
    }
    // A2) Présence d'un angle droit (produit scalaire nul)
    if (fabs((p2.x()-p1.x())*(p3.x()-p2.x())+(p2.y()-p1.y())*(p3.y()-p2.y())) > 0.000001){
        throw std::invalid_argument("You're trying to create a Maillage with a figure which is not a rectangle");
    }

    // B) Ici c'est un rectangle construction à l'origine avec des segments de taille 1 :
    // B1) Construction du maillage
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            //Remplissage de chaque carré
            // Premier triangle du carré (i,j)
            conteneur.push_back(Triangle<Type>(Point<Type>(j,i),
                                               Point<Type>(j,i + 1),
                                               Point<Type>(j + 1,i)));
            // Deuxième triangle du carré (i,j)
            conteneur.push_back(Triangle<Type>(Point<Type>(j + 1,i + 1),
                                               Point<Type>(j,i + 1),
                                               Point<Type>(j + 1,i)));
        }
    }
    // B2) Changement de la taille
    double tailleN = dist(p2,p3);
    double tailleM = dist(p1,p2);

    (*this).transformer(tailleM/m,0,0,tailleN/n);

    // B3) Rotation
    // Calcul de l'angle entre p1p2 et l'horizontal
    double theta(0);
    if (p2.x()-p1.x() != 0) {
        theta = atan(fabs((p2.y() - p1.y()) / (p2.x() - p1.x())));
    }

    (*this).tourner(theta,Point<Type>(0,0));

    // B4) Translation
    (*this).deplacer(p1.x(),p1.y());

};

template<typename T, template<typename = Triangle<T>,typename = std::allocator<Triangle<T> > > class C>
std::ostream &operator<<(std::ostream &flux, Maillage<T, C> &mail) {
    typename C<>::const_iterator pos;
    pos = mail.beginiter();
    // Parcours du conteneur s'il n'est pas vide
    if (!mail.conteneur.empty()) {
        while (pos != mail.conteneur.end()) {
            // Affichage du triangle courant
            flux << (*pos) << "\n\n";
            // Passage au prochain triangle
            pos++;
        }
    }
    return flux;
}

template <typename Type, template<typename = Triangle<Type>,typename = std::allocator<Triangle<Type> > > class Cont>
void Maillage<Type,Cont>::transformer(double m11, double m12, double m21, double m22) {
    typename Cont<>::iterator pos = conteneur.begin();
    // Transformation pour chaque triangle si le conteneur n'est pas vide
    if(!conteneur.empty()){
        while (pos != conteneur.end()){
            (*pos).transformer(m11,m12,m21,m22);
            pos++;
        }
    }
}

template <typename Type, template<typename = Triangle<Type>,typename = std::allocator<Triangle<Type> > > class Cont>
void Maillage<Type,Cont>::deplacer(double dx, double dy) {
    typename Cont<>::iterator pos = conteneur.begin();
    // Transformation pour chaque triangle si le conteneur n'est pas vide
    if(!conteneur.empty()){
        while (pos != conteneur.end()){
            (*pos).deplacer(dx,dy);
            pos++;
        }
    }
}

template <typename Type, template<typename = Triangle<Type>,typename = std::allocator<Triangle<Type> > > class Cont>
void Maillage<Type,Cont>::tourner(double angle, const Point<Type> &pt) {
    typename Cont<>::iterator pos = conteneur.begin();
    // Transformation pour chaque triangle si le conteneur n'est pas vide
    if(!conteneur.empty()){
        while (pos != conteneur.end()){
            (*pos).tourner(angle,pt);
            pos++;
        }
    }
}

