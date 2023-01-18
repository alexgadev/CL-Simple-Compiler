%{
#define _GNU_SOURCE
#include <stdio.h>
#include <stdbool.h>

// symbol table
#include "../include/symtab/symtab.h"

// for logging
#include <time.h>


/* ------ Function and variable declaration ------ */
int yylex(void);
void yyerror(char*);
extern FILE* yyin;


/* ------ Logging ------ */
void console_log_iden(char*, atributs);
void console_log_expr(atributs);

void file_log(char*); // file logging (primarily grammar production) for debugging
void file_log_error(char*); // file logging for errors


/* ------ Auxiliar function declaration ------ */
int num_types(atributs, atributs);


/* ------ Global variables ------ */
FILE* fp; // pointer to the log file created each execution
int line = 1; // run-time line counter
char* name;
char* temp; 
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

 
%type<attrs> T_INT T_FLOAT T_IDEN assignment factor pow unary term expr statement sentence 

%start start

%%

start: 
     | start sentence			
;

sentence_list: sentence_list sentence	
	     | sentence
;

sentence: statement EOL			{ 
						line++; 
						err = false; 
						if(print){  
							printf("%d:   PARAM %s\n%d:   CALL PUTI, 1\n", line - 1, $$.string, line); 
						}
					}
	| EOL				{ err = false; }	
	| CMD_EXIT			{ printf("%d:   HALT\n", line); exit(0); }

;

statement: expr				{ if(!err) console_log_expr($1); }
	 | assignment			{ if(!err) console_log_iden(name, $1); }
	 | fixed_iteration		{ printf("useless?\n"); }
;

expr: term				{ $$ = $1; }
	| expr OP_ADD term		{ 	if(!err){
							int type_expr = num_types($1, $3); // determine the kind of numeric expression we encountered
								
							// calculate the addition depending on the types of the arguments
							switch(type_expr){
								case 0: $$.integer = $1.integer + $3.integer;
									asprintf(&temp, "%d + %d = %d; of type int reduced from rule 'expr OP_ADD term'", $1.integer, $3.integer, $$.integer);
									break;
								case 1: $$.floating = $1.integer + $3.floating;
									asprintf(&temp, "%d + %lf = %lf; of type float reduced from rule 'expr OP_ADD term'", $1.integer, $3.floating, $$.floating);
									break;
								case 2: $$.floating = $1.floating + $3.integer;
									asprintf(&temp, "%lf + %d = %lf; of type float reduced from rule 'expr OP_ADD term'", $1.floating, $3.integer, $$.floating);
									break;
								case 3: $$.floating = $1.floating + $3.floating;
									asprintf(&temp, "%lf + %lf = %lf; of type float reduced from rule 'expr OP_ADD term'", $1.floating, $3.floating, $$.floating);
									break;
							}
								
							$$.type = type_expr == 0 ? 0 : 1;
							
							

							file_log(temp); // log grammar production
							free(temp);
						}
					}
	| expr OP_SUB term		{	if(!err){
							int type_expr = num_types($1, $3); // determine the kind of numeric expression we encountered
								
							// calculate the subtraction depending on the types of the arguments
							switch(type_expr){
								case 0: $$.integer = $1.integer - $3.integer;
									asprintf(&temp, "%d - %d = %d; of type int reduced from rule 'expr OP_SUB term'", $1.integer, $3.integer, $$.integer);
									break;
								case 1: $$.floating = $1.integer - $3.floating;
									asprintf(&temp, "%d - %lf = %lf; of type float reduced from rule 'expr OP_SUB term'", $1.integer, $3.floating, $$.floating);
									break;
								case 2: $$.floating = $1.floating - $3.integer;
									asprintf(&temp, "%lf - %d = %lf; of type float reduced from rule 'expr OP_SUB term'", $1.floating, $3.integer, $$.floating);
									break;
								case 3: $$.floating = $1.floating - $3.floating;
									asprintf(&temp, "%lf - %lf = %lf; of type float reduced from rule 'expr OP_SUB term'", $1.floating, $3.floating, $$.floating);
									break;
							}
								
							$$.type = type_expr == 0 ? 0 : 1; 
								
							file_log(temp); // log grammar production
							free(temp);
						}
					}
;

term: unary				{ $$ = $1; }
    | term OP_MUL unary			{ 	if(!err){							
							int type_expr = num_types($1, $3); // determine the kind of numeric expression we encountered
								
							// calculate the product depending on the types of the arguments
							switch(type_expr){
								case 0: $$.integer = $1.integer * $3.integer;
									asprintf(&temp, "%d * %d = %d; of type int reduced from rule 'term OP_MUL unary'", $1.integer, $3.integer, $$.integer);
									break;
								case 1: $$.floating = $1.integer * $3.floating;
									asprintf(&temp, "%d * %lf = %lf; of type float reduced from rule 'term OP_MUL unary'", $1.integer, $3.floating, $$.floating);
									break;
								case 2: $$.floating = $1.floating * $3.integer;
									asprintf(&temp, "%lf * %d = %lf; of type float reduced from rule 'term OP_MUL unary'", $1.floating, $3.integer, $$.floating);
									break;
								case 3: $$.floating = $1.floating * $3.floating;
									asprintf(&temp, "%lf * %lf = %lf; of type float reduced from rule 'term OP_MUL unary'", $1.floating, $3.floating, $$.floating);
									break;
							}
								
								$$.type = type_expr == 0 ? 0 : 1; 
								
								file_log(temp); // log grammar production
								free(temp);
						}
					}
    | term OP_DIV unary			{ 	if(!err){
							// control division by 0
							if($3.type == 0){
								if($3.integer == 0){
									yyerror("semantic error: cannot divide by 0"); 
									err = true;
								}
							}
							else{
								if($3.floating == 0.0f){
									yyerror("semantic error: cannot divide by 0.0"); 
									err = true;
								}
							}
								
							// if there wasn't an attempt of dividing by 0 calculate the division depending on arguments' type
							if(!err){
								int type_expr = num_types($1, $3); // determine the kind of numeric expression we encountered
									
								// calculate the division depending on the types of the arguments
								switch(type_expr){
									case 0: $$.floating = $1.integer / $3.integer;
										asprintf(&temp, "%d / %d = %lf; of type float reduced from rule 'term OP_DIV unary'", 
																	$1.integer, $3.integer, $$.floating);
										break;
									case 1: $$.floating = $1.integer / $3.floating;
										asprintf(&temp, "%d / %lf = %lf; of type float reduced from rule 'term OP_MOD unary'", 
																	$1.integer, $3.floating, $$.floating);
										break;
									case 2: $$.floating = $1.floating / $3.integer;
										asprintf(&temp, "%lf / %d = %lf; of type float reduced from rule 'term OP_MOD unary'", 
																	$1.floating, $3.integer, $$.floating);
										break;
									case 3: $$.floating = $1.floating / $3.floating;
										asprintf(&temp, "%lf / %lf = %lf; of type float reduced from rule 'term OP_MOD unary'", 
																	$1.floating, $3.floating, $$.floating);
										break;
								}

								$$.type = 1;

								file_log(temp); // log grammar production
								free(temp);
							}
						}

					}
    | term OP_MOD unary			{ 	if(!err){
							int type_expr = num_types($1, $3); // determine the kind of numeric expression we encountered

							// calculate the modulo depending on the types of the arguments
							switch(type_expr){
								case 0: $$.integer = $1.integer % $3.integer;
									asprintf(&temp, "%d %% %d = %d; of type int reduced from rule 'term OP_MOD unary'", $1.integer, $3.integer, $$.integer);
									break;
								case 1: $$.floating = fmod($1.integer,$3.floating);
									asprintf(&temp, "%d %% %lf = %lf; of type float reduced from rule 'term OP_MOD unary'", $1.integer, $3.floating, $$.floating);
									break;
								case 2: $$.floating = fmod($1.floating, $3.integer);
									asprintf(&temp, "%lf %% %d = %lf; of type float reduced from rule 'term OP_MOD unary'", $1.floating, $3.integer, $$.floating);
									break;
								case 3: $$.floating = fmod($1.floating, $3.floating);
									asprintf(&temp, "%lf %% %lf = %lf; of type float reduced from rule 'term OP_MOD unary'", $1.floating, $3.floating, $$.floating);
									break;
							}
								
							$$.type = type_expr == 0 ? 0 : 1; 
								
							file_log(temp); // log grammar production
							free(temp);
						}	
					}
;

unary: OP_SUB unary			{ 	if(!err){
     							if($2.type == 0){
								$$.integer = -$2.integer;
								$$.type = 0;
								
								asprintf(&temp, "-%d = %d; of type int reduced from rule 'OP_SUB unary'", $2.integer, $$.integer);
							}
							else{
								$$.floating = -$2.floating;
								$$.type = 1;
								
								asprintf(&temp, "-%lf = %lf; of type float reduced from rule 'OP_SUB unary'", $2.floating, $$.floating);
							}
								
							file_log(temp); // log grammar production
							free(temp);
						}
					}
     | pow				{ $$ = $1; }
;

pow: factor OP_POW pow			{ 	if(!err){
							int type_expr = num_types($1, $3); // determine the kind of numeric expression we encountered
								
							// calculate the power depending on the types of the arguments
							switch(type_expr){
								case 0: $$.integer = pow($1.integer, $3.integer);
									asprintf(&temp, "%d ** %d = %d; of type int reduced from rule 'factor OP_POW pow'", $1.integer, $3.integer, $$.integer);
									break;
								case 1: $$.floating = pow($1.integer, $3.floating);
									asprintf(&temp, "%d ** %lf = %lf; of type float reduced from rule 'factor OP_POW pow'", $1.integer, $3.floating, $$.floating);
									break;
								case 2: $$.floating = pow($1.floating, $3.integer);
									asprintf(&temp, "%lf ** %d = %lf; of type float reduced from rule 'factor OP_POW pow'", $1.floating, $3.integer, $$.floating);
									break;
								case 3: $$.floating = pow($1.floating, $3.floating);
									asprintf(&temp, "%lf ** %lf = %lf; of type float reduced from rule 'factor OP_POW pow'", $1.floating, $3.floating, $$.floating);
									break;
							}

							$$.type = type_expr == 0 ? 0 : 1;
								
							file_log(temp); // log grammar production
							free(temp);
						}
					}
   | factor				{ $$ = $1; }
;



factor: T_IDEN				{	atributs aux;
      						int found = sym_lookup($1.string, &aux);
      						if(found == 0){
							name = $1.string;
							$$ = aux;
							print = true;
						}
						else{
							yyerror("syntax error: undeclared identifier");
							file_log_error("syntax error: undeclared identifier");
							err = true;
						}
					}
      | T_INT				{ $$ = $1; $$.type = 0; }
      | T_FLOAT				{ $$ = $1; $$.type = 1; }
      | CONST_PI			{ atributs pi; pi.floating = acos(-1.0); pi.type = 1; $$ = pi; }
      | SYM_OB expr SYM_CB		{ $$ = $2; }
;


assignment: T_IDEN ASSIG expr		{ 	if(!err){ // check if there were any errors in the calculations of the expr to be assigned
	  						atributs aux;
							name = $1.string;
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
									file_log_error("semantic error: identifier and expression type missmatch");
									err = true;
								}
							}
							else{
								// if identifier doesn't exist then we have to create a new entry
								if(found == 2){
									aux = $3;
									sym_add(name, &aux);
								}
							}

							// if the assignment succeeded log grammar production
							if(!err) {
								switch($3.type){
									case 0: asprintf(&temp, "%s := %d; of type int reduced from rule 'T_IDEN ASSIG expr'", name, $3.integer);
										break;
									case 1: asprintf(&temp, "%s := %lf; of type float reduced from rule 'T_IDEN ASSIG expr'", name, $3.floating);
										break;
								}

								file_log(temp); // log grammar production
								free(temp);
								$$ = $3;
							}
						}
					}
;

fixed_iteration: open_sentence sentence_list DONE 	{ printf("IF sentence GOTO line_number\n"); }
;

open_sentence: REPEAT expr DO EOL			{ printf("abre repeat\n"); }
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

  printf("%d:   HALT\n", line);

  fclose(fp);
  return 0;
}

void yyerror(char *str)
{
  fprintf(stderr, "Compiler error:%d -> %s.\n", line, str);
}


/*-----------------------------------------------------*/
/*----------------- Auxiliar functions ----------------*/
/*-----------------------------------------------------*/

/* 
*  Returns the kind of numeric expression we've encountered.
*  Must only be used after 'is_numeric' succeeded, otherwise errors might happen.
*
*  0 -> both integers
*  1 -> a int, b float
*  2 -> a float, b int
*  3 -> both floats
*
*/
int num_types(atributs a, atributs b){
  if((a.type == 0) && (b.type == 0)){
  	return 0;
  }
  else{
  	if((a.type == 1) && (b.type == 1)){
		return 3;
	}
	else{
		if(a.type == 0){
			return 1;
		}
		else{
			return 2;
		}
	}
  }
}

/*----------------------------------------------------*/
/*----------------- Logging functions ----------------*/
/*----------------------------------------------------*/
void console_log_iden(char* name, atributs assig){
  switch(assig.type){
	case 0: printf("Assignment name: %s\ttype: int\tvalue: %d\n", name, assig.integer); 
		break;
	case 1: printf("Assignment name: %s\ttype: float\tvalue: %lf\n", name, assig.floating); 
		break;
  }
}

void console_log_expr(atributs expr){ 
  switch(expr.type){
	case 0: printf("Expression of type: int\t\tvalue: %d\n", expr.integer); 
		break;
	case 1: printf("Expression of type: float\tvalue: %lf\n", expr.floating); 
		break;
  }
}

void file_log(char* str){
	fprintf(fp, "sentence in line %d:\n\tgrammar production -> %s.\n\n", line, str);
}

void file_log_error(char* str){
	fprintf(fp, "sentence in line %d:\n\tcompiler error -> %s.\n\n", line, str);
}
