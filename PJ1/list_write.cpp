//Hailey Warner
//ID: 1218372181

#include "list_write.h"
#include <stdlib.h>
#include <cstdio>

void listInsert(TAG_LIST *list, double given_key){
    NODE *new_node = (NODE *) calloc(1, sizeof(NODE));	
    // set the key field of new node to the value of <KEY>
    new_node->key = given_key;  

    // insert new node at head of list 
    if(list->head==NULL){	 		// no elements
        list->head = new_node;
        list->tail = new_node;
        new_node->next = NULL;
    }	
    else{					// 1+ elements
        new_node->next = list->head;
        list->head = new_node;	
    }
}

void listAppend(TAG_LIST *list, double given_key){
    NODE *new_node = (NODE *) calloc(1, sizeof(NODE));// allocate memory for a new node 	
    NODE *curr_node = (NODE *) calloc(1, sizeof(NODE));
    new_node->key  = given_key;  		          // set the key field of new node to the value of <KEY>
    new_node->next = NULL;
    curr_node = list->head;

    //append new node to tail of list
    if(curr_node==NULL){			// no elements
	list->head = new_node;
	list->tail = new_node;
	curr_node  = new_node;
    }
    else{					// 1+ elements
	while(curr_node->next!=NULL){
   	    curr_node = curr_node->next;
	}
	curr_node->next = new_node;
    }
}

void listDelete(TAG_LIST *list, double given_key){
	
	NODE* node = list->head;
	NODE* prev_node = NULL;

	if(node==NULL)				// 0 elements
		return;	

	if(list->head->key==given_key){		// head = deleted element
		if (list->head->next==NULL){	// 1 element
			list->head = NULL;
			return;
			}
		list->head = list->head->next;  // 2+ elements
		return;
		}
		

	while(node!=NULL){
		if(node->key == given_key){
			// remove current node and link previous node to next node
			prev_node->next = node->next;
			}

		prev_node = node;
		node = node->next;
		}
	}


