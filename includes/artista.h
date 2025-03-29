



#ifndef ARTISTA_H
#define ARTISTA_H



typedef struct ARTISTA{
    char *nome;
    char *tipo;
    char *estilo_musical;
    short int numero_de_albuns;
    void *albuns_raiz_arvore;

} ARTISTA;

ARTISTA *alocar_artista();

void liberar_artista(ARTISTA *artista);

ARTISTA *criar_artista(char *nome, char *tipo, char *estilo_musical, short int numero_albuns, void *raiz);

ARTISTA *cadastrar_artista();

void imprimir_artista(ARTISTA *artista);


#endif