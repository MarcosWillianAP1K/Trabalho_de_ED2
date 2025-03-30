

#ifndef MUSICA_H
#define MUSICA_H

typedef struct MUSICA{
    char *titulo;
    char *duracao;
    // void *playlist
} MUSICA;


MUSICA *alocar_musica();

void liberar_musica(MUSICA **musica);

MUSICA *criar_musica(char *titulo, char *duracao);

MUSICA *cadastrar_musica();

void imprimir_musica(MUSICA *musica);

int comparar_titulo_musica(MUSICA *musica1, MUSICA *musica2);


#endif