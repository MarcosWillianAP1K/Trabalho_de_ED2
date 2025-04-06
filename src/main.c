#include <stdio.h>
#include "../includes/interatividade.h"
#include "../includes/funcao_sistema.h"

// gcc src/main.c Tads/album.c Tads/artista.c Tads/arv_binaria.c Tads/funcao_sistema.c Tads/interatividade.c Tads/musica_playlist.c Tads/musica.c Tads/playlist.c Tads/dados.c

void inserir_testes(ARV_BINARIA **raiz_artista, ARV_BINARIA **raiz_playlist)
{
    DADOS *teste_artista = alocar_dados();
    teste_artista->artista = criar_artista("teste_artista", "teste_tipo", "teste_estilo", 0, NULL);

    // Adiciona o artista a arvore
    inserir_arv_binaria(raiz_artista, teste_artista, comparar_dados_nome_artista);

    DADOS *teste_album = alocar_dados();
    teste_album->album = criar_album("teste_album", "teste_data", 0, NULL);

    // Adiciona o album ao artista
    ARV_BINARIA *inserir = (*raiz_artista)->info->artista->albuns_raiz_arvore;
    inserir_arv_binaria(&inserir, teste_album, comparar_dados_titulo_album);
    (*raiz_artista)->info->artista->albuns_raiz_arvore = inserir;

    teste_artista->artista->numero_de_albuns++;

    DADOS *teste_musica = alocar_dados();
    teste_musica->musica = criar_musica("teste_musica", "9.99");

    
    // Adiciona a musica ao album
    inserir = teste_album->album->musicas_raiz_arvore;
    inserir_arv_binaria(&inserir, teste_musica, comparar_dados_titulo_musica);
    teste_album->album->musicas_raiz_arvore = inserir;
    teste_album->album->numero_de_musicas++;



    DADOS *teste_playlist = alocar_dados();
    teste_playlist->playlist = criar_playlist("teste_playlist", 0, NULL);

    // Adiciona a playlist a arvore
    inserir_arv_binaria(raiz_playlist, teste_playlist, comparar_dados_nome_playlist);

    inserir = teste_playlist->playlist->musicas_raiz_arvore;
    inserir_arv_binaria(&inserir, teste_musica, comparar_dados_titulo_musica_musica_playlist);
    teste_playlist->playlist->musicas_raiz_arvore = inserir;
    teste_playlist->playlist->numero_de_musicas++;
}

int main()
{
    ARV_BINARIA *raiz_artista = NULL;
    ARV_BINARIA *raiz_playlist = NULL;

    // Teste de inserção de artista e playlist
    inserir_testes(&raiz_artista, &raiz_playlist);

    menu_principal(&raiz_artista, &raiz_playlist);

    // Não ta funcionando direito, verificar
    delete_all(&raiz_artista, &raiz_playlist);

    printf("Programa encerrado.\n");

    return 0;
}