all: decimal2binary hello

decimal2binary: decimal2binary.o stack.o
	gcc -std=c99 -o decimal2binary decimal2binary.o stack.o

decimal2binary.o: decimal2binary.c stack.h bit.h
	gcc -std=c99 -c decimal2binary.c

stack.o: stack.c stack.h bit.h
	gcc -std=c99 -c stack.c

hello: hello.c
	gcc -o hello hello.c

clean: 
	rm decimal2binary decimal2binary.o stack.o hello
