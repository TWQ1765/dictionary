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

#define ADD_HEAD 0
#define ADD_TAIL 1

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
//function linkedList
void linkedListAddToHead(LinkedList * linkList , ListItem* listItem);
void listInit(LinkedList * list);
void linkedListAddToTail(LinkedList * linkedList , ListItem* listItem);
void linkedListRemoveFrist(LinkedList * linkedList);
void linkedListRemoveLast(LinkedList * linkedList);
ListItem* dataSearch(LinkedList * linkedList, void * inputData);
//funtion Dictionary
void linkedListSearchRemove(LinkedList * linkedList, void * inputData);
int getNameFromDictionaryAndCompare(ListItem * item, char* inputData);
ListItem* searchItemFromDictionary(LinkedList * linkedList, char* inputData);
void SearchAndRemoveDictionary(LinkedList * linkedList, void* inputData);
char* find1stNonSpace(char * name);
int getWordLength(char* name);
char* createWordTolower(char* name , int length);
char* extractWork(char* name);
void freeDictionary(LinkedList *list);//void*
char*toLower(char * line);
int stringCompare(char* testStr,char *inputStr);
int SearchAvoidSameWork(LinkedList * linkedList, char* name);
void SearchAndAddDictionary(LinkedList* linkedList, ListItem* listItem, int addMode);
char* getDefination(LinkedList* linkedList, char* name);


#endif // _DICTIONARY_H
