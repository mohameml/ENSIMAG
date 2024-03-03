##########################
#
# Makefile for the TP4
# Compilation of src
#
# Ibakuyua
# Lebitb
#
# 14 March 2016
#
###########################

#Variable Definition

CXX=g++
CXXFLAGS= -Wall -Wextra -g #-DNDEBUG to avoid assert

TESTS= test_Point test_Triangle test_Maillage
ANALYSE= test_Analyse
CLASS= 
TEMPLATE= Point Triangle Maillage #Juste à titre informatif

BIN_DIR=../bin
SRC_DIR=.
TEST_DIR=$(SRC_DIR)/Tests

###############################

EXE_TESTS=$(TESTS:%=$(BIN_DIR)/%.te)
ANA_TESTS=$(ANALYSE:%=$(BIN_DIR)/%.an)
OBJ_CLASS=$(CLASS:%=$(BIN_DIR)/%.o)

###############################


#Rules definition

#Compilation of the project
all: $(OBJ_CLASS) $(EXE_TESTS) $(ANA_TESTS)

#Launch the test
check: all
	chmod +x $(TEST_DIR)/execute_tests.sh $(BIN_DIR)
	$(TEST_DIR)/execute_tests.sh $(BIN_DIR)

analyse: all
	chmod +x $(TEST_DIR)/execute_analyse.sh $(BIN_DIR)
	$(TEST_DIR)/execute_analyse.sh $(BIN_DIR)

#Creation of object files
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

#Creation of test files
$(BIN_DIR)/%.te: $(BIN_DIR)/%.o $(OBJ_CLASS)
	$(CXX) $(CXXFLAGS) $^ -o $@

#Creation of analyse file
$(BIN_DIR)/%.an: $(BIN_DIR)/%.o $(OBJ_CLASS)
	$(CXX) $(CXXFLAGS) $^ -o $@

#Clean the bin directory
clean:
	rm -r -v -f $(BIN_DIR)/*


