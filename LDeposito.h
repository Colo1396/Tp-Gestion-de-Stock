#ifndef __LDEPOSITO_H__
#define __LDEPOSITO_H__
#include "ArtDeposito.h"
#ifndef NULL
#define NULL      0
#endif

//TIPO DE INFORMACION CONTENIDA EN LA ESTRUCTURA ARTDEPOSITO IDENTIFICADA COMO ARTDEP
typedef ArtDeposito ArtDep;

//TIPO DE ESTRUCTURA DE LOS NODOS DE LA LISTA
struct NodoListaDeposito{
ArtDep datoArtDep;
NodoListaDeposito *sgteAD;
};

// TIPO DE PUNTERO A LOS NODOS DE LA LISTA, EL CUAL SE USA PARA RECORRER LA LISTA Y ACCEDER A SUS DATOS
typedef NodoListaDeposito *PtrNodoListaDeposito;

// TIPO DE ESTRUCTURA DE LA LISTA
struct ListaArtDeposito{
    PtrNodoListaDeposito primerArtDeposito;
};

//DEFINICION DE PRIMITIVAS
//**********************************************************************************************
/* CREAR LISTA
*PRE-CONDICION:La lista no debe haber sido creada.
*POST-CONDICION:La lista queda creada y preparada para ser usada.
*listaArtDep : estructura de datos a ser creado.
*/
void crearListaArtDeposito(ListaArtDeposito &listaArtDep);
//***********************************************************************************************
/* LISTA VACIA
*PRE-CONDICION:Lista Creada con crearListaArtDeposito().
*POST-CONDICION: Devuelve true si lista esta vacia, sino devuelve false.
*listaArtDep: lista sobre la cual se invoca la primitiva.
*/
bool listaVacia(ListaArtDeposito &listaArtDep);
//***********************************************************************************************
/* FINAD
*PRE-CONDICION: Lista Creada con crearListaArtDeposito().
*POST-CONDICION: Devuelve la representacion de lo Siguiente al último Nodo de la lista,
                 o sea el valor Null, que en esta implementacion representa el final de la lista.
*return representación del fin de la lista.
*/
PtrNodoListaDeposito finAD();
//***********************************************************************************************
/* PRIMERO
*PRE-CONDICION: Lista Creada con crearListaArtDeposito().
*POST-CONDICION:Devuelve el puntero al primer elemento de la lista, o devuelve fin() si esta vacia
*listaArtDep : lista sobre la cual se invoca la primitiva.
*return puntero al primer nodo.
*/
PtrNodoListaDeposito primero(ListaArtDeposito &listaArtDep);
//***********************************************************************************************
/* SIGUIENTE
PRE-CONDICION: Lista Creada con crearListaArtDep().
POST-CONDICION:Devuelve el puntero al nodo proximo del apuntado, o devuelve fin() si
               ptrNodo apuntaba a fin() o si lista esta vacia.
*lista : lista sobre la cual se invoca la primitiva.
*prtNodoListaDep : puntero al nodo a partir del cual se requiere el siguiente.
*return puntero al nodo siguiente.
*/
PtrNodoListaDeposito siguiente(ListaArtDeposito &listaArtDep,PtrNodoListaDeposito ptrNodoListaDep);
//************************************************************************************************
/* ANTERIOR
*PRE-CONDICION:Lista Creada con crearListaArtDep().
               PtrNodoListaDep es un puntero a un nodo de lista.
*POST-CONDICION: devuelve el puntero al nodo anterior del apuntado, o devuelve fin() si
                ptrNodo apuntaba al primero o si lista esta vacia.
*listaArtDep :Lista sobre la cual se invoca la primitiva.
*prtNodoListaDep : puntero al nodo a partir del cual se requiere el anterior.
*return puntero al nodo anterior.
*/
PtrNodoListaDeposito anterior(ListaArtDeposito &listaArtDep,PtrNodoListaDeposito ptrNodoListaDep);
//*************************************************************************************************
/* ULTIMO
*PRE-CONDICION: lista creada con crearListaArtDep().
*POST-CONDICION: devuelve el puntero al ultimo nodo de la lista, o devuelve fin() si ista esta vacia.
*listaArtDep : lista sobre la cual se invoca la primitiva.
*return puntero al último nodo.
*/
PtrNodoListaDeposito ultimo(ListaArtDeposito &listaArtDep);
//*************************************************************************************************

PtrNodoListaDeposito crearNodoLista(ArtDep datoArtDep);
//*************************************************************************************************
/* ADICIONAR AL PRINCIPIO
*PRE-CONDICION: lista creada con crearListaArtDep().
*POST-CONDICION: agrega un nodo nuevo al principio de la lista con el dato proporcionado
                y devuelve un puntero a ese elemento.
*listaArtDep: lista sobre la cual se invoca la primitiva.
*datoArtDep: elemento a adicionar al principio de la lista.
*return puntero al nodo adicionado.
*/
PtrNodoListaDeposito adicionarPrincipio(ListaArtDeposito &listaArtDep,ArtDep datoArtDep);
//*************************************************************************************************
/* ADICIONAR DESPUES
*PRE-CONDICION: lista creada con crearListaArtDep().
*POST-CONDICION: agrega un nodo despues del apuntado por ptrNodo con el dato proporcionado y devuelve
                un puntero apuntado al elemento insertado.
                Si la lista esta vacía agrega un nodo al principio de esta y devuelve un puntero al
                nodo insertado. Si ptrNodo apunta a fin() no inserta nada y devuelve fin().
*listaArtDep : lista sobre la cual se invoca la primitiva.
*datoArtDep: elemento a adicionar.
*ptrNodoListaDep: puntero al nodo después del cual se quiere adicionar el dato.
*return puntero al nodo adicionado.
*/
PtrNodoListaDeposito adicionarDespues(ListaArtDeposito &listaArtDep,ArtDep datoArtDep, PtrNodoListaDeposito ptrNodoListaDep);
//***************************************************************************************************
/* ADICIONAR FINAL
*PRE-CONDICION: lista creada con crearListaArtDep().
*POST-CONDICION: agrega un nodo al final de la lista con el dato proporcionado y devuelve un puntero
                al nodo insertado.
*listaArtDep : lista sobre la cual se invoca la primitiva.
*datoArtDep : elemento a adicionar al final de la lista.
*return puntero al nodo adicionado.
*/
PtrNodoListaDeposito adicionarFinal(ListaArtDeposito &listaArtDep, ArtDep datoArtDep);
//**************************************************************************************************
/* COLOCAR DATO
*PRE-CONDICION: lista creada con crearListaArtDep(), no vacia. ptrNodo es distinto de fin().
*POST-CONDICION: coloca el dato proporcionado en el nodo apuntado por ptrNodo.
*lista : lista sobre la cual se invoca la primitiva.
*dato : elemento a colocar.
*ptrNodo : puntero al nodo del cual se quiere colocar el dato.
*/
void colocarDato(ListaArtDeposito &listaArtDep,ArtDep &datoArtDep, PtrNodoListaDeposito ptrNodoListaDep);
//***************************************************************************************************
/* OBTENER DATO
*PRE-CONDICION: lista creada con crearListaArtDep(), no vacia. ptrNodo es distinto de fin().
*POST-CONDICION: devuelve el dato del nodo apuntado por ptrNodo.
*listaArtDep: lista sobre la cual se invoca la primitiva.
*datoArtDep: elemento obtenido.
*ptrNodoListaDep : puntero al nodo del cual se quiere obtener el dato.
*/
void obtenerDato(ListaArtDeposito &listaArtDep,ArtDep &datoArtDep, PtrNodoListaDeposito ptrNodoListaDep);
//****************************************************************************************************
/* ELIMINAR NODO
*PRE-CONDICION: lista creada con crearListaArtDep().
*POST-CONDICION: elimina el nodo apuntado por ptrNodo. No realiza accion si la lista
                esta vacia o si ptrNodo apunta a fin().
*listaArtDep: lista sobre la cual se invoca la primitiva.
*ptrNodoListaDep: puntero al nodo que se desea eliminar.
*/
void eliminarNodo(ListaArtDeposito &listaArtDep,PtrNodoListaDeposito ptrNodoListaDep);
//*****************************************************************************************************
/* ELIMINAR NODO PRIMERO
*PRE-CONDICION:Lista creada con crearListaArtDep().
*POST-CONDICION:Si la lista no esta vacia, elimina su nodo primero, sino no realiza accion alguna.
*listaArtDep : lista sobre la cual se invoca la primitiva.
*/
void eliminarNodoPrimero(ListaArtDeposito &listaArtDep);
//*****************************************************************************************************
/* ELIMINAR NODO ULTIMO
*PRE-CONDICION: lista creada con crearListaArtDep().
*POST-CONDICION: si la lista no esta vacia elimina su nodo ultimo, sino no realiza accion.
*listaArtDep : lista sobre la cual se invoca la primitiva.
*/
void eliminarNodoUltimo(ListaArtDeposito &listaArtDep);
//*****************************************************************************************************
/* ELIMINAR LISTA
*PRE-CONDICION:Lista creada con crearListaArtDep().
*POST-CONDICION: Elimina todos los Nodos de la lista quedando destruida e inhabilitada para su uso.
*listaArtDep: lista sobre la cual se invoca la primitiva.
*/
void eliminarLista(ListaArtDeposito &listaArtDep);
//******************************************************************************************************

#endif // __LDEPOSITO_H__
