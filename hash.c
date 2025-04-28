#include "hash.h"

hasht* iniciaTabela (int nodos, int (*funcao_espalhamento)(char*), int (*destroiDado)(void*)) {
	hasht* tabela;
	int status = SUCESSO, i = 0, j = 0;
	
	if (nodos <= 0)
		return NULL;

	tabela = (hasht*) malloc (sizeof(hasht));

	if (!tabela)
		return NULL;
	
	tabela->buckets = nodos / ALPHA;
	tabela->funcao_espalhamento = funcao_espalhamento;
	tabela->destroiDado = destroiDado;

	tabela->tabela = (lista**) malloc (tabela->buckets * sizeof(lista));
	if (!tabela->tabela)
		status = ERRO_MALLOC;

	while (i < tabela->buckets && status == SUCESSO) {
		tabela->tabela[i] = iniciaLista (destroiDado);
		if (!tabela->tabela[i])
			status = ERRO_MALLOC;
		i++;
	}	
	
	if (status == SUCESSO)
		return tabela;
	
	while (j < i) {
		destroiLista (tabela->tabela[j]);
		tabela->tabela[j] = NULL;
		j++;
	}
	tabela->funcao_espalhamento = NULL;
	tabela->destroiDado = NULL;
	free(tabela->tabela);
	free(tabela);
	tabela = NULL;

	return NULL;
}

int insereTabela (hasht* tabela, char* chave, void* dado) {
	int pos;

	if (!tabela || !chave || !dado)
		return ERRO_PARAM;
	
	pos = tabela->funcao_espalhamento(chave);
	return insereLista(tabela->tabela[pos], chave, dado);			
}

void* removeTabela (hasht* tabela, char* chave) {
	int pos;

	if (!tabela || !chave)
		return NULL;

	pos = tabela->funcao_espalhamento(chave);
	return removeLista(tabela->tabela[pos], chave);
}

void* buscaTabela (hasht* tabela, char* chave) {
	int pos;

	if (!tabela || !chave)
		return NULL;
	
	pos = tabela->funcao_espalhamento(chave);
	return buscaLista (tabela->tabela[pos], chave);	
}

int destroiTabela (hasht* tabela) {
	if (!tabela)
		return ERRO_PARAM;

	for (int i = 0; i < tabela->buckets; i++) {
		destroiLista (tabela->tabela[i]);
		tabela->tabela[i] = NULL;	
	}	

	tabela->funcao_espalhamento = NULL;
	tabela->destroiDado = NULL;
	free(tabela->tabela);
	tabela->tabela = NULL;
	free(tabela);

	return SUCESSO;
}

int fator_carregamento (hasht* t) {
	int nodos = 0;
	int buckets;

	if (!t)
		return -1;
	
	buckets = t->buckets;
	for (int i = 0; i < buckets; i++) {
		nodos += tamanhoLista (t->tabela[i]);
	}

	return nodos / buckets;
}

