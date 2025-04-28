#include <stdio.h>
#include "listaligada.h"

int main () {
	int vetor[] = {1,2,3,4,5};
	char* chaves[] = {"lucas", "fernanda", "leticia", "rafinha", "lorete"};
	int* dado;
	char c;
	lista* l;

	l = iniciaLista (NULL);	

	if (!l)
		printf("Erro ao inicializar\n");
	
	printf("Insercao na lista ligada:\n");
	for (int i = 0; i < 5; i++) {
		if (insereLista(l, chaves[i], &vetor[i]) == SUCESSO) {
			printf("Insercao %d:\n", i);
			printf("\t%s => %d\n", chaves[i], vetor[i]);
		}
	}	
	printf("Fim da insercao. Digite qualquer tecla para continuar.");
	c = getchar ();

	printf("Remocao da lista ligada por chave:\n");
	for (int i = 0; i < 5; i++) {
		dado = removeLista (l, chaves[i]);	
		printf("Removido:\n");
		printf("\tChave \"%s\" => %d\n", chaves[i], *dado);
	}	
	printf("Fim da remocao. Digite qualquer tecla para continuar.");
	c = getchar ();

	destroiLista (l);
	l = NULL;
	
	return 0;
}
