




#ifndef ALBUM_H
#define ALBUM_H




typedef struct ALBUM{
    char *titulo;
    char *data_lancamento;
    short int numero_de_musicas;
    void *musicas_raiz_arvore;
} ALBUM;

#endif