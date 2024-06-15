//Hailey Warner
//ID: 1218372181

#include <cstdio>
#include <stdio.h>
#include <cfloat>
#include <tgmath.h>
#include "heap.h"
#include "data_structures.h"

int Parent(HEAP* heap, int i){
    return floor((i-1)/2);
}	
int Left(HEAP* heap, int i){
    return 2*i+1;
}
int Right(HEAP* heap, int i){
    return 2*i+2;
}
void MinHeapify(HEAP* heap, int i){
    HEAPIFY_CALLS++;
    int smallest;
    int l = Left(heap, i);
    int r = Right(heap, i);
    if (l < heap->size and heap->A[l]->key < heap->A[i]->key)
        smallest = l;
    else smallest = i;
    if (r < heap->size and heap->A[r]->key < heap->A[smallest]->key)
        smallest = r;
    if (smallest != i){
	
	double temp_pos = heap->A[i]->position;
	heap->A[i]->position = heap->A[smallest]->position;
	heap->A[smallest]->position = temp_pos;
	
	double temp = heap->A[i]->key;
        heap->A[i]->key = heap->A[smallest]->key;
        heap->A[smallest]->key = temp;
	
        MinHeapify(heap, smallest);
    }
}
void BuildMinHeap(HEAP* heap){
    HEAPIFY_CALLS = -1;
    for (int i = floor((heap->size-1)/2); i >= 0; i--)
	    MinHeapify(heap, i);
}

//////////////////////////////////////////////////////////

HEAP* Init(int cap){
    HEAP* heap = (HEAP*) calloc(1, sizeof(HEAP));
    if (!heap){
        fprintf(stderr, "Error: calloc failed\n");
        return NULL;
    }
    heap->A = (ELEMENT**) calloc(cap, sizeof(ELEMENT*));
    if (!heap->A){
	fprintf(stderr, "Error: calloc failed\n");
	free(heap);
    }
    heap->capacity = cap;
    heap->size = 0;
    return heap;
}



void Print(HEAP* heap){
    fprintf(stdout, "%d\n", heap->size);
    for(int i=0; i<heap->size; i++)
        fprintf(stdout, "%lf\n", heap->A[i]->key);
}



void Insert(HEAP* heap, VERTEX** V, double new_key, int new_pos){
    heap->size++;
    ELEMENT* new_element = (ELEMENT*) calloc(1, sizeof(ELEMENT));
    heap->A[heap->size-1] = new_element;
    heap->A[heap->size-1]->key = DBL_MAX;
    heap->A[heap->size-1]->position = heap->size;
    heap->A[heap->size-1]->index = heap->size-1;
    DecreaseKey(heap, V, heap->size-1, new_key, new_pos);
}



int ExtractMin(HEAP* heap){
    HEAPIFY_CALLS = 0;
    int min_pos = heap->A[0]->position;
    //fprintf(stdout, "min_pos: %d\n", min_pos);
    /*
    for (int i = 0; i < heap->size; i++)
    	fprintf(stdout, "heap->A[%d]->index: %d\n", i, heap->A[i]->index);
    for (int i = 0; i < heap->size; i++)
    	fprintf(stdout, "heap->A[%d]->key: %lf\n", i, heap->A[i]->key);
    */
    heap->A[0]->key = heap->A[heap->size-1]->key;
    heap->A[0]->position = heap->A[heap->size-1]->position;
    heap->size--;
    MinHeapify(heap, 0);
    /*
    fprintf(stdout, "EXTRACTMIN\n");
    for (int i = 0; i < heap->size; i++)
    	fprintf(stdout, "heap->A[%d]->position: %d\n", i, heap->A[i]->position);
    for (int i = 0; i < heap->size; i++)
    	fprintf(stdout, "heap->A[%d]->key: %lf\n", i, heap->A[i]->key);
    */
    return min_pos;
}



void DecreaseKey(HEAP* heap, VERTEX** V, int v, double new_key, int new_pos){
    int index;
    //fprintf(stdout, "heap->size: %d\n", heap->size);
    for (int i = 0; i < heap->size; i++){
    	if (heap->A[i]->position == v)
	    index = i;
	else
	    index = heap->size-1;
    }
    //fprintf(stdout,"index: %d\n", index);
    /*
    fprintf(stdout, "BEFORE DECREASEKEY\n");
    for (int i = 0; i < heap->size; i++)
    	fprintf(stdout, "heap->A[%d]->position: %d\n", i, heap->A[i]->position);
    for (int i = 0; i < heap->size; i++)
    	fprintf(stdout, "heap->A[%d]->key: %lf\n", i, heap->A[i]->key);
    */
    heap->A[index]->key = new_key;
    heap->A[index]->position = new_pos;
    /*
    fprintf(stdout, "MID DECREASEKEY\n");
    for (int i = 0; i < heap->size; i++)
    	fprintf(stdout, "heap->A[%d]->position: %d\n", i, heap->A[i]->position);
    for (int i = 0; i < heap->size; i++)
    	fprintf(stdout, "heap->A[%d]->key: %lf\n", i, heap->A[i]->key);
    */
    while (index > 0 and heap->A[Parent(heap,index)]->key > heap->A[index]->key){

   	int pos_swap = heap->A[index]->position;
	heap->A[index]->position = heap->A[Parent(heap,index)]->position;
	heap->A[Parent(heap,index)]->position = pos_swap;
       
       	double swap = heap->A[index]->key;
        heap->A[index]->key = heap->A[Parent(heap,index)]->key;
	heap->A[Parent(heap,index)]->key = swap;
        
	index = Parent(heap,index);
    }
    /*
    fprintf(stdout, "AFTER DECREASEKEY\n");
    for (int i = 0; i < heap->size; i++)
    	fprintf(stdout, "heap->A[%d]->position: %d\n", i, heap->A[i]->position);
    for (int i = 0; i < heap->size; i++)
    	fprintf(stdout, "heap->A[%d]->key: %lf\n", i, heap->A[i]->key);
    */
}

