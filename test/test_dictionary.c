#include "unity.h"
#include "dictionary.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_dictionary_NeedToImplement(void)
{
    TEST_IGNORE_MESSAGE("Need to Implement dictionary");
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
void test_listInit_given_a_new_structure_should_piont_to_NULL(void){
	LinkedList list ={
		(ListItem*)NULL,
		(ListItem*)NULL,
		10
	};
	listInit(&list);
	TEST_ASSERT_NULL(list.head);		//NULL
	TEST_ASSERT_NULL(list.tail);		//NULL
	TEST_ASSERT_EQUAL(0,list.count);	//0
	
	
}

/**
 *Strting from an empty Linked-List,add item 1 into it.
 *
 *	before					after
 *	head-----			head---> item 1
 *			|					 next-----
 *	tail-----			tail-------^ 	 |
 *			|							--
 *			--
 *	count = 0			count = 1
 *
 */
 /*
void test_linkedListAddToHead_given_1_expect_item_inserted(void){
	LinkedList list = {.head=NULL, .tail=NULL, .count=0};
	int value = 1;
	ListItem * item = {.next=NULL, .data=(void*)&value};
	LinkedList list = {.head=NULL, .tail=NULL, .count=0};
	
	linkedListAddToHead(&list, item);
	
	TEST_ASSERT_EQUAL(item, list.head);
	TEST_ASSERT_EQUAL(item, list.tail);
	TEST_ASSERT_EQUAL(1, list.count);
}
*/
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
	ListItem * item = {.next=NULL, .data=(void*)&value1};
	ListItem * item = {.next=NULL, .data=(void*)&value2};
	LinkedList list = {.head=NULL, .tail=NULL, .count=1};
	
	linkedListAddToHead(&list, item2);
	
	TEST_ASSERT_EQUAL(item2, list.head);
	TEST_ASSERT_EQUAL(item1, list.tail);
	TEST_ASSERT_EQUAL(item1, item2->next);
	TEST_ASSERT_EQUAL(NULL, item1->next);
	TEST_ASSERT_EQUAL(2, list.count);
}
*/