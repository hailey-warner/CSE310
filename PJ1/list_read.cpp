//Hailey Warner
//ID: 1218372181

#include "list_read.h"
#include <cstddef>
#include <stdio.h>
#include <iostream>

double listMax(LIST *list){
	
	if (list->head == NULL)
		return 0;

	double max_key = list->head->key;
	NODE* node = list->head;

	// while list contains at least one node
	while(node!=NULL){
		if(max_key < node->key){
			max_key = node->key;
		}
		node = node->next;
	}
	return max_key;
}


void listPrint(LIST *list){		//DONE
	NODE* node = list->head;
	while(node!=NULL){
		printf("%lf\n", node->key);
		//std::cout << node->key << "%lf\n";
		node = node->next;
		}
	}	
