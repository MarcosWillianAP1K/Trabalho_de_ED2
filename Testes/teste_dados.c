#include "../includes/dados.h"
#include "../includes/funcao_sistema.h"
#include <stdio.h>
#include <stdlib.h>

//gcc Testes/teste_dados.c Tads/dados.c Tads/funcao_sistema.c Tads/album.c Tads/artista.c Tads/musica_playlist.c Tads/musica.c Tads/playlist.c

int main()
{
    DADOS *dados = alocar_dados();
    dados->artista = criar_artista("Artista Teste1", "Artista Teste2", "Artista Teste3", 0, NULL);

    printf("Tamanho da string: %d\n", sizeof (dados->artista->estilo_musical));

    printar_dados(dados);
    liberar_dados(dados);
    // Teste de alocação e liberação de dados





    return 0;
}