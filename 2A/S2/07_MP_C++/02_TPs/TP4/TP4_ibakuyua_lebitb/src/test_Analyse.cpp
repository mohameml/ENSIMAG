/**
 * \file test_Analyse.cpp
 * \brief Test file for the class Maillage
 * \author Ibakuyumcu Arnaud and Lebit Benjamin
 * \version 1.0
 * \date 15 March 2016
 *
 * \details Permit to test class Maillage with large length of donnee
 */

#include <vector>
#include "Maillage.h"

using namespace std;

int main(int argc, char* argv[]){

    switch (atoi(argv[2]))
    {
        case 1:
            Maillage<double,list>(atoi(argv[1]), 1, Point<>(0, 0));
            break;
        case 2:
            Maillage<double, vector>(atoi(argv[1]),1, Point<>(0,0));
            break;
        case 3:
            Maillage<double, deque>(atoi(argv[1]),1, Point<>(0,0));
            break;
    }

    return 0;
}
