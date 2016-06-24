#ifndef __PILAARTUB_H__
#define __PILAARTUB_H__
#include "ArtUbicacion.h"

#ifndef NULL
#define NULL      0
#endif

typedef ArtUbicacion ArtUb;
struct NodoPilaArtUb{
ArtUb datoArtUb;
NodoPilaArtUb *sgteU;
};

typedef NodoPilaArtUb *PtrNodoPilaArtUb;

struct PilaArtUb{
    PtrNodoPilaArtUb top;
    };

void crearPila(PilaArtUb &pilaArtUb);

void destruir(PilaArtUb &pilaArtUb);

bool pilaVacia(PilaArtUb &pilaArtUb);

void push(PilaArtUb &pilaArtUb,ArtUb datoArtUb);

ArtUb pop(PilaArtUb &pilaArtUb);

PtrNodoPilaArtUb finU();
PtrNodoPilaArtUb top(PilaArtUb &pilaArtUb);

#endif // __PILAARTUB_H__
