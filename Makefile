CC = gcc
FLAGS = -Wall -Wextra

all: testahash.o listaligada.o hash.o
	$(CC) $(FLAGS) testahash.o listaligada.o hash.o -o testahash
	if [ -f testahash ]; then valgrind ./testahash; fi

testalista: testalista.o listaligada.o
	$(CC) $(FLAGS) testalista.o listaligada.o -o testalista
	if [ -f testalista ]; then valgrind ./testalista; fi

testalista.o: testalista.c
	$(CC) $(FLAGS) -c testalista.c

testahash.o: testahash.c
	$(CC) $(FLAGS) -c testahash.c

listaligada.o: listaligada.c listaligada.h
	$(CC) $(FLAGS) -c listaligada.c

hash.o: hash.c hash.h listaligada.o
	$(CC) $(FLAGS) -c hash.c

clean:
	rm -f *.o

purge: clean
	rm -f testahash testalista
