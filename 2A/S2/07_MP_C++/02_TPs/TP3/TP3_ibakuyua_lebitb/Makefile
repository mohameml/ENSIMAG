###############################
#
# Makefile for TP3
#
# Compilation and documentation
# for the third project of C++
#
# Ibakuyumcu Arnaud
# Lebit Benjamin
#
# ENSIMAG
#
# 23 February 2016
#
##############################
#
# Read the README for more
# information about the 
# Makefile or use make help
#
##############################

SRC_DIR=src
BIN_DIR=bin
DOCU_DIR=docu
OPEN=firefox

CXX=g++
CXXFLAGS= -Wall -Wextra -g #-DNDEBUG to avoid assert

all:
	make SRC_DIR=$(SRC_DIR) BIN_DIR=$(BIN_DIR) CXX=$(CXX) CXXFLAGS="$(CXXFLAGS)" -f src/Makefile
	make DOCU_DIR=$(DOCU_DIR) -f docu/Makefile

check:
	make check SRC_DIR=$(SRC_DIR) BIN_DIR=$(BIN_DIR) CXX=$(CXX) CXXFLAGS="$(CXXFLAGS)" -f src/Makefile

doc:
	make doc OPEN=$(OPEN) DOCU_DIR=$(DOCU_DIR) -f docu/Makefile

clean:
	make clean BIN_DIR=$(BIN_DIR) -f src/Makefile
	make clean DOCU_DIR=$(DOCU_DIR) -f docu/Makefile

help:
	more .helpMakefile
