#include <stdio.h>
#include "hash.h"
#define NODOS 1000
#define TAM_STR 8

int funcao_espalhamento (char* chave) {
	int r = 1;

	for (int i = 0; i < (int) strlen(chave); i++) {
		if (r * (int) chave[i] > 0)
			r *= (int) chave[i];
	}
	
	return r % (NODOS / ALPHA);
}

void str_aleatoria (char* str) {
	for (int i = 0; i < (int) strlen(str); i++)
		str[i] = 'a' + rand()%25;
}

int destroi_inteiro (int* i) {
	if (i)
		free(i);
	return 0;
}

int main () {
	hasht *t = iniciaTabela (NODOS, funcao_espalhamento, destroi_inteiro);
	int *n;
	char str[TAM_STR];
	int pos;
	srand(0);

	// inicializacao da string 'chave'
	strcpy (str, "1234567");

	for (int i = 0; i < NODOS; i++) {
		n = (int*) malloc (sizeof(int));
		if (n) {
			*n = rand();
			str_aleatoria (str);
			pos = funcao_espalhamento(str);
			if (pos > NODOS / ALPHA)
				printf("Erro na funcao de espalhamento\n");
			insereTabela (t, str, n);
		}
	}

	printf("Fator de carregamento da tabela: %d\n", fator_carregamento(t));
	
	destroiTabela(t);
	return 0;
}
