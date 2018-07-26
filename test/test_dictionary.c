#include "unity.h"
#include "dictionary.h"

void setUp(void)
{
}

void tearDown(void)
{
}


//*
void test_addToDic_given_NULL_expect_return_false(void){
	
	
}
//*/

void test_createLinkedList_try(void){
	struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;
	createLinkedList(head,second,third);
	//printf(" data=%d\n ", head->data);
	
}
/*
 * create only 1st list in the linked list. 
 * should piont to NULL and count is zero.
 *
 *	head-----		
 *			|				
 *	tail-----			
 *			|				
 *			NULL
 *	count = 0			
 */
void test_listInit_given_a_new_structure_should_piont_to_NULL(void){
	LinkedList listTest; 
	listInit(&listTest);
	TEST_ASSERT_NULL(listTest.head);		//NULL
	TEST_ASSERT_NULL(listTest.tail);		//NULL
	TEST_ASSERT_EQUAL(0,listTest.count);	//0
}

void test_testSomething_understanding_for_pointers(void){
	LinkedList list = {.head=NULL, .tail=NULL, .count=0};
	
	int value = 1;
	char *Cvalue = "asd";
	char *name2 = "hi";
	char *defination2 = "used as a friendly greeting or to attract attention.";
	Dictionary dictionary = {.name=name2,.defination=defination2};
	
	ListItem itemData = {.next=NULL, .data=(void*)&value};
	ListItem itemData2 = {.next=NULL, .data=(void*)Cvalue};
	ListItem itemData3 = {.next=NULL, .data=(Dictionary*)&dictionary};
	
	ListItem * item = &itemData;
	ListItem * itemString = &itemData2;
	ListItem * itemDictionary = &itemData3;
	
	//printf("list->count=%d\n",(list.count));
	///->print data as int.
	//printf("item->data=%d\n",*(int*)((*item).data));
	///->print data as string.
	//printf("itemString->data=%s\n",(char*)(((*itemString).data))+0); 
	
	///-> directly print dictionary
	//printf("dictionary->name=%s\n",dictionary.name); 
	//printf("dictionary->defination=%s\n",dictionary.defination); 
	
	///->print data as struct type.
	//Dictionary *temp = (Dictionary*)(itemDictionary->data);
	//printf("itemDictionary->name=%s\n",temp->name); 
	
	//printf("itemDictionary->name=%s\n",((Dictionary*)(itemDictionary->data))->name); 
	//printf("itemDictionary->defination=%s\n",((Dictionary*)(itemDictionary->data))->defination); 
	
	TEST_ASSERT_EQUAL(1,*(int*)((*item).data));
	TEST_ASSERT_EQUAL_STRING("asd",(char*)(((*itemString).data)));
	TEST_ASSERT_EQUAL_STRING("hi",((Dictionary*)(itemDictionary->data))->name);
	TEST_ASSERT_EQUAL_STRING(defination2,((Dictionary*)(itemDictionary->data))->defination);
}

/**
 *Strting from an empty Linked-List,add item 1 into it.
 *
 *	before				after
 *	head-----			head---> item 1
 *			|					 next-----
 *	tail-----			tail-------^ 	 |
 *			|							--
 *			--
 *	count = 0			count = 1
 *
 */
void test_linkedListAddToHead_given_1_expect_item_inserted(void){
	LinkedList list = {.head=NULL, .tail=NULL, .count=0};
	int value = 1;
	ListItem itemData = {.next=NULL, .data=(void*)&value};
	ListItem * item = &itemData;
	
	linkedListAddToHead(&list, item);
	printf("list.tail=%d\n",list.tail);
	printf("item=%d\n",item);
	
	TEST_ASSERT_EQUAL(1,*(int*)((*item).data));
	TEST_ASSERT_EQUAL(item, list.tail);
	TEST_ASSERT_EQUAL(1, list.count);
}
/**
 *Strting from a Linked-List with item 1, add item 2 into it.
 *
 *	before					after
 *	head--->item 1			head---> item 2		item1
 *			next-----				 next-----> next-----
 *	tail-----^		|		tail------------------^		|
 *					--									--
 *	count = 1				count = 2
 *
 */
 /*
void test_linkedListAddToHead_given_linked_list_with_item_1_add_item_2_expect_2_then_1(void){
	
	int value1 = 1,value2 = 2;
	LinkedList list = {.head=NULL, .tail=NULL, .count=1};
	ListItem  itemData1 = {.next=NULL, .data=(void*)&value1};
	ListItem  itemData2 = {.next=NULL, .data=(void*)&value2};
	
	ListItem * item1 = &itemData1;
	ListItem * item2 = &itemData2;
	
	linkedListAddToHead(&list, item2);
	
	TEST_ASSERT_EQUAL(item2, list.head);
	//TEST_ASSERT_EQUAL(item1, list.tail);
	//TEST_ASSERT_EQUAL(item1, item2->next);
	//TEST_ASSERT_EQUAL(NULL, item1->next);
	//TEST_ASSERT_EQUAL(2, list.count);
}
*/
void test_linkedListAddToHead_given_linked_list_with_item_1_add_item_2_expect_2_then_1(void){
	
	int value1 = 1,value2 = 2;
	
	//ListItem  itemData1 = {.next=NULL, .data=(void*)&value1};
	//ListItem  itemData2 = {.next=NULL, .data=(void*)&value2};
	//LinkedList list = {.head=&itemData1, .tail=&itemData1, .count=1};
	
	//ListItem * item1 = &itemData1;
	//ListItem * item2 = &itemData2;
	
	//linkedListAddToHead(&list, item2);
	
	//TEST_ASSERT_EQUAL(item2, list.head);
	//TEST_ASSERT_EQUAL(item1, list.tail);
	//TEST_ASSERT_EQUAL(item1, item2->next);
	//TEST_ASSERT_EQUAL(NULL, item1->next);
	//TEST_ASSERT_EQUAL(2, list.count);
}