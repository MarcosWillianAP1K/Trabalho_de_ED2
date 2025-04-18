#include "../includes/interatividade.h"
#include "../includes/funcao_sistema.h"
#include <stdio.h>
#include <stdlib.h>

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
    ARTISTA *artista = criar_artista(nome_artista, "auxiliar", "auxiliar", 0, NULL);
    ALBUM *album = criar_album(titulo_album, 0, 0, NULL);

    aux->musica_playlist = criar_musica_playlist(artista, album, musica);

    return aux;
}

DADOS *digitar_cadastro_artista()
{
    printf("Digite o nome do artista\n");
    char *nome = digitar_string();

    printf("Digite o tipo do artista\n");
    char *tipo = digitar_string();

    printf("Digite o estilo musical do artista\n");
    char *estilo = digitar_string();

    DADOS *aux = alocar_dados();
    aux->artista = criar_artista(nome, tipo, estilo, 0, NULL);

    if (comparar_se_esta_vazio(aux->artista->nome) == 0 || comparar_se_esta_vazio(aux->artista->tipo) == 0 || comparar_se_esta_vazio(aux->artista->estilo_musical) == 0)
    {
        liberar_dados_artista(&aux);
    }

    return aux;
}

DADOS *digitar_cadastro_album()
{

    printf("Digite o titulo do album: ");
    char *titulo = digitar_string();

    printf("Digite o ano de lancamento do album: ");

    DADOS *aux = alocar_dados();
    aux->album = criar_album(titulo, digitar_short_int(), 0, NULL);

    if (comparar_se_esta_vazio(aux->album->titulo) == 0)
    {
        liberar_dados_album(&aux);
    }

    return aux;
}

DADOS *digitar_cadastro_musica()
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

    DADOS *aux = alocar_dados();
    aux->musica = criar_musica(titulo, minutos, segundos);

    if (comparar_se_esta_vazio(aux->musica->titulo) == 0)
    {
        liberar_dados_musica(&aux);
    }

    return aux;
}

DADOS *digitar_cadastro_playlist()
{
    printf("Digite o nome da playlist: ");
    char *nome_playlist = digitar_string();

    DADOS *aux = alocar_dados();
    aux->playlist = criar_playlist(nome_playlist, 0, NULL);

    if (comparar_se_esta_vazio(aux->playlist->nome) == 0)
    {
        liberar_dados_playlist(&aux);
    }

    return aux;
}

void cadastrar_artista_interativo(ARV_AVL **raiz_artista)
{
    limpar_tela();
    print_amarelo("Cadastrar artista:\n");
    print_amarelo("Deixe os campos vazios para sair\n\n");

    DADOS *cadastro = digitar_cadastro_artista();
    if (cadastrar_artista(raiz_artista, cadastro) == 1)
    {
        mensagem_sucesso("Artista cadastrado com sucesso!\n");
    }
    else
    {
        mensagem_erro("Artista ja cadastrado!\n");
        liberar_dados_artista(&cadastro);
    }
    pausar_tela();
}

void cadastrar_album_interativo(ARV_AVL **raiz_artista)
{
    print_amarelo("Cadastrar albuns:\n");
    print_amarelo("Deixe os campos vazios para sair\n\n");
    ARV_AVL *artista_encontrado = encontrar_dado_na_arv_digitando(*raiz_artista, digitar_nome_artista, comparar_dados_nome_artista, liberar_dados_artista);

    if (artista_encontrado != NULL)
    {
        DADOS *cadastro = digitar_cadastro_album(artista_encontrado->info);
        if (cadastrar_album(artista_encontrado->info, cadastro) == 1)
        {
            mensagem_sucesso("Album cadastrado com sucesso!\n");
        }
        else
        {
            mensagem_erro("Album ja cadastrado!\n");
            liberar_dados_album(&cadastro);
        }
    }
    else
    {
        mensagem_erro("Artista nao encontrado!");
    }

    pausar_tela();
}

void cadastrar_musica_interativo(ARV_AVL **raiz_artista)
{
    print_amarelo("Cadastrar musicas:\n");
    print_amarelo("Deixe os campos vazios para sair\n\n");
    ARV_AVL *artista_encontrado = encontrar_dado_na_arv_digitando(*raiz_artista, digitar_nome_artista, comparar_dados_nome_artista, liberar_dados_artista);

    if (artista_encontrado != NULL)
    {
        ARV_AVL *album_encontrado = encontrar_dado_na_arv_digitando(artista_encontrado->info->artista->albuns_raiz_arvore, digitar_titulo_album, comparar_dados_titulo_album, liberar_dados_album);

        if (album_encontrado != NULL)
        {
            DADOS *cadastro = digitar_cadastro_musica();
            if (cadastrar_musica(album_encontrado->info, cadastro) == 1)
            {
                mensagem_sucesso("Musica cadastrada com sucesso!\n");
            }
            else
            {
                mensagem_erro("Musica ja cadastrada!\n");
                liberar_dados_musica(&cadastro);
            }
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

void mostrar_artistas_interativo(ARV_AVL **raiz_artista)
{
    print_amarelo("Artistas cadastrados:\n");
    // printf("Altura: %d\n", (*raiz_artista)->altura);

    mostrar_artistas(*raiz_artista);
    pausar_tela();
}

void mostrar_artistas_de_um_tipo_interativo(ARV_AVL **raiz_artista)
{
    print_amarelo("Artistas cadastrados de um tipo:\n");
    DADOS *aux = digitar_tipo_artista();
    mostrar_artistas_por_tipo(*raiz_artista, aux);
    liberar_dados_artista(&aux);
    pausar_tela();
}

void mostrar_artistas_de_um_estilo_musical_interativo(ARV_AVL **raiz_artista)
{
    print_amarelo("Artistas cadastrados de um estilo musical:\n");
    DADOS *aux = digitar_estilo_artista();
    mostrar_artistas_por_estilo(*raiz_artista, aux);
    liberar_dados_artista(&aux);
    pausar_tela();
}

void mostrar_artistas_de_um_estilo_musical_e_tipo_interativo(ARV_AVL **raiz_artista)
{
    print_amarelo("Artistas cadastrados de um estilo musical e tipo:\n");
    DADOS *aux = digitar_tipo_e_estilo_artista();
    mostrar_artistas_por_tipo_e_estilo(*raiz_artista, aux);
    liberar_dados_artista(&aux);
    pausar_tela();
}

void mostrar_albuns_de_um_artista_interativo(ARV_AVL **raiz_artista)
{
    print_amarelo("Albuns cadastrados de um artista:\n");
    ARV_AVL *artista_encontrado = encontrar_dado_na_arv_digitando(*raiz_artista, digitar_nome_artista, comparar_dados_nome_artista, liberar_dados_artista);

    if (artista_encontrado != NULL)
    {
        mostrar_albuns_de_um_artista(artista_encontrado->info);
    }
    else
    {
        mensagem_erro("Artista nao encontrado!");
    }
    pausar_tela();
}

void mostrar_albuns_de_um_ano_de_um_artista_interativo(ARV_AVL **raiz_artista)
{
    print_amarelo("Albuns cadastrados de um artista de um ano:\n");
    ARV_AVL *artista_encontrado = encontrar_dado_na_arv_digitando(*raiz_artista, digitar_nome_artista, comparar_dados_nome_artista, liberar_dados_artista);

    if (artista_encontrado != NULL)
    {
        DADOS *ano_album = digitar_ano_album();
        mostrar_albuns_de_um_artista_de_um_ano(artista_encontrado->info, ano_album);
        liberar_dados_album(&ano_album);
    }
    else
    {
        mensagem_erro("Artista nao encontrado!");
    }
    pausar_tela();
}

void mostrar_musicas_de_um_album_de_um_artista_interativo(ARV_AVL **raiz_artista)
{
    print_amarelo("Musicas cadastradas de um album de um artista:\n");
    ARV_AVL *artista_encontrado = encontrar_dado_na_arv_digitando(*raiz_artista, digitar_nome_artista, comparar_dados_nome_artista, liberar_dados_artista);

    if (artista_encontrado != NULL)
    {
        ARV_AVL *album_encontrado = encontrar_dado_na_arv_digitando(artista_encontrado->info->artista->albuns_raiz_arvore, digitar_titulo_album, comparar_dados_titulo_album, liberar_dados_album);

        if (album_encontrado != NULL)
        {
            mostrar_musicas_de_um_album_de_um_artista(album_encontrado->info, artista_encontrado->info);
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

void mostrar_albuns_de_todos_artistas_de_um_ano_interativo(ARV_AVL **raiz_artista)
{
    print_amarelo("Albuns cadastrados de todos artista de um ano:\n");
    DADOS *ano_album = digitar_ano_album();
    mostrar_albuns_de_todos_artistas_de_um_ano(*raiz_artista, ano_album);
    liberar_dados_album(&ano_album);
    pausar_tela();
}

void mostrar_dados_de_uma_musica_interativo(ARV_AVL **raiz_artista)
{
    print_amarelo("Dados de uma musica:\n");
    DADOS *aux = digitar_titulo_musica();
    mostrar_dados_de_uma_musica(*raiz_artista, aux);
    liberar_dados_musica(&aux);
    pausar_tela();
}

void cadastrar_playlist_interativo(ARV_AVL **raiz_playlist)
{
    print_amarelo("Cadastrar playlist:\n");
    print_amarelo("Deixe os campos vazios para sair\n\n");
    DADOS *cadastro = digitar_cadastro_playlist();
    if (cadastrar_playlist(raiz_playlist, cadastro) == 1)
    {
        mensagem_sucesso("Playlist cadastrada com sucesso!\n");
    }
    else
    {
        mensagem_erro("Playlist ja cadastrada!\n");
        liberar_dados_playlist(&cadastro);
    }
    pausar_tela();
}

void cadastrar_musica_em_uma_playlist_interativo(ARV_AVL **raiz_artista, ARV_AVL **raiz_playlist)
{
    print_amarelo("Cadastrar musica em uma playlist:\n");
    print_amarelo("Deixe os campos vazios para sair\n\n");
    ARV_AVL *playlist_encontrada = encontrar_dado_na_arv_digitando(*raiz_playlist, digitar_nome_playlist, comparar_dados_nome_playlist, liberar_dados_playlist);

    if (playlist_encontrada != NULL)
    {
        ARV_AVL *artista_encontrado = encontrar_dado_na_arv_digitando(*raiz_artista, digitar_nome_artista, comparar_dados_nome_artista, liberar_dados_artista);

        if (artista_encontrado != NULL)
        {
            ARV_AVL *album_encontrado = encontrar_dado_na_arv_digitando(artista_encontrado->info->artista->albuns_raiz_arvore, digitar_titulo_album, comparar_dados_titulo_album, liberar_dados_album);

            if (album_encontrado != NULL)
            {
                ARV_AVL *musica_encontrada = encontrar_dado_na_arv_digitando(album_encontrado->info->album->musicas_raiz_arvore, digitar_titulo_musica, comparar_dados_titulo_musica, liberar_dados_musica);

                if (musica_encontrada != NULL)
                {
                    DADOS *musica_playlist = alocar_dados();
                    musica_playlist->musica_playlist = criar_musica_playlist(artista_encontrado->info->artista, album_encontrado->info->album, musica_encontrada->info->musica);

                    if (cadastrar_musica_em_uma_playlist(playlist_encontrada->info, musica_playlist) == 1)
                    {
                        mensagem_sucesso("Musica cadastrada com sucesso!");
                    }
                    else
                    {
                        mensagem_erro("Musica ja cadastrada!");
                        liberar_dados_musica_playlist(&musica_playlist);
                    }
                }
                else
                {
                    mensagem_erro("Musica nao encontrada!");
                }
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
    }
    else
    {
        mensagem_erro("Playlist nao encontrada!");
    }

    pausar_tela();
}

void mostrar_playlists_interativo(ARV_AVL **raiz_playlist)
{
    print_amarelo("Mostrar playlists:\n");
    mostrar_playlists(*raiz_playlist);
    pausar_tela();
}

void mostrar_dados_de_uma_playlist_interativo(ARV_AVL **raiz_playlist)
{
    print_amarelo("Mostrar dados de uma playlist:\n");
    ARV_AVL *playlist_encontrada = encontrar_dado_na_arv_digitando(*raiz_playlist, digitar_nome_playlist, comparar_dados_nome_playlist, liberar_dados_playlist);

    if (playlist_encontrada != NULL)
    {
        mostrar_dados_de_uma_playlist(playlist_encontrada->info);
    }
    pausar_tela();
}

void remover_musica_de_uma_playlist_interativo(ARV_AVL **raiz_playlist)
{
    print_amarelo("Remover musica de uma playlist:\n");
    print_amarelo("Deixe os campos vazios para sair\n\n");
    ARV_AVL *playlist_encontrada = encontrar_dado_na_arv_digitando(*raiz_playlist, digitar_nome_playlist, comparar_dados_nome_playlist, liberar_dados_playlist);

    if (playlist_encontrada != NULL)
    {
        DADOS *musica_playlist = digitar_musica_playlist();

        if (remover_musica_de_uma_playlist(playlist_encontrada->info, musica_playlist) == 1)
        {
            mensagem_sucesso("Musica removida com sucesso!\n");
        }
        else
        {
            mensagem_sucesso("Musica nao encontrada na playlist!\n");
        }

        liberar_musica(&musica_playlist->musica_playlist->musica);
        liberar_artista(&musica_playlist->musica_playlist->artista);
        liberar_album(&musica_playlist->musica_playlist->album);
        liberar_dados_musica_playlist(&musica_playlist);
    }
    else
    {
        mensagem_erro("Playlist nao encontrada!");
    }
    pausar_tela();
}

void remover_playlist_interativo(ARV_AVL **raiz_playlist)
{
    print_amarelo("Remover uma playlist:\n");
    print_amarelo("Deixe os campos vazios para sair\n\n");

    DADOS *playlist_a_remover = digitar_nome_playlist();

    if (remover_playlist(raiz_playlist, playlist_a_remover) == 1)
    {
        mensagem_sucesso("Playlist removida com sucesso!\n");
    }
    else
    {
        mensagem_erro("Playlist nao encontrada!\n");
    }
    liberar_dados_playlist(&playlist_a_remover);
    pausar_tela();
}

void remover_musica_de_um_album_de_um_artista_interativo(ARV_AVL **raiz_artista, ARV_AVL **raiz_playlist)
{
    print_amarelo("Remover uma musica de um album de um artista:\n");
    print_amarelo("Deixe os campos vazios para sair\n\n");

    ARV_AVL *artista_encontrado = encontrar_dado_na_arv_digitando(*raiz_artista, digitar_nome_artista, comparar_dados_nome_artista, liberar_dados_artista);

    if (artista_encontrado != NULL)
    {
        ARV_AVL *album_encontrado = encontrar_dado_na_arv_digitando(artista_encontrado->info->artista->albuns_raiz_arvore, digitar_titulo_album, comparar_dados_titulo_album, liberar_dados_album);

        if (album_encontrado != NULL)
        {
            DADOS *musica_a_remover = digitar_titulo_musica();

            if (remover_musica_de_album_de_artista(artista_encontrado->info, album_encontrado->info, musica_a_remover, *raiz_playlist) == 1)
            {
                mensagem_sucesso("Musica removida com sucesso!\n");
            }
            else
            {
                mensagem_erro("Musica nao encontrada no album!\n");
            }
            liberar_dados_musica(&musica_a_remover);
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

void menu_principal(ARV_AVL **raiz_artista, ARV_AVL **raiz_playlist)
{

    short int opcao = 0;

    do
    {
        limpar_tela();

        printf("Menu Principal:\n");
        printf("1 - Cadastrar artista\n");
        printf("2 - Cadastrar album\n");
        printf("3 - Cadastrar musica\n");
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
            cadastrar_artista_interativo(raiz_artista);
            break;

        case 2:
            cadastrar_album_interativo(raiz_artista);
            break;

        case 3:
            cadastrar_musica_interativo(raiz_artista);
            break;

        case 4:
            mostrar_artistas_interativo(raiz_artista);
            break;

        case 5:
            mostrar_artistas_de_um_tipo_interativo(raiz_artista);
            break;

        case 6:
            mostrar_artistas_de_um_estilo_musical_interativo(raiz_artista);
            break;

        case 7:
            mostrar_artistas_de_um_estilo_musical_e_tipo_interativo(raiz_artista);

            break;

        case 8:
            mostrar_albuns_de_um_artista_interativo(raiz_artista);
            break;

        case 9:
            mostrar_albuns_de_um_ano_de_um_artista_interativo(raiz_artista);
            break;

        case 10:
            mostrar_musicas_de_um_album_de_um_artista_interativo(raiz_artista);
            break;

        case 11:
            mostrar_albuns_de_todos_artistas_de_um_ano_interativo(raiz_artista);
            break;

        case 12:
            mostrar_dados_de_uma_musica_interativo(raiz_artista);
            break;

        case 13:
            cadastrar_playlist_interativo(raiz_playlist);
            break;

        case 14:
            cadastrar_musica_em_uma_playlist_interativo(raiz_artista, raiz_playlist);
            break;

        case 15:
            mostrar_playlists_interativo(raiz_playlist);
            break;

        case 16:
            mostrar_dados_de_uma_playlist_interativo(raiz_playlist);
            break;

        case 17:
            remover_musica_de_uma_playlist_interativo(raiz_playlist);
            break;

        case 18:
            remover_playlist_interativo(raiz_playlist);
            break;

        case 19:
            remover_musica_de_um_album_de_um_artista_interativo(raiz_artista, raiz_playlist);
            break;

        default:
            break;
        }

    } while (opcao != 0);
}
