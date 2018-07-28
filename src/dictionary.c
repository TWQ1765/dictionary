#include "dictionary.h"

int addToDic(Dictionary * dictionary, char name, char definition){
	
	
}
/*
 *  If(count == 0)				If(count != 0)
 *	linkedList					linkedList
 *		head--->listItem			head--->listItem(n)		listItem(n++)
 *					data=1						data=n			data=n+1
 *					next-----					next----------->next-----
 *		tail-------^		|		tail-------------------------^		|
 *		count = 1			--		count = n+1							--
 */	
void linkedListAddToHead(LinkedList* linkedList , ListItem* listItem){
	
	ListItem* previousAddr = 0;
	if(linkedList->count == 0){
		linkedList -> head = listItem;
		linkedList -> tail = listItem;
		linkedList -> count += 1;
		linkedList -> head -> next = NULL;
	}
	else{
		previousAddr = linkedList -> head;
		linkedList -> head = listItem;
		listItem -> next = previousAddr;
		linkedList -> tail -> next = NULL;
		linkedList -> count += 1;
	}
}

//start a new structure that point to nothing.
void listInit(LinkedList* list){
	list->head=NULL;
	list->tail=NULL;
	list->count = 0;
}

void linkedListAddToTail(LinkedList * linkedList , ListItem* listItem){
	ListItem* previousAddr = 0;
	if(linkedList->count == 0){
		linkedList -> head = listItem;
		linkedList -> tail = listItem;
		linkedList -> count += 1;
		linkedList -> head -> next = NULL;
	}
	else{
		linkedList -> count += 1;
		previousAddr = linkedList -> tail;
		//printf("previousAddr=%d\n",previousAddr);
		//printf("linkedList->head->next=%d\n",linkedList->head->next);
		linkedList -> tail = listItem;
		previousAddr->next = listItem;
		linkedList -> tail -> next = NULL;
		//linkedList -> head -> next = listItem;
	}
}

void linkedListRemoveFrist(LinkedList * linkedList){
	ListItem* tempAddr = 0;
	//*test something
	//linkedList++;
	//printf("\n")
	//*/
	if(linkedList->head == NULL){
		linkedList->head = NULL;
		linkedList->tail =NULL;
		linkedList->count = 0;
	}else{
		tempAddr = linkedList->head->next;  
		linkedList->head = tempAddr;
		linkedList->count -= 1;
	}
}
void linkedListRemoveLast(LinkedList * linkedList){
	ListItem* tempAddr = 0;
	
	if(linkedList->tail == NULL){
		linkedList->head = NULL;
		linkedList->tail =NULL;
		linkedList->count = 0;
	}else{
		tempAddr = linkedList->tail;  
		
		linkedList->count -= 1;
	}
}