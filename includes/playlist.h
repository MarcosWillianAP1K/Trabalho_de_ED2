

#ifndef PLAYLIST_H
#define PLAYLIST_H


typedef struct PLAYLIST
{
    char *nome;
    short int numero_de_musicas;
    void *musicas_raiz_arvore;
} PLAYLIST;


#endif