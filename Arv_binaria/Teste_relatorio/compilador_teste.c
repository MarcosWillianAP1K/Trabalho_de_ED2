#include <stdio.h>
#include <stdlib.h>

//Comando executa pelo CMD o compilador GCC para compilar os arquivos C e gerar um executável

int main()
{
    int compilador = 1;
    

    compilador = system("gcc -o executavel_teste ../iniciar_teste.c ../Cronometro.c ../../../Resultados_testes/Escrever_resultado.c ../../Tads/album.c ../../Tads/artista.c ../../Tads/arv_binaria.c ../../Tads/funcao_sistema.c  ../../Tads/func_interatividade.c ../../Tads/musica_playlist.c ../../Tads/musica.c ../../Tads/playlist.c ../../Tads/dados.c ");
    
    if (compilador == 0)
    {
        system("executavel_teste");
        
    }

    return 0;
} 