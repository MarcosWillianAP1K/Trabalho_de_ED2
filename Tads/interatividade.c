#include "../includes/interatividade.h"
#include "../includes/funcao_sistema.h"
#include "../includes/arv_binaria.h"
#include <stdio.h>
#include <stdlib.h>

void menu_principal()
{
    ARV_BINARIA *raiz = NULL;
    ARTISTA *artista = NULL;
    ALBUM *album = NULL;
    MUSICA *musica = NULL;


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
        printf("9 - Mostrar albuns de um ano do artista\n");
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
            printf("Digite o tipo: ");
            char tipo[50];
            scanf("%s", tipo);
            artista = buscar_artista_por_tipo(raiz, tipo);
            if (artista != NULL)
            {
                imprimir_artista(artista);
            }
            else
            {
                printf("Nenhum artista encontrado com o tipo %s\n", tipo);
            }
            break;

        case 6:
            printf("Artistas cadastrados de um estilo musical:\n");
            printf("Digite o estilo musical: ");
            char estilo_musical[50];
            scanf("%s", estilo_musical);
            artista = buscar_artista_por_estilo_musical(raiz, estilo_musical);
            if (artista != NULL)
            {
                imprimir_artista(artista);
            }
            else
            {
                printf("Nenhum artista encontrado com o estilo musical %s\n", estilo_musical);
            }
            break;

        case 7:
            printf("Artistas cadastrados de um estilo musical e tipo:\n");
            printf("Digite o estilo musical: ");
            char estilo_musical_tipo[50];
            scanf("%s", estilo_musical_tipo);
            printf("Digite o tipo: ");
            char tipo_tipo[50];
            scanf("%s", tipo_tipo);
            artista = buscar_artista_por_estilo_musical_e_tipo(raiz, estilo_musical_tipo, tipo_tipo);
            if (artista != NULL)
            {
                imprimir_artista(artista);
            }
            else
            {
                printf("Nenhum artista encontrado com o estilo musical %s e tipo %s\n", estilo_musical_tipo, tipo_tipo);
            }
            break;

        case 8:
            printf("Albuns cadastrados de um artista:\n");
            printf("Digite o nome do artista: ");
            char nome_artista[50];
            scanf("%s", nome_artista);
            artista = buscar_artista_por_nome(raiz, nome_artista);
            if (artista != NULL)
            {
                printf("Albuns do artista %s:\n", artista->nome);
                imprimir_arv_binaria(artista->albuns_raiz_arvore, imprimir_album);
            }
            else
            {
                printf("Nenhum artista encontrado com o nome %s\n", nome_artista);
            }
            break;

        case 9:
            printf("Albuns cadastrados de um artista de um ano:\n");
            printf("Digite o nome do artista: ");
            char nome_artista_ano[50];
            scanf("%s", nome_artista_ano);
            artista = buscar_artista_por_nome(raiz, nome_artista_ano);
            
            break;

        case 10:
            break;

        case 11:
            break;

        case 12:
            break;

        case 13:
            break;

        case 14:
            break;

        case 15:
            break;

        default:
            break;
        }

    } while (opcao != 0);
}