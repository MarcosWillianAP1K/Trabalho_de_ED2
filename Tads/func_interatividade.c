#include "../includes/func_interatividade.h"

#include <stdio.h>
#include <stdlib.h>


void mostrar_artista_por_tipo(ARV_BINARIA *raiz, ARTISTA *artista)
{
    printf("Digite o tipo: ");
    
    char *tipo = digitar_string();

    DADOS *aux = alocar_dados();
    aux->artista = criar_artista("auxiliar", *tipo, "auxiliar", 0, NULL);

    if (*tipo != '\0')
    {
        imprimir_arv_binaria_filtro(raiz, aux, imprimir_artista, comparar_dados_tipo_artista);
    }
    else
    {
        printf("Nenhum artista encontrado com o tipo %s\n", tipo);
    }

    liberar_dados_artista(&aux);
}

void mostrar_artista_por_estilo(ARV_BINARIA *raiz, ARTISTA *artista)
{
    printf("Digite o estilo: ");
    
    char *estilo = digitar_string();

    DADOS *aux = alocar_dados();
    aux->artista = criar_artista("auxiliar", "auxiliar", *estilo, 0, NULL);

    if (*estilo != '\0')
    {
        imprimir_arv_binaria_filtro(raiz, aux, imprimir_artista, comparar_dados_estilo_artista);
    }
    else
    {
        printf("Nenhum artista encontrado com o estilo %s\n", estilo);
    }

    liberar_dados_artista(&aux);
}

void mostrar_artista_por_tipo_e_estilo(ARV_BINARIA *raiz, ARTISTA *artista)
{
    printf("Digite o tipo: ");
    
    char *tipo = digitar_string();

    printf("Digite o estilo: ");
    
    char *estilo = digitar_string();

    DADOS *aux = alocar_dados();
    aux->artista = criar_artista("auxiliar", *tipo, *estilo, 0, NULL);

    if (*tipo != '\0' && *estilo != '\0')
    {
        imprimir_arv_binaria_filtro(raiz, aux, imprimir_artista, comparar_dados_tipo_e_estilo_artista);
    }
    else
    {
        printf("Nenhum artista encontrado com o tipo %s e estilo %s\n", tipo, estilo);
    }

    liberar_dados_artista(&aux);
}

void albuns_um_artista(ARV_BINARIA *raiz, ARTISTA *artista)
{
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
}

void albuns_um_artista_um_ano(ARV_BINARIA *raiz, ARTISTA *artista)
{
    printf("Digite o nome do artista: ");
    char nome_artista[50];
    scanf("%s", nome_artista);
    artista = buscar_artista_por_nome(raiz, nome_artista);
    if (artista != NULL)
    {
        printf("Digite o ano: ");
        int ano;
        scanf("%d", &ano);
        printf("Albuns do artista %s no ano %d:\n", artista->nome, ano);
        imprimir_albuns_por_ano(artista->albuns_raiz_arvore, ano, imprimir_album);
    }
    else
    {
        printf("Nenhum artista encontrado com o nome %s\n", nome_artista);
    }
}

void mostra_r_musicas_album(ARV_BINARIA *raiz, ALBUM *album)
{
    printf("Digite o nome do album: ");
    char nome_album[50];
    scanf("%s", nome_album);
    album = buscar_album_por_nome(raiz, nome_album);
    if (album != NULL)
    {
        printf("Musicas do album %s:\n", album->titulo);
        imprimir_arv_binaria(album->musicas_raiz_arvore, imprimir_musica);
    }
    else
    {
        printf("Nenhum album encontrado com o nome %s\n", nome_album);
    }
}

void mostrar_dados_musica(ARV_BINARIA *raiz, MUSICA *musica)
{
    printf("Digite o nome da musica: ");
    char nome_musica[50];
    scanf("%s", nome_musica);
    musica = buscar_musica_por_nome(raiz, nome_musica);
    if (musica != NULL)
    {
        printf("Dados da musica %s:\n", musica->titulo);
        imprimir_musica(musica);
    }
    else
    {
        printf("Nenhuma musica encontrada com o nome %s\n", nome_musica);
    }
}

void mostrar_dados_playlist(ARV_BINARIA *raiz, PLAYLIST *playlist)
{
    printf("Digite o nome da playlist: ");
    char nome_playlist[50];
    scanf("%s", nome_playlist);
    playlist = buscar_playlist_por_nome(raiz, nome_playlist);
    if (playlist != NULL)
    {
        printf("Dados da playlist %s:\n", playlist->nome);
        imprimir_playlist(playlist);
    }
    else
    {
        printf("Nenhuma playlist encontrada com o nome %s\n", nome_playlist);
    }
}

void remover_musica_playlist(ARV_BINARIA *raiz, PLAYLIST *playlist)
{
    printf("Digite o nome da playlist: ");
    char nome_playlist[50];
    scanf("%s", nome_playlist);
    playlist = buscar_playlist_por_nome(raiz, nome_playlist);
    
    if (playlist != NULL)
    {
        printf("Digite o nome da musica: ");
        char nome_musica[50];
        scanf("%s", nome_musica);
        remover_musica_da_playlist(playlist, nome_musica);
    }
    else
    {
        printf("Nenhuma playlist encontrada com o nome %s\n", nome_playlist);
    }
}

void remover_playlist(ARV_BINARIA *raiz, PLAYLIST *playlist)
{
    printf("Digite o nome da playlist: ");
    char nome_playlist[50];
    scanf("%s", nome_playlist);
    playlist = buscar_playlist_por_nome(raiz, nome_playlist);
    if (playlist != NULL)
    {
        remover_playlist_da_arvore(raiz, playlist);
        printf("Playlist %s removida com sucesso.\n", nome_playlist);
    }
    else
    {
        printf("Nenhuma playlist encontrada com o nome %s\n", nome_playlist);
    }
}

void remover_musica_de_album_de_artista(ARV_BINARIA *raiz, ARTISTA *artista, ALBUM *album, MUSICA *musica)
{
    printf("Digite o nome do artista: ");
    char nome_artista[50];
    scanf("%s", nome_artista);
    artista = buscar_artista_por_nome(raiz, nome_artista);
    if (artista != NULL)
    {
        printf("Digite o nome do album: ");
        char nome_album[50];
        scanf("%s", nome_album);
        album = buscar_album_por_nome(artista->albuns_raiz_arvore, nome_album);
        if (album != NULL)
        {
            printf("Digite o nome da musica: ");
            char nome_musica[50];
            scanf("%s", nome_musica);
            musica = buscar_musica_por_nome(album->musicas_raiz_arvore, nome_musica);
            if (musica != NULL)
            {
                remover_musica_do_album(artista, album, musica);
                printf("Musica %s removida do album %s do artista %s.\n", musica->titulo, album->titulo, artista->nome);
            }
            else
            {
                printf("Nenhuma musica encontrada com o nome %s\n", nome_musica);
            }
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


void delete_musica(ARV_BINARIA **raiz_musica)
{
    if ((*raiz_musica) != NULL)
    {
        liberar_no_arv_binaria(raiz_musica, liberar_dados_musica);
        raiz_musica = NULL;
    }
}

void delete_album(ARV_BINARIA **raiz_album)
{
    if (raiz_album != NULL)
    {
        delete_album((*raiz_album)->esq);
        delete_album((*raiz_album)->dir);

        delete_musica(&(ARV_BINARIA *)(*raiz_album)->info->album->musicas_raiz_arvore);

        liberar_no_arv_binaria(&raiz_album, liberar_dados_album);
        raiz_album = NULL;
    }
}

void delete_artista(ARV_BINARIA **raiz_artista)
{
    if (raiz_artista != NULL)
    {
        delete_artista((*raiz_artista)->esq);
        delete_artista((*raiz_artista)->dir);

        delete_album(&(ARV_BINARIA *)(*raiz_artista)->info->artista->albuns_raiz_arvore);

        liberar_no_arv_binaria(raiz_artista, liberar_dados_artista);
        raiz_artista = NULL;
    }
    
}

void delete_musica_playlist(ARV_BINARIA **raiz_musica_playlist)
{
    if (raiz_musica_playlist != NULL)
    {
        liberar_no_arv_binaria(raiz_musica_playlist, liberar_dados_musica_playlist);
        raiz_musica_playlist = NULL;
    }
}

void delete_playlist(ARV_BINARIA **raiz_playlist)
{
    if (raiz_playlist != NULL)
    {
        delete_playlist((*raiz_playlist)->esq);
        delete_playlist((*raiz_playlist)->dir);

        delete_musica_playlist(&(ARV_BINARIA *)(*raiz_playlist)->info->playlist->musicas_raiz_arvore);

        liberar_no_arv_binaria(raiz_playlist, liberar_dados_playlist);
        raiz_playlist = NULL;
    }
}

void delete_all(ARV_BINARIA **raiz_artista, ARV_BINARIA **raiz_playlist)
{
    delete_playlist(raiz_playlist);
    delete_artista(raiz_artista);

    *raiz_artista = NULL;
    *raiz_playlist = NULL;
}
