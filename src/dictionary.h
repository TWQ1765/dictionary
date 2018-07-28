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

typedef struct Dictionary Dictionary;
struct Dictionary{
   char *name;
   char *defination;
};
 


void linkedListAddToHead(LinkedList * linkList , ListItem* listItem);
void listInit(LinkedList * list);
void linkedListAddToTail(LinkedList * linkedList , ListItem* listItem);
void linkedListRemoveFrist(LinkedList * linkedList);
void linkedListRemoveLast(LinkedList * linkedList);
#endif // _DICTIONARY_H
