#ifndef __LISTACALLE_H__
#define __LISTACALLE_H__
#ifndef NULL
#define NULL      0
#endif
#include "ListaPiso.h"

typedef ListaPiso ListPiso;
 struct NodoCalle{
 ListPiso listPiso ;// puntero al piso
 NodoCalle *sgteC;//puntero al nodo siguente
 };

 typedef NodoCalle *PtrNodoCalle;// puntero de la estructura nodo

 struct ListaCalle{
 PtrNodoCalle primeroCalle;//declaro el PtrNodoCalle como el tipo de la variable primero
 };

void crearListaCalle(ListaCalle &listaC);
//****************
bool listaVacia(ListaCalle &listaC);

PtrNodoCalle finC();
PtrNodoCalle primero(ListaCalle &listaC);
PtrNodoCalle siguiente(ListaCalle &listaC,PtrNodoCalle ptrNodoCalle);


// Definicion de Primitivas


PtrNodoCalle anterior(ListaCalle &listaC, PtrNodoCalle ptrNodoC);

PtrNodoCalle ultimo(ListaCalle &listaC);

PtrNodoCalle crearNodoLista(ListPiso listPiso);

PtrNodoCalle adicionarPrincipio(ListaCalle &listaC, ListPiso listPiso);
PtrNodoCalle adicionarDespues(ListaCalle &listaC, ListPiso listPiso, PtrNodoCalle ptrNodoC);

PtrNodoCalle adicionarFinal(ListaCalle &listaC,ListPiso listPiso);

PtrNodoCalle adicionarAntes(ListaCalle &listaC, ListPiso listPiso, PtrNodoCalle ptrNodoC);

void colocarDato(ListaCalle &listaC,ListPiso listPiso, PtrNodoCalle ptrNodoC);

void obtenerDato(ListaCalle &listaC, ListPiso listPiso, PtrNodoCalle ptrNodoC);

void eliminarNodo(ListaCalle &listaC, PtrNodoCalle ptrNodoC);

void eliminarNodoPrimero(ListaCalle &listaC);

void eliminarNodoUltimo(ListaCalle &listaC);

void eliminarLista(ListaCalle &listaC);

// Definición de Operaciones Adicionales

PtrNodoCalle localizarDato(ListaCalle &listaC , ListPiso listPiso);

PtrNodoCalle insertarDato(ListaCalle &listaC, ListPiso listPiso);

void eliminarDato(ListaCalle &listaC, ListPiso listPiso);

void reordenar(ListaCalle &listaC);

int longitud(ListaCalle &listaC);


#endif // __LISTACALLE_H__

