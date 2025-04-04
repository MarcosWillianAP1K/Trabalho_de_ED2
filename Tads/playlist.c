#include "../includes/playlist.h"
#include "../includes/funcao_sistema.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

PLAYLIST *alocar_playlist()
{
    PLAYLIST *playlist = (PLAYLIST *)malloc(sizeof(PLAYLIST));

    verificar_alocacao(playlist);

    return playlist;
}

void liberar_playlist(PLAYLIST **playlist)
{
    if (*playlist != NULL)
    {
        free((*playlist)->nome);
        free(*playlist);
        *playlist = NULL;
    }
}

PLAYLIST *criar_playlist(char *nome, short int numero_de_musicas, void *raiz)
{
    PLAYLIST *playlist = alocar_playlist();
    playlist->nome = nome;
    playlist->numero_de_musicas = numero_de_musicas;
    playlist->musicas_raiz_arvore = raiz;

    return playlist;
}

PLAYLIST *cadastrar_playlist()
{
    printf("\nDigite o nome da playlist: ");
    char *nome = digitar_string();

    printf("\nDigite o numero de musicas da playlist: ");
    short int numero_de_musicas = digitar_short_int();

    return criar_playlist(nome, numero_de_musicas, NULL);
}

void imprimir_playlist(PLAYLIST *playlist)
{
    if (playlist != NULL)
    {
        printf("\nNome: %s", playlist->nome);
        printf("\nNumero de Musicas: %d", playlist->numero_de_musicas);
    }
}

int comparar_nome_playlist(PLAYLIST *playlist1, PLAYLIST *playlist2)
{
    return strcmp(playlist1->nome, playlist2->nome);
}