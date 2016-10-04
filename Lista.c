#include "includes.h"

void initLista(TipoLista *lista)
{
	lista->tamanho = 0;
	
	lista->primeiro = allocN(TipoApontadorLista, struct ApontadorLista);
	lista->ultimo = lista->primeiro;
	
	lista->primeiro->anterior = NULL;
	lista->ultimo->proximo = NULL;
}

void adicionar(TipoLista *lista, TipoItemLista item)
{
	lista->ultimo->proximo = allocN(TipoApontadorLista, struct ApontadorLista);
	lista->ultimo->proximo->anterior = lista->ultimo;
	lista->ultimo = lista->ultimo->proximo;
	
	lista->ultimo->item = item;
	lista->ultimo->proximo = NULL;
	lista->tamanho++;
}

int listaVazia(TipoLista lista)
{
	return (lista.primeiro == lista.ultimo);
}

void limpa(TipoLista *lista)
{
	lista->primeiro->proximo = NULL;
	lista->ultimo = lista->primeiro;
	lista->tamanho = 0;
}

int contem(TipoLista *lista, TipoItemLista item)
{
	if(!listaVazia(*lista))
	{
		TipoApontadorLista *apontador = lista->primeiro;
		while((apontador = apontador->proximo) != NULL)
		{
			if(apontador->item.Letra == item.Letra)
			{
				return 1;
			}
		}
	}
	return 0;
}
