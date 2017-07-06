#include <math.h>
#include "ccc.h"

Expression createIntLiteralExpression(int value)
{
  Expression exp;
  exp.type = INT_EXPRESSION;
  exp.u.intValue = value;
  return exp;
}

Expression createDoubleLiteralExpression(double value)
{
  Expression exp;
  exp.type = DOUBLE_EXPRESSION;
  exp.u.doubleValue = value;
  return exp;
}

Expression createBinaryExpression(ExpressionType expressionType,
                                  Expression left,
                                  Expression right)
{
  Expression exp;
  int isDouble = 0;
  if ((left.type == INT_EXPRESSION || left.type == DOUBLE_EXPRESSION) &&
      (right.type == INT_EXPRESSION || right.type == DOUBLE_EXPRESSION))
  {
    if (left.type == DOUBLE_EXPRESSION || right.type == DOUBLE_EXPRESSION)
    {
      isDouble = 1;
    }
  }

  if (isDouble)
  {
    exp.type = DOUBLE_EXPRESSION;
  }

  if (expressionType == ADD_EXPRESSION)
  {
    if (isDouble)
    {
      exp.u.doubleValue = left.u.doubleValue + right.u.doubleValue;
    }
    else
    {
      exp.u.intValue = left.u.intValue + right.u.intValue;
    }
  }

  if (expressionType == SUB_EXPRESSION)
  {
    if (isDouble)
    {
      exp.u.doubleValue = left.u.doubleValue - right.u.doubleValue;
    }
    else
    {
      exp.u.intValue = left.u.intValue - right.u.intValue;
    }
  }

  if (expressionType == MUL_EXPRESSION)
  {
    if (isDouble)
    {
      exp.u.doubleValue = left.u.doubleValue * right.u.doubleValue;
    }
    else
    {
      exp.u.intValue = left.u.intValue * right.u.intValue;
    }
  }

  if (expressionType == DIV_EXPRESSION)
  {
    if (isDouble)
    {
      exp.u.doubleValue = left.u.doubleValue / right.u.doubleValue;
    }
    else
    {
      exp.u.intValue = left.u.intValue / right.u.intValue;
    }
  }

  if (expressionType == MOD_EXPRESSION)
  {
    if (isDouble)
    {
      exp.u.doubleValue = fmod(left.u.doubleValue, right.u.doubleValue);
    }
    else
    {
      exp.u.intValue = left.u.intValue % right.u.intValue;
    }
  }

  return exp;
}
