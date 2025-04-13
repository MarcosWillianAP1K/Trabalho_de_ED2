#include "../includes/musica.h"
#include <stdio.h>
#include <stdlib.h>

//gcc Testes/teste_musica.c Tads/musica.c Tads/funcao_sistema.c

int main() 
{
    MUSICA *teste1 = cadastrar_musica();
    MUSICA *teste2 = cadastrar_musica();

    imprimir_musica(teste1);
    imprimir_musica(teste2);

    printf("\n\nComparando musicas: %d\n", comparar_titulo_musica(teste1, teste2));


    liberar_musica(&teste1);
    liberar_musica(&teste2);

    return 0;
}