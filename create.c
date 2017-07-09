#include <stdlib.h>
#include <math.h>
#include "ccc.h"

Expression *createIntLiteralExpression(int value)
{
  Expression *exp;
  exp = (Expression*)malloc(sizeof(Expression));
  exp->type = INT_EXPRESSION;
  exp->u.intValue = value;
  return exp;
}

Expression *createDoubleLiteralExpression(double value)
{
  Expression *exp;
  exp = (Expression*)malloc(sizeof(Expression));
  exp->type = DOUBLE_EXPRESSION;
  exp->u.doubleValue = value;
  return exp;
}

Expression *createBinaryExpression(ExpressionType expressionType,
                                  Expression *left,
                                  Expression *right)
{
  Expression *exp;
  exp = (Expression*)malloc(sizeof(Expression));
  int isDouble = 0;
  if ((left->type == INT_EXPRESSION || left->type == DOUBLE_EXPRESSION) &&
      (right->type == INT_EXPRESSION || right->type == DOUBLE_EXPRESSION))
  {
    if (left->type == DOUBLE_EXPRESSION || right->type == DOUBLE_EXPRESSION)
    {
      isDouble = 1;
    }
  }

  if (isDouble)
  {
    exp->type = DOUBLE_EXPRESSION;
  }
  else
  {
    exp->type = INT_EXPRESSION;
  }

  if (expressionType == ADD_EXPRESSION)
  {
    if (isDouble)
    {
      exp->u.doubleValue = left->u.doubleValue + right->u.doubleValue;
    }
    else
    {
      exp->u.intValue = left->u.intValue + right->u.intValue;
    }
  }

  if (expressionType == SUB_EXPRESSION)
  {
    if (isDouble)
    {
      exp->u.doubleValue = left->u.doubleValue - right->u.doubleValue;
    }
    else
    {
      exp->u.intValue = left->u.intValue - right->u.intValue;
    }
  }

  if (expressionType == MUL_EXPRESSION)
  {
    if (isDouble)
    {
      exp->u.doubleValue = left->u.doubleValue * right->u.doubleValue;
    }
    else
    {
      exp->u.intValue = left->u.intValue * right->u.intValue;
    }
  }

  if (expressionType == DIV_EXPRESSION)
  {
    if (isDouble)
    {
      exp->u.doubleValue = left->u.doubleValue / right->u.doubleValue;
    }
    else
    {
      exp->u.intValue = left->u.intValue / right->u.intValue;
    }
  }

  if (expressionType == MOD_EXPRESSION)
  {
    if (isDouble)
    {
      exp->u.doubleValue = fmod(left->u.doubleValue, right->u.doubleValue);
    }
    else
    {
      exp->u.intValue = left->u.intValue % right->u.intValue;
    }
  }

  return exp;
}

Expression *createAssignExpression(char *variable, Expression *operand)
{
  Expression *exp;
  exp = (Expression*)malloc(sizeof(Expression));
  exp->type = ASSIGN_EXPRESSION;
  exp->u.assignExpression = (AssignExpression*)malloc(sizeof(AssignExpression));
  exp->u.assignExpression->variable = variable;
  exp->u.assignExpression->operand = operand;
  return exp;
}

Statement *createExpressionStatement(Expression *expression)
{
  Statement *statement;
  statement = (Statement *)malloc(sizeof(Statement));
  statement->type = EXPRESSION_STATEMENT;
  statement->u.expression = expression;
  return statement;
}

StatementList *createStatamentList(Statement *statement)
{
  StatementList *list;
  list = (StatementList *)malloc(sizeof(StatementList));
  list->statement = statement;
  list->next = NULL;
  return list;
}

StatementList *chainStatemengList(StatementList *statementList, Statement *statement)
{
  if (statementList == NULL)
  {
    StatementList *list;
    list = createStatamentList(statement);
    return list;
  }
  StatementList *pos;
  for (pos = statementList; pos->next; pos = pos->next)
    ;

  pos->next = createStatamentList(statement);

  return statementList;
}

void interAddStatement(Statement *statement)
{
  Interpreter *inter;
  inter = getCurInterpreter();
  StatementList *list;
  list = chainStatemengList(inter->statementList, statement);
  inter->statementList = list;
}
