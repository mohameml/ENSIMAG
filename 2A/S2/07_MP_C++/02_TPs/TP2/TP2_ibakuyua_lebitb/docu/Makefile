#########################
#
# Makefile for TP2
#
# Compilation of documentation
#
# ibakuyua
# lebitb
#
# 8 February 2016
#
#########################

DOCU_DIR=.
OPEN=firefox

all:
	doxygen $(DOCU_DIR)/Doxyfile

doc:all
	$(OPEN) $(DOCU_DIR)/html/index.html
clean:
	rm -r -f -v $(DOCU_DIR)/html/
