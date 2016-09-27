#include "includes.h"

void initInterpretador(TipoInterpretador* interpretador)
{
	interpretador->ultimoResultado = 0;
	
	interpretador->lLetras = alloc(TipoLista);
	interpretador->pExpressoes = alloc(TipoPilha);
	interpretador->pOperacoes = alloc(TipoPilha);
	
	initLista(interpretador->lLetras);
	initPilha(interpretador->pExpressoes);
	initPilha(interpretador->pOperacoes);
}

int valida(char letra, int* resultado)
{
	*resultado = 0;
	if(letra == '(' || letra == ')' || (letra >= 'A' && letra <= 'Z') || letra == '+' || letra == '.')
		return 1;
	else if(letra < 'A' || letra > 'Z' && !(letra == '(' || letra == ')' || letra == '+' || letra == '.'))
	{
		*resultado = ERR_BOOL;
	}
	else if(!(letra == '(' || letra == ')') && (letra != '+' || letra != '.'))
	{
		*resultado = ERR_OP;
	}
	else
	{
		*resultado = ERR_SYNTAX;
	}
	return 0;
}

void carregaLetras(TipoInterpretador* interpretador, char* expressao)
{
	TipoItemLista item;
	int i;
	
	for(i = 0; i < strlen(expressao); i++)
	{
		char letra = expressao[i];
		
		if(letra >= 'A' && letra <= 'Z')
		{
			item.Letra = letra;
			
			if(!contem(interpretador->lLetras, item))
			{
				adicionar(interpretador->lLetras, item);
			}
		}
	}
}

int carrega(TipoInterpretador* interpretador, char* expressao)
{	
	int i = 0, resultado;
	for(i = 0; i < strlen(expressao); i++)
	{
		if(!valida(expressao[i], &resultado))
		{
			interpretador->ultimoResultado = resultado;
			return 0;
		}
		else
		{
			switch(expressao[i])
			{
				case '(':
					break;
			}
		}
	}
	
	return 0;
}
