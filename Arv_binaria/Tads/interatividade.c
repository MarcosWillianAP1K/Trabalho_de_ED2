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
    else if (n == 0)
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
    else if (n == 0)
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
    else if (n == 0)
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
    else if (n == 0)
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
    else if (n == 0)
    {
        mensagem_erro("Musica ja existe na playlist!");
    }
}

void verificacao_remover_playlist(short int n)
{
    if (n == 1)
    {
        mensagem_sucesso("Playlist removida com sucesso!");
    }
    else if (n == 0)
    {
        mensagem_erro("Playlist nao encontrada!");
    }
}

void verificacao_remover_musica_playlist(short int n)
{
    if (n == 1)
    {
        mensagem_sucesso("Musica removida da playlist com sucesso!");
    }
    else if (n == -1)
    {
        mensagem_erro("Playlist nao encontrada!");
    }
    else if (n == 0)
    {
        mensagem_erro("Musica nao encontrada!");
    }
}

void verificacao_remover_musica_album_artista(short int n)
{
    if (n == 1)
    {
        mensagem_sucesso("Musica removida do album com sucesso!");
    }
    else if (n == -1)
    {
        mensagem_erro("Artista nao encontrado!");
    }
    else if (n == -2)
    {
        mensagem_erro("Album nao encontrado!");
    }
    else if (n == -3)
    {
        mensagem_erro("A musica esta em uma playlist!");
    }
    else if (n == 0)
    {
        mensagem_erro("Musica nao encontrada!");
    }
}



DADOS *digitar_nome_artista()
{
    DADOS *aux = alocar_dados();

    printf("Digite nome do artista\n");
    char *nome = digitar_string();

    aux->artista = criar_artista(nome, "auxiliar", "auxiliar", 0, NULL);

    return aux;
}

DADOS *digitar_tipo_artista()
{
    DADOS *aux = alocar_dados();

    printf("Digite o tipo do artista\n");
    char *tipo = digitar_string();

    aux->artista = criar_artista("auxiliar", tipo, "auxiliar", 0, NULL);

    return aux;
}

DADOS *digitar_estilo_artista()
{
    DADOS *aux = alocar_dados();

    printf("Digite o estilo musical do artista\n");
    char *estilo = digitar_string();

    aux->artista = criar_artista("auxiliar", "auxiliar", estilo, 0, NULL);

    return aux;
}

DADOS *digitar_tipo_e_estilo_artista()
{
    DADOS *aux = alocar_dados();

    printf("Digite o tipo do artista\n");
    char *tipo = digitar_string();

    printf("Digite o estilo musical do artista\n");
    char *estilo = digitar_string();

    aux->artista = criar_artista("auxiliar", tipo, estilo, 0, NULL);

    return aux;
}

DADOS *digitar_titulo_album()
{
    DADOS *aux = alocar_dados();

    printf("Digite o titulo do album\n");
    char *titulo = digitar_string();

    aux->album = criar_album(titulo, 0, 0, NULL);

    return aux;
}

DADOS *digitar_ano_album()
{
    DADOS *aux = alocar_dados();

    printf("Digite o ano de lancamento do album\n");

    aux->album = criar_album("auxiliar", digitar_short_int(), 0, NULL);

    return aux;
}

DADOS *digitar_titulo_ano_album()
{
    DADOS *aux = alocar_dados();

    printf("Digite o titulo do album\n");
    char *titulo = digitar_string();

    printf("Digite a data de lancamento do album\n");

    aux->album = criar_album(titulo, digitar_short_int(), 0, NULL);

    return aux;
}

DADOS *digitar_titulo_musica()
{
    DADOS *aux = alocar_dados();

    printf("Digite o titulo da musica\n");
    char *titulo = digitar_string();

    aux->musica = criar_musica(titulo, 1, 1);

    return aux;
}

DADOS *digitar_nome_playlist()
{
    DADOS *aux = alocar_dados();

    printf("Digite o nome da playlist\n");
    char *nome_playlist = digitar_string();

    aux->playlist = criar_playlist(nome_playlist, 0, NULL);

    return aux;
}

DADOS *digitar_musica_playlist()
{
    DADOS *aux = alocar_dados();

    printf("Digite o nome do artista\n");
    char *nome_artista = digitar_string();

    printf("Digite o titulo do album\n");
    char *titulo_album = digitar_string();

    printf("Digite o titulo da musica\n");
    char *titulo_musica = digitar_string();

    MUSICA *musica = criar_musica(titulo_musica, 0, 0);

    aux->musica_playlist = criar_musica_playlist(nome_artista, titulo_album, musica);

    return aux;
}



DADOS *digitar_cadastro_artista(ARV_BINARIA *raiz_artista)
{
    print_amarelo("Deixe os campos vazios para sair (Menos os que envolve numeros)\n\n");
    DADOS *aux = alocar_dados();

    printf("Digite o nome do artista\n");
    char *nome = digitar_string();

    printf("Digite o tipo do artista\n");
    char *tipo = digitar_string();

    printf("Digite o estilo musical do artista\n");
    char *estilo = digitar_string();

    aux->artista = criar_artista(nome, tipo, estilo, 0, NULL);

    if (comparar_se_esta_vazio(aux->artista->nome) == 0 || comparar_se_esta_vazio(aux->artista->tipo) == 0 || comparar_se_esta_vazio(aux->artista->estilo_musical) == 0)
    {
        liberar_dados_artista(&aux);
    }
    else if (buscar_arv_binaria(raiz_artista, aux, comparar_dados_nome_artista) != NULL)
    {
        liberar_dados_artista(&aux);
    }

    return aux;
}

DADOS *digitar_cadastro_album(DADOS *artista)
{
    DADOS *aux = NULL;

    if (artista != NULL && artista->artista != NULL)
    {

        print_amarelo("Deixe os campos vazios para sair (Menos os que envolve numeros)\n\n");

        aux = alocar_dados();

        printf("Digite o titulo do album: ");
        char *titulo = digitar_string();

        printf("Digite o ano de lancamento do album: ");

        aux->album = criar_album(titulo, digitar_short_int(), 0, NULL);

        if (comparar_se_esta_vazio(aux->album->titulo) == 0)
        {
            liberar_dados_album(&aux);
        }
        else if (buscar_arv_binaria(artista->artista->albuns_raiz_arvore, aux, comparar_dados_titulo_album) != NULL)
        {
            liberar_dados_album(&aux);
        }
    }

    return aux;
}

DADOS *digitar_cadastro_musica(DADOS *album)
{
    DADOS *aux = NULL;

    if (album != NULL)
    {
        printf("Digite o titulo da musica: ");
        char *titulo = digitar_string();

        printf("Digite o duracao da musica\n");
        printf("Digite os minutos: ");
        short int minutos = digitar_short_int();

        printf("Digite os segundos: ");
        short int segundos;

        while ((segundos = digitar_short_int()) > 59)
        {
            mensagem_erro("Segundos invalidos, digite novamente\n");
            printf("Digite os segundos: ");
        }

        aux->musica = criar_musica(titulo, minutos, segundos);

        if (comparar_se_esta_vazio(aux->musica->titulo) == 0)
        {
            liberar_dados_musica(&aux);
        }
        else if (buscar_arv_binaria(album->album->musicas_raiz_arvore, aux, comparar_dados_titulo_musica) != NULL)
        {
            liberar_dados_musica(&aux);
        }
    }

    return aux;
}





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
            limpar_tela();
            print_amarelo("Cadastrar artista:\n");
            verificacao_cadastro_artista(cadastrar_artista(raiz_artista, digitar_cadastro_artista(*raiz_artista)));
            pausar_tela();
            break;

        case 2:
        {
            print_amarelo("Cadastrar albuns:\n");

            ARV_BINARIA *artista_encontrado = encontrar_dado_na_arv_digitando(*raiz_artista, digitar_nome_artista, comparar_dados_nome_artista, liberar_dados_artista);

            if (artista_encontrado != NULL)
            {
                verificacao_cadastro_album(cadastrar_albuns(artista_encontrado->info, digitar_cadastro_album(artista_encontrado->info)));
            }
            else
            {
                mensagem_erro("Artista nao encontrado!");
            }

            pausar_tela();
        }
        break;

        case 3:
        {
            print_amarelo("Cadastrar musicas:\n");

            
            ARV_BINARIA *artista_encontrado = encontrar_dado_na_arv_digitando(*raiz_artista, digitar_nome_artista, comparar_dados_nome_artista, liberar_dados_artista);
            

            if (artista_encontrado != NULL)
            {
                ARV_BINARIA *album_encontrado = encontrar_dado_na_arv_digitando(artista_encontrado->info->artista->albuns_raiz_arvore, digitar_titulo_album, comparar_dados_titulo_album, liberar_dados_album);

                if (album_encontrado != NULL)
                {
                    verificacao_cadastro_musica(cadastrar_musica(album_encontrado->info, digitar_cadastro_musica(album_encontrado->info)));
                }
                else
                {
                    mensagem_erro("Album nao encontrado!");
                }
            }
            else
            {
                mensagem_erro("Artista nao encontrado!");
            }
            pausar_tela();
        }
            break;

        case 4:
            print_amarelo("Artistas cadastrados:\n");
            imprimir_arv_binaria(*raiz_artista, imprimir_dados_artista);
            pausar_tela();
            break;

        case 5:
            print_amarelo("Artistas cadastrados de um tipo:\n");
            mostrar_artista_por_tipo(*raiz_artista);
            pausar_tela();
            break;

        case 6:
            print_amarelo("Artistas cadastrados de um estilo musical:\n");
            mostrar_artista_por_estilo(*raiz_artista);
            pausar_tela();
            break;

        case 7:
            print_amarelo("Artistas cadastrados de um estilo musical e tipo:\n");
            mostrar_artista_por_tipo_e_estilo(*raiz_artista);
            pausar_tela();
            break;

        case 8:
            print_amarelo("Albuns cadastrados de um artista:\n");
            mostrar_albuns_de_um_artista(*raiz_artista);
            pausar_tela();
            break;

        case 9:
            print_amarelo("Albuns cadastrados de um artista de um ano:\n");
            mostrar_albuns_de_um_artista_de_um_ano(*raiz_artista);
            pausar_tela();
            break;

        case 10:
            print_amarelo("Musicas cadastradas de um album de um artista:\n");
            mostrar_musicas_de_um_album_de_um_artista(*raiz_artista);
            pausar_tela();
            break;

        case 11:
            print_amarelo("Albuns cadastrados de todos artista de um ano:\n");
            mostrar_albuns_de_todos_artistas_de_um_ano(*raiz_artista);
            pausar_tela();
            break;

        case 12:
            print_amarelo("Dados de uma musica:\n");
            mostrar_dados_de_uma_musica(*raiz_artista);
            pausar_tela();
            break;

        case 13:
            print_amarelo("Cadastrar playlist:\n");
            verificacao_cadastro_playlist(cadastrar_playlist(raiz_playlist));
            pausar_tela();
            break;

        case 14:
            print_amarelo("Cadastrar musica em uma playlist:\n");
            verificacao_cadastro_musica_playlist(cadastrar_musica_em_uma_playlist(raiz_playlist, raiz_artista));
            pausar_tela();
            break;

        case 15:
            print_amarelo("Mostrar playlists:\n");
            imprimir_arv_binaria(*raiz_playlist, imprimir_dados_playlist);
            pausar_tela();
            break;

        case 16:
            print_amarelo("Mostrar dados de uma playlist:\n");
            mostrar_dados_de_uma_playlist(*raiz_playlist);
            pausar_tela();
            break;

        case 17:
            print_amarelo("Remover musica de uma playlist:\n");
            verificacao_remover_musica_playlist(remover_musica_de_uma_playlist(raiz_playlist));
            pausar_tela();
            break;

        case 18:
            print_amarelo("Remover uma playlist:\n");
            verificacao_remover_playlist(remover_playlist(raiz_playlist));
            pausar_tela();
            break;

        case 19:
            print_amarelo("Remover uma musica de um album de um artista:\n");
            verificacao_remover_musica_album_artista(remover_musica_de_album_de_artista(raiz_artista, raiz_playlist));
            pausar_tela();
            break;

        default:
            break;
        }

    } while (opcao != 0);
}
