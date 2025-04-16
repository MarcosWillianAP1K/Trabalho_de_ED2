

#ifndef PLAYLIST_H
#define PLAYLIST_H




typedef struct PLAYLIST
{
    char *nome;
    short int numero_de_musicas;
    void *musicas_raiz_arvore;
} PLAYLIST;

PLAYLIST *alocar_playlist();

void liberar_playlist(PLAYLIST **playlist);

PLAYLIST *criar_playlist(char *nome, short int numero_de_musicas, void *raiz);

void imprimir_playlist(PLAYLIST *playlist);

int comparar_nome_playlist(PLAYLIST *playlist1, PLAYLIST *playlist2);

#endif