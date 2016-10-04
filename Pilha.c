#include "includes.h"

void initPilha(TipoPilha* pilha)
{
	pilha->tamanho = 0;
	pilha->primeiro = allocN(TipoApontador, struct Apontador);
	pilha->primeiro->anterior = NULL;
	pilha->primeiro->proximo = NULL;
	pilha->ultimo = pilha->primeiro;
}

int pilhaVazia(TipoPilha pilha)
{
	return !pilha.tamanho;
}

void empilha(TipoPilha* pilha, TipoItemPilha ItemPilha)
{
	TipoApontador* apontador = allocN(TipoApontador, struct Apontador);
	apontador->ItemPilha = ItemPilha;
	apontador->proximo = NULL;
	apontador->anterior = pilha->ultimo;
	
	pilha->ultimo->proximo = apontador;
	pilha->ultimo = apontador;
	pilha->tamanho++;
}

void desempilha(TipoPilha* pilha, TipoItemPilha *ItemPilha)
{
	if(!pilhaVazia(*pilha))
	{
		*ItemPilha = pilha->ultimo->ItemPilha;
		pilha->ultimo = pilha->ultimo->anterior;
		pilha->ultimo->proximo = NULL;
		
		pilha->tamanho--;
	}
}
