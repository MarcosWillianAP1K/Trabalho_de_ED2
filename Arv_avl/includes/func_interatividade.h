#include "dados.h" // Ensure DADOS is defined here
#include "funcao_sistema.h"
#include "arv_avl.h"

#ifndef FUNC_INTERATIVIDADE_H
#define FUNC_INTERATIVIDADE_H



ARV_AVL *encontrar_dado_na_arv_digitando(ARV_AVL *raiz, DADOS *(*digite)(), int (*comparar)(DADOS *, DADOS *), void (*liberar)(DADOS **));

short int menu_que_volta();

short int comparar_se_esta_vazio(char *n1);

void mostrar_artistas(ARV_AVL *raiz_artista);

void mostrar_playlists(ARV_AVL *raiz_playlist);

void mostrar_artistas_por_tipo(ARV_AVL *raiz_artista, DADOS *tipo);

void mostrar_artistas_por_estilo(ARV_AVL *raiz_artista, DADOS *estilo);

void mostrar_artistas_por_tipo_e_estilo(ARV_AVL *raiz_artista, DADOS *tipo_estilo);

void mostrar_albuns_de_um_artista(DADOS *artista);

void mostrar_albuns_de_um_artista_de_um_ano(DADOS *artista, DADOS *ano_album);

void mostrar_musicas_de_um_album_de_um_artista(DADOS *album, DADOS *artista);

void mostrar_dados_de_uma_musica(ARV_AVL *raiz, DADOS *filtro);

void mostrar_albuns_de_todos_artistas_de_um_ano(ARV_AVL *raiz_artista, DADOS *ano);

void mostrar_dados_de_uma_playlist(DADOS *playlist);

short int remover_musica_de_uma_playlist(DADOS *playlist, DADOS *musica_a_remover);

short int remover_playlist(ARV_AVL **raiz_playlist, DADOS *playlist_a_remover);

ARV_AVL *verificar_nas_playlists(ARV_AVL *raiz_playlist, DADOS *musica_playlist);

short int remover_musica_de_album_de_artista(DADOS *artista ,DADOS *album, DADOS *musica_a_remover, ARV_AVL *raiz_playlist);

void delete_musica(ARV_AVL **raiz_musica);

void delete_album(ARV_AVL **raiz_album);

void delete_artista(ARV_AVL **raiz_artista);

void delete_musica_playlist(ARV_AVL **raiz_musica_playlist);

void delete_playlist(ARV_AVL **raiz_playlist);

void delete_all(ARV_AVL **raiz_artista, ARV_AVL **raiz_playlist);

short int cadastrar_artista(ARV_AVL **raiz_artista, DADOS *info);

short int cadastrar_album(DADOS *artista, DADOS *info);

short int cadastrar_musica(DADOS *album, DADOS *info);

short int cadastrar_playlist(ARV_AVL **raiz, DADOS *info);

short int cadastrar_musica_em_uma_playlist(DADOS *playlist, DADOS *info);

#endif
