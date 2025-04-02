#include "../includes/dados.h"
#include "../includes/funcao_sistema.h"
#include <stdio.h>
#include <stdlib.h>

//gcc Testes/teste_dados.c Tads/dados.c Tads/funcao_sistema.c Tads/album.c Tads/artista.c Tads/musica_playlist.c Tads/musica.c Tads/playlist.c

int main()
{
    //Teste artista
    DADOS *dados = alocar_dados();
    verificar_alocacao(dados);
    printf("Dados alocados\n\n\n");

    dados->artista = criar_artista("Artista", "Tipo", "Estilo", 0, NULL);

    printf("Artista criado\n");

    imprimir_dados_artista(dados);
    
    printf("\n\n");

    liberar_dados_artista(&dados);

    printf("Artista liberado\n\n\n");

    //Teste album
    
    dados->album = criar_album("Album", "2023-10-01", 0, NULL);

    printf("Album criado\n");

    imprimir_dados_album(dados);

    printf("\n\n");

    liberar_dados_album(&dados);

    printf("Album liberado\n\n\n");

    //Teste musica
    
    dados->musica = criar_musica("Musica",  "0:00");

    printf("Musica criada\n");

    imprimir_dados_musica(dados);

    printf("\n\n");

    liberar_dados_musica(&dados);

    printf("Musica liberada\n\n\n");

    //Teste playlist
    
    dados->playlist = criar_playlist("Playlist", 0, NULL);

    printf("Playlist criada\n");

    imprimir_dados_playlist(dados);

    printf("\n\n");

    liberar_dados_playlist(&dados);

    printf("Playlist liberada\n\n\n");


    //Teste musica_playlist
    
    dados->musica_playlist = criar_musica_playlist("Musica", "2023-10-01", NULL);

    printf("Musica_playlist criada\n");

    imprimir_dados_musica_playlist(dados);

    printf("\n\n");

    liberar_dados_musica_playlist(&dados);

    printf("Musica_playlist liberada\n\n\n");

    //Teste dados
    liberar_dados(&dados);
    printf("Dados liberados\n\n");


    return 0;
}