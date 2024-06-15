//Hailey Warner
//ID: 1218372181

#ifndef _data_structures_h
#define _data_structures_h 1

extern int HEAPIFY_CALLS;

typedef struct TAG_ELEMENT {
    double key;
    // other fields as you see fit
}ELEMENT;

typedef struct TAG_HEAP {
    int capacity; /* capacity of the heap */
    int size; /* current size of the heap */
    ELEMENT** A; /* array of pointers to ELEMENT */
    // other fields as you see fit
}HEAP;

#endif
