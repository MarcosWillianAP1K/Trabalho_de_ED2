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
    musica->titulo_do_album = NULL;
    musica->titulo_do_artista = NULL;

    return musica;
}

void liberar_musica_playlist(MUSICA_PLAYLIST **musica_playlist)
{
    if (*musica_playlist != NULL)
    {
        free((*musica_playlist)->titulo_do_artista);
        free((*musica_playlist)->titulo_do_album);
        // if ((*musica_playlist)->musica != NULL)
        // {
        //     liberar_musica(&(*musica_playlist)->musica);
        // }
        free(*musica_playlist);
        *musica_playlist = NULL;
    }
}

MUSICA_PLAYLIST *criar_musica_playlist(char *titulo_artista, char *titulo_album, MUSICA *musica)
{
    MUSICA_PLAYLIST *musica_playlist = alocar_musica_playlist();

    musica_playlist->titulo_do_artista = titulo_artista;
    musica_playlist->titulo_do_album = titulo_album;
    musica_playlist->musica = musica;

    return musica_playlist;
}

MUSICA_PLAYLIST *cadastrar_musica_playlist(MUSICA *musica)
{
    printf("\nDigite o nome do artista: ");
    char *titulo_artista = digitar_string();

    printf("\nDigite o nome do album: ");
    char *titulo_album = digitar_string();

    return criar_musica_playlist(titulo_artista, titulo_album, musica);
}

void imprimir_musica_playlist(MUSICA_PLAYLIST *musica_playlist)
{
    if (musica_playlist != NULL)
    {
        printf("\nNome do Artista: %s", musica_playlist->titulo_do_artista);
        printf("\nNome do Album: %s", musica_playlist->titulo_do_album);
        imprimir_musica(musica_playlist->musica);
    }
}

int comparar_titulo_artista_musica_playlist(MUSICA_PLAYLIST *musica_playlist1, MUSICA_PLAYLIST *musica_playlist2)
{
    return strcmp(musica_playlist1->titulo_do_artista, musica_playlist2->titulo_do_artista);
}

int comparar_titulo_album_musica_playlist(MUSICA_PLAYLIST *musica_playlist1, MUSICA_PLAYLIST *musica_playlist2)
{
    return strcmp(musica_playlist1->titulo_do_album, musica_playlist2->titulo_do_album);

}

int comparar_titulo_musica_musica_playlist(MUSICA_PLAYLIST *musica_playlist1, MUSICA_PLAYLIST *musica_playlist2)
{
    return comparar_titulo_musica(musica_playlist1->musica, musica_playlist2->musica);
}

int comparar_musica_playlist(MUSICA_PLAYLIST *musica_playlist1, MUSICA_PLAYLIST *musica_playlist2)
{
    int comparacao = 0;

    if (musica_playlist1 != NULL && musica_playlist2 != NULL)
    {
        comparacao = comparar_titulo_artista_musica_playlist(musica_playlist1, musica_playlist2);
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