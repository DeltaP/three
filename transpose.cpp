/*
 * Gregory Petropoulos
 *
 * This is my matrix transpose program for Assignment 3
 *
 * To compile:  mpicxx -g -Wall -std=c99 -o transpose transpose.cpp
 * To run:  mpiexec -n 8 ./transpose
 *          <> -> mandatory
 *          [] -> optional
 */

#include <stdio.h>
#include <mpi.h>


// -----------------------------------------------------------------
// the main program
int main(int argc, char *argv[]) {
  int i, j, count, my_rank, comm_sz;
  int a[3][3], b[3][3];

  MPI_Datatype col;

  MPI_Init(&argc, &argv);                               /* start up MPI                         */
  MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);              /* get the number of processes          */
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);              /* get my rank among all the processes  */

  MPI_Type_vector(3, 1, 3, MPI_INT, &col);
  MPI_Type_commit(&col);

  count = 0;
  if (my_rank == 0) {
    for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
        a[i][j] = count;
        count++;
      }
    }
    printf("A =\n");
    for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
        printf("%d ",a[i][j]);
      }
      printf("\n");
    }

    for (i = 0; i < 3; i++) {
      MPI_Send(&a[0][i], 1, col, 1, 0, MPI_COMM_WORLD);
    }
  }
  else if (my_rank == 1) {
    for (i = 0; i < 3; i++) {
      MPI_Recv(b[i], 3, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }
    printf("Transpose(A) =\n");
    for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
        printf("%d ",b[i][j]);
      }
    printf("\n");
    }
  }

  MPI_Finalize();
  return 0;
}



