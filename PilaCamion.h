#ifndef __PILACAMION_H__
#define __PILACAMION_H__

#include "Camion.h"

#ifndef NULL
#define NULL      0
#endif

typedef Camion Cam;
struct NodoPilaCamion{
Cam datoCamion;
NodoPilaCamion *sgteCa;
};

typedef NodoPilaCamion *PtrNodoPilaCamion;

struct PilaCamion{
    PtrNodoPilaCamion top;
    };

void crearPila(PilaCamion &pilaCamion);

void destruir(PilaCamion &pilaCamion);
//1 es vacio ,0 es lleno
bool pilaVacia(PilaCamion &pilaCamion);

void push(PilaCamion &pilaCamion,Cam datoCamion);

Cam pop(PilaCamion &pilaCamion);
PtrNodoPilaCamion top(PilaCamion &pilaCamion);
PtrNodoPilaCamion finCa();
#endif // __PILACAMION_H__
