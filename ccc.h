#ifndef PRIVATE_CCC_H_INCLUDED
#define PRIVATE_CCC_H_INCLUDED

#include <stdio.h>

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

struct Expression
{
  ExpressionType type;
  union {
    Boolean booleanValue;
    int intValue;
    double doubleValue;
    char *stringValue;
  } u;
};

struct StatementType
{
  EXPRESSION_STATEMENT = 1,
};

struct Statement
{
  StatementType type;
  union {
    Expression expression;
  } u;
};

struct statementList
{
  Statement statement;
  statementList next;
};

struct Interpreter
{
  StatementList statementList;
};

#endif