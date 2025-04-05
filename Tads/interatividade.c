#include "../includes/interatividade.h"
#include "../includes/funcao_sistema.h"
#include "../includes/func_interatividade.h"
#include "../includes/arv_binaria.h"
#include <stdio.h>
#include <stdlib.h>

void menu_principal()
{
    ARV_BINARIA *raiz = NULL;
    ARTISTA *artista = NULL;
    ALBUM *album = NULL;
    MUSICA *musica = NULL;
    PLAYLIST *playlist = NULL;


    short int opcao = 0;

    do
    {
        printf("Menu Principal:\n");
        printf("1 - Cadastrar artista\n");
        printf("2 - Cadastrar albuns\n");
        printf("3 - Cadastrar musicas\n");
        printf("4 - Mostrar artistas\n");
        printf("5 - Mostrar artistas de um tipo\n");
        printf("6 - Mostrar artistas de um estilo musical\n");
        printf("7 - Mostrar artistas de um estilo musical e tipo\n");
        printf("8 - Mostrar albuns de um artista\n");
        printf("9 - Mostrar albuns de um ano de um artista\n");
        printf("10 - Mostrar musicas de um album de um artista\n");
        printf("11 - Mostrar dados de uma musica\n");
        printf("12 - Mostrar dados de uma playlist\n");
        printf("13 - Remover musica de uma playlist\n");
        printf("14 - Remover uma playlist\n");
        printf("15 - Remover uma musica de um album de um artista (So sera removido se nao estiver em playlists)\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");


        opcao = digitar_short_int();

        switch (opcao)
        {

        case 0:
            break; 

        case 1:
            artista = cadastrar_artista(artista);
            break;

        case 2:
            album = cadastrar_album(album);
            break;

        case 3:
            musica = cadastrar_musica(musica);
            break;

        case 4:
            printf("Artistas cadastrados:\n");
            imprimir_arv_binaria(raiz, imprimir_artista);
            break;

        case 5:
            printf("Artistas cadastrados de um tipo:\n");
            mostrar_art_por_tipo(raiz, artista);
            break;

        case 6:
            printf("Artistas cadastrados de um estilo musical:\n");
            mostrar_art_por_estilo(raiz, artista);
            break;

        case 7:
            printf("Artistas cadastrados de um estilo musical e tipo:\n");
            mostrar_art_por_tipo_e_estilo(raiz, artista);
            break;

        case 8:
            printf("Albuns cadastrados de um artista:\n");
            albuns_um_artista(raiz, artista);
            break;

        case 9:
            printf("Albuns cadastrados de um artista de um ano:\n");
            albuns_um_artista_um_ano(raiz, artista);

            break;

        case 10:
            printf("Musicas cadastradas de um album de um artista:\n");
            mostrar_musicas_album(raiz, album);
            break;

        case 11:
            printf("Dados de uma musica:\n");
            mostrar_dados_musica(raiz, musica);
            break;

        case 12:
            printf("Dados de uma playlist:\n");
            mostrar_dados_playlist(raiz, playlist);
            break;

        case 13:
            printf("Remover musica de uma playlist:\n");
            remover_musica_playlist(raiz, playlist);
            break;

        case 14:
            printf("Remover uma playlist:\n");
            remover_playlist(raiz, playlist);
            break;

        case 15:
            printf("Remover uma musica de um album de um artista:\n");
            remover_musica_de_album_de_artista(raiz, artista, album, musica);
            break;

        default:
            break;
        }

    } while (opcao != 0);
}