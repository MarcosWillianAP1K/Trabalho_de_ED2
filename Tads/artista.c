#include "../includes/funcao_sistema.h"
#include "../includes/artista.h"
#include <stdio.h>
#include <stdlib.h>


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


ARTISTA *criar_artista(char *nome, char *tipo, char *estilo_musical, short int numero_albuns, void *raiz){
    ARTISTA *artista = alocar_artista();
    artista->nome = nome;
    artista->tipo = tipo;
    artista->estilo_musical = estilo_musical;
    artista->numero_de_albuns = numero_albuns;
    artista->albuns_raiz_arvore = raiz;
    return artista;
}



ARTISTA *cadastrar_artista()
{
    
    printf("\nDigite o nome do artista: ");
    char *nome = digitar_string();

    printf("\nDigite o tipo do artista: ");
    char *tipo = digitar_string();

    printf("\nDigite o estilo musical do artista: ");
    char *estilo_musical = digitar_string();

    short int numero_albuns = 0;

    
    return criar_artista(nome, tipo, estilo_musical, numero_albuns, NULL);
}

void imprimir_artista(ARTISTA *artista){
    if(artista != NULL){
        printf("\nNome: %s", artista->nome);
        printf("\nTipo: %s", artista->tipo);
        printf("\nEstilo Musical: %s", artista->estilo_musical);
        printf("\nNumero de Albuns: %d", artista->numero_de_albuns);
    }
}

