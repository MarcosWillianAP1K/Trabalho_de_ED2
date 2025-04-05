#include <stdio.h>
#include <../includes/interatividade.h>
#include <../includes/funcao_sistema.h>
#include <../includes/arv_binaria.h>


//gcc src/main.c Tads/album.c Tads/artista.c Tads/arv_binaria.c Tads/funcao_sistema.c Tads/interatividade.c Tads/musica_playlist.c Tads/musica.c Tads/playlist.c Tads/dados.c

int main()
{
    ARV_BINARIA *raiz_artista = NULL;
    ARV_BINARIA *raiz_playlist = NULL;

    menu_principal(raiz_artista, raiz_playlist);

    liberar_arv_binaria(raiz_playlist, liberar_playlist );

    return 0;
}