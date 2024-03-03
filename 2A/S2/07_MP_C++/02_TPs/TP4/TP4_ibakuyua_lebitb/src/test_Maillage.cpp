
/**
 * \file test_Maillage.cpp
 * \brief Test file for the class Maillage
 * \author Ibakuyumcu Arnaud and Lebit Benjamin
 * \version 1.0
 * \date 15 March 2016
 *
 * \details Permit to test all the function of the class Maillage
 */

#include <sstream>
#include <vector>
#include <assert.h>
#include <deque>
#include <fstream>
#include "Maillage.h"

using namespace std;

int main(){
    stringstream str;
    cout << "============= TEST OF MAILLAGE =============\n";
    cout << "\n1) Constructors : \n";
    cout << "\n1.1) Without Type and arguments : ";
    Maillage<> m1;
    str << m1;
    assert(str.str()=="");
    cout << " \E[32;1m[CHECK]\E[m \n";
    cout << "\n1.2) With Type, without argument : ";
    Maillage<float,std::vector> m2;
    str << m2;
    assert(str.str()=="");
    cout << " \E[32;1m[CHECK]\E[m \n";
    cout << "\n1.3) With type and arguments (1,1,(0;0)) : ";
    Maillage<float,std::vector> m3(1,1,Point<float>(0,0));
    str << m3;
    assert(str.str()=="0 0\n0 1\n1 0\n0 0\n\n1 1\n0 1\n1 0\n1 1\n\n");
    str.str("");
    cout << " \E[32;1m[CHECK]\E[m \n";
    cout << "\n2) Test of display (operator <<) : ";
    Maillage<double,std::deque> m4(2,1,Point<double>(2,2));
    cout << "\n\n" << m4;
    cout << "\n\n";
    cout << " \E[32;1m[CHECK]\E[m \n";
    cout << "\n3) You can gnuplot with the file carre.dat : plot [-1:11][0:12] \"carre.dat\" w l : ";
    Maillage<float> m5(10,10,Point<float>(0,1));
    ofstream file;
    file.open("DATfile/carre.dat");
    file << m5;
    file.close();
    cout << " \E[32;1m[CHECK]\E[m \n";
    cout << "\n4) Transformation : You can gnuplot the file transformation.dat : plot [-50:60][-10:60] \"transformation.dat\" w l : ";
    file.open("DATfile/transformation.dat");
    m5.transformer(2,1,4,1);
    m5.deplacer(-5,-5);
    m5.tourner(M_PI_2,Point<float>(0,0));
    file << m5;
    file.close();
    cout << " \E[32;1m[CHECK]\E[m \n";
    cout << "\n5.1) Subject examples : You can gnuplot the file maillage1.dat and maillage2.dat : ";
    file.open("DATfile/maillage1.dat");
    Maillage<> m6(Point<>(2,3), Point<>(7,3), Point<>(7,6), Point<>(2,6), 2, 3 );
    file << m6;
    file.close();
    file.open("DATfile/maillage2.dat");
    Maillage<> m7(Point<>(2,3), Point<>(5,6), Point<>(3,8), Point<>(0,5), 2, 3);
    file << m7;
    file.close();
    cout << " \E[32;1m[CHECK]\E[m \n";
    cout << "\n5.2) Anormal examples : \n";
    cout << "\n5.2.1) Not a rectangle : \n";
    try{
        Maillage<> m8(Point<>(0,0), Point<>(1,1), Point<>(1,0), Point<>(0,1), 2, 3);
    }catch (exception &e){
        cout << "Exception : " << e.what() << "  " << " \E[32;1m[CHECK]\E[m \n";
    }
    cout << "\n5.2.2) Rectangle line : gnuplot with line.dat : ";
    file.open("DATfile/line.dat");
    Maillage<> m9(Point<>(1,1), Point<>(3,2), Point<>(3,2), Point<>(1,1), 2,3);
    file << m9;
    file.close();
    cout << " \E[32;1m[CHECK]\E[m \n";
    cout << "\n5.2.3) Rectangle point : gnuplot with point.dat : ";
    file.open("DATfile/point.dat");
    Maillage <> m10(Point<>(2,3),Point<>(2,3),Point<>(2,3),Point<>(2,3),4,2);
    file << m10;
    file.close();
    cout << " \E[32;1m[CHECK]\E[m \n";
    cout << "\n\n";
}