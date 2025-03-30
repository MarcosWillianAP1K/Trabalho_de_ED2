#include "dados.h"



#ifndef ARV_BINARIA_H
#define ARV_BINARIA_H


typedef struct ARV_BINARIA{
    DADOS *info;
    struct ARV_BINARIA *esq;
    struct ARV_BINARIA *dir;
} ARV_BINARIA;

void inicializar_arv_binaria(ARV_BINARIA **raiz);

ARV_BINARIA *alocar_arv_binaria();

void liberar_arv_binaria(ARV_BINARIA **raiz, void (*liberar)(DADOS **));

ARV_BINARIA * criar_arv_binaria(DADOS *info);

void inserir_arv_binaria(ARV_BINARIA **raiz, DADOS *info, int (*comparar)(DADOS *, DADOS *));

void imprimir_arv_binaria(ARV_BINARIA *raiz, void (*printar_dados)(DADOS *));

int eh_folha(ARV_BINARIA *raiz);

int eh_um_filho(ARV_BINARIA *raiz);

int endereco_minino_esqueda(ARV_BINARIA *raiz);

int remover_arv_binaria(ARV_BINARIA **raiz, DADOS *info);


#endif
