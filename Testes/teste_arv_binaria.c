#include "../includes/arv_binaria.h"
#include "../includes/funcao_sistema.h"

#include <stdio.h>
#include <stdlib.h>

//gcc Testes/teste_arv_binaria.c Tads/arv_binaria.c Tads/album.c Tads/artista.c Tads/dados.c Tads/funcao_sistema.c Tads/musica_playlist.c Tads/musica.c Tads/playlist.c

int main()
{
    ARV_BINARIA *raiz = NULL;

    DADOS *dado1 = alocar_dados();

    dado1->artista = criar_artista("Artista 1", "Tipo 1", "Estilo 1", 0, NULL);

    DADOS *dado2 = alocar_dados();

    dado2->artista = criar_artista("Artista 2", "Tipo 2", "Estilo 2", 0, NULL);

    inserir_arv_binaria(&raiz, dado1, comparar_dados_nome_artista);
    inserir_arv_binaria(&raiz, dado2, comparar_dados_nome_artista);

    imprimir_arv_binaria(raiz, imprimir_dados_artista);


    liberar_arv_binaria(&raiz, liberar_dados_artista);

    return 0;
}