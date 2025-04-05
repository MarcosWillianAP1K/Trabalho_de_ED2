#include "../includes/arv_binaria.h"
#include "../includes/funcao_sistema.h"

#include <stdio.h>
#include <stdlib.h>

//gcc Testes/teste_arv_binaria.c Tads/arv_binaria.c Tads/album.c Tads/artista.c Tads/dados.c Tads/funcao_sistema.c Tads/musica_playlist.c Tads/musica.c Tads/playlist.c

int main()
{
    ARV_BINARIA *raiz = NULL;
    // Trabalhando com ARTISTA
    DADOS *dado_artista1 = alocar_dados();
    dado_artista1->artista = criar_artista("Artista 1", "Genero 1", "Estilo 1", 0, NULL);
    DADOS *dado_artista2 = alocar_dados();
    dado_artista2->artista = criar_artista("Artista 2", "Genero 2", "Estilo 2", 0, NULL);
    DADOS *dado_artista3 = alocar_dados();
    dado_artista3->artista = criar_artista("Artista 3", "Genero 3", "Estilo 3", 0, NULL);
    DADOS *dado_artista4 = alocar_dados();
    dado_artista4->artista = criar_artista("Artista 4", "Genero 4", "Estilo 4", 0, NULL);

    inserir_arv_binaria(&raiz, dado_artista2, comparar_dados_nome_artista);
    inserir_arv_binaria(&raiz, dado_artista1, comparar_dados_nome_artista);
    inserir_arv_binaria(&raiz, dado_artista3, comparar_dados_nome_artista);
    inserir_arv_binaria(&raiz, dado_artista4, comparar_dados_nome_artista);

    imprimir_arv_binaria(raiz, imprimir_dados_artista);

    remover_arv_binaria(&raiz, dado_artista3, liberar_dados_artista, comparar_dados_nome_artista);
    printf("\n\nDepois de remover o dado artista 3:\n");

    imprimir_arv_binaria(raiz, imprimir_dados_artista);

    liberar_arv_binaria(&raiz, liberar_dados_artista);

    printf("\n\nDepois de liberar a arvore de artistas:\n");

    // Trabalhando com ALBUM
    DADOS *dado_album1 = alocar_dados();
    dado_album1->album = criar_album("Album 1", "Artista 1", 2020, "Genero 1");
    DADOS *dado_album2 = alocar_dados();
    dado_album2->album = criar_album("Album 2", "Artista 2", 2021, "Genero 2");
    DADOS *dado_album3 = alocar_dados();
    dado_album3->album = criar_album("Album 3", "Artista 3", 2022, "Genero 3");
    DADOS *dado_album4 = alocar_dados();
    dado_album4->album = criar_album("Album 4", "Artista 4", 2023, "Genero 4");

    inserir_arv_binaria(&raiz, dado_album2, comparar_dados_titulo_album);
    inserir_arv_binaria(&raiz, dado_album1, comparar_dados_titulo_album);
    inserir_arv_binaria(&raiz, dado_album3, comparar_dados_titulo_album);
    inserir_arv_binaria(&raiz, dado_album4, comparar_dados_titulo_album);

    imprimir_arv_binaria(raiz, imprimir_dados_album);

    remover_arv_binaria(&raiz, dado_album3, liberar_dados_album, comparar_dados_titulo_album);
    printf("\n\nDepois de remover o dado album 3:\n");

    imprimir_arv_binaria(raiz, imprimir_dados_album);

    liberar_arv_binaria(&raiz, liberar_dados_album);

    printf("\n\nDepois de liberar a arvore de albuns:\n");

    // Trabalhando com MUSICA
    DADOS *dado_musica1 = alocar_dados();
    dado_musica1->musica = criar_musica("Musica 1", "3.5");
    DADOS *dado_musica2 = alocar_dados();
    dado_musica2->musica = criar_musica("Musica 2", "4.0");
    DADOS *dado_musica3 = alocar_dados();
    dado_musica3->musica = criar_musica("Musica 3", "2.8");
    DADOS *dado_musica4 = alocar_dados();
    dado_musica4->musica = criar_musica("Musica 4", "5.0");

    inserir_arv_binaria(&raiz, dado_musica2, comparar_dados_titulo_musica);
    inserir_arv_binaria(&raiz, dado_musica1, comparar_dados_titulo_musica);
    inserir_arv_binaria(&raiz, dado_musica3, comparar_dados_titulo_musica);
    inserir_arv_binaria(&raiz, dado_musica4, comparar_dados_titulo_musica);

    imprimir_arv_binaria(raiz, imprimir_dados_musica);

    remover_arv_binaria(&raiz, dado_musica3, liberar_dados_musica, comparar_dados_titulo_musica);
    printf("\n\nDepois de remover o dado musica 3:\n");

    imprimir_arv_binaria(raiz, imprimir_dados_musica);

    liberar_arv_binaria(&raiz, liberar_dados_musica);

    printf("\n\nDepois de liberar a arvore de musicas:\n");

    // Trabalhando com PLAYLIST
    DADOS *dado_playlist1 = alocar_dados();
    dado_playlist1->playlist = criar_playlist("Playlist 1", 3, NULL);
    DADOS *dado_playlist2 = alocar_dados();
    dado_playlist2->playlist = criar_playlist("Playlist 2", 4, NULL);
    DADOS *dado_playlist3 = alocar_dados();
    dado_playlist3->playlist = criar_playlist("Playlist 3", 5, NULL);
    DADOS *dado_playlist4 = alocar_dados();
    dado_playlist4->playlist = criar_playlist("Playlist 4", 6, NULL);

    inserir_arv_binaria(&raiz, dado_playlist2, comparar_dados_nome_playlist);
    inserir_arv_binaria(&raiz, dado_playlist1, comparar_dados_nome_playlist);
    inserir_arv_binaria(&raiz, dado_playlist3, comparar_dados_nome_playlist);
    inserir_arv_binaria(&raiz, dado_playlist4, comparar_dados_nome_playlist);

    imprimir_arv_binaria(raiz, imprimir_dados_playlist);

    remover_arv_binaria(&raiz, dado_playlist3, liberar_dados_playlist, comparar_dados_nome_playlist);
    printf("\n\nDepois de remover o dado playlist 3:\n");

    imprimir_arv_binaria(raiz, imprimir_dados_playlist);

    liberar_arv_binaria(&raiz, liberar_dados_playlist);

    printf("\n\nDepois de liberar a arvore de playlists:\n");

    //PROBLEMA NA INSERÇÃO DA MUSICA PLAYLIST (NA COMPARAÇÃO) E NA LIBERAÇÃO
    // Trabalhando com MUSICA PLAYLIST
    DADOS *dado_musica_playlist1 = alocar_dados();
    dado_musica_playlist1->musica_playlist = criar_musica_playlist("Musica Playlist 1", "Playlist 1", NULL);
    DADOS *dado_musica_playlist2 = alocar_dados();
    dado_musica_playlist2->musica_playlist = criar_musica_playlist("Musica Playlist 2", "Playlist 2", NULL);
    DADOS *dado_musica_playlist3 = alocar_dados();
    dado_musica_playlist3->musica_playlist = criar_musica_playlist("Musica Playlist 3", "Playlist 3", NULL);
    DADOS *dado_musica_playlist4 = alocar_dados();
    dado_musica_playlist4->musica_playlist = criar_musica_playlist("Musica Playlist 4", "Playlist 4", NULL);

    inserir_arv_binaria(&raiz, dado_musica_playlist2, comparar_dados_musica_playlist);
    inserir_arv_binaria(&raiz, dado_musica_playlist1, comparar_dados_musica_playlist);
    inserir_arv_binaria(&raiz, dado_musica_playlist3, comparar_dados_musica_playlist);
    inserir_arv_binaria(&raiz, dado_musica_playlist4, comparar_dados_musica_playlist);

    imprimir_arv_binaria(raiz, imprimir_dados_musica_playlist);

    remover_arv_binaria(&raiz, dado_musica_playlist3, liberar_dados_musica_playlist, comparar_dados_musica_playlist);
    printf("\n\nDepois de remover o dado musica playlist 3:\n");

    imprimir_arv_binaria(raiz, imprimir_dados_musica_playlist);

    liberar_arv_binaria(&raiz, liberar_dados_musica_playlist);

    printf("\n\nDepois de liberar a arvore de musicas playlists:\n");



    return 0;
}