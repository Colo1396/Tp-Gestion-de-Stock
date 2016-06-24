#ifndef __PILACAMION_H__
#define __PILACAMION_H__

#include "Camion.h"

#ifndef NULL
#define NULL      0
#endif
/* Tipo de Estructura de los Nodos de la Pila. */
typedef Camion Cam;
struct NodoPilaCamion{
Cam datoCamion;
NodoPilaCamion *sgteCa;
};
/* Tipo de Puntero a los Nodos de la Pila, el cual se usa para recorrer
   la pila y acceder a sus Datos. */
typedef NodoPilaCamion *PtrNodoPilaCamion;
/* Tipo de Estructura de la Pila*/
struct PilaCamion{
    PtrNodoPilaCamion top;
    };
/***************************************/
/*
  pre : la pila no debe haber sido creada.
  post: pila queda creada y preparada para ser usada.

  pilaCamion : estructura de datos a ser creado.
*/
void crearPila(PilaCamion &pilaCamion);
/***************************************/
/*
  pre : pila debe estar creada.
  post: elimina el nodo apuntado por ptrNodo. No realiza accion si la pila
        esta vacia o si ptrNodo apunta a fin().

  pilaCamion : pila sobre la cual se invoca la primitiva.
*/
void destruir(PilaCamion &pilaCamion);
/***************************************/
/*
  pre : pila debe estar creada.
  post: Devuelve true si pila esta vacia, sino devuelve false.

  pilaCamion : pila sobre la cual se invoca la primitiva.
*/
bool pilaVacia(PilaCamion &pilaCamion);
/***************************************/
/*
  pre : tiene que haber una pila creada.
  post: Se saca un nodo el dato a la pila.

  pilaCamion : pila sobre la cual se invoca la primitiva.
  cam datocamion : tipo de creo una instancia de tip camion
*/
void push(PilaCamion &pilaCamion,Cam datoCamion);
/***************************************/
/*
  pre : tiene que haber una pila creada.
  post: Se saca un nodo el dato a la pila.

  pilaCamion : pila sobre la cual se invoca la primitiva.
*/
Cam pop(PilaCamion &pilaCamion);
/***************************************/
/*
  pre : pila debe estar  creada .
  post: devuelve el puntero al top de la pila

  pilaCamion : pila sobre la cual se invoca la primitiva.

*/
PtrNodoPilaCamion top(PilaCamion &pilaCamion);
/***************************************/
/*
  pre : pila debe estar  creada .
  post: Si es nulo es el fin de pila camion


*/
PtrNodoPilaCamion finCa();
/***************************************/
#endif // __PILACAMION_H__
