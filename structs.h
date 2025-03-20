


typedef struct ARV_BINARIA{
    void *info;
    struct ARV_BINARIA *esq;
    struct ARV_BINARIA *dir;
} ARV_BINARIA;



typedef struct ALBUM{
    char *titulo;
    char *data_lancamento;
    short int numero_de_musicas;
    void *musicas_raiz_arvore;
} ALBUM;

typedef struct MUSICA{
    char *titulo;
    char *duracao;
} MUSICA;


typedef struct ARTISTA{
    char *nome;
    char tipo[20];
    char estilo_musical[40];
    short int numero_de_albuns;
    void *albuns_raiz_arvore;

} ARTISTA;

