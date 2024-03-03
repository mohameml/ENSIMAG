/**
 * \file test_Dmatrix_bases.cpp
 * \brief Test File for Dmatrix
 * \author Arnaud Ibakuyumcu Benjamin Lebit
 * \version 1.0
 * \date 3 Mars 2016
 *
 * \details Permit to test all the basic functions of #Dmatrix.
 */

#include "Dmatrix.h"
#include <assert.h>
#include <sstream>

using namespace std;

/**
 * \fn int main()
 * \brief Program entering
 *
 * \return int != 0 if program exit with error
 *
 */
int main() {

    cout << "\n ############## TEST OF DMATRIX : Bases ##############\n";
    stringstream str;

    // Creation de plusieurs Dmatrix

    cout << "\n 1) Creation of Dmatrix (and lines() columns()): \n";
    cout << "\n 1.1) With default constructor : ";
    Dmatrix m1;
    assert(m1.size() == 0 && m1.lines() == 0 && m1.columns() == 0);
    m1.display(str);
    assert(str.str() == "");
    cout << " \E[32;1m[CHECK]\E[m \n";
    cout << "\n 1.2) With constructors and arguments : ";
    Dmatrix m2(2,3,4);
    assert(m2.size() == 6 && m2.lines() == 2 && m2.columns() == 3);
    str.str("");
    m2.display(str);
    assert(str.str() == "4\n4\n4\n4\n4\n4\n");
    cout << " \E[32;1m[CHECK]\E[m \n";
    cout << "\n 1.3) With constructor by copy : ";
    str.str("");
    Dmatrix m3(m2);
    assert(m3 == m2 && m3.lines() == m2.lines() && m3.columns() == m3.columns());
    cout << " \E[32;1m[CHECK]\E[m \n";
    cout << "\n 1.4) Convert an array in Matrix(n,1) : ";
    Dvector x(4);
    x(2) = 2;
    Dmatrix m4(x);
    m4.display(str);
    assert(m4.lines() == x.size() && m4.columns() == 1);
    assert(str.str() == "0\n0\n2\n0\n");
    str.str("");
    cout << " \E[32;1m[CHECK]\E[m \n";

    // Extraction de vecteur

    cout << "\n 2) Extraction of vector : \n";
    cout << "\n 2.1) Line extraction : \n";
    cout << "\n 2.1.1) Invalid index : ";
    Dvector v;
    try {
        v = m3.line(3);
    }catch (exception &e){
        cout << "\n Exception : " << e.what() << " \E[32;1m[CHECK]\E[m \n";
    }
    cout << "\n 2.1.2) Valid index : ";
    m3(0,0) = 1;
    v = m3.line(0);
    v.display(str);
    assert(v.size() == m3.columns());
    assert(str.str() == "1\n4\n4\n");
    cout << " \E[32;1m[CHECK]\E[m \n";
    str.str("");
    cout << "\n 2.2) Column extraction : \n";
    cout << "\n 2.2.1) Invalid index : ";
    try {
        v = m3.column(3);
    }catch (exception &e){
        cout << "\n Exception : " << e.what() << " \E[32;1m[CHECK]\E[m \n";
    }
    cout << "\n 2.2.2) Valid index : ";
    v = m3.column(1);
    v.display(str);
    assert(v.size() == m3.lines());
    assert(str.str() == "4\n4\n");
    cout << " \E[32;1m[CHECK]\E[m \n";
    str.str("");

    // Transposé

    cout << "\n 3) Transposé : \n";
    cout << "\n 3.1) With a not square matrix : \n";
    try {
        m3.transpose();
    }catch (exception &e){
        cout << "Exception : " << e.what() << "\E[32;1m [CHECK]\E[m \n";
    }
    cout << "\n 3.2) Une fois : ";
    Dmatrix m5(2,2,1);
    m5(0,1) = 2;
    m5(1,0) = 3;
    m5(1,1) = 4;
    m5.transpose();
    m5.display(str);
    cout << str;
    //TODO: assert(str.str() == "1\n3\n2\n4\n");
    str.str("");
    cout << "\E[32;1m [CHECK]\E[m \n";
    cout << "\n 3.3) Chainable ? ToT = id : ";
    m5.transpose().transpose();
    m5.display(str);
    //TODO: assert(str.str() == "1\n3\n2\n4\n");
    str.str("");
    cout << "\E[32;1m [CHECK]\E[m \n";
    /* TEST POUR MATRICE RECTANGULAIRE
    cout << "\n 3.2) Une fois : ";
    m3(0,1) = 2;
    m3(0,2) = 3;
    m3(1,0) = 4;
    m3(1,1) = 5;
    m3(1,2) = 6;
    m3.display(str);
    assert(str.str() == "1\n2\n3\n4\n5\n6\n");
    str.str("");
    m3.transpose();
    m3.display(str);
    assert(m3.lines() == 3 && m3.columns() == 2);
    assert(str.str() == "1\n4\n2\n5\n3\n6\n");
    str.str("");
    cout << " \E[32;1m[CHECK]\E[m \n";
    cout << "\n 3.3) Chainable ? ToT = id : ";
    m3.transpose().transpose();
    m3.display(str);
    assert(m3.lines() == 3 && m3.columns() == 2);
    assert(str.str() == "1\n4\n2\n5\n3\n6\n");
    str.str("");
    cout << " \E[32;1m[CHECK]\E[m \n";
     */

    // Display

    cout << "\n 4) matDisplay : \n\n";
    m5.matDisplay(cout);
    cout << " \n transposé = \n\n";
    m5.transpose().matDisplay(cout);
    cout << "\n\E[32;1m [CHECK]\E[m \n";

    cout << "\n\n ################ FIN DU TEST ###############\n\n";
}