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
        liberar(aux, liberar);
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

void mostrar_artista_por_tipo(ARV_BINARIA *raiz_artista)
{
    DADOS *aux = digitar_tipo_artista();

    imprimir_arv_binaria_filtro(raiz_artista, aux, imprimir_dados_artista, comparar_dados_tipo_artista);

    liberar_dados_artista(&aux);
}

void mostrar_artista_por_estilo(ARV_BINARIA *raiz_artista)
{
    DADOS *aux = digitar_estilo_artista();

    imprimir_arv_binaria_filtro(raiz_artista, aux, imprimir_dados_artista, comparar_dados_estilo_artista);

    liberar_dados_artista(&aux);
}

void mostrar_artista_por_tipo_e_estilo(ARV_BINARIA *raiz_artista)
{
    DADOS *aux = digitar_tipo_e_estilo_artista();
    // ARV_BINARIA *artista = buscar_arv_binaria(raiz_artista, aux, comparar_dados_tipo_e_estilo_artista);

    imprimir_arv_binaria_filtro(raiz_artista, aux, imprimir_dados_artista, comparar_dados_tipo_e_estilo_artista);

    liberar_dados_artista(&aux);
}

void mostrar_albuns_de_um_artista(ARV_BINARIA *raiz)
{
    DADOS *aux = digitar_nome_artista();
    ARV_BINARIA *artista = buscar_arv_binaria(raiz, aux, comparar_dados_nome_artista);

    if (artista != NULL)
    {
        printf("Albuns do artista %s:\n", artista->info->artista->nome);
        imprimir_arv_binaria(artista->info->artista->albuns_raiz_arvore, imprimir_dados_album);
    }
    else
    {
        printf("Nenhum artista encontrado com o nome %s\n", artista->info->artista->nome);
    }

    liberar_dados_artista(&aux);
}

void mostrar_albuns_de_um_artista_de_um_ano(ARV_BINARIA *raiz_artista)
{
    DADOS *aux = digitar_nome_artista();
    ARV_BINARIA *artista = buscar_arv_binaria(raiz_artista, aux, comparar_dados_nome_artista);

    if (artista != NULL)
    {
        DADOS *aux2 = digitar_ano_album();

        printf("Albuns do artista %s:\n", artista->info->artista->nome);
        imprimir_arv_binaria_filtro(artista->info->artista->albuns_raiz_arvore, aux2, imprimir_dados_album, comparar_dados_data_album);
        liberar_dados_album(&aux2);
    }
    else
    {
        printf("Nenhum artista encontrado com o nome %s\n", aux->artista->nome);
    }

    liberar_dados_artista(&aux);
}

void mostrar_musicas_de_um_album_de_um_artista(ARV_BINARIA *raiz)
{
    DADOS *aux = digitar_nome_artista();
    ARV_BINARIA *artista = buscar_arv_binaria(raiz, aux, comparar_dados_nome_artista);

    if (artista != NULL)
    {
        DADOS *aux2 = digitar_titulo_album();
        ARV_BINARIA *album = buscar_arv_binaria(artista->info->artista->albuns_raiz_arvore, aux2, comparar_dados_titulo_album);

        if (album != NULL)
        {
            printf("Musicas do album %s:\n", album->info->album->titulo);
            imprimir_arv_binaria(album->info->album->musicas_raiz_arvore, imprimir_dados_musica);
        }
        else
        {
            printf("Nenhum album encontrado com o nome %s\n", aux2->album->titulo);
        }

        liberar_dados_album(&aux2);
    }
    else
    {
        printf("Nenhum artista encontrado com o nome %s\n", aux->artista->nome);
    }

    liberar_dados_artista(&aux);
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

void mostrar_albuns_de_todos_artistas_de_um_ano(ARV_BINARIA *raiz_artista)
{
    DADOS *aux = digitar_ano_album();

    pecorrer_artistas_imprimir_ano(raiz_artista, aux);

    liberar_dados_album(&aux);
}

short int pecorrer_album_impimir_musica(ARV_BINARIA *raiz_album, DADOS *aux)
{
    short int retorno = 0;

    if (raiz_album != NULL)
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

    if (raiz_artista != NULL)
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

void mostrar_dados_de_uma_musica(ARV_BINARIA *raiz)
{
    DADOS *aux = digitar_titulo_musica();

    pecorrer_artista_imprimir_musica(raiz, aux);

    liberar_dados_musica(&aux);
}

void mostrar_dados_de_uma_playlist(ARV_BINARIA *raiz)
{
    DADOS *aux = digitar_nome_playlist();
    ARV_BINARIA *playlist = buscar_arv_binaria(raiz, aux, comparar_dados_nome_playlist);

    if (playlist != NULL)
    {
        printf("Dados da playlist %s:\n", playlist->info->playlist->nome);
        imprimir_dados_playlist(playlist->info);

        printf("\n\nMusicas da playlist %s:\n", playlist->info->playlist->nome);
        imprimir_arv_binaria(playlist->info->playlist->musicas_raiz_arvore, imprimir_dados_musica_playlist);
    }
    else
    {
        printf("Nenhuma playlist encontrada com o nome %s\n", aux->playlist->nome);
    }

    liberar_dados_playlist(&aux);
}

short int remover_musica_de_uma_playlist(ARV_BINARIA **raiz)
{
    print_amarelo("Deixe os campos vazios para sair\n\n");
    short int retorno = 0;

    DADOS *aux = digitar_nome_playlist();
    ARV_BINARIA *playlist = buscar_arv_binaria(*raiz, aux, comparar_dados_nome_playlist);

    if (comparar_se_esta_vazio(aux->playlist->nome) == 0)
    {
        retorno = 2;
    }
    else if (playlist != NULL)
    {
        DADOS *aux2 = digitar_musica_playlist();

        if (comparar_se_esta_vazio(aux2->musica_playlist->musica->titulo) == 0)
        {
            retorno = 2;
        }
        else if (aux2->musica_playlist != NULL)
        {
            ARV_BINARIA *remover = playlist->info->playlist->musicas_raiz_arvore;

            if (menu_que_volta() == 1)
            {
                ARV_BINARIA *musica_removida = remover_arv_binaria(&remover, aux2, comparar_dados_musica_playlist);

                if (musica_removida != NULL)
                {
                    retorno = 1;
                    liberar_no_arv_binaria(&musica_removida, liberar_dados_musica_playlist);
                    playlist->info->playlist->musicas_raiz_arvore = remover;
                    playlist->info->playlist->numero_de_musicas--;
                }
            }
            else
            {
                retorno = 2;
            }
        }

        liberar_musica(&aux2->musica_playlist->musica);
        liberar_dados_musica_playlist(&aux2);
    }
    else
    {
        retorno = -1;
    }

    liberar_dados_playlist(&aux);

    return retorno;
}

short int remover_playlist(ARV_BINARIA **raiz)
{
    print_amarelo("Deixe os campos vazios para sair\n\n");
    short int retorno = 0;

    DADOS *aux = digitar_nome_playlist();

    if (comparar_se_esta_vazio(aux->playlist->nome) == 0)
    {
        retorno = 2;
    }
    else
    {
        if (menu_que_volta() == 1)
        {
            ARV_BINARIA *playlist = NULL;

            if ((playlist = remover_arv_binaria(raiz, aux, comparar_dados_nome_playlist)) != NULL)
            {
                retorno = 1;
                ARV_BINARIA *apagar_musicas = playlist->info->playlist->musicas_raiz_arvore;

                liberar_arv_binaria(&apagar_musicas, liberar_dados_musica_playlist);
                playlist->info->playlist->musicas_raiz_arvore = apagar_musicas;
                liberar_no_arv_binaria(&playlist, liberar_dados_playlist);
            }
        }
        else
        {
            retorno = 2;
        }
    }

    liberar_dados_playlist(&aux);

    return retorno;
}

ARV_BINARIA *verificar_nas_playlists(ARV_BINARIA **raiz_playlist, DADOS *aux)
{
    ARV_BINARIA *musica = NULL;

    if (*raiz_playlist != NULL)
    {
        musica = buscar_arv_binaria((*raiz_playlist)->info->playlist->musicas_raiz_arvore, aux, comparar_dados_musica_playlist);

        if (musica == NULL)
        {
            musica = verificar_nas_playlists(&(*raiz_playlist)->esq, aux);
        }

        if (musica == NULL)
        {
            musica = verificar_nas_playlists(&(*raiz_playlist)->dir, aux);
        }
    }
    return musica;
}

short int remover_musica_de_album_de_artista(ARV_BINARIA **raiz, ARV_BINARIA **raiz_playlist)
{
    print_amarelo("Deixe os campos vazios para sair\n\n");
    short int retorno = 0;

    DADOS *aux = digitar_nome_artista();
    ARV_BINARIA *artista = buscar_arv_binaria(*raiz, aux, comparar_dados_nome_artista);

    if (comparar_se_esta_vazio(aux->artista->nome) == 0)
    {
        retorno = 2;
    }
    else if (artista != NULL)
    {
        DADOS *aux2 = digitar_titulo_album();
        ARV_BINARIA *album = buscar_arv_binaria(artista->info->artista->albuns_raiz_arvore, aux2, comparar_dados_titulo_album);

        if (comparar_se_esta_vazio(aux2->album->titulo) == 0)
        {
            retorno = 2;
        }
        else if (album != NULL)
        {
            DADOS *aux3 = digitar_titulo_musica();
            DADOS *aux4 = alocar_dados();
            aux4->musica_playlist = criar_musica_playlist(aux->artista->nome, aux2->album->titulo, aux3->musica);

            if (comparar_se_esta_vazio(aux3->musica->titulo) == 0)
            {
                retorno = 2;
            }
            else if (verificar_nas_playlists(raiz_playlist, aux4) == NULL)
            {
                if (menu_que_volta() == 1)
                {
                    ARV_BINARIA *remover = album->info->album->musicas_raiz_arvore;
                    ARV_BINARIA *musica_removida = remover_arv_binaria(&remover, aux3, comparar_dados_titulo_musica);

                    if (musica_removida != NULL)
                    {
                        retorno = 1;
                        liberar_no_arv_binaria(&musica_removida, liberar_dados_musica);
                        album->info->album->musicas_raiz_arvore = remover;
                        album->info->album->numero_de_musicas--;
                    }
                }
                else
                {
                    retorno = 2;
                }
            }
            else
            {
                retorno = -3;
            }

            liberar_musica(&aux4->musica_playlist->musica);
            liberar_dados_musica_playlist(&aux4);
            liberar_dados(&aux3);
        }
        else
        {
            retorno = -2;
        }

        liberar_dados_album(&aux2);
    }
    else
    {
        retorno = -1;
    }

    liberar_dados_artista(&aux);

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

    if (raiz_playlist != NULL && *raiz_playlist != NULL && info != NULL && info->playlist != NULL)
    {
        retorno = inserir_arv_binaria(raiz_playlist, info, comparar_dados_nome_playlist);
    }

    return retorno;
}

short int cadastrar_musica_em_uma_playlist(DADOS *playlist, DADOS *info)
{
    short int retorno = 0;

    if ( playlist != NULL && info != NULL && info->musica_playlist != NULL)
    {
        ARV_BINARIA *inserir = playlist->playlist->musicas_raiz_arvore;
        retorno = inserir_arv_binaria(&inserir, info, comparar_dados_musica_playlist);
        playlist->playlist->musicas_raiz_arvore = inserir;
        playlist->playlist->numero_de_musicas++;
    }

    return retorno;
}