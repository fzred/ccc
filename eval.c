#include <stdlib.h>
#include <string.h>
#include "ccc.h"

Variable *searchGlobalVariable(Interpreter *inter, char *name)
{
  Variable *variable;
  for (variable = inter->variable; variable; variable = variable->next)
  {
    if (strcmp(variable->name, name))
    {
      return variable;
    }
  }
  return NULL;
}

Value evalAssignExpression(Expression *expression)
{
  Value v;
  Interpreter *inter;
  AssignExpression *aexp;
  inter = getCurInterpreter();
  aexp = expression->u.assignExpression;
  Variable *variable;
  variable = searchGlobalVariable(inter, aexp->variable);

  // 解析求值表达式
  switch (aexp->operand->type)
  {
  case INT_EXPRESSION:
    v.type = INT_VALUE;
    v.u.intValue = aexp->operand->u.intValue;
    break;
  case DOUBLE_EXPRESSION:
    v.type = DOUBLE_VALUE;
    v.u.intValue = aexp->operand->u.doubleValue;
    break;
  default:
    break;
  }

  if (variable == NULL)
  {
    variable = (Variable *)malloc(sizeof(Variable));
    variable->name = aexp->variable;
    variable->value = v;
    variable->next = NULL;
    if (inter->variable != NULL)
    {
      Variable *pos;
      for (pos = inter->variable; pos->next; pos = pos->next)
        ;
      pos->next = variable;
    }
  }
  else
  {
    variable->value = v;
  }

  if (inter->variable == NULL)
  {
    inter->variable = variable;
  }
  printf("声明变量%s\n", aexp->variable);
  return v;
}
