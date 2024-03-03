##########################
#
# Makefile for the TP3
# Compilation of src
#
# Ibakuyua
# Lebitb
#
# 23 February 2016
#
###########################

#Variable Definition

CXX=g++
CXXFLAGS= -Wall -Wextra -g #-DNDEBUG to avoid assert

TESTS= test_Dvector_bases test_Dvector_operators 
TESTS+= test_Dmatrix_bases test_Dmatrix_operators
TESTS+= test_Dmatrix_Cholesky

CLASS= Darray Dvector Dmatrix

BIN_DIR=../bin
SRC_DIR=.
TEST_DIR=$(SRC_DIR)/Tests

###############################

EXE_TESTS=$(TESTS:%=$(BIN_DIR)/%.te)
OBJ_CLASS=$(CLASS:%=$(BIN_DIR)/%.o)

###############################


#Rules definition

#Compilation of the project
all: $(OBJ_CLASS) $(EXE_TESTS)

#Launch the test
check: all
	$(TEST_DIR)/execute_tests.sh $(BIN_DIR)

#Creation of object files
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

#Creation of test files
$(BIN_DIR)/%.te: $(BIN_DIR)/%.o $(OBJ_CLASS)
	$(CXX) $(CXXFLAGS) $^ -o $@

#Clean the bin directory
clean:
	rm -r -v -f $(BIN_DIR)/*


