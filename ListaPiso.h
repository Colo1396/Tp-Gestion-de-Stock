#ifndef __LISTAPISO_H__
#define __LISTAPISO_H__
#ifndef NULL
#define NULL      0
#endif
#include "PilaArtUb.h"
/* Tipo de Informacion que esta contenida en los Nodos de la lista*/
typedef PilaArtUb PilUb;
/* Tipo de Estructura de los Nodos de la Lista. */
 struct NodoPiso{
 PilUb pilUb;// puntero a la pila
 NodoPiso *sgteP;//puntero al nodo siguente
 };
/* Tipo de Puntero a los Nodos de la Lista*/
 typedef NodoPiso *PtrNodoPiso;// puntero de la estructura nodo
/* Tipo de Estructura de la Lista */
 struct ListaPiso{
 PtrNodoPiso primeroPiso;//declaro el PtrNodoCalle como el tipo de la variable primero
 };

//*******************
/*
  pre : la lista no debe haber sido creada.
  post: lista queda creada y preparada para ser usada.
  listaP : estructura de datos a ser creado.
*/
void crearListaPiso(ListaPiso &listaP);
//********************
/*
  pre : lista Creada anteriormente.
  post: Devuelve true si lista esta vacia, sino devuelve false.
  listaP : lista sobre la cual se invoca la primitiva.
*/
bool listaVacia(ListaPiso &listaP);
//********************
/*
  pre : lista debe estar creada.
  post: devuelve la representacion de lo Siguiente al último Nodo de la lista,
        o sea el valor Null.
  return: representación del fin de la lista.
*/
PtrNodoPiso finP();
//********************
/*
  pre : lista debe haber sido creada
  post: devuelve el puntero al primer elemento de la lista, o devuelve fin() si
        esta vacia
  listaP : Lista sobre la cual se invoca la primitiva.
  return puntero al primer nodo.
*/
PtrNodoPiso primero(ListaPiso &listaP);
//********************
/*
  pre : lista debe estar creada.
  post: devuelve el puntero al nodo proximo del apuntado, o devuelve fin() si
        ptrNodo apuntaba a fin() o si lista esta vacia.
  listaP : lista sobre la cual se invoca la primitiva.
  prtNodoP : puntero al nodo a partir del cual se requiere el siguiente.
  return puntero al nodo siguiente.
*/
PtrNodoPiso siguiente(ListaPiso &listaP, PtrNodoPiso ptrNodoP);
//********************
/*
  pre : lista creada con anterioridad
  post: añade un dato a la pila
  piluB: dato que se añade a la pila.
  return crea un nodo en la lista.
*/
PtrNodoPiso crearNodoLista(PilUb pilUb);
//********************
/*
  pre : lista Creada anteriormente.
        ptrNodoP es un puntero a un nodo de lista.
  post: devuelve el puntero al nodo anterior del apuntado, o devuelve fin() si
        el punter apuntaba al primero o si lista esta vacia.
  listaP : lista sobre la cual se invoca la primitiva.
  prtNodoP : puntero al nodo a partir del cual se requiere el anterior.
  return puntero al nodo anterior.
*/
PtrNodoPiso anterior(ListaPiso &listaP, PtrNodoPiso ptrNodoP);
//********************
/*
  pre : lista creada con anterioridad
  post: devuelve el puntero al ultimo nodo de la lista, o devuelve fin() si
        si lista esta vacia.
  listaP : lista sobre la cual se invoca la primitiva.
  return puntero al último nodo.
*/
PtrNodoPiso ultimo(ListaPiso &listaP);
//********************
//********************
/*
  pre : lista creada
  post: agrega un nodo nuevo al principio de la lista con el dato proporcionado
        y devuelve un puntero a ese elemento.

  listaP: lista sobre la cual se invoca la primitiva.
  Pilub : elemento a adicionar al principio de la lista.
  return puntero al nodo adicionado.
*/
PtrNodoPiso adicionarPrincipio(ListaPiso &listaP, PilUb pilUb);
//********************
/*
  pre : lista creada
  post: agrega un nodo despues del apuntado por puntero con el dato
        proporcionado y devuelve un puntero apuntado al elemento insertado.
  listaP : lista sobre la cual se invoca la primitiva.
  Pilub : elemento a adicionar.
  ptrNodoP : puntero al nodo después del cual se quiere adicionar el dato.
  return puntero al nodo adicionado.
*/
PtrNodoPiso adicionarDespues(ListaPiso &listaP, PilUb pilUb, PtrNodoPiso ptrNodoP);
//********************
/*
  pre : lista creada
  post: agrega un nodo al final de la lista con el dato proporcionado y devuelve
        un puntero al nodo insertado.
  listaP : lista sobre la cual se invoca la primitiva.
  Pilub : elemento a adicionar al final de la lista.
  return puntero al nodo adicionado.
*/
PtrNodoPiso adicionarFinal(ListaPiso &listaP, PilUb pilUb);
/*
  pre : lista creada
  post: agrega un nodo antes en la lista con el dato proporcionado y devuelve
        un puntero al nodo insertado.
  listaP : lista sobre la cual se invoca la primitiva.
  Pilub : elemento a adicionar al final de la lista.
  ptrNodoP
  return puntero al nodo adicionado.
*/
PtrNodoPiso adicionarAntes(ListaPiso &listaP, PilUb pilUb, PtrNodoPiso ptrNodoP);
//********************
/*
  pre : lista creada, no vacia. puntero al nodo es distinto de fin().
  post: coloca el dato proporcionado en el nodo apuntado por ptrNodo.

  listaP : lista sobre la cual se invoca la primitiva.
  dpiluB : elemento a colocar.
  ptrNodoP : puntero al nodo del cual se quiere colocar el dato.
*/
void colocarDato(ListaPiso &listaP, PilUb &pilUb, PtrNodoPiso ptrNodoP);
//********************
/*
  pre : lista creada ,no vacia. puntero al nodo es distinto de fin().
  post: devuelve el dato del nodo apuntado por ptrNodo.

  listaF : lista sobre la cual se invoca la primitiva.
  datoF: elemento obtenido.
  ptrNodoFaltante : puntero al nodo del cual se quiere obtener el dato.
*/
void obtenerDato(ListaPiso &listaP, PilUb &pilUb, PtrNodoPiso ptrNodoP);
//********************
/*
  pre : lista creada
  post: elimina el nodo apuntado por el puntero. No realiza accion si la lista
        esta vacia o si puntero apunta a fin().

  listaP : lista sobre la cual se invoca la primitiva.
  ptrNodoP : puntero al nodo que se desea eliminar.
*/
void eliminarNodo(ListaPiso &listaP, PtrNodoPiso ptrNodoP);
//********************
/*
  pre : lista creada
  post: si la lista no esta vacia, elimina su nodo primero, sino no realiza
        accion alguna.
listaP : lista sobre la cual se invoca la primitiva.
*/
void eliminarNodoPrimero(ListaPiso &listaP);
//********************
/*
  pre : lista creada.
  post: si la lista no esta vacia elimina su nodo ultimo,
        sino no realiza accion.
  listaP : lista sobre la cual se invoca la primitiva.
*/
void eliminarNodoUltimo(ListaPiso &listaP);
//********************
/*
  pre : lista creada
  post: elimina todos los Nodos de la lista quedando destruida.
  listaP : lista sobre la cual se invoca la primitiva.
*/
void eliminarLista(ListaPiso &listaP);
//********************
/*
  pre : lista creada ,no vacia. puntero al nodo es distinto de fin().
  post: Localiza el dato y devuelve un puntero apuntando a ese dato

  listap : lista sobre la cual se invoca la primitiva.
  pilUb: elemento a localizar
*/
PtrNodoPiso localizarDato(ListaPiso &listaP , PilUb pilUb);
//********************
/*
  pre : lista creada ,no vacia. puntero al nodo es distinto de fin().
  post: inserta el dato y devuelve un puntero apuntando a ese dato

  listap : lista sobre la cual se invoca la primitiva.
  pilUb: elemento a localizar
*/
PtrNodoPiso insertarDato(ListaPiso &listaP, PilUb pilUb);
//********************
/*
  pre : lista creada ,no vacia. puntero al nodo es distinto de fin().
  post: elimina el dato

  listap : lista sobre la cual se invoca la primitiva.
  pilUb: elemento a eliminar
*/
void eliminarDato(ListaPiso &listaP, PilUb pilUb);
//********************
/*
  pre : lista creada ,no vacia. puntero al nodo es distinto de fin().
  post: reordena la lista
  listap : lista sobre la cual se invoca la primitiva.
*/
void reordenar(ListaPiso &listaP);
//********************
/*
  pre : lista creada ,no vacia. puntero al nodo es distinto de fin().
  post: obtiene la longitud de la lista.
  listap : lista sobre la cual se invoca la primitiva.
*/
int longitud(ListaPiso &listaP);


#endif // __LISTAPISO_H__
