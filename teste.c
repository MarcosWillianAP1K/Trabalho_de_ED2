#include <stdio.h>
#include <stdlib.h>

// Definindo as estruturas e a union
struct Pessoa {
    char nome[50];
    int idade;
};

struct Endereco {
    char rua[100];
    int numero;
};

typedef union dados {
    struct Pessoa *pessoa;
    struct Endereco *endereco;
} DADOS;

// Definindo a estrutura da árvore binária
typedef struct ARV_BINARIA {
    DADOS *info;
    struct ARV_BINARIA *esq;
    struct ARV_BINARIA *dir;
} ARV_BINARIA;

// Função para liberar a estrutura Pessoa
void liberarPessoa(DADOS **info) {
    if (*info && (*info)->pessoa) {
        printf("Liberando Pessoa: %s\n", (*info)->pessoa->nome);
        free((*info)->pessoa);
        (*info)->pessoa = NULL;
    }
}

// Função para liberar a estrutura Endereco
void liberarEndereco(DADOS **info) {
    if (*info && (*info)->endereco) {
        printf("Liberando Endereço: %s\n", (*info)->endereco->rua);
        free((*info)->endereco);
        (*info)->endereco = NULL;
    }
}

// Função que libera a árvore binária e o membro 'info' de acordo com o tipo
void liberar_arv_binaria(ARV_BINARIA **raiz, void (*liberar)(DADOS **)) {
    if (raiz != NULL && *raiz != NULL) {
        liberar_arv_binaria(&((*raiz)->esq), liberar);
        liberar_arv_binaria(&((*raiz)->dir), liberar);

        if ((*raiz)->info != NULL) {
            liberar(&(*raiz)->info);
        }

        free(*raiz);
        *raiz = NULL;
    }
}

int main() {
    // Alocando memória para a árvore binária e suas estruturas
    ARV_BINARIA *raiz = malloc(sizeof(ARV_BINARIA));
    raiz->info = malloc(sizeof(DADOS));
    raiz->info->pessoa = malloc(sizeof(struct Pessoa));
    sprintf(raiz->info->pessoa->nome, "Carlos");
    raiz->info->pessoa->idade = 30;
    
    // Chamando a função para liberar a árvore e o membro info
    liberar_arv_binaria(&raiz, liberarPessoa);

    return 0;
}