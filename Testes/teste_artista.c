#include "../includes/artista.h"
#include <stdio.h>
#include <stdlib.h>

//gcc Testes/teste_artista.c Tads/artista.c Tads/funcao_sistema.c

int main() 
{


    ARTISTA *teste = cadastrar_artista();
    

    imprimir_artista(teste);

    free(teste->nome);
    free(teste->tipo);
    free(teste->estilo_musical);
    free(teste);

    return 0;
}