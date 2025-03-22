#include "album.h"
#include "musica.h"
#include "playlist.h"
#include "artista.h"
#include "musica_playlist.h"

#ifndef DADOS_H
#define DADOS_H

typedef union DADOS{
    ARTISTA *artista;
    ALBUM *album;
    MUSICA *musica;
    PLAYLIST *playlist;
    MUSICA_PLAYLIST *musica_playlist;
} DADOS;


#endif