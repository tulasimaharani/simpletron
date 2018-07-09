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

/*Memory size*/
#define MEMORY 100

int memory[MEMORY];



int accumulator = 0;
int instructionCounter = 0;
int operationCode = 0;
int operand = 0;
Bool processing = False;  

void simpletron(){
    load();
    interpret();
    dump();
}

void read(){
    
}

void write(){
    
}

void load(){
    accumulator = memory[operand];
    instructionCounter++;
}

void store(){
    memory[operand] = accumulator;
    instructionCounter++;
}

void add(){
    accumulator = accumulator + memory[operand];
    instructionCounter++;
}

void subtract(){
    accumulator = accumulator - memory[operand];
    instructionCounter++;
}

void divide(){
    accumulator = memory[operand] / accumulator; 
    instructionCounter++;
}

void multiply(){
    accumulator = accumulator * memory[operand];
    instructionCounter++;
}

void branch(){
    instructionCounter = operand;
}

void branchneg(){
    if (accumulator < 0){
        instructionCounter = operand;
    }else{
        instructionCounter++;
    }
}

void branchzero(){
    if(accumulator == 0){
        instructionCounter = operand;
    }else{
        instructionCounter++;
    }   
}

void halt(){
    processing = False;
}

void interpret(){
    processing = True;
    
    while(processing){
        int instructionRegister = memory[instructionCounter];
        
        operationCode = instructionCounter / 100;
        operand = instructionCounter % 100;
        
        switch(operationCode){
            case READ: read();
            break;
            case WRITE: write();
            break;
            case LOAD: load();
            break;
            case STORE: store();
            break;
            case ADD: add();
            break;
            case SUBTRACT: subtract();
            break;
            case DIVIDE: divide();
            break;
            case MULTIPLY: multiply();
            break;
            case BRANCH: branch();
            break;
            case BRANCHNEG: branchneg();
            break;
            case BRANCHZERO: branchzero();
            break;
            case HALT: halt();
            break;
            //default retornar erro no dump
            
        }    
    }
}

void dump(){
    //add file operations
    
    /*
     * REGISTERS:
     * Accumulator            accumulator   
     * InstructionCounter     instructionCounter   
     * InstructionRegister    instructionRegister    
     * OperationCode          operationCode  
     * Operand                operand 
    */
    
    //MEMORY:
    int i;
    for(i = 0; i < 10; i++){
        printf("     %d", &i);
    }
    for(i = 0; i < MEMORY; i += 10){
        printf("%d ", &i);
        
        int j;
        for(j = i; j < i + 10; j++){
            printf("&d ", memory[j]);
        }
        
    }
}

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
    
    simpletron();
    
    return 0;
}