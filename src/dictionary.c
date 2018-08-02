#include "dictionary.h"

int addToDic(Dictionary * dictionary, char name, char definition){
	
	
}
/*
 *  If(count == 0)				If(count != 0)
 *	linkedList					linkedList
 *		head--->listItem			head--->listItem(n)		listItem(n++)
 *					data=1						data=n			data=n+1
 *					next-----					next----------->next-----
 *					perv-----		NULL<-------prev<-----------prev	|
 *		tail-------^		|		tail-------------------------^		|
 *		count = 1			--		count = n+1							--
 */	
void linkedListAddToHead(LinkedList* linkedList , ListItem* listItem){
	
	ListItem* perviousAddr = 0;
	if(linkedList->count == 0){
		linkedList -> head = listItem;
		linkedList -> tail = listItem;
		linkedList -> head -> pervious = NULL;
		linkedList -> count += 1;
		linkedList -> head -> next = NULL;
	}
	else{
		perviousAddr = linkedList -> head;
		linkedList -> head = listItem;
		linkedList -> head -> pervious = NULL;
		linkedList -> head -> next = perviousAddr;
		linkedList -> head -> next -> pervious = listItem;
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
		linkedList -> head -> pervious = NULL;
		linkedList -> tail = listItem;
		previousAddr->next = listItem;
		linkedList -> tail -> next = NULL;
		linkedList -> tail -> pervious = previousAddr;
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
	ListItem* tempTailAddr = 0;
	
	//printf("linkedList=%d",linkedList);
	
	if(linkedList->head == NULL){
		linkedList->head = NULL;
		linkedList->tail =NULL;
		linkedList->count = 0;
	}else{
		//tempTailAddr = linkedList->tail;  
		tempTailAddr = linkedList->tail->pervious ;
		linkedList->tail = tempTailAddr;
		linkedList->tail->next = NULL;
		linkedList->count -= 1;
	}
}
void linkedListSearchRemove(LinkedList * linkedList, int data){
	
	
	
	
}
//Search data on LinkedList return the address of the ListItem
ListItem* dataSearch(LinkedList * linkedList, void * inputData){
	int value = 0;
	ListItem  item = {.next = NULL , .data=(void*)&value};
	LinkedList * tempList = linkedList;
	if (linkedList->head == NULL){
		linkedList -> head = &item;
		return linkedList->head;
	}else{
		
		//while(tempList->head->data != inputData);
	}
}