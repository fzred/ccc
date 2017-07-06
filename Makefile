TARGET = ccc
CC = gcc
OBJS = y.tab.h y.tab.c lex.yy.c util.c main.c create.c ccc.h


$(TARGET) : $(OBJS)
	$(CC) $(OBJS)

clean :
	rm -f *.o lex.yy.c y.tab.c y.tab.h
y.tab.h : ccc.y
	bison --yacc -dv ccc.y
y.tab.c : ccc.y
	bison --yacc -dv ccc.y
lex.yy.c : ccc.l ccc.y y.tab.h
	flex ccc.l
