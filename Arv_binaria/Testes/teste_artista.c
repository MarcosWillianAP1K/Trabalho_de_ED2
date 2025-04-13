#include "../includes/artista.h"
#include <stdio.h>
#include <stdlib.h>

//gcc Testes/teste_artista.c Tads/artista.c Tads/funcao_sistema.c

int main() 
{


    ARTISTA *teste1 = cadastrar_artista();
    ARTISTA *teste2 = cadastrar_artista();

    imprimir_artista(teste1);
    imprimir_artista(teste2);

    printf("\n\nComparando artistas: %d\n", comparar_nome_artista(teste1, teste2));

    liberar_artista(&teste1);
    liberar_artista(&teste2);

    return 0;
}