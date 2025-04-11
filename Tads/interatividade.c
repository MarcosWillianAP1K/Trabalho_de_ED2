#include "../includes/interatividade.h"
#include "../includes/funcao_sistema.h"
#include <stdio.h>
#include <stdlib.h>

void verificacao_cadastro_artista(short int n)
{
    if (n == 1)
    {
        mensagem_sucesso("Artista cadastrado com sucesso!");
    }
    else
    {
        mensagem_erro("Artista nao cadastrado, nome ja existente!");
    }
}

void verificacao_cadastro_album(short int n)
{
    if (n == 1)
    {
        mensagem_sucesso("Album cadastrados com sucesso!");
    }
    else if (n == -1)
    {
        mensagem_erro("Artista nao encontrado!");
    }
    else
    {
        mensagem_erro("Album nao cadastrado, titulo ja existente!");
    }
}

void verificacao_cadastro_musica(short int n)
{
    if (n == 1)
    {
        mensagem_sucesso("Musica cadastrada com sucesso!");
    }
    else if (n == -1)
    {
        mensagem_erro("Artista nao encontrado!");
    }
    else if (n == -2)
    {
        mensagem_erro("Album nao encontrado!");
    }
    else
    {
        mensagem_erro("Musica nao cadastrada, titulo ja existente!");
    }
}

void verificacao_cadastro_playlist(short int n)
{
    if (n == 1)
    {
        mensagem_sucesso("Playlist cadastrada com sucesso!");
    }
    else
    {
        mensagem_erro("Playlist nao cadastrada, nome ja existente!");
    }
}

void verificacao_cadastro_musica_playlist(short int n)
{
    if (n == 1)
    {
        mensagem_sucesso("Musica cadastrada na playlist com sucesso!");
    }
    else if (n == -1)
    {
        mensagem_erro("Playlist nao encontrada!");
    }
    else if (n == -2)
    {
        mensagem_erro("Artista nao encontrado!");
    }
    else if (n == -3)
    {
        mensagem_erro("Album nao encontrado!");
    }
    else if (n == -4)
    {
        mensagem_erro("Musica nao encontrada!");
    }
    else
    {
        mensagem_erro("Musica ja existe na playlist!");
    }
}



void menu_principal(ARV_BINARIA **raiz_artista, ARV_BINARIA **raiz_playlist)
{

    short int opcao = 0;
    short int retorno = 0;

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
        printf("15 - Mostrar playlists\n");
        printf("16 - Mostrar dados de uma playlist\n");
        printf("17 - Remover musica de uma playlist\n");
        printf("18 - Remover uma playlist\n");
        printf("19 - Remover uma musica de um album de um artista (So sera removido se nao estiver em playlists)\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        opcao = digitar_short_int();

        limpar_tela();

        switch (opcao)
        {

        case 0:
            break;

        case 1:
            printf("Cadastrar artista:\n");
            verificacao_cadastro_artista(cadastrar_artista(raiz_artista));
            pausar_tela();
            break;

        case 2:
            printf("Cadastrar albuns:\n");
            verificacao_cadastro_album(cadastrar_albuns(raiz_artista));
            pausar_tela();
            break;

        case 3:
            printf("Cadastrar musicas:\n");
            verificacao_cadastro_musica(cadastrar_musica(raiz_artista));
            pausar_tela();
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
            mostrar_dados_de_uma_musica(*raiz_artista);
            pausar_tela();
            break;

        case 13:
            printf("Cadastrar playlist:\n");
            verificacao_cadastro_playlist(cadastrar_playlist(raiz_playlist));
            pausar_tela();
            break;

        case 14:
            printf("Cadastrar musica em uma playlist:\n");
            verificacao_cadastro_musica_playlist(cadastrar_musica_em_uma_playlist(raiz_playlist, raiz_artista));
            pausar_tela();
            break;

        case 15:
            printf("Mostrar playlists:\n");
            imprimir_arv_binaria(*raiz_playlist, imprimir_dados_playlist);
            pausar_tela();
            break;

        case 16:
            printf("Mostrar dados de uma playlist:\n");
            mostrar_dados_de_uma_playlist(*raiz_playlist);
            pausar_tela();
            break;

        case 17:
            printf("Remover musica de uma playlist:\n");
            remover_musica_de_uma_playlist(raiz_playlist);
            break;

        case 18:
            printf("Remover uma playlist:\n");
            remover_playlist(raiz_playlist);
            break;

        case 19:
            printf("Remover uma musica de um album de um artista:\n");
            remover_musica_de_album_de_artista(raiz_artista, raiz_playlist);
            break;

        default:
            break;
        }

    } while (opcao != 0);
}
