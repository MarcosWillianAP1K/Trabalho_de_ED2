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
  nova_arv->altura = 0;
  nova_arv->esq = NULL;
  nova_arv->dir = NULL;
  return nova_arv;
}

short int fator_balanceamento(ARV_AVL *raiz)
{
  short int fb = -1;

  if (raiz != NULL)
  {
    int altura_esq = -1;
    if (raiz->esq != NULL)
    {
      altura_esq = raiz->esq->altura;
    }

    int altura_dir = -1;
    if (raiz->dir != NULL)
    {
      altura_dir = raiz->dir->altura;
    }

    fb = altura_esq - (altura_dir);
  }

  return fb;
}

void ajuste_altura(ARV_AVL **raiz)
{
  if (raiz != NULL && *raiz != NULL)
  {
    int altura_esq = -1;
    if ((*raiz)->esq != NULL)
    {
      altura_esq = (*raiz)->esq->altura;
    }

    int altura_dir = -1;
    if ((*raiz)->dir != NULL)
    {
      altura_dir = (*raiz)->dir->altura;
    }

    (*raiz)->altura = (altura_esq > altura_dir ? altura_esq : altura_dir) + 1;
  }
}

void de_ladinho_para_direita(ARV_AVL **raiz)
{
  if (raiz != NULL && *raiz != NULL)
  {
    ARV_AVL *aux = (*raiz)->esq;
    (*raiz)->esq = aux->dir;
    aux->dir = *raiz;
    *raiz = aux;

    ajuste_altura(&(*raiz)->dir);
    ajuste_altura(raiz);
  }
}

void de_ladinho_para_esquerda(ARV_AVL **raiz)
{
  if (raiz != NULL && *raiz != NULL)
  {
    ARV_AVL *aux = (*raiz)->dir;
    (*raiz)->dir = aux->esq;
    aux->esq = *raiz;
    *raiz = aux;

    ajuste_altura(&(*raiz)->esq);
    ajuste_altura(raiz);
  }
}

short int balanceamento(ARV_AVL **raiz, int (*comparar)(DADOS *, DADOS *))
{
  short int retorno = 0;

  if (raiz != NULL && *raiz != NULL)
  {
    short int fb = fator_balanceamento(*raiz);

    // Pendente para esquerda, rotacionando para direita
    if (fb == 2)
    {
      retorno = 1;
      // Verifica se o nó da esquerda é pendente para direita, se sim deve fazer 2 rotações
      if ((*raiz)->dir != NULL && fator_balanceamento((*raiz)->dir) == -1)
      {
        de_ladinho_para_esquerda(&(*raiz)->dir);
        de_ladinho_para_direita(raiz);
      }
      else
      {
        de_ladinho_para_direita(raiz);
      }
    }
    // Pendente para direita, rotacionando para esquerda
    else if (fb == -2)
    {
      retorno = 1;
      // Verifica se o nó da direita é pendente para esquerda, se sim deve fazer 2 rotações
      if ((*raiz)->esq != NULL && fator_balanceamento((*raiz)->esq) == 1)
      {
        de_ladinho_para_direita(&(*raiz)->esq);
        de_ladinho_para_esquerda(raiz);
      }
      else
      {
        de_ladinho_para_esquerda(raiz);
      }
    }
  }

  return retorno;
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

    if (inseriu == 1)
    {
      balanceamento(raiz, comparar);
      ajuste_altura(raiz);
    }
  }

  return inseriu;
}

void imprimir_arv_avl(ARV_AVL *raiz, void (*printar_dados)(DADOS *))
{
  if (raiz != NULL)
  {
    imprimir_arv_avl(raiz->esq, printar_dados);
    printf("\nAltura: %d", raiz->altura);
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

    if (removeu != NULL)
    {
      balanceamento(raiz, comparar);
      ajuste_altura(raiz);
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
