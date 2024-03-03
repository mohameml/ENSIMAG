###############################################################################
#
# Ensimag 2A POO - TP 2015/16
# ============================
# Ibakuyumcu Arnaud
# ============================
#
# Ce Makefile permet de compiler et executer l'ensemble des tests.
#
# Organisation:
#  1) Les sources (*.java) se trouvent dans le repertoire src
#  2) Les bytecodes (*.class) se trouvent dans le repertoire bin
#
##############################################################################

#   CONSTANTE A MODIFIER SI NECESSAIRE : 
BIN=bin
SRC=src
EXE=
TEST= ${shell cd $(SRC)/tests/ && echo *.java}

#   REGLE GENERAL : COMPILATION DE TOUS LES TESTS

all: $(TEST)

#   COMPILATION D'UN TEST

%.java:
	javac -d $(BIN) -sourcepath $(SRC) $(SRC)/tests/$@

# EXECUTION:
# On tape en ligne de commande make exe EXE={Nom_du_test} ex : make exe EXE=Vector

exe: Test$(EXE).java
	java -classpath bin: tests/Test$(EXE)

# NETTOYAGE DES .CLASS
clean:
	rm -rf $(BIN)/*

