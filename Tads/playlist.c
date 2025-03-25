#include "../includes/playlist.h"
#include "../includes/funcao_sistema.h"
#include <stdio.h>
#include <stdlib.h>

PLAYLIST *alocar_playlist()
{
    PLAYLIST *playlist = (PLAYLIST *)malloc(sizeof(PLAYLIST));

    verificar_alocacao(playlist);

    return playlist;
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
    char *nome = escrever_string();

    printf("\nDigite o numero de musicas da playlist: ");
    short int numero_de_musicas = 0;
    while (scanf("%hd", &numero_de_musicas) != 1 || numero_de_musicas < 0)
    {
        mensagem_erro("Numero de musicas invalido");
        limpar_buffer();
    }

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
