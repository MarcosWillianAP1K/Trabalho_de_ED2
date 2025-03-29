#include "../includes/dados.h"
#include "../includes/funcao_sistema.h"
#include <stdio.h>
#include <stdlib.h>


DADOS *alocar_dados()
{
    DADOS *novo_dados = (DADOS *)malloc(sizeof(DADOS));
    verificar_alocacao(novo_dados);
    return novo_dados;
}

void liberar_dados(DADOS *dados)
{
    if (dados != NULL)
    {
        free(dados);
    }
}