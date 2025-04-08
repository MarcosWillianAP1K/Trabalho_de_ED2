#include "../includes/musica.h"
#include "../includes/funcao_sistema.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

MUSICA *alocar_musica()
{
    MUSICA *musica = (MUSICA *)malloc(sizeof(MUSICA));

    verificar_alocacao(musica);
    musica->titulo = NULL;
    musica->duracao = NULL;
    return musica;
}

void liberar_musica(MUSICA **musica)
{
    
    if (musica != NULL && *musica != NULL)
    {
        free((*musica)->titulo);
        free((*musica)->duracao);
        free(*musica);

        *musica = NULL;
    }
}

MUSICA *criar_musica(char *titulo, char *duracao)
{
    MUSICA *musica = alocar_musica();
    musica->titulo = titulo;
    musica->duracao = duracao;

    return musica;
}

void imprimir_musica(MUSICA *musica)
{
    if (musica != NULL)
    {
        printf("\nNome: %s", musica->titulo);
        printf("\nDuracao: %s\n", musica->duracao);
    }
}

int comparar_titulo_musica(MUSICA *musica1, MUSICA *musica2)
{
    return strcmp(musica1->titulo, musica2->titulo);
}