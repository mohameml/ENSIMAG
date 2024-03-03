/**
 * \file test_Dvector_bases.cpp
 * \brief Test File for Dvector
 * \author Arnaud Ibakuyumcu Benjamin Lebit
 * \version 1.0
 * \date 3 Février 2016
 *
 * \details Permit to test all the basic functions of #Dvector (and so Darray).
 * \details If an argument is used, display the vector contained in the argument
 */

#include "Dvector.h"
#include <fstream>
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
    cout << "\n ############ TEST OF DVECTOR : Bases #############\n";
    if (argc == 1) {
        stringstream str;
        cout << "\n 1) Creation of Dvector : \n";
        cout << "\n 1.1) With default constructor : ";
        Dvector dv1;
        assert(dv1.size() == 0);
        dv1.display(str);
        assert(str.str() == "");
        cout << " \E[32;1m[CHECK]\E[m \n";
        cout << "\n 1.2) With length(5) and value(not mentionned) : ";
        Dvector dv2(5);
        assert(dv2.size() == 5);
        dv2.display(str);
        assert(str.str() == "0\n0\n0\n0\n0\n");
        str.str("");
        cout << " \E[32;1m[CHECK]\E[m \n";
        cout << "\n 1.3) With a copy of vector4 = Dvector(7,1.0) : ";
        Dvector dv4(7, 1.0);
        Dvector dv3(dv4);
        assert(dv3.size()==7);
        dv3.display(str);
        assert(str.str()=="1\n1\n1\n1\n1\n1\n1\n");
        str.str("");
        cout << " \E[32;1m[CHECK]\E[m \n";

        // Affichage
        cout << "\n 2) Display of the Dvector created with their length : \n\n";
        cout << "Vector 1 : " << dv1.size() << "\n";
        dv1.display(cout);
        cout << "Vector 2 : " << dv2.size() << "\n";
        dv2.display(cout);
        cout << "Vector 3 : " << dv3.size() << "\n";
        dv3.display(cout);
        cout << "\n\n \E[32;1m[CHECK]\E[m\n";

        // Random
        cout << "\n 3) Fill randomly the second vector : \n\n";
        dv2.fillRandomly();
        cout << "Vector 2 : \n";
        dv2.display(cout);
        cout << "\n\n \E[32;1m[CHECK]\E[m\n";

        // SetPrecision
        cout << "\n 4) Display again the second vector with less precision\n";
        Dvector::setPrecision(25);
        assert(Dvector::getPrecision() == 25);
        cout << "\nVector 2 with setPrecision(" << Dvector::getPrecision() << ") : \n";
        dv2.display(cout);
        Dvector::setPrecision();
        assert(Dvector::getPrecision() == 53);
        cout << "\n\n \E[32;1m[CHECK]\E[m\n";

        //Write and Read in a file
        cout << "\n 5) Display in a file then constructor with this file\n";
        cout << "\n 5.1) Display vector 2 in a file (temp.txt) : ";
        ofstream temp("temp.txt");
        dv2.display(temp);
        dv2.display(str);
        temp.close();
        cout << " \E[32;1m[CHECK]\E[m\n";
        cout << "\n 5.2) Creation of vector 5 with constructor by file : ";
        Dvector dv5("temp.txt");
        stringstream str2;
        dv5.display(str2);
        assert(str.str() == str2.str());
        cout << " \E[32;1m[CHECK]\E[m\n";
        cout << "\n 5.3) Display of the vector 5 ( same at vector 2 ) : \n\n";
        dv5.display(cout);
        if (remove("temp.txt")==0){
            cout << "\n\n ** Fichier temporaire temp.txt supprimé";
        }
        cout << "\n \E[32;1m[CHECK]\E[m\n";

        // Destruction des Dvectors
        cout << "\n 6) Destruction of 5 Dvector (see below) : ";
    }else if (argc == 2) {
        cout << "\n 1) Creation of Dvector with file in argument : " << argv[1];
        Dvector dv(argv[1]);
        cout << " \E[32;1m[CHECK]\E[m\n\n";
        cout << " 2) Display of the vector with its length  \n";
        cout << "\tlength : " << dv.size() << "\n";
        dv.display(cout);
        cout << "\n \E[32;1m[CHECK]\E[m\n\n";
        cout << " 3) Destruction of Dvector : \E[32;1m[CHECK]\E[m\n";
    }else{
        cout << "\n\n !!!!! Too much argument, usage : ./test_Dvector_bases [argument]";
    }
    cout << "\E[32;1m[CHECK]\E[m \n";
    cout << "\n\n ################ FIN DU TEST ###############\n\n";

    return 0;
}

