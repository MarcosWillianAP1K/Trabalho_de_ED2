#include <stdio.h>
#include <stdlib.h>

int main()
{
    int compilador = system("gcc -o compilador ../src/main.c ../Tads/album.c ../Tads/artista.c ../Tads/arv_binaria.c ../Tads/funcao_sistema.c ../Tads/interatividade.c ../Tads/func_interatividade.c ../Tads/musica_playlist.c ../Tads/musica.c ../Tads/playlist.c ../Tads/dados.c ");
    
    if (compilador == 0)
    {
        // system("./compilador");
    }

    return 0;
}