#ifndef __LISTAARTICULO_H__
#define __LISTAARTICULO_H__
#include "Articulo.h"

#ifndef NULL
#define NULL      0
#endif

//TIPO DE INFORMACION CONTENIDA EN LA ESTRUCTURA ARTICULO IDENTIFICADA COMO LART
typedef Articulo LArt;
//TIPO DE ESTRUCTURA DE LOS NODOS DE LA LISTA
struct NodoListaArt{
LArt datoLArt;
NodoListaArt *sgteArt;
};

// TIPO DE PUNTERO A LOS NODOS DE LA LISTA, EL CUAL SE USA PARA RECORRER LA LISTA Y ACCEDER A SUS DATOS
typedef NodoListaArt *PrtNodoListaArt;

// TIPO DE ESTRUCTURA DE LA LISTA
struct ListaArt{
PrtNodoListaArt primeroListaArt;
};


//DEFINICION DE PRIMITIVAS
//**********************************************************************************************
/* CREAR LISTA ART
*PRE-CONDICION:La lista no debe haber sido creada.
*POST-CONDICION:La lista queda creada y preparada para ser usada.
*listaA : estructura de datos a ser creado.
*/
void crearListaArt(ListaArt &listaA);
//***********************************************************************************************
/* LISTA VACIA
*PRE-CONDICION:Lista Creada con crearListaArt().
*POST-CONDICION: Devuelve true si lista esta vacia, sino devuelve false.
*listaA: lista sobre la cual se invoca la primitiva.
*/
bool listaVacia(ListaArt &listaA);
//***********************************************************************************************
/* FINA
*PRE-CONDICION: Lista Creada con crearListaArt().
*POST-CONDICION: Devuelve la representacion de lo Siguiente al último Nodo de la lista,
                 o sea el valor Null, que en esta implementacion representa el final de la lista.
*return representación del fin de la lista.
*/
PrtNodoListaArt finA();
//***********************************************************************************************
/* PRIMERO
*PRE-CONDICION: Lista Creada con crearListaArt().
*POST-CONDICION:Devuelve el puntero al primer elemento de la lista, o devuelve fin() si esta vacia
*listaA : lista sobre la cual se invoca la primitiva.
*return puntero al primer nodo.
*/
PrtNodoListaArt primero(ListaArt &listaA);
//***********************************************************************************************
/* SIGUIENTE
PRE-CONDICION: Lista Creada con crearListaArt().
POST-CONDICION:Devuelve el puntero al nodo proximo del apuntado, o devuelve fin() si
               ptrNodo apuntaba a fin() o si lista esta vacia.
*listaA : lista sobre la cual se invoca la primitiva.
*prtNodoListaArt : puntero al nodo a partir del cual se requiere el siguiente.
*return puntero al nodo siguiente.
*/
PrtNodoListaArt siguiente(ListaArt &listaA,PrtNodoListaArt ptrNodoListaArt);
//************************************************************************************************
/* ANTERIOR
*PRE-CONDICION:Lista Creada con crearListaArt().
               PtrNodoListaArt es un puntero a un nodo de lista.
*POST-CONDICION: devuelve el puntero al nodo anterior del apuntado, o devuelve fin() si
                ptrNodo apuntaba al primero o si lista esta vacia.
*listaA :Lista sobre la cual se invoca la primitiva.
*prtNodoListaArt : puntero al nodo a partir del cual se requiere el anterior.
*return puntero al nodo anterior.
*/
PrtNodoListaArt anterior(ListaArt  &listaA,PrtNodoListaArt ptrNodoListaArt);
//*************************************************************************************************
/* ULTIMO
*PRE-CONDICION: lista creada con crearListaArt().
*POST-CONDICION: devuelve el puntero al ultimo nodo de la lista, o devuelve fin() si ista esta vacia.
*listaA : lista sobre la cual se invoca la primitiva.
*return puntero al último nodo.
*/
PrtNodoListaArt ultimo(ListaArt &listaA);
//*************************************************************************************************
PrtNodoListaArt crearNodoLista(LArt datoArticulo);
//*************************************************************************************************
/* ADICIONAR AL PRINCIPIO
*PRE-CONDICION: lista creada con crearListaArt().
*POST-CONDICION: agrega un nodo nuevo al principio de la lista con el dato proporcionado
                y devuelve un puntero a ese elemento.
*listaA: lista sobre la cual se invoca la primitiva.
*datoArticulo: elemento a adicionar al principio de la lista.
*return puntero al nodo adicionado.
*/
PrtNodoListaArt adicionarPrincipio(ListaArt &listaA,LArt datoArticulo);
//*************************************************************************************************
/* ADICIONAR DESPUES
*PRE-CONDICION: lista creada con crearListaArt().
*POST-CONDICION: agrega un nodo despues del apuntado por ptrNodoListaArt con el dato proporcionado y devuelve
                un puntero apuntado al elemento insertado.
                Si la lista esta vacía agrega un nodo al principio de esta y devuelve un puntero al
                nodo insertado. Si ptrNodo apunta a fin() no inserta nada y devuelve fin().
*listaArt : lista sobre la cual se invoca la primitiva.
*datoArticulo: elemento a adicionar.
*ptrNodoListaArt: puntero al nodo después del cual se quiere adicionar el dato.
*return puntero al nodo adicionado.
*/
PrtNodoListaArt adicionarDespues(ListaArt &listaA,LArt datoArticulo, PrtNodoListaArt ptrNodoListaArt);
//***************************************************************************************************
/* ADICIONAR FINAL
*PRE-CONDICION: lista creada con crearListaArt().
*POST-CONDICION: agrega un nodo al final de la lista con el dato proporcionado y devuelve un puntero
                al nodo insertado.
*listaA: lista sobre la cual se invoca la primitiva.
*datoArticulo : elemento a adicionar al final de la lista.
*return puntero al nodo adicionado.
*/
PrtNodoListaArt adicionarFinal(ListaArt  &listaA, LArt datoArticulo);
//**************************************************************************************************
/* COLOCAR DATO
*PRE-CONDICION: lista creada con crearListaArt(), no vacia. ptrNodo es distinto de fin().
*POST-CONDICION: coloca el dato proporcionado en el nodo apuntado por ptrNodoListaArt.
*lista : lista sobre la cual se invoca la primitiva.
*dato : elemento a colocar.
*ptrNodoListaArt : puntero al nodo del cual se quiere colocar el dato.
*/
void colocarDato(ListaArt  &listaA,LArt &datoArticulo, PrtNodoListaArt ptrNodoListaArt);
//***************************************************************************************************
/* OBTENER DATO
*PRE-CONDICION: lista creada con crearListaArt(), no vacia. ptrNodo es distinto de fin().
*POST-CONDICION: devuelve el dato del nodo apuntado por ptrNodo.
*listaA: lista sobre la cual se invoca la primitiva.
*datoArticulo: elemento obtenido.
*ptrNodoListaArt : puntero al nodo del cual se quiere obtener el dato.
*/
void obtenerDato(ListaArt  &listaA,LArt &datoArticulo, PrtNodoListaArt ptrNodoListaArt);
//****************************************************************************************************
/* ELIMINAR NODO
*PRE-CONDICION: lista creada con crearListaArt().
*POST-CONDICION: elimina el nodo apuntado por ptrNodoListaArt. No realiza accion si la lista
                esta vacia o si ptrNodo apunta a fin().
*listaA: lista sobre la cual se invoca la primitiva.
*ptrNodoListaArt: puntero al nodo que se desea eliminar.
*/
void eliminarNodo(ListaArt  &listaA,PrtNodoListaArt ptrNodoListaArt);
//*****************************************************************************************************
/* ELIMINAR NODO PRIMERO
*PRE-CONDICION:Lista creada con crearListaArt().
*POST-CONDICION:Si la lista no esta vacia, elimina su nodo primero, sino no realiza accion alguna.
*listaA : lista sobre la cual se invoca la primitiva.
*/
void eliminarNodoPrimero(ListaArt  &listaA);
//*****************************************************************************************************
/* ELIMINAR NODO ULTIMO
*PRE-CONDICION: lista creada con crearListaArt().
*POST-CONDICION: si la lista no esta vacia elimina su nodo ultimo, sino no realiza accion.
*listaA : lista sobre la cual se invoca la primitiva.
*/
void eliminarNodoUltimo(ListaArt  &listaA);
//*****************************************************************************************************
/* ELIMINAR LISTA
*PRE-CONDICION:Lista creada con crearListaArt().
*POST-CONDICION: Elimina todos los Nodos de la lista quedando destruida e inhabilitada para su uso.
*listaA: lista sobre la cual se invoca la primitiva.
*/
void eliminarLista(ListaArt  &listaA);
//*****************************************************************************************************

#endif // __LISTAARTICULO_H__
