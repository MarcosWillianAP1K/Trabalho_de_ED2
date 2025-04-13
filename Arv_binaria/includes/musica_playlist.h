
#ifndef MUSICA_PLAYLIST_H
#define MUSICA_PLAYLIST_H

#include "musica.h"

typedef struct MUSICA_PLAYLIST{
    char *titulo_do_artista;
    char *titulo_do_album;
    MUSICA *musica;
    
} MUSICA_PLAYLIST;


MUSICA_PLAYLIST *alocar_musica_playlist();

void liberar_musica_playlist(MUSICA_PLAYLIST **musica_playlist);

MUSICA_PLAYLIST *criar_musica_playlist(char *titulo_artista, char *titulo_album, MUSICA *musica);

void imprimir_musica_playlist(MUSICA_PLAYLIST *musica_playlist);

int comparar_titulo_artista_musica_playlist(MUSICA_PLAYLIST *musica_playlist1, MUSICA_PLAYLIST *musica_playlist2);

int comparar_titulo_album_musica_playlist(MUSICA_PLAYLIST *musica_playlist1, MUSICA_PLAYLIST *musica_playlist2);

int comparar_titulo_musica_musica_playlist(MUSICA_PLAYLIST *musica_playlist1, MUSICA_PLAYLIST *musica_playlist2);

int comparar_musica_playlist(MUSICA_PLAYLIST *musica_playlist1, MUSICA_PLAYLIST *musica_playlist2);

#endif