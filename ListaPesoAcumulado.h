#ifndef __LISTAPESOACUMULADO_H__
#define __LISTAPESOACUMULADO_H__

#ifndef NULL
#define NULL      0
#endif

#include "PesoAcumulado.h"

typedef PesoAcum PesoA;

struct NodoListaPAcum{
PesoA datoPesoA;
NodoListaPAcum *sgtePA;
};

typedef NodoListaPAcum *PtrNodoListaPA;

struct ListaPesoAcum{
    PtrNodoListaPA primerPesoAcum;
};

//********************
void crearListaPesoAcum(ListaPesoAcum &listaPA);
//********************
bool listaVacia(ListaPesoAcum &listaPA);
//********************
PtrNodoListaPA finPA();
//********************
PtrNodoListaPA primero(ListaPesoAcum &listaPA);
//********************
PtrNodoListaPA siguiente(ListaPesoAcum &listaPA,PtrNodoListaPA ptrNodoListaPA);
//********************
PtrNodoListaPA anterior(ListaPesoAcum &listaPA,PtrNodoListaPA ptrNodoListaPA);
//********************
PtrNodoListaPA ultimo(ListaPesoAcum &listaPA);
//********************
PtrNodoListaPA crearNodoLista(PesoA datoPesoA);
//********************
PtrNodoListaPA adicionarPrincipio(ListaPesoAcum &listaPA,PesoA datoPesoA);
//********************
PtrNodoListaPA adicionarDespues(ListaPesoAcum &listaPA,PesoA datoPesoA, PtrNodoListaPA ptrNodoListaPA);
//********************
PtrNodoListaPA adicionarFinal(ListaPesoAcum &listaPA, PesoA datoPesoA);
//********************
void colocarDato(ListaPesoAcum &listaPA,PesoA &datoPesoA, PtrNodoListaPA ptrNodoListaPA);
//********************
void obtenerDato(ListaPesoAcum &listaPA,PesoA &datoPesoA, PtrNodoListaPA ptrNodoListaPA);
//********************
void eliminarNodo(ListaPesoAcum &listaPA,PtrNodoListaPA ptrNodoListaPA);
//********************
void eliminarNodoPrimero(ListaPesoAcum &listaPA);
//********************
void eliminarNodoUltimo(ListaPesoAcum &listaPA);
//********************
void eliminarLista(ListaPesoAcum &listaPA);


#endif // __LISTAPESOACUMULADO_H__
