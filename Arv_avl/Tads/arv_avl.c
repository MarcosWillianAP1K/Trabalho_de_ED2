#include "../includes/arv_avl.h"
#include "../includes/funcao_sistema.h"
#include <stdio.h>
#include <stdlib.h>

ARV_AVL *alocar_arv_avl()
{
  ARV_AVL *nova_arv = (ARV_AVL *)malloc(sizeof(ARV_AVL));

  verificar_alocacao(nova_arv);

  return nova_arv;
}

void liberar_no_arv_avl(ARV_AVL **raiz, void (*liberar)(DADOS **))
{

  if (raiz != NULL && *raiz != NULL)
  {
    if ((*raiz)->info != NULL)
    {
      liberar(&(*raiz)->info);
    }

    free(*raiz);
    *raiz = NULL;
  }
}

void liberar_arv_avl(ARV_AVL **raiz, void (*liberar)(DADOS **))
{
  if (raiz != NULL && *raiz != NULL)
  {
    liberar_arv_avl(&((*raiz)->esq), liberar);
    liberar_arv_avl(&((*raiz)->dir), liberar);

    liberar_no_arv_avl(raiz, liberar);

    *raiz = NULL;
  }
}

ARV_AVL *criar_no_arv_avl(DADOS *info)
{
  ARV_AVL *nova_arv = alocar_arv_avl();
  nova_arv->info = info;
  nova_arv->esq = NULL;
  nova_arv->dir = NULL;
  return nova_arv;
}

int inserir_arv_avl(ARV_AVL **raiz, DADOS *info, int (*comparar)(DADOS *, DADOS *))
{
  int inseriu = 1;

  if (raiz != NULL && info != NULL)
  {
    if (*raiz == NULL)
    {
      *raiz = criar_no_arv_avl(info);
    }
    else if (comparar((*raiz)->info, info) > 0)
    {
      inseriu = inserir_arv_avl(&(*raiz)->esq, info, comparar);
    }
    else if (comparar((*raiz)->info, info) < 0)
    {
      inseriu = inserir_arv_avl(&(*raiz)->dir, info, comparar);
    }
    else
    {
      inseriu = 0;
    }
  }

  return inseriu;
}

void imprimir_arv_avl(ARV_AVL *raiz, void (*printar_dados)(DADOS *))
{
  if (raiz != NULL)
  {
    imprimir_arv_avl(raiz->esq, printar_dados);
    printar_dados(raiz->info);
    imprimir_arv_avl(raiz->dir, printar_dados);
  }
}

short int imprimir_arv_avl_filtro(ARV_AVL *raiz, DADOS *info, void (*printar_dados)(DADOS *), int (*comparar)(DADOS *, DADOS *))
{
  short int retorno = 0;

  if (raiz != NULL && info != NULL)
  {
    retorno |= imprimir_arv_avl_filtro(raiz->esq, info, printar_dados, comparar);
    if (comparar(raiz->info, info) == 0)
    {
      printar_dados(raiz->info);
      retorno = 1;
    }
    retorno |= imprimir_arv_avl_filtro(raiz->dir, info, printar_dados, comparar);
  }

  return retorno;
}

int eh_folha(ARV_AVL *raiz)
{
  return (raiz->esq == NULL && raiz->dir == NULL);
}

ARV_AVL *eh_um_filho(ARV_AVL *raiz)
{
  ARV_AVL *filho = NULL;

  if (raiz->esq != NULL && raiz->dir == NULL)
  {
    filho = raiz->esq;
  }
  else if (raiz->esq == NULL && raiz->dir != NULL)
  {
    filho = raiz->dir;
  }

  return filho;
}

ARV_AVL **endereco_maximo_direita(ARV_AVL **raiz)
{
  ARV_AVL **no = NULL;

  if ((*raiz)->dir != NULL)
  {
    no = endereco_maximo_direita(&(*raiz)->dir);
  }
  else
  {
    no = raiz;
  }

  return no;
}

ARV_AVL *remover_arv_avl(ARV_AVL **raiz, DADOS *info, int (*comparar)(DADOS *, DADOS *))
{
  ARV_AVL *removeu = NULL;

  if (raiz != NULL && *raiz != NULL && info != NULL)
  {
    if (comparar((*raiz)->info, info) == 0)
    {

      if (eh_folha(*raiz))
      {
        removeu = *raiz;
        *raiz = NULL;
      }
      else
      {
        ARV_AVL *filho;

        if ((filho = eh_um_filho(*raiz)) != NULL)
        {
          removeu = *raiz;
          *raiz = filho;
        }
        else
        {
          ARV_AVL **menor;
          menor = endereco_maximo_direita(&(*raiz)->esq);

          ARV_AVL *aux = *menor;
          *menor = aux->esq;
          aux->esq = (*raiz)->esq;
          aux->dir = (*raiz)->dir;

          removeu = *raiz;
          *raiz = aux;
        }
      }
    }
    else
    {
      if (comparar((*raiz)->info, info) > 0)
      {
        removeu = remover_arv_avl(&(*raiz)->esq, info, comparar);
      }
      else
      {
        removeu = remover_arv_avl(&(*raiz)->dir, info, comparar);
      }
    }
  }

  return removeu;
}

ARV_AVL *buscar_arv_avl(ARV_AVL *raiz, DADOS *info, int (*comparar)(DADOS *, DADOS *))
{
  ARV_AVL *no = NULL;

  if (raiz != NULL && info != NULL)
  {
    if (comparar(raiz->info, info) == 0)
    {
      no = raiz;
    }
    else
    {
      if (comparar(raiz->info, info) > 0)
      {
        no = buscar_arv_avl(raiz->esq, info, comparar);
      }
      else
      {
        no = buscar_arv_avl(raiz->dir, info, comparar);
      }
    }
  }

  return no;
}
