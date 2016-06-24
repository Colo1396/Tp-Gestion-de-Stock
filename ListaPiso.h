#ifndef __LISTAPISO_H__
#define __LISTAPISO_H__
#ifndef NULL
#define NULL      0
#endif
#include "PilaArtUb.h"

typedef PilaArtUb PilUb;
 struct NodoPiso{
 PilUb pilUb;// puntero a la pila
 NodoPiso *sgteP;//puntero al nodo siguente
 };

 typedef NodoPiso *PtrNodoPiso;// puntero de la estructura nodo

 struct ListaPiso{
 PtrNodoPiso primeroPiso;//declaro el PtrNodoCalle como el tipo de la variable primero
 };

//*******************

void crearListaPiso(ListaPiso &listaP);
//****************
bool listaVacia(ListaPiso &listaP);

PtrNodoPiso finP();
PtrNodoPiso primero(ListaPiso &listaP);
PtrNodoPiso siguiente(ListaPiso &listaP, PtrNodoPiso ptrNodoP);

PtrNodoPiso crearNodoLista(PilUb pilUb);

PtrNodoPiso anterior(ListaPiso &listaP, PtrNodoPiso ptrNodoP);

PtrNodoPiso ultimo(ListaPiso &listaP);

PtrNodoPiso adicionarPrincipio(ListaPiso &listaP, PilUb pilUb);

PtrNodoPiso adicionarDespues(ListaPiso &listaP, PilUb pilUb, PtrNodoPiso ptrNodoP);

PtrNodoPiso adicionarFinal(ListaPiso &listaP, PilUb pilUb);

PtrNodoPiso adicionarAntes(ListaPiso &listaP, PilUb pilUb, PtrNodoPiso ptrNodoP);

void colocarDato(ListaPiso &listaP, PilUb &pilUb, PtrNodoPiso ptrNodoP);

void obtenerDato(ListaPiso &listaP, PilUb &pilUb, PtrNodoPiso ptrNodoP);

void eliminarNodo(ListaPiso &listaP, PtrNodoPiso ptrNodoP);

void eliminarNodoPrimero(ListaPiso &listaP);

void eliminarNodoUltimo(ListaPiso &listaP);

void eliminarLista(ListaPiso &listaP);

PtrNodoPiso localizarDato(ListaPiso &listaP , PilUb pilUb);

PtrNodoPiso insertarDato(ListaPiso &listaP, PilUb pilUb);

void eliminarDato(ListaPiso &listaP, PilUb pilUb);

void reordenar(ListaPiso &listaP);

int longitud(ListaPiso &listaP);


#endif // __LISTAPISO_H__
