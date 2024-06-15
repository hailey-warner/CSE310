//Hailey Warner
//ID: 1218372181

#include <cstdio>
#include <stdio.h>
#include <float.h>
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
    //fprintf(stdout, "l: %d\n", l);
    //fprintf(stdout, "r: %d\n", r);
    //fprintf(stdout, "i: %d\n", i);
    //fprintf(stdout, "heapsize: %d\n", heap->size);
    //fprintf(stdout, "A[l]: %lf\n", heap->A[l]->key);
    //fprintf(stdout, "A[i]: %lf\n", heap->A[i]->key);
    //fprintf(stdout, "A[r]: %lf\n", heap->A[r]->key);
    if (l < heap->size and heap->A[l]->key < heap->A[i]->key)
        smallest = l;
    else smallest = i;
    if (r < heap->size and heap->A[r]->key < heap->A[smallest]->key)
        smallest = r;
    if (smallest != i){
	double temp = heap->A[i]->key;
        heap->A[i]->key = heap->A[smallest]->key;
        heap->A[smallest]->key = temp;
        MinHeapify(heap, smallest);
    }
}
void BuildMinHeap(HEAP* heap){
    HEAPIFY_CALLS = -1;
    //fprintf(stdout,"heap->size: %d\n", heap->size); // length(A)... heap->capacity? std::end(heap->A) - std::begin(heap->A);
    for (int i = floor((heap->size-1)/2); i >= 0; i--)
	    MinHeapify(heap, i);
}

//////////////////////////////////////////////////////////

HEAP* Init(int cap){
    //fprintf(stdout, "intake cap: %d\n", cap);
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

void Insert(HEAP* heap, double new_key){
    heap->size++;
    ELEMENT* new_element = (ELEMENT*) calloc(1, sizeof(ELEMENT));
    heap->A[heap->size-1] = new_element;
    heap->A[heap->size-1]->key = 1000000; // -inf
    DecreaseKey(heap, heap->size-1, new_key);
}



double ExtractMin(HEAP* heap){
    HEAPIFY_CALLS = 0;
    double min = heap->A[0]->key;
    heap->A[0]->key = heap->A[heap->size-1]->key;
    heap->size--;
    MinHeapify(heap, 0);
    return min;
}



void DecreaseKey(HEAP* heap, int index, double new_key){
    heap->A[index]->key = new_key;
    while (index > 0 and heap->A[Parent(heap,index)]->key > heap->A[index]->key){
        double swap = heap->A[index]->key;
        heap->A[index]->key = heap->A[Parent(heap,index)]->key;
        heap->A[Parent(heap,index)]->key = swap;
        index = Parent(heap,index);
    }
}

