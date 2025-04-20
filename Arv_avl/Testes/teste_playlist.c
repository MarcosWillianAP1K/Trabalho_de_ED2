#include "../includes/playlist.h"
#include <stdio.h>
#include <stdlib.h>


//gcc Testes/teste_playlist.c Tads/playlist.c Tads/funcao_sistema.c 

int main() 
{
    PLAYLIST *teste1 = cadastrar_playlist();
    PLAYLIST *teste2 = cadastrar_playlist();

    imprimir_playlist(teste1);
    imprimir_playlist(teste2);

    printf("\n\nComparando playlists: %d\n", comparar_nome_playlist(teste1, teste2));

    liberar_playlist(&teste1);
    liberar_playlist(&teste2);

    return 0;
}