#include "func_interatividade.h"
#include "arv_binaria.h"

#ifndef INTERATIVIDADE_H
#define INTERATIVIDADE_H

void cadastrar_artista_interativo(ARV_BINARIA **raiz_artista);

void cadastrar_album_interativo(ARV_BINARIA **raiz_artista);

void cadastrar_musica_interativo(ARV_BINARIA **raiz_artista);

void mostrar_artistas_interativo(ARV_BINARIA **raiz_artista);

void mostrar_artistas_de_um_tipo_interativo(ARV_BINARIA **raiz_artista);

void mostrar_artistas_de_um_estilo_musical_interativo(ARV_BINARIA **raiz_artista);

void mostrar_artistas_de_um_estilo_musical_e_tipo_interativo(ARV_BINARIA **raiz_artista);

void mostrar_albuns_de_um_artista_interativo(ARV_BINARIA **raiz_artista);

void mostrar_albuns_de_um_ano_de_um_artista_interativo(ARV_BINARIA **raiz_artista);

void mostrar_musicas_de_um_album_de_um_artista_interativo(ARV_BINARIA **raiz_artista);

void mostrar_albuns_de_todos_artistas_de_um_ano_interativo(ARV_BINARIA **raiz_artista);

void mostrar_dados_de_uma_musica_interativo(ARV_BINARIA **raiz_artista);

void cadastrar_playlist_interativo(ARV_BINARIA **raiz_playlist);

void cadastrar_musica_em_uma_playlist_interativo(ARV_BINARIA **raiz_artista, ARV_BINARIA **raiz_playlist);

void mostrar_playlists_interativo(ARV_BINARIA **raiz_playlist);

void mostrar_dados_de_uma_playlist_interativo(ARV_BINARIA **raiz_playlist);

void remover_musica_de_uma_playlist_interativo(ARV_BINARIA **raiz_playlist);

void remover_playlist_interativo(ARV_BINARIA **raiz_playlist);

void remover_musica_de_um_album_de_um_artista_interativo(ARV_BINARIA **raiz_artista, ARV_BINARIA **raiz_playlist);

void menu_principal(ARV_BINARIA **raiz_artista, ARV_BINARIA **raiz_playlist);


#endif