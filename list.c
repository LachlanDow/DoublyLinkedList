#include <stdlib.h>
#include "list.h"
/* Initialize a new List and record its pointer into (*listPtr).
		listPtr must not be NULL
		(*listPtr) must be NULL */
int listInit(List **listPtr){
if (listPtr == NULL){
		return NULL_PARAM;
	}

	//make sure the DEQ hasnt already been initialised already
	if(*listPtr != NULL){
		return BAD_INIT_PARAM;
	}


	//allocate memory 
	*listPtr = (List*)myMalloc(sizeof(List));

	// check for memory failure
	if ((*listPtr) == NULL)
	{
			return OUT_OF_MEMORY;
	}

	//intitialise fields in queue
	(*listPtr)->head = NULL;
	(*listPtr)->tail = NULL;
	(*listPtr)->curr = NULL;

	return SUCCESS;
}


/* Insert 'data' as a new node into the List immediately before
   the current position ('curr')
		listPtr must not be NULL */
int insertBeforeCurr(List* listPtr, int data)
{
	//check if the memory address in null
	if(listPtr == NULL){
		return NULL_PARAM;
	}
	
	//allocaate memory for new node
	ListNode *newNode = (ListNode*)myMalloc(sizeof(ListNode));


	//check for memory failure
	if (newNode == NULL){
		return OUT_OF_MEMORY;
	}

	//assign the data to the new node
	newNode->data = data;

	//Set the new nodes next pointer to what is at the front of the queue
	if((listPtr->curr == listPtr->head) && (listPtr->curr->prev == NULL)){
	newNode->next = listPtr->curr;

	listPtr->curr->prev = newNode;

	listPtr->head = newNode;
	}else if((listPtr->head !=listPtr->curr) && (listPtr->curr->prev != NULL)){
		newNode->next = listPtr->curr;
		newNode->prev = listPtr->curr->prev;
		listPtr->curr->prev->next = newNode;
		listPtr->curr = listPtr->curr->prev;


	}

}


/* Insert 'data' as a new node into the List immediately after 
   the current position ('curr'.)
		listPtr must not be NULL */
int insertAfterCurr(List* listPtr, int data)
{
	return SUCCESS;
}

/* Move 'curr' one position back in the list
   (towards head and away from tail).
		listPtr must not be NULL */
int currToPrev(List* listPtr)
{
	return SUCCESS;
}

/* Move 'curr' one position forward in the list
   (towards tail and away from head).
		listPtr must not be NULL */
int currToNext(List* listPtr)
{
	return SUCCESS;
}

/* Get the data stored at the current position in the list ('curr')
  (but do not remove it from the list). This is a 'peek' method.
		listPtr must not be NULL
		pointer to data must not be NULL */
int getDataAtCurr(List* listPtr, int *data)
{
	return SUCCESS;
}

/* Remove the node at the current position ('curr') from the List
   storing its data in the data pointer provided.
   'curr' should always be bounded by 'head' and 'tail'.
   Upon removal, 'curr' should move one item forward in the list (if moveForward != 0).
   Otherwise, 'curr' should move one item backward in the list (if moveForward == 0).
		listPtr must not be NULL
		pointer to data must not be NULL*/
int removeAtCurr(List* listPtr, int *data, int moveForward)
{
	return SUCCESS;
}


/* Free all memory used by the List. 
		listPtr must not be NULL */
int listFree(List* listPtr)
{
	return SUCCESS;
}
