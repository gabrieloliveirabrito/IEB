typedef struct Interpretador
{
	char expressao[MAX_EXPR_LEN];	
	int ultimoResultado;
	
	TipoLista* lLetras;
	TipoPilha* pExpressoes;
	TipoPilha* pOperacoes;
} TipoInterpretador;

void initInterpretador(TipoInterpretador* interpretador);
int carrega(TipoInterpretador* interpretador, char* expressao);
int valida(char letra, int* resultado);
