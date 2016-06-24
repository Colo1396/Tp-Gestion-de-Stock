#ifndef __LISTAVENTAS_H__
#define __LISTAVENTAS_H__

#ifndef NULL
#define NULL        0
#endif // NULL

#include "Ventas.h"

typedef Ventas Venta;

struct NodoListaVentas{
Venta datoVenta;
NodoListaVentas *sgteV;
};

typedef NodoListaVentas *PtrNodoListaVentas;

struct ListaVentas{
PtrNodoListaVentas primeroListaVentas;
};

//********************
void crearListaVenta(ListaVentas &listaV);
//********************
bool listaVacia(ListaVentas &listaV);
//********************
PtrNodoListaVentas finV();
//********************
PtrNodoListaVentas primero(ListaVentas &listaV);
//********************
PtrNodoListaVentas siguiente(ListaVentas &listaV,PtrNodoListaVentas ptrNodoListaVent);
//********************
PtrNodoListaVentas anterior(ListaVentas &listaV,PtrNodoListaVentas ptrNodoListaVent);
//********************
PtrNodoListaVentas ultimo(ListaVentas &listaV);
//********************
PtrNodoListaVentas crearNodoLista(Venta datoVenta);
//********************
PtrNodoListaVentas adicionarPrincipio(ListaVentas &listaV,Venta datoVenta);
//********************
PtrNodoListaVentas adicionarDespues(ListaVentas &listaV,Venta datoVenta, PtrNodoListaVentas ptrNodoListaVent);
//********************
PtrNodoListaVentas adicionarFinal(ListaVentas &listaV, Venta datoVenta);
//********************
void colocarDato(ListaVentas &listaV,Venta &datoVenta, PtrNodoListaVentas ptrNodoListaVent);
//********************
void obtenerDato(ListaVentas &listaV,Venta &datoVenta, PtrNodoListaVentas ptrNodoListaVent);
//********************
void eliminarNodo(ListaVentas &listaV,PtrNodoListaVentas ptrNodoListaVent);
//********************
void eliminarNodoPrimero(ListaVentas &listaV);
//********************
void eliminarNodoUltimo(ListaVentas &listaV);
//********************
void eliminarLista(ListaVentas &listaV);

#endif // __LISTAVENTAS_H__
