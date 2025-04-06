




#ifndef ALBUM_H
#define ALBUM_H




typedef struct ALBUM{
    char *titulo;
    char *data_lancamento;
    short int numero_de_musicas;
    void *musicas_raiz_arvore;
} ALBUM;

ALBUM *alocar_album();

void liberar_album(ALBUM **album);

ALBUM *criar_album(char *titulo, char *data_lancamento, short int numero_de_musicas, void *raiz);

void imprimir_album(ALBUM *album);

int comparar_titulo_album(ALBUM *album1, ALBUM *album2);

int comparar_data_album(ALBUM *album1, ALBUM *album2);

#endif