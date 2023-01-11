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
void check_error(atributs, atributs);


/* ------ Auxiliar function declaration ------ */
bool is_numeric(atributs, atributs);
bool is_string(atributs, atributs);
bool is_bool(atributs, atributs);
int num_types(atributs, atributs);


/* ------ Auxiliar variables ------ */
FILE* fp; // pointer to the log file created each execution
int line = 1; // run-time line counter
char* name;
char* temp; 
bool err; // error flag

%}


%union{
	atributs attrs;
}


%token T_INT T_FLOAT T_STRING T_IDEN T_BOOL

%token ASSIG

%token SYM_OB SYM_CB

%token OP_ADD OP_SUB OP_MUL OP_DIV OP_MOD OP_POW

%token OP_LT OP_LE OP_GT OP_GE OP_EQ OP_INEQ 

%token BOOL_OP_NOT BOOL_OP_AND BOOL_OP_OR

%token CONST_PI

%token EOL CMD_EXIT

 
%type<attrs> T_INT T_FLOAT T_STRING T_IDEN T_BOOL assignment factor pow unary term arith relexpr bool_not bool_and expr statement line 

%%

start: 
     | start line
;

line: EOL 				{ line++; err = false; }
    | statement EOL 			{ line++; err = false; }
    | CMD_EXIT				{ exit(0); }
;

statement: expr				{ if(!err) console_log_expr($1); }
	 | assignment			{ if(!err) console_log_iden(name, $1); }
;

expr: bool_and				{ $$ = $1; }
    | expr BOOL_OP_OR bool_and		{	if(!err){ 
							bool res = is_bool($1, $3); // arguments can only be of type 'boolean'
							if(res && ($1.type == $3.type)){
								$$.boolean = $1.boolean || $3.boolean; // compute logical or
								$$.type = 3;

								asprintf(&temp, "%s or %s = %s; of type boolean reduced from rule 'expr BOOL_OP_OR bool_and'",
										$1.boolean ? "true" : "false", $3.boolean ? "true" : "false", $$.boolean ? "true" : "false");

								file_log(temp); // log grammar production
								free(temp);
							}
							else{
								yyerror("semantic error: cannot compute logical or on non-boolean values");
								file_log_error("semantic error: cannot compute logical or on non-boolean values");
								err = true;
							}
						}
    					}
;

bool_and: bool_not			{ $$ = $1; }
	| bool_and BOOL_OP_AND bool_not	{ 	if(!err){
							bool res = is_bool($1, $3); // arguments can only be of type 'boolean'
							if(res && ($1.type == $3.type)){
								$$.boolean = $1.boolean && $3.boolean; // compute logical and
								$$.type = 3;

					
								asprintf(&temp, "%s and %s = %s; of type boolean reduced from rule 'bool_and BOOL_OP_AND bool_not'",
										$1.boolean ? "true" : "false", $3.boolean ? "true" : "false", $$.boolean ? "true" : "false");

								file_log(temp); // log grammar production
								free(temp);
						}
							else{
								yyerror("semantic error: cannot compute logical and on non-boolean values");
								file_log_error("semantic error: cannot compute logical and on non-boolean values");
								err = true;
							}
						}
 					}
;
	
bool_not: BOOL_OP_NOT relexpr		{ 	if(!err){
							// argument can only be of type 'boolean'
							if($2.type == 3){
								$$.boolean = !$2.boolean; // negate with logical '!'
								$$.type = 3;
								
								
								asprintf(&temp, "not %s; of type boolean reduced from rule 'BOOL_OP_NOT relexpr'", $$.boolean ? "true" : "false");

								file_log(temp); // log grammar production
								free(temp);
							}
							else{
								yyerror("semantic error: cannot compute logical not on non-boolean values");
								file_log_error("semantic error: cannot compute logical not on non-boolean values");
								err = true;
							}
						}
					}	
	| relexpr			{ $$ = $1; }
;

relexpr: arith				{ $$ = $1; }
	| relexpr OP_GT arith		{	if(!err){
							// check types and make appropiate conversion if needed
							bool numeric = is_numeric($1, $3); 
									
							if(numeric){ // operation applicable to numeric and string only for concatenation 
								int type_expr = num_types($1, $3); // determine the kind of numeric expression we encountered

								// check arg1 is greater than arg2 depending on the types of the arguments
								switch(type_expr){
									case 0: $$.boolean = $1.integer > $3.integer ? true : false;
										asprintf(&temp, "%d > %d = %s; of type boolean reduced from rule 'relexpr OP_GT arith'", 
															$1.integer, $3.integer, $$.boolean ? "true" : "false");
										break;
									case 1: $$.boolean = $1.integer > $3.floating ? true : false;
										asprintf(&temp, "%d > %lf = %s; of type boolean reduced from rule 'relexpr OP_GT arith'", 
															$1.integer, $3.floating, $$.boolean ? "true" : "false");
										break;
									case 2: $$.boolean = $1.floating > $3.integer ? true : false;
										asprintf(&temp, "%lf > %d = %s; of type boolean reduced from rule 'relexpr OP_GT arith'", 
															$1.floating, $3.integer, $$.boolean ? "true" : "false");
										break;
									case 3: $$.boolean = $1.floating > $3.floating ? true : false;
										asprintf(&temp, "%lf > %lf = %s; of type boolean reduced from rule 'relexpr OP_GT arith'", 
															$1.floating, $3.floating, $$.boolean ? "true" : "false");
										break;
								}
								$$.type = 3;

								file_log(temp); // log grammar production
								free(temp);
							}
							else{ check_error($1, $3); }
						}
					}
	| relexpr OP_GE arith		{
						if(!err){
							// check types and make appropiate conversion if needed
							bool numeric = is_numeric($1, $3); 
									
							if(numeric){ // operation applicable to numeric and string only for concatenation 
								int type_expr = num_types($1, $3); // determine the kind of numeric expression we encountered

								// check arg1 is greater or equal than arg2 depending on the types of the arguments
								switch(type_expr){
									case 0: $$.boolean = $1.integer >= $3.integer ? true : false;
										asprintf(&temp, "%d >= %d = %s; of type boolean reduced from rule 'relexpr OP_GE arith'", 
															$1.integer, $3.integer, $$.boolean ? "true" : "false");
										break;
									case 1: $$.boolean = $1.integer >= $3.floating ? true : false;
										asprintf(&temp, "%d >= %lf = %s; of type boolean reduced from rule 'relexpr OP_GE arith'", 
															$1.integer, $3.floating, $$.boolean ? "true" : "false");
										break;
									case 2: $$.boolean = $1.floating >= $3.integer ? true : false;
										asprintf(&temp, "%lf >= %d = %s; of type boolean reduced from rule 'relexpr OP_GE arith'", 
															$1.floating, $3.integer, $$.boolean ? "true" : "false");
										break;
									case 3: $$.boolean = $1.floating >= $3.floating ? true : false;
										asprintf(&temp, "%lf >= %lf = %s; of type boolean reduced from rule 'relexpr OP_GE arith'", 
															$1.floating, $3.floating, $$.boolean ? "true" : "false");
										break;
								}
								$$.type = 3;

								file_log(temp); // log grammar production
								free(temp);
							}
							else{ check_error($1, $3); }
						}
					}
	| relexpr OP_LT arith		{
						if(!err){
							// check types and make appropiate conversion if needed
							bool numeric = is_numeric($1, $3); 
									
							if(numeric){ // operation applicable to numeric and string only for concatenation 
								int type_expr = num_types($1, $3); // determine the kind of numeric expression we encountered

								// check arg1 is less than arg2 depending on the types of the arguments
								switch(type_expr){
									case 0: $$.boolean = $1.integer < $3.integer ? true : false;
										asprintf(&temp, "%d < %d = %s; of type boolean reduced from rule 'relexpr OP_LT arith'", 
															$1.integer, $3.integer, $$.boolean ? "true" : "false");
										break;
									case 1: $$.boolean = $1.integer < $3.floating ? true : false;
										asprintf(&temp, "%d < %lf = %s; of type boolean reduced from rule 'relexpr OP_LT arith'", 
															$1.integer, $3.floating, $$.boolean ? "true" : "false");
										break;
									case 2: $$.boolean = $1.floating < $3.integer ? true : false;
										asprintf(&temp, "%lf < %d = %s; of type boolean reduced from rule 'relexpr OP_LT arith'", 
															$1.floating, $3.integer, $$.boolean ? "true" : "false");
										break;
									case 3: $$.boolean = $1.floating < $3.floating ? true : false;
										asprintf(&temp, "%lf < %lf = %s; of type boolean reduced from rule 'relexpr OP_LT arith'", 
															$1.floating, $3.floating, $$.boolean ? "true" : "false");
										break;
								}
								$$.type = 3;

								file_log(temp); // log grammar production
								free(temp);
							}
							else{ check_error($1, $3); }
						}
					}
	| relexpr OP_LE arith		{	if(!err){
							// check types and make appropiate conversion if needed
							bool numeric = is_numeric($1, $3); 
									
							if(numeric){ // operation applicable to numeric and string only for concatenation 
								int type_expr = num_types($1, $3); // determine the kind of numeric expression we encountered

								// check arg1 is less or equal than arg2 depending on the types of the arguments
								switch(type_expr){
									case 0: $$.boolean = $1.integer <= $3.integer ? true : false;
										asprintf(&temp, "%d <= %d = %s; of type boolean reduced from rule 'relexpr OP_LE arith'", 
															$1.integer, $3.integer, $$.boolean ? "true" : "false");
										break;
									case 1: $$.boolean = $1.integer <= $3.floating ? true : false;
										asprintf(&temp, "%d <= %lf = %s; of type boolean reduced from rule 'relexpr OP_LE arith'", 
															$1.integer, $3.floating, $$.boolean ? "true" : "false");
										break;
									case 2: $$.boolean = $1.floating <= $3.integer ? true : false;
										asprintf(&temp, "%lf <= %d = %s; of type boolean reduced from rule 'relexpr OP_LE arith'", 
															$1.floating, $3.integer, $$.boolean ? "true" : "false");
										break;
									case 3: $$.boolean = $1.floating <= $3.floating	? true : false;
										asprintf(&temp, "%lf <= %lf = %s; of type boolean reduced from rule 'relexpr OP_LE arith'", 
															$1.floating, $3.floating, $$.boolean ? "true" : "false");
										break;
								}
								$$.type = 3;

								file_log(temp); // log grammar production
								free(temp);
							}
							else{ check_error($1, $3); }
						}
					}
	| relexpr OP_EQ arith		{	if(!err){
							// check types and make appropiate conversion if needed
							bool numeric = is_numeric($1, $3); 
									
							if(numeric){ // operation applicable to numeric and string only for concatenation 
								int type_expr = num_types($1, $3); // determine the kind of numeric expression we encountered

								// check equality depending on the types of the arguments
								switch(type_expr){
									case 0: $$.boolean = $1.integer == $3.integer ? true : false;
										asprintf(&temp, "'%d = %d' = %s; of type boolean reduced from rule 'relexpr OP_EQ arith'", 
															$1.integer, $3.integer, $$.boolean ? "true" : "false");
										break;
									case 1: $$.boolean = $1.integer == $3.floating ? true : false;
										asprintf(&temp, "'%d = %lf' = %s; of type boolean reduced from rule 'relexpr OP_EQ arith'", 
															$1.integer, $3.floating, $$.boolean ? "true" : "false");
										break;
									case 2: $$.boolean = $1.floating == $3.integer ? true : false;
										asprintf(&temp, "'%lf = %d' = %s; of type boolean reduced from rule 'relexpr OP_EQ arith'", 
															$1.floating, $3.integer, $$.boolean ? "true" : "false");
										break;
									case 3: $$.boolean = $1.floating == $3.floating ? true : false;
										asprintf(&temp, "'%lf = %lf' = %s; of type boolean reduced from rule 'relexpr OP_EQ arith'", 
															$1.floating, $3.floating, $$.boolean ? "true" : "false");
										break;
								}
								$$.type = 3;

								file_log(temp); // log grammar production
								free(temp);
							}
							else{ check_error($1, $3); }
						}
					}
	| relexpr OP_INEQ arith		{ 	if(!err){
							// check types and make appropiate conversion if needed
							bool numeric = is_numeric($1, $3); 
									
							if(numeric){ // operation applicable to numeric and string only for concatenation 
								int type_expr = num_types($1, $3); // determine the kind of numeric expression we encountered

								// check inequality depending on the types of the arguments
								switch(type_expr){
									case 0: $$.boolean = $1.integer != $3.integer;
										asprintf(&temp, "%d <> %d = %s; of type boolean reduced from rule 'relexpr OP_INEQ arith'", 
															$1.integer, $3.integer, $$.boolean ? "true" : "false");
										break;
									case 1: $$.boolean = $1.integer != $3.floating;
										asprintf(&temp, "%d <> %lf = %s; of type boolean reduced from rule 'relexpr OP_INEQ arith'", 
															$1.integer, $3.floating, $$.boolean ? "true" : "false");
										break;
									case 2: $$.boolean = $1.floating != $3.integer ? true : false;
										asprintf(&temp, "%lf <> %d = %s; of type boolean reduced from rule 'relexpr OP_INEQ arith'", 
															$1.floating, $3.integer, $$.boolean ? "true" : "false");
										break;
									case 3: $$.boolean = $1.floating != $3.floating ? true : false;
										asprintf(&temp, "%lf <> %lf = %s; of type boolean reduced from rule 'relexpr OP_INEQ arith'", 
															$1.floating, $3.floating, $$.boolean ? "true" : "false");
										break;
								}
								$$.type = 3;

								file_log(temp); // log grammar production
								free(temp);
							}
							else{ check_error($1, $3); }
						}
					}	
;


arith: term				{ $$ = $1; }
	| arith OP_ADD term		{ 	if(!err){
							// check types and make appropiate conversion if needed
							bool numeric = is_numeric($1, $3);

							if(numeric){ // operation applicable to numeric and string only for concatenation
								int type_expr = num_types($1, $3); // determine the kind of numeric expression we encountered
								
								// calculate the addition depending on the types of the arguments
								switch(type_expr){
									case 0: $$.integer = $1.integer + $3.integer;
										asprintf(&temp, "%d + %d = %d; of type int reduced from rule 'arith OP_ADD term'", 
																	$1.integer, $3.integer, $$.integer);
										break;
									case 1: $$.floating = $1.integer + $3.floating;
										asprintf(&temp, "%d + %lf = %lf; of type float reduced from rule 'arith OP_ADD term'", 
																	$1.integer, $3.floating, $$.floating);
										break;
									case 2: $$.floating = $1.floating + $3.integer;
										asprintf(&temp, "%lf + %d = %lf; of type float reduced from rule 'arith OP_ADD term'", 
																	$1.floating, $3.integer, $$.floating);
										break;
									case 3: $$.floating = $1.floating + $3.floating;
										asprintf(&temp, "%lf + %lf = %lf; of type float reduced from rule 'arith OP_ADD term'", 
																	$1.floating, $3.floating, $$.floating);
										break;
								}
								
								$$.type = type_expr == 0 ? 0 : 1;
								
								file_log(temp); // log grammar production
								free(temp);
							}
							else{
								// concatenation
								if(is_string($1, $3)){
									char* str = strdup($1.string);
									char* aux1 = strdup($3.string);
									
									// if both aren't strings, must make the appropiate conversions
									if(($1.type == 2) != ($3.type == 2)){
										if($1.type == 2){
											switch($3.type){
												case 0: asprintf(&aux1, "%d", $3.integer);
													break;
												case 1: asprintf(&aux1, "%lf", $3.floating);
													break;
												case 3: asprintf(&aux1, "%s", $1.boolean ? "true" : "false");
													break;
											}
										}
										else{
											switch($1.type){
												case 0: asprintf(&str, "%d", $1.integer);
													break;
												case 1: asprintf(&str, "%lf", $1.floating);
													break;
												case 3: asprintf(&str, "%s", $1.boolean ? "true" : "false");
													break;
											}
										}
									}
									char* aux = strdup(str); // save first string for logging purposes
									
									// after needed conversions, concatenate the result into 'str'
									strcat(str, aux1);
									
									asprintf(&temp, "%s + %s = '%s'; of type string reduced from rule 'arith OP_ADD term'", aux, aux1, str);
									
									$$.string = strdup(str);
									$$.type = 2;	
									

									file_log(temp); // log grammar production
									free(temp);
									
									// free all memory allocated
									free(str);
									free(aux);
									free(aux1);
								}
								else{
									yyerror("semantic error: expected a value of type 'int', 'float' or 'string', but got one of type 'boolean'");
									file_log_error("semantic error: expected a value of type 'int', 'float' or 'string', but got one of type 'boolean'");
									err = true;
								}
							}
						}
					}
	| arith OP_SUB term		{	if(!err){
							// check types and make appropiate conversion if needed	
							bool numeric = is_numeric($1, $3);

							if(numeric){ //operation only applicable to numeric values
								int type_expr = num_types($1, $3); // determine the kind of numeric expression we encountered
								
								// calculate the subtraction depending on the types of the arguments
								switch(type_expr){
									case 0: $$.integer = $1.integer - $3.integer;
										asprintf(&temp, "%d - %d = %d; of type int reduced from rule 'arith OP_SUB term'", 
																	$1.integer, $3.integer, $$.integer);
										break;
									case 1: $$.floating = $1.integer - $3.floating;
										asprintf(&temp, "%d - %lf = %lf; of type float reduced from rule 'arith OP_SUB term'", 
																	$1.integer, $3.floating, $$.floating);
										break;
									case 2: $$.floating = $1.floating - $3.integer;
										asprintf(&temp, "%lf - %d = %lf; of type float reduced from rule 'arith OP_SUB term'", 
																	$1.floating, $3.integer, $$.floating);
										break;
									case 3: $$.floating = $1.floating - $3.floating;
										asprintf(&temp, "%lf - %lf = %lf; of type float reduced from rule 'arith OP_SUB term'", 
																	$1.floating, $3.floating, $$.floating);
										break;
								}
								
								$$.type = type_expr == 0 ? 0 : 1; 
								
								file_log(temp); // log grammar production
								free(temp);
							}
							else{ check_error($1, $3); }
						}
					}
;

term: unary				{ $$ = $1; }
    | term OP_MUL unary			{ 	if(!err){
							// check types and make appropiate conversion if needed
							bool numeric = is_numeric($1, $3);

							if(numeric){ //operation only applicable to numeric values								
								int type_expr = num_types($1, $3); // determine the kind of numeric expression we encountered
								
								// calculate the product depending on the types of the arguments
								switch(type_expr){
									case 0: $$.integer = $1.integer * $3.integer;
										asprintf(&temp, "%d * %d = %d; of type int reduced from rule 'term OP_MUL unary'", 
																	$1.integer, $3.integer, $$.integer);
										break;
									case 1: $$.floating = $1.integer * $3.floating;
										asprintf(&temp, "%d * %lf = %lf; of type float reduced from rule 'term OP_MUL unary'", 
																	$1.integer, $3.floating, $$.floating);
										break;
									case 2: $$.floating = $1.floating * $3.integer;
										asprintf(&temp, "%lf * %d = %lf; of type float reduced from rule 'term OP_MUL unary'", 
																	$1.floating, $3.integer, $$.floating);
										break;
									case 3: $$.floating = $1.floating * $3.floating;
										asprintf(&temp, "%lf * %lf = %lf; of type float reduced from rule 'term OP_MUL unary'", 
																	$1.floating, $3.floating, $$.floating);
										break;
								}
								
								$$.type = type_expr == 0 ? 0 : 1; 
								
								file_log(temp); // log grammar production
								free(temp);
							}
							else{ check_error($1, $3); }
						}
					}
    | term OP_DIV unary			{ 	if(!err){
							// check types and make appropiate conversion if needed
							bool numeric = is_numeric($1, $3);

							if(numeric){ //operation only applicable to numeric values
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
							else{ check_error($1, $3); }
						}

					}
    | term OP_MOD unary			{ 	if(!err){
							// check types and make appropiate conversion if needed							
							bool numeric = is_numeric($1, $3);
							
							if(numeric){ // operation only applicable to numeric arguments	
								int type_expr = num_types($1, $3); // determine the kind of numeric expression we encountered

								// calculate the modulo depending on the types of the arguments
								switch(type_expr){
									case 0: $$.integer = $1.integer % $3.integer;
										asprintf(&temp, "%d %% %d = %d; of type int reduced from rule 'term OP_MOD unary'", 
																	$1.integer, $3.integer, $$.integer);
										break;
									case 1: $$.floating = fmod($1.integer,$3.floating);
										asprintf(&temp, "%d %% %lf = %lf; of type float reduced from rule 'term OP_MOD unary'", 
																	$1.integer, $3.floating, $$.floating);
										break;
									case 2: $$.floating = fmod($1.floating, $3.integer);
										asprintf(&temp, "%lf %% %d = %lf; of type float reduced from rule 'term OP_MOD unary'", 
																	$1.floating, $3.integer, $$.floating);
										break;
									case 3: $$.floating = fmod($1.floating, $3.floating);
										asprintf(&temp, "%lf %% %lf = %lf; of type float reduced from rule 'term OP_MOD unary'", 
																	$1.floating, $3.floating, $$.floating);
										break;
								}
								
								$$.type = type_expr == 0 ? 0 : 1; 
								
								file_log(temp); // log grammar production
								free(temp);
							}
							else{ check_error($1, $3); }
						}	
					}
;

unary: OP_SUB unary			{ 	if(!err){
     							// only negate numeric arguments aka of type 0 or 1
							if(($2.type == 0) || ($2.type == 1)){
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
							else { 
								yyerror("semantic error: cannot negate non-numeric values"); 
								file_log_error("semantic error: cannot negate non-numeric values");
								err = true; 
							}
						}
					}
     | pow				{ $$ = $1; }
;

pow: factor OP_POW pow			{ 	if(!err){
							// check types and make appropiate conversion if needed
							bool numeric = is_numeric($1, $3);

							if(numeric){
								int type_expr = num_types($1, $3); // determine the kind of numeric expression we encountered
								//char* temp;
								
								// calculate the power depending on the types of the arguments
								switch(type_expr){
									case 0: $$.integer = pow($1.integer, $3.integer);
										asprintf(&temp, "%d ** %d = %d; of type int reduced from rule 'factor OP_POW pow'", 
																	$1.integer, $3.integer, $$.integer);
										break;
									case 1: $$.floating = pow($1.integer, $3.floating);
										asprintf(&temp, "%d ** %lf = %lf; of type float reduced from rule 'factor OP_POW pow'", 
																	$1.integer, $3.floating, $$.floating);
										break;
									case 2: $$.floating = pow($1.floating, $3.integer);
										asprintf(&temp, "%lf ** %d = %lf; of type float reduced from rule 'factor OP_POW pow'", 
																	$1.floating, $3.integer, $$.floating);
										break;
									case 3: $$.floating = pow($1.floating, $3.floating);
										asprintf(&temp, "%lf ** %lf = %lf; of type float reduced from rule 'factor OP_POW pow'", 
																	$1.floating, $3.floating, $$.floating);
										break;
								}

								$$.type = type_expr == 0 ? 0 : 1;
								
								file_log(temp); // log grammar production
								free(temp);
							}
							else{ check_error($1, $3); }
						}
					}
   | factor				{ $$ = $1; }
;



factor: T_IDEN				{	atributs aux;
      						int found = sym_lookup($1.string, &aux);
      						if(found == 0){
							name = $1.string;
							$$ = aux;
						}
						else{
							yyerror("syntax error: undeclared identifier");
							file_log_error("syntax error: undeclared identifier");
							err = true;
						}
					}
      | T_INT				{ $$ = $1; $$.type = 0; }
      | T_FLOAT				{ $$ = $1; $$.type = 1; }
      | T_STRING			{ $$ = $1; $$.type = 2; }
      | T_BOOL				{ $$ = $1; $$.type = 3; }
      | SYM_OB expr SYM_CB		{ $$ = $2; /*TODO: large string containing complete sentence*/}
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
								//char* temp;
								switch($3.type){
									case 0: asprintf(&temp, "%s := %d; of type int reduced from rule 'T_IDEN ASSIG expr'", name, $3.integer);
										break;
									case 1: asprintf(&temp, "%s := %lf; of type float reduced from rule 'T_IDEN ASSIG expr'", name, $3.floating);
										break;
									case 2: asprintf(&temp, "%s := '%s'; of type string reduced from rule 'T_IDEN ASSIG expr'", name, $3.string);
										break;
									case 3: asprintf(&temp, "%s := %s; of type bool reduced from rule 'T_IDEN ASSIG expr'", name, $3.boolean ? "true" : "false");
										break;
								}

								file_log(temp); // log grammar production
								free(temp);
								$$ = $3;
							}
						}
					}
;

%%

int main(int argc, char **argv)
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

  yyparse();

  fclose(fp);
  return 0;
}

void yyerror(char *str)
{
  fprintf(stderr, "Compiler error:%d: %s.\n", line, str);
}


/*-----------------------------------------------------*/
/*----------------- Auxiliar functions ----------------*/
/*-----------------------------------------------------*/

/* 
*  Checks if passed variables are of a numeric type or not 
*/
bool is_numeric(atributs a, atributs b){
	return (((a.type == 0) || (a.type == 1)) && ((b.type == 0) || (b.type == 1)));
}

bool is_string(atributs a, atributs b){
	return (a.type == 2) || (b.type == 2);
}

bool is_bool(atributs a, atributs b){
	return (a.type == 3) || (b.type == 3);
}

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
	case 2: printf("Assignment name: %s\ttype: string\tvalue: '%s'\n", name, assig.string); 
		break;
	case 3: printf("Assignment name: %s\ttype: boolean\tvalue: %s\n", name, assig.boolean ? "true" : "false"); 
		break;
  }
}

void console_log_expr(atributs expr){ 
  switch(expr.type){
	case 0: printf("Expression of type: int\tvalue: %d\n", expr.integer); 
		break;
	case 1: printf("Expression of type: float\tvalue: %lf\n", expr.floating); 
		break;
	case 2: printf("Expression of type: string\tvalue: '%s'\n", expr.string); 
		break;
	case 3: printf("Expression of type: boolean\tvalue: %s\n", expr.boolean ? "true" : "false"); 
		break;
  }
}

void file_log(char* str){
	fprintf(fp, "sentence in line %d:\n\tgrammar production -> %s\n\n", line, str);
}

void file_log_error(char* str){
	fprintf(fp, "Compiler error:%d: %s.\n\n", line, str);
}

void check_error(atributs a, atributs b){
	// string arguments are not valid
	if(is_string(a, b)){
		yyerror("semantic error: expected a value of type 'int' or 'float', but got one of type 'string'");
		file_log_error("semantic error: expected a value of type 'int' or 'float', but got one of type 'string'");
	}
	// boolean arguments are not valid either
	else{
		yyerror("semantic error: expected a value of type 'int' or 'float', but got one of type 'boolean'");
		file_log_error("semantic error: expected a value of type 'int' or 'float', but got one of type 'boolean'");
	}
	err = true;
}
