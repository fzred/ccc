#include <stdio.h>
#include "ccc.h"

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