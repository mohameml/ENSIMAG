##########################
#
# Makefile for the TP1
# Compilation of src
#
# Ibakuyua
# Lebitb
#
# 3 February 2016
#
###########################

#Variable Definition

TEST_NAME=testDvector
BIN_DIR=../bin
SRC_DIR=.

OBJ=$(BIN_DIR)/Dvector.o
OBJ+=$(BIN_DIR)/main.o

CXX=g++
CXXFLAGS= -Wall -Wextra -g

#Rules definition

#Compilation of the project
all: $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(BIN_DIR)/$(TEST_NAME)


#Launch the test
check: all 
	$(BIN_DIR)/$(TEST_NAME)

#Creation of object files
$(BIN_DIR)/Dvector.o: $(SRC_DIR)/Dvector.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

$(BIN_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

#Clean the bin directory
clean:
	rm -r -v -f $(BIN_DIR)/*


