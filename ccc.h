#ifndef PRIVATE_CCC_H_INCLUDED
#define PRIVATE_CCC_H_INCLUDED

#include <stdio.h>

typedef enum {
  CRB_FALSE = 0,
  CRB_TRUE = 1
} CRB_Boolean;

typedef enum {
  INT_EXPRESSION,
  DOUBLE_EXPRESSION,
  ADD_EXPRESSION,
  SUB_EXPRESSION,
  MUL_EXPRESSION,
  DIV_EXPRESSION,
  MOD_EXPRESSION,
  EQ_EXPRESSION,
  NE_EXPRESSION,
  GT_EXPRESSION,
  GE_EXPRESSION,
  LT_EXPRESSION,
  LE_EXPRESSION,
  LOGICAL_AND_EXPRESSION,
  LOGICAL_OR_EXPRESSION,
} ExpressionType;

typedef struct
{
  ExpressionType type;
  union {
    CRB_Boolean booleanValue;
    int intValue;
    double doubleValue;
    char *stringValue;
  } u;
} Expression;

typedef enum {
  EXPRESSION_STATEMENT = 1
} StatementType;

typedef struct
{
  StatementType type;
  union {
    Expression expression;
  } u;
} Statement;

typedef struct StatementList_tag
{
  Statement statement;
  struct StatementList_tag *next;
} StatementList;

typedef struct
{
  StatementList statementList;
} Interpreter;

Expression createBinaryExpression(ExpressionType expressionType,
                                  Expression left,
                                  Expression right);

Expression createIntLiteralExpression(int value);

Expression createDoubleLiteralExpression(double value);

void printExpression(Expression expression);

#endif
