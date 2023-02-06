#include <stdlib.h>
#include <stdio.h>

#include <stdbool.h>

#include <string.h>

#include <math.h>

typedef struct{
    int integer;
    float real;
    char* id;
 
    int type;
} atributs;


void yyerror(char*);
void file_log(FILE*, char*);
void file_log_error(FILE*, char*);

void next_line();
bool is_null(atributs);
int num_types(atributs, atributs);
atributs eval(atributs, char, atributs, char*);
int start_iteration(atributs*);
int end_iteration(atributs);
void show(atributs);
void halt();
