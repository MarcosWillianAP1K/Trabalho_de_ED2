



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
ARTISTA *buscar_artista(ARTISTA *raiz, char *nome);
ARTISTA *inserir_artista(ARTISTA *raiz, ARTISTA *novo);
ARTISTA *remover_artista(ARTISTA *raiz, char *nome);
ARTISTA *remover_artista_recursivo(ARTISTA *raiz, char *nome);

ARTISTA *criar_artista(char *nome, char *tipo, char *estilo_musical){
    ARTISTA *novo = (ARTISTA *) malloc(sizeof(ARTISTA));
    novo->nome = nome;
}

#endif