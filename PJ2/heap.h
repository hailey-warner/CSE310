//Hailey Warner
//ID: 1218372181

#ifndef _heap_h
#define _heap_h 1
#include "data_structures.h"

int    Parent(HEAP*, int);
int    Left(HEAP*, int);
int    Right(HEAP*, int);
void   MinHeapify(HEAP*, int);
void   BuildMinHeap(HEAP*);
HEAP*  Init(int);
void   Print(HEAP*);
void   Write(HEAP*);
void   Insert(HEAP*, double);
double ExtractMin(HEAP*);
void   DecreaseKey(HEAP*, int, double);

#endif
