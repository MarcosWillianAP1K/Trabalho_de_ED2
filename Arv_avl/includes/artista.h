



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

void liberar_artista(ARTISTA **artista);

ARTISTA *criar_artista(char *nome, char *tipo, char *estilo_musical, short int numero_albuns, void *raiz);

void imprimir_artista(ARTISTA *artista);

int comparar_nome_artista(ARTISTA *artista1, ARTISTA *artista2);

int comparar_estilo_artista(ARTISTA *artista1, ARTISTA *artista2);

int comparar_tipo_artista(ARTISTA *artista1, ARTISTA *artista2);

int comparar_tipo_e_estilo_artista(ARTISTA *artista1, ARTISTA *artista2);

#endif