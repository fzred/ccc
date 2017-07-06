#include "ccc.h"

Expression createIntLiteralExpression(int value)
{
  Expression exp;
  exp.type = INT_EXPRESSION;
  exp.intValue = value;
  return exp;
}

Expression createDoubleLiteralExpression(int value)
{
  Expression exp;
  exp.type = DOUBLE_EXPRESSION;
  exp.doubleValue = value;
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
      exp.doubleValue = left.doubleValue + right.doubleValue;
    }
    else
    {
      exp.intValue = left.intValue + right.intValue;
    }
  }

  if (expressionType == SUB_EXPRESSION)
  {
    if (isDouble)
    {
      exp.doubleValue = left.doubleValue - right.doubleValue;
    }
    else
    {
      exp.intValue = left.intValue - right.intValue;
    }
  }

  if (expressionType == MUL_EXPRESSION)
  {
    if (isDouble)
    {
      exp.doubleValue = left.doubleValue * right.doubleValue;
    }
    else
    {
      exp.intValue = left.intValue * right.intValue;
    }
  }

  if (expressionType == DIV_EXPRESSION)
  {
    if (isDouble)
    {
      exp.doubleValue = left.doubleValue / right.doubleValue;
    }
    else
    {
      exp.intValue = left.intValue / right.intValue;
    }
  }

  if (expressionType == MOD_EXPRESSION)
  {
    if (isDouble)
    {
      exp.doubleValue = left.doubleValue % right.doubleValue;
    }
    else
    {
      exp.intValue = left.intValue % right.intValue;
    }
  }

  return exp;
}
