



#ifndef ARTISTA_H
#define ARTISTA_H

typedef struct ARTISTA{
    char *nome;
    char tipo[20];
    char estilo_musical[40];
    short int numero_de_albuns;
    void *albuns_raiz_arvore;

} ARTISTA;



ARTISTA *criar_artista(char *nome, char *tipo, char *estilo_musical);

#endif