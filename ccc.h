#ifndef PRIVATE_CCC_H_INCLUDED
#define PRIVATE_CCC_H_INCLUDED

#include <stdio.h>

typedef struct Expression_tag Expression;

typedef enum {
  CCC_FALSE = 0,
  CCC_TRUE = 1
} CCC_Boolean;

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
  IDENTIFIER_EXPRESSION,
  ASSIGN_EXPRESSION
} ExpressionType;

typedef struct
{
  char *variable;
  Expression *operand;
} AssignExpression;

struct Expression_tag
{
  ExpressionType type;
  union {
    CCC_Boolean booleanValue;
    int intValue;
    double doubleValue;
    char *stringValue;
    char *identifier;
    AssignExpression assignExpression;
  } u;
};

typedef enum {
  EXPRESSION_STATEMENT = 1
} StatementType;

typedef enum {
  BOOLEAN_VALUE,
  INT_VALUE,
  DOUBLE_VALUE,
  STRING_VALUE,
  NULL_VALUE
} ValueType;

typedef struct
{
  ValueType type;
  union {
    CCC_Boolean booleanValue;
    int intValue;
    double doubleValue;
    char *stringValue;
  } u;
} Value;

struct Statement_tag
{
  StatementType type;
  union {
    Expression *expression;
  } u;
};

typedef struct Statement_tag Statement;

typedef struct StatementList_tag
{
  Statement *statement;
  struct StatementList_tag *next;
} StatementList;

typedef struct Variable_tag
{
  char *name;
  Value value;
  struct Variable_tag *next;
} Variable;

typedef enum {
  NORMAL_STATEMENT_RESULT = 1,
  RETURN_STATEMENT_RESULT,
  BREAK_STATEMENT_RESULT,
  CONTINUE_STATEMENT_RESULT,
  STATEMENT_RESULT_TYPE_COUNT_PLUS_1
} StatementResultType;

typedef struct
{
  StatementResultType type;
  union {
    Value returnValue;
  } u;
} StatementResult;

typedef struct
{
  Variable *variable;
  StatementList *statementList;
} Interpreter;

Expression createBinaryExpression(ExpressionType expressionType,
                                  Expression left,
                                  Expression right);

Expression createIntLiteralExpression(int value);

Expression createDoubleLiteralExpression(double value);

Expression createAssignExpression(char *variable, Expression *operand);

Statement *createExpressionStatement(Expression expression);

StatementList *chainStatemengList(StatementList *statementList, Statement *statement);

Interpreter *getCurInterpreter();

void interAddStatement(Statement *statement);

void printExpression(Expression *expression);

StatementResult executeStatementList(StatementList *list);

#endif
