#include <stdio.h>
#include <stdlib.h>
#include "includes.h"

main() 
{
	TipoInterpretador interpretador;		
	initInterpretador(&interpretador);
	
	char expressao[MAX_EXPR_LEN];
	printf("Insira a expressao a ser interpretada: ");
	scanf("%s", &expressao);
	
	carregaLetras(&interpretador, expressao);
	
	TipoApontadorLista *apontador = interpretador.lLetras->primeiro;
	while((apontador = apontador->proximo) != NULL)
	{
		printf("Insira o valor da entrada de %c: ", apontador->item.Letra);
		scanf("%d", &apontador->item.Valor);
	}
	
	/*if(carrega(&interpretador, "0+1"))
	{
		printf("Carregado com sucesso!\n");
	}
	else
	{
		printf("ERRO(%d): ", interpretador.ultimoResultado);
		switch(interpretador.ultimoResultado)
		{
			case 1:
				printf("Erro na sintaxe!\n");
				break;
			case 2:
				printf("Operador invalido!\n");
				break;
			case 3:
				printf("Valor booleano invalido!\n");
				break;
			default:
				printf("Erro desconhecido!\n");
				break;
		}
		printf("Falha ao carregar a expressao!\n");
	}*/
	
	system("PAUSE");
}
