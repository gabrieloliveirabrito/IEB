typedef struct Apontador
{
	TipoItemPilha ItemPilha;
	
	struct Apontador* anterior;
	struct Apontador* proximo;
} TipoApontador;

typedef struct Pilha
{
	TipoApontador *primeiro;
	TipoApontador *ultimo;
	
	int tamanho;
} TipoPilha;

void initPilha(TipoPilha* pilha);
int pilhaVazia(TipoPilha pilha);
void empilha(TipoPilha* pilha, TipoItemPilha ItemPilha);
void desempilha(TipoPilha* pilha, TipoItemPilha *ItemPilha);
