#include "dictionary.h"

int addToDic(Dictionary * dictionary, char name, char definition){
	
	
}
	//linkedListAddToHead(&list, item);
void linkedListAddToHead(LinkedList * linkedList , ListItem* listItem){

		//LinkedList  linkedList 
	
}

//start a new structure that point to nothing.
void listInit(LinkedList * list){
	list->head=NULL;
	list->tail=NULL;
	list->count = 0;
}

/*
 * this function create a linked list  
 * 
 *	head---data = 1
 *	 |
 *	 node------->second-----data = 2
 *					|
 *					------------->third----data = 3
 *									|
 *									---------NULL
 */
void createLinkedList(struct Node* head,struct Node* second,struct Node* third){
	
	head = NULL;
    second = NULL;
    third = NULL;
	
	head = (struct Node*)malloc(sizeof(struct Node)); 
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));
	
	head->data = 1;
	head->next = second;
	
	second->data = 2;
	second->next = third;
	
	second->data = 3;
	second->next = NULL;
	printf("head->data = %d",head->data);
}

