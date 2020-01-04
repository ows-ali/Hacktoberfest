# Makefile for CSE 101 Programming Assignment 2

# Spencer Fulgham
# srfulgha
# PA2
# No special instructions to compile or run program
#------------------------------------------------------------------------------
#  Makefile for CMPS 101 Programming Assignment 2
#
#  make                     makes MatrixClient
#  make clean               removes all binaries
#  make memcheck            runs Matrix Client under valgrind
#------------------------------------------------------------------------------

CLIENT         = Sparse
ADT1           = Matrix
ADT2           = List
SOURCE         = $(CLIENT).c
OBJECT         = $(CLIENT).o
ADT1_SOURCE    = $(ADT1).c
ADT1_OBJECT    = $(ADT1).o
ADT1_HEADER    = $(ADT1).h
ADT2_SOURCE    = $(ADT2).c
ADT2_OBJECT    = $(ADT2).o
ADT2_HEADER    = $(ADT2).h
COMPILE        = gcc -c -std=c99 -Wall
LINK           = gcc -o
REMOVE         = rm -f
MEMCHECK       = valgrind --leak-check=full

$(CLIENT) : $(OBJECT) $(ADT1_OBJECT) $(ADT2_OBJECT)
	$(LINK) $(CLIENT) $(OBJECT) $(ADT1_OBJECT) $(ADT2_OBJECT)

$(OBJECT) : $(SOURCE) $(ADT1_HEADER) $(ADT2_HEADER)
	$(COMPILE) $(SOURCE)

$(ADT1_OBJECT) : $(ADT1_SOURCE) $(ADT1_HEADER)
	$(COMPILE) $(ADT1_SOURCE)

$(ADT2_OBJECT) : $(ADT2_SOURCE) $(ADT2_HEADER)
	$(COMPILE) $(ADT2_SOURCE)

clean :
	$(REMOVE) $(CLIENT) $(OBJECT) $(ADT1_OBJECT) $(ADT2_OBJECT)

memcheck : $(CLIENT)
	$(MEMCHECK) $(CLIENT)

# ASSIGNMENT = pa2
# ID = srfulgha
# SOURCES = List.c Matrix.c List.h Matrix.h Sparse.c ListTest.c MatrixTest.c Makefile README

# ListTest: ListTest.o List.o
#     gcc -o ListTest ListTest.o List.o
 
# ListTest.o: ListTest.c List.h
#     gcc -c -std=c99 -Wall ListTest.c
 
# MatrixTest: MatrixTest.o Matrix.o List.o
#     gcc -o MatrixTest MatrixTest.o Matrix.o List.o
 
# MatrixTest.o: MatrixTest.c Matrix.h List.h
#     gcc -c -std=c99 -Wall MatrixTest.c
 
# List.o : List.c List.h
#     gcc -c -std=c99 -Wall List.c
 
# Matrix.o : Matrix.c Matrix.h
#     gcc -c -std=c99 -Wall Matrix.c
 
# clean :
#     rm -f ListTest ListTest.o List.o MatrixTest MatrixTest.o Matrix.o





# Matrix.o : Matrix.c Matrix.h List.h
# 	gcc -c -std=c99 -Wall Matrix.c

# List.o : List.c List.h
# 	gcc -c -std=c99 -Wall List.c

# ListTest.c : ListTester.o List.o
# 	gcc -o ListTest ListTest.o List.o

# ListTest.o : ListTester.c List.h
# 	gcc -c -std=c99 -Wall ListTest.c

# MatrixTest.c : ListTester.o List.o
# 	gcc -o MatrixTest MatrixTest.o Matrix.o

# MatrixTest.o : Matrixtest.c Matrix.h list.h
# 	gcc -c -std=c99 -Wall MatrixTest.c

# Sparse.c : Sparse.o List.o Martix.o
# 	gcc -o Sparse Sparse.o List.o Martix.o

# Sparse.o : Sparse.c List.h Matrix.h
# 	gcc -c -std=c99 -Wall Sparse.c

# clean :
# 	rm -f Lex ListClient Lex.o ListClient.o List.o

# submit: $(SOURCES)
# 	submit cse101-pt.f19 $(ASSIGNMENT) $(SOURCES)

# check: 
# 	check /afs/cats.ucsc.edu/class/cse101-pt.f19/$(ASSIGNMENT)/srfulgha)
