#ifndef __PILAARTUB_H__
#define __PILAARTUB_H__
#include "ArtUbicacion.h"

#ifndef NULL
#define NULL      0
#endif
/* Tipo de Estructura de los Nodos de la Pila. */
typedef ArtUbicacion ArtUb;
struct NodoPilaArtUb{
ArtUb datoArtUb;
NodoPilaArtUb *sgteU;
};
/* Tipo de Puntero a los Nodos de la Pila, el cual se usa para recorrer
   la pila y acceder a sus Datos. */
typedef NodoPilaArtUb *PtrNodoPilaArtUb;
/* Tipo de Estructura de la Pila*/
struct PilaArtUb{
    PtrNodoPilaArtUb top;
    };
/*********************************************/
/*
  pre : la pila no debe haber sido creada.
  post: pila queda creada y preparada para ser usada.

  pilaArtUb : estructura de datos a ser creado.
*/
void crearPila(PilaArtUb &pilaArtUb);
/*********************************************/
/*
  pre : pila creada con crearpila().
  post: elimina el nodo apuntado por ptrNodo. No realiza accion si la pila
        esta vacia o si ptrNodo apunta a fin().

  pila : pila sobre la cual se invoca la primitiva.
  pilaArtUb : puntero al nodo que se desea eliminar.
*/
void destruir(PilaArtUb &pilaArtUb);
/*********************************************/
/*
  pre : pila Creada con crearpila().
  post: Devuelve true si pila esta vacia, sino devuelve false.

  pilaArtUb : pila sobre la cual se invoca la primitiva.
*/
bool pilaVacia(PilaArtUb &pilaArtUb);
/**********************************************/
/*
  pre : tiene que haber una pila creada.
  post: Se agrega el dato a la pila.

  pilaArtUb : pila sobre la cual se invoca la primitiva.
*/
void push(PilaArtUb &pilaArtUb,ArtUb datoArtUb);
/**********************************************/
/*
  pre : tiene que haber una pila creada.
  post: Se saca un nodo el dato a la pila.

  pilaArtUb : pila sobre la cual se invoca la primitiva.
*/
ArtUb pop(PilaArtUb &pilaArtUb);
/*********************************************/
/*
  pre : pila debe estar creada.
  post: devuelve el puntero al ultimo nodo de la pila, o devuelve fin() si
        si pila esta vacia.

  pilaArtUb : pila sobre la cual se invoca la primitiva.
*/
PtrNodoPilaArtUb finU();
/********************************************/
/*
  pre : pila debe estar  creada .
  post: devuelve el puntero al top de la pila

  pilaArtUb : pila  sobre la cual se invoca la primitiva.

*/
PtrNodoPilaArtUb top(PilaArtUb &pilaArtUb);
/*******************************************/
#endif // __PILAARTUB_H__
