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

ARV_BINARIA *criar_arv_binaria(DADOS *info)
{
  ARV_BINARIA *nova_arv = alocar_arv_binaria();
  nova_arv->info = info;
  nova_arv->esq = NULL;
  nova_arv->dir = NULL;
  return nova_arv;
}

void inserir_arv_binaria(ARV_BINARIA **raiz, DADOS *info, int (*comparar)(DADOS *, DADOS *))
{
  if (*raiz == NULL)
  {
    *raiz = alocar_arv_binaria();
    (*raiz)->info = info;
    (*raiz)->esq = NULL;
    (*raiz)->dir = NULL;
  }
  else if (comparar( (*raiz)->info, info) > 0)
  {
    inserir_arv_binaria(&(*raiz)->esq, info, comparar);
  }
  else
  {
    inserir_arv_binaria(&(*raiz)->dir, info, comparar);
  }
}

void imprimir_arv_binaria(ARV_BINARIA *raiz, void (*printar_dados)(DADOS *))
{
  if (raiz != NULL)
  {
    imprimir_arv_binaria(raiz->esq, printar_dados);
    printar_dados(raiz->info);
    imprimir_arv_binaria(raiz->dir, printar_dados);
  }
}

int eh_folha(ARV_BINARIA *raiz)
{
  return (raiz->esq == NULL && raiz->dir == NULL);
}

int eh_um_filho(ARV_BINARIA *raiz)
{
  return (raiz->esq == NULL || raiz->dir == NULL);
}

int endereco_minino_esqueda(ARV_BINARIA *raiz)
{
  int eh = 0;
  if (raiz->esq != NULL)
  {
    eh = endereco_minino_esqueda(raiz->esq);
  }
  else
  {
    eh = raiz;
  }
  return eh;
}

int remover_arv_binaria_com_valor(ARV_BINARIA **raiz, DADOS *info, void (*liberar)(DADOS **), int remover_no)
{
  int removeu = 1;

  if (*raiz != NULL)
  {
    if ((*raiz)->info == info)
    {
      if (remover_no)
      {
        ARV_BINARIA *aux;
        ARV_BINARIA *filho;

        if (eh_folha(*raiz))
        {
          aux = *raiz;
          *raiz = NULL;
          free(aux);
        }
        else
        {
          if ((filho = eh_um_filho(*raiz)) != NULL)
          {
            aux = *raiz;
            *raiz = filho;
            free(aux);
          }
          else
          {
            ARV_BINARIA *menor;
            menor = endereco_minino_esqueda((*raiz)->dir);
            (*raiz)->info = menor->info;
            removeu = remover_arv_binaria_com_valor(&(*raiz)->dir, menor->info, liberar, 1);
          }
        }
      }
      else
      {
        if ((*raiz)->info != NULL)
        {
          liberar(&(*raiz)->info);
          (*raiz)->info = NULL;
        }
      }
    }
    else
    {
      if (info < (*raiz)->info)
      {
        removeu = remover_arv_binaria_com_valor(&(*raiz)->esq, info, liberar, remover_no);
      }
      else
      {
        removeu = remover_arv_binaria_com_valor(&(*raiz)->dir, info, liberar, remover_no);
      }
    }
  }
  else
  {
    removeu = 0;
  }
  return removeu;
}

void buscar_arv_binaria(ARV_BINARIA *raiz, DADOS *info, int (*comparar)(DADOS *, DADOS *), void (*printar_dados)(DADOS *))
{
  if (raiz != NULL)
  {
    if (comparar(raiz->info, info) == 0)
    {
      printar_dados(raiz->info);
    }
    else
    {
      if (comparar(raiz->info, info) < 0)
      {
        buscar_arv_binaria(raiz->dir, info, comparar, printar_dados);
      }
      else
      {
        buscar_arv_binaria(raiz->esq, info, comparar, printar_dados);
      }
      
    }
  }
}