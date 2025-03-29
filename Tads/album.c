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

void liberar_album(ALBUM *album)
{
    if (album != NULL)
    {
        free(album->titulo);
        free(album->data_lancamento);
        free(album);
    }
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

ALBUM *cadastrar_album()
{
    printf("\nDigite o titulo do album: ");
    char *titulo = digitar_string();

    printf("\nDigite data de lancamento do album: ");
    char *data_lancamento = digitar_string();

    printf("\nDigite o numero de musical do artista: ");
    short int numero_de_musicas = digitar_short_int();
    

    return criar_album(titulo, data_lancamento, numero_de_musicas, NULL);
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

