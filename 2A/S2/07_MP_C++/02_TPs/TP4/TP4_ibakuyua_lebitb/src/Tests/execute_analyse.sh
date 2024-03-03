#! /bin/bash

######################################
# Script to execute the analyse file !
######################################

echo ""
echo ""
echo "/////////////////////////////////////////////////"
echo "              LANCEMENT DE L'ANALYSE"
echo "/////////////////////////////////////////////////"

echo ""
echo ""
echo "==> test_Analyse nbre_maillage choix_STL avec 1 : list 2 : vector 3 : deque"
echo ""
echo "Test du fichier : test_Analyse 100 1"
echo ""
time ./bin/test_Analyse.an 100 1
echo ""
echo "Test du fichier : test_Analyse 10000 1"
echo ""
time ./bin/test_Analyse.an 10000 1
echo ""
echo "Test du fichier : test_Analyse 1000000 1"
echo ""
time ./bin/test_Analyse.an 1000000 1
echo ""
echo "Test du fichier : test_Analyse 10000000 1"
echo ""
time ./bin/test_Analyse.an 10000000 1
echo ""
echo ""
echo "Test du fichier : test_Analyse 100 2"
echo ""
time ./bin/test_Analyse.an 100 2
echo ""
echo "Test du fichier : test_Analyse 10000 2"
echo ""
time ./bin/test_Analyse.an 10000 2
echo ""
echo "Test du fichier : test_Analyse 1000000 2"
echo ""
time ./bin/test_Analyse.an 1000000 2
echo ""
echo "Test du fichier : test_Analyse 10000000 2"
echo ""
time ./bin/test_Analyse.an 10000000 2
echo ""
echo "Test du fichier : test_Analyse 100 3"
echo ""
time ./bin/test_Analyse.an 100 3
echo ""
echo "Test du fichier : test_Analyse 10000 3"
echo ""
time ./bin/test_Analyse.an 10000 3
echo ""
echo "Test du fichier : test_Analyse 1000000 3"
echo ""
time ./bin/test_Analyse.an 1000000 3
echo ""
echo "Test du fichier : test_Analyse 10000000 3"
echo ""
time ./bin/test_Analyse.an 10000000 3
echo "/////////////////////////////////////////////////"
echo "                 FIN DES ANALYSES"
echo "/////////////////////////////////////////////////"
