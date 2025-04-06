#include "../includes/interatividade.h"
#include "../includes/funcao_sistema.h"
#include <stdio.h>
#include <stdlib.h>

void menu_principal(ARV_BINARIA **raiz_artista, ARV_BINARIA **raiz_playlist)
{

    short int opcao = 0;

    do
    {
        limpar_tela();

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
        printf("11 - Mostrar albuns de todos artista de um ano\n");
        printf("12 - Mostrar dados de uma musica\n");
        printf("13 - Cadastrar playlist\n");
        printf("14 - Cadastrar musica em uma playlist\n");
        printf("15 - Mostrar dados de uma playlist\n");
        printf("16 - Remover musica de uma playlist\n");
        printf("17 - Remover uma playlist\n");
        printf("18 - Remover uma musica de um album de um artista (So sera removido se nao estiver em playlists)");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        opcao = digitar_short_int();

        limpar_tela();

        switch (opcao)
        {

        case 0:
            break;

        case 1:
            cadastrar_artista(raiz_artista);
            break;

        case 2:
            cadastrar_albuns(raiz_artista);
            break;

        case 3:
            cadastrar_musica(raiz_artista);
            break;

        case 4:
            printf("Artistas cadastrados:\n");
            imprimir_arv_binaria(*raiz_artista, imprimir_dados_artista);
            pausar_tela();
            break;

        case 5:
            printf("Artistas cadastrados de um tipo:\n");
            mostrar_artista_por_tipo(*raiz_artista);
            pausar_tela();
            break;

        case 6:
            printf("Artistas cadastrados de um estilo musical:\n");
            mostrar_artista_por_estilo(*raiz_artista);
            pausar_tela();
            break;

        case 7:
            printf("Artistas cadastrados de um estilo musical e tipo:\n");
            mostrar_artista_por_tipo_e_estilo(*raiz_artista);
            pausar_tela();
            break;

        case 8:
            printf("Albuns cadastrados de um artista:\n");
            mostrar_albuns_de_um_artista(*raiz_artista);
            pausar_tela();
            break;

        case 9:
            printf("Albuns cadastrados de um artista de um ano:\n");
            mostrar_albuns_de_um_artista_de_um_ano(*raiz_artista);
            pausar_tela();
            break;

        case 10:
            printf("Musicas cadastradas de um album de um artista:\n");
            mostrar_musicas_de_um_album_de_um_artista(*raiz_artista);
            pausar_tela();
            break;

        case 11:
            printf("Albuns cadastrados de todos artista de um ano:\n");
            mostrar_albuns_de_todos_artistas_de_um_ano(*raiz_artista);
            pausar_tela();
            break;

        case 12:
            printf("Dados de uma musica:\n");
            mostrar_dados_de_uma_musica(*raiz_playlist);
            pausar_tela();
            break;

        case 13:
            printf("Cadastrar playlist:\n");
            // cadastrar_playlist(raiz_playlist);
            break;

        case 14:
            printf("Cadastrar musica em uma playlist:\n");
            // cadastrar_musica_em_playlist(raiz_playlist, raiz_artista);
            break;
        
        case 15:
            printf("Mostrar dados de uma playlist:\n");
            // mostrar_dados_de_uma_playlist(raiz_playlist);
            break;
        
        case 16:
            printf("Remover musica de uma playlist:\n");
            // remover_musica_de_playlist(raiz_playlist);
            break;
        
        case 17:
            printf("Remover uma playlist:\n");
            // remover_playlist(raiz_playlist);
            break;

        case 18:
            printf("Remover uma musica de um album de um artista:\n");
            // remover_musica_de_album(raiz_artista, raiz_playlist);
            break;



        default:
            break;
        }

    } while (opcao != 0);
}