// Hailey Warner
// ID: 1218372181
 
#include <cfloat>
#include <cstddef>
#include <stdio.h>
#include <cstdlib>
#include "graph.h"
#include "heap.h"
#include "data_structures.h"

extern int LAST_T;

void PrintADJ(LIST** ADJ, int n){ 
    for(int i = 1; i <= n; i++){
        NODE* node = ADJ[i-1]->head;
	fprintf(stdout, "ADJ[%d]:-->", i);
        while(node!=NULL){
	    if(node->next!=NULL){
     	    	fprintf(stdout, "[%d %d: %.2f]-->", node->u, node->v, node->w);
	        node = node->next;
	    }
	    else{
		fprintf(stdout, "[%d %d: %.2f]\n", node->u, node->v, node->w);
		free(node);
		break;	
	    }
	}
    }
}	

void listInsert(LIST *list, int u, int v, double w){
    NODE* new_node = new NODE;
    // set the key field of new node to the value of <KEY>
    new_node->u = u;
    new_node->v = v;
    new_node->w = w;

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
    //fprintf(stdout, "%d %d %lf \n", u, v, w);
    //fprintf(stdout, "list: %p \n", list);
    //fprintf(stdout, "head: %p \n", list->head);
    //fprintf(stdout, "head->next: %p \n", list->head->next);
    //fprintf(stdout, "tail: %p \n", list->tail);
    //fprintf(stdout, "new_node: %p \n", new_node);
    //fprintf(stdout, "new_node->next: %p \n", new_node->next);
}

void listAppend(LIST *list, int u, int v, double w){
    NODE* new_node  = new NODE;
    NODE* curr_node = new NODE;
    // set the key field of new node to the value of <KEY>
    new_node->u = u;
    new_node->v = v;
    new_node->w  = w;   	        
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

/////////////////////////////////////////////////////

void InitSource(int s, int n, VERTEX** V){
    for (int i = 1; i <= n; i++){
        V[i-1]->key = DBL_MAX;
	V[i-1]->pi  = 0;
    }
    V[s-1]->key = 0;
}

void Relax(int u_pos, double u_key, int v, double w, VERTEX** V){
    //fprintf(stdout, "RELAX\n");
    if (V[v-1]->key > u_key + w){
	//fprintf(stdout, "relaxed\n");
    	V[v-1]->key = u_key + w;
	V[v-1]->pi  = u_pos;
    }
}

void SingleSource(int s, int n, VERTEX** V, LIST** ADJ, HEAP* Q){
    LAST_T = 0;
    InitSource(s, n, V);
    // Q = empty 
    for (int i = 1; i <= n; i++)
        Insert(Q, V, V[i-1]->key, i);
    
    //Print(Q);
    /*
    for (int i = 0; i < Q->size; i++)
    	fprintf(stdout, "heap->A[%d]->key: %lf \n", i, Q->A[i]->key); 
    for (int i = 0; i < Q->size; i++)
    	fprintf(stdout, "heap->A[%d]->pos: %d \n", i, Q->A[i]->position); 
    */
    //for (int i = 1; i <= n; i++)
    //	fprintf(stdout, "V[%d]->key: %lf \n", i, V[i-1]->key); 
    
    while (Q->size!=0){
        int u_pos = ExtractMin(Q); // position in V of vertex u
	double u_key = V[u_pos-1]->key;

	//fprintf(stdout, "u_pos: %d \n", u_pos);
	NODE* node = ADJ[u_pos-1]->head;
	while (node!=NULL and Q->size!=0){ // for each vertex v in ADJ[u]
	    //fprintf(stdout, "node->u: %d \nnode->v: %d \n", node->u, node->v);
  	    double past_key = V[(node->v)-1]->key;
	    Relax(u_pos, u_key, node->v, node->w, V);
	    //for (int i = 0; i < Q->size; i++)
    	    //  fprintf(stdout, "Q->A[%d]->position: %d\n", i, Q->A[i]->position);

	    if(V[(node->v)-1]->key < past_key){
		//fprintf(stdout, "decreased key\n");
		DecreaseKey(Q, V, node->v, V[(node->v)-1]->key, V[(node->v)-1]->position);
	    }
	    node = node->next;
	    //fprintf(stdout, "next node\n");
	    /*			
   	    for (int i = 0; i < Q->size; i++)
    		fprintf(stdout, "Q->A[%d]->position: %d\n", i, Q->A[i]->position);
       	    for (int i = 0; i < Q->size; i++)
    	 	fprintf(stdout, "Q->A[%d]->index: %d\n", i, Q->A[i]->index);
            for (int i = 0; i < Q->size; i++)
    		fprintf(stdout, "Q->A[%d]->key: %lf\n", i, Q->A[i]->key);
	    */
	}
    }
    //for (int i = 1; i <= 10; i++)
    //	fprintf(stdout, "V[%d]->key: %lf \n", i, V[i-1]->key); 
}

void SinglePair(int s, int t, int n, VERTEX** V, LIST** ADJ, HEAP* Q){
    LAST_T = t;

    InitSource(s, n, V);
    // Q = empty 
    for (int i = 1; i <= n; i++)
        Insert(Q, V, V[i-1]->key, i);

    //Print(Q);
    /*
    for (int i = 0; i < Q->size; i++)
    	fprintf(stdout, "heap->A[%d]->key: %lf \n", i, Q->A[i]->key); 
    for (int i = 0; i < Q->size; i++)
    	fprintf(stdout, "heap->A[%d]->pos: %d \n", i, Q->A[i]->position); 
    */
    //for (int i = 1; i <= n; i++)
    //	fprintf(stdout, "V[%d]->key: %lf \n", i, V[i-1]->key); 
    while (Q->size!=0){
        int u_pos = ExtractMin(Q); // position in V of vertex u
	double u_key = V[u_pos-1]->key;

	if (u_pos == t)
	    return;

	NODE* node = ADJ[u_pos-1]->head;
	while (node!=NULL and Q->size!=0){ // for each vertex v in ADJ[u]
	    //fprintf(stdout, "node->u: %d \nnode->v: %d \n", node->u, node->v);
  	    double past_key = V[(node->v)-1]->key;
	    Relax(u_pos, u_key, node->v, node->w, V);
	    //for (int i = 0; i < Q->size; i++)
    	    //  fprintf(stdout, "Q->A[%d]->position: %d\n", i, Q->A[i]->position);

	    if(V[(node->v)-1]->key < past_key){
		//fprintf(stdout, "decreased key\n");
		DecreaseKey(Q, V, node->v, V[(node->v)-1]->key, V[(node->v)-1]->position);
	    }
	    node = node->next;
	    //fprintf(stdout, "next node\n");
	    /*			
   	    for (int i = 0; i < Q->size; i++)
    		fprintf(stdout, "Q->A[%d]->position: %d\n", i, Q->A[i]->position);
       	    for (int i = 0; i < Q->size; i++)
    	 	fprintf(stdout, "Q->A[%d]->index: %d\n", i, Q->A[i]->index);
            for (int i = 0; i < Q->size; i++)
    		fprintf(stdout, "Q->A[%d]->key: %lf\n", i, Q->A[i]->key);
	    */
	}
    }
    //for (int i = 1; i <= n; i++)
    //	fprintf(stdout, "V[%d]->key: %lf \n", i, V[i-1]->key); 
}



void PrintLength(int s, int t, VERTEX** V){
    if(V[s-1]->key != 0){
	fprintf(stderr, "Error: Invalid instruction.\n");
	return;
    }
    if(LAST_T != t and LAST_T != 0){
	fprintf(stderr, "Error: Invalid instruction.\n");
	return;
    }

    if (V[t-1]->key < DBL_MAX)
	fprintf(stdout, "The length of the shortest path from %d to %d is: %8.2lf\n", s, t, V[t-1]->key);  
    else
	fprintf(stdout, "There is no path from %d to %d.\n", s, t);
}

void PrintPath(int s, int t, VERTEX** V){
    if(V[s-1]->key != 0){
	fprintf(stderr, "Error: Invalid instruction.\n");
	return;
    }
    if(LAST_T != t and LAST_T != 0){
	fprintf(stderr, "Error: Invalid instruction.\n");
	return;
    }

    if(V[t-1]->key < DBL_MAX){	    
	fprintf(stdout, "The shortest path from %d to %d is:\n", s, t);  

        std::stack<int> S;    // pi stack
	std::stack<double> K; // key stack
        int x = t;
    
        while(x != s){
            K.push(V[x-1]->key);
            S.push(x);
            x = V[x-1]->pi;
        }
        K.push(V[s-1]->key);
        S.push(s);

        while(!S.empty()){
            int new_pi = S.top();
	    S.pop();
	    double new_key = K.top();
	    K.pop();
	    if (new_pi == t)
	        fprintf(stdout, "[%d:%8.2lf].\n", new_pi, new_key); 
            else
                fprintf(stdout, "[%d:%8.2lf]-->", new_pi, new_key); 
        }	
    }
    else{
	fprintf(stdout, "There is no path from %d to %d.\n", s, t);
    }
}
