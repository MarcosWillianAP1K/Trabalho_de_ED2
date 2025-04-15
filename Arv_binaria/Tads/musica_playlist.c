#include "../includes/musica_playlist.h"
#include "../includes/musica.h"
#include "../includes/funcao_sistema.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

MUSICA_PLAYLIST *alocar_musica_playlist()
{
    MUSICA_PLAYLIST *musica = (MUSICA_PLAYLIST *)malloc(sizeof(MUSICA_PLAYLIST));
    verificar_alocacao(musica);

    musica->musica = NULL;
    musica->album = NULL;
    musica->artista = NULL;

    return musica;
}

void liberar_musica_playlist(MUSICA_PLAYLIST **musica_playlist)
{
    if (*musica_playlist != NULL)
    {
        free(*musica_playlist);
        *musica_playlist = NULL;
    }
}

MUSICA_PLAYLIST *criar_musica_playlist(ARTISTA *artista, ALBUM *album, MUSICA *musica)
{
    MUSICA_PLAYLIST *musica_playlist = alocar_musica_playlist();

    musica_playlist->artista = artista;
    musica_playlist->album = album;
    musica_playlist->musica = musica;

    return musica_playlist;
}


void imprimir_musica_playlist(MUSICA_PLAYLIST *musica_playlist)
{
    if (musica_playlist != NULL)
    {
        printf("\nNome do Artista: %s", musica_playlist->artista->nome);
        printf("\nTitulo do Album: %s", musica_playlist->album->titulo);
        imprimir_musica(musica_playlist->musica);
    }
}

int comparar_nome_artista_musica_playlist(MUSICA_PLAYLIST *musica_playlist1, MUSICA_PLAYLIST *musica_playlist2)
{
    return comparar_nome_artista(musica_playlist1->artista, musica_playlist2->artista);
}

int comparar_titulo_album_musica_playlist(MUSICA_PLAYLIST *musica_playlist1, MUSICA_PLAYLIST *musica_playlist2)
{
    return comparar_titulo_album(musica_playlist1->album, musica_playlist2->album);

}

int comparar_titulo_musica_musica_playlist(MUSICA_PLAYLIST *musica_playlist1, MUSICA_PLAYLIST *musica_playlist2)
{
    return comparar_titulo_musica(musica_playlist1->musica, musica_playlist2->musica);
}

int comparar_musica_playlist(MUSICA_PLAYLIST *musica_playlist1, MUSICA_PLAYLIST *musica_playlist2)
{
    int comparacao = -2;

    if (musica_playlist1 != NULL && musica_playlist2 != NULL)
    {
        comparacao = comparar_nome_artista_musica_playlist(musica_playlist1, musica_playlist2);
        if (comparacao == 0)
        {
            comparacao = comparar_titulo_album_musica_playlist(musica_playlist1, musica_playlist2);
            if (comparacao == 0 && musica_playlist1->musica != NULL && musica_playlist2->musica != NULL)
            {
                comparacao = comparar_titulo_musica_musica_playlist(musica_playlist1, musica_playlist2);
            }
        }
    }

    return comparacao;
    
}