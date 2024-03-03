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

# CONSTANTE A MODIFIER SI NECESSAIRE :
BIN=bin
SRC=src
TEST=TestGraphe

# Compilation
all: $(SRC)/$(TEST).java
	javac -d $(BIN) -sourcepath $(SRC) $^

# Execution
test: all
	java -classpath $(BIN): $(TEST)

# Nettoyage
clean:
	rm -rf $(BIN)/*
