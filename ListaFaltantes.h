#ifndef __LISTAFALTANTES_H__
#define __LISTAFALTANTES_H__
#include "Faltantes.h"
#ifndef NULL
#define NULL      0
#endif
/* Tipo de Informacion que esta contenida en los Nodos de la lista*/
typedef Faltantes Faltante;
/* Tipo de Estructura de los Nodos de la Lista. */
struct NodoFaltante{
Faltante datoFaltante;
NodoFaltante *sgteF;
};
/* Tipo de Puntero a los Nodos de la Lista*/
typedef NodoFaltante *PtrNodoFaltante;
/* Tipo de Estructura de la Lista */
struct ListaFaltante{
PtrNodoFaltante primerFaltante;
};
//********************
/*
  pre : la lista no debe haber sido creada.
  post: lista queda creada y preparada para ser usada.
  listaF : estructura de datos a ser creado.
*/
void crearListaFaltante(ListaFaltante &listaF);
//********************
/*
  pre : lista Creada anteriormente.
  post: Devuelve true si lista esta vacia, sino devuelve false.
  listaF : lista sobre la cual se invoca la primitiva.
*/
bool listaVacia(ListaFaltante &listaF);
//********************
/*
  pre : lista debe estar creada.
  post: devuelve la representacion de lo Siguiente al último Nodo de la lista,
        o sea el valor Null.
  return: representación del fin de la lista.
*/
PtrNodoFaltante finF();
//********************
/*
  pre : lista debe haber sido creada
  post: devuelve el puntero al primer elemento de la lista, o devuelve fin() si
        esta vacia
  listaF : Lista sobre la cual se invoca la primitiva.
  return puntero al primer nodo.
*/
PtrNodoFaltante primero(ListaFaltante &listaF);
//********************
/*
  pre : lista debe estar creada.
  post: devuelve el puntero al nodo proximo del apuntado, o devuelve fin() si
        ptrNodo apuntaba a fin() o si lista esta vacia.
  listaF : lista sobre la cual se invoca la primitiva.
  prtNodoFaltante : puntero al nodo a partir del cual se requiere el siguiente.
  return puntero al nodo siguiente.
*/
PtrNodoFaltante siguiente(ListaFaltante &listaF,PtrNodoFaltante ptrNodoFaltante);
//********************
/*
  pre : lista Creada anteriormente.
        ptrNodoFaltante es un puntero a un nodo de lista.
  post: devuelve el puntero al nodo anterior del apuntado, o devuelve fin() si
        el punter apuntaba al primero o si lista esta vacia.
  listaF : lista sobre la cual se invoca la primitiva.
  prtNodoFaltante : puntero al nodo a partir del cual se requiere el anterior.
  return puntero al nodo anterior.
*/
PtrNodoFaltante anterior(ListaFaltante &listaF,PtrNodoFaltante ptrNodoFaltante);
//********************
/*
  pre : lista creada con anterioridad
  post: devuelve el puntero al ultimo nodo de la lista, o devuelve fin() si
        si lista esta vacia.
  listaF : lista sobre la cual se invoca la primitiva.
  return puntero al último nodo.
*/
PtrNodoFaltante ultimo(ListaFaltante &listaF);
//********************
/*
  pre : lista creada con anterioridad
  post: devuelve el puntero al ultimo nodo de la lista, o devuelve fin() si
        si lista esta vacia.
  datoFaltante : dato faltante ya viene creado de antes.
  return crea un nodo en la lista.
*/
PtrNodoFaltante crearNodoLista(Faltante datoFaltante);
//********************
/*
  pre : lista creada
  post: agrega un nodo nuevo al principio de la lista con el dato proporcionado
        y devuelve un puntero a ese elemento.

  listaF : lista sobre la cual se invoca la primitiva.
  datFaltanteo : elemento a adicionar al principio de la lista.
  return puntero al nodo adicionado.
*/
PtrNodoFaltante adicionarPrincipio(ListaFaltante &listaF,Faltante datoFaltante);
//********************
/*
  pre : lista creada
  post: agrega un nodo despues del apuntado por puntero con el dato
        proporcionado y devuelve un puntero apuntado al elemento insertado.
  listaF : lista sobre la cual se invoca la primitiva.
  datoFaltante : elemento a adicionar.
  ptrNodoFaltante : puntero al nodo después del cual se quiere adicionar el dato.
  return puntero al nodo adicionado.
*/
PtrNodoFaltante adicionarDespues(ListaFaltante &listaF,Faltante datoFaltante, PtrNodoFaltante ptrNodoFaltante);
//********************
/*
  pre : lista creada
  post: agrega un nodo al final de la lista con el dato proporcionado y devuelve
        un puntero al nodo insertado.
  listaf : lista sobre la cual se invoca la primitiva.
  datoFaltante : elemento a adicionar al final de la lista.
  return puntero al nodo adicionado.
*/
PtrNodoFaltante adicionarFinal(ListaFaltante &listaF, Faltante datoFaltante);
//********************
/*
  pre : lista creada, no vacia. puntero al nodo es distinto de fin().
  post: coloca el dato proporcionado en el nodo apuntado por ptrNodo.

  listaF : lista sobre la cual se invoca la primitiva.
  datoFaltante : elemento a colocar.
  ptrNodo : puntero al nodo del cual se quiere colocar el dato.
*/
void colocarDato(ListaFaltante &listaF,Faltante &datoFaltante, PtrNodoFaltante ptrNodoFaltante);
//********************
/*
  pre : lista creada ,no vacia. puntero al nodo es distinto de fin().
  post: devuelve el dato del nodo apuntado por ptrNodo.

  listaF : lista sobre la cual se invoca la primitiva.
  datoF: elemento obtenido.
  ptrNodoFaltante : puntero al nodo del cual se quiere obtener el dato.
*/
void obtenerDato(ListaFaltante &listaF,Faltante &datoFaltante, PtrNodoFaltante ptrNodoFaltante);
//********************
/*
  pre : lista creada
  post: elimina el nodo apuntado por el puntero. No realiza accion si la lista
        esta vacia o si puntero apunta a fin().

  listaF : lista sobre la cual se invoca la primitiva.
  ptrNodoFaltante : puntero al nodo que se desea eliminar.
*/
void eliminarNodo(ListaFaltante &listaF,PtrNodoFaltante ptrNodoFaltante);
//********************
/*
  pre : lista creada
  post: si la lista no esta vacia, elimina su nodo primero, sino no realiza
        accion alguna.
listaF : lista sobre la cual se invoca la primitiva.
*/
void eliminarNodoPrimero(ListaFaltante &listaF);
//********************
/*
  pre : lista creada.
  post: si la lista no esta vacia elimina su nodo ultimo,
        sino no realiza accion.
  listaF : lista sobre la cual se invoca la primitiva.
*/
void eliminarNodoUltimo(ListaFaltante &listaF);
//********************
/*
  pre : lista creada
  post: elimina todos los Nodos de la lista quedando destruida.
  listaF : lista sobre la cual se invoca la primitiva.
*/
void eliminarLista(ListaFaltante &listaF);


#endif // __LISTAFALTANTES_H__
