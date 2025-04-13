#include "dados.h"



#ifndef ARV_BINARIA_H
#define ARV_BINARIA_H


typedef struct ARV_BINARIA{
    DADOS *info;
    struct ARV_BINARIA *esq;
    struct ARV_BINARIA *dir;
} ARV_BINARIA;


ARV_BINARIA *alocar_arv_binaria();

void liberar_no_arv_binaria(ARV_BINARIA **raiz, void (*liberar)(DADOS **));

void liberar_arv_binaria(ARV_BINARIA **raiz, void (*liberar)(DADOS **));

ARV_BINARIA *criar_no_arv_binaria(DADOS *info);

int inserir_arv_binaria(ARV_BINARIA **raiz, DADOS *info, int (*comparar)(DADOS *, DADOS *));

void imprimir_arv_binaria(ARV_BINARIA *raiz, void (*printar_dados)(DADOS *));

int eh_folha(ARV_BINARIA *raiz);

ARV_BINARIA *eh_um_filho(ARV_BINARIA *raiz);

ARV_BINARIA **endereco_maximo_direita(ARV_BINARIA **raiz);

ARV_BINARIA *remover_arv_binaria(ARV_BINARIA **raiz, DADOS *info, int (*comparar)(DADOS *, DADOS *));

ARV_BINARIA *buscar_arv_binaria(ARV_BINARIA *raiz, DADOS *info, int (*comparar)(DADOS *, DADOS *));

short int imprimir_arv_binaria_filtro(ARV_BINARIA *raiz, DADOS *info,void (*printar_dados)(DADOS *), int (*comparar)(DADOS *, DADOS *));


#endif
