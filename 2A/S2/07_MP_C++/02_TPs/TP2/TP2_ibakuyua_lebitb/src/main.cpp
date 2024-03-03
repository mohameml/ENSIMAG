/**
 * \file main.cpp
 * \brief Test File for Dvector Operators
 * \author Arnaud Ibakuyumcu Benjamin Lebit
 * \version 1.0
 * \date 8 February 2016
 *
 * \details Permit to test Dvector operators.
 * \details If one or two arguments is added, test the operators on the vector contained in the file(s).
 */

#include "Dvector.h"
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
int main(int argc, char* argv[]) {

    // Création de plusieurs Dvector
    cout << "\n ############ TEST OF DVECTOR #############\n";
    if (argc == 1) {
        cout << "\n\n Creation of two vectors Dvector(4,1.5) and const Dvector(3,2.0)";
        Dvector dv1(4, 1.5);
        const Dvector dv2(3, 2.0);

        // ACCESS //
        cout << "\n\n 1) Access operator : \n";
        cout << "\n\t 1.1) Possible reading dv1(2) -> ";
        double d = dv1(2);
        cout << d;
        assert(d == 1.5);
        cout << "\E[32;1m [CHECK]\E[m \n";
        cout << "\n\t 1.2) Impossible reading dv1(5) -> ";
        try {
            d = dv1(5);
            cout << " \E[31;1m [FAIL]\E[m \n";
        } catch (exception &e) {
            cout << e.what() << " : \E[32;1m [CHECK]\E[m \n";
        }
        cout << "\n\t 1.3) Possible writing dv2(1) <- 1.5 : ";
        dv2(1)=1.5;
        assert(dv2(1)==1.5);
        cout << "\E[32;1m [CHECK]\E[m \n";
        cout << "\n\t 1.4) Impossible writing dv2(-1) <- 1.5 : ";
        try {
            dv2(-1)=1.5;
            cout << " \E[31;1m [FAIL]\E[m \n";
        }catch(exception& e){
            cout << e.what() << " : \E[32;1m [CHECK]\E[m \n";
        }

        // CLASSIC ARITHMETIC OPERATOR //
        cout << "\n 2) Classic binary operators  +,-,*,/ with a double : \n";
        cout << "\n\t 2.1) Addition Dvector+double and double+Dvector : ";
        Dvector dv3(dv1);
        assert(dv3 == dv1);
        dv3 = dv3 + 1.;
        dv3 = 0.5 + dv3;
        d = 1.5 + 1. + 0.5;
        assert(dv3(0)==d && dv3(1)==d && dv3(2)==d && dv3(3)==d);
        cout << "\E[32;1m [CHECK]\E[m \n";
        cout << "\n\t 2.2) Subtraction Dvector-double and double-Dvector : ";
        dv3 = dv3 - 1.;
        d = d - 1.;
        dv3 = 5.5 - dv3;
        d = 5.5 - d;
        assert(dv3(0)==d && dv3(1)==d && dv3(2)==d && dv3(3)==d);
        cout << "\E[32;1m [CHECK]\E[m \n";
        cout << "\n\t 2.3) Multiplication Dvector*double and double*Dvector : ";
        dv3 = dv3 * 2.2;
        d = d * 2.2;
        dv3 = (-1.) * dv3;
        d = (-1.) * d;
        assert(dv3(0)==d && dv3(1)==d && dv3(2)==d && dv3(3)==d);
        cout << "\E[32;1m [CHECK]\E[m \n";
        cout << "\n\t 2.4) Division Dvector/double : ";
        dv3 = dv3 / 3.07;
        d = d / 3.07;
        assert(dv3(0)==d && dv3(1)==d && dv3(2)==d && dv3(3)==d);
        cout << "\E[32;1m [CHECK]\E[m \n";
        cout << "\n\t 2.5) Division by zero : ";
        try{
            double d2 = 0;
            dv3 = dv3 / d2;
            cout << " \E[31;1m [FAIL]\E[m \n";
        }catch(exception& e){
            cout << e.what() << " : \E[32;1m [CHECK]\E[m \n";
        }
        cout << "\n\t 2.5 Operator -= (the other are tested with +,*,/) : ";
        dv3 -= 0.6543;
        d -= 0.6543;
        dv3 -= dv1;
        d -= dv1(0);
        assert(dv3(0)==d && dv3(1)==d && dv3(2)==d && dv3(3)==d);
        cout << "\E[32;1m [CHECK]\E[m \n";

        // STREAM OPERATOR //
        cout << "\n\n 3) Stream operator : \n";
        cout << "\n\t 3.1) << : ";
        stringstream str("");
        str << dv1;
        assert(str.str() == "1.5\n1.5\n1.5\n1.5\n");
        cout << "\E[32;1m [CHECK]\E[m \n";
        cout << "\n\t 3.2) >> : \n";
        cout << "\n\t\t 3.2.1) Stream size <= vector size : ";
        str.str("2.5\n2.5\n2.5\n");
        str >> dv1;
        assert(dv1(0) == 2.5 && dv1(1) == 2.5 && dv1(2) == 2.5 && dv1(3) == 1.5);
        cout << "\E[32;1m [CHECK]\E[m \n";
        cout << "\n\t\t 3.2.2) Stream size > vector size : ";
        str.clear();
        str.str("2.5\n2.5\n2.5\n2.5\n2.5\n2.5\n2.5\n");
        str >> dv1;
        cout << dv1(0);
        assert(dv1(0) == 2.5 && dv1(1) == 2.5 && dv1(2) == 2.5 && dv1(3) == 2.5 && dv1.size() == 4);
        cout << "\E[32;1m [CHECK]\E[m \n";

        // EQUAL OPERATOR //
       cout << "\n\n 4) Equal operator = : ";
        Dvector dv4;
        dv4 = dv1;
        assert(dv4.getVect() != dv1.getVect());
        assert(dv4.size() == dv1.size() && dv4(0) == dv1(0) && dv4(1) == dv1(1) && dv4(2) == dv1(2) && dv4(3) == dv1(3));
        cout << "\E[32;1m [CHECK]\E[m \n";

        // BOOLEAN OPERATOR //
        cout << "\n\n 5) Boolean operator : \n";
        cout << "\n\t 5.1) == : ";
        assert(dv4==dv1);
        cout << "\E[32;1m [CHECK]\E[m \n";
        cout << "\n\t 5.2) != : ";
        dv4(2)=0;
        assert(dv4!=dv1);
        cout << "\E[32;1m [CHECK]\E[m \n";

        // RESIZE METHOD //
        cout << "\n\n 6) Resize method : \n";
        cout << "\n\t 6.1) Smaler than the original : ";
        dv4.resize(2);
        assert(dv4.size() == 2 && dv4(0) == 2.5 && dv4(1) == 2.5);
        cout << "\E[32;1m [CHECK]\E[m \n";
        cout << "\n\t 6.2) Higher than the original with values : ";
        dv4.resize(3,0.7);
        assert(dv4.size() == 3 && dv4(0) == 2.5 && dv4(1) == 2.5 && dv4(2) == 0.7);
        cout << "\E[32;1m [CHECK]\E[m \n";

        // TIME FOR EQUAL //
        cout << "\n\n 7) Equal with a milion dimension vector (compare the time with the two differents methods) : ";
        Dvector dv5(10000000);
        dv5.fillRandomly();
        dv1 = dv5;
        cout << "\E[32;1m [CHECK]\E[m \n\n";

    }
    else if(argc == 2){
        cout << "\n ** Creation of Dvector with file in argument : " << argv[1];
        Dvector dv1(argv[1]);
        if (dv1.size() == 0) {
            cout << "\n !! File in argument is a empty vector \n\n";
            return 0;
        }
        double d1 = dv1(0);
        Dvector dv2(dv1.size());
        dv2.fillRandomly();
        double d2 = dv2(0);
        cout << "\n ** Basic operations with an other random vector : ";
        dv1 *= 2.5;
        d1 *= 2.5;
        assert(dv1(0) == d1);
        d2 += d1;
        dv2 += dv1;
        assert(dv2(0) == d2);
        dv2 = dv1;
        d2 = d1;
        assert(dv1.getVect() != dv2.getVect());
        assert(dv1(0) == dv2(0));
        if (dv2 != dv1){
            cout << "\n Problem with == operator \n";
        }
        dv2.fillRandomly();
        stringstream str;
        str.str("");
        str << dv1;
        str >> dv2;
        assert(dv2 == dv1);
        dv2.resize(dv2.size()-1);
        assert(dv2.size() == dv1.size() - 1);
        cout << "\E[32;1m [CHECK]\E[m \n";

    }
    else if(argc == 3){
        cout << "\n ** Creation of Dvector with files in argument : \n" << argv[1] << "\n" << argv[2];
        Dvector dv1(argv[1]);
        Dvector dv2(argv[2]);
        if (dv1.size() == 0 || dv2.size() == 0) {
            cout << "\n !! File in argument is a empty vector \n\n";
            return 0;
        }
        double d1 = dv1(0);
        double d2 = dv2(0);
        cout << "\n ** Basic operations with this two vectors : ";
        dv1 *= 2.5;
        d1 *= 2.5;
        assert(dv1(0) == d1);
        d2 += d1;
        try {
            dv2 += dv1;
            assert(dv2(0) == d2);

        }catch(exception &e){
            cout << "\n Exception : " << e.what();
        }
        dv2 = dv1;
        assert(dv1.getVect() != dv2.getVect());
        for (int i = 0; i < dv1.size(); i++) {
            assert(dv2(i) == dv1(i));
        }
        if (dv2 != dv1){
            cout << "\n Problem with == operator \n";
        }
        dv2.fillRandomly();
        stringstream str("");
        str << dv1;
        str >> dv2;
        assert(dv2 == dv1);
        dv2.resize(dv2.size()-1);
        assert(dv2.size() == dv1.size() - 1);
        cout << "\n\n\E[32;1m [CHECK]\E[m \n";
    }
    else {
        cout << "\n\n !!!!! Too much argument, usage : ./testDvector [argument1] [Argument2]";
    }

    cout << "\n\n ################ FIN DU TEST ###############\n\n";

    return 0;
}

