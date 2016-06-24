#ifndef __LISTAPESOACUMULADO_H__
#define __LISTAPESOACUMULADO_H__
#ifndef NULL
#define NULL      0
#endif
#include "PesoAcumulado.h"
/* Tipo de Informacion que esta contenida en los Nodos de la lista*/
typedef PesoAcum PesoA;
/* Tipo de Estructura de los Nodos de la Lista. */
struct NodoListaPAcum{
PesoA datoPesoA;
NodoListaPAcum *sgtePA;
};
/* Tipo de Puntero a los Nodos de la Lista*/
typedef NodoListaPAcum *PtrNodoListaPA;
/* Tipo de Estructura de la Lista */
struct ListaPesoAcum{
    PtrNodoListaPA primerPesoAcum;
};

//********************
/*
  pre : la lista no debe haber sido creada.
  post: lista queda creada y preparada para ser usada.
  listaPesoAcum : estructura de datos a ser creado.
*/
void crearListaPesoAcum(ListaPesoAcum &listaPA);
//********************
/*
  pre : lista Creada anteriormente.
  post: Devuelve true si lista esta vacia, sino devuelve false.
  listaPA : lista sobre la cual se invoca la primitiva.
*/
bool listaVacia(ListaPesoAcum &listaPA);
//********************
/*
  pre : lista debe estar creada.
  post: devuelve la representacion de lo Siguiente al último Nodo de la lista,
        o sea el valor Null.
  return: representación del fin de la lista.
*/
PtrNodoListaPA finPA();
//********************
/*
  pre : lista debe haber sido creada
  post: devuelve el puntero al primer elemento de la lista, o devuelve fin() si
        esta vacia
  listaPA : Lista sobre la cual se invoca la primitiva.
  return puntero al primer nodo.
*/
PtrNodoListaPA primero(ListaPesoAcum &listaPA);
//********************
/*
  pre : lista debe estar creada.
  post: devuelve el puntero al nodo proximo del apuntado, o devuelve fin() si
        ptrNodo apuntaba a fin() o si lista esta vacia.
  listaPA : lista sobre la cual se invoca la primitiva.
  prtNodoListaPA : puntero al nodo a partir del cual se requiere el siguiente.
  return puntero al nodo siguiente.
*/
PtrNodoListaPA siguiente(ListaPesoAcum &listaPA,PtrNodoListaPA ptrNodoListaPA);
//********************
/*
  pre : lista Creada anteriormente.
        ptrNodoListaPA es un puntero a un nodo de lista.
  post: devuelve el puntero al nodo anterior del apuntado, o devuelve fin() si
        el punter apuntaba al primero o si lista esta vacia.
  listaPA : lista sobre la cual se invoca la primitiva.
  prtNodoListaPA : puntero al nodo a partir del cual se requiere el anterior.
  return puntero al nodo anterior.
*/
PtrNodoListaPA anterior(ListaPesoAcum &listaPA,PtrNodoListaPA ptrNodoListaPA);
//********************
/*
  pre : lista creada con anterioridad
  post: devuelve el puntero al ultimo nodo de la lista, o devuelve fin() si
        si lista esta vacia.
  listaPA : lista sobre la cual se invoca la primitiva.
  return puntero al último nodo.
*/
PtrNodoListaPA ultimo(ListaPesoAcum &listaPA);
//********************
/*
  pre : lista creada con anterioridad
  post: devuelve el puntero al ultimo nodo de la lista, o devuelve fin() si
        si lista esta vacia.
  datoPesoA : dato pesoA ya viene creado de antes.
  return crea un nodo en la lista.
*/
PtrNodoListaPA crearNodoLista(PesoA datoPesoA);
//********************
/*
  pre : lista creada
  post: agrega un nodo nuevo al principio de la lista con el dato proporcionado
        y devuelve un puntero a ese elemento.

  listaPA: lista sobre la cual se invoca la primitiva.
  datPesoA : elemento a adicionar al principio de la lista.
  return puntero al nodo adicionado.
*/
PtrNodoListaPA adicionarPrincipio(ListaPesoAcum &listaPA,PesoA datoPesoA);
//********************
/*
  pre : lista creada
  post: agrega un nodo despues del apuntado por puntero con el dato
        proporcionado y devuelve un puntero apuntado al elemento insertado.
  listaPA : lista sobre la cual se invoca la primitiva.
  datoPesoA : elemento a adicionar.
  ptrNodoListaPA : puntero al nodo después del cual se quiere adicionar el dato.
  return puntero al nodo adicionado.
*/
PtrNodoListaPA adicionarDespues(ListaPesoAcum &listaPA,PesoA datoPesoA, PtrNodoListaPA ptrNodoListaPA);
//********************
/*
  pre : lista creada
  post: agrega un nodo al final de la lista con el dato proporcionado y devuelve
        un puntero al nodo insertado.
  listaPA : lista sobre la cual se invoca la primitiva.
  datoPesoA : elemento a adicionar al final de la lista.
  return puntero al nodo adicionado.
*/
PtrNodoListaPA adicionarFinal(ListaPesoAcum &listaPA, PesoA datoPesoA);
//********************
/*
  pre : lista creada, no vacia. puntero al nodo es distinto de fin().
  post: coloca el dato proporcionado en el nodo apuntado por ptrNodo.

  listaPA : lista sobre la cual se invoca la primitiva.
  datoPesoA : elemento a colocar.
  ptrNodoListaPA : puntero al nodo del cual se quiere colocar el dato.
*/
void colocarDato(ListaPesoAcum &listaPA,PesoA &datoPesoA, PtrNodoListaPA ptrNodoListaPA);
//********************
/*
  pre : lista creada ,no vacia. puntero al nodo es distinto de fin().
  post: devuelve el dato del nodo apuntado por ptrNodo.

  listaPA : lista sobre la cual se invoca la primitiva.
  datoPesoA: elemento obtenido.
  ptrNodoListaPA : puntero al nodo del cual se quiere obtener el dato.
*/
void obtenerDato(ListaPesoAcum &listaPA,PesoA &datoPesoA, PtrNodoListaPA ptrNodoListaPA);
//********************
/*
  pre : lista creada
  post: elimina el nodo apuntado por el puntero. No realiza accion si la lista
        esta vacia o si puntero apunta a fin().

  listaPA: lista sobre la cual se invoca la primitiva.
  ptrNodoListaPA : puntero al nodo que se desea eliminar.
*/
void eliminarNodo(ListaPesoAcum &listaPA,PtrNodoListaPA ptrNodoListaPA);
//********************
/*
  pre : lista creada
  post: si la lista no esta vacia, elimina su nodo primero, sino no realiza
        accion alguna.
listaPA : lista sobre la cual se invoca la primitiva.
*/
void eliminarNodoPrimero(ListaPesoAcum &listaPA);
//********************
/*
  pre : lista creada.
  post: si la lista no esta vacia elimina su nodo ultimo,
        sino no realiza accion.
  listaPA : lista sobre la cual se invoca la primitiva.
*/
void eliminarNodoUltimo(ListaPesoAcum &listaPA);
//********************
/*
  pre : lista creada
  post: elimina todos los Nodos de la lista quedando destruida.
  listaPA : lista sobre la cual se invoca la primitiva.
*/
void eliminarLista(ListaPesoAcum &listaPA);


#endif // __LISTAPESOACUMULADO_H__
