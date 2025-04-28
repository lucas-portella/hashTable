CC = gcc
FLAGS = -Wall -Wextra

all: main.o listaligada.o hash.o
	$(CC) $(FLAGS) main.o listaligada.o hash.o -o main

main.o: main.c
	$(CC) $(FLAGS) -c main.c

listaligada.o: listaligada.c listaligada.h
	$(CC) $(FLAGS) -c listaligada.c

hash.o: hash.c hash.h listaligada.o
	$(CC) $(FLAGS) -c hash.c

clean:
	rm *.o

purge: clean
	rm -f main
