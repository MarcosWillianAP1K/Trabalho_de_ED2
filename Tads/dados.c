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

void imprimir_dados_artista(DADOS *dados)
{
    if (dados->artista != NULL)
    {
        imprimir_artista(dados->artista);
    }
}

void imprimir_dados_album(DADOS *dados)
{
    if (dados->album != NULL)
    {
        imprimir_album(dados->album);
    }
}

void imprimir_dados_musica(DADOS *dados)
{
    if (dados->musica != NULL)
    {
        imprimir_musica(dados->musica);
    }
}

void imprimir_dados_playlist(DADOS *dados)
{
    if (dados->playlist != NULL)
    {
        imprimir_playlist(dados->playlist);
    }
}

void imprimir_dados_musica_playlist(DADOS *dados)
{
    if (dados->musica_playlist != NULL)
    {
        imprimir_musica_playlist(dados->musica_playlist);
    }
}



void liberar_dados(DADOS **dados)
{
    if (*dados != NULL)
    {
        free(*dados);
        *dados = NULL;
    }
}

void liberar_dados_artista(DADOS **dados)
{
    if (dados != NULL && *dados != NULL && (*dados)->artista != NULL)
    {
        liberar_artista(&(*dados)->artista);
    }

    liberar_dados(dados);
}

void liberar_dados_album(DADOS **dados)
{
    if (dados != NULL && *dados != NULL && (*dados)->album != NULL)
    {
        liberar_album(&(*dados)->album);
    }

    liberar_dados(dados);
}

void liberar_dados_musica(DADOS **dados)
{
    if (dados != NULL && *dados != NULL && (*dados)->musica != NULL)
    {
        liberar_musica(&(*dados)->musica);
    }

    liberar_dados(dados);
}

void liberar_dados_playlist(DADOS **dados)
{
    if (dados != NULL && *dados != NULL && (*dados)->playlist != NULL)
    {
        liberar_playlist(&(*dados)->playlist);
    }

    liberar_dados(dados);
}

void liberar_dados_musica_playlist(DADOS **dados)
{
    if (dados != NULL && *dados != NULL && (*dados)->musica_playlist != NULL)
    {
        liberar_musica_playlist(&(*dados)->musica_playlist);
    }

    liberar_dados(dados);
}


int comparar_dados_nome_artista(DADOS *dados1, DADOS *dados2)
{
    return comparar_nome_artista(dados1->artista, dados2->artista);
}

int comparar_dados_titulo_album(DADOS *dados1, DADOS *dados2)
{
    return comparar_titulo_album(dados1->album, dados2->album);
}

int comparar_dados_titulo_musica(DADOS *dados1, DADOS *dados2)
{
    return comparar_titulo_musica(dados1->musica, dados2->musica);
}

int comparar_dados_nome_playlist(DADOS *dados1, DADOS *dados2)
{
    return comparar_nome_playlist(dados1->playlist, dados2->playlist);
}


int comparar_dados_musica_playlist(DADOS *dados1, DADOS *dados2)
{
    return comparar_musica_playlist(dados1->musica_playlist, dados2->musica_playlist);
}

