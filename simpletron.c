#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

#define Bool short
#define True 1
#define False 0


/* Input/Output */
#define READ   10
#define WRITE  11

/* Loading/Storing */
#define LOAD  20
#define STORE 21

/* Arithmetical */
#define ADD      30
#define SUBTRACT 31
#define DIVIDE   32
#define MULTIPLY 33

/* Reference and control */
#define BRANCH     40
#define BRANCHNEG  41
#define BRANCHZERO 42
#define HALT       43







Bool readFile(char* filename){
    FILE* f;
    ssize_t read;
    size_t len;
    char* linestr;
    f = fopen(filename,"r");
    
    if(f == NULL) return False;
    
    while( (read = getline(&linestr, &len, f)) != -1){
        
        int op = (int) (linestr[1] - 48)*10 + (linestr[2] - 48);
        printf("entrada: %d\n",op);
    }
    
    fclose(f);
    if(linestr) free(linestr);
     return True;
}

int main(int argv, char* argc) {
    if(readFile("sum2num.ass") == True){
        printf("Success!\n");
    }else{
        printf("Error.\n");
    }
    return 0;
}
