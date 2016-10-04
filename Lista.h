typedef struct ApontadorLista
{
	TipoItemLista item;
	struct ApontadorLista* proximo;
	struct ApontadorLista* anterior;
} TipoApontadorLista;

typedef struct Lista
{
	TipoApontadorLista* primeiro;
	TipoApontadorLista* ultimo;
	
	int tamanho;
} TipoLista;

void initLista(TipoLista *lista);
void adicionar(TipoLista *lista, TipoItemLista item);
int listaVazia(TipoLista lista);
void limpa(TipoLista *lista);
int contem(TipoLista *lista, TipoItemLista item);
