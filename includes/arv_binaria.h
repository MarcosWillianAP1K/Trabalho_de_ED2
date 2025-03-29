#include "dados.h"



#ifndef ARV_BINARIA_H
#define ARV_BINARIA_H


typedef struct ARV_BINARIA{
    union dados *info;
    struct ARV_BINARIA *esq;
    struct ARV_BINARIA *dir;
} ARV_BINARIA;

void inicializar_arv_binaria(ARV_BINARIA **raiz);

ARV_BINARIA *alocar_arv_binaria();

// void liberar_arv_binaria(ARV_BINARIA *raiz);

ARV_BINARIA * criar_arv_binaria(DADOS *info);

void inserir_arv_binaria(ARV_BINARIA **raiz, int valor);

void imprimir(ARV_BINARIA *raiz);


#endif
