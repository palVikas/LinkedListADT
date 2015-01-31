#include <stdio.h>
#include "linkedList.h"
#include <stdlib.h>

LinkedList createList(void){
	LinkedList list;
	list.head = NULL;
	list.tail = NULL;
	list.count =0;
	return list;
};

Node* create_node(void *data){
	Node* node = malloc(sizeof(Node));
	node->data = data;
	(*node).next = NULL;
	return node;
};


int add_to_list(LinkedList *LinkedList_ptr,Node *node) {
	if(LinkedList_ptr->head==NULL) {
		LinkedList_ptr->head=(node);
	}
	else
		(*(*LinkedList_ptr).tail).next = node;
	(*LinkedList_ptr).tail = node;
	(*LinkedList_ptr).count++;

	return LinkedList_ptr->count;
};

void *get_first_element(LinkedList list){
	return list.head;
};

void *get_last_element(LinkedList list){
	return list.tail;
};


void traverse(LinkedList list,  traverseFunc* travers){
	while(list.head != NULL){
		travers((*list.head).data);
		list.head = (*list.head).next;
	}
};


void * getElementAt(LinkedList list, int index ){
	int count = -1;
	if(list.head == NULL)
		return list.head;
	
	do {
			count++;
			if(count == index)
				return list.head->data;
			list.head = list.head->next;
		}
	while(list.head != NULL);

	return NULL;	

}


int indexOf(LinkedList list, void *data){
	int count=-1,index;

	while(list.head != NULL){
		count++;
		if(list.head->data == data){
			index = count;
			return index;
		}

		list.head = list.head->next;
	}
	return -1;
};



void * deleteElementAt(LinkedList * list_ptr, int index){
	int i;
	Node * temp1 = list_ptr->head;
	Node * temp2 = temp1->next;
	if(index<0){
		printf("Node does not exists\n");
		return NULL;
	}
	if(index == 0){
		list_ptr->head = temp1->next;
		list_ptr->count--;
		return temp1->data;
	}

	for(i=0;i<index-1;i++){
		temp2=temp2->next;
		temp1 = temp1->next;
	}

	temp1->next = temp2->next;
	list_ptr->count--;
	return temp2->data;
	
};

int asArray(LinkedList list, void **array){
	int count = 0;
	while(list.head != NULL){
		array[count] = list.head->data;
		count++;
		list.head = list.head->next;
	}
	return count;
}

LinkedList * filter(LinkedList list, filterFunc* filterr){
	LinkedList* list_ptr = calloc(1,sizeof(LinkedList));

	while(list.head != NULL){

		if(filterr(list.head->data)==1) {
			add_to_list(list_ptr,list.head);
		}

		list.head = list.head->next; 
	}
	return list_ptr;
};
