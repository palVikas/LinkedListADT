#include "stdio.h"
#include "linkedList.h"
#include "stdlib.h"
#include "expr_assert.h"

LinkedList list;
Node* result;

void test_for_createList_create_an_empty_list_and_gives_head_and_tail_is_null(){
	list = createList();
	assertEqual(sizeof(list),12);
	assert(list.head==NULL);
	assert(list.tail==NULL);
	assertEqual(list.count,0);
};

void test_create_node_to_create_for_int_data_and_gives_next_to_null(){
	int x =4;
	result = create_node(&x);
	assertEqual(*(int*)result->data,4);
	assert(result->next== NULL);
	free(result);
};

void test_create_node_create_for_char_data_and_gives_next_to_null(){
	char ch = 'c';
	result = create_node(&ch);
	assertEqual(*(char*)result->data ,'c');
	assert(result->next == NULL);
	free(result);
}
void test_create_node_create_for_string_data_and_gives_next_to_null(){
	char* str = "vikas";
	result = create_node(&str);
	assert(*(char**)result->data == "vikas");
	assert(result->next == NULL);
	free(result);
}


void test_create_node_create_for_float_data_and_gives_next_to_null(){
	float f = 3.14;
	result = create_node(&f);
	assert(*(float*)result->data==(float)3.14);
	assert(result->next == NULL);
	free(result);
}
void test_for_add_to_list_add_node_in_the_null_linked_list(){
	int x=5;
	Node* node = create_node(&x);
	assertEqual(add_to_list(&list, node),1);
	assert(list.head==node);
	assertEqual(*(int*)node->data,5);
	free(node);
}
void test_for_add_to_list_add_two_node_first_as_head_and_second_as_tail_in_linkedlist(){
	int x=5,y=17;
	Node* node1 = create_node(&x);
	Node* node2 = create_node(&y);
	 list = createList();
	add_to_list(&list, node1);
	assert(list.head==node1);
	assertEqual(*(int*)node1->data,5);
	add_to_list(&list,node2);
	assert(list.tail==node2);
	assertEqual(*(int*)node2->data,17);
	free(node1);
	free(node2);
};

void test_for_get_first_element_in_the_linkedList(){
	int x=5;
	Node* node1 = create_node(&x);
	 list = createList();
	add_to_list(&list, node1);
	result = get_first_element(list);
	assertEqual(*(int*)result->data, 5);
	free(result);
}

void test_for_get_first_element_if_two_elements_are_added(){
	int x=5,y=6;
	Node* node1 = create_node(&x);
	Node* node2 = create_node(&y);
	 list = createList();
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	result = get_first_element(list);
	assertEqual(*(int*)result->data, 5);
	free(result);
}

void test_for_get_last_element_in_the_linkedList(){
	int x=5;
	Node* node1 = create_node(&x);
	LinkedList list = createList();
	add_to_list(&list, node1);
	result = get_last_element(list);
	assertEqual(*(int*)result->data, 5);
	free(result);
}

void test_for_get_last_element_if_two_elements_are_added(){
	int x=5,y=6;
	Node* node1 = create_node(&x);
	Node* node2 = create_node(&y);
	LinkedList list = createList();
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	result = get_last_element(list);
	assertEqual(*(int*)result->data, 6);
	free(result);
}

void add(void* data){
	(*(int*)data)+=2;
}

void test_for_traverse_goto_each_elements_and_increment_data_by_2(){
	int x=5,y=6;
	LinkedList list = createList();
	Node* node1 = create_node(&x);
	Node* node2 = create_node(&y);
	add_to_list(&list, node1);
	add_to_list(&list, node2);
 	traverse(list,add);
 	assertEqual((*(int*)(list.head)->data),7);
 	assertEqual((*(int*)(list.tail)->data),8);
 	free(node1);
 	free(node2);
};

void test_getElementAt_returns_element_at_given_index_in_list(){
	int x = 9, y=10, *result;
	LinkedList list = createList();
	Node *node1 = create_node(&x);
	Node *node2 = create_node(&y);

	add_to_list(&list,node1);
	add_to_list(&list,node2);

	result = getElementAt(list, 1);
	assertEqual(*(int*)result, 10);
}

void test_getElementAt_returns_null_if_given_index_not_in_the_list(){
	int x = 9, y=10, *result;
	LinkedList list = createList();
	Node *node1 = create_node(&x);
	Node *node2 = create_node(&y);

	add_to_list(&list,node1);
	add_to_list(&list,node2);

	result = getElementAt(list, -1);
	assert(result == NULL);
}
void test_getElementAt_returns_element_at_given_index_in_list_of_2(){
	int x = 9, y=10,z=6,a=3, *result;
	LinkedList list = createList();
	Node *node1 = create_node(&x);
	Node *node2 = create_node(&y);
	Node *node3 = create_node(&z);
	Node *node4 = create_node(&a);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	add_to_list(&list,node4);

	result = getElementAt(list, 2);
	assertEqual(*(int*)result, 6);
}

void test_getElementAt_returns_char_type_element_at_given_index_in_list(){
	char x = 'c', y='d', *result;
	LinkedList list = createList();
	Node *node1 = create_node(&x);
	Node *node2 = create_node(&y);

	add_to_list(&list,node1);
	add_to_list(&list,node2);

	result = getElementAt(list, 1);
	assertEqual(*(char*)result, 'd');
	
}

void test_getElementAt_returns_char_type_element_gives_null_if_index_not_in_list(){
	char x = 'c', y='d', *result;
	LinkedList list = createList();
	Node *node1 = create_node(&x);
	Node *node2 = create_node(&y);

	add_to_list(&list,node1);
	add_to_list(&list,node2);

	result = getElementAt(list, 3);
	assert(result == NULL);
	
}

void test_getElementAt_for_float_element_at_given_index_in_list_of(){
	float x = 9, y=10, *result;
	LinkedList list = createList();
	Node *node1 = create_node(&x);
	Node *node2 = create_node(&y);

	add_to_list(&list,node1);
	add_to_list(&list,node2);

	result = getElementAt(list, 1);
	assert(*(float*)result == 10);
};

void test_indexOf_gives_the_index_if_element_match_of_that_list(){
	int x=5,y=4,z=6,result;

	LinkedList list = createList();
	Node *node1 = create_node(&x);
	Node *node2 = create_node(&y);
	Node *node3 = create_node(&z);


	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);


	result = indexOf(list,&y);
	assertEqual(result, 1);
	result = indexOf(list,&z);
	assertEqual(result, 2);
}

void test_indexOf_gives_the_index_if_char_type_element_match_of_that_list(){
	char a='a',b='b',c='c',result;

	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	Node *node3 = create_node(&c);


	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);


	result = indexOf(list,&a);
	assertEqual(result, 0);
	result = indexOf(list,&c);
	assertEqual(result, 2);
}

void test_for_deleteElement_delete_the_0_element_for_given_index(){
	int x=5,y=4,z=6,a=7,*result;

	LinkedList list = createList();
	Node *node1 = create_node(&x);
	Node *node2 = create_node(&y);
	Node *node3 = create_node(&z);
	Node *node4 = create_node(&a);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	add_to_list(&list,node4);

	result = deleteElementAt(&list,0);
	assertEqual(*(int*)result,5);
	assertEqual(indexOf(list,&y), 0);
	assertEqual(indexOf(list,&z), 1);
	assertEqual(indexOf(list,&a), 2);
}

void test_indexOf_returns_minus_1_if_index_is_not_found_in_in_the_list(){
	char a = 'v', b = 'i';
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	add_to_list(&list,node1);

	assert(indexOf(list, &b) == -1);
	free(node1); 
}

void test_indexOf_returns_minus_1_of_when_given_double_value_is_not_in_the_list(){
	double a = 12.2, b = 3.4, c = 14.6;
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	add_to_list(&list, node1);
	add_to_list(&list, node2);

	assertEqual(indexOf(list, &c), -1);
	free(node1); free(node2); 
}
void test_for_deleteElement_delete_the_2_element_for_given_index(){
	int x=5,y=4,z=6,a=7,*result;

	LinkedList list = createList();
	Node *node1 = create_node(&x);
	Node *node2 = create_node(&y);
	Node *node3 = create_node(&z);
	Node *node4 = create_node(&a);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	add_to_list(&list,node4);

	result = deleteElementAt(&list,2);
	assertEqual(*(int*)result,6);
	assertEqual(indexOf(list,&x), 0);
	assertEqual(indexOf(list,&y), 1);
	assertEqual(indexOf(list,&a), 2);
};

void test_deleteElementAt_returns_NULL_when_index_is_not_found_in_list(){
	double a = 12.4, b = 3.4;
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	add_to_list(&list,node1);
	add_to_list(&list,node2);

	assert((double*)deleteElementAt(&list, -3) == NULL);
	free(node1); free(node2);
};

void test_asArray_return_the_number_of_node_in_the_list(){
	int a=4,b=5,c=6;
	void **array=(void**)malloc(sizeof(int*)*3);

	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	Node *node3 = create_node(&c);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);

	assertEqual(asArray(list,array), 3);
	assert(array[0] == &a);
	assert(array[1] == &b);
	assert(array[2] == &c);

	assertEqual(*(int*)array[2],6);
	assertEqual(*(int*)array[1],5);
	assertEqual(*(int*)array[0],4);

}


void test_asArray_does_not_populates_double_Array_and_returns_0_when_list_is_empty(){
	double **array = (double**)malloc(sizeof(double*));
	LinkedList list = createList();
	assert(asArray(list, (void**)array) == 0);
	free(array);
}
void test_asArray_does_not_populates_char_Array_and_returns_0_when_list_is_empty(){
	char **array = (char**)malloc(sizeof(char*));
	LinkedList list = createList();

	assert(asArray(list, (void**)array) == 0);
	free(array);
}
void test_asArray_populates_int_Array_with_char_Nodes_data_and_returns_number_of_elements_added_to_the_array(){
	char a = 'x', b = 'y';
	char **array = (char**)malloc(sizeof(char*)*2);
	LinkedList list = createList();
	Node *node1 = create_node(&a);
	Node *node2 = create_node(&b);
	add_to_list(&list,node1);
	add_to_list(&list,node2);

	assert(asArray(list, (void**)array) == 2);
	assert(array[0] == &a);
	assert(array[1] == &b);

	assert(*(char*)(array[0]) == 'x');
	assert(*(char*)(array[1]) == 'y');
	free(array);
}

void test_asArray_does_not_populates_float_Array_and_returns_0_when_list_is_empty(){
	float **array = (float**)malloc(sizeof(float*));
	LinkedList list = createList();

	assert(asArray(list, (void**)array) == 0);
	free(array);
};


int isLessThan(void* data){
	return ((*(int*)data) <= 5)? 1: 0;
};

void test_for_filter_gives_all_the_nodes_which_data_is_less_than_5_(){
	int x=4,y=6,z=3;
	LinkedList list = createList();
	LinkedList* list_ptr;

	Node* node1 = create_node(&x);
	Node* node2 = create_node(&y);
	Node* node3 = create_node(&z);

	add_to_list(&list, node1);
	add_to_list(&list, node2);
	add_to_list(&list, node3);

	list_ptr = filter(list,isLessThan);
 	assertEqual((*(int*)(list_ptr->head)->data),4);
 	assertEqual((list_ptr->count),2);
 	assertEqual((*(int*)(list_ptr->tail)->data),3);
 	
};

int find_small_charecter(void* data){
	if((*(char*)data)>=97) 
		return 1 ;
	return 0;
}

void test_for_filter_gives_all_the_small_letter_in_the_list(){
	char a='F',b='e',c='T',d='z',e='Y',f='f',g='s';
	LinkedList list = createList();
	LinkedList* list_ptr;

	Node* node1 = create_node(&a);
	Node* node2 = create_node(&b);
	Node* node3 = create_node(&c);
	Node* node4 = create_node(&d);
	Node* node5 = create_node(&e);
	Node* node6 = create_node(&f);
	Node* node7 = create_node(&g);


	add_to_list(&list, node1);
	add_to_list(&list, node2);
	add_to_list(&list, node3);
	add_to_list(&list, node4);
	add_to_list(&list, node5);
	add_to_list(&list, node6);
	add_to_list(&list, node7);

	list_ptr = filter(list,find_small_charecter);
 	assertEqual((*(char*)(list_ptr->head)->data),'e');
 	assertEqual((list_ptr->count),4);
 	assertEqual((*(char*)(list_ptr->tail)->data),'s');
 	
};
