%{
#define YYSTYPE atributs

#include <stdio.h>
#include "../include/atributs.h"
#include "../gen/parse.tab.h"
%}

/* Stop the error "undefined reference to 'yywrap'" from Flex */
%option noyywrap

%%


-?[0-9]+				{ 
						yylval.integer = atoi(yytext); 
						return T_INT; 
					}
-?[0-9]+\.[0-9]+(e-?[0-9]+)?		{ 	
						yylval.floating = atof(yytext); 
						return T_FLOAT; 
					}
\".*\"					{ 
						// remove first and last characters which are '"'
						char* temp = strdup(yytext);
						char* result = temp + 1;

						result[strlen(result) - 1] = '\0';

						yylval.string = result;

						return T_STRING; 
					}
("true")|("false")			{
						yylval.boolean = (strcmp(yytext, "true")) ? false : true;
						return T_BOOL;
					}


\/\/.*					{}
#.*					{}
"/*"([^*]|\*+[^*/])*\*+"/"		{}


":="					{ return ASSIG; }


"("					{ return SYM_OB; }

")"					{ return SYM_CB; }


"+"					{ return OP_ADD; }
"-"					{ return OP_SUB; }
"*"					{ return OP_MUL; }
"/"					{ return OP_DIV; }
"%"					{ return OP_MOD; }
"**"					{ return OP_POW; }


"<"					{ return OP_LT; }
"<="					{ return OP_LE; }
">"					{ return OP_GT; }
">="					{ return OP_GE; }
"="					{ return OP_EQ; }
"<>"					{ return OP_INEQ; }


"not"					{ return BOOL_OP_NOT; }
"and"					{ return BOOL_OP_AND; }
"or"					{ return BOOL_OP_OR; }


("pi"|"PI")				{ return CONST_PI; }


"exit"					{ return CMD_EXIT; }

[a-zA-Z]+				{ 
						yylval.string = (char *) strdup(yytext);
						return T_IDEN; 
					}


"\n"					{ return EOL; }

" "

%%
