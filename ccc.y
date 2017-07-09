%{
#include <stdio.h>
#include "ccc.h"
#define YYDEBUG 1
%}
%union {
 char                *identifier;
 Expression          *expression;
 Statement           *statement;
}
%token <expression>  INT_LITERAL
%token <expression>  DOUBLE_LITERAL
%token <identifier>  IDENTIFIER
%token FUNCTION IF ELSE ELSIF WHILE FOR RETURN_T BREAK CONTINUE NULL_T
        LP RP LC RC SEMICOLON COMMA ASSIGN LOGICAL_AND LOGICAL_OR
        EQ NE GT GE LT LE ADD SUB MUL DIV MOD TRUE_T FALSE_T GLOBAL_T
        DOUBLE_LITERAL INT_LITERAL CR IDENTIFIER
%type  <expression> expression additiveExpression multiplicativeExpression
                    primaryExpression
%type  <statement>  statement definition_or_statement
%%
definition_or_statement
  : statement
  {
    interAddStatement($1);
    $$ = $1;
  }
  | definition_or_statement statement
  {
    interAddStatement($2);
    $$ = $1;
  }
statement
  : expression CR
  {
    $$ = createExpressionStatement($1);
  }
  | expression
  {
    $$ = createExpressionStatement($1);
  }
  ;
expression
  : additiveExpression
  | IDENTIFIER ASSIGN expression
  {
    $$ = createAssignExpression($1, &$3);
  }
  ;
additiveExpression
  : multiplicativeExpression
  | additiveExpression ADD multiplicativeExpression
  {
    $$ = createBinaryExpression(ADD_EXPRESSION, $1, $3);
  }
  | additiveExpression SUB multiplicativeExpression
  {
    $$ = createBinaryExpression(SUB_EXPRESSION, $1, $3);
  }
  ;
multiplicativeExpression
  : primaryExpression
  | multiplicativeExpression MUL primaryExpression
  {
    $$ = createBinaryExpression(MUL_EXPRESSION, $1, $3);
  }
  | multiplicativeExpression DIV primaryExpression
  {
    $$ = createBinaryExpression(DIV_EXPRESSION, $1, $3);
  }
  ;
primaryExpression
  : LP expression RP
  {
    $$ = $2;
  }
  | INT_LITERAL
  | DOUBLE_LITERAL
  ;
%%
