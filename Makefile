all: main.c
	gcc -O0 -Wall main.c -lm
	./a.out
