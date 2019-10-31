ifeq ($(DEBUG),true)
	CC = gcc -g
else
	CC = gcc
endif

all: main.o node.o library.o
	$(CC) -o myTunes main.o node.o library.o
test: testLinkedList.o node.o
	$(CC) -o myTunes testLinkedList.o node.o
testLinkedList.o: testLinkedList.c node.h
	$(CC) -c testLinkedList.c
main.o: main.c node.h library.h
	$(CC) -c main.c
library.o: library.c library.h node.h
	$(CC) -c library.c
node.o: node.c node.h
	$(CC) -c node.c
run:
	./myTunes
memcheck:
	valgrind --leak-check=yes ./myTunes
