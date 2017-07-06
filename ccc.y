%{
#include <stdio.h>
#include "ccc.h"

%}
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
