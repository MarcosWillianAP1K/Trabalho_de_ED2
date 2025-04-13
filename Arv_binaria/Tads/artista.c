#include "../includes/funcao_sistema.h"
#include "../includes/artista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ARTISTA *alocar_artista()
{
    ARTISTA *artista = (ARTISTA *)malloc(sizeof(ARTISTA));

    verificar_alocacao(artista);
    artista->nome = NULL;
    artista->tipo = NULL;
    artista->estilo_musical = NULL;
    artista->numero_de_albuns = 0;
    artista->albuns_raiz_arvore = NULL;

    return artista;
}

void liberar_artista(ARTISTA **artista)
{
    if (*artista != NULL)
    {
        free((*artista)->nome);
        free((*artista)->tipo);
        free((*artista)->estilo_musical);
        free(*artista);
        *artista = NULL;
    }
}

ARTISTA *criar_artista(char *nome, char *tipo, char *estilo_musical, short int numero_albuns, void *raiz)
{
    ARTISTA *artista = alocar_artista();
    artista->nome = nome;
    artista->tipo = tipo;
    artista->estilo_musical = estilo_musical;
    artista->numero_de_albuns = numero_albuns;
    artista->albuns_raiz_arvore = raiz;
    return artista;
}

void imprimir_artista(ARTISTA *artista)
{
    if (artista != NULL)
    {
        printf("\nNome: %s", artista->nome);
        printf("\nTipo: %s", artista->tipo);
        printf("\nEstilo Musical: %s", artista->estilo_musical);
        printf("\nNumero de Albuns: %d\n", artista->numero_de_albuns);
    }
}

int comparar_nome_artista(ARTISTA *artista1, ARTISTA *artista2)
{
    if (artista1 != NULL && artista2 != NULL)
    {
        return strcmp(artista1->nome, artista2->nome);
    }

    // return 0;
}

int comparar_estilo_artista(ARTISTA *artista1, ARTISTA *artista2)
{
    if (artista1 != NULL && artista2 != NULL)
    {
        return strcmp(artista1->estilo_musical, artista2->estilo_musical);
    }

    // return 0;
}

int comparar_tipo_artista(ARTISTA *artista1, ARTISTA *artista2)
{
    if (artista1 != NULL && artista2 != NULL)
    {
        return strcmp(artista1->tipo, artista2->tipo);
    }

    // return 0;
}

int comparar_tipo_e_estilo_artista(ARTISTA *artista1, ARTISTA *artista2)
{
    if (artista1 != NULL && artista2 != NULL)
    {
        int num = 0;

        if ((num = comparar_estilo_artista(artista1, artista2)) == 0)
        {
            num = comparar_tipo_artista(artista1, artista2);
        }

        return num;
        
    }

    return 0;
}

