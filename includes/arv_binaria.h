#include "dados.h"



#ifndef ARV_BINARIA_H
#define ARV_BINARIA_H


typedef struct ARV_BINARIA{
    union dados *info;
    struct ARV_BINARIA *esq;
    struct ARV_BINARIA *dir;
    int ID;
} ARV_BINARIA;





#endif
