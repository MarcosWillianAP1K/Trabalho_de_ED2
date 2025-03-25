#include "../includes/album.h"
#include "../includes/funcao_sistema.h"
#include <stdio.h>
#include <stdlib.h>


ALBUM *alocar_album()
{
    ALBUM *album = (ALBUM *)malloc(sizeof(ALBUM));
    verificar_alocacao(album);
    album->titulo = NULL;
    album->data_lancamento = NULL;
    album->numero_de_musicas = 0;
    album->musicas_raiz_arvore = NULL;
    return album;
}

ALBUM *criar_album(char *titulo, char *data_lancamento, short int numero_de_musicas, void *raiz)
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
        printf("\nData de lancamento: %s", album->data_lancamento);
        printf("\nNumero de musicas: %hd", album->numero_de_musicas);
    }
}