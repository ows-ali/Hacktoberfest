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

int main(int argc, char * argv[]){

	Matrix A = newMatrix(5);
	Matrix B = newMatrix(5);

	changeEntry(A, 1, 1, 0);
	changeEntry(A, 1, 2, 2);
	changeEntry(A, 5, 5, 3);
	changeEntry(A, 2, 1, 4);
	changeEntry(A, 2, 2, 5);
	changeEntry(A, 4, 3, 0);
	changeEntry(A, 5, 3, 9);
	changeEntry(A, 3, 2, 8);
	changeEntry(A, 3, 5, 7);

	changeEntry(B, 1, 4, 1);
	changeEntry(B, 1, 2, 2);
	changeEntry(B, 1, 3, 3);
	changeEntry(B, 4, 1, 4);
	changeEntry(B, 2, 5, 0);
	changeEntry(B, 2, 3, 6);
	changeEntry(B, 3, 2, 8);
	changeEntry(B, 3, 4, 0);
	changeEntry(B, 5, 1, 7);

	printf("\nA:\n");
	printMatrix(stdout, A);
	printf("\nB:\n");
	printMatrix(stdout, B);
	printf("\n");
	
	Matrix E = makeZero(A);
	printf("A made empty:\n");
	printMatrix(stdout, E);
	printf("\n");

	Matrix D = transpose(B);
	printf("transpose B:\n");
	printMatrix(stdout, D);
	printf("\n");

	Matrix F = A;
	printf("Should be True aka 1:");
	printf("%d\n", equals(A,F));
	printf("\n");

	Matrix G = scalarMult(3.0, A);
	printf("3A:\n");
	printMatrix(stdout, G);
	printf("\n");

	Matrix H = sum(A, D);
	printf("A + transpose B:\n");
	printMatrix(stdout, H);
	printf("\n");

	Matrix J = diff(A,B);
	printf("A-B:\n");
	printMatrix(stdout, J);
	printf("\n");

	Matrix I = diff(A,A);
	printf("A-B:\n");
	printMatrix(stdout, I);
	printf("\n");

	Matrix C = product(B,A);
	printf("C:\n");
	printMatrix(stdout,C);
	printf("\nDone\n");

	freeMatrix(&A);
	freeMatrix(&B);
	freeMatrix(&C);
	freeMatrix(&D);
	freeMatrix(&E);
	freeMatrix(&F);
	freeMatrix(&G);
	freeMatrix(&H);
	freeMatrix(&I);
	freeMatrix(&J);

	return 1;
}