#########################
#
# Makefile for TP1
#
# Compilation of documentation
#
# ibakuyua
# lebitb
#
# 3 February 2016
#
#########################

DOCU_DIR=.

all:
	doxygen $(DOCU_DIR)/Doxyfile

doc:all
	firefox $(DOCU_DIR)/html/index.html
clean:
	rm -r -f -v $(DOCU_DIR)/html/
