#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../includes/func_interatividade.h"
#include "../../Resultados_testes/Escrever_resultado.h"
#include "Cronometro.h"

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

#define tamanho_buffer 200

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
    ARTISTA *artista = NULL;

    char buffer[tamanho_buffer];
    if (fgets(buffer, sizeof(buffer), arquivo_artista) != NULL)
    {
        remover_newline(buffer); // Remove o '\n' do final, se existir

        char *nome = (char *)malloc(strlen(buffer) + 1);

        verificar_alocacao(nome);
        

        strcpy(nome, buffer); // Copia o nome do artista para a variável nome

        artista = criar_artista(nome, NULL, NULL, 0, NULL); // Aloca apenas a memória necessária

    }

    return artista;
}

ALBUM *ler_album(FILE *arquivo_album)
{
    ALBUM *album = NULL;

    char buffer[tamanho_buffer];
    if (fgets(buffer, sizeof(buffer), arquivo_album) != NULL)
    {
        remover_newline(buffer); // Remove o '\n' do final, se existir

        char *titulo = (char *)malloc(strlen(buffer) + 1);
        
        verificar_alocacao(titulo);

        strcpy(titulo, buffer); // Copia o título do álbum para a variável título

        album = criar_album(titulo, 0, 0, NULL); // Aloca apenas a memória necessária
    }

    return album;
}

MUSICA *ler_musica(FILE *arquivo_musica)
{
    MUSICA *musica = NULL;

    char buffer[tamanho_buffer];
    if (fgets(buffer, sizeof(buffer), arquivo_musica) != NULL)
    {
        remover_newline(buffer); // Remove o '\n' do final, se existir

        char *titulo = (char *)malloc(strlen(buffer) + 1);

        verificar_alocacao(titulo);

        strcpy(titulo, buffer); // Copia o título da música para a variável título

        musica = criar_musica(titulo, 0, 0); // Aloca apenas a memória necessária
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

short int buscar_musica_de_um_album_de_um_artista(ARV_BINARIA *raiz_artista, char *artista, char *album, char *musica){
    short int retorno = 0;
    
    if (raiz_artista != NULL && artista != NULL && album != NULL && musica != NULL)
    {
        DADOS *artista_dados = alocar_dados();
        artista_dados->artista = criar_artista(artista, NULL, NULL, 0, NULL);

        ARV_BINARIA *retorno_artista = buscar_arv_binaria(raiz_artista, artista_dados, comparar_dados_nome_artista);
        if (retorno_artista != NULL)
        {
            DADOS *album_dados = alocar_dados();
            album_dados->album = criar_album(album, 0, 0, NULL);

            ARV_BINARIA *retorno_album = buscar_arv_binaria(retorno_artista->info->artista->albuns_raiz_arvore, album_dados, comparar_dados_titulo_album);
            if (retorno_album != NULL)
            {
                DADOS *musica_dados = alocar_dados();
                musica_dados->musica = criar_musica(musica, 0, 0);

                ARV_BINARIA *retorno_musica = buscar_arv_binaria(retorno_album->info->album->musicas_raiz_arvore, musica_dados, comparar_dados_titulo_musica);
                if (retorno_musica != NULL)
                {
                    retorno = 1;
                }
            }
        }

    }
    
    return retorno;
}


void insercao_crescente_na_arv_binaria(ARV_BINARIA **raiz_artista)
{
    pecorrer_arquivo_artista(DIRETORIO_ARTISTA_CRESCENTE, DIRETORIO_ALBUM_CRESCENTE, DIRETORIO_MUSICA_CRESCENTE, raiz_artista);
}

void insercao_decrescente_na_arv_binaria(ARV_BINARIA **raiz_artista)
{
    pecorrer_arquivo_artista(DIRETORIO_ARTISTA_DECRESCENTE, DIRETORIO_ALBUM_DECRESCENTE, DIRETORIO_MUSICA_DECRESCENTE, raiz_artista);
}

void insercao_aleatoria_na_arv_binaria(ARV_BINARIA **raiz_artista)
{
    pecorrer_arquivo_artista(DIRETORIO_ARTISTA_ALEATORIO, DIRETORIO_ALBUM_ALEATORIO, DIRETORIO_MUSICA_ALEATORIO, raiz_artista);
}

int main()
{
    #define NOME_ARQUIVO_RESULTADO "../RESULTADOS_TESTES.txt"

    #define BUSCAR_ARTISTA "Teste Artista 10"
    #define BUSCAR_ALBUM "Teste Album 10"
    #define BUSCAR_MUSICA "Teste Musica 10"

    if (verificar_se_existem_arquivos() == 1)
    {

        ARV_BINARIA *raiz_artista = NULL;
        char buffer[256];
        criar_resetar_arquivo_resultado(NOME_ARQUIVO_RESULTADO);

       
        escrever_resultado(NOME_ARQUIVO_RESULTADO, "Teste de desempenho da arvore binaria\n\nAs buscas foram feitas com os seguintes dados:\n\n");
        escrever_resultado(NOME_ARQUIVO_RESULTADO, BUSCAR_ARTISTA);
        escrever_resultado(NOME_ARQUIVO_RESULTADO, "\n");
        escrever_resultado(NOME_ARQUIVO_RESULTADO, BUSCAR_ALBUM);
        escrever_resultado(NOME_ARQUIVO_RESULTADO, "\n");
        escrever_resultado(NOME_ARQUIVO_RESULTADO, BUSCAR_MUSICA);
        escrever_resultado(NOME_ARQUIVO_RESULTADO, "\n\n");

        time_t cronometro;

        //CRESCENTE
        printf("CRESCENTE\n");

        cronometro = cronometro_iniciar();

        // Teste de inserção crescente
        insercao_crescente_na_arv_binaria(&raiz_artista);

        cronometro = cronometro_finalizar(cronometro);
        converter_para_string(cronometro, buffer, sizeof(buffer), converter_para_milisegundos);

        escrever_resultado(NOME_ARQUIVO_RESULTADO, "Tempo de insercao crescente: ");
        escrever_resultado(NOME_ARQUIVO_RESULTADO, buffer);
        escrever_resultado(NOME_ARQUIVO_RESULTADO, " Milisegundos\n");
        



        cronometro = cronometro_iniciar();
        // Teste de busca de uma musica de um album de um artista
        buscar_musica_de_um_album_de_um_artista(raiz_artista, BUSCAR_ARTISTA, BUSCAR_ALBUM, BUSCAR_MUSICA);
    

        cronometro = cronometro_finalizar(cronometro);
        converter_para_string(cronometro, buffer, sizeof(buffer), converter_para_milisegundos);

        escrever_resultado(NOME_ARQUIVO_RESULTADO, "Tempo de busca: ");
        escrever_resultado(NOME_ARQUIVO_RESULTADO, buffer);
        escrever_resultado(NOME_ARQUIVO_RESULTADO, " Milisegundos\n");


        

        cronometro = cronometro_iniciar();

        // Teste de deleção crescente
        delete_all(&raiz_artista, NULL);

        cronometro = cronometro_finalizar(cronometro);
        converter_para_string(cronometro, buffer, sizeof(buffer), converter_para_milisegundos);
        
        escrever_resultado(NOME_ARQUIVO_RESULTADO, "Tempo de exclusao crescente: ");
        escrever_resultado(NOME_ARQUIVO_RESULTADO, buffer);
        escrever_resultado(NOME_ARQUIVO_RESULTADO, " Milisegundos\n\n");


        // imprimir_arv_binaria(raiz_artista, imprimir_dados_artista);
        // imprimir_arv_binaria(raiz_artista->info->artista->albuns_raiz_arvore, imprimir_dados_album);
        // ARV_BINARIA *raiz_album = raiz_artista->info->artista->albuns_raiz_arvore;
        // imprimir_arv_binaria(raiz_album->info->album->musicas_raiz_arvore, imprimir_dados_musica);

      
        
        //DECRESCENTE
        printf("\nDECRESCENTE\n");

        cronometro = cronometro_iniciar();
        
        // Teste de inserção decrescente
        insercao_decrescente_na_arv_binaria(&raiz_artista);

        cronometro = cronometro_finalizar(cronometro);
        converter_para_string(cronometro, buffer, sizeof(buffer), converter_para_milisegundos);
        
        escrever_resultado(NOME_ARQUIVO_RESULTADO, "Tempo de insercao decrescente: ");
        escrever_resultado(NOME_ARQUIVO_RESULTADO, buffer);
        escrever_resultado(NOME_ARQUIVO_RESULTADO, " Milisegundos\n");



        
        cronometro = cronometro_iniciar();

        // Teste de busca de uma musica de um album de um artista
        buscar_musica_de_um_album_de_um_artista(raiz_artista, BUSCAR_ARTISTA, BUSCAR_ALBUM, BUSCAR_MUSICA);
       

        cronometro = cronometro_finalizar(cronometro);
        converter_para_string(cronometro, buffer, sizeof(buffer), converter_para_milisegundos);

        escrever_resultado(NOME_ARQUIVO_RESULTADO, "Tempo de busca: ");
        escrever_resultado(NOME_ARQUIVO_RESULTADO, buffer);
        escrever_resultado(NOME_ARQUIVO_RESULTADO, " Milisegundos\n");



        cronometro = cronometro_iniciar();

        // Teste de deleção decrescente
        delete_all(&raiz_artista, NULL);

        cronometro = cronometro_finalizar(cronometro);
        converter_para_string(cronometro, buffer, sizeof(buffer), converter_para_milisegundos);

        escrever_resultado(NOME_ARQUIVO_RESULTADO, "Tempo de exclusao decrescente: ");
        escrever_resultado(NOME_ARQUIVO_RESULTADO, buffer);
        escrever_resultado(NOME_ARQUIVO_RESULTADO, " Milisegundos\n\n");


        raiz_artista = NULL;

        //ALEATORIO
        printf("\nALEATORIO\n");

        cronometro = cronometro_iniciar();
        
        // Teste de inserção aleatória
        insercao_aleatoria_na_arv_binaria(&raiz_artista);

        cronometro = cronometro_finalizar(cronometro);

        converter_para_string(cronometro, buffer, sizeof(buffer), converter_para_milisegundos);


        escrever_resultado(NOME_ARQUIVO_RESULTADO, "Tempo de insercao aleatoria: ");
        escrever_resultado(NOME_ARQUIVO_RESULTADO, buffer);
        escrever_resultado(NOME_ARQUIVO_RESULTADO, " Milisegundos\n");


        cronometro = cronometro_iniciar();

        // Teste de busca de uma musica de um album de um artista
        buscar_musica_de_um_album_de_um_artista(raiz_artista, BUSCAR_ARTISTA, BUSCAR_ALBUM, BUSCAR_MUSICA);
        

        cronometro = cronometro_finalizar(cronometro);
        converter_para_string(cronometro, buffer, sizeof(buffer), converter_para_milisegundos);

        escrever_resultado(NOME_ARQUIVO_RESULTADO, "Tempo de busca: ");
        escrever_resultado(NOME_ARQUIVO_RESULTADO, buffer);
        escrever_resultado(NOME_ARQUIVO_RESULTADO, " Milisegundos\n");



        
        cronometro = cronometro_iniciar();

        // Teste de deleção aleatória
        delete_all(&raiz_artista, NULL);

        cronometro = cronometro_finalizar(cronometro);
        converter_para_string(cronometro, buffer, sizeof(buffer), converter_para_milisegundos);

        escrever_resultado(NOME_ARQUIVO_RESULTADO, "Tempo de exclusao aleatoria: ");
        escrever_resultado(NOME_ARQUIVO_RESULTADO, buffer);
        escrever_resultado(NOME_ARQUIVO_RESULTADO, " Milisegundos\n\n");

    }

    return 0;
}