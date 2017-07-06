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

  }
  | additiveExpression SUB multiplicativeExpression
  {

  }
  ;
multiplicativeExpression
  : primaryExpression
  | multiplicativeExpression MUL primaryExpression
  {

  }
  | multiplicativeExpression DIV primaryExpression
  {

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
