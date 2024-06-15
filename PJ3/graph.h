// Hailey Warner
// 1218372181

#ifndef _graph_h
#define _graph_h 1
#include "data_structures.h"
#include "heap.h"
#include <stack>

void PrintADJ(LIST**, int);
void listInsert(LIST*, int, int, double);
void listAppend(LIST*, int, int, double);
void SinglePair(int, int, int, VERTEX**, LIST**, HEAP*);
void SingleSource(int, int, VERTEX**, LIST**, HEAP*);
void PrintLength(int, int, VERTEX**);
void PrintPath(int, int, VERTEX**);
void InitSource(int, int, VERTEX**);
void Relax(int, int, double, VERTEX**);

#endif
