%{
#define _GNU_SOURCE
#include <stdio.h>
#include <stdbool.h>

#include <math.h>

// symbol table
#include "../include/symtab/symtab.h"

// for logging
#include <time.h>


/* ------ Function and variable declaration ------ */
int yylex(void);
extern FILE* yyin;


/* ------ Global variables ------ */
FILE* fp; // pointer to the log file created each execution


atributs NULL_ARG = {-1, -1.0, "", -1};
atributs pi = {0, acos(-1.0), "pi", 1};

char* msg;
bool err; // error flag
bool print;

%}


%union{
	atributs attrs;
}


%token T_INT T_FLOAT T_IDEN 

%token ASSIG

%token SYM_OB SYM_CB

%token OP_ADD OP_SUB OP_MUL OP_DIV OP_MOD OP_POW

%token REPEAT DO DONE

%token CONST_PI

%token EOL CMD_EXIT

 
%type<attrs> T_INT T_FLOAT T_IDEN assignment factor unary term expr statement sentence open_sentence fixed_iteration 

%start start

%%

start: 
     | start sentence			
;

sentence_list: sentence_list sentence	
	     | sentence
;

sentence: statement EOL			{ err = false; if(print){ show($$); } }
	| EOL				{ err = false; }	
	| CMD_EXIT			{ halt(); exit(0); }

;

statement: expr				{ $$ = $1; }
	 | assignment			{ $$ = $1; }
	 | fixed_iteration		{ $$ = $1; }
;


assignment: T_IDEN ASSIG expr		{ 	if(!err){ // check if there were any errors in the calculations of the expr to be assigned
	  						atributs aux;
							char* name = $1.id;
							int found = sym_lookup(name, &aux); // 1. search identifier
						
							// check whether the identifier was found or not
							if(found == 0){
								// if types are compatible then change var value
								
								// for assignments, compatibility depends only if types
								// are the same for both the identifier found and the value to be saved
								if(aux.type == $3.type){
									aux = $3;
									sym_enter(name, &aux);
								}
								// if types aren't compatible then there's a semantic error
								else{
									yyerror("semantic error: identifier and expression type missmatch"); 
									file_log_error(fp, "semantic error: identifier and expression type missmatch");
									err = true;
								}
							}
							else{
								// if identifier doesn't exist then we have to create a new entry
								if(found == 2){
									aux = $3;
									aux.id = name;
									sym_add(name, &aux);
								}
							}

							// if the assignment succeeded log grammar production
							if(!err) {
								eval($1, ':', $3, msg);	

								file_log(fp, msg); // log grammar production
								
								$$ = aux;	
							}
						}
					}
;


expr: term				{ $$ = $1; }
	| expr OP_ADD term		{ if(!err){  $$ = eval($1, '+', $3, msg);  file_log(fp, msg);  print = false; } }
	| expr OP_SUB term		{ if(!err){  $$ = eval($1, '-', $3, msg);  file_log(fp, msg);  print = false; } }
;

term: unary				{ $$ = $1; }
    | term OP_MUL unary			{ if(!err){ $$ = eval($1, '*', $3, msg);  file_log(fp, msg);  print = false; } }
    | term OP_DIV unary			{ if(!err){
    						// control division by 0
						if($3.type == 0){
							if($3.integer == 0){
								yyerror("semantic error: cannot divide by 0"); 
								err = true;
							}
						}
						else{
							if($3.real == 0.0f){
								yyerror("semantic error: cannot divide by 0.0"); 
								err = true;
							}
						}
								
						// if there wasn't an attempt of dividing by 0 calculate the division depending on arguments' type
						if(!err){  $$ = eval($1, '/', $3, msg);  file_log(fp, msg);  print = false; }
	  				 }
					}
    | term OP_MOD unary			{ if(!err){  $$ = eval($1, '%', $3, msg);  file_log(fp, msg);  print = false; } }
;

unary: OP_SUB unary			{ if(!err){  $$ = eval(NULL_ARG, '-', $2, msg);  file_log(fp, msg);  print = false; } }
     | factor				{ $$ = $1; }
;

factor: T_IDEN				{	atributs aux = {-1, -1.0, "", -1};
      						int found = sym_lookup($1.id, &aux);
						
						if(found == 0){	
							$$ = aux;
							$$.id = $1.id;
							print = true;
						}
						else{
							yyerror("syntax error: undeclared identifier");
							file_log_error(fp, "syntax error: undeclared identifier");
							err = true;
						}
					}
      | T_INT				{ $$ = $1; $$.type = 0; }
      | T_FLOAT				{ $$ = $1; $$.type = 1; }
      | CONST_PI			{ $$ = pi; }
      | SYM_OB expr SYM_CB		{ $$ = $2; }
;

fixed_iteration: open_sentence sentence_list DONE 	{ 
	       							end_iteration($1); // $1, condition 
							}
;

open_sentence: REPEAT expr DO EOL			{ 	
	     							atributs aux = $2;
	     							int res = start_iteration(&aux);
	     							if(res == 0){
									$$ = aux;
								}
								else{
									yyerror("syntax error: repeat condition must be of integer type");
									file_log_error(fp, "syntax error: repeat condition must be of integer type");
									err = true;
								}
	     						}
;

%%

int main(int argc, char *argv[])
{ 
  // get current date and time 
  time_t t = time(NULL); 
  struct tm tm = *localtime(&t);

  // set log file name
  char* path;
  if(0 > asprintf(&path, "log/%d-%02d-%02d_%02d:%02d:%02d.log",
        tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour,
        tm.tm_min, tm.tm_sec)) {
		fprintf(stderr, "Couldn't create log file...");
		return 1;
  }
  
  // create log file
  fp = fopen(path, "w");
  free(path);

  if(argc > 1) { 
  	fprintf(fp, "Reading from file: %s\n\n", argv[1]);
	yyin = fopen(argv[1], "r");
  }
  yyparse();

  halt(); 

  fclose(fp);
  return 0;
}
