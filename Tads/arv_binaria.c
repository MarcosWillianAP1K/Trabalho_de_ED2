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

    if ((*raiz)->info != NULL)
    {
      liberar(&(*raiz)->info);
    }

    liberar_no_arv_binaria(raiz, liberar);

    *raiz = NULL;
  }
}

ARV_BINARIA *cria_no_arv_binaria(DADOS *info)
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
    *raiz = cria_no_arv_binaria(info);
  }
  else if (comparar((*raiz)->info, info) > 0)
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

// PRECISA FAZER UMA REMOÇÃO DIFERENTE, NÃO BASTA COPIAR O CONTEUDO, DEVE TROCAR O NO POR INTEIRO.
int remover_arv_binaria(ARV_BINARIA **raiz, DADOS *info, void (*liberar)(DADOS **), int (*comparar)(DADOS *, DADOS *))
{
  int removeu = 1;

  if (*raiz != NULL)
  {
    if (comparar((*raiz)->info, info) == 0)
    {

      if (eh_folha(*raiz))
      {
        liberar_no_arv_binaria(raiz, liberar);
      }
      else
      {
        ARV_BINARIA *filho;

        if ((filho = eh_um_filho(*raiz)) != NULL)
        {
          liberar_no_arv_binaria(raiz, liberar);
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

          liberar_no_arv_binaria(raiz, liberar);
          *raiz = aux;
        }
      }
    }
    else
    {
      if (comparar((*raiz)->info, info) > 0)
      {
        removeu = remover_arv_binaria(&(*raiz)->esq, info, liberar, comparar);
      }
      else
      {
        removeu = remover_arv_binaria(&(*raiz)->dir, info, liberar, comparar);
      }
    }
  }
  else
  {
    removeu = 0;
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
      if (comparar(raiz->info, info) < 0)
      {
        no = buscar_arv_binaria(raiz->dir, info, comparar);
      }
      else
      {
        no = buscar_arv_binaria(raiz->esq, info, comparar);
      }
    }
  }

  return no;
}

void imprimir_arv_binaria_filtro(ARV_BINARIA *raiz, void (*printar_dados)(DADOS *), int (*comparar)(DADOS *, DADOS *), DADOS *info)
{
  if (raiz != NULL)
  {
    imprimir_arv_binaria_filtro(raiz->esq, printar_dados, comparar, info);
    if (comparar(raiz->info, info) == 0)
    {
      printar_dados(raiz->info);
    }
    imprimir_arv_binaria_filtro(raiz->dir, printar_dados, comparar, info);
  }
}
