#--make file for CS253 sed253 p3
#--includes targets for all (default) and clean
#--rebuild files when out of date with .c files or headerfiles inlcuded in .c

#----Define object files
	OBJS = sed253.o copy.o substitute.o delete.o
#----Define name of released product
	EXE = sed253
#----Define options passed by make to compiler and compiler options
	CFLAGS= -Wall -g -O0 -std=c99
	CC = gcc
#----Define target for all when building executables
all: rules.d $(EXE)

rules.d: Makefile $(wildcard *.c) $(wildcard *.h)
	gcc -MM $(wildcard *.c) >rules.d

#----Include the rules for rebuilding each *.o file
-include rules.d

#----Define Rule for linking executable product
$(EXE): $(OBJS)

	$(CC) $(CFLAGS) $^ -o $@

#----Define clean for cleaning .o and executables
clean:
	rm -f $(OBJS) $(EXE) *.d *~
