#include <sstream>
#include <assert.h>
#include "Point.h"

/**
 * \file test_Point.cpp
 * \brief Test file for the class Point
 * \author Ibakuyumcu Arnaud and Lebit Benjamin
 * \version 1.0
 * \date 14 March 2016
 *
 * \details Permit to test all the function of the class Point
 */

using namespace std;

int main(){
    stringstream str;
    int size;
    cout << "============= TEST OF POINT ================\n";
    cout << "\n1) Constructors : \n";
    cout << "\n1.1) Without type template with two arguments : ";
    Point<> point(2.5,1);
    str << point;
    size = sizeof(point.x());
    assert(str.str() == "2.5 1" && size == 8);
    str.str("");
    cout << " \E[32;1m[CHECK]\E[m \n";
    cout << "\n1.2) Float type without argument : ";
    Point<float> fp;
    str << fp;
    size = sizeof(fp.x());
    assert(str.str() == "0 0" && size == 4);
    str.str("");
    cout << " \E[32;1m[CHECK]\E[m \n";
    cout << "\n1.3) Double type with one argument : ";
    Point<double> dp(2.6);
    str << dp;
    size = sizeof(dp.y());
    assert(str.str() == "2.6 0" && size == 8 );
    str.str("");
    cout << " \E[32;1m[CHECK]\E[m \n";

    cout << "\n2) Display : \n\n";
    cout << "Point 1 : " << point << "\nPoint 2 : " << fp << "\nPoint 3 : " << dp;
    cout << "\n\n\E[32;1m[CHECK]\E[m \n";

    cout << "\n3) Test of transformation : \n";
    cout << "\n3.1) transformer : ";
    dp.transformer(1,2,3,1);
    fp.transformer(2,2,1,1);
    size = sizeof(fp.y());
    assert(size == 4);
    str << dp;
    assert(str.str()=="2.6 5.2");
    str.str("");
    cout << "\E[32;1m[CHECK]\E[m \n";
    cout << "\n3.2) deplacer : ";
    fp.deplacer(1,2);
    size= sizeof(fp.x());
    assert(size==4);
    str << fp;
    assert(str.str()=="1 2");
    str.str("");
    cout << "\E[32;1m[CHECK]\E[m \n";
    cout << "\n3.3) tourner : ";
    Point<> p(2,2);
    p.tourner(M_PI_2,Point<>(5,2));
    str << p;
    assert(str.str()=="5 -1");
    cout << "\E[32;1m[CHECK]\E[m \n";
    cout << "\n\n";

    return 0;
}

