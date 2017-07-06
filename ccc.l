%{
  int yywrap(void)
  {
    return 1;
  }
%}
%%
<INITIAL>"("            return LP;
<INITIAL>")"            return RP;
<INITIAL>"{"            return LC;
<INITIAL>"}"            return RC;
<INITIAL>"&&"           return LOGICAL_AND;
<INITIAL>"||"           return LOGICAL_OR;
<INITIAL>"="            return ASSIGN;
<INITIAL>"=="           return EQ;
<INITIAL>"!="           return NE;
<INITIAL>">"            return GT;
<INITIAL>">="           return GE;
<INITIAL>"<"            return LT;
<INITIAL>"<="           return LE;
<INITIAL>"+"            return ADD;
<INITIAL>"-"            return SUB;
<INITIAL>"*"            return MUL;
<INITIAL>"/"            return DIV;
<INITIAL>"%"            return MOD;
<INITIAL>"\n"           return CR;

<INITIAL>([1-9][0-9]*)|"0" {
  return INT_LITERAL;
}
<INITIAL>[0-9]+\.[0-9]+ {
  return DOUBLE_LITERAL;
}
%%