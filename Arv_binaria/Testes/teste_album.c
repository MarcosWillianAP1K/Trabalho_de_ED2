#include "../includes/album.h"
#include <stdio.h>
#include <stdlib.h>

//gcc Testes/teste_album.c Tads/album.c Tads/funcao_sistema.c

int main() 
{


    ALBUM *teste1 = cadastrar_album();
    ALBUM *teste2 = cadastrar_album();
    

    imprimir_album(teste1);
    imprimir_album(teste2);

    printf("\ncomparando os albuns: %d\n", comparar_titulo_album(teste1, teste2));


    liberar_album(&teste1);
    liberar_album(&teste2);

    return 0;
}