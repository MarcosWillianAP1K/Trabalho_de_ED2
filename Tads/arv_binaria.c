#include "../includes/arv_binaria.h"
#include "../includes/funcao_sistema.h"
#include <stdio.h>
#include <stdlib.h>

void inicializar_arv_binaria(ARV_BINARIA **raiz)
{
  *raiz = NULL;
}

ARV_BINARIA *alocar_arv_binaria()
{
  ARV_BINARIA *nova_arv = (ARV_BINARIA *)malloc(sizeof(ARV_BINARIA));
  
  verificar_alocacao(nova_arv);

  return nova_arv;
}

void liberar_arv_binaria(ARV_BINARIA **raiz, void (*liberar)(DADOS **))
{
  if (raiz != NULL && *raiz != NULL)
  {
    liberar_arv_binaria(&((*raiz)->esq), liberar);
    liberar_arv_binaria(&((*raiz)->dir), liberar);
   
    if ((*raiz)->info != NULL)
    {
      liberar(&(*raiz)->info);
    }
    
    free(*raiz);
    *raiz = NULL;
  }
}


ARV_BINARIA * criar_arv_binaria(DADOS *info)
{
  ARV_BINARIA *nova_arv = alocar_arv_binaria();
  nova_arv->info = info;
  nova_arv->esq = NULL;
  nova_arv->dir = NULL;
  return nova_arv;
}



// void inserir_arv_binaria(ARV_BINARIA **raiz, DADOS *info)
// {
//   if (*raiz == NULL)
//   {
//     *raiz = (ARV_BINARIA *)malloc(sizeof(ARV_BINARIA));
//     (*raiz)->info = info;
//     (*raiz)->esq = NULL;
//     (*raiz)->dir = NULL;
//   }
//   else if (valor < (*raiz)->info)
//   {
//     inserir_arv_binaria(&(*raiz)->esq, valor);
//   }
//   else
//   {
//     inserir_arv_binaria(&(*raiz)->dir, valor);
//   }
// }


void imprimir_arv_binaria(ARV_BINARIA *raiz, void (*printar_dados)(DADOS *))
{
  if (raiz != NULL)
  {
    imprimir_arv_binaria(raiz->esq, printar_dados);
    printar_dados(raiz->info);
    imprimir_arv_binaria(raiz->dir, printar_dados);
  }
}