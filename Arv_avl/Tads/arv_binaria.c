#include "../includes/arv_binaria.h"
#include "../includes/funcao_sistema.h"
#include <stdio.h>
#include <stdlib.h>

ARV_BINARIA *alocar_arv_binaria()
{
  ARV_BINARIA *nova_arv = (ARV_BINARIA *)malloc(sizeof(ARV_BINARIA));

  verificar_alocacao(nova_arv);

  return nova_arv;
}

void liberar_no_arv_binaria(ARV_BINARIA **raiz, void (*liberar)(DADOS **))
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
  
void liberar_arv_binaria(ARV_BINARIA **raiz, void (*liberar)(DADOS **))
{
  if (raiz != NULL && *raiz != NULL)
  {
    liberar_arv_binaria(&((*raiz)->esq), liberar);
    liberar_arv_binaria(&((*raiz)->dir), liberar);

    liberar_no_arv_binaria(raiz, liberar);

    *raiz = NULL;
  }
}

ARV_BINARIA *criar_no_arv_binaria(DADOS *info)
{
  ARV_BINARIA *nova_arv = alocar_arv_binaria();
  nova_arv->info = info;
  nova_arv->esq = NULL;
  nova_arv->dir = NULL;
  return nova_arv;
}

int inserir_arv_binaria(ARV_BINARIA **raiz, DADOS *info, int (*comparar)(DADOS *, DADOS *))
{
  int inseriu = 1;

  if (*raiz == NULL)
  {
    *raiz = criar_no_arv_binaria(info);
  }
  else if (comparar((*raiz)->info, info) > 0)
  {
    inseriu = inserir_arv_binaria(&(*raiz)->esq, info, comparar);
  }
  else if (comparar((*raiz)->info, info) < 0)
  {
    inseriu = inserir_arv_binaria(&(*raiz)->dir, info, comparar);
    /* code */
  }
  else{
    inseriu = 0;
  }

  return inseriu;
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

short int imprimir_arv_binaria_filtro(ARV_BINARIA *raiz, DADOS *info, void (*printar_dados)(DADOS *), int (*comparar)(DADOS *, DADOS *))
{
  short int retorno = 0;

  if (raiz != NULL)
  {
    retorno |= imprimir_arv_binaria_filtro(raiz->esq, info, printar_dados, comparar);
    if (comparar(raiz->info, info) == 0)
    {
      printar_dados(raiz->info);
      retorno = 1;
    }
    retorno |= imprimir_arv_binaria_filtro(raiz->dir, info, printar_dados, comparar);
  }

  return retorno;
}

int eh_folha(ARV_BINARIA *raiz)
{
  return (raiz->esq == NULL && raiz->dir == NULL);
}

ARV_BINARIA *eh_um_filho(ARV_BINARIA *raiz)
{
  ARV_BINARIA *filho = NULL;

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

ARV_BINARIA **endereco_maximo_direita(ARV_BINARIA **raiz)
{
  ARV_BINARIA **no = NULL;

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


ARV_BINARIA *remover_arv_binaria(ARV_BINARIA **raiz, DADOS *info, int (*comparar)(DADOS *, DADOS *))
{
  ARV_BINARIA *removeu = NULL;

  if (*raiz != NULL)
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
        ARV_BINARIA *filho;

        if ((filho = eh_um_filho(*raiz)) != NULL)
        {
          removeu = *raiz;
          *raiz = filho;
        }
        else
        {
          ARV_BINARIA **menor;
          menor = endereco_maximo_direita(&(*raiz)->esq);

          ARV_BINARIA *aux = *menor;
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
        removeu = remover_arv_binaria(&(*raiz)->esq, info, comparar);
      }
      else
      {
        removeu = remover_arv_binaria(&(*raiz)->dir, info, comparar);
      }
    }
  }


  return removeu;
}

ARV_BINARIA *buscar_arv_binaria(ARV_BINARIA *raiz, DADOS *info, int (*comparar)(DADOS *, DADOS *))
{
  ARV_BINARIA *no = NULL;

  if (raiz != NULL)
  {
    if (comparar(raiz->info, info) == 0)
    {
      no = raiz;
    }
    else
    {
      if (comparar(raiz->info, info) > 0)
      {
        no = buscar_arv_binaria(raiz->esq, info, comparar);
      }
      else
      {
        no = buscar_arv_binaria(raiz->dir, info, comparar);
      }
    }
  }

  return no;
}


