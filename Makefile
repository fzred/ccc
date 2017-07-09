TARGET = ccc
CC = gcc
OBJS = lex.yy.o y.tab.o util.c main.c create.c ccc.h execute.c eval.c

CFLAGS = -c -g -Wall -Wswitch-enum -ansi -pedantic -DDEBUG
INCLUDES = \

$(TARGET) : $(OBJS)
	$(CC) -g $(OBJS)

clean :
	rm -f *.o lex.yy.c y.tab.c y.tab.h
y.tab.h : ccc.y
	bison --yacc -dv ccc.y
y.tab.c : ccc.y
	bison --yacc -dv ccc.y
lex.yy.c : ccc.l ccc.y y.tab.h
	flex ccc.l
y.tab.o: y.tab.c ccc.h
	$(CC) -c -g $*.c $(INCLUDES)
lex.yy.o: lex.yy.c ccc.h
	$(CC) -c -g $*.c $(INCLUDES)
.c.o:
	$(CC) $(CFLAGS) $*.c $(INCLUDES)