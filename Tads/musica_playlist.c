#include "../includes/musica_playlist.h"
#include "../includes/funcao_sistema.h"
#include <stdio.h>
#include <stdlib.h>

MUSICA_PLAYLIST *alocar_musica_playlist()
{
    MUSICA_PLAYLIST *musica = (MUSICA_PLAYLIST *)malloc(sizeof(MUSICA_PLAYLIST));
    verificar_alocacao(musica);

    musica->musica = NULL;
    musica->titulo_do_album = NULL;
    musica->titulo_do_artista = NULL;

    return musica;
}

void liberar_musica_playlist(MUSICA_PLAYLIST *musica_playlist)
{
    if (musica_playlist != NULL)
    {
        free(musica_playlist->titulo_do_artista);
        free(musica_playlist->titulo_do_album);
        liberar_musica(musica_playlist->musica);
        free(musica_playlist);
    }
}

MUSICA_PLAYLIST *criar_musica_playlist(char *titulo_artista, char *titulo_album, MUSICA *musica)
{
    MUSICA_PLAYLIST *musica_playlist = alocar_musica();

    musica_playlist->titulo_do_artista = titulo_artista;
    musica_playlist->titulo_do_album = titulo_album;
    musica_playlist->musica = musica;

    return musica_playlist;
}

MUSICA_PLAYLIST *cadastrar_musica_playlist()
{
    printf("\nDigite o nome do artista: ");
    char *titulo_artista = digitar_string();

    printf("\nDigite o nome do album: ");
    char *titulo_album = digitar_string();

    MUSICA *musica = cadastrar_musica();

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
