#include "../includes/arv_binaria.h"
#include <stdio.h>


void imprimir(ARV_BINARIA *raiz)
{
  if (raiz != NULL)
  {
    imprimir(raiz->esq);
    printf("%d ", raiz->info);
    imprimir(raiz->dir);
  }
}