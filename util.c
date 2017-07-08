#include <stdio.h>
#include "ccc.h"


Interpreter curInterter;

Interpreter getCurInterpreter(){
  return curInterter;
}

void printExpression(Expression expression)
{
  if (expression.type == INT_EXPRESSION)
  {
    printf("%d\n", expression.u.intValue);
  }
  if (expression.type == DOUBLE_EXPRESSION)
  {
    printf("%f\n", expression.u.doubleValue);
  }
}

int yyerror(char const *str)
{
    extern char *yytext;
    fprintf(stderr, "parser error near %s\n", yytext);
    return 0;
}
