MPICXX=mpicxx
CXX=g++
CXXFLAGS  = -g -Wall -std=c99 -Wextra -DEBUG

all: fox transpose

fox: fox.c
	${MPICXX} $(CXXFLAGS)   $^ -o $@  
	@printf 'Linked\n'

transpose: transpose.cpp
	${MPICXX} $(CXXFLAGS)   $^ -o $@  
	@printf 'Linked\n'

mpi_mat_vect_time: mpi_mat_vect_time.c
	${MPICXX} $(CXXFLAGS)   $^ -o $@  
	@printf 'Linked\n'

clean: 	
	rm -f *.o fox transpose

new: clean all

.PHONY: all new clean
