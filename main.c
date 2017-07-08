#include <stdio.h>
#include <stdlib.h>
#include "ccc.h"

extern int yyparse(void);
extern FILE *yyin;

int main(int argc, char **argv)
{
  FILE *fp;

  if (argc != 2)
  {
    fprintf(stderr, "usage:%s filename\n", argv[0]);
    exit(1);
  }

  fp = fopen(argv[1], "r");
  if (fp == NULL)
  {
    fprintf(stderr, "%s not found.\n", argv[1]);
    exit(1);
  }

  yyin = fp;

  if (yyparse())
  {
    fprintf(stderr, "Error ! Error ! Error !\n");
    exit(1);
  }

  Interpreter *inter = getCurInterpreter();
  executeStatementList(inter->statementList);

  return 0;
}
