#include "../includes/func_interatividade.h"
#include "../includes/funcao_sistema.h"

#include <stdio.h>
#include <stdlib.h>

void mostrar_artista_por_tipo(ARV_BINARIA *raiz)
{
    printf("Digite o tipo: ");

    char *tipo = digitar_string();

    DADOS *aux = alocar_dados();
    aux->artista = criar_artista("auxiliar", tipo, "auxiliar", 0, NULL);

    if (*tipo != '\0')
    {
        imprimir_arv_binaria_filtro(raiz, aux, imprimir_dados_artista, comparar_dados_tipo_artista);
    }
    else
    {
        printf("Nenhum artista encontrado com o tipo %s\n", tipo);
    }

    liberar_dados_artista(&aux);
}

void mostrar_artista_por_estilo(ARV_BINARIA *raiz)
{
    printf("Digite o estilo: ");

    char *estilo = digitar_string();

    DADOS *aux = alocar_dados();
    aux->artista = criar_artista("auxiliar", "auxiliar", estilo, 0, NULL);

    if (*estilo != '\0')
    {
        imprimir_arv_binaria_filtro(raiz, aux, imprimir_dados_artista, comparar_dados_estilo_artista);
    }
    else
    {
        printf("Nenhum artista encontrado com o estilo %s\n", estilo);
    }

    liberar_dados_artista(&aux);
}

void mostrar_artista_por_tipo_e_estilo(ARV_BINARIA *raiz)
{
    printf("Digite o tipo: ");

    char *tipo = digitar_string();

    printf("Digite o estilo: ");

    char *estilo = digitar_string();

    DADOS *aux = alocar_dados();
    aux->artista = criar_artista("auxiliar", tipo, estilo, 0, NULL);

    if (*tipo != '\0' && *estilo != '\0')
    {
        imprimir_arv_binaria_filtro(raiz, aux, imprimir_dados_artista, comparar_dados_tipo_e_estilo_artista);
    }
    else
    {
        printf("Nenhum artista encontrado com o tipo %s e estilo %s\n", tipo, estilo);
    }

    liberar_dados_artista(&aux);
}

void mostrar_albuns_de_um_artista(ARV_BINARIA *raiz)
{
    printf("Digite o nome do artista: ");
    char *nome_artista = digitar_string();
    DADOS *aux = alocar_dados();
    aux->artista = criar_artista(nome_artista, "auxiliar", "auxiliar", 0, NULL);

    if (nome_artista != '\0')
    {
        printf("Albuns do artista %s:\n", nome_artista);

        ARV_BINARIA *artista = buscar_arv_binaria(raiz, aux, comparar_dados_nome_artista);

        if (artista != NULL)
        {
            imprimir_arv_binaria((ARV_BINARIA *)artista->info->album->musicas_raiz_arvore, imprimir_dados_album);
        }
    }
    else
    {
        printf("Nenhum artista encontrado com o nome %s\n", nome_artista);
    }

    liberar_dados_artista(&aux);
}

void mostrar_albuns_de_um_artista_de_um_ano(ARV_BINARIA *raiz)
{
    printf("Digite o nome do artista: ");
    char *nome_artista;
    nome_artista = digitar_string();
    DADOS *aux = alocar_dados();
    aux->artista = criar_artista(nome_artista, "auxiliar", "auxiliar", 0, NULL);

    printf("Digite o ano do album: ");
    char *ano_album = digitar_string();
    DADOS *aux2 = alocar_dados();
    aux2->album = criar_album("auxiliar", ano_album, 0, NULL);

    if (nome_artista != '\0' && ano_album != '\0')
    {
        ARV_BINARIA *artista = buscar_arv_binaria(raiz, aux, comparar_dados_nome_artista);

        if (artista != NULL)
        {
            imprimir_arv_binaria_filtro(raiz, aux2, imprimir_dados_album, comparar_dados_data_album);
        }
    }
    else
    {
        printf("Nenhum artista encontrado com o nome %s e ano %d\n", nome_artista, ano_album);
    }

    liberar_dados_artista(&aux);
    liberar_dados_album(&aux2);
}

void mostrar_musicas_de_um_album_de_um_artista(ARV_BINARIA *raiz)
{
    printf("Digite o nome do artista: ");
    char *nome_artista = digitar_string();
    DADOS *aux1 = alocar_dados();
    aux1->artista = criar_artista(nome_artista, "auxiliar", "auxiliar", 0, NULL);

    printf("Digite o titulo do album: ");
    char *nome_album = digitar_string();
    DADOS *aux2 = alocar_dados();
    aux2->album = criar_album(nome_album, "auxiliar", 0, NULL);

    if (nome_artista != '\0' && nome_album != '\0')
    {
        ARV_BINARIA *artista = buscar_arv_binaria(raiz, aux1, comparar_dados_nome_artista);
        if (artista != NULL)
        {
            ARV_BINARIA *album = buscar_arv_binaria((ARV_BINARIA *)artista->info->artista->albuns_raiz_arvore, aux2, comparar_dados_titulo_album);

            if (album != NULL)
            {
                imprimir_arv_binaria_filtro(raiz, aux2, imprimir_dados_musica, comparar_dados_titulo_musica);
            }
            else
            {
                printf("Nenhum album encontrado com o nome %s\n", nome_album);
            }
        }
        else
        {
            printf("Nenhum artista encontrado com o nome %s\n", nome_artista);
        }
    }
    else
    {
        printf("Nenhum artista encontrado com o nome %s e album %s\n", nome_artista, nome_album);
    }

    liberar_dados_artista(&aux1);
    liberar_dados_album(&aux2);
}

void mostrar_dados_de_uma_musica(ARV_BINARIA *raiz)
{
    printf("Digite o nome da musica: ");
    char *nome_musica = digitar_string();
    DADOS *aux = alocar_dados();
    aux->musica = criar_musica(nome_musica, "9.99");

    if (nome_musica != '\0')
    {
        printf("Dados da musica %s:\n", nome_musica);
        imprimir_arv_binaria_filtro(raiz, aux, imprimir_dados_musica, comparar_dados_titulo_musica);
    }
    else
    {
        printf("Nenhuma musica encontrada com o nome %s\n", nome_musica);
    }

    liberar_dados_musica(&aux);
}

void mostrar_dados_de_uma_playlist(ARV_BINARIA *raiz)
{
    printf("Digite o nome da playlist: ");
    char *nome_playlist = digitar_string();
    DADOS *aux = alocar_dados();
    aux->playlist = criar_playlist(nome_playlist, 0, NULL);

    if (nome_playlist != '\0')
    {
        printf("Dados da playlist %s:\n", nome_playlist);
        imprimir_arv_binaria_filtro(raiz, aux, imprimir_dados_playlist, comparar_dados_nome_playlist);
    }
    else
    {
        printf("Nenhuma playlist encontrada com o nome %s\n", nome_playlist);
    }

    liberar_dados_playlist(&aux);
}

void Remover_musica_de_uma_playlist(ARV_BINARIA *raiz)
{
    printf("Digite o nome da playlist: ");
    char *nome_playlist = digitar_string();
    DADOS *aux = alocar_dados();
    aux->playlist = criar_playlist(nome_playlist, 0, NULL);

    if (nome_playlist != '\0')
    {
        ARV_BINARIA *playlist = buscar_arv_binaria(raiz, aux, comparar_dados_nome_playlist);

        if (playlist != NULL)
        {
            printf("Digite o nome da musica: ");
            char *nome_musica = digitar_string();
            DADOS *aux2 = alocar_dados();
            aux2->musica = criar_musica(nome_musica, "9.99");

            if (nome_musica != '\0')
            {
                remover_arv_binaria(playlist->info->playlist->musicas_raiz_arvore, aux2, liberar_dados_musica_playlist, comparar_dados_titulo_musica_musica_playlist);
            }
            else
            {
                printf("Nenhuma musica encontrada com o nome %s\n", nome_musica);
            }
        }
        else
        {
            printf("Nenhuma playlist encontrada com o nome %s\n", nome_playlist);
        }
    }
    else
    {
        printf("Nenhuma playlist encontrada com o nome %s\n", nome_playlist);
    }
}

void remover_playlist(ARV_BINARIA *raiz)
{
}

void remover_musica_de_album_de_artista(ARV_BINARIA *raiz)
{
}

void delete_musica(ARV_BINARIA **raiz_musica)
{
    if ((*raiz_musica) != NULL)
    {
        liberar_no_arv_binaria(raiz_musica, liberar_dados_musica);
    }
}

void delete_album(ARV_BINARIA **raiz_album)
{
    if (raiz_album != NULL)
    {
        delete_album(&(*raiz_album)->esq);
        delete_album(&(*raiz_album)->dir);

        delete_musica((*raiz_album)->info->album->musicas_raiz_arvore);

        liberar_no_arv_binaria(raiz_album, liberar_dados_album);
    }
}

void delete_artista(ARV_BINARIA **raiz_artista)
{
    if (raiz_artista != NULL)
    {
        delete_artista(&(*raiz_artista)->esq);
        delete_artista(&(*raiz_artista)->dir);

        delete_album((*raiz_artista)->info->artista->albuns_raiz_arvore);

        liberar_no_arv_binaria(raiz_artista, liberar_dados_artista);
    }
}

void delete_musica_playlist(ARV_BINARIA **raiz_musica_playlist)
{
    if (raiz_musica_playlist != NULL)
    {
        liberar_no_arv_binaria(raiz_musica_playlist, liberar_dados_musica_playlist);
    }
}

void delete_playlist(ARV_BINARIA **raiz_playlist)
{
    if (raiz_playlist != NULL)
    {
        delete_playlist(&(*raiz_playlist)->esq);
        delete_playlist(&(*raiz_playlist)->dir);

        delete_musica_playlist((*raiz_playlist)->info->playlist->musicas_raiz_arvore);

        liberar_no_arv_binaria(raiz_playlist, liberar_dados_playlist);
    }
}

void delete_all(ARV_BINARIA **raiz_artista, ARV_BINARIA **raiz_playlist)
{
    if (raiz_artista != NULL)
    {
        delete_playlist(raiz_playlist);
        *raiz_playlist = NULL;
    }

    if (raiz_artista != NULL)
    {
        delete_artista(raiz_artista);
        *raiz_artista = NULL;
    }
}
