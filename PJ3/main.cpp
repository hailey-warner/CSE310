//Hailey Warner
//ID: 1218372181

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <typeinfo>
#include <iostream>
#include "util.h"
#include "data_structures.h"
#include "heap.h"
#include "graph.h"

int HEAPIFY_CALLS = 0;
int LAST_T = -1;

int main(int argc, char **argv){
    FILE *fp;
    HEAP *Q;
    //int* S;
    int returnV, param1, param2;
    int i, n, m, u, v;
    double w;
    char Word[100];

    // check correct usage
    if (argc < 4){
        fprintf(stderr, "Usage: %s <InputFile> <GraphType> <Flag>\n", argv[0]);
        exit(0);
    }

    if (strcmp(argv[3],"1")!=0 and strcmp(argv[3],"2")!=0){ 
	fprintf(stderr, "Invalid Flag (must be 1 or 2)\n");
    	exit(0);
    }

    // 6.1 Read in the Graph and Build the Adjacency Lists
    fp = fopen(argv[1], "r");
    if(!fp){
	fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
	exit(0);
    }

    // read first line to get n, m
    fscanf(fp, "%d %d", &n, &m);

    VERTEX** V = new VERTEX*[n];
    LIST** ADJ = new LIST*[n];
    
    for(i = 1; i <= n; i++){
	LIST *new_list = new LIST;
	ADJ[i-1] = new_list;
	VERTEX *new_vertex = new VERTEX;
	V[i-1] = new_vertex;
	V[i-1]->position = i;
    }

    // read remaining lines to get (u,v)
    while (fscanf(fp, "%d %d %d %lf ", &i, &u, &v, &w) != EOF){
	
	//if (strcmp(argv[2],"D")==0 and strcmp(argv[3],"1")==0){ 	
	if (strcmp(argv[2],"DirectedGraph")==0 and strcmp(argv[3],"1")==0){ 	
	    listInsert(ADJ[u-1], u, v, w);
	}
	//if (strcmp(argv[2],"D")==0 and strcmp(argv[3],"2")==0){
	if (strcmp(argv[2],"DirectedGraph")==0 and strcmp(argv[3],"2")==0){
	    listAppend(ADJ[u-1], u, v, w);
	}
	//if (strcmp(argv[2],"U")==0 and strcmp(argv[3],"1")==0){
	if (strcmp(argv[2],"UndirectedGraph")==0 and strcmp(argv[3],"1")==0){
	    listInsert(ADJ[u-1], u, v, w);
	    listInsert(ADJ[v-1], v, u, w);
	}
	//if (strcmp(argv[2],"U")==0 and strcmp(argv[3],"2")==0){
	if (strcmp(argv[2],"UndirectedGraph")==0 and strcmp(argv[3],"2")==0){
	    listAppend(ADJ[u-1], u, v, w);
	    listAppend(ADJ[v-1], v, u, w);
	}
    }
    fclose(fp);
    
    // 6.2 Initialize Priority Queue (min-heap) and the Stack

    Q = Init(n); // queue

    // 6.3 Loop over the Instructions

    while (1){
        returnV = nextInstruction(Word, &param1, &param2);
	// check valid instruction
        if (returnV == 0){
            fprintf(stderr, "Warning: Invalid instruction\n");
            continue;
        }

	// STOP
        if (strcmp(Word, "Stop")==0){
	    free(Q);
	    delete []V;
	    delete []ADJ;
	    return 0;
        }

	// PRINT ADJ
        if (strcmp(Word, "PrintADJ")==0){
       	    PrintADJ(ADJ, n);
       	}

	// SINGLE PAIR
        if (strcmp(Word, "SinglePair")==0){
	    SinglePair(param1, param2, n, V, ADJ, Q); 
        }

	// SINGLE SOURCE
        if (strcmp(Word, "SingleSource")==0){
	    SingleSource(param1, n, V, ADJ, Q);
	}

	// PRINT LENGTH
        if (strcmp(Word, "PrintLength")==0){
	    PrintLength(param1, param2, V);
	}

	// PRINT PATH
        if (strcmp(Word, "PrintPath")==0){
	    PrintPath(param1, param2, V);
        }

    }
    return 1;
}

