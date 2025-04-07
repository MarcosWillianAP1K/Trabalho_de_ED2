#include "../includes/func_interatividade.h"
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

    aux->album = criar_album(titulo, "auxiliar", 0, NULL);

    return aux;
}

DADOS *digitar_data_album()
{
    DADOS *aux = alocar_dados();

    printf("Digite a data de lancamento do album\n");
    char *data_lancamento = digitar_string();

    aux->album = criar_album("auxiliar", data_lancamento, 0, NULL);

    return aux;
}

DADOS *digitar_titulo_ano_album()
{
    DADOS *aux = alocar_dados();

    printf("Digite o titulo do album\n");
    char *titulo = digitar_string();

    printf("Digite a data de lancamento do album\n");
    char *data_lancamento = digitar_string();

    aux->album = criar_album(titulo, data_lancamento, 0, NULL);

    return aux;
}

DADOS *digitar_titulo_musica()
{
    DADOS *aux = alocar_dados();

    printf("Digite o titulo da musica\n");
    char *titulo = digitar_string();

    aux->musica = criar_musica(titulo, "9.99");

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
    ARV_BINARIA *artista = buscar_arv_binaria(raiz_artista, aux, comparar_dados_tipo_e_estilo_artista);

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
        printf("Nenhum artista encontrado com o nome %s\n", artista);
    }

    liberar_dados_artista(&aux);
}

void mostrar_albuns_de_um_artista_de_um_ano(ARV_BINARIA *raiz_artista)
{
    DADOS *aux = digitar_nome_artista();
    ARV_BINARIA *artista = buscar_arv_binaria(raiz_artista, aux, comparar_dados_nome_artista);

    if (artista != NULL)
    {
        DADOS *aux2 = digitar_data_album();

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

void pecorrer_artistas(ARV_BINARIA *raiz_artista, DADOS *aux)
{
    if (raiz_artista != NULL)
    {
        pecorrer_artistas(raiz_artista->esq, aux);

        if (raiz_artista->info->artista->albuns_raiz_arvore != NULL)
        {
            printf("\nAlbuns do artista %s:\n\n", raiz_artista->info->artista->nome);
            imprimir_arv_binaria_filtro(raiz_artista->info->artista->albuns_raiz_arvore, aux, imprimir_dados_album, comparar_dados_data_album);
        }

        pecorrer_artistas(raiz_artista->dir, aux);
    }
}

void mostrar_albuns_de_todos_artistas_de_um_ano(ARV_BINARIA *raiz_artista)
{    
    DADOS *aux = digitar_data_album();

    pecorrer_artistas(raiz_artista, aux);

    liberar_dados_album(&aux);
}

void mostrar_dados_de_uma_musica(ARV_BINARIA *raiz)
{
    DADOS *aux = digitar_nome_artista();
    ARV_BINARIA *artista = buscar_arv_binaria(raiz, aux, comparar_dados_nome_artista);

    if (artista != NULL)
    {
        DADOS *aux2 = digitar_titulo_album();
        ARV_BINARIA *album = buscar_arv_binaria(artista->info->artista->albuns_raiz_arvore, aux2, comparar_dados_titulo_album);

        if (album != NULL)
        {
            DADOS *aux3 = digitar_titulo_musica();
            ARV_BINARIA *musica = buscar_arv_binaria(album->info->album->musicas_raiz_arvore, aux3, comparar_dados_titulo_musica);

            if (musica != NULL)
            {
                printf("\n");
                imprimir_dados_musica(musica->info);
            }
            else
            {
                printf("Nenhuma musica encontrada com o nome %s\n", aux3->musica->titulo);
            }

            liberar_dados_musica(&aux3);
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

void mostrar_dados_de_uma_playlist(ARV_BINARIA *raiz)
{
    DADOS *aux = digitar_nome_playlist();
    ARV_BINARIA *playlist = buscar_arv_binaria(raiz, aux, comparar_dados_nome_playlist);
    
    if (playlist != NULL)
    {
        printf("Dados da playlist %s:\n", playlist->info->playlist->nome);
        imprimir_dados_playlist(playlist->info);
    }
    else
    {
        printf("Nenhuma playlist encontrada com o nome %s\n", aux->playlist->nome);
    }

    liberar_dados_playlist(&aux);
}





void remover_musica_de_uma_playlist(ARV_BINARIA **raiz)
{
    
}

void remover_playlist(ARV_BINARIA **raiz)
{
}

void remover_musica_de_album_de_artista(ARV_BINARIA **raiz)
{
}

void delete_musica(ARV_BINARIA **raiz_musica)
{
    if (*raiz_musica != NULL)
    {
        liberar_no_arv_binaria(raiz_musica, liberar_dados_musica);
        printf("Entrou no deletar musica\n");
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
        
        printf("Entrou no delete album\n");
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
        
        printf("Entrou no delete artista\n");
        liberar_no_arv_binaria(raiz_artista, liberar_dados_artista);
    }
}

void delete_musica_playlist(ARV_BINARIA **raiz_musica_playlist)
{
    if (*raiz_musica_playlist != NULL)
    { 
        liberar_no_arv_binaria(raiz_musica_playlist, liberar_dados_musica_playlist);
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
    printf("Entrou no delete all\n");
    if (*raiz_playlist != NULL)
    {
        delete_playlist(raiz_playlist);
        *raiz_playlist = NULL;
    }

    if (*raiz_artista != NULL)
    {
        printf("Entrou no artista");
        delete_artista(raiz_artista);
        *raiz_artista = NULL;
    }
}





void cadastrar_artista(ARV_BINARIA **raiz_artista)
{
    
    printf("Digite o nome do artista: ");
    char *nome = digitar_string();
    
    printf("Digite o tipo do artista: ");
    char *tipo = digitar_string();
    
    printf("Digite o estilo musical do artista: ");
    char *estilo = digitar_string();
    
    DADOS *aux = alocar_dados();
    aux->artista = criar_artista(nome, tipo, estilo, 0, NULL);

    if (aux->artista != NULL)
    {
        inserir_arv_binaria(raiz_artista, aux, comparar_dados_nome_artista);
        printf("Artista cadastrado com sucesso!\n");
    }
    else
    {
        printf("Artista nao cadastrado!\n");
        liberar_dados_artista(&aux);
    }
}

// Não é necessario ponteiro por referencia, mas so pra padronizar mantem ele assim
void cadastrar_albuns(ARV_BINARIA **raiz_artista)
{
    DADOS *aux = digitar_nome_artista();
    ARV_BINARIA *artista = buscar_arv_binaria(*raiz_artista, aux, comparar_dados_nome_artista);

    liberar_dados_artista(&aux);

    if (artista != NULL)
    {
        DADOS *aux2 = alocar_dados();

        printf("Digite o titulo do album: ");
        char *titulo = digitar_string();

        printf("Digite a data de lancamento do album: ");
        char *data_lancamento = digitar_string();

        aux2->album = criar_album(titulo, data_lancamento, 0, NULL);

        if (aux2->album != NULL)
        {
            ARV_BINARIA *inserir = artista->info->artista->albuns_raiz_arvore;

            inserir_arv_binaria(&inserir, aux2, comparar_dados_titulo_album);
            artista->info->artista->albuns_raiz_arvore = inserir;

            artista->info->artista->numero_de_albuns++;
            printf("Album cadastrado com sucesso!\n");
        }
        else
        {
            printf("Album nao cadastrado!\n");
            liberar_dados_album(&aux2);
        }
    }
}

void cadastrar_musica(ARV_BINARIA **raiz_artista)
{
    DADOS *aux = digitar_nome_artista();
    ARV_BINARIA *artista = buscar_arv_binaria(*raiz_artista, aux, comparar_dados_nome_artista);

    liberar_dados_artista(&aux);

    if (artista != NULL)
    {
        DADOS *aux2 = digitar_titulo_album();
        ARV_BINARIA *album = buscar_arv_binaria(artista->info->artista->albuns_raiz_arvore, aux2, comparar_dados_titulo_album);

        liberar_dados_album(&aux2);

        if (album != NULL)
        {
            DADOS *aux3 = alocar_dados();

            printf("Digite o titulo da musica: ");
            char *titulo = digitar_string();

            printf("Digite o duracao da musica: ");
            char *duracao = digitar_string();

            aux3->musica = criar_musica(titulo, duracao);

            if (aux3->musica != NULL)
            {
                ARV_BINARIA *inserir = album->info->album->musicas_raiz_arvore;
                inserir_arv_binaria(&inserir, aux3, comparar_dados_titulo_musica);
                album->info->album->musicas_raiz_arvore = inserir;

                album->info->album->numero_de_musicas++;
                printf("Musica cadastrada com sucesso!\n");
            }
            else
            {
                printf("Musica nao cadastrada!\n");
                liberar_dados_musica(&aux3);
            }
        }
        else
        {
            printf("Album nao encontrado!\n");
            liberar_dados_album(&aux2);
        }
    }
}


void cadastrar_playlist(ARV_BINARIA **raiz)
{
    printf("Digite o nome da playlist: ");
    char *nome_playlist = digitar_string();

    DADOS *aux = alocar_dados();
    aux->playlist = criar_playlist(nome_playlist, 0, NULL);

    if (aux->playlist != NULL)
    {
        inserir_arv_binaria(raiz, aux, comparar_dados_nome_playlist);
        printf("Playlist cadastrada com sucesso!\n");
    }
    else
    {
        printf("Playlist nao cadastrada!\n");
        liberar_dados_playlist(&aux);
    }



}

void cadastrar_musica_em_uma_playlist(ARV_BINARIA **raiz_playlist, ARV_BINARIA **raiz_artista)
{
    DADOS *aux = digitar_nome_playlist();
    ARV_BINARIA *playlist = buscar_arv_binaria(*raiz_playlist, aux, comparar_dados_nome_playlist);

    liberar_dados_playlist(&aux);

    if (playlist != NULL)
    {
        DADOS *aux2 = digitar_nome_artista();
        ARV_BINARIA *artista = buscar_arv_binaria(*raiz_artista, aux2, comparar_dados_nome_artista);

        liberar_dados_artista(&aux2);

        if (artista != NULL)
        {
            DADOS *aux3 = digitar_titulo_album();
            ARV_BINARIA *album = buscar_arv_binaria(artista->info->artista->albuns_raiz_arvore, aux3, comparar_dados_titulo_album);

            liberar_dados_album(&aux3);

            if (album != NULL)
            {
                DADOS *aux4 = digitar_titulo_musica();
                ARV_BINARIA *musica = buscar_arv_binaria(album->info->album->musicas_raiz_arvore, aux4, comparar_dados_titulo_musica);

                liberar_dados_musica(&aux4);

                if (musica != NULL)
                {
                    ARV_BINARIA *inserir = playlist->info->playlist->musicas_raiz_arvore;
                    inserir_arv_binaria(&inserir, musica->info, comparar_dados_titulo_musica_musica_playlist);
                    playlist->info->playlist->musicas_raiz_arvore = inserir;

                    playlist->info->playlist->numero_de_musicas++;
                    printf("Musica cadastrada na playlist com sucesso!\n");
                }
                else
                {
                    printf("Musica nao encontrada!\n");
                    liberar_dados_musica(&aux4);
                }
            }
            else
            {
                printf("Album nao encontrado!\n");
                liberar_dados_album(&aux3);
            }
        }
        else
        {
            printf("Artista nao encontrado!\n");
            liberar_dados_artista(&aux2);
        }
    }
    else
    {

        printf("Playlist não encontrada\n");

    }
    
}