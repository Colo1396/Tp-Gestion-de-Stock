#ifndef __LDEPOSITO_H__
#define __LDEPOSITO_H__
#include "ArtDeposito.h"
#ifndef NULL
#define NULL      0
#endif

typedef ArtDeposito ArtDep;
struct NodoListaDeposito{
ArtDep datoArtDep;
NodoListaDeposito *sgteAD;
};

typedef NodoListaDeposito *PtrNodoListaDeposito;

struct ListaArtDeposito{
    PtrNodoListaDeposito primerArtDeposito;
};
//********************
void crearListaArtDeposito(ListaArtDeposito &listaArtDep);
//********************
bool listaVacia(ListaArtDeposito &listaArtDep);
//********************
PtrNodoListaDeposito finAD();
//********************
PtrNodoListaDeposito primero(ListaArtDeposito &listaArtDep);
//********************
PtrNodoListaDeposito siguiente(ListaArtDeposito &listaArtDep,PtrNodoListaDeposito ptrNodoListaDep);
//********************
PtrNodoListaDeposito anterior(ListaArtDeposito &listaArtDep,PtrNodoListaDeposito ptrNodoListaDep);
//********************
PtrNodoListaDeposito ultimo(ListaArtDeposito &listaArtDep);
//********************
PtrNodoListaDeposito crearNodoLista(ArtDep datoArtDep);
//********************
PtrNodoListaDeposito adicionarPrincipio(ListaArtDeposito &listaArtDep,ArtDep datoArtDep);
//********************
PtrNodoListaDeposito adicionarDespues(ListaArtDeposito &listaArtDep,ArtDep datoArtDep, PtrNodoListaDeposito ptrNodoListaDep);
//********************
PtrNodoListaDeposito adicionarFinal(ListaArtDeposito &listaArtDep, ArtDep datoArtDep);
//********************
void colocarDato(ListaArtDeposito &listaArtDep,ArtDep &datoArtDep, PtrNodoListaDeposito ptrNodoListaDep);
//********************
void obtenerDato(ListaArtDeposito &listaArtDep,ArtDep &datoArtDep, PtrNodoListaDeposito ptrNodoListaDep);
//*******************
void eliminarNodo(ListaArtDeposito &listaArtDep,PtrNodoListaDeposito ptrNodoListaDep);
//********************
void eliminarNodoPrimero(ListaArtDeposito &listaArtDep);
//********************
void eliminarNodoUltimo(ListaArtDeposito &listaArtDep);
//********************
void eliminarLista(ListaArtDeposito &listaArtDep);


#endif // __LDEPOSITO_H__
