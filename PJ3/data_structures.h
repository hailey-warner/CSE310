//Hailey Warner
//ID: 1218372181

#ifndef _data_structures_h
#define _data_structures_h 1

extern int HEAPIFY_CALLS;
extern int LAST_T;

typedef struct TAG_VERTEX{
	int index;    // in Q
	int pi;       //DOUBLE CHECK THIS DEF
	int position; // in V
	double key;   // distance
}VERTEX;
//typedef VERTEX *pVERTEX;
// synonyms to make heap.cpp compatible
typedef VERTEX ELEMENT;
//typedef ELEMENT *pELEMENT;

typedef struct TAG_NODE{
	int index;
	int u;
	int v;
	double w;
	TAG_NODE *next;
}NODE;
//typedef NODE *pNODE;

// linked list for adjacency lists
typedef struct TAG_LIST{
    	NODE *head;
	NODE *tail;
}LIST;

typedef struct TAG_HEAP{
	int capacity;
	int size;
	ELEMENT** A;
}HEAP;
//typedef HEAP *pHEAP

#endif
