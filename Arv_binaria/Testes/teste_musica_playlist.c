#include "../includes/musica_playlist.h"
#include <stdio.h>
#include <stdlib.h>

//gcc Testes/teste_musica_playlist.c Tads/musica_playlist.c Tads/musica.c Tads/funcao_sistema.c

int main()
{
    MUSICA *musica1 = cadastrar_musica();

    MUSICA_PLAYLIST *teste1 = cadastrar_musica_playlist(musica1);
    MUSICA_PLAYLIST *teste2 = cadastrar_musica_playlist(musica1);

    imprimir_musica_playlist(teste1);
    imprimir_musica_playlist(teste2);

    //TA DANDO 1 NA COMPARACAO, ERA PRA DAR -1 POIS O TESTE 1 E MENOR QUE O TESTE 2
    printf("\n\nComparando musicas: %d\n", comparar_musia_playlist(teste1, teste2));

    liberar_musica_playlist(&teste1);
    liberar_musica_playlist(&teste2);
    

    return 0;
}