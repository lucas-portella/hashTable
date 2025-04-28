#ifndef HASH_H
#define HASH_H

#include "listaligada.h"
#define ALPHA 2 			// alpha = nodos / buckets

typedef struct _hasht {
	int buckets;
	lista** tabela;
	int (*funcao_espalhamento)(char*);
	int (*destroiDado)(void*);
} hasht;

hasht* iniciaTabela (int nodos, int (*funcao_espalhamento)(char*), int (*funcao_desaloc_mem)(void*));

int insereTabela (hasht* tabela, char* chave, void* dado);

void* removeTabela (hasht* tabela, char* chave);

void* buscaTabela (hasht* tabela, char* chave);

int destroiTabela (hasht* tabela);

#endif
