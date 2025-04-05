#include "dados.h" // Ensure DADOS is defined here
#include "funcao_sistema.h"
#include "arv_binaria.h"

#ifndef FUNC_INTERATIVIDADE_H
#define FUNC_INTERATIVIDADE_H

void mostrar_art_por_tipo(ARV_BINARIA *raiz, ARTISTA *artista);

void mostrar_art_por_estilo(ARV_BINARIA *raiz, ARTISTA *artista);

void mostrar_art_por_tipo_e_estilo(ARV_BINARIA *raiz, ARTISTA *artista);

void albuns_um_artista(ARV_BINARIA *raiz, ARTISTA *artista);

void albuns_um_artista_um_ano(ARV_BINARIA *raiz, ARTISTA *artista);

void mostra_r_musicas_album(ARV_BINARIA *raiz, ALBUM *album);

void mostrar_dados_musica(ARV_BINARIA *raiz, MUSICA *musica);

void mostrar_dados_playlist(ARV_BINARIA *raiz, PLAYLIST *playlist);

void remover_musica_playlist(ARV_BINARIA *raiz, PLAYLIST *playlist);

void remover_playlist(ARV_BINARIA *raiz, PLAYLIST *playlist);

void remover_musica_de_album_de_artista(ARV_BINARIA *raiz, ARTISTA *artista, ALBUM *album, MUSICA *musica);

void delete_musica(ARV_BINARIA **raiz_musica);

void delete_album(ARV_BINARIA **raiz_album);

void delete_artista(ARV_BINARIA **raiz_artista);

void delete_musica_playlist(ARV_BINARIA **raiz_musica_playlist);

void delete_playlist(ARV_BINARIA **raiz_playlist);

void delete_all(ARV_BINARIA **raiz_artista, ARV_BINARIA **raiz_playlist);

#endif
