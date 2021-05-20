makefile:

all: unique
unique: unique.o lines.o match.o
	gcc -std=c99 -o unique unique.o lines.o match.o

unique.o: unique.c lines.h
	gcc -std=c99 -c unique.c

lines.o: lines.c lines.h match.h
	gcc -std=c99 -c lines.c

match.o: match.c match.h
	gcc -std=c99 -c match.c
