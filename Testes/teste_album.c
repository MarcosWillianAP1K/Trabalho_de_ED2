#include "../includes/album.h"
#include <stdio.h>
#include <stdlib.h>

//gcc Testes/teste_album.c Tads/album.c Tads/funcao_sistema.c

int main() 
{


    ALBUM *teste = cadastrar_album();
    

    imprimir_album(teste);

    free(teste->titulo);
    free(teste->data_lancamento);
    free(teste);

    return 0;
}