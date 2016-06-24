#ifndef __LISTAVENTAS_H__
#define __LISTAVENTAS_H__

#ifndef NULL
#define NULL        0
#endif // NULL

#include "Ventas.h"
/* Tipo de Informacion que esta contenida en los Nodos de la lista*/
typedef Ventas Venta;
/* Tipo de Estructura de los Nodos de la Lista. */

struct NodoListaVentas{
Venta datoVenta;
NodoListaVentas *sgteV;
};
/* Tipo de Puntero a los Nodos de la Lista*/
typedef NodoListaVentas *PtrNodoListaVentas;
/* Tipo de Estructura de la Lista */
struct ListaVentas{
PtrNodoListaVentas primeroListaVentas;
};

//********************
/*
  pre : la lista no debe haber sido creada.
  post: lista queda creada y preparada para ser usada.
  listaV: estructura de datos a ser creado.
*/
void crearListaVenta(ListaVentas &listaV);
//********************
/*
  pre : lista Creada anteriormente.
  post: Devuelve true si lista esta vacia, sino devuelve false.
  listaV : lista sobre la cual se invoca la primitiva.
*/
bool listaVacia(ListaVentas &listaV);
//********************
/*
  pre : lista debe estar creada.
  post: devuelve la representacion de lo Siguiente al último Nodo de la lista,
        o sea el valor Null.
  return: representación del fin de la lista.
*/
PtrNodoListaVentas finV();
//********************
/*
  pre : lista debe haber sido creada
  post: devuelve el puntero al primer elemento de la lista, o devuelve fin() si
        esta vacia
  listaV : Lista sobre la cual se invoca la primitiva.
  return puntero al primer nodo.
*/
PtrNodoListaVentas primero(ListaVentas &listaV);
//********************
/*
  pre : lista debe estar creada.
  post: devuelve el puntero al nodo proximo del apuntado, o devuelve fin() si
        ptrNodo apuntaba a fin() o si lista esta vacia.
  listaV : lista sobre la cual se invoca la primitiva.
  prtNodoListaVent : puntero al nodo a partir del cual se requiere el siguiente.
  return puntero al nodo siguiente.
*/
PtrNodoListaVentas siguiente(ListaVentas &listaV,PtrNodoListaVentas ptrNodoListaVent);
//********************
/*
  pre : lista Creada anteriormente.
        ptrNodoListaVentas es un puntero a un nodo de lista.
  post: devuelve el puntero al nodo anterior del apuntado, o devuelve fin() si
        el punter apuntaba al primero o si lista esta vacia.
  listav : lista sobre la cual se invoca la primitiva.
  prtNodoListaVentas : puntero al nodo a partir del cual se requiere el anterior.
  return puntero al nodo anterior.
*/
PtrNodoListaVentas anterior(ListaVentas &listaV,PtrNodoListaVentas ptrNodoListaVent);
//********************
/*
  pre : lista creada con anterioridad
  post: devuelve el puntero al ultimo nodo de la lista, o devuelve fin() si
        si lista esta vacia.
  listaV : lista sobre la cual se invoca la primitiva.
  return puntero al último nodo.
*/
PtrNodoListaVentas ultimo(ListaVentas &listaV);
//********************
/*
  pre : lista creada con anterioridad
  post: devuelve el puntero al ultimo nodo de la lista, o devuelve fin() si
        si lista esta vacia.
  datoVenta: dato faltante ya viene creado de antes.
  return crea un nodo en la lista.
*/
PtrNodoListaVentas crearNodoLista(Venta datoVenta);
//********************
/*
  pre : lista creada
  post: agrega un nodo nuevo al principio de la lista con el dato proporcionado
        y devuelve un puntero a ese elemento.

  listaF : lista sobre la cual se invoca la primitiva.
  datFaltanteo : elemento a adicionar al principio de la lista.
  return puntero al nodo adicionado.
*/
PtrNodoListaVentas adicionarPrincipio(ListaVentas &listaV,Venta datoVenta);
//********************
/*
  pre : lista creada
  post: agrega un nodo despues del apuntado por puntero con el dato
        proporcionado y devuelve un puntero apuntado al elemento insertado.
  listav : lista sobre la cual se invoca la primitiva.
  datoVenta : elemento a adicionar.
  ptrNodoListaVent: puntero al nodo después del cual se quiere adicionar el dato.
  return puntero al nodo adicionado.
*/
PtrNodoListaVentas adicionarDespues(ListaVentas &listaV,Venta datoVenta, PtrNodoListaVentas ptrNodoListaVent);
//********************
/*
  pre : lista creada
  post: agrega un nodo al final de la lista con el dato proporcionado y devuelve
        un puntero al nodo insertado.
  listaV: lista sobre la cual se invoca la primitiva.
  datoVenta : elemento a adicionar al final de la lista.
  return puntero al nodo adicionado.
*/
PtrNodoListaVentas adicionarFinal(ListaVentas &listaV, Venta datoVenta);
//********************
/*
  pre : lista creada, no vacia. puntero al nodo es distinto de fin().
  post: coloca el dato proporcionado en el nodo apuntado por ptrNodo.

  listaV : lista sobre la cual se invoca la primitiva.
  datoVenta : elemento a colocar.
  ptrNodo : puntero al nodo del cual se quiere colocar el dato.
*/
void colocarDato(ListaVentas &listaV,Venta &datoVenta, PtrNodoListaVentas ptrNodoListaVent);
//********************
/*
  pre : lista creada ,no vacia. puntero al nodo es distinto de fin().
  post: devuelve el dato del nodo apuntado por ptrNodo.

  listaV : lista sobre la cual se invoca la primitiva.
  datoVentas: elemento obtenido.
  ptrNodoListaVent : puntero al nodo del cual se quiere obtener el dato.
*/
void obtenerDato(ListaVentas &listaV,Venta &datoVenta, PtrNodoListaVentas ptrNodoListaVent);
//********************
/*
  pre : lista creada
  post: elimina el nodo apuntado por el puntero. No realiza accion si la lista
        esta vacia o si puntero apunta a fin().

  listaV : lista sobre la cual se invoca la primitiva.
  ptrNodoListaVent : puntero al nodo que se desea eliminar.
*/
void eliminarNodo(ListaVentas &listaV,PtrNodoListaVentas ptrNodoListaVent);
//********************
/*
  pre : lista creada
  post: si la lista no esta vacia, elimina su nodo primero, sino no realiza
        accion alguna.
listaV : lista sobre la cual se invoca la primitiva.
*/
void eliminarNodoPrimero(ListaVentas &listaV);
//********************
/*
  pre : lista creada
  post: Elimina nodo ultimo de la lista.
listaV : lista sobre la cual se invoca la primitiva.
*/
void eliminarNodoUltimo(ListaVentas &listaV);
//********************
/*
  pre : lista creada
  post: elimina todos los Nodos de la lista quedando destruida.
  listaV : lista sobre la cual se invoca la primitiva.
*/
void eliminarLista(ListaVentas &listaV);

#endif // __LISTAVENTAS_H__
