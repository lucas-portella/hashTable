#include <stdio.h>
#include "hash.h"
#define NODOS 1000
#define TAM_STR 8

int funcao_espalhamento (char* chave) {
	int r = 1;

	for (int i = 0; i < (int) strlen(chave); i++)
		r *= (int) chave[i];
	
	return r % (NODOS / ALPHA);
}

void str_aleatoria (char* str) {
	for (int i = 0; i < (int) strlen(str); i++)
		str[i] = 'a' + rand()%25;
}

int main () {
	hasht *t = iniciaTabela (NODOS, funcao_espalhamento, NULL);
	char str[TAM_STR];
	srand(0);

	for (int i = 0; i < NODOS; i++) {
		str_aleatoria (str);
		insereTabela(t, str, rand());
	}

	destroiTabela(t);
	return 0;
}
