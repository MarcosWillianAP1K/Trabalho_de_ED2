#include "../includes/album.h"
#include "../includes/funcao_sistema.h"
#include <stdio.h>
#include <stdlib.h>


ALBUM *alocar_album()
{
    ALBUM *album = (ALBUM *)malloc(sizeof(ALBUM));
    verificar_alocacao(album);
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

ALBUM *cadastrar_album()
{
    printf("\nDigite o titulo do album: ");
    char *titulo = escrever_string();

    printf("\nDigite data de lancamento do album: ");
    char *data_lancamento = escrever_string();

    printf("\nDigite o numero de musical do artista: ");
    short int numero_de_musicas = 0;
    while (scanf("%hd", &numero_de_musicas) != 1 || numero_de_musicas < 0)
    {
        mensagem_erro("Numero de musicas invalido");
        limpar_buffer();
    }

    return criar_album(titulo, data_lancamento, numero_de_musicas, NULL);
}

void imprimir_album(ALBUM *album)
{
    printf("\nTitulo: %s", album->titulo);
    printf("\nData de Lancamento: %s", album->data_lancamento);
    printf("\nNumero de Musicas: %d", album->numero_de_musicas);
}