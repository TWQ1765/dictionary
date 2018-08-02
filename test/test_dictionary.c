#include "unity.h"
#include "dictionary.h"

void setUp(void)
{}
void tearDown(void)
{}

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
//*
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
	
	TEST_ASSERT_EQUAL(1,*(int*)((*item).data));//*(int*)(item->data)
	TEST_ASSERT_EQUAL_STRING("asd",(char*)(((*itemString).data)));
	TEST_ASSERT_EQUAL_STRING("hi",((Dictionary*)(itemDictionary->data))->name);
	TEST_ASSERT_EQUAL_STRING(defination2,((Dictionary*)(itemDictionary->data))->defination);
}
//*/
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
 //*
void test_linkedListAddToHead_given_1_expect_item_inserted(void){
	LinkedList list = {.head=NULL, .tail=NULL, .count=0};
	int value = 1;
	ListItem itemData = {.next=NULL, .data=(void*)&value};
	ListItem * item = &itemData;
	
	linkedListAddToHead(&list, item);
	//printf("list.tail=%d\n",list.tail);
	//printf("item=%d\n",item);
	
	TEST_ASSERT_EQUAL(1,*(int*)((*item).data));
	TEST_ASSERT_EQUAL(item, list.tail);
	TEST_ASSERT_EQUAL(1, list.count);
}
//*/
/**
 *Strting from a Linked-List with item 1, add item 2 into it at head.
 *
 *	before					after
 *	head--->item 1			head---> item 2		item1
 *			next-----				 next-----> next-----
 *	tail-----^		|		tail------------------^		|
 *					--									--
 *	count = 1				count = 2
 *
 */
 //*
void test_linkedListAddToHead_given_linked_list_with_item_1_add_item_2_expect_2_then_1(void){
	
	int value1 = 1,value2 = 2;
	
	ListItem  itemData1 = {.next=NULL, .data=(void*)&value1};
	ListItem  itemData2 = {.next=NULL, .data=(void*)&value2};
	LinkedList list = {.head=&itemData1, .tail=&itemData1, .count=1};
	
	ListItem * item1 = &itemData1;
	ListItem * item2 = &itemData2;
	
	linkedListAddToHead(&list, item2);
	
	TEST_ASSERT_EQUAL(item2, list.head);
	TEST_ASSERT_EQUAL(item1, list.tail);
	TEST_ASSERT_EQUAL(item1, item2->next);
	TEST_ASSERT_EQUAL(NULL, item1->next);
	TEST_ASSERT_EQUAL(2, list.count);
}
//*/
/**
 *Strting from a Linked-List with item 2, add item 3 into it at head.
 *
 *	before				after
 *	head---> item 2		head---> item3		item 2		
 *  		  next----		 	 next-----> next-----  
 *	tail-------^	 |	tail------------------^		|
 *					--								--
 *	count = 2			count = 3
 *
 */
 //*
void test_linkedListAddToHead_given_linked_list_with_item_2_add_item_3_expect_3_then_2(void){
	
	int value3 = 3,value2 = 2;
	
	ListItem  itemData3 = {.next=NULL, .data=(void*)&value3};
	ListItem  itemData2 = {.next=NULL, .data=(void*)&value2};
	LinkedList list = {.head=&itemData2, .tail=&itemData2, .count=2};
	
	ListItem * item3 = &itemData3;
	ListItem * item2 = &itemData2;
	
	linkedListAddToHead(&list, item3);
	//printf("list.head->data =%d\n",*(int*)(list.head->data));//print item3 punya data
	//printf("list.head->next->data =%d\n",*(int*)(list.head->next->data));//print item2 punya data
	TEST_ASSERT_EQUAL(item3, list.head);
	TEST_ASSERT_EQUAL(item2, list.tail);
	TEST_ASSERT_EQUAL(item2, item3->next);
	TEST_ASSERT_EQUAL(NULL, item2->next);
	TEST_ASSERT_EQUAL(3, list.count);
	TEST_ASSERT_EQUAL(value2, *(int*)(list.head->next->data));
	TEST_ASSERT_EQUAL(value3, *(int*)(list.head->data));
}
//*/
/**
 *Strting from a Linked-List with item 2, add item 3 into it at tail.
 *
 *	before				after
 *	head---> item2		head---> item2		item3	
 *  		 next-----			 next-----> next-----
 *	tail------^		 |	tail------------------^		|
 *					--								--
 *	count = 2						count = 3
 *
 */
 //*
void test_linkedListAddToTail_given_linked_list_with_item_2_add_item_3_expect_3_then_2(void){
	
	int value3 = 3,value2 = 2;
	
	ListItem  itemData3 = {.next=NULL, .data=(void*)&value3};
	ListItem  itemData2 = {.next=NULL, .data=(void*)&value2};
	LinkedList list = {.head=&itemData2, .tail=&itemData2, .count=2};
	
	ListItem * item3 = &itemData3;
	ListItem * item2 = &itemData2;
	
	linkedListAddToTail(&list, item3);
	
	TEST_ASSERT_EQUAL(item3, list.tail);
	TEST_ASSERT_EQUAL(item2, list.head);
	TEST_ASSERT_EQUAL(item3, item2->next);
	TEST_ASSERT_EQUAL(NULL, item3->next);
	TEST_ASSERT_EQUAL(3, list.count);
	TEST_ASSERT_EQUAL(value3, *(int*)(list.head->next->data));
	TEST_ASSERT_EQUAL(value2, *(int*)(list.head->data));
}
//*/
/* testing whether LinkedList is update every time new item is added head or not.
 *
 *	before		after add head X1		after add head X2 		after add head X3
 *	head-----		head---> item1		head--->item2	item1	head--->item3	item2	item1
 *  	    |  			 	 next----- 			next--->next--- 		next--->next--->next---
 *	tail----|		tail------^		 |	tail--------------^	  | tail---------------------^	  |
 *			--						--						  --							  --
 *	count = 0		count = 1			count = 2						count = 3
 *
 *
 */
 //*
void test_linkedListAddToHead_given_empty_linkedlist_count_is_0_expect_count_2_when_run_two_time(void){
	
	int value3 = 3,value2 = 2,value1 = 1;
	ListItem  itemData3 = {.next=NULL, .data=(void*)&value3};
	ListItem  itemData2 = {.next=NULL, .data=(void*)&value2};
	ListItem  itemData1 = {.next=NULL, .data=(void*)&value1};
	ListItem * item3 = &itemData3;
	ListItem * item2 = &itemData2;
	ListItem * item1 = &itemData1;
	
	LinkedList list;
	
	listInit(&list);
	TEST_ASSERT_NULL(list.head);		
	TEST_ASSERT_NULL(list.tail);		
	TEST_ASSERT_EQUAL(0,list.count);	
	
	linkedListAddToHead(&list,&itemData1);
	TEST_ASSERT_EQUAL(item1, list.head);
	TEST_ASSERT_EQUAL(item1, list.tail);
	TEST_ASSERT_EQUAL(1, list.count);
	
	linkedListAddToHead(&list,&itemData2);
	TEST_ASSERT_EQUAL(item2, list.head);
	TEST_ASSERT_EQUAL(item1, list.tail);
	TEST_ASSERT_EQUAL(NULL, list.head->next->next);
	TEST_ASSERT_EQUAL(value2,*(int*)(list.head->data));
	TEST_ASSERT_EQUAL(value1,*(int*)(list.head->next->data));
	TEST_ASSERT_EQUAL(2, list.count);
	
	linkedListAddToHead(&list,&itemData3);
	TEST_ASSERT_EQUAL(item3, list.head);
	TEST_ASSERT_EQUAL(item1, list.tail);
	TEST_ASSERT_EQUAL(item2, list.head->next);
	TEST_ASSERT_EQUAL(item1, list.head->next->next);
	TEST_ASSERT_EQUAL(NULL, list.head->next->next->next);
	TEST_ASSERT_EQUAL(value3,*(int*)(list.head->data));
	TEST_ASSERT_EQUAL(value2,*(int*)(list.head->next->data));
	TEST_ASSERT_EQUAL(value1,*(int*)(list.head->next->next->data));
}
//*/
/* testing whether LinkedList is update every time new item is added tail or not.
 *
 *	before		after add tail X1			after add tail X2
 *	head-----		head---> item1				head--->		item1		item2	
 *  	    |  			 	 next----- 			 	next-----> 	next--->	next---
 *	tail----|		tail------^		 |				tail---------------------^	  |
 *			--						--								    		 --
 *	count = 0		count = 1						count = 2
 *
 *
 */
 //*
void test_linkedListAddToTail_given_empty_linkedlist_count_is_0_expect_count_2_when_run_two_time(void){
	
	int value3 = 3,value2 = 2,value1 = 1;
	ListItem  itemData3 = {.next=NULL, .data=(void*)&value3};
	ListItem  itemData2 = {.next=NULL, .data=(void*)&value2};
	ListItem  itemData1 = {.next=NULL, .data=(void*)&value1};
	ListItem * item3 = &itemData3;
	ListItem * item2 = &itemData2;
	ListItem * item1 = &itemData1;
	
	LinkedList list;
	
	listInit(&list);
	TEST_ASSERT_NULL(list.head);		
	TEST_ASSERT_NULL(list.tail);		
	TEST_ASSERT_EQUAL(0,list.count);	
	
	linkedListAddToTail(&list,&itemData1);
	TEST_ASSERT_EQUAL(item1, list.head);
	TEST_ASSERT_EQUAL(item1, list.tail);
	TEST_ASSERT_EQUAL(1, list.count);
	
	linkedListAddToTail(&list,&itemData2);
	TEST_ASSERT_EQUAL(item1, list.head);
	TEST_ASSERT_EQUAL(item2, list.tail);
	TEST_ASSERT_EQUAL(NULL, list.head->next->next);
	TEST_ASSERT_EQUAL(value1,*(int*)(list.head->data));
	TEST_ASSERT_EQUAL(value2,*(int*)(list.head->next->data));
	TEST_ASSERT_EQUAL(2, list.count);
}
//*/
/**
 * test from a empty Linked-List, add item 1 and item 2 into at head then add item3 at tail.
 *
 *	before					after add head					after add tail
 *	head---> item 1			head---> item2		item1		head---> item2		item1	item3	
 *  		 next---- 			 	 next-----> next-----			 next-----> next--->next---
 *	tail-------^	|		tail------------------^		|	tail-------------------------^	  |
 *					--									--								     --
 *	count = 1				count = 2						count = 3
 *
 */
 //*
void test_linkedListAddToTail_And_linkedListAddToHead_given_empty_list_\
add_item_1_then_item_2_at_head_and_add_item_3_at_tail(void){
	
	int value3 = 3,value2 = 2,value1 = 1;
	
	ListItem  itemData3 = {.next=NULL, .data=(void*)&value3};
	ListItem  itemData2 = {.next=NULL, .data=(void*)&value2};
	ListItem  itemData1 = {.next=NULL, .data=(void*)&value1};
	
	ListItem * item3 = &itemData3;
	ListItem * item2 = &itemData2;
	ListItem * item1 = &itemData1;
	LinkedList list;
	
	listInit(&list);
	TEST_ASSERT_NULL(list.head);		
	TEST_ASSERT_NULL(list.tail);		
	TEST_ASSERT_EQUAL(0,list.count);
	
	linkedListAddToHead(&list, item1);
	TEST_ASSERT_EQUAL(item1, list.head);
	TEST_ASSERT_EQUAL(item1, list.tail);
	TEST_ASSERT_EQUAL(1, list.count);
	
	linkedListAddToHead(&list,&itemData2);
	TEST_ASSERT_EQUAL(item2, list.head);
	TEST_ASSERT_EQUAL(item1, list.tail);
	TEST_ASSERT_EQUAL(2, list.count);
	
	linkedListAddToTail(&list, item3);
	
	TEST_ASSERT_EQUAL(item3, list.tail);
	TEST_ASSERT_EQUAL(item2, list.head);
	TEST_ASSERT_EQUAL(item3, list.head->next->next);
	TEST_ASSERT_EQUAL(item1, list.head->next->next->pervious);
	TEST_ASSERT_EQUAL(NULL, item3->next);
	TEST_ASSERT_EQUAL(3, list.count);
	TEST_ASSERT_EQUAL(value1, *(int*)(list.head->next->data));
	TEST_ASSERT_EQUAL(value2, *(int*)(list.head->data));
	TEST_ASSERT_EQUAL(value3, *(int*)(list.head->next->next->data));
}
//*/
/**
 *Strting from a Linked-List with item 2 then item 1 remove item 2.
 *
 *	before							after
 *	head---> item2		item 1		head---> item 1
 *  		 next-----> next-----  		 	 next-----
 *	tail------------------^		|	tail-------^	 |
 *								--					--
 *	count = 2						count = 1
 *
 */
 //*
void test_linkedListRemoveFrist_given_linked_list_with_item_2_and_item_1_expect_count_1(void){
	
	int value1 = 1,value2 = 2;
	
	ListItem  itemData1 = {.next=NULL, .data=(void*)&value1};
	ListItem  itemData2 = {.next=&itemData1, .data=(void*)&value2};
	LinkedList list = {.head=&itemData2, .tail=&itemData1, .count=2};
	
	linkedListRemoveFrist(&list);//REMOVE 1st
	
	TEST_ASSERT_EQUAL(&itemData1, list.head);
	TEST_ASSERT_EQUAL(&itemData1, list.tail);
	TEST_ASSERT_EQUAL(NULL, list.head->next);
	TEST_ASSERT_EQUAL(NULL, list.tail->next);
	TEST_ASSERT_EQUAL(1, list.count);
}
//*/

/**
 *Strting from a Linked-List with item 2 then item 1 remove item 1.
 *
 *	before							after
 *	head---> item2		item 1		head---> item 2
 *  		 next-----> next-----  		 	 next-----
 *    NULL<--perv <-----perv	|	  NULL<--perv	 |
 *	tail------------------^		|	tail-------^	 |
 *								--					--
 *	count = 2						count = 1
 *
 */
//*
void test_linkedListRemoveLast_given_item2_then_item1_count_2_expect_count_1(void){
	int value1 = 1,value2 = 2;
	ListItem  itemData2 = {.next=NULL,.pervious = NULL, .data=(void*)&value2};
	ListItem  itemData1 = {.next=NULL,.pervious = NULL, .data=(void*)&value1};
	
	ListItem * item2 = &itemData2;
	ListItem * item1 = &itemData1;
	LinkedList list;
	
	listInit(&list);
	TEST_ASSERT_NULL(list.head);		
	TEST_ASSERT_NULL(list.tail);
	TEST_ASSERT_EQUAL(0,list.count);
	
	linkedListAddToHead(&list, item1);
	TEST_ASSERT_EQUAL(item1, list.head);
	TEST_ASSERT_EQUAL(item1, list.tail);
	TEST_ASSERT_EQUAL(NULL, list.head->next);
	TEST_ASSERT_EQUAL(NULL, list.head->pervious);
	TEST_ASSERT_EQUAL(1, list.count);
	
	linkedListAddToHead(&list,&itemData2);
	TEST_ASSERT_EQUAL(item2, list.head);
	TEST_ASSERT_EQUAL(item1, list.tail);
	TEST_ASSERT_EQUAL(NULL, list.tail->next);
	TEST_ASSERT_EQUAL(NULL, list.head->pervious);
	TEST_ASSERT_EQUAL(item1, list.head->next);
	TEST_ASSERT_EQUAL(item2, list.head->next->pervious);
	TEST_ASSERT_EQUAL(2, list.count);
	
	linkedListRemoveLast(&list);
	TEST_ASSERT_EQUAL(item2, list.head);
	TEST_ASSERT_EQUAL(NULL, list.head->next);
	TEST_ASSERT_EQUAL(item2, list.tail);
	TEST_ASSERT_EQUAL(1, list.count);
}//*/

/**
 *Strting from a Linked-List with item 3 to item 1 remove item 1.
 *
 *	before									after
 *	head---> item3		item2 	item 1		head---> item 3		item2
 *  		 next-----> next---->next---|			 next-----> next-----
 *    NULL<--perv <-----perv<----perv	|	  NULL<--perv<------perv	|
 *	tail--------------------------^		|	tail----------------^	 	|
 *										--								--
 *	count = 3								count = 2
 *
 */
//*
void test_linkedListRemoveLast_given_item3_to_item2_then_item1_count_3_expect_count_2(void){
	int value3 = 3,value2 = 2,value1 = 1;
	
	ListItem  itemData3 = {.next=NULL, .data=(void*)&value3};
	ListItem  itemData2 = {.next=NULL, .data=(void*)&value2};
	ListItem  itemData1 = {.next=NULL, .data=(void*)&value1};
	
	ListItem * item3 = &itemData3;
	ListItem * item2 = &itemData2;
	ListItem * item1 = &itemData1;
	LinkedList list;
	
	listInit(&list);//tested
	linkedListAddToHead(&list, item1);//tested
	linkedListAddToHead(&list, item2);//tested
	linkedListAddToHead(&list, item3);//tested
	linkedListRemoveLast(&list);
	
	TEST_ASSERT_EQUAL(item3, list.head);
	TEST_ASSERT_EQUAL(item2, list.head->next);
	TEST_ASSERT_EQUAL(NULL, list.head->next->next);
	TEST_ASSERT_EQUAL(item3, list.head->next->pervious);
	TEST_ASSERT_EQUAL(item2, list.tail);
	TEST_ASSERT_EQUAL(NULL, list.tail->next);
	TEST_ASSERT_EQUAL(2, list.count);
}//*/
//*
void test_dataSearch_given_empty_list_expect_return_addrest_NULL(void){
	LinkedList emptyList;
	listInit(&emptyList);
	ListItem *tempItem = dataSearch(&emptyList, (void*)1);
	TEST_ASSERT_EQUAL(NULL,tempItem);
}
//*/
/**
 *Strting from a Linked-List with item 3 to item 1 find value2.
 *
 *	given:									return:
 *	head---> item3		item2 	item 1			address item2 
 * 			 value3		value2	value1	
 *  		 next-----> next---->next---|	main:
 *    NULL<--perv <-----perv<----perv	|	  find value2 in which item
 *	tail--------------------------^		|	
 *										--		
 *	count = 3					
 *
 */
 //*
void test_dataSearch_given_data_int_2_expect_return_addrest_item(void){
	
	int value3 = 3,value2 = 2,value1 = 1;
	
	ListItem  itemData3 = {.next=NULL, .data=(void*)&value3};
	ListItem  itemData2 = {.next=NULL, .data=(void*)&value2};
	ListItem  itemData1 = {.next=NULL, .data=(void*)&value1};
	
	ListItem * item3 = &itemData3;
	ListItem * item2 = &itemData2;
	ListItem * item1 = &itemData1;
	LinkedList list;
	
	///initialise linklist: item1->item2->item3->NULL
	listInit(&list);//tested
	linkedListAddToTail(&list, item1);//tested
	linkedListAddToTail(&list, item2);//tested
	linkedListAddToTail(&list, item3);//tested
	///end initialise
	
	ListItem *tempItem = dataSearch(&list, (void*)&value2);
	TEST_ASSERT_EQUAL(value2,*(int*)(list.head->next->data));
	TEST_ASSERT_EQUAL(tempItem,list.head->next);
	
}
//*/
/**
 *Strting from a Linked-List with item C to item A find valueA.
 *
 *	given:									return:
 *	head---> itemC		itemB 	item A			address itemA 
 * 			 valueC		valueB	valueA	
 *  		 next-----> next---->next---|	main:
 *    NULL<--perv <-----perv<----perv	|	  find valueA in which item
 *	tail--------------------------^		|	
 *										--		
 *	count = 3					
 */
 //*
void test_dataSearch_given_data_char_c_expect_return_addrest_itemA(void){
	
	char valueC = 'c',valueB = 'b',valueA = 'a';
	
	ListItem  itemDataC = {.next=NULL, .data=(void*)&valueC};
	ListItem  itemDataB = {.next=NULL, .data=(void*)&valueB};
	ListItem  itemDataA = {.next=NULL, .data=(void*)&valueA};
	
	ListItem * itemC = &itemDataC;
	ListItem * itemB = &itemDataB;
	ListItem * itemA = &itemDataA;
	LinkedList list;
	
	///initialise linklist: itemC->itemB->itemA->NULL
	listInit(&list);//tested
	linkedListAddToHead(&list, itemA);//tested
	linkedListAddToHead(&list, itemB);//tested
	linkedListAddToHead(&list, itemC);//tested
	///end initialise
	
	ListItem *tempItem = dataSearch(&list, (void*)&valueA);
	TEST_ASSERT_EQUAL(valueA,*(char*)(list.head->next->next->data));
	TEST_ASSERT_EQUAL(tempItem,list.head->next->next);
}
//*/
/**
 *Strting from a Linked-List with item C to item A find string1.
 *
 *	given:									return:
 *	head---> itemC		itemB 	item A			address itemA 
 * 			 string3	string2	string1	
 *  		 next-----> next---->next---|	main:
 *    NULL<--perv <-----perv<----perv	|	  find valueA in which item
 *	tail--------------------------^		|	
 *										--		
 *	count = 3					
 */
void test_dataSearch_given_data_string_abc_expect_return_addrest_itemA(void){
	
	char *string1 = "abc";
	char *string2 = "def";
	char *string3 = "ghi";
	char *stringtest = "zhi";
	ListItem  itemDataC = {.next=NULL, .data=(void*)string3};
	ListItem  itemDataB = {.next=NULL, .data=(void*)string2};
	ListItem  itemDataA = {.next=NULL, .data=(void*)string1};
	
	ListItem * itemC = &itemDataC;
	ListItem * itemB = &itemDataB;
	ListItem * itemA = &itemDataA;
	LinkedList list;
	
	///initialise linklist: itemC->itemB->itemA->NULL
	listInit(&list);
	linkedListAddToHead(&list, itemA);
	linkedListAddToHead(&list, itemB);
	linkedListAddToHead(&list, itemC);
	///end initialise
	
	ListItem *tempItem = dataSearch(&list, (void*)string1);//string1
	TEST_ASSERT_EQUAL(string1,(char*)(list.head->next->next->data));
	TEST_ASSERT_EQUAL(tempItem,list.head->next->next);
}
/**
 *Strting from a Linked-List with item C to item A find Dictionary1.
 *
 *	given:											return:
 *	head---> itemC			itemB 		item A			address itemA 
 * 			 Dictionary3	Dictionary2	Dictionary1	
 *  		 next	-----> 	next---->	next---|	main:
 *    NULL<--perv <-----	perv<-------perv   |	 	find Dictionary1->data 
 *	tail--------------------------^			   |		in which item.
 *											   --		
 *	count = 3					
 */
 //*
void test_dataSearch2_given_data_string_abc_expect_return_addrest_itemA(void){
	
	char *name1 = "amoeba";
	char *name2 = "bacterium";
	char *name3 = "Carnotaurus";
	char *defination1 = "Is a type of microorganism, one-celled animal, also spelled ameba.";
	char *defination2 = "A bacterium(plural bacteria) is a primitive, single-celled organism.";
	char *defination3 = "Carnotaurus was a meat-eating dinosaur with horns on its head.";
	Dictionary dictionary1 = {.name = name1 ,.defination = defination1};
	Dictionary dictionary2 = {.name = name2 ,.defination = defination2};
	Dictionary dictionary3 = {.name = name3 ,.defination = defination3};
	ListItem  itemDataC = {.next=NULL, .data=(void*)&dictionary3};
	ListItem  itemDataB = {.next=NULL, .data=(void*)&dictionary2};
	ListItem  itemDataA = {.next=NULL, .data=(void*)&dictionary1};
	
	ListItem * itemC = &itemDataC;
	ListItem * itemB = &itemDataB;
	ListItem * itemA = &itemDataA;
	LinkedList list;
	
	///initialise linklist: itemC->itemB->itemA->NULL
	listInit(&list);
	linkedListAddToHead(&list, itemA);
	linkedListAddToHead(&list, itemB);
	linkedListAddToHead(&list, itemC);
	///end initialise
	
	ListItem *tempItem = dataSearch(&list, (void*)(&dictionary2.name));
	TEST_ASSERT_EQUAL_STRING(name2,((Dictionary*)(list.head->next->data))->name);
	TEST_ASSERT_EQUAL_STRING(defination2,((Dictionary*)(list.head->next->data))->defination);
	TEST_ASSERT_EQUAL(tempItem,list.head->next);
}//*/
/**
 *Strting from a Linked-List with item 3 to item 1 remove item2.
 *
 *	before:									after:
 *	head---> item3		item2 	item 1		head---> item3		item1	
 * 			 value3		value2	value1				 value3		value1
 *  		 next-----> next---->next---|			 next-----> next----|
 *    NULL<--perv <-----perv<----perv	|	  NULL<--perv <-----perv    |
 *	tail--------------------------^		|	tail-------------------^    |
 *										--								--	
 *	count = 3								count = 2	
 *
 */
 //*
void test_linkedListSearchRemove_given_data_int_2_expect_count_2_item2_remove(void){
	
	int value3 = 3,value2 = 2,value1 = 1;
	
	ListItem  itemData3 = {.next=NULL, .data=(void*)&value3};
	ListItem  itemData2 = {.next=NULL, .data=(void*)&value2};
	ListItem  itemData1 = {.next=NULL, .data=(void*)&value1};
	
	ListItem * item3 = &itemData3;
	ListItem * item2 = &itemData2;
	ListItem * item1 = &itemData1;
	LinkedList list;
	
	///initialise linklist: item1->item2->item3->NULL
	listInit(&list);//tested
	linkedListAddToHead(&list, item1);//tested
	linkedListAddToHead(&list, item2);//tested
	linkedListAddToHead(&list, item3);//tested
	///end initialise
	TEST_ASSERT_EQUAL(3, list.count);
	
	linkedListSearchRemove(&list,(void*)&value2);
	TEST_ASSERT_EQUAL(value1,*(int*)(list.head->next->data));
	TEST_ASSERT_EQUAL(value3,*(int*)(list.head->data));
	TEST_ASSERT_EQUAL(item3, list.head);
	TEST_ASSERT_EQUAL(item1, list.tail);
	TEST_ASSERT_EQUAL(item1, list.head->next);
	TEST_ASSERT_EQUAL(item3, list.head->next->pervious);
	TEST_ASSERT_EQUAL(NULL, list.head->next->next);
	TEST_ASSERT_EQUAL(NULL, list.tail->next);
	TEST_ASSERT_EQUAL(NULL, list.head->pervious);
	TEST_ASSERT_EQUAL(2, list.count);
}
//*/
/**
 *Strting from a Linked-List with item 4 to item 1 remove item3.
 *
 *	before:										after:
 *	head---> item4	item3	item2 	item 1		head---> item4	item2	item1	
 * 			 value4	value3	value2	value1				 value4	value2	value1
 *  		 next -->next -->next--->next---|			 next--> next-->next--|
 *    NULL<--perv <-perv <---perv<----perv	|     NULL<--perv <--perv<--perv  |
 *	tail------------------------------^		|	tail---------------------^    |
 *											--								 --	
 *	count = 4									count = 3	
 *
 */
 //*
void test_linkedListSearchRemove_given_data_int_3_expect_count_3_item3_remove(void){
	
	int value4 = 4,value3 = 3,value2 = 2,value1 = 1;
	ListItem  itemData4 = {.next=NULL, .data=(void*)&value4};
	ListItem  itemData3 = {.next=NULL, .data=(void*)&value3};
	ListItem  itemData2 = {.next=NULL, .data=(void*)&value2};
	ListItem  itemData1 = {.next=NULL, .data=(void*)&value1};
	ListItem * item4 = &itemData4;
	ListItem * item3 = &itemData3;
	ListItem * item2 = &itemData2;
	ListItem * item1 = &itemData1;
	LinkedList list;
	
	///initialise linklist: 
	listInit(&list);
	linkedListAddToHead(&list, item1);
	linkedListAddToHead(&list, item2);
	linkedListAddToHead(&list, item3);
	linkedListAddToHead(&list, item4);
	///end initialise
	TEST_ASSERT_EQUAL(4, list.count);
	
	linkedListSearchRemove(&list,(void*)&value3);
	TEST_ASSERT_EQUAL(value1,*(int*)(list.head->next->next->data));
	TEST_ASSERT_EQUAL(value2,*(int*)(list.head->next->data));
	TEST_ASSERT_EQUAL(value4,*(int*)(list.head->data));
	TEST_ASSERT_EQUAL(item4, list.head);
	TEST_ASSERT_EQUAL(item1, list.tail);
	TEST_ASSERT_EQUAL(item2, list.head->next);
	TEST_ASSERT_EQUAL(item4, list.head->next->pervious);
	TEST_ASSERT_EQUAL(item2, list.head->next->next->pervious);
	TEST_ASSERT_EQUAL(NULL, list.head->next->next->next);
	TEST_ASSERT_EQUAL(NULL, list.tail->next);
	TEST_ASSERT_EQUAL(NULL, list.head->pervious);
	TEST_ASSERT_EQUAL(3, list.count);
}
//*/
/**
 *Strting from a Linked-List with item 4 to item 1 remove item4.
 *
 *	before:										after:
 *	head---> item4	item3	item2 	item 1		head---> item3	item2	item1	
 * 			 value4	value3	value2	value1				 value3	value2	value1
 *  		 next -->next -->next--->next---|			 next--> next-->next--|
 *    NULL<--perv <-perv <---perv<----perv	|     NULL<--perv <--perv<--perv  |
 *	tail------------------------------^		|	tail---------------------^    |
 *											--								 --	
 *	count = 4									count = 3	
 *
 */
 //*
void test_linkedListSearchRemove_given_data_int_4_expect_count_3_item4_remove(void){
	
	int value4 = 4,value3 = 3,value2 = 2,value1 = 1;
	ListItem  itemData4 = {.next=NULL, .data=(void*)&value4};
	ListItem  itemData3 = {.next=NULL, .data=(void*)&value3};
	ListItem  itemData2 = {.next=NULL, .data=(void*)&value2};
	ListItem  itemData1 = {.next=NULL, .data=(void*)&value1};
	ListItem * item4 = &itemData4;
	ListItem * item3 = &itemData3;
	ListItem * item2 = &itemData2;
	ListItem * item1 = &itemData1;
	LinkedList list;
	
	///initialise linklist: 
	listInit(&list);
	linkedListAddToHead(&list, item1);
	linkedListAddToHead(&list, item2);
	linkedListAddToHead(&list, item3);
	linkedListAddToHead(&list, item4);
	///end initialise
	TEST_ASSERT_EQUAL(4, list.count);
	
	linkedListSearchRemove(&list,(void*)&value4);
	TEST_ASSERT_EQUAL(value1,*(int*)(list.head->next->next->data));
	TEST_ASSERT_EQUAL(value2,*(int*)(list.head->next->data));
	TEST_ASSERT_EQUAL(value3,*(int*)(list.head->data));
	TEST_ASSERT_EQUAL(item3, list.head);
	TEST_ASSERT_EQUAL(item1, list.tail);
	TEST_ASSERT_EQUAL(item2, list.head->next);
	TEST_ASSERT_EQUAL(item3, list.head->next->pervious);
	TEST_ASSERT_EQUAL(item2, list.head->next->next->pervious);
	TEST_ASSERT_EQUAL(NULL, list.head->next->next->next);
	TEST_ASSERT_EQUAL(NULL, list.tail->next);
	TEST_ASSERT_EQUAL(NULL, list.head->pervious);
	TEST_ASSERT_EQUAL(3, list.count);
}//*/
/**
 *Strting from a Linked-List with item 4 to item 1 remove item1.
 *
 *	before:										after:
 *	head---> item4	item3	item2 	item 1		head---> item4	item3	item2	
 * 			 value4	value3	value2	value1				 value4	value3	value2
 *  		 next -->next -->next--->next---|			 next--> next-->next--|
 *    NULL<--perv <-perv <---perv<----perv	|     NULL<--perv <--perv<--perv  |
 *	tail------------------------------^		|	tail---------------------^    |
 *											--								 --	
 *	count = 4									count = 3	
 *
 */
 //*
void test_linkedListSearchRemove_given_data_int_1_expect_count_3_item1_remove(void){
	
	int value4 = 4,value3 = 3,value2 = 2,value1 = 1;
	ListItem  itemData4 = {.next=NULL, .data=(void*)&value4};
	ListItem  itemData3 = {.next=NULL, .data=(void*)&value3};
	ListItem  itemData2 = {.next=NULL, .data=(void*)&value2};
	ListItem  itemData1 = {.next=NULL, .data=(void*)&value1};
	ListItem * item4 = &itemData4;
	ListItem * item3 = &itemData3;
	ListItem * item2 = &itemData2;
	ListItem * item1 = &itemData1;
	LinkedList list;
	
	///initialise linklist: 
	listInit(&list);
	linkedListAddToHead(&list, item1);
	linkedListAddToHead(&list, item2);
	linkedListAddToHead(&list, item3);
	linkedListAddToHead(&list, item4);
	///end initialise
	TEST_ASSERT_EQUAL(4, list.count);
	
	linkedListSearchRemove(&list,(void*)&value1);
	TEST_ASSERT_EQUAL(value2,*(int*)(list.head->next->next->data));
	TEST_ASSERT_EQUAL(value3,*(int*)(list.head->next->data));
	TEST_ASSERT_EQUAL(value4,*(int*)(list.head->data));
	TEST_ASSERT_EQUAL(item4, list.head);
	TEST_ASSERT_EQUAL(item2, list.tail);
	TEST_ASSERT_EQUAL(item3, list.head->next);
	TEST_ASSERT_EQUAL(item4, list.head->next->pervious);
	TEST_ASSERT_EQUAL(item3, list.head->next->next->pervious);
	TEST_ASSERT_EQUAL(NULL, list.head->next->next->next);
	TEST_ASSERT_EQUAL(NULL, list.tail->next);
	TEST_ASSERT_EQUAL(NULL, list.head->pervious);
	TEST_ASSERT_EQUAL(3, list.count);
}//*/