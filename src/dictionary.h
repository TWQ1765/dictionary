#ifndef _DICTIONARY_H
#define _DICTIONARY_H
#include	<stdio.h>
#include	<stdarg.h>
#include	<malloc.h>
#include	<stdlib.h>
#include	<string.h>
#include	<math.h>
#include 	<ctype.h>
#include 	<Exception.h>
#include 	"Exception.h"
#include 	"CException.h"

typedef struct ListItem ListItem;
struct ListItem{
	ListItem *next;
	ListItem *pervious;
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
 
typedef struct StrCompare StrCompare;
struct StrCompare{
   int trueFalse;
   int sensitivity;
   char * nearIdaeData;
};

void linkedListAddToHead(LinkedList * linkList , ListItem* listItem);
void listInit(LinkedList * list);
void linkedListAddToTail(LinkedList * linkedList , ListItem* listItem);
void linkedListRemoveFrist(LinkedList * linkedList);
void linkedListRemoveLast(LinkedList * linkedList);
ListItem* dataSearch(LinkedList * linkedList, void * inputData);
void linkedListSearchRemove(LinkedList * linkedList, void * inputData);
int getNameFormDictionaryAndCompare(ListItem * item, char* inputData);
ListItem* searchItemFromDictionary(LinkedList * linkedList, char* inputData);
void SearchAndRemoveDictionary(LinkedList * linkedList, void* inputData);

char* find1stNonSpace(char * name);
int getWordLength(char* name);
char* createWordTolower(char* name , int length);
char* extractWork(char* name);
void freeDictionary(ListItem *item);//void*
char*toLower(char * line);
int stringCompare(char* testStr,char *inputStr);

//test

#endif // _DICTIONARY_H
