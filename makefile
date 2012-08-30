###################################################
#
# Makefile for VLSI_Assignment1
# Creator [Xcode -> Makefile Ver: Feb 14 2007 09:18:41]
# Created: [Thu Aug 30 18:00:53 2012]
#
###################################################

#
# Macros
#

CC = /usr/bin/g++ -fopenmp
CC_OPTIONS = 
LNK_OPTIONS = 


#
# INCLUDE directories for VLSI_Assignment1
#

INCLUDE = -I.\
		-IVLSI_Assignment1 \
		-I /Volumes/Files/Programs/VLSI/VLSI_Assignment1/ \
        
#
# Build VLSI_Assignment1
#

VLSI_Assignment1 : \
		./main.o\
		./Graph.o
	$(CC) $(LNK_OPTIONS) \
		./main.o\
		./Graph.o\
		

clean : 
		rm \
		./main.o\
		./Graph.o\
		a.out	

install : VLSI_Assignment1
		cp VLSI_Assignment1 VLSI_Assignment1

#
# Build the parts of VLSI_Assignment1
#


# Item # 1 -- main --
./main.o : VLSI_Assignment1/main.cpp
	$(CC) $(CC_OPTIONS) VLSI_Assignment1/main.cpp -c $(INCLUDE) -o ./main.o


# Item # 2 -- Graph --
./Graph.o : VLSI_Assignment1/Graph.cpp
	$(CC) $(CC_OPTIONS) VLSI_Assignment1/Graph.cpp -c $(INCLUDE) -o ./Graph.o


##### END RUN ####
