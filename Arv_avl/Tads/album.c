#include "../includes/album.h"
#include "../includes/funcao_sistema.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


ALBUM *alocar_album()
{
    ALBUM *album = (ALBUM *)malloc(sizeof(ALBUM));
    verificar_alocacao(album);
    album->titulo = NULL;
    album->data_lancamento = 0;
    album->numero_de_musicas = 0;
    album->musicas_raiz_arvore = NULL;
    return album;
}

void liberar_album(ALBUM **album)
{
    if (*album != NULL)
    {
        free((*album)->titulo);
        free(*album);
        *album = NULL;
    }
}

ALBUM *criar_album(char *titulo, short int data_lancamento, short int numero_de_musicas, void *raiz)
{
    ALBUM *album = alocar_album();
    album->titulo = titulo;
    album->data_lancamento = data_lancamento;
    album->numero_de_musicas = numero_de_musicas;
    album->musicas_raiz_arvore = raiz;

    return album;
}


void imprimir_album(ALBUM *album)
{
    if(album != NULL)
    {
        printf("\nTitulo: %s", album->titulo);
        printf("\nAno de lancamento: %04hd", album->data_lancamento);
        printf("\nNumero de musicas: %hd\n", album->numero_de_musicas);
    }
}


int comparar_titulo_album(ALBUM *album1, ALBUM *album2)
{
    if (album1 != NULL && album2 != NULL)
    {
        return strcmp(album1->titulo, album2->titulo);
    }
    
    return -2;
}

int comparar_data_album(ALBUM *album1, ALBUM *album2)
{
    int retorno = 0;

    if (album1 != NULL && album2 != NULL)
    {
        if (album1->data_lancamento > album2->data_lancamento)
        {
            retorno = 1;
        }
        else if (album1->data_lancamento < album2->data_lancamento)
        {
            retorno = -1;
        }
    }
    
    return retorno;
}

int comparar_titulo_ano_album(ALBUM *album1, ALBUM *album2)
{
    int retorno = comparar_titulo_album(album1, album2);
    
    if (retorno == 0)
    {
        retorno = comparar_data_album(album1, album2);
    }
    
    return retorno;
}

