//-----------------------------------------------------------------------------
// Spencer Fulgham
// srfulgha
// PA2
// No special instructions to compile or run program
//-----------------------------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"List.h"

int main(int argc, char * argv[]){

  	List A = newList();
  	List B = newList();
  	List C = NULL;

  	for(int i=1; i<=15; i++){
		append(B,i);
     	prepend(A,i);
  	}

	if(length(A) != 15){
		printf("false");
  	}

  	prepend(A, 76);
    append(A, 4);
    deleteFront(A);
    moveFront(A);
    if(get(A) == 76){
    	printf("prepend 76 worked");
    }
    moveBack(A);
    if(get(A) == 4){
    	printf("append 4 worked");
    }  

    for(int i=0; i<(length(B)/2)-1; i++){
    	deleteBack(B);
    	deleteFront(B):
	}
	if(length(B) == 1){
    	printf("deleteFront and deleteBack working");
    }


    clear(B);
    if(length(B) == 0){
    	printf("clear woorked");
    }





	freeList(&A);
   	freeList(&B);
   	freeList(&C);


	return 1;
}