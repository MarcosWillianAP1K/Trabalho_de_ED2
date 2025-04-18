#include "dados.h"

#ifndef ARV_AVL_H
#define ARV_AVL_H

typedef struct ARV_AVL
{
    DADOS *info;
    int altura;
    struct ARV_AVL *esq;
    struct ARV_AVL *dir;
} ARV_AVL;

ARV_AVL *alocar_arv_avl();

void liberar_no_arv_avl(ARV_AVL **raiz, void (*liberar)(DADOS **));

void liberar_arv_avl(ARV_AVL **raiz, void (*liberar)(DADOS **));

ARV_AVL *criar_no_arv_avl(DADOS *info);

int inserir_arv_avl(ARV_AVL **raiz, DADOS *info, int (*comparar)(DADOS *, DADOS *));

void imprimir_arv_avl(ARV_AVL *raiz, void (*printar_dados)(DADOS *));

int eh_folha(ARV_AVL *raiz);

ARV_AVL *eh_um_filho(ARV_AVL *raiz);

ARV_AVL **endereco_maximo_direita(ARV_AVL **raiz);

ARV_AVL *remover_arv_avl(ARV_AVL **raiz, DADOS *info, int (*comparar)(DADOS *, DADOS *));

ARV_AVL *buscar_arv_avl(ARV_AVL *raiz, DADOS *info, int (*comparar)(DADOS *, DADOS *));

short int imprimir_arv_avl_filtro(ARV_AVL *raiz, DADOS *info, void (*printar_dados)(DADOS *), int (*comparar)(DADOS *, DADOS *));

#endif
