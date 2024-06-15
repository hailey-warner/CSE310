//Hailey Warner
//ID: 1218372181

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "data_structures.h"
#include "heap.h"

int HEAPIFY_CALLS = 0;

int main(int argc, char **argv){
    FILE *fp;
    HEAP *heap;
    double min, param2;
    int returnV, param1;
    char Word[100];

    // check correct usage
    if (argc < 4){
        fprintf(stderr, "Usage: %s <ifile> <ofile> <tag>\n", argv[0]);
        exit(0);
    }
    if (strcmp(argv[3],"0")==1 and strcmp(argv[3],"1")==1){ 
	fprintf(stderr, "Invalid Tag (must be 0 or 1)\n");
    	exit(0);
    }
    
    while (1){
        returnV = nextInstruction(Word, &param1, &param2);
	// check valid instruction
        if (returnV == 0){
            fprintf(stderr, "Warning: Invalid instruction\n");
            continue;
        }

	// STOP
        if (strcmp(Word, "Stop")==0){
	    return 0;
        }

	// INIT <CAP>
	if (strcmp(Word, "Init")==0){
	    heap = Init(param1);
	    continue;
	}

	// PRINT
        if (strcmp(Word, "Print")==0){
    	    if(!heap){
	        fprintf(stdout, "0\n");
		fprintf(stderr, "Error: heap is NULL\n");
		continue;
	    }
            Print(heap);
            continue;
        }

	// WRITE
        if (strcmp(Word, "Write")==0){
            fp = fopen(argv[2], "w");
            
            fprintf(fp, "%d\n", heap->size);

	    if(!heap){
		fprintf(stderr, "Error: heap is NULL\n");
		continue;
	    }
	    if (!fp){
                fprintf(stderr, "Error: cannot open file %s\n", argv[2]);
                continue;
            }

	    for(int i=0; i<heap->size; i++){
                fprintf(fp, "%lf\n", heap->A[i]->key);
            }
            fclose(fp);
            continue;
        }

	// READ
        if (strcmp(Word, "Read")==0){
	    fp = fopen(argv[1], "r");
            if(!heap){
		fprintf(stderr, "Error: heap is NULL\n");
	    	continue;
	    }
	    if(!fp){
	        fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
	        continue;
  	    }

	    int n;
	    fscanf(fp, "%d", &n);
	    if (heap->capacity < n){
	        fprintf(stderr, "Error: heap is too small\n");
	        fclose(fp);
	        continue;
	    }   

	    heap->size = n;
	    
            for (int j=0; j<n; j++){
	        ELEMENT* elementj = (ELEMENT*) calloc(1, sizeof(ELEMENT));
	        double keyj;
	        fscanf(fp, "%lf", &keyj);
	        heap->A[j] = elementj;
	        heap->A[j]->key = keyj;
	    }
	    BuildMinHeap(heap);
            //check tag
            if (strcmp(argv[3], "1")==0)
	        fprintf(stdout, "Number of Heapify calls: %d\n", HEAPIFY_CALLS);
	    fclose(fp);
	    continue;
        }

	// EXTRACTMIN
        if (strcmp(Word, "ExtractMin")==0){
	    if(!heap){
		fprintf(stderr, "Error: heap is NULL\n");
   	        continue;
    	    }
	    if(heap->size==0){
		fprintf(stderr, "Error: heap is empty\n");
                continue;
	    }

            min = ExtractMin(heap);
            fprintf(stdout, "ExtractMin: %lf\n", min);
	    //check tag
            if (strcmp(argv[3], "1")==0)
	        fprintf(stdout, "Number of Heapify calls: %d\n", HEAPIFY_CALLS);
            continue;
        }

	// INSERT <KEY>
	if (strcmp(Word, "Insert")==0){
    	    if(!heap){
		fprintf(stderr, "Error: heap is NULL\n");
        	continue;
	    }
    	    if(heap->size >= heap->capacity){
		fprintf(stderr, "Error: heap is full\n");
		continue;
	    }  
	    Insert(heap, param2);
	    continue;
	}

	// DECREASEKEY <INDEX> <KEY>
        if (strcmp(Word, "DecreaseKey")==0){
	    if(!heap){
	        fprintf(stderr, "Error: heap is NULL\n");
	        continue;
	    }
	    if(!heap->A[0]){
	        fprintf(stderr, "Error: heap is empty\n");
	        continue;
  	    }
	    if ((param1-1 > heap->size) or (param2 > heap->A[param1-1]->key)){
	        fprintf(stderr, "Error: invalid call to DecreaseKey\n");
	        continue;
	    }
	    
            DecreaseKey(heap, param1-1, param2);
	    continue;
        }
    } 
    return 1;
}

