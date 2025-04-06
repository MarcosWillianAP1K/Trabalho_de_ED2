#include "dados.h" // Ensure DADOS is defined here
#include "funcao_sistema.h"
#include "arv_binaria.h"

#ifndef FUNC_INTERATIVIDADE_H
#define FUNC_INTERATIVIDADE_H

void mostrar_artista_por_tipo(ARV_BINARIA *raiz);

void mostrar_artista_por_estilo(ARV_BINARIA *raiz);

void mostrar_artista_por_tipo_e_estilo(ARV_BINARIA *raiz);

void mostrar_albuns_de_um_artista(ARV_BINARIA *raiz);

void mostrar_albuns_de_um_artista_de_um_ano(ARV_BINARIA *raiz);

void mostrar_musicas_de_um_album_de_um_artista(ARV_BINARIA *raiz);

void mostrar_dados_de_uma_musica(ARV_BINARIA *raiz);

void mostrar_albuns_de_todos_artistas_de_um_ano(ARV_BINARIA *raiz_artista);

void mostrar_dados_de_uma_playlist(ARV_BINARIA *raiz);

void remover_musica_de_uma_playlist(ARV_BINARIA *raiz);

void remover_playlist(ARV_BINARIA *raiz);

void remover_musica_de_album_de_artista(ARV_BINARIA *raiz);

void delete_musica(ARV_BINARIA **raiz_musica);

void delete_album(ARV_BINARIA **raiz_album);

void delete_artista(ARV_BINARIA **raiz_artista);

void delete_musica_playlist(ARV_BINARIA **raiz_musica_playlist);

void delete_playlist(ARV_BINARIA **raiz_playlist);

void delete_all(ARV_BINARIA **raiz_artista, ARV_BINARIA **raiz_playlist);

void cadastrar_artista(ARV_BINARIA **raiz_artista);

void cadastrar_albuns(ARV_BINARIA **raiz_artista);

void cadastrar_musica(ARV_BINARIA **raiz_artista);

void cadastrar_playlist(ARV_BINARIA **raiz);

void cadastrar_musica_em_uma_playlist(ARV_BINARIA **raiz_playlist, ARV_BINARIA **raiz_artista)

#endif
