#ifndef LISTALIGADA_H
#define LISTALIGADA_H

#include <stdlib.h>
#include <string.h>

#define SUCESSO 0
#define ERRO_PARAM 1
#define ERRO_MALLOC 2

typedef struct _nodo {
	struct _nodo *prox;
	char* chave;
	void *dado;
} nodo;

typedef struct _lista {
	nodo *inicio;
	int (*destroiDado)(void*);
} lista;

nodo* criaNodo (char *chave, void* dado);

void* destroiNodo (nodo* nodo);

lista* iniciaLista (int (*destroiDado)(void*));

int insereLista (lista *lista, char *chave, void *dado);

void* buscaLista (lista *lista, char *chave);

void* removeLista (lista *lista, char* chave);

void* removeInicio (lista *lista); 

int destroiLista (lista *lista);

int tamanhoLista (lista *lista);

#endif
