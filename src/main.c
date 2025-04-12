#include <stdio.h>
#include "../includes/interatividade.h"
#include "../includes/funcao_sistema.h"

// gcc src/main.c Tads/album.c Tads/artista.c Tads/arv_binaria.c Tads/funcao_sistema.c Tads/interatividade.c Tads/musica_playlist.c Tads/musica.c Tads/playlist.c Tads/dados.c

// Test Case 1
void inserir_teste1(ARV_BINARIA **raiz_artista, ARV_BINARIA **raiz_playlist)
{
    DADOS *teste_artista = alocar_dados();
    teste_artista->artista = criar_artista("artista_rock", "rock", "alternativo", 0, NULL);

    // Adiciona o artista a arvore
    inserir_arv_binaria(raiz_artista, teste_artista, comparar_dados_nome_artista);

    DADOS *teste_album = alocar_dados();
    teste_album->album = criar_album("album_rock", "2023-01-01", 0, NULL);

    // Adiciona o album ao artista
    ARV_BINARIA *inserir = teste_artista->artista->albuns_raiz_arvore;
    inserir_arv_binaria(&inserir, teste_album, comparar_dados_titulo_album);
    teste_artista->artista->albuns_raiz_arvore = inserir;

    teste_artista->artista->numero_de_albuns++;

    DADOS *teste_musica = alocar_dados();
    teste_musica->musica = criar_musica("musica_rock", "4.50");

    // Adiciona a musica ao album
    inserir = teste_album->album->musicas_raiz_arvore;
    inserir_arv_binaria(&inserir, teste_musica, comparar_dados_titulo_musica);
    teste_album->album->musicas_raiz_arvore = inserir;
    teste_album->album->numero_de_musicas++;

    DADOS *teste_playlist = alocar_dados();
    teste_playlist->playlist = criar_playlist("playlist_rock", 0, NULL);

    // Adiciona a playlist a arvore
    inserir_arv_binaria(raiz_playlist, teste_playlist, comparar_dados_nome_playlist);

    DADOS *teste_musica_playlist = alocar_dados();
    teste_musica_playlist->musica_playlist = criar_musica_playlist(teste_artista->artista->nome, teste_album->album->titulo, teste_musica->musica);

    inserir = teste_playlist->playlist->musicas_raiz_arvore;
    inserir_arv_binaria(&inserir, teste_musica_playlist, comparar_dados_titulo_musica_musica_playlist);
    teste_playlist->playlist->musicas_raiz_arvore = inserir;
    teste_playlist->playlist->numero_de_musicas++;
}

// Test Case 2
void inserir_teste2(ARV_BINARIA **raiz_artista, ARV_BINARIA **raiz_playlist)
{
    DADOS *teste_artista = alocar_dados();
    teste_artista->artista = criar_artista("artista_pop", "pop", "moderno", 0, NULL);

    // Adiciona o artista a arvore
    inserir_arv_binaria(raiz_artista, teste_artista, comparar_dados_nome_artista);

    DADOS *teste_album = alocar_dados();
    teste_album->album = criar_album("album_pop", "2024-06-15", 0, NULL);

    // Adiciona o album ao artista
    ARV_BINARIA *inserir = teste_artista->artista->albuns_raiz_arvore;
    inserir_arv_binaria(&inserir, teste_album, comparar_dados_titulo_album);
    teste_artista->artista->albuns_raiz_arvore = inserir;

    teste_artista->artista->numero_de_albuns++;

    DADOS *teste_musica = alocar_dados();
    teste_musica->musica = criar_musica("musica_pop", "3.45");

    // Adiciona a musica ao album
    inserir = teste_album->album->musicas_raiz_arvore;
    inserir_arv_binaria(&inserir, teste_musica, comparar_dados_titulo_musica);
    teste_album->album->musicas_raiz_arvore = inserir;
    teste_album->album->numero_de_musicas++;

    DADOS *teste_playlist = alocar_dados();
    teste_playlist->playlist = criar_playlist("playlist_pop", 0, NULL);

    // Adiciona a playlist a arvore
    inserir_arv_binaria(raiz_playlist, teste_playlist, comparar_dados_nome_playlist);

    DADOS *teste_musica_playlist = alocar_dados();
    teste_musica_playlist->musica_playlist = criar_musica_playlist(teste_artista->artista->nome, teste_album->album->titulo, teste_musica->musica);

    inserir = teste_playlist->playlist->musicas_raiz_arvore;
    inserir_arv_binaria(&inserir, teste_musica_playlist, comparar_dados_titulo_musica_musica_playlist);
    teste_playlist->playlist->musicas_raiz_arvore = inserir;
    teste_playlist->playlist->numero_de_musicas++;
}

// Test Case 3
void inserir_teste3(ARV_BINARIA **raiz_artista, ARV_BINARIA **raiz_playlist)
{
    DADOS *teste_artista = alocar_dados();
    teste_artista->artista = criar_artista("artista_jazz", "jazz", "fusion", 0, NULL);

    // Adiciona o artista a arvore
    inserir_arv_binaria(raiz_artista, teste_artista, comparar_dados_nome_artista);

    DADOS *teste_album = alocar_dados();
    teste_album->album = criar_album("album_jazz", "2022-11-11", 0, NULL);

    // Adiciona o album ao artista
    ARV_BINARIA *inserir = teste_artista->artista->albuns_raiz_arvore;
    inserir_arv_binaria(&inserir, teste_album, comparar_dados_titulo_album);
    teste_artista->artista->albuns_raiz_arvore = inserir;

    teste_artista->artista->numero_de_albuns++;

    DADOS *teste_musica = alocar_dados();
    teste_musica->musica = criar_musica("musica_jazz", "5.20");

    // Adiciona a musica ao album
    inserir = teste_album->album->musicas_raiz_arvore;
    inserir_arv_binaria(&inserir, teste_musica, comparar_dados_titulo_musica);
    teste_album->album->musicas_raiz_arvore = inserir;
    teste_album->album->numero_de_musicas++;

    DADOS *teste_playlist = alocar_dados();
    teste_playlist->playlist = criar_playlist("playlist_jazz", 0, NULL);

    // Adiciona a playlist a arvore
    inserir_arv_binaria(raiz_playlist, teste_playlist, comparar_dados_nome_playlist);

    DADOS *teste_musica_playlist = alocar_dados();
    teste_musica_playlist->musica_playlist = criar_musica_playlist(teste_artista->artista->nome, teste_album->album->titulo, teste_musica->musica);

    inserir = teste_playlist->playlist->musicas_raiz_arvore;
    inserir_arv_binaria(&inserir, teste_musica_playlist, comparar_dados_titulo_musica_musica_playlist);
    teste_playlist->playlist->musicas_raiz_arvore = inserir;
    teste_playlist->playlist->numero_de_musicas++;
}

// Test Case 4
void inserir_teste4(ARV_BINARIA **raiz_artista, ARV_BINARIA **raiz_playlist)
{
    DADOS *teste_artista = alocar_dados();
    teste_artista->artista = criar_artista("artista_mpb", "mpb", "tradicional", 0, NULL);

    // Adiciona o artista a arvore
    inserir_arv_binaria(raiz_artista, teste_artista, comparar_dados_nome_artista);

    DADOS *teste_album = alocar_dados();
    teste_album->album = criar_album("album_mpb", "2021-12-01", 0, NULL);

    // Adiciona o album ao artista
    ARV_BINARIA *inserir = teste_artista->artista->albuns_raiz_arvore;
    inserir_arv_binaria(&inserir, teste_album, comparar_dados_titulo_album);
    teste_artista->artista->albuns_raiz_arvore = inserir;

    teste_artista->artista->numero_de_albuns++;

    DADOS *teste_musica = alocar_dados();
    teste_musica->musica = criar_musica("musica_mpb", "4.00");

    // Adiciona a musica ao album
    inserir = teste_album->album->musicas_raiz_arvore;
    inserir_arv_binaria(&inserir, teste_musica, comparar_dados_titulo_musica);
    teste_album->album->musicas_raiz_arvore = inserir;
    teste_album->album->numero_de_musicas++;

    DADOS *teste_playlist = alocar_dados();
    teste_playlist->playlist = criar_playlist("playlist_mpb", 0, NULL);

    // Adiciona a playlist a arvore
    inserir_arv_binaria(raiz_playlist, teste_playlist, comparar_dados_nome_playlist);

    DADOS *teste_musica_playlist = alocar_dados();
    teste_musica_playlist->musica_playlist = criar_musica_playlist(teste_artista->artista->nome, teste_album->album->titulo, teste_musica->musica);

    inserir = teste_playlist->playlist->musicas_raiz_arvore;
    inserir_arv_binaria(&inserir, teste_musica_playlist, comparar_dados_titulo_musica_musica_playlist);
    teste_playlist->playlist->musicas_raiz_arvore = inserir;
    teste_playlist->playlist->numero_de_musicas++;
}

// Test Case 5
void inserir_teste5(ARV_BINARIA **raiz_artista, ARV_BINARIA **raiz_playlist)
{
    DADOS *teste_artista = alocar_dados();
    teste_artista->artista = criar_artista("artista_rap", "rap", "underground", 0, NULL);

    // Adiciona o artista a arvore
    inserir_arv_binaria(raiz_artista, teste_artista, comparar_dados_nome_artista);

    DADOS *teste_album = alocar_dados();
    teste_album->album = criar_album("album_rap", "2023-09-05", 0, NULL);

    // Adiciona o album ao artista
    ARV_BINARIA *inserir = teste_artista->artista->albuns_raiz_arvore;
    inserir_arv_binaria(&inserir, teste_album, comparar_dados_titulo_album);
    teste_artista->artista->albuns_raiz_arvore = inserir;

    teste_artista->artista->numero_de_albuns++;

    DADOS *teste_musica = alocar_dados();
    teste_musica->musica = criar_musica("musica_rap", "3.30");

    // Adiciona a musica ao album
    inserir = teste_album->album->musicas_raiz_arvore;
    inserir_arv_binaria(&inserir, teste_musica, comparar_dados_titulo_musica);
    teste_album->album->musicas_raiz_arvore = inserir;
    teste_album->album->numero_de_musicas++;

    DADOS *teste_playlist = alocar_dados();
    teste_playlist->playlist = criar_playlist("playlist_rap", 0, NULL);

    // Adiciona a playlist a arvore
    inserir_arv_binaria(raiz_playlist, teste_playlist, comparar_dados_nome_playlist);

    DADOS *teste_musica_playlist = alocar_dados();
    teste_musica_playlist->musica_playlist = criar_musica_playlist(teste_artista->artista->nome, teste_album->album->titulo, teste_musica->musica);

    inserir = teste_playlist->playlist->musicas_raiz_arvore;
    inserir_arv_binaria(&inserir, teste_musica_playlist, comparar_dados_titulo_musica_musica_playlist);
    teste_playlist->playlist->musicas_raiz_arvore = inserir;
    teste_playlist->playlist->numero_de_musicas++;
}

// Test Case 6
void inserir_teste6(ARV_BINARIA **raiz_artista, ARV_BINARIA **raiz_playlist)
{
    DADOS *teste_artista = alocar_dados();
    teste_artista->artista = criar_artista("artista_classico", "classico", "orquestral", 0, NULL);

    // Adiciona o artista a arvore
    inserir_arv_binaria(raiz_artista, teste_artista, comparar_dados_nome_artista);

    DADOS *teste_album = alocar_dados();
    teste_album->album = criar_album("album_classico", "2020-03-10", 0, NULL);

    // Adiciona o album ao artista
    ARV_BINARIA *inserir = teste_artista->artista->albuns_raiz_arvore;
    inserir_arv_binaria(&inserir, teste_album, comparar_dados_titulo_album);
    teste_artista->artista->albuns_raiz_arvore = inserir;

    teste_artista->artista->numero_de_albuns++;

    DADOS *teste_musica = alocar_dados();
    teste_musica->musica = criar_musica("musica_classica", "6.15");

    // Adiciona a musica ao album
    inserir = teste_album->album->musicas_raiz_arvore;
    inserir_arv_binaria(&inserir, teste_musica, comparar_dados_titulo_musica);
    teste_album->album->musicas_raiz_arvore = inserir;
    teste_album->album->numero_de_musicas++;

    DADOS *teste_playlist = alocar_dados();
    teste_playlist->playlist = criar_playlist("playlist_classica", 0, NULL);

    // Adiciona a playlist a arvore
    inserir_arv_binaria(raiz_playlist, teste_playlist, comparar_dados_nome_playlist);

    DADOS *teste_musica_playlist = alocar_dados();
    teste_musica_playlist->musica_playlist = criar_musica_playlist(teste_artista->artista->nome, teste_album->album->titulo, teste_musica->musica);

    inserir = teste_playlist->playlist->musicas_raiz_arvore;
    inserir_arv_binaria(&inserir, teste_musica_playlist, comparar_dados_titulo_musica_musica_playlist);
    teste_playlist->playlist->musicas_raiz_arvore = inserir;
    teste_playlist->playlist->numero_de_musicas++;
}

// Test Case 7
void inserir_teste7(ARV_BINARIA **raiz_artista, ARV_BINARIA **raiz_playlist)
{
    DADOS *teste_artista = alocar_dados();
    teste_artista->artista = criar_artista("artista_electronica", "eletronica", "techno", 0, NULL);

    // Adiciona o artista a arvore
    inserir_arv_binaria(raiz_artista, teste_artista, comparar_dados_nome_artista);

    DADOS *teste_album = alocar_dados();
    teste_album->album = criar_album("album_electronica", "2024-02-28", 0, NULL);

    // Adiciona o album ao artista
    ARV_BINARIA *inserir = teste_artista->artista->albuns_raiz_arvore;
    inserir_arv_binaria(&inserir, teste_album, comparar_dados_titulo_album);
    teste_artista->artista->albuns_raiz_arvore = inserir;

    teste_artista->artista->numero_de_albuns++;

    DADOS *teste_musica = alocar_dados();
    teste_musica->musica = criar_musica("musica_techno", "7.00");

    // Adiciona a musica ao album
    inserir = teste_album->album->musicas_raiz_arvore;
    inserir_arv_binaria(&inserir, teste_musica, comparar_dados_titulo_musica);
    teste_album->album->musicas_raiz_arvore = inserir;
    teste_album->album->numero_de_musicas++;

    DADOS *teste_playlist = alocar_dados();
    teste_playlist->playlist = criar_playlist("playlist_techno", 0, NULL);

    // Adiciona a playlist a arvore
    inserir_arv_binaria(raiz_playlist, teste_playlist, comparar_dados_nome_playlist);

    DADOS *teste_musica_playlist = alocar_dados();
    teste_musica_playlist->musica_playlist = criar_musica_playlist(teste_artista->artista->nome, teste_album->album->titulo, teste_musica->musica);

    inserir = teste_playlist->playlist->musicas_raiz_arvore;
    inserir_arv_binaria(&inserir, teste_musica_playlist, comparar_dados_titulo_musica_musica_playlist);
    teste_playlist->playlist->musicas_raiz_arvore = inserir;
    teste_playlist->playlist->numero_de_musicas++;
}

// Test Case 8
void inserir_teste8(ARV_BINARIA **raiz_artista, ARV_BINARIA **raiz_playlist)
{
    DADOS *teste_artista = alocar_dados();
    teste_artista->artista = criar_artista("artista_metal2", "metal", "roots", 0, NULL);

    // Adiciona o artista a arvore
    inserir_arv_binaria(raiz_artista, teste_artista, comparar_dados_nome_artista);

    DADOS *teste_album = alocar_dados();
    teste_album->album = criar_album("album_metal", "2022-05-20", 0, NULL);

    // Adiciona o album ao artista
    ARV_BINARIA *inserir = teste_artista->artista->albuns_raiz_arvore;
    inserir_arv_binaria(&inserir, teste_album, comparar_dados_titulo_album);
    teste_artista->artista->albuns_raiz_arvore = inserir;

    teste_artista->artista->numero_de_albuns++;

    DADOS *teste_musica = alocar_dados();
    teste_musica->musica = criar_musica("musica_metal", "4.20");

    // Adiciona a musica ao album
    inserir = teste_album->album->musicas_raiz_arvore;
    inserir_arv_binaria(&inserir, teste_musica, comparar_dados_titulo_musica);
    teste_album->album->musicas_raiz_arvore = inserir;
    teste_album->album->numero_de_musicas++;

    DADOS *teste_playlist = alocar_dados();
    teste_playlist->playlist = criar_playlist("playlist_metal", 0, NULL);

    // Adiciona a playlist a arvore
    inserir_arv_binaria(raiz_playlist, teste_playlist, comparar_dados_nome_playlist);

    DADOS *teste_musica_playlist = alocar_dados();
    teste_musica_playlist->musica_playlist = criar_musica_playlist(teste_artista->artista->nome, teste_album->album->titulo, teste_musica->musica);

    inserir = teste_playlist->playlist->musicas_raiz_arvore;
    inserir_arv_binaria(&inserir, teste_musica_playlist, comparar_dados_titulo_musica_musica_playlist);
    teste_playlist->playlist->musicas_raiz_arvore = inserir;
    teste_playlist->playlist->numero_de_musicas++;
}

// Test Case 9
void inserir_teste9(ARV_BINARIA **raiz_artista, ARV_BINARIA **raiz_playlist)
{
    DADOS *teste_artista = alocar_dados();
    teste_artista->artista = criar_artista("artista_metal", "metal", "thrash", 0, NULL);

    // Adiciona o artista a arvore
    inserir_arv_binaria(raiz_artista, teste_artista, comparar_dados_nome_artista);

    DADOS *teste_album = alocar_dados();
    teste_album->album = criar_album("album_metal", "2023-03-15", 0, NULL);

    // Adiciona o album ao artista
    ARV_BINARIA *inserir = teste_artista->artista->albuns_raiz_arvore;
    inserir_arv_binaria(&inserir, teste_album, comparar_dados_titulo_album);
    teste_artista->artista->albuns_raiz_arvore = inserir;

    teste_artista->artista->numero_de_albuns++;

    DADOS *teste_musica = alocar_dados();
    teste_musica->musica = criar_musica("musica_metal", "5.00");

    // Adiciona a musica ao album
    inserir = teste_album->album->musicas_raiz_arvore;
    inserir_arv_binaria(&inserir, teste_musica, comparar_dados_titulo_musica);
    teste_album->album->musicas_raiz_arvore = inserir;
    teste_album->album->numero_de_musicas++;

    DADOS *teste_playlist = alocar_dados();
    teste_playlist->playlist = criar_playlist("playlist_metal", 0, NULL);

    // Adiciona a playlist a arvore
    inserir_arv_binaria(raiz_playlist, teste_playlist, comparar_dados_nome_playlist);

    DADOS *teste_musica_playlist = alocar_dados();
    teste_musica_playlist->musica_playlist = criar_musica_playlist(teste_artista->artista->nome, teste_album->album->titulo, teste_musica->musica);

    inserir = teste_playlist->playlist->musicas_raiz_arvore;
    inserir_arv_binaria(&inserir, teste_musica_playlist, comparar_dados_titulo_musica_musica_playlist);
    teste_playlist->playlist->musicas_raiz_arvore = inserir;
    teste_playlist->playlist->numero_de_musicas++;
}

// Test Case 10
void inserir_teste10(ARV_BINARIA **raiz_artista, ARV_BINARIA **raiz_playlist)
{
    DADOS *teste_artista = alocar_dados();
    teste_artista->artista = criar_artista("artista_blues", "blues", "delta", 0, NULL);

    // Adiciona o artista a arvore
    inserir_arv_binaria(raiz_artista, teste_artista, comparar_dados_nome_artista);

    DADOS *teste_album = alocar_dados();
    teste_album->album = criar_album("album_blues", "2021-08-30", 0, NULL);

    // Adiciona o album ao artista
    ARV_BINARIA *inserir = teste_artista->artista->albuns_raiz_arvore;
    inserir_arv_binaria(&inserir, teste_album, comparar_dados_titulo_album);
    teste_artista->artista->albuns_raiz_arvore = inserir;

    teste_artista->artista->numero_de_albuns++;

    DADOS *teste_musica = alocar_dados();
    teste_musica->musica = criar_musica("musica_blues", "4.45");

    // Adiciona a musica ao album
    inserir = teste_album->album->musicas_raiz_arvore;
    inserir_arv_binaria(&inserir, teste_musica, comparar_dados_titulo_musica);
    teste_album->album->musicas_raiz_arvore = inserir;
    teste_album->album->numero_de_musicas++;

    DADOS *teste_playlist = alocar_dados();
    teste_playlist->playlist = criar_playlist("playlist_blues", 0, NULL);

    // Adiciona a playlist a arvore
    inserir_arv_binaria(raiz_playlist, teste_playlist, comparar_dados_nome_playlist);

    DADOS *teste_musica_playlist = alocar_dados();
    teste_musica_playlist->musica_playlist = criar_musica_playlist(teste_artista->artista->nome, teste_album->album->titulo, teste_musica->musica);

    inserir = teste_playlist->playlist->musicas_raiz_arvore;
    inserir_arv_binaria(&inserir, teste_musica_playlist, comparar_dados_titulo_musica_musica_playlist);
    teste_playlist->playlist->musicas_raiz_arvore = inserir;
    teste_playlist->playlist->numero_de_musicas++;
}

int main()
{
    ARV_BINARIA *raiz_artista = NULL;
    ARV_BINARIA *raiz_playlist = NULL;

    inserir_teste1(&raiz_artista, &raiz_playlist);
    inserir_teste2(&raiz_artista, &raiz_playlist);
    inserir_teste3(&raiz_artista, &raiz_playlist);
    inserir_teste4(&raiz_artista, &raiz_playlist);
    inserir_teste5(&raiz_artista, &raiz_playlist);
    inserir_teste6(&raiz_artista, &raiz_playlist);
    inserir_teste7(&raiz_artista, &raiz_playlist);
    inserir_teste8(&raiz_artista, &raiz_playlist);
    inserir_teste9(&raiz_artista, &raiz_playlist);
    inserir_teste10(&raiz_artista, &raiz_playlist);

    menu_principal(&raiz_artista, &raiz_playlist);

    // Não ta funcionando direito, verificar
    printf("Liberando memoria...\n");
    delete_all(&raiz_artista, &raiz_playlist);

    printf("Programa encerrado.\n");

    return 0;
}