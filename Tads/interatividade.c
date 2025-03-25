#include "../includes/interatividade.h"
#include "../includes/funcao_sistema.h"
#include <stdio.h>
#include <stdlib.h>

void menu_principal()
{

    char opcao = '0';

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
        printf("9 - Mostrar albuns de um ano do artista\n");
        printf("10 - Mostrar musicas de um album de um artista\n");
        printf("11 - Mostrar dados de uma musica\n");
        printf("12 - Mostrar dados de uma playlist\n");
        printf("13 - Remover musica de uma playlist\n");
        printf("14 - Remover uma playlist\n");
        printf("15 - Remover uma musica de um album de um artista (So sera removido se nao estiver em playlists)\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");


        opcao = digitar_um_caracter();

        switch (opcao)
        {

        case '0':
            break; 

        case '1':
            break;

        case '2':
            break;

        case '3':
            break;

        case '4':
            break;

        case '5':
            break;

        case '6':
            break;

        case '7':
            break;

        case '8':
            break;

        case '9':
            break;

        case '10':
            break;

        case '11':
            break;

        case '12':
            break;

        case '13':
            break;

        case '14':
            break;

        case '15':
            break;

        default:
            break;
        }

    } while (opcao != '0');
}