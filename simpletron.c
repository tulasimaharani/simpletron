#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

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




char* operation(char* op){
    char* opc;
    int pos;
    
    opc = (char *) malloc( sizeof(char) );
    opc[0] = '\0';
    
    if(op[0] != '\0' || op[0] != ' '){
        pos = 0;
        do{
            opc = (char *) malloc( (sizeof(char) * (pos+1)) );
            opc[pos] = op[pos];
            ++pos;
        }while(op[pos] != ' ' || op[pos] != '\0');
        op[pos] = '\0';
    }
    
    return opc;
}


Bool readFile(char* filename){
    FILE* f;
    ssize_t read;
    size_t len;
    char* linestr;
    f = fopen(filename,"r");
    
    if(f == NULL) return False;
    
    while( (read = getline(&linestr, &len, f)) != -1){
        printf("Linha: %s\n",operation(linestr));
    }
    
    fclose(f);
    if(linestr) free(linestr);
     return True;
}

int main() {
    readFile("input.ass");
    return 0;
}
