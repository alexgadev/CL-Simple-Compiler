#define _GNU_SOURCE
:q

#include <stdlib.h>
#include <stdio.h>

#include "../include/compiler.h"


int line = 1;
int t_num = 1;

/*----------------------------------------------------*/
/*---------------- Logging Functions -----------------*/
/*----------------------------------------------------*/
void yyerror(char *str)
{
    fprintf(stderr, "Compiler error: %s.\n", str);
}

void file_log(FILE* fp, char *str){
    fprintf(fp, "sentence in line:%d\n\tgrammar production\t%s.\n", line, str);
}

void file_log_error(FILE* fp, char *str){
    fprintf(fp, "sentence in line:%d\n\tcompiler error -> %s.\n", line, str);
}


/*-----------------------------------------------------*/
/*---------------- Auxiliar Functions -----------------*/
/*-----------------------------------------------------*/
void next_line(){ line++; }

bool is_null(atributs a){
    if((a.integer == -1) && (a.real == -1.0) && !(a.id))
        return true;
    else return false;
}


/*
*  Returns the type of numeric expression we've encountered
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

atributs eval(atributs a, char op, atributs b, char* log){
    atributs res;


    int type_expr = num_types(a, b);
    res.type = type_expr == 0 ? 0 : 1;

    char *op_strI, *op_strF;
    switch(op){
        case '+':   op_strI = "ADDI";
                    op_strF = "ADDF";
                    asprintf(&log, "'expr -> expr OP_ADD term' rule reduced");
                    break;

        case '-':   op_strI = "SUBI";
                    op_strF = "SUBF";
                    asprintf(&log, "'expr -> expr OP_SUB term' rule reduced");
                    break;

        case '*':   op_strI = "MULI";
                    op_strF = "MULF";
                    asprintf(&log, "'term -> term OP_MUL unary' rule reduced");
                    break;

        case '/':   op_strI = "DIVI";
                    op_strF = "DIVF";
                    asprintf(&log, "'term -> term OP_DIV unary' rule reduced");
                    res.type = 1;
                    break;

        case '%':   op_strI = "MODI";
                    op_strF = "MODF";
                    asprintf(&log, "'term -> term OP_MOD unary' rule reduced");
                    break;  
    }

    // compute the unary operation
    if(is_null(a)){
        if(b.type == 0){
            printf("%d:  $t%02d := CHSI%s\n", line, t_num, b.id);
            res.integer = -b.integer;

            asprintf(&res.id, "%d", res.integer);
        }
        else{
            printf("%d:  $t%02d := CHSF%s\n", line, t_num, b.id);
            res.real = -b.real;

            asprintf(&res.id, "%lf", res.real);
        }
            
        res.type = b.type;

        free(log);
        asprintf(&log, "'unary -> OP_SUB unary' rule reduced");

    }
    else{
        if(op == ':'){
            asprintf(&res.id, "'assignment -> T_IDEN ASSIG expr' rule reduced");
            printf("%d:  %s := %s\n", line, a.id, b.id);
        }
        else{
            char *temp;
            switch(type_expr){
                case 0: printf("%d:  $t%02d := %s %s %s\n", line, t_num, a.id, op_strI, b.id);
                        asprintf(&res.id, "$t%02d", t_num);

                        t_num++;
                        break;

                case 1: printf("%d:  $t%02d := I2F %s\n", line, t_num, a.id);
                        asprintf(&temp, "$t%02d", t_num);
                        t_num++;
                        line++;
    
                        printf("%d:  $t%02d := %s %s %s\n", line, t_num, temp, op_strF, b.id);
                        asprintf(&res.id, "$t%02d", t_num);

                        free(temp);
                        t_num++;
                        break;

                case 2: printf("%d:  $t%02d := I2F %s\n", line, t_num, b.id);
                        asprintf(&temp, "$t%02d", t_num);
                        t_num++;
                        line++;

                        printf("%d:  $t%02d := %s %s %s\n", line, t_num, a.id, op_strF, temp);
                        asprintf(&res.id, "$t%02d", t_num);

                        free(temp);
                        t_num++;
                        break;
    
                case 3: printf("%d:  $t%02d := %s %s %s\n", line, t_num, a.id, op_strF, b.id);
                        asprintf(&res.id, "$t%02d", t_num);
                        t_num++;
                        break;
            }
        }
    }
    line++;
    return res;
}


int start_iteration(atributs *arg){
    if(arg->type != 0) return 1;
    printf("%d:  $t%02d := 0\n", line, t_num);
 
    arg->integer = line + 1;
    arg->real = t_num;

    t_num++;
    line++;
    return 0;
}

int end_iteration(atributs arg){
    int n = arg.real;

    printf("%d:  $t%02d := $t%02d ADDI 1\n", line, n, n);
    line++;

    printf("%d:  IF $t%02d LTI %s GOTO %d\n", line, n, arg.id, arg.integer);
    line++;
}

void show(atributs arg){
    switch(arg.type){
        case 0: printf("%d:  PARAM %s\n%d:  CALL PUTI, 1\n", line, arg.id, line + 1);
                break;
        case 1: printf("%d:  PARAM %s\n%d:  CALL PUTF, 1\n", line, arg.id, line + 1);
                break;
    }
    line += 2;
}

void halt(){
    printf("%d:  HALT\n", line);
}
