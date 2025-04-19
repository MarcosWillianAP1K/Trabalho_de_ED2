#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/func_interatividade.h"

// Mantenha a quantidade de artistas, albuns e musicas igual a quantidade de artistas, albuns e musicas que o gerador de testes gera
#define QUANTIDADE_ARTISTAS 10
#define QUANTIDADE_ALBUNS 10
#define QUANTIDADE_MUSICAS 10

#define DIRETORIO_ARTISTA_CRESCENTE "../../../Gerador_de_testes/Testes/Artistas_crescente.txt"
#define DIRETORIO_ARTISTA_DECRESCENTE "../../../Gerador_de_testes/Testes/Artistas_decrescente.txt"
#define DIRETORIO_ARTISTA_ALEATORIO "../../../Gerador_de_testes/Testes/Artistas_aleatorio.txt"

#define DIRETORIO_ALBUM_CRESCENTE "../../../Gerador_de_testes/Testes/Albuns_crescente.txt"
#define DIRETORIO_ALBUM_DECRESCENTE "../../../Gerador_de_testes/Testes/Albuns_decrescente.txt"
#define DIRETORIO_ALBUM_ALEATORIO "../../../Gerador_de_testes/Testes/Albuns_aleatorio.txt"

#define DIRETORIO_MUSICA_CRESCENTE "../../../Gerador_de_testes/Testes/Musicas_crescente.txt"
#define DIRETORIO_MUSICA_DECRESCENTE "../../../Gerador_de_testes/Testes/Musicas_decrescente.txt"
#define DIRETORIO_MUSICA_ALEATORIO "../../../Gerador_de_testes/Testes/Musicas_aleatorio.txt"

short int verificar_se_existem_arquivos()
{
    short int retorno = 1;
    FILE *arquivo_artista_crescente = fopen(DIRETORIO_ARTISTA_CRESCENTE, "r");
    FILE *arquivo_artista_decrescente = fopen(DIRETORIO_ARTISTA_DECRESCENTE, "r");
    FILE *arquivo_artista_aleatorio = fopen(DIRETORIO_ARTISTA_ALEATORIO, "r");

    FILE *arquivo_album_crescente = fopen(DIRETORIO_ALBUM_CRESCENTE, "r");
    FILE *arquivo_album_decrescente = fopen(DIRETORIO_ALBUM_DECRESCENTE, "r");
    FILE *arquivo_album_aleatorio = fopen(DIRETORIO_ALBUM_ALEATORIO, "r");

    FILE *arquivo_musica_crescente = fopen(DIRETORIO_MUSICA_CRESCENTE, "r");
    FILE *arquivo_musica_decrescente = fopen(DIRETORIO_MUSICA_DECRESCENTE, "r");
    FILE *arquivo_musica_aleatorio = fopen(DIRETORIO_MUSICA_ALEATORIO, "r");

    if (arquivo_artista_crescente == NULL)
    {
        printf("Falha ao abrir o arquivo: Artista_crescente.txt\n");
        retorno = 0;
    }
    if (arquivo_artista_decrescente == NULL)
    {
        printf("Falha ao abrir o arquivo: Artista_decrescente.txt\n");
        retorno = 0;
    }
    if (arquivo_artista_aleatorio == NULL)
    {
        printf("Falha ao abrir o arquivo: Artista_aleatorio.txt\n");
        retorno = 0;
    }

    if (arquivo_album_crescente == NULL)
    {
        printf("Falha ao abrir o arquivo: Album_crescente.txt\n");
        retorno = 0;
    }
    if (arquivo_album_decrescente == NULL)
    {
        printf("Falha ao abrir o arquivo: Album_decrescente.txt\n");
        retorno = 0;
    }
    if (arquivo_album_aleatorio == NULL)
    {
        printf("Falha ao abrir o arquivo: Album_aleatorio.txt\n");
        retorno = 0;
    }

    if (arquivo_musica_crescente == NULL)
    {
        printf("Falha ao abrir o arquivo: Musica_crescente.txt\n");
        retorno = 0;
    }
    if (arquivo_musica_decrescente == NULL)
    {
        printf("Falha ao abrir o arquivo: Musica_decrescente.txt\n");
        retorno = 0;
    }
    if (arquivo_musica_aleatorio == NULL)
    {
        printf("Falha ao abrir o arquivo: Musica_aleatorio.txt\n");
        retorno = 0;
    }

    fclose(arquivo_artista_crescente);
    fclose(arquivo_artista_decrescente);
    fclose(arquivo_artista_aleatorio);

    fclose(arquivo_album_crescente);
    fclose(arquivo_album_decrescente);
    fclose(arquivo_album_aleatorio);

    fclose(arquivo_musica_crescente);
    fclose(arquivo_musica_decrescente);
    fclose(arquivo_musica_aleatorio);

    return retorno;
}

void verificar_abertura_arquivos(FILE *arquivo)
{
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
}

void remover_newline(char *str)
{
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
}

ARTISTA *ler_artista(FILE *arquivo_artista)
{
    ARTISTA *artista = alocar_artista();

    char buffer[256];
    if (fgets(buffer, sizeof(buffer), arquivo_artista) != NULL)
    {
        remover_newline(buffer); // Remove o '\n' do final, se existir
        artista->nome = malloc(strlen(buffer) + 1); // Aloca apenas a memória necessária
        verificar_alocacao(artista->nome); // Verifica se a alocação de memória foi bem-sucedida

        strcpy(artista->nome, buffer); // Copia a string para a memória alocada
    }

    return artista;
}

ALBUM *ler_album(FILE *arquivo_album)
{
    ALBUM *album = alocar_album();

    char buffer[256];
    if (fgets(buffer, sizeof(buffer), arquivo_album) != NULL)
    {
        remover_newline(buffer); // Remove o '\n' do final, se existir
        album->titulo = malloc(strlen(buffer) + 1); // Aloca apenas a memória necessária
        verificar_alocacao(album->titulo); // Verifica se a alocação de memória foi bem-sucedida

        strcpy(album->titulo, buffer); // Copia a string para a memória alocada
    }

    return album;
}

MUSICA *ler_musica(FILE *arquivo_musica)
{
    MUSICA *musica = alocar_musica();

    char buffer[256];
    if (fgets(buffer, sizeof(buffer), arquivo_musica) != NULL)
    {
        remover_newline(buffer); // Remove o '\n' do final, se existir
        musica->titulo = malloc(strlen(buffer) + 1); // Aloca apenas a memória necessária
        verificar_alocacao(musica->titulo); // Verifica se a alocação de memória foi bem-sucedida

        strcpy(musica->titulo, buffer); // Copia a string para a memória alocada
    }

    return musica;
}


void pecorrer_arquivo_musica(char *diretorio_musica, DADOS *album)
{
    FILE *arquivo_musica = fopen(diretorio_musica, "r");

    verificar_abertura_arquivos(arquivo_musica);

    for (int i = 0; i < QUANTIDADE_MUSICAS; i++)
    {
        DADOS *musica = alocar_dados();
        musica->musica = ler_musica(arquivo_musica);
    
        if (cadastrar_musica(album, musica) != 1)
        {
            printf("Falha ao cadastrar a musica: %s\n", musica->musica->titulo);
        }
    }

    fclose(arquivo_musica);
    
}

void pecorrer_arquivo_album(char *diretorio_album, char *diretorio_musica, DADOS *artista)
{
    FILE *arquivo_album = fopen(diretorio_album, "r");

    verificar_abertura_arquivos(arquivo_album);

    for (int i = 0; i < QUANTIDADE_ALBUNS; i++)
    {
        DADOS *album = alocar_dados();
        album->album = ler_album(arquivo_album);

        if (cadastrar_album(artista, album) == 1)
        {
            pecorrer_arquivo_musica(diretorio_musica, album);
        }
        else
        {
            printf("Falha ao cadastrar o album: %s\n", album->album->titulo);
        }

    }

    fclose(arquivo_album);
    
}

void pecorrer_arquivo_artista(char *diretorio_artista, char *diretorio_album, char *diretorio_musica, ARV_BINARIA **raiz_artista)
{
    FILE *arquivo_artista = fopen(diretorio_artista, "r");

    verificar_abertura_arquivos(arquivo_artista);

    for (int i = 0; i < QUANTIDADE_ARTISTAS; i++)
    {
        DADOS *artista = alocar_dados();
        artista->artista = ler_artista(arquivo_artista);

        if (cadastrar_artista(raiz_artista, artista) == 1)
        {
            
            pecorrer_arquivo_album(diretorio_album, diretorio_musica, artista);
        }
        else
        {
            printf("Falha ao cadastrar o artista: %s\n", artista->artista->nome);
        }

    }

    fclose(arquivo_artista);
    
}

void insercao_crescente_na_arv_binaria(ARV_BINARIA **raiz_artista)
{
    pecorrer_arquivo_artista(DIRETORIO_ARTISTA_CRESCENTE, DIRETORIO_ALBUM_CRESCENTE, DIRETORIO_MUSICA_CRESCENTE, raiz_artista);
}

int main()
{

    if (verificar_se_existem_arquivos() == 1)
    {
        ARV_BINARIA *raiz_artista = NULL;
        insercao_crescente_na_arv_binaria(&raiz_artista);

        imprimir_arv_binaria(raiz_artista, imprimir_dados_artista); 

        delete_all(&raiz_artista, NULL); // Libera a memória alocada para a árvore binária de artistas
    }

    return 0;
}