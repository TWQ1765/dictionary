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
	//printf("linkedList=%d\n",*(char*)(linkedList->head->data));//try find struct or int,char type.
	
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
//only if void* data is not point to structure type.
ListItem* dataSearch(LinkedList * linkedList, void* inputData){
	char * error = (char*)inputData;//inputData only can be string for error display.
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
		while((tempItem->data != inputData) && (tempItem!=(tempList->tail))){//check until tail
			tempItem = tempItem->next;
		}
		if(tempItem->data != inputData){//check tail
			//return tempItem = tempItem->next; 
			throwError(1,"ERROR %d: '%s' is not found in the Dictionary.",1,(error));
		}else{
			return tempItem;
		}
	}
}
/* data search for linkedList which void* data point to structure type
 * function needed:
 * 1.) getNameFormDictionaryAndCompare;
 */
ListItem* searchItemFromDictionary(LinkedList * linkedList, char* inputData){
	char * error = inputData;
	//printf("linkedList=%s\n",((Dictionary*)(linkedList->head->data))->name);//try struct or int,char type.
	//printf("linkedList=%d\n",(char*)(linkedList->head->data));//try struct or int,char type
	LinkedList * tempList = linkedList;
	if (linkedList->head == NULL){
		return NULL;
	}else{
		ListItem *tempItem = tempList->head;
		while((getNameFormDictionaryAndCompare(tempItem,inputData)!=1)  && (tempItem!=(tempList->tail))){
			//check until tail
			tempItem = tempItem->next;
		}
		if(getNameFormDictionaryAndCompare(tempItem,inputData)!=1){//check tail
			throwError(1,"ERROR %d: '%s' is not found in the Dictionary.",1,(error));
		}else{
			return tempItem;
		}
	}
}
// true  = 1 , compare result same string.
// flase = 0 , compare result not same string.
int getNameFormDictionaryAndCompare(ListItem * item, char* inputData){
	char * tempData = ((Dictionary*)(item->data))->name;	
	//printf("is tempData=%s\n",tempData);
	//printf("is inputData=%s\n",inputData);
	int result = strcmp(tempData,inputData);
	//printf("is result=%d\n",result);
	if(result == 0){
		return 1;
	}else{
		return 0;
	}
}
/* how to differentiate void* data point to struct or int,char type?
 * no way to do that. so this fuction is only for void* data point to struct.
 * to remove paticular item from linkedList.
 */
void SearchAndRemoveDictionary(LinkedList * linkedList, void* inputData){
	ListItem *tempItem = searchItemFromDictionary(linkedList, inputData);//find item addr
	
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