#ifndef _DICTIONARY_H
#define _DICTIONARY_H
#include	<stdio.h>
#include	<stdarg.h>
#include	<malloc.h>
#include	<stdlib.h>
#include	<string.h>
#include	<math.h>

typedef struct ListItem ListItem;
struct ListItem{
	ListItem *next;
	void *data;
};

typedef struct LinkedList LinkedList;
struct LinkedList{
	ListItem *head;
	ListItem *tail;
	int count;
};


typedef struct Dictionary {
   char name[50];
   char defination[100];
} Dictionary;
 
struct Node 
{
  int data;
  struct Node *next;
};


void linkedListAddToHead(LinkedList * linkList , ListItem* listItem);
void createLinkedList(struct Node* head,struct Node* second,struct Node* third);
void listInit(LinkedList * list);
#endif // _DICTIONARY_H
