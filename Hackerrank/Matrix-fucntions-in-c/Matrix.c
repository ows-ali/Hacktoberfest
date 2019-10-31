//-----------------------------------------------------------------------------
// Spencer Fulgham
// srfulgha
// PA2
// No special instructions to compile or run program
//----------------------------------------------------------------------------- Constructors

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"Matrix.h"
#include"List.h"


typedef struct EntryObj{
	int column;
	double value;
} EntryObj;

// Entry
typedef EntryObj* Entry;

// newEntry()
// constructor of the Eentry type
Entry newEntry(int c, double d) {
   Entry E = malloc(sizeof(EntryObj));
   assert(E!=NULL);
   E->column = c;
   E->value = d;
   return(E);
}

void freeEntry(Entry* pE){
   if( pE!=NULL && *pE!=NULL ){
      free(*pE);
      *pE = NULL;
   }
}

// MatrixObj
typedef struct MatrixObj{
	int size;
	int nnz;
	List* rowArray;
} MatrixObj;


//----------------------------------------------------------------------------- Setup
Matrix newMatrix(int n){
	// Returns a reference to a new nXn Matrix object in the zero state.
	Matrix M = malloc(sizeof(MatrixObj));
	assert(M!=NULL);
	M->size = n;
	M->nnz = 0;
	M->rowArray = malloc(n * sizeof(List*));
	for(int i = 0; i < n; i++){
		M->rowArray[i] = newList();
	}
	return M;
}

void freeMatrix(Matrix* pM){
	// Frees heap memory associated with *pM, sets *pM to NULL

	if(pM!=NULL && *pM!=NULL){
		Matrix M = *pM;
		makeZero(M);
		for(int i=0; i < size(M); i++){
			freeList(&(M->rowArray[i]));
		}
		free(M->rowArray);
		free(*pM);
		*pM = NULL;
	}
}

//----------------------------------------------------------------------------- Access Functions
int size(Matrix M){
	// Return the size of square Matrix M.
	return M->size;
}

int NNZ(Matrix M){
	// Return the number of non-zero elements in M.
	// go through array and get the length of each list
	return M->nnz;
}

int equals(Matrix A, Matrix B){
	// Return true (1) if matrices A and B are equal, false (0) otherwise.
	// makd sure same size
	if(size(A) != size(B)){ return 0; }
	//for loop through array
	for(int i=0; i< size(A); i++){
		List currA = A->rowArray[i];
		List currB = B->rowArray[i];
		moveFront(currA);
		moveFront(currB);
		if(length(currA) != 0 && length(currB) != 0){

			// while loop through list
			while(index(currA) != -1 && index(currB) != -1){
				Entry entryA = (Entry) get(currA);
				Entry entryB = (Entry) get(currB);
				if(entryA->column != entryB->column || entryA->value != entryB->value){ 
					// entryA != entryB
					return 0; 
				}
				moveNext(currA);
				moveNext(currB);
			}
			if(index(currA) != -1 || index(currB) != -1){  // or currB is -1 and currA isn't?
				return 0;
			}
		}		
	}
	return 1;
}

//----------------------------------------------------------------------------- Manipulation procedures
void makeZero(Matrix M){
	// Re-sets M to the zero Matrix.

	// make sure that the length is 
	if(size(M) != 0){
		for(int i=0; i<size(M); i++){
		List currList = M->rowArray[i];
		moveFront(currList);
			// go through the list
			if(index(currList) != -1){
				while(index(currList) != -1){
					Entry entryM = (Entry) get(currList);
					freeEntry(&entryM);
					delete(currList);
					M->nnz--;
					moveFront(currList);
				}
			}
		}
	}
}

void changeEntry(Matrix M, int i, int j, double x){
	// Pre: 1<=i<=size(M), 1<=j<=size(M)
	if( 1>i && i>size(M) ){
    	fprintf(stderr, 
            "Matrix Error: calling changeEntry() with an i out of bounds\n");
    	exit(EXIT_FAILURE);
	}
 	if( 1>j && j>size(M) ){
    	fprintf(stderr, 
            "Matrix Error: calling changeEntry() with an j out of bounds\n");
    	exit(EXIT_FAILURE);
	}
	// Changes the ith row, jth column of M to the value x.
		// keep going through the list until cursor is -1, searching for the column and stop there

	List currentList = M->rowArray[i-1];
	moveFront(currentList);

	// while on the list or not past column j, keep moving through the row array
	if(index(currentList) != -1){
		while(index(currentList) != -1   &&  ((Entry) get(currentList))->column < j){
			moveNext(currentList);
		}
	}

	// case 1: index is off the list, let's append!
	if(index(currentList) == -1){
		if(x != 0){
			append(currentList, newEntry(j,x));
			M->nnz++;
		}
	}

	// case 2: index is past j, lets add before!
	else if(((Entry) get(currentList))->column > j){
		if(x!=0){
			insertBefore(currentList, newEntry(j,x));
			M->nnz++;
		}
	}

	// case 3: column is beore or equal to column j, change that value!
	else{
		if(x == 0){
			Entry freeMe = (Entry) get(currentList);
			freeEntry(&freeMe);
			delete(currentList);
			M->nnz--;
		}
		else{
			Entry E = (Entry) get(currentList);
			E->value = x;
		}
	}
}

//----------------------------------------------------------------------------- Matrix Arithmetic operations
Matrix copy(Matrix A){
	// Returns a reference to a new Matrix object having the same entries as A.
	Matrix N = newMatrix(size(A));

	if(size(A) != 0){
		// go through the array (vertical)
		for(int i=0; i<size(A); i++){
			List currList = A->rowArray[i];
			moveFront(currList);
				// go through the list (horizontal)
				if(index(currList) != -1){
					while(index(currList) != -1){
						Entry E = (Entry) get(currList);
						changeEntry(N, i+1, E->column, E->value);
						moveNext(currList);
					}
				}
			}
		}
	return N;
}

Matrix transpose(Matrix A){
	// Returns a reference to a new Matrix object representing the transpose of A.
	// transpose means that, if A(i,j), transA = A(j,i)
	Matrix N = newMatrix(size(A));

	if(size(A) != 0){
		// go through the array (vertical)
		for(int i=0; i<size(A); i++){
			List currList = A->rowArray[i];
			moveFront(currList);
				// go through the list (horizontal)
				if(index(currList) != -1){
					while(index(currList) != -1){
						Entry E = (Entry) get(currList);
						changeEntry(N, E->column, i+1, E->value);
						moveNext(currList);
					}
				}
			}
		}
	return N;
}

Matrix scalarMult(double x, Matrix A){
	// Returns a reference to a new Matrix object representing xA.

	Matrix N = newMatrix(size(A));

	if(size(A) != 0){
		// go through the array (vertical)
		for(int i=0; i<size(A); i++){
			List currList = A->rowArray[i];
			moveFront(currList);
				// go through the list (horizontal)
				if(index(currList) != -1){
					while(index(currList) != -1){
						Entry E = (Entry) get(currList);
						changeEntry(N, i+1, E->column, E->value * x);
						moveNext(currList);
					}
				}
			}
		}

	return N;
}

Matrix sum(Matrix A, Matrix B){
	// Returns a reference to a new Matrix object representing A+B.
	// pre: size(A)==size(B)

	if(size(A) != size(B)){
    	fprintf(stderr, 
            "List Error: calling sum() on two arrays of opposing sizes\n");
    	exit(EXIT_FAILURE);
	}
	if(size(A) == 0){
		Matrix C = newMatrix(0);
		return C;
	}

	// check if both cursors are on list via move front, then check using index!=-1
	// start outter for loop for array
	// 3 main cases in "or" while loop
		// case 1: columns are the same, simply add
		// case 2: a list dont exist, make C list = b list
		// case 3: b list dont exist, make C list = a one
	if (A == B){ return scalarMult(2.0,A); }

	Matrix C = newMatrix(size(A));
	for(int i=0; i < size(A); i++){
		List currlistA = A->rowArray[i];
		List currlistB = B->rowArray[i];
		moveFront(currlistA);
		moveFront(currlistB);

		if(index(currlistA) != -1 || index(currlistB) != -1){
			while(index(currlistA) != -1 || index(currlistB) != -1){

				// case 1: A is absent but B still has more
				if(index(currlistA) == -1 && index(currlistB) != -1){
					Entry entryB = (Entry) get(currlistB);
					changeEntry(C, i+1, entryB->column, entryB->value);
					moveNext(currlistB);
				}

				// case 2: B is absent but A still has more
				else if(index(currlistB) == -1 && index(currlistA) != -1){
					Entry entryA = (Entry) get(currlistA);
					changeEntry(C, i+1, entryA->column, entryA->value);
					moveNext(currlistA);
				}

				// case 3: both Alist and Blist exist, lets start adding!
				else{
					Entry entryA = (Entry) get(currlistA);
					Entry entryB = (Entry) get(currlistB);

					// case 3a: B is at a greater column
					if(entryA->column < entryB->column){
						changeEntry(C, i+1, entryA->column, entryA->value);
						moveNext(currlistA);
					}
					// case 3b: A is at a greater column
					else if(entryA->column > entryB->column){
						changeEntry(C, i+1, entryB->column, entryB->value);
						moveNext(currlistB);
					}
					// case 3c: A and B are at the same column
					else{
						changeEntry(C, i+1, entryA->column, entryA->value + entryB->value);
						moveNext(currlistA);
						moveNext(currlistB);
					}

				}
			}
		}
	}
	return C;
}

Matrix diff(Matrix A, Matrix B){
	// diff()
	// Returns a reference to a new Matrix object representing A-B.
	// pre: size(A)==size(B)

	if(size(A) != size(B)){
    	fprintf(stderr, 
            "List Error: calling diff() on two arrays of opposing sizes\n");
    	exit(EXIT_FAILURE);
	}
	if(size(A) == 0){
		Matrix C = newMatrix(0);
		return C;
	}

	// check if both cursors are on list via move front, then check using index!=-1
	// start outter for loop for array
	// 3 main cases in "or" while loop
		// case 1: columns are the same, simply add
		// case 2: a list dont exist, make C list = b list
		// case 3: b list dont exist, make C list = a one
	Matrix C = newMatrix(size(A));
	if (A==B){ return C; }

	for(int i=0; i < size(A); i++){
		List currlistA = A->rowArray[i];
		List currlistB = B->rowArray[i];
		moveFront(currlistA);
		moveFront(currlistB);

		if(index(currlistA) != -1 || index(currlistB) != -1){
			while(index(currlistA) != -1 || index(currlistB) != -1){

				// case 1: A is over but B still has more
				if(index(currlistA) == -1 && index(currlistB) != -1){
					Entry entryB = (Entry) get(currlistB);
					changeEntry(C, i+1, entryB->column, -1 * entryB->value);
					moveNext(currlistB);
				}

				// case 2: B is over but A still has more
				else if(index(currlistB) == -1 && index(currlistA) != -1){
					Entry entryA = (Entry) get(currlistA);
					changeEntry(C, i+1, entryA->column, entryA->value);
					moveNext(currlistA);
				}

				// case 3: both Alist and Blist exist, lets start adding!
				else{
					Entry entryA = (Entry) get(currlistA);
					Entry entryB = (Entry) get(currlistB);

					// case 3a: B is at a greater column
					if(entryA->column < entryB->column){
						changeEntry(C, i+1, entryA->column, entryA->value);
						moveNext(currlistA);
					}
					// case 3b: A is at a greater column
					else if(entryA->column > entryB->column){
						changeEntry(C, i+1, entryB->column, -1*entryB->value);
						moveNext(currlistB);
					}
					// case 3c: A and B are at the same column
					else{
						changeEntry(C, i+1, entryA->column, entryA->value - entryB->value);
						moveNext(currlistA);
						moveNext(currlistB);
					}

				}
			}
		}
	}
	return C;



	return A;
}

double vectorDot(List currlistA, List currlistB){ // helper
	// keep testing vectorDot with MatrixTest before moving to product
	// do the columns match?
	// keep pushing through each column list until you get find an equals, then perform
	// if they dont equal, keep moving until they do, and perform on things by 0
	// if one list cursor goes off to -1, then 0 the rest of the other list, as there is no way they equal

	double val = 0;
	moveFront(currlistA);
	moveFront(currlistB);

		while(index(currlistA) != -1 && index(currlistB) != -1 ){
		//  both Alist and Blist exist, lets start adding!
			Entry entryA = (Entry) get(currlistA);
			Entry entryB = (Entry) get(currlistB);

			// case a: B is at a greater column
			if(entryA->column < entryB->column){
				moveNext(currlistA);
			}
			// case b: A is at a greater column
			else if(entryA->column > entryB->column){
				moveNext(currlistB);
			}
			// case c: A and B are at the same column
			else{
				val = val + entryA->value * entryB->value;
				moveNext(currlistB);
				moveNext(currlistA);
			}
		}
	return val;
}

Matrix product(Matrix A, Matrix B){
	// Returns a reference to a new Matrix object representing AB
	// pre: size(A)==size(B)
	// transpose B 
	// call dot product a lot
	if(size(A) != size(B)){
	fprintf(stderr, 
        "List Error: calling product() on two arrays of opposing sizes\n");
	exit(EXIT_FAILURE);
	}

	Matrix C = newMatrix(size(A));
	B = transpose(B);
	// for length of A array
	for(int i=0; i<size(A); i++){
		List currlistA = A->rowArray[i];
		moveFront(currlistA);

		if(index(currlistA) != -1){
			// for length of B array
			for(int j =0; j<size(B); j++){
				List currlistB = B->rowArray[j];
				moveFront(currlistB);

				if(index(currlistB) != -1){
					//Entry entryA = (Entry) get(currlistA);
					//printf("about to vectorDot\n");
					double v = vectorDot(currlistA, currlistB);
					changeEntry(C, i+1, j+1, v);
				}
			}
		}
	 }
	freeMatrix(&B);
	return C;
}

void printMatrix(FILE* out, Matrix M){
	// Prints a string representation of Matrix M to filestream out. Zero rows
	// are not printed. Each non-zero is represented as one line consisting
	// of the row number, followed by a colon, a space, then a space separated
	// list of pairs "(col, val)" giving the column numbers and non-zero values
	// in that row. The double val will be rounded to 1 decimal point.

	if(size(M)!=0){
		for(int i = 0; i < M->size; i++){
			if(length(M->rowArray[i]) != 0){
				moveFront(M->rowArray[i]);
				fprintf(out, "%d:", i+1);
				for(int j = 0; j < length(M->rowArray[i]); j++){
					Entry P = (Entry) get(M->rowArray[i]);
					fprintf(out, " (%d,%.1f)", P->column, P->value);
					moveNext(M->rowArray[i]);
				}
				fprintf(out, "\n");
			}
		}
	}
}