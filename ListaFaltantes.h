#ifndef __LISTAFALTANTES_H__
#define __LISTAFALTANTES_H__
#include "Faltantes.h"
#ifndef NULL
#define NULL      0
#endif
typedef Faltantes Faltante;

struct NodoFaltante{
Faltante datoFaltante;
NodoFaltante *sgteF;
};

typedef NodoFaltante *PtrNodoFaltante;

struct ListaFaltante{
PtrNodoFaltante primerFaltante;
};
//********************
void crearListaFaltante(ListaFaltante &listaF);
//********************
bool listaVacia(ListaFaltante &listaF);
//********************
PtrNodoFaltante finF();
//********************
PtrNodoFaltante primero(ListaFaltante &listaF);
//********************
PtrNodoFaltante siguiente(ListaFaltante &listaF,PtrNodoFaltante ptrNodoFaltante);
//********************
PtrNodoFaltante anterior(ListaFaltante &listaF,PtrNodoFaltante ptrNodoFaltante);
//********************
PtrNodoFaltante ultimo(ListaFaltante &listaF);
//********************
PtrNodoFaltante crearNodoLista(Faltante datoFaltante);
//********************
PtrNodoFaltante adicionarPrincipio(ListaFaltante &listaF,Faltante datoFaltante);
//********************
PtrNodoFaltante adicionarDespues(ListaFaltante &listaF,Faltante datoFaltante, PtrNodoFaltante ptrNodoFaltante);
//********************
PtrNodoFaltante adicionarFinal(ListaFaltante &listaF, Faltante datoFaltante);
//********************
void colocarDato(ListaFaltante &listaF,Faltante &datoFaltante, PtrNodoFaltante ptrNodoFaltante);
//********************
void obtenerDato(ListaFaltante &listaF,Faltante &datoFaltante, PtrNodoFaltante ptrNodoFaltante);
//********************
void eliminarNodo(ListaFaltante &listaF,PtrNodoFaltante ptrNodoFaltante);
//********************
void eliminarNodoPrimero(ListaFaltante &listaF);
//********************
void eliminarNodoUltimo(ListaFaltante &listaF);
//********************
void eliminarLista(ListaFaltante &listaF);


#endif // __LISTAFALTANTES_H__
