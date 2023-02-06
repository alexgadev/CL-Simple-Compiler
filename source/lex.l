%{
#define YYSTYPE atributs

#include <stdio.h>
#include "../include/compiler.h"
#include "../gen/parse.tab.h"
%}

/* Stop the error "undefined reference to 'yywrap'" from Flex */
%option noyywrap

%%


-?[0-9]+				{ 
						yylval.integer = atoi(yytext);
						yylval.id = (char *) strdup(yytext);
						return T_INT; 
					}
-?[0-9]+\.[0-9]+(e-?[0-9]+)?		{ 	
						yylval.real = atof(yytext);
						yylval.id = (char *) strdup(yytext);	
						return T_FLOAT; 
					}


\/\/.*					{}
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


("pi"|"PI")				{ return CONST_PI; }


"repeat"				{ return REPEAT; }
"do"					{ return DO; }
"done"					{ return DONE; }


"exit"					{ return CMD_EXIT; }

[a-zA-Z]+				{ 
						yylval.id = (char *) strdup(yytext);
						return T_IDEN; 
					}


[\n]					{ return EOL; }			
[\t]

" "

%%
