#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Detalhe, os albuns




void gerar_testes_artistas_cresente(int quantidade_artistas)
{
    int largura_digitos = snprintf(NULL, 0, "%d", quantidade_artistas);

    FILE *arquivo = fopen("../Testes/Artistas_cresente.txt", "w");

    for (int i = 0; i < quantidade_artistas; i++)
    {
        char *nome_artista = (char *)malloc(sizeof(char) * (strlen("Teste Artista ") + largura_digitos + 1));
        
        snprintf(nome_artista, strlen("Teste Artista ") + largura_digitos + 1, "Teste Artista %0*d", largura_digitos, i + 1);

        fprintf(arquivo, "%s\n", nome_artista);
        free(nome_artista);
    }

    fclose(arquivo);
}

void gerar_testes_albuns_cresente(int quantidade_albuns)
{
    int largura_digitos = snprintf(NULL, 0, "%d", quantidade_albuns);

    FILE *arquivo = fopen("../Testes/Albuns_cresente.txt", "w");

    for (int i = 0; i < quantidade_albuns; i++)
    {
        char *nome_album = (char *)malloc(sizeof(char) * (strlen("Teste Album ") + largura_digitos + 1));
        
        snprintf(nome_album, strlen("Teste Album ") + largura_digitos + 1, "Teste Album %0*d", largura_digitos, i + 1);

        fprintf(arquivo, "%s\n", nome_album);
        free(nome_album);
    }

    fclose(arquivo);
    
}

void gerar_testes_musicas_cresente(int quantidade_musicas)
{
    int largura_digitos = snprintf(NULL, 0, "%d", quantidade_musicas);

    FILE *arquivo = fopen("../Testes/Musicas_cresente.txt", "w");

    for (int i = 0; i < quantidade_musicas; i++)
    {
        char *nome_musica = (char *)malloc(sizeof(char) * (strlen("Teste Musica ") + largura_digitos + 1));
        
        snprintf(nome_musica, strlen("Teste Musica ") + largura_digitos + 1, "Teste Musica %0*d", largura_digitos, i + 1);

        fprintf(arquivo, "%s\n", nome_musica);
        free(nome_musica);
    }

    fclose(arquivo);
    
}


void gerar_testes_artistas_decrescente(int quantidade_artistas)
{
    int largura_digitos = snprintf(NULL, 0, "%d", quantidade_artistas);

    FILE *arquivo = fopen("../Testes/Artistas_decrescente.txt", "w");

    for (int i = quantidade_artistas; i > 0; i--)
    {
        char *nome_artista = (char *)malloc(sizeof(char) * (strlen("Teste Artista ") + largura_digitos + 1));
        
        snprintf(nome_artista, strlen("Teste Artista ") + largura_digitos + 1, "Teste Artista %0*d", largura_digitos, i);

        fprintf(arquivo, "%s\n", nome_artista);
        free(nome_artista);
    }

    fclose(arquivo);
    
}

void gerar_testes_albuns_decrescente(int quantidade_albuns)
{
    int largura_digitos = snprintf(NULL, 0, "%d", quantidade_albuns);

    FILE *arquivo = fopen("../Testes/Albuns_decrescente.txt", "w");

    for (int i = quantidade_albuns; i > 0; i--)
    {
        char *nome_album = (char *)malloc(sizeof(char) * (strlen("Teste Album ") + largura_digitos + 1));
        
        snprintf(nome_album, strlen("Teste Album ") + largura_digitos + 1, "Teste Album %0*d", largura_digitos, i);

        fprintf(arquivo, "%s\n", nome_album);
        free(nome_album);
    }

    fclose(arquivo);
    
}

void gerar_testes_musicas_decrescente(int quantidade_musicas)
{
    int largura_digitos = snprintf(NULL, 0, "%d", quantidade_musicas);

    FILE *arquivo = fopen("../Testes/Musicas_decrescente.txt", "w");

    for (int i = quantidade_musicas; i > 0; i--)
    {
        char *nome_musica = (char *)malloc(sizeof(char) * (strlen("Teste Musica ") + largura_digitos + 1));
        
        snprintf(nome_musica, strlen("Teste Musica ") + largura_digitos + 1, "Teste Musica %0*d", largura_digitos, i);

        fprintf(arquivo, "%s\n", nome_musica);
        free(nome_musica);
    }

    fclose(arquivo);
    
}


void gerar_testes_artistas_aleatorio(int quantidade_artistas)
{
    int largura_digitos = snprintf(NULL, 0, "%d", quantidade_artistas);

    FILE *arquivo = fopen("../Testes/Artistas_aleatorio.txt", "w");

    int *usados = (int *)calloc(quantidade_artistas, sizeof(int));

    for (int i = 0; i < quantidade_artistas; i++)
    {
        int numero_aleatorio;
        do
        {
            numero_aleatorio = rand() % quantidade_artistas + 1;
        } while (usados[numero_aleatorio - 1]);

        usados[numero_aleatorio - 1] = 1;

        char *nome_artista = (char *)malloc(sizeof(char) * (strlen("Teste Artista ") + largura_digitos + 1));
        
        snprintf(nome_artista, strlen("Teste Artista ") + largura_digitos + 1, "Teste Artista %0*d", largura_digitos, numero_aleatorio);

        fprintf(arquivo, "%s\n", nome_artista);
        free(nome_artista);
    }

    free(usados);
    fclose(arquivo);
}

void gerar_testes_albuns_aleatorio(int quantidade_albuns)
{
    int largura_digitos = snprintf(NULL, 0, "%d", quantidade_albuns);

    FILE *arquivo = fopen("../Testes/Albuns_aleatorio.txt", "w");

    int *usados = (int *)calloc(quantidade_albuns, sizeof(int));

    for (int i = 0; i < quantidade_albuns; i++)
    {
        int numero_aleatorio;
        do
        {
            numero_aleatorio = rand() % quantidade_albuns + 1;
        } while (usados[numero_aleatorio - 1]);

        usados[numero_aleatorio - 1] = 1;

        char *nome_album = (char *)malloc(sizeof(char) * (strlen("Teste Album ") + largura_digitos + 1));
        
        snprintf(nome_album, strlen("Teste Album ") + largura_digitos + 1, "Teste Album %0*d", largura_digitos, numero_aleatorio);

        fprintf(arquivo, "%s\n", nome_album);
        free(nome_album);
    }

    free(usados);
    fclose(arquivo);
    
}

void gerar_testes_musicas_aleatorio(int quantidade_musicas)
{
    int largura_digitos = snprintf(NULL, 0, "%d", quantidade_musicas);

    FILE *arquivo = fopen("../Testes/Musicas_aleatorio.txt", "w");

    int *usados = (int *)calloc(quantidade_musicas, sizeof(int));

    for (int i = 0; i < quantidade_musicas; i++)
    {
        int numero_aleatorio;
        do
        {
            numero_aleatorio = rand() % quantidade_musicas + 1;
        } while (usados[numero_aleatorio - 1]);

        usados[numero_aleatorio - 1] = 1;

        char *nome_musica = (char *)malloc(sizeof(char) * (strlen("Teste Musica ") + largura_digitos + 1));
        
        snprintf(nome_musica, strlen("Teste Musica ") + largura_digitos + 1, "Teste Musica %0*d", largura_digitos, numero_aleatorio);

        fprintf(arquivo, "%s\n", nome_musica);
        free(nome_musica);
    }

    free(usados);
    fclose(arquivo);
    
}


void gerar_testes(int quantidade_artistas, int quantidade_albuns, int quantidade_musicas)
{
    gerar_testes_artistas_cresente(quantidade_artistas);
    gerar_testes_albuns_cresente(quantidade_albuns);
    gerar_testes_musicas_cresente(quantidade_musicas);
    
    gerar_testes_artistas_decrescente(quantidade_artistas);
    gerar_testes_albuns_decrescente(quantidade_albuns);
    gerar_testes_musicas_decrescente(quantidade_musicas);

    gerar_testes_artistas_aleatorio(quantidade_artistas);
    gerar_testes_albuns_aleatorio(quantidade_albuns);
    gerar_testes_musicas_aleatorio(quantidade_musicas);
}

