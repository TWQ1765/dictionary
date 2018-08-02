#include "dictionary.h"

int addToDictionary(LinkedList* linkedList, char nameDic, char definitionDic){
	//Dictionary itemDictionary ={.name = nameDic, .definition = definitionDic};
	
}
/*
 *  If(count == 0)				If(count != 0)
 *	linkedList					linkedList
 *		head--->listItem			head--->listItem(n++)		listItem
 *					data=1						data(new)		data
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


/*
 * start a new structure that point to nothing.
 *	head-----		
 *			|				
 *	tail-----			
 *			|				
 *			NULL
 *	count = 0			
 */
void listInit(LinkedList* list){
	list->head=NULL;
	list->tail=NULL;
	list->count = 0;
}
/*
 *  If(count == 0)				If(count != 0)
 *	linkedList					linkedList
 *		head--->listItem			head--->listItem		listItem(n++)
 *					data=1						data			data(new)
 *					next-----					next----------->next-----
 *					perv-----		NULL<-------prev<-----------prev	|
 *		tail-------^		|		tail-------------------------^		|
 *		count = 1			--		count = n+1							--
 */	
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
	if(linkedList->head == NULL){
		linkedList->head = NULL;
		linkedList->tail =NULL;
		linkedList->count = 0;
	}else{
		tempAddr = linkedList->head->next;  
		linkedList->head = tempAddr;
		linkedList->head->pervious = NULL;
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
/* find the inputData stay in which item in the linkedList and match and remove that item.
 * function needed:
 * 1.) dataSearch;
 * 2.) ...
 * 3.) linkedListRemoveFrist;
 * 4.) linkedListRemoveLast;
 * 5.) listInit;
 */
void linkedListSearchRemove(LinkedList * linkedList, void* inputData){
	ListItem *tempItem = dataSearch(linkedList, inputData);//find item addr
	
	ListItem * itemNext = tempItem->next;
	ListItem * itemPerv = tempItem->pervious;
	int numNext = 0;
	if(itemNext == NULL && itemPerv != NULL)//the 1st item
	{
		linkedListRemoveLast(linkedList);
	}
	else if(itemNext != NULL && itemPerv == NULL)//the last item
	{
		linkedListRemoveFrist(linkedList);
	}
	else if(itemNext == NULL && itemPerv == NULL){ //only 1 item
		listInit(linkedList);
	}
	else{
		itemPerv -> next = itemNext;
		itemNext -> pervious = itemPerv;
		linkedList->count -= 1;
	}
}
//Search data on LinkedList return the address of the ListItem
//needed extral function like compareString;
ListItem* dataSearch(LinkedList * linkedList, void* inputData){
	
	LinkedList * tempList = linkedList;
	if (linkedList->head == NULL){
		return NULL;
	}else{
		ListItem *tempItem = tempList->head;
		/*just testing
		
		if (tempItem->next->next->data != inputData){//given 1
		return (ListItem*)100;
		}
		else{
			return (ListItem*)101;
		}
		*/
		//printf("tempItem=%d\n",tempItem);
		while((tempItem->data != inputData) ){//&& (tempItem!=NULL)
			/*
			if(tempItem == NULL){
			printf("is null\n");
			return tempItem = 0;
		}else{
			*/
			tempItem = tempItem->next;
			//printf("tempItem=%d\n",tempItem);
		}
		/*
		if(tempItem == NULL){
			printf("is null\n");
			return tempItem = 0;
		}else{
			*/
		return tempItem;
		
	}
}

void * getDataFormLinkList();