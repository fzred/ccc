#include <stdio.h>
#include "ccc.h"

extern Interpreter currentInterter;
extern int yyparse(void);

int main(int argc, char **argv)
{
  if (yyparse())
  {
    fprintf(stderr, "Error ! Error ! Error !\n");
    exit(1);
  }
  return 0;
}
