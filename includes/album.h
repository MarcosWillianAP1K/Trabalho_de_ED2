




#ifndef ALBUM_H
#define ALBUM_H




typedef struct ALBUM{
    char *titulo;
    char *data_lancamento;
    short int numero_de_musicas;
    void *musicas_raiz_arvore;
} ALBUM;

ALBUM *alocar_album();

void liberar_album(ALBUM *album);

ALBUM *criar_album(char *titulo, char *data_lancamento, short int numero_de_musicas, void *raiz);

ALBUM *cadastrar_album();

void imprimir_album(ALBUM *album);

#endif