MPICXX=mpicxx
CXX=g++
CXXFLAGS  = -g -Wall -std=c99 -Wextra

INCLUDES =

all: fox transpose

fox: fox.c
	${MPICXX} $(CXXFLAGS)   $^ -o $@  
	@printf 'Linked\n'

clean: 	
	rm -f *.o fox

new: clean all

.PHONY: all new clean
