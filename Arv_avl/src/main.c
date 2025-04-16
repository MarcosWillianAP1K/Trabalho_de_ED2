#include <stdio.h>
#include "../includes/interatividade.h"
#include "../includes/funcao_sistema.h"

// gcc src/main.c Tads/album.c Tads/artista.c Tads/arv_avl.c Tads/funcao_sistema.c Tads/interatividade.c Tads/musica_playlist.c Tads/musica.c Tads/playlist.c Tads/dados.c



int main()
{
    ARV_AVL *raiz_artista = NULL;
    ARV_AVL *raiz_playlist = NULL;

    

    menu_principal(&raiz_artista, &raiz_playlist);

    // Não ta funcionando direito, verificar
    printf("Liberando memoria...\n");
    delete_all(&raiz_artista, &raiz_playlist);

    printf("Programa encerrado.\n");

    return 0;
}