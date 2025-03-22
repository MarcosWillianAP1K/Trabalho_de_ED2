#include "album.h"
#include "musica.h"
#include "playlist.h"
#include "artista.h"

#ifndef DADOS_H
#define DADOS_H


typedef union DADOS{
    ARTISTA *artista;
    ALBUM *album;
    MUSICA *musica;
    PLAYLIST *playlist;
} DADOS;


#endif