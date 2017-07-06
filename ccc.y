%{
#include <stdio.h>
#include "ccc.h"

%}
%token FUNCTION IF ELSE ELSIF WHILE FOR RETURN_T BREAK CONTINUE NULL_T
        LP RP LC RC SEMICOLON COMMA ASSIGN LOGICAL_AND LOGICAL_OR
        EQ NE GT GE LT LE ADD SUB MUL DIV MOD TRUE_T FALSE_T GLOBAL_T
        DOUBLE_LITERAL INT_LITERAL CR
%%
statement
  : expression CR
  {
    printExpression($1);
  }
  ;
expression
  : additiveExpression
  ;
additiveExpression
  : multiplicativeExpression
  | additiveExpression ADD multiplicativeExpression
  {
    $$ = createBinaryExpression(ADD_EXPRESSION, $1, $2);
  }
  | additiveExpression SUB multiplicativeExpression
  {
    $$ = createBinaryExpression(SUB_EXPRESSION, $1, $2);
  }
  ;
multiplicativeExpression
  : primaryExpression
  | multiplicativeExpression MUL primaryExpression
  {
    $$ = createBinaryExpression(MUL_EXPRESSION, $1, $2);
  }
  | multiplicativeExpression DIV primaryExpression
  {
    $$ = createBinaryExpression(DIV_EXPRESSION, $1, $2);
  }
  ;
primaryExpression
  : LP expression RP
  {
    $$ = $2;
  }
  | INT_LITERAL
  {
    $$ = createIntLiteralExpression($1);
  }
  | DOUBLE_LITERAL
  {
    $$ = createDoubleLiteralExpression($1);
  }
  ;
%%
