//Hailey Warner
//ID: 1218372181

#include <stdio.h>
#include <string.h>
#include "util.h"

int nextInstruction(char *Word, int *param1, int *param2)
{
    int  returnV;

    fscanf(stdin, "%s", Word);

    if (strcmp(Word, "Stop")==0) return 1;
    if (strcmp(Word, "PrintADJ")==0) return 1;
    if (strcmp(Word, "Print")==0) return 1;
    if (strcmp(Word, "Write")==0) return 1;
    if (strcmp(Word, "Read")==0) return 1;
    if (strcmp(Word, "ExtractMin")==0) return 1;
    
    if (strcmp(Word, "SinglePair")==0){
	returnV = fscanf(stdin, "%d %d", param1, param2);
	if (returnV == 2){
	    return 1;
	}else{
	   return 0;
	}
    }

    if (strcmp(Word, "SingleSource")==0){
	returnV = fscanf(stdin, "%d", param1);
	if (returnV == 1){
	    return 1;
	}else{
	   return 0;
	}
    }

    if (strcmp(Word, "PrintLength")==0){
	returnV = fscanf(stdin, "%d %d", param1, param2);
	if (returnV == 2){
	    return 1;
	}else{
	   return 0;
	}
    }

    if (strcmp(Word, "PrintPath")==0){
	returnV = fscanf(stdin, "%d %d", param1, param2);
	if (returnV == 2){
	    return 1;
	}else{
	   return 0;
	}
    }

    if (strcmp(Word, "Init")==0){
        returnV = fscanf(stdin, "%d", param1);
        if (returnV == 1){
            return 1;
        }else{
            return 0;
        }
    }

    if (strcmp(Word, "Insert")==0){
        returnV = fscanf(stdin, "%d", param2);
        if (returnV == 1){
            return 1;
        }else{
            return 0;
        }
    }

    if (strcmp(Word, "DecreaseKey")==0){
        returnV = fscanf(stdin, "%d %d", param1, param2);
        if (returnV == 2){
            return 1;
        }else{
            return 0;
        }
    }

    return 0;
}
