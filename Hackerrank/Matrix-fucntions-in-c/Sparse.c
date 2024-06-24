//-----------------------------------------------------------------------------
// Spencer Fulgham
// srfulgha
// PA2
// No special instructions to compile or run program
//-----------------------------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"Matrix.h"
#include"List.h"

int main(int argc, char * argv[]){

	FILE *in, *out;   // handles for input and output files

	// check command line for correct number of arguments
  	 if( argc != 3 ){
   	   printf("Sparse Error:  Usage: %s <input file> <output file>\n", argv[0]);
   	   exit(EXIT_FAILURE);
   	}

   	// open input file for reading
   	in = fopen(argv[1], "r");
   	if( in==NULL ){
      	printf("Unable to read from file %s\n", argv[1]);
    	exit(EXIT_FAILURE);
   	}
   	// open output file for writing 
 	out = fopen(argv[2], "w");
  	if( out==NULL ){
    	printf("Unable to write to file %s\n", argv[2]);
      	exit(EXIT_FAILURE);
   	}

   	int size = 0;
   	int nnzA= 0;
   	int nnzB= 0;
	fscanf(in, "%d %d %d", &size, &nnzA, &nnzB);

	Matrix A = newMatrix(size);
	int i = 0;
	int j = 0;
	double v = 0;
	for(int k=0; k<nnzA; k++){
		fscanf(in, "%d %d %lf", &i, &j, &v);
		changeEntry(A,i,j,v);
	}

	Matrix B = newMatrix(size);
	i = 0;
	j = 0;
	v = 0;
	for(int k=0; k<nnzB; k++){
		fscanf(in, "%d %d %lf", &i, &j, &v);
		changeEntry(B,i,j,v);
	}

	// A
	fprintf(out, "A has %d non-zero entries:\n", nnzA);
	printMatrix(out, A);
	fprintf(out, "\n");
	// B
	fprintf(out, "B has %d non-zero entries:\n", nnzB);
	printMatrix(out, B);
	fprintf(out, "\n");
	// 1.5*A
	fprintf(out, "(1.5)*A =\n");
	Matrix scal = scalarMult(1.5,A);
	printMatrix(out, scal);
	fprintf(out, "\n");
	// // A+B 
	fprintf(out, "A+B =\n");
	Matrix sumAB = sum(A,B);
	printMatrix(out, sumAB);
	fprintf(out, "\n");
	// // A+A
	fprintf(out, "A+A =\n");
	Matrix sumAA = sum(A,A);
	printMatrix(out, sumAA);
	fprintf(out, "\n");
	// // B-A
	fprintf(out, "B-A =\n");
	Matrix diffBA = diff(B,A);
	printMatrix(out, diffBA);
	fprintf(out, "\n");
	// // A-A
	fprintf(out, "A-A =\n");
	Matrix diffAA = diff(A,A);
	printMatrix(out, diffAA);
	fprintf(out, "\n");
	// // Transpose(A)
	fprintf(out, "Transpose(A) =\n");
	Matrix transA = transpose(A);
	printMatrix(out, transA);
	fprintf(out, "\n");
	// // A*B
	fprintf(out, "A*B =\n");
	Matrix AB = product(A,B);
	printMatrix(out, AB);
	fprintf(out, "\n");
	// // B*B
	fprintf(out, "B*B =\n");
	Matrix BB = product(B,B);
	printMatrix(out, BB);
	fprintf(out, "\n");


	// A
	freeMatrix(&A);
	// B
	freeMatrix(&B);
	freeMatrix(&scal);
	freeMatrix(&sumAB);
	freeMatrix(&sumAA);
	freeMatrix(&diffBA);
	freeMatrix(&diffAA);
	freeMatrix(&transA);
	freeMatrix(&AB);
	freeMatrix(&BB);

	fclose(in);
	fclose(out);
	return 1;
}



// input file:
// 3 9 5

// 1 1 1.0
// 1 2 2.0
// 1 3 3.0
// 2 1 4.0
// 2 2 5.0
// 2 3 6.0
// 3 1 7.0
// 3 2 8.0
// 3 3 9.0
// 1 1 1.0
// 1 3 1.0
// 3 1 1.0
// 3 2 1.0
// 3 3 1.0

// Your program will read an input file as above, initialize and build the Array of Lists representation of the
// matrices A and B, then calculate and print the following matrices to the output file:

// The output file format is illustrated by the following example, which
// corresponds to the above input file.

// A has 9 non-zero entries:
// 1: (1, 1.0) (2, 2.0) (3, 3.0)
// 2: (1, 4.0) (2, 5.0) (3, 6.0)
// 3: (1, 7.0) (2, 8.0) (3, 9.0)

// B has 5 non-zero entries:
// 1: (1, 1.0) (3, 1.0)
// 3: (1, 1.0) (2, 1.0) (3, 1.0)

// (1.5)*A =
// 1: (1, 1.5) (2, 3.0) (3, 4.5)
// 2: (1, 6.0) (2, 7.5) (3, 9.0)
// 3: (1, 10.5) (2, 12.0) (3, 13.5)

// A+B =
// 1: (1, 2.0) (2, 2.0) (3, 4.0)
// 2: (1, 4.0) (2, 5.0) (3, 6.0)
// 3: (1, 8.0) (2, 9.0) (3, 10.0)

// A+A =
// 1: (1, 2.0) (2, 4.0) (3, 6.0)
// 2: (1, 8.0) (2, 10.0) (3, 12.0)
// 3: (1, 14.0) (2, 16.0) (3, 18.0)

// B-A =
// 1: (2, -2.0) (3, -2.0)
// 2: (1, -4.0) (2, -5.0) (3, -6.0)
// 3: (1, -6.0) (2, -7.0) (3, -8.0)

// A-A =

// Transpose(A) =
// 1: (1, 1.0) (2, 4.0) (3, 7.0)
// 2: (1, 2.0) (2, 5.0) (3, 8.0)
// 3: (1, 3.0) (2, 6.0) (3, 9.0)

// A*B =
// 1: (1, 4.0) (2, 3.0) (3, 4.0)
// 2: (1, 10.0) (2, 6.0) (3, 10.0)
// 3: (1, 16.0) (2, 9.0) (3, 16.0)

// B*B =
// 1: (1, 2.0) (2, 1.0) (3, 2.0)
// 3: (1, 2.0) (2, 1.0) (3, 2.0)