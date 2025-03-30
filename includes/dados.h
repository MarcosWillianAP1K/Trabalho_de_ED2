#include "album.h" // Ensure ALBUM is defined here
#include "musica.h" // Ensure MUSICA is defined here
#include "playlist.h" // Ensure PLAYLIST is defined here
#include "artista.h" // Ensure ARTISTA is defined here
#include "musica_playlist.h" // Ensure MUSICA_PLAYLIST is defined here

#ifndef DADOS_H
#define DADOS_H



typedef union DADOS{
    ARTISTA *artista;
    ALBUM *album;
    MUSICA *musica;
    PLAYLIST *playlist;
    MUSICA_PLAYLIST *musica_playlist;
} DADOS;

DADOS *alocar_dados();

void imprimir_dados_artista(DADOS *dados);

void imprimir_dados_album(DADOS *dados);

void imprimir_dados_musica(DADOS *dados);

void imprimir_dados_playlist(DADOS *dados);

void imprimir_dados_musica_playlist(DADOS *dados);

void liberar_dados(DADOS **dados);

void liberar_dados_artista(DADOS **dados);

void liberar_dados_album(DADOS **dados);

void liberar_dados_musica(DADOS **dados);

void liberar_dados_playlist(DADOS **dados);

void liberar_dados_musica_playlist(DADOS **dados);

int comparar_dados_nome_artista(DADOS *dados1, DADOS *dados2);

int comparar_dados_titulo_album(DADOS *dados1, DADOS *dados2);

int comparar_dados_titulo_musica(DADOS *dados1, DADOS *dados2);

int comparar_dados_nome_playlist(DADOS *dados1, DADOS *dados2);

int comparar_dados_titulo_musica_playlist(DADOS *dados1, DADOS *dados2);

#endif