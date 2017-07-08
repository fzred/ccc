#include <stdlib.h>
#include "ccc.h"

void executeExpression(Expression *expression)
{
  printExpression(expression);
}

StatementResult executeStatement(Statement *statement)
{
  StatementResult result;
  result.type = NORMAL_STATEMENT_RESULT;
  switch (statement->type)
  {
  case EXPRESSION_STATEMENT:
    executeExpression(statement->u.expression);
    break;
  }
  return result;
}

StatementResult executeStatementList(StatementList *list)
{
  StatementList *pos;
  StatementResult result;
  result.type = NORMAL_STATEMENT_RESULT;
  for (pos = list; pos; pos = pos->next)
  {
    result = executeStatement(pos->statement);
    if (result.type != NORMAL_STATEMENT_RESULT)
    {
      break;
    }
  }
  return result;
}
