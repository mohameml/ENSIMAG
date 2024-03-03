/**
* \file test_Dmatrix_Cholesky.cpp
* \brief Test File for Dmatrix cholesky algorithm
* \author Arnaud Ibakuyumcu Benjamin Lebit
* \version 1.0
* \date 3 Mars 2016
*
* \details Permit to test cholesky algorithm
*/

#include <assert.h>
#include "Dmatrix.h"

using namespace std;

// Definition de l'erreur maximale pour le cholesky
#define ERR_MAX 1e-10

/**
 * \fn int main()
 * \brief Program entering
 *
 * \return int != 0 if program exit with error
 *
 */
int main() {
    // On set la precision à 10 pour que ce ne soit pas trop pour l'affichage des matrices
    Darray::setPrecision(10);

    cout << "\n ############## TEST OF DMATRIX : Cholesky ##############\n";
    cout << "\n\n 1) Test with not conform matrix : \n";
    cout << "\n 1.1) Not square matrix : \n";
    Dmatrix err(5,6,2);
    try{
        err.cholesky();
    }catch (exception &e){
        cout << " Exception : " << e.what() << "\E[32;1m [CHECK]\E[m \n";
    }
    cout << "\n 1.2) Not symetric matrix : \n";
    Dmatrix err2(6,6,2);
    err2(1,0) = 7;
    try {
        err2.cholesky();
    }catch (exception &e){
        cout << "Exception : " << e.what() << "\E[32;1m [CHECK]\E[m \n";
    }
    cout << "\n 1.3) Not positive definite matrix (two examples) : \n";
    Dmatrix err3(3,3,0);
    err3(0,0) = 3;
    err3(1,1) = -1;
    err3(2,2) = 7;
    try {
        err3.cholesky();
    }catch (exception &e){
        cout << "Exception : " << e.what() << "\E[32;1m [CHECK]\E[m \n";
    }
    Dmatrix err4(2,2);
    err4(0,0) = -4;
    err4(0,1) = 8;
    err4(1,0) = 8;
    err4(1,1) = 16;
    try {
        err4.cholesky();
    } catch (exception &e){
        cout << "Exception : " << e.what() << "\E[32;1m [CHECK]\E[m \n";
    }

    cout << "\n 2) Test of Cholesky : \n\n";
    // Creation matrice L random triangulaire inférieur
    Dmatrix L(6,6);
    L.fillRandomly();
    for (int i = 0; i < L.lines(); i++){
        for (int j = i+1; j < L.columns() ; j++) {
            L(i,j) = 0;
        }
    }
    cout << "\n Matrice L : \n\n";
    L.matDisplay(cout);
    Dmatrix TL(L);
    TL.transpose();
    // Creation matrice A = L*TL
    Dmatrix A = L*TL;
    cout << "\n Matrice A = L * TL : \n\n";
    A.matDisplay(cout);
    // Test si A.cholesky() = L
    A.cholesky();
    cout << "\n Matrice de choleskY de A=L*TL : \n\n";
    A.matDisplay(cout);
    // Calcul des erreurs d'arrondis
    A -= L;
    for(int i = 0; i < A.lines(); i++){
        for(int j = 0; j < A.columns(); j++){
            assert(A(i,j) < ERR_MAX);
        }
    }
    cout << "\n\nErreur d'arrondis < " << ERR_MAX << " : \E[32;1m [CHECK]\E[m \n";

    return 0;
}
