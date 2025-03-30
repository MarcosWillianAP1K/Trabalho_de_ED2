#include "../includes/func_interatividade.h"
#include <stdio.h>
#include <stdlib.h>

void mostrar_art_por_tipo(ARV_BINARIA *raiz, ARTISTA *artista) {
    printf("Digite o tipo: ");
    char tipo[50];
    scanf("%s", tipo);
    artista = buscar_artista_por_tipo(raiz, tipo);
    if (artista != NULL) {
        imprimir_artista(artista);
    } else {
        printf("Nenhum artista encontrado com o tipo %s\n", tipo);
    }
}
void mostrar_art_por_estilo(ARV_BINARIA *raiz, ARTISTA *artista) {
    printf("Digite o estilo: ");
    char estilo[50];
    scanf("%s", estilo);
    artista = buscar_artista_por_estilo(raiz, estilo);
    if (artista != NULL) {
        imprimir_artista(artista);
    } else {
        printf("Nenhum artista encontrado com o estilo %s\n", estilo);
    }
}  

void mostrar_art_por_tipo_e_estilo(ARV_BINARIA *raiz, ARTISTA *artista) {
    printf("Digite o tipo: ");
    char tipo[50];
    scanf("%s", tipo);
    printf("Digite o estilo: ");
    char estilo[50];
    scanf("%s", estilo);
    artista = buscar_artista_por_tipo_e_estilo(raiz, tipo, estilo);
    if (artista != NULL) {
        imprimir_artista(artista);
    } else {
        printf("Nenhum artista encontrado com o tipo %s e estilo %s\n", tipo, estilo);
    }
}

void albuns_um_artista(ARV_BINARIA *raiz, ARTISTA *artista) {
    printf("Digite o nome do artista: ");
    char nome_artista[50];
    scanf("%s", nome_artista);
    artista = buscar_artista_por_nome(raiz, nome_artista);
    if (artista != NULL) {
        printf("Albuns do artista %s:\n", artista->nome);
        imprimir_arv_binaria(artista->albuns_raiz_arvore, imprimir_album);
    } else {
        printf("Nenhum artista encontrado com o nome %s\n", nome_artista);
    }
}

void albuns_um_artista_um_ano(ARV_BINARIA *raiz, ARTISTA *artista) {
    printf("Digite o nome do artista: ");
    char nome_artista[50];
    scanf("%s", nome_artista);
    artista = buscar_artista_por_nome(raiz, nome_artista);
    if (artista != NULL) {
        printf("Digite o ano: ");
        int ano;
        scanf("%d", &ano);
        printf("Albuns do artista %s no ano %d:\n", artista->nome, ano);
        imprimir_albuns_por_ano(artista->albuns_raiz_arvore, ano, imprimir_album);
    } else {
        printf("Nenhum artista encontrado com o nome %s\n", nome_artista);
    }
}

void mostra_r_musicas_album(ARV_BINARIA *raiz, ALBUM *album) {
    printf("Digite o nome do album: ");
    char nome_album[50];
    scanf("%s", nome_album);
    album = buscar_album_por_nome(raiz, nome_album);
    if (album != NULL) {
        printf("Musicas do album %s:\n", album->titulo);
        imprimir_arv_binaria(album->musicas_raiz_arvore, imprimir_musica);
    } else {
        printf("Nenhum album encontrado com o nome %s\n", nome_album);
    }
}

void mostrar_dados_musica(ARV_BINARIA *raiz, MUSICA *musica) {
    printf("Digite o nome da musica: ");
    char nome_musica[50];
    scanf("%s", nome_musica);
    musica = buscar_musica_por_nome(raiz, nome_musica);
    if (musica != NULL) {
        printf("Dados da musica %s:\n", musica->titulo);
        imprimir_musica(musica);
    } else {
        printf("Nenhuma musica encontrada com o nome %s\n", nome_musica);
    }
}

void mostrar_dados_playlist(ARV_BINARIA *raiz, PLAYLIST *playlist) {
    printf("Digite o nome da playlist: ");
    char nome_playlist[50];
    scanf("%s", nome_playlist);
    playlist = buscar_playlist_por_nome(raiz, nome_playlist);
    if (playlist != NULL) {
        printf("Dados da playlist %s:\n", playlist->nome);
        imprimir_playlist(playlist);
    } else {
        printf("Nenhuma playlist encontrada com o nome %s\n", nome_playlist);
    }
}

void remover_musica_playlist(ARV_BINARIA *raiz, PLAYLIST *playlist) {
    printf("Digite o nome da playlist: ");
    char nome_playlist[50];
    scanf("%s", nome_playlist);
    playlist = buscar_playlist_por_nome(raiz, nome_playlist);
    if (playlist != NULL) {
        printf("Digite o nome da musica: ");
        char nome_musica[50];
        scanf("%s", nome_musica);
        remover_musica_da_playlist(playlist, nome_musica);
    } else {
        printf("Nenhuma playlist encontrada com o nome %s\n", nome_playlist);
    }
}
void remover_playlist(ARV_BINARIA *raiz, PLAYLIST *playlist) {
    printf("Digite o nome da playlist: ");
    char nome_playlist[50];
    scanf("%s", nome_playlist);
    playlist = buscar_playlist_por_nome(raiz, nome_playlist);
    if (playlist != NULL) {
        remover_playlist_da_arvore(raiz, playlist);
        printf("Playlist %s removida com sucesso.\n", nome_playlist);
    } else {
        printf("Nenhuma playlist encontrada com o nome %s\n", nome_playlist);
    }
}

void remover_musica_de_album_de_artista(ARV_BINARIA *raiz, ARTISTA *artista, ALBUM *album, MUSICA *musica) {
    printf("Digite o nome do artista: ");
    char nome_artista[50];
    scanf("%s", nome_artista);
    artista = buscar_artista_por_nome(raiz, nome_artista);
    if (artista != NULL) {
        printf("Digite o nome do album: ");
        char nome_album[50];
        scanf("%s", nome_album);
        album = buscar_album_por_nome(artista->albuns_raiz_arvore, nome_album);
        if (album != NULL) {
            printf("Digite o nome da musica: ");
            char nome_musica[50];
            scanf("%s", nome_musica);
            musica = buscar_musica_por_nome(album->musicas_raiz_arvore, nome_musica);
            if (musica != NULL) {
                remover_musica_do_album(artista, album, musica);
                printf("Musica %s removida do album %s do artista %s.\n", musica->titulo, album->titulo, artista->nome);
            } else {
                printf("Nenhuma musica encontrada com o nome %s\n", nome_musica);
            }
        } else {
            printf("Nenhum album encontrado com o nome %s\n", nome_album);
        }
    } else {
        printf("Nenhum artista encontrado com o nome %s\n", nome_artista);
    }
}