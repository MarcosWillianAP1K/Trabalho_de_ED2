#include <stdio.h>
#include <stdlib.h>

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

int main()
{


    if (verificar_se_existem_arquivos() == 1)
    {
        
    }

    return 0;
}