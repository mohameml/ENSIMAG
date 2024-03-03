#include <sstream>
#include <assert.h>
#include "Triangle.h"

/**
 * \file test_Triangle.cpp
 * \brief Test file for the class Triangle
 * \author Ibakuyumcu Arnaud and Lebit Benjamin
 * \version 1.0
 * \date 15 March 2016
 *
 * \details Permit to test all the function of the class Triangle
*/

using namespace std;

int main(){
    stringstream str;
    int size;
    cout << "============= TEST OF TRIANGLE ================\n";
    cout << "\n1) Constructors : \n";
    cout << "\n1.1) Without Type and arguments : ";
    Triangle<> t1;
    str << t1;
    size = sizeof(t1.p1().x());
    assert(str.str() == "0 0\n0 0\n0 0\n0 0" && size == 8);
    str.str("");
    cout << " \E[32;1m[CHECK]\E[m \n";
    cout << "\n1.2) With Type float and arguments : ";
    Point<float> p1(2.7);
    Point<float> p2(1.3,2.7);
    Point<float> p3(4,2.9);
    Triangle<float> t2(p1,p2,p3);
    str << t2;
    size = sizeof(t2.p2().y());
    assert(str.str() == "2.7 0\n1.3 2.7\n4 2.9\n2.7 0" && size == 4);
    str.str("");
    cout << " \E[32;1m[CHECK]\E[m \n";
    cout << "\n2) Display : \n\n";
    cout << "Triangle 1 : \n" << t1;
    cout << "\nTriangle 2 : \n" << t2;
    cout << "\n\n";
    cout << " \E[32;1m[CHECK]\E[m \n";
    cout << "\n3) Transformation : \n";
    cout << "\n3.1) transformer : ";
    t2.transformer(1,2,1,1);
    size = sizeof(t2.p3().y());
    assert(size==4);
    str << t2;
    assert(str.str()=="2.7 5.4\n4 5.3\n6.9 10.9\n2.7 5.4");
    str.str("");
    cout << " \E[32;1m[CHECK]\E[m \n";
    cout << "\n3.2) deplacer : ";
    t1.deplacer(1,2);
    str << t1;
    assert(str.str() == "1 2\n1 2\n1 2\n1 2");
    str.str("");
    cout << " \E[32;1m[CHECK]\E[m \n";
    cout << "\n3.3) tourner : ";
    t2.tourner(M_PI,Point<float>(0,0));
    str << t2;
    assert(str.str()=="-2.7 -5.4\n-4 -5.3\n-6.9 -10.9\n-2.7 -5.4");
    cout << " \E[32;1m[CHECK]\E[m \n";
    cout << "\n\n";

    return 0;
}