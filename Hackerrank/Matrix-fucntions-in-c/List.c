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
// -------------------------------------------------------------- private types 

// NodeObj
typedef struct NodeObj{
	void* data;
	struct NodeObj* next;
	struct NodeObj* prev;
} NodeObj;

// Node
typedef NodeObj* Node;

// newNode()
// constructor of the Node type
Node newNode(void* e) {
   Node N = malloc(sizeof(NodeObj));
   assert(N!=NULL);
   N->data = e;
   N->next = NULL;
   N->prev = NULL;
   return(N);
}

// freeNode()
// destructor for the Node type
void freeNode(Node* pN){
   if( pN!=NULL && *pN!=NULL ){
      free(*pN);
      *pN = NULL;
   }
}

// ListObj
typedef struct ListObj{
   Node front;
   Node cursor;
   Node back;
   int cursorIndex;
   int numItems;
} ListObj;

//--------------------------------------------------- Constructors-Destructors

List newList(void){
	// Creates and returns a new empty List.
	// constructor for the List type
	List L = malloc(sizeof(ListObj));
	assert(L!=NULL);
	L->front = NULL;
	L->cursor = NULL;
	L->back = NULL;
	L->numItems = 0;
	L->cursorIndex = -1;
	return L;
}
void freeList(List* pL){
	// Frees all heap memory associated with *pL, and sets *pL to NULL.
	if(pL!=NULL && *pL!=NULL){
		if(length(*pL) > 0){ clear(*pL); }
		free(*pL);
		*pL = NULL;
	}
}

//----------------------------------------------------------- Access functions // general
int length(List L){
	// Returns the number of elements in L.
	return L->numItems;
}

int index(List L){
	// Returns index of cursor element if defined, -1 otherwise.
	return L->cursorIndex;
}

//----------------------------------------------------------- Access functions // get data
void* front(List L){
	// Returns front element of L. Pre: length()>0
	if(length(L)<=0 ){
    	fprintf(stderr, 
            "List Error: calling front() on list length of 0\n");
    	exit(EXIT_FAILURE);
   }
   return L->front->data;
}

void* back(List L){
	// Returns back element of L. Pre: length()>0
   if(length(L)<=0){
    	fprintf(stderr, 
        	"List Error: calling back() on list length of 0\n");
    	exit(EXIT_FAILURE);
   }
   return L->back->data;
}

void* get(List L){
	// Returns cursor element of L. Pre: length()>0, index()>=0
	if(length(L)<=0){
    fprintf(stderr, 
    	"List Error: calling get() on list length of 0\n");
   	exit(EXIT_FAILURE);
   }
   	if(index(L)<0){
    fprintf(stderr, 
    	"List Error: calling get() while there is no cursor present\n");
   	exit(EXIT_FAILURE);
   }
	return L->cursor->data;
}

/*
void* equals(List A, List B) {
	// Returns true (1) iff Lists A and B are in same state, and returns false (0) otherwise.
	Node nodeA = A->front;
	Node nodeB = B->front;

	if(length(A) != length(B)){ return 0; }

	while(nodeA != NULL && nodeB != NULL){
		if(nodeA->data != nodeB->data){ return 0; }
		nodeA = nodeA->next;
		nodeB = nodeB->next;
	}
	return 1;
}
*/

//---------------------------------------------------- Manipulation procedures // general
void clear(List L){
	// Resets L to its original empty state.
   	if(length(L) > 0){
		L->cursor = L->front;
		while(L->cursor->next != NULL){
			L->cursor = L->cursor->next;
			freeNode(&L->cursor->prev);
		}
		freeNode(&L->cursor);
	}
	L->front = NULL;
	L->back = NULL;
	L->cursor = NULL;
	L->numItems = 0;
	L->cursorIndex = -1;
}

//---------------------------------------------------- Manipulation procedures // cursor placement
void moveFront(List L){
	// If L is non-empty, sets cursor under the front element,
 	if(L->front != NULL){
 		L->cursor = L->front;
 		L->cursorIndex = 0;
 	}
 	// otherwise does nothing.
 }

void moveBack(List L){
	// If L is non-empty, sets cursor under the back element,
	if(L->front != NULL){
		L->cursor = L->back;
		L->cursorIndex = L->numItems - 1;
	}
 	// otherwise does nothing.
}

void movePrev(List L){ 
	// If cursor is defined and not at front, move cursor one step toward the front of L; 
	if(L->cursor != NULL){
		if(L->cursor != L->front){
			L->cursor = L->cursor->prev;
			L->cursorIndex--;
		}
	// if cursor is defined and at front, cursor becomes undefined; if cursor is undefined do nothing
		else if(L->cursor == L->front){
			L->cursor = NULL;
			L->cursorIndex = - 1;
		}
	}	
}

void moveNext(List L){ 
	// If cursor is defined and not at back, move cursor one step toward the back of L; 
	if(L->cursor != NULL){
		if(L->cursor != L->back){
			L->cursorIndex++;
			L->cursor = L->cursor->next;
		}
	// if cursor is defined and at back, cursor becomes undefined; if cursor is undefined do nothing
		else if(L->cursor == L->back){
			L->cursor = NULL;
			L->cursorIndex = -1;
		}
	}
}

//---------------------------------------------------- Manipulation procedures // adding nodes
void prepend(List L, void* data){ 
	// Insert new element into L. If L is non-empty, insertion takes place before front element.
	Node newbie = newNode(data);
	if(L->numItems > 0){
		L->front->prev = newbie;
		newbie->next = L->front;
		L->front = newbie;
		if(L->cursorIndex != -1){	
			L->cursorIndex++;
		}	
	}
	else {
		L->front = newbie;
		L->back = newbie;
	}
	L->numItems++;
}

void append(List L, void* data){
	// Insert new element into L. If L is non-empty, insertion takes place after back element.
	Node newbie = newNode(data);
	if(L->numItems > 0){
		L->back->next = newbie;
		newbie->prev = L->back;
		L->back = newbie;
	}
	else{
		L->front = newbie;
		L->back = newbie;
	}
	L->numItems++;
}

void insertBefore(List L, void* data){
	// Insert new element before cursor. Pre: length()>0, index()>=0
   	if(length(L) <= 0 ){
    	fprintf(stderr, 
        	"List Error: calling insertbefore() on list length of 0\n");
    	exit(EXIT_FAILURE);
    }
    if(index(L) < 0){
    	fprintf(stderr, 
        	"List Error: calling insertbefore() with a NULL cursor\n");
    	exit(EXIT_FAILURE);
    }
    Node newbie = newNode(data);
    // if cursor is at front, avoid seg fault
    if(L->cursor == L->front){
    	L->cursor->prev = newbie;
   	 	newbie->next = L->cursor;
   	 	L->front = L->front->prev;
    }
    else{
    	Node temp = L->cursor->prev;
    	temp->next = newbie;
   	 	newbie->next = L->cursor;
   		L->cursor->prev = newbie;
    	newbie->prev = temp;
    }
    L->cursorIndex++;
    L->numItems++;
}

void insertAfter(List L, void* data){
	// Insert new element before cursor. Pre: length()>0, index()>=0
	if(length(L) <= 0 ){
    	fprintf(stderr, 
        	"List Error: calling insertAfter() on list length of 0\n");
    	exit(EXIT_FAILURE);
    }
    if(index(L) < 0){
    	fprintf(stderr, 
        	"List Error: calling insertAfter() with a null cursor\n");
    	exit(EXIT_FAILURE);
    }
    Node newbie = newNode(data);
    // if cursor is in back, avoid seg fault
    if(L->cursor == L->back){
    	L->cursor->next = newbie;
    	newbie->prev = L->cursor;
    	L->back = L->back->next;
    }
     else {
   		Node temp = L->cursor->next;
    	temp->prev = newbie;
    	newbie->next = temp;
    	L->cursor->next = newbie;
    	newbie->prev = L->cursor;
     }
     L->numItems++;
    
}

//---------------------------------------------------- Manipulation procedures // removing nodes
void deleteFront(List L){
	// Delete the front element. Pre: length()>0
	if(length(L) <= 0 ){
    	fprintf(stderr, 
        	"List Error: calling deleteFront() on list length of 0\n");
    	exit(EXIT_FAILURE);
    }	
    //checking length of the list 
    if(L->numItems == 1){
    	freeNode(&L->front);
    } 
    else{
    	L->front = L->front->next;
    	freeNode(&L->front->prev);
	}
	//checking cursor spot
    if(L->cursor == L->front){
    	L->cursorIndex = -1;
    }
    else{
    	L->cursorIndex--;
    }
    L->numItems--;
}

void deleteBack(List L){ 
	// Delete the back element. Pre: length()>0
	if(length(L) <= 0 ){
    	fprintf(stderr, 
        	"List Error: calling deleteBack() on list length of 0\n");
    	exit(EXIT_FAILURE);
    }	
    // if cursor is in the back wheen dleeted
    if(L->cursor == L->back){
    	L->cursor = NULL;
    	L->cursorIndex = -1;
    }
    // for a whole ass list
    if(L->numItems > 1){
    	L->back = L->back->prev;
		freeNode(&L->back->next);
    }
    // for a single node list
    else{
    	freeNode(&L->back);
    }
    L->numItems--;
}

void delete(List L){ 
	// Delete cursor element, making cursor undefined. Pre: length()>0, index()>=0
	if(length(L) <= 0 ){
    	fprintf(stderr, 
        	"List Error: calling delete() on list length of 0\n");
    	exit(EXIT_FAILURE);
    }	
    // if 1 element	 
    if(L->numItems == 1){
    	deleteFront(L);
    } 
    else{
	    // if cursor is at front
	    if(L->cursor == L->front){
	    	deleteFront(L);
	    }
	    // if cursor is at back 
	    else if(L->cursor == L->back){
	    	deleteBack(L);
	    }
    	//if cursor is in the middle some place
   		else{ 
    		Node temp = L->cursor->prev;
    		temp->next = L->cursor->next;
    		Node situ = L->cursor->next;
    		situ->prev = temp;
    		freeNode(&L->cursor);
    		L->numItems--;
   		}
   	}
    L->cursor = NULL;
    L->cursorIndex = -1;
}

//-----------------------------------------------------------  Other operations
/*
void printList(FILE* out, List L){
	// Prints to the file pointed to by out, a string representation of L consisting
	// of a space separated sequence of integers, with front on left.
	if(length(L) < 0 ){
    	fprintf(stderr, 
        	"List Error: calling printList() wihtout a list\n");
    	exit(EXIT_FAILURE);
    }	

	Node N = L->front;
	for(int i = 0; i < length(L); i++){
		fprintf(out, "%d " ,N->data);
		N = N->next;
	}
}


List copyList(List L){ 
	// Returns a new List representing the same integer sequence as L. The cursor in the new list is undefined, 
 	// regardless of the state of the cursor in L. The state of L is unchanged.

 	List nList = newList();
	Node N = L->front;
	for(int i = 0; i < length(L); i++){
		append(nList, N->data);
		N = N->next;
	}
	return nList;
}
*/