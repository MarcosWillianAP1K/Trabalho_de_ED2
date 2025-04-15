#include "../includes/func_interatividade.h"
#include "../includes/funcao_sistema.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ARV_BINARIA *encontrar_dado_na_arv_digitando(ARV_BINARIA *raiz, DADOS *(*digite)(), int (*comparar)(DADOS *, DADOS *), void (*liberar)(DADOS **))
{
    ARV_BINARIA *no = NULL;

    if (raiz != NULL && digite != NULL && comparar != NULL && liberar != NULL)
    {
        DADOS *aux = digite();
        no = buscar_arv_binaria(raiz, aux, comparar);
        liberar(&aux);
    }

    return no;
}

short int menu_que_volta()
{
    limpar_tela();
    short int retorna = 0;
    printf("Deseja continuar com a acao?\n\n");
    printf("1 - Sim\n");
    printf("2 - Nao\n");
    printf("Digite a opcao: ");
    short int opcao = digitar_short_int();

    switch (opcao)
    {
    case 1:
        printf("\nContinuando...\n");
        retorna = 1;
        break;
    case 2:
        printf("\nVoltando ao menu principal...\n");
        limpar_buffer();
        break;
    default:
        printf("\nOpcao invalida. Voltando ao menu principal...\n");
        break;
    }
    return retorna;
}

short int comparar_se_esta_vazio(char *n1)
{
    return strcmp(n1, "");
}

void mostrar_artista(ARV_BINARIA *raiz_artista)
{
    imprimir_arv_binaria(raiz_artista, imprimir_dados_artista);
}

void mostrar_playlist(ARV_BINARIA *raiz_playlist)
{
    imprimir_arv_binaria(raiz_playlist, imprimir_dados_playlist);
}

void mostrar_artista_por_tipo(ARV_BINARIA *raiz_artista, DADOS *tipo)
{
    if (raiz_artista != NULL && tipo != NULL)
    {
        imprimir_arv_binaria_filtro(raiz_artista, tipo, imprimir_dados_artista, comparar_dados_tipo_artista);
    }
    else
    {
        printf("Nenhum artista encontrado");
    }
}

void mostrar_artista_por_estilo(ARV_BINARIA *raiz_artista, DADOS *estilo)
{
    if (raiz_artista != NULL && estilo != NULL && estilo->artista != NULL)
    {
        imprimir_arv_binaria_filtro(raiz_artista, estilo, imprimir_dados_artista, comparar_dados_estilo_artista);
    }
    else
    {
        printf("Nenhum artista encontrado");
    }
}

void mostrar_artista_por_tipo_e_estilo(ARV_BINARIA *raiz_artista, DADOS *tipo_estilo)
{
    if (raiz_artista != NULL && tipo_estilo != NULL && tipo_estilo->artista != NULL)
    {
        imprimir_arv_binaria_filtro(raiz_artista, tipo_estilo, imprimir_dados_artista, comparar_dados_tipo_e_estilo_artista);
    }
    else
    {
        printf("Nenhum artista encontrado");
    }
}

void mostrar_albuns_de_um_artista(DADOS *artista)
{
    if (artista != NULL && artista->artista != NULL)
    {
        printf("Albuns do artista %s:\n", artista->artista->nome);
        imprimir_arv_binaria(artista->artista->albuns_raiz_arvore, imprimir_dados_album);
    }
}

void mostrar_albuns_de_um_artista_de_um_ano(DADOS *artista, DADOS *ano_album)
{
    if (artista != NULL && artista->artista != NULL)
    {
        printf("Albuns do artista %s:\n", artista->artista->nome);
        imprimir_arv_binaria_filtro(artista->artista->albuns_raiz_arvore, ano_album, imprimir_dados_album, comparar_dados_data_album);
    }
}

void mostrar_musicas_de_um_album_de_um_artista(DADOS *album, DADOS *artista)
{
    if (album != NULL && album->album != NULL)
    {
        printf("Albuns do artista %s:\n", artista->artista->nome);
        imprimir_arv_binaria(album->album->musicas_raiz_arvore, imprimir_dados_musica);
    }
}

void pecorrer_artistas_imprimir_ano(ARV_BINARIA *raiz_artista, DADOS *aux)
{
    if (raiz_artista != NULL)
    {
        pecorrer_artistas_imprimir_ano(raiz_artista->esq, aux);

        if (raiz_artista->info->artista->albuns_raiz_arvore != NULL)
        {
            if (imprimir_arv_binaria_filtro(raiz_artista->info->artista->albuns_raiz_arvore, aux, imprimir_dados_album, comparar_dados_data_album) == 1)
            {
                printf("\nArtista: %s\n", raiz_artista->info->artista->nome);
            }
        }

        pecorrer_artistas_imprimir_ano(raiz_artista->dir, aux);
    }
}

void mostrar_albuns_de_todos_artistas_de_um_ano(ARV_BINARIA *raiz_artista, DADOS *ano)
{
    pecorrer_artistas_imprimir_ano(raiz_artista, ano);
}

short int pecorrer_album_impimir_musica(ARV_BINARIA *raiz_album, DADOS *aux)
{
    short int retorno = 0;

    if (raiz_album != NULL && aux != NULL)
    {
        retorno |= pecorrer_album_impimir_musica(raiz_album->esq, aux);

        if (raiz_album->info->album->musicas_raiz_arvore != NULL)
        {
            short int retorno_aux = 0;
            retorno_aux = imprimir_arv_binaria_filtro(raiz_album->info->album->musicas_raiz_arvore, aux, imprimir_dados_musica, comparar_dados_titulo_musica);
            retorno |= retorno_aux;

            if (retorno_aux == 1)
            {
                printf("\nAlbum: %s\n", raiz_album->info->album->titulo);
            }
        }

        retorno |= pecorrer_album_impimir_musica(raiz_album->dir, aux);
    }

    return retorno;
}

void pecorrer_artista_imprimir_musica(ARV_BINARIA *raiz_artista, DADOS *aux)
{

    if (raiz_artista != NULL && aux != NULL)
    {

        pecorrer_artista_imprimir_musica(raiz_artista->esq, aux);

        if (raiz_artista->info->artista->albuns_raiz_arvore != NULL)
        {
            if (pecorrer_album_impimir_musica(raiz_artista->info->artista->albuns_raiz_arvore, aux) == 1)
            {
                printf("\nArtista: %s\n", raiz_artista->info->artista->nome);
            }
        }

        pecorrer_artista_imprimir_musica(raiz_artista->dir, aux);
    }
}

void mostrar_dados_de_uma_musica(ARV_BINARIA *raiz, DADOS *musica)
{
    pecorrer_artista_imprimir_musica(raiz, musica);
}

void mostrar_dados_de_uma_playlist(DADOS *playlist)
{
    if (playlist != NULL)
    {
        printf("Dados da playlist %s:\n", playlist->playlist->nome);
        imprimir_dados_playlist(playlist);

        printf("\n\nMusicas da playlist %s:\n", playlist->playlist->nome);
        imprimir_arv_binaria(playlist->playlist->musicas_raiz_arvore, imprimir_dados_musica_playlist);
    }
}

short int remover_musica_de_uma_playlist(DADOS *playlist, DADOS *musica_a_remover)
{
    short int retorno = 0;

    if (playlist != NULL && musica_a_remover != NULL)
    {
        ARV_BINARIA *remover = playlist->playlist->musicas_raiz_arvore;
        ARV_BINARIA *musica_removida = remover_arv_binaria(&remover, musica_a_remover, comparar_dados_musica_playlist);

        if (musica_removida != NULL)
        {
            retorno = 1;
            liberar_no_arv_binaria(&musica_removida, liberar_dados_musica_playlist);
            playlist->playlist->musicas_raiz_arvore = remover;
            playlist->playlist->numero_de_musicas--;
        }
    }

    return retorno;
}

short int remover_playlist(ARV_BINARIA **raiz_playlist, DADOS *playlist_a_remover)
{
    short int retorno = 0;

    if (raiz_playlist != NULL && *raiz_playlist != NULL && playlist_a_remover != NULL)
    {
        ARV_BINARIA *playlist_removida = remover_arv_binaria(raiz_playlist, playlist_a_remover, comparar_dados_nome_playlist);

        if (playlist_removida != NULL)
        {
            retorno = 1;
            ARV_BINARIA *musicas = playlist_removida->info->playlist->musicas_raiz_arvore;
            liberar_arv_binaria(&musicas, liberar_dados_musica_playlist);
            playlist_removida->info->playlist->musicas_raiz_arvore = musicas;
            playlist_removida->info->playlist->numero_de_musicas = 0;

            liberar_no_arv_binaria(&playlist_removida, liberar_dados_playlist);
        }
    }

    return retorno;
}

ARV_BINARIA *verificar_nas_playlists(ARV_BINARIA *raiz_playlist, DADOS *musica_playlist)
{
    ARV_BINARIA *musica = NULL;

    if (raiz_playlist != NULL && musica_playlist != NULL && musica_playlist->musica_playlist != NULL)
    {
        musica = buscar_arv_binaria(raiz_playlist->info->playlist->musicas_raiz_arvore, musica_playlist, comparar_dados_musica_playlist);

        if (musica == NULL)
        {
            musica = verificar_nas_playlists(raiz_playlist->esq, musica_playlist);
        }

        if (musica == NULL)
        {
            musica = verificar_nas_playlists(raiz_playlist->dir, musica_playlist);
        }
    }
    return musica;
}

short int remover_musica_de_album_de_artista(DADOS *artista ,DADOS *album, DADOS *musica_a_remover, ARV_BINARIA *raiz_playlist)
{
    short int retorno = 0;

    if (artista != NULL && album != NULL && musica_a_remover != NULL && artista->artista != NULL && album->album != NULL && musica_a_remover->musica != NULL)
    {
        DADOS *musica_playlist = alocar_dados();
        musica_playlist->musica_playlist = criar_musica_playlist(artista->artista, album->album, musica_a_remover->musica);

        if (verificar_nas_playlists(raiz_playlist, musica_playlist) == NULL)
        {
            ARV_BINARIA *remover = album->album->musicas_raiz_arvore;
            ARV_BINARIA *musica_removida = remover_arv_binaria(&remover, musica_a_remover, comparar_dados_titulo_musica);

            if (musica_removida != NULL)
            {
                retorno = 1;
                liberar_no_arv_binaria(&musica_removida, liberar_dados_musica);
                album->album->musicas_raiz_arvore = remover;
                album->album->numero_de_musicas--;
            }
        }
        liberar_dados_musica_playlist(&musica_playlist);
    }
    return retorno;
}

void delete_musica(ARV_BINARIA **raiz_musica)
{
    if (*raiz_musica != NULL)
    {
        liberar_arv_binaria(raiz_musica, liberar_dados_musica);
    }
}

void delete_album(ARV_BINARIA **raiz_album)
{
    if (*raiz_album != NULL)
    {
        delete_album(&(*raiz_album)->esq);
        delete_album(&(*raiz_album)->dir);

        ARV_BINARIA *aux = (*raiz_album)->info->album->musicas_raiz_arvore;
        delete_musica(&aux);
        (*raiz_album)->info->album->musicas_raiz_arvore = aux;

        liberar_no_arv_binaria(raiz_album, liberar_dados_album);
    }
}

void delete_artista(ARV_BINARIA **raiz_artista)
{
    if (*raiz_artista != NULL)
    {
        delete_artista(&(*raiz_artista)->esq);
        delete_artista(&(*raiz_artista)->dir);

        ARV_BINARIA *aux = (*raiz_artista)->info->artista->albuns_raiz_arvore;
        delete_album(&aux);
        (*raiz_artista)->info->artista->albuns_raiz_arvore = aux;

        liberar_no_arv_binaria(raiz_artista, liberar_dados_artista);
    }
}

void delete_musica_playlist(ARV_BINARIA **raiz_musica_playlist)
{
    if (*raiz_musica_playlist != NULL)
    {
        liberar_arv_binaria(raiz_musica_playlist, liberar_dados_musica_playlist);
    }
}

void delete_playlist(ARV_BINARIA **raiz_playlist)
{
    if (*raiz_playlist != NULL)
    {
        delete_playlist(&(*raiz_playlist)->esq);
        delete_playlist(&(*raiz_playlist)->dir);

        ARV_BINARIA *aux = (*raiz_playlist)->info->playlist->musicas_raiz_arvore;
        delete_musica_playlist(&aux);
        (*raiz_playlist)->info->playlist->musicas_raiz_arvore = aux;

        liberar_no_arv_binaria(raiz_playlist, liberar_dados_playlist);
    }
}

void delete_all(ARV_BINARIA **raiz_artista, ARV_BINARIA **raiz_playlist)
{
    if (*raiz_playlist != NULL)
    {
        printf("Entrou na playlist\n");
        delete_playlist(raiz_playlist);
        *raiz_playlist = NULL;
    }

    if (*raiz_artista != NULL)
    {
        printf("Entrou no artista\n");
        delete_artista(raiz_artista);
        *raiz_artista = NULL;
    }
}

short int cadastrar_artista(ARV_BINARIA **raiz_artista, DADOS *info)
{
    short int retorno = 0;

    if (info != NULL && info->artista != NULL)
    {
        retorno = inserir_arv_binaria(raiz_artista, info, comparar_dados_nome_artista);
    }

    return retorno;
}

short int cadastrar_albuns(DADOS *artista, DADOS *info)
{
    short int retorno = 0;

    if (artista != NULL && info != NULL)
    {
        ARV_BINARIA *inserir = artista->artista->albuns_raiz_arvore;
        retorno = inserir_arv_binaria(&inserir, info, comparar_dados_titulo_album);
        artista->artista->albuns_raiz_arvore = inserir;
        artista->artista->numero_de_albuns++;
    }

    return retorno;
}

short int cadastrar_musica(DADOS *album, DADOS *info)
{
    short int retorno = 0;

    if (album != NULL && info != NULL)
    {
        ARV_BINARIA *inserir = album->album->musicas_raiz_arvore;
        retorno = inserir_arv_binaria(&inserir, info, comparar_dados_titulo_musica);
        album->album->musicas_raiz_arvore = inserir;
        album->album->numero_de_musicas++;
    }

    return retorno;
}

short int cadastrar_playlist(ARV_BINARIA **raiz_playlist, DADOS *info)
{
    short int retorno = 0;

    if (info != NULL && info->playlist != NULL)
    {
        retorno = inserir_arv_binaria(raiz_playlist, info, comparar_dados_nome_playlist);
    }

    return retorno;
}

short int cadastrar_musica_em_uma_playlist(DADOS *playlist, DADOS *info)
{
    short int retorno = 0;

    if (info != NULL && info->musica_playlist != NULL)
    {
        ARV_BINARIA *inserir = playlist->playlist->musicas_raiz_arvore;
        retorno = inserir_arv_binaria(&inserir, info, comparar_dados_musica_playlist);
        playlist->playlist->musicas_raiz_arvore = inserir;
        playlist->playlist->numero_de_musicas++;
    }

    return retorno;
}