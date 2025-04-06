#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/funcao_sistema.h"

void limpar_buffer()
{
    // char c;
    // while ((c = getchar()) != '\n' && c != EOF)
    //     ;

    fflush(stdin);
}

void limpar_tela()
{
    system("cls||clear"); // Para Windows
    // system("clear"); // Para Linux e MacOS
}

void pausar_tela()
{
    // printf("\nPressione qualquer tecla para continuar...");
    // getchar();

    system("pause");
}

void mensagem_erro(char *mensagem)
{
    printf("\n\033[1;31mERRO: %s\033[0m\n\n", mensagem);
}

void verificar_alocacao(void *ponteiro)
{
    if (ponteiro == NULL)
    {
        mensagem_erro("Erro ao alocar memoria");
        exit(1);
    }
}

void verificar_realocacao(void *ponteiro)
{
    if (ponteiro == NULL)
    {
        mensagem_erro("Erro ao realocar memoria");
        exit(1);
    }
}

char *digitar_string()
{
    limpar_buffer();
#define TAM_PADRAO 20

    int tam, cont = 0;
    char *nome = (char *)malloc(TAM_PADRAO * sizeof(char));

    if (fgets(nome, TAM_PADRAO * sizeof(char), stdin) != NULL)
    {

        tam = strlen(nome);

        while (nome[tam - 1] != '\n')
        {
            cont++;
            char *temp = (char *)realloc(nome, (TAM_PADRAO * cont) * sizeof(char));

            verificar_realocacao(temp);

            nome = temp;

            if (fgets(nome + tam, ((TAM_PADRAO * cont) * sizeof(char)) - tam, stdin) == NULL)
            {
                //xiu
                break;
            }

            tam = strlen(nome);
        }
    }

    tam = strlen(nome);

    if (nome[tam - 1] == '\n')
    {
        nome[tam - 1] = '\0';
    }

    limpar_buffer();

    return nome;
}

short int digitar_short_int()
{
    short int numero = 0;
    
    while (scanf("%hd", &numero) != 1 || numero < 0)
    {
        mensagem_erro("Numero invalido ");
        limpar_buffer();
        printf("Digite novamente: ");
    }
    
    return numero;
}

char digitar_um_caracter()
{
    char c;
    scanf("%c", &c);
    limpar_buffer();

    return c;
}