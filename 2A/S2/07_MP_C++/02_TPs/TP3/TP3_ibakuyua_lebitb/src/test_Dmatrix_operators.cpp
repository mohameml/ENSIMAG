/**
* \file test_Dmatrix_operators.cpp
* \brief Test File for Dmatrix operators
* \author Arnaud Ibakuyumcu Benjamin Lebit
* \version 1.0
* \date 3 Mars 2016
*
* \details Permit to test all the operator of #Dmatrix.
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
    cout << "\n ############## TEST OF DMATRIX : Operators ##############\n";
    stringstream str;
    // Création
    Dmatrix a(2,3);
    Dmatrix b(3,2);
    Dvector x(2);
    double d;

    // ACCESS OPERATOR
    cout << "\n\n 1) Access operators : \n";
    cout << "\n 1.1) Writting : ";
    a(0,0) = 0;
    a(0,1) = 2;
    a(0,2) = 3;
    a(1,0) = 1;
    a(1,1) = 2;
    a(1,2) = 0;
    b(0,0) = 1;
    b(0,1) = 4;
    b(1,0) = 0;
    b(1,1) = 2;
    b(2,0) = 1;
    b(2,1) = 1;
    x(0) = 2;
    x(1) = 3;
    a.display(str);
    assert(str.str() == "0\n2\n3\n1\n2\n0\n");
    str.str("");
    b.display(str);
    assert(str.str() == "1\n4\n0\n2\n1\n1\n");
    str.str("");
    cout << "\E[32;1m [CHECK]\E[m \n";
    cout << "\n 1.2) Reading : ";
    d = b(1,1);
    d++;
    assert(d == 3 && b(1,1) == 2);
    cout << "\E[32;1m [CHECK]\E[m \n";

    // EQUAL OPERATOR

    cout << "\n 2) Equal operator : ";
    Dmatrix c;
    c = b;
    c += d;
    c.display(str);
    assert(str.str() == "4\n7\n3\n5\n4\n4\n" && b(1,1) == 2);
    str.str("");
    cout << "\E[32;1m [CHECK]\E[m \n";

    // MULTIPLICATION OPERATOR

    cout << "\n 3) Multiplication operator : \n";
    cout << "\n 3.1) With invalid size : \n";
    try{
        b = b * b;
    }catch(exception &e){
        cout << "Exception : " << e.what() << " : \E[32;1m [CHECK]\E[m \n";
    }
    try{
        x = a * x;
    }catch(exception &e){
        cout << "Exception : " << e.what() << " : \E[32;1m [CHECK]\E[m \n";
    }
    cout << "\n 3.2) With two matrix : ";
    a = a * b;
    a.display(str);
    assert(a.lines() == 2 && a.columns() == 2);
    assert(str.str() == "3\n7\n1\n8\n");
    cout << "\E[32;1m [CHECK]\E[m \n";
    str.str("");
    cout << "\n 3.3) With a matrix and a vector : ";
    x = b * x;
    x.display(str);
    assert(x.size() == 3);
    assert(str.str() == "14\n6\n5\n");
    cout << "\E[32;1m [CHECK]\E[m \n";

    cout << "\n\n ################ FIN DU TEST ###############\n\n";

    return 0;
}