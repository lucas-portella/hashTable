#include "listaligada.h"

nodo* criaNodo (char *chave, void *dado) {
	nodo *novo;
	char *chaveNodo;

	if (!chave || !dado)
		return NULL;

	novo = (nodo*) malloc (sizeof(nodo));
	chaveNodo = (char*) malloc (sizeof(char) * (strlen(chave) + 1));

	if (!novo || !chaveNodo) {
		if (novo)
			free(novo);
		if (chaveNodo)
			free(chaveNodo);
		return NULL;
	}

	novo->chave = chaveNodo;
	strcpy (novo->chave, chave);
	novo->dado = dado;
	
	chaveNodo = NULL;
	return novo;
}

void* destroiNodo (nodo* nodo) {
	void* dado = NULL;

	if (nodo) {
		dado = nodo->dado;
		free(nodo->chave);
		free(nodo);
	}

	return dado;
}

lista* iniciaLista (int (*destroiDado)(void*)) {
	lista* l = (lista*) malloc (sizeof(lista));

	if (!l)
		return NULL;

	l->inicio = NULL;
	l->destroiDado = destroiDado;

	return l;
}

int insereLista (lista* lista, char* chave, void* dado) {
	nodo *novo;

	if (!lista || !dado)
		return ERRO_PARAM;

	novo = criaNodo (chave, dado);

	if (!novo)
		return ERRO_MALLOC;

	novo->prox = lista->inicio;
	lista->inicio = novo;

	return SUCESSO;
}

void* buscaLista (lista *lista, char *chave) {
	nodo *aux;

	if (!lista || !chave)
		return NULL;

	aux = lista->inicio;

	while (aux && strcmp(aux->chave, chave) != 0)
		aux = aux->prox;
	
	return aux->dado;
}

void* removeLista (lista *lista, char *chave) {
	nodo *anterior, *atual;

	if (!lista || !chave)
		return NULL;

	anterior = lista->inicio;
	atual = anterior->prox;
	
	if (strcmp(chave, anterior->chave) == 0) {
		lista->inicio = atual;
		return destroiNodo(anterior);
	}

	while (atual && strcmp(chave, atual->chave) != 0) {
		anterior = atual; 
		atual = atual->prox;
	}

	if (atual) {
		anterior->prox = atual->prox;
		return destroiNodo(atual);
	}

	return NULL;
}

void* removeInicio (lista* lista) {
	nodo* aux = NULL;

	if (!lista)
		return NULL;

	aux = lista->inicio;

	if (aux) 
		lista->inicio = aux->prox;

	return destroiNodo(aux);
}

int destroiLista (lista* lista) {
	void* dado;

	if (!lista) 
		return ERRO_PARAM;

	while (lista->inicio){
		dado = removeInicio (lista);
		if (lista->destroiDado) 
			lista->destroiDado(dado);
	}
	
	free(lista);

	return SUCESSO;
}

int tamanhoLista (lista* lista) {
	int nodos = 0;
	nodo* aux;

	if (!lista)
		return -1;

	aux = lista->inicio;

	while (aux) {
		nodos++;
		aux = aux->prox;
	}

	return nodos;
}
