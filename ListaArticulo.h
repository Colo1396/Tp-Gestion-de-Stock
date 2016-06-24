#ifndef __LISTAARTICULO_H__
#define __LISTAARTICULO_H__
#include "Articulo.h"

#ifndef NULL
#define NULL      0
#endif

typedef Articulo LArt;
struct NodoListaArt{
LArt datoLArt;
NodoListaArt *sgteArt;
};
typedef NodoListaArt *PrtNodoListaArt;

struct ListaArt{
PrtNodoListaArt primeroListaArt;
};
//********************
void crearListaArt(ListaArt &listaA);
//********************
bool listaVacia(ListaArt &listaA);
//********************
PrtNodoListaArt finA();
//********************
PrtNodoListaArt primero(ListaArt &listaA);
//********************
PrtNodoListaArt siguiente(ListaArt &listaA,PrtNodoListaArt ptrNodoListaArt);
//********************
PrtNodoListaArt anterior(ListaArt  &listaA,PrtNodoListaArt ptrNodoListaArt);
//********************
PrtNodoListaArt ultimo(ListaArt &listaA);
//********************
PrtNodoListaArt crearNodoLista(LArt datoArticulo);
//********************
PrtNodoListaArt adicionarPrincipio(ListaArt &listaA,LArt datoArticulo);
//********************
PrtNodoListaArt adicionarDespues(ListaArt &listaA,LArt datoArticulo, PrtNodoListaArt ptrNodoListaArt);
//********************
PrtNodoListaArt adicionarFinal(ListaArt  &listaA, LArt datoArticulo);
//********************
void colocarDato(ListaArt  &listaA,LArt &datoArticulo, PrtNodoListaArt ptrNodoListaArt);
//********************
void obtenerDato(ListaArt  &listaA,LArt &datoArticulo, PrtNodoListaArt ptrNodoListaArt);
//********************
void eliminarNodo(ListaArt  &listaA,PrtNodoListaArt ptrNodoListaArt);
//********************
void eliminarNodoPrimero(ListaArt  &listaA);
//********************
void eliminarNodoUltimo(ListaArt  &listaA);
//********************
void eliminarLista(ListaArt  &listaA);
#endif // __LISTAARTICULO_H__
