#ifndef __LISTACALLE_H__
#define __LISTACALLE_H__
#ifndef NULL
#define NULL      0
#endif
#include "ListaPiso.h"

//TIPO DE INFORMACION CONTENIDA EN LA ESTRUCTURA LISTAPISO IDENTIFICADA COMO LISTPISO
typedef ListaPiso ListPiso;

//TIPO DE ESTRUCTURA DE LOS NODOS DE LA LISTA
 struct NodoCalle{
 ListPiso listPiso ;// puntero al piso
 NodoCalle *sgteC;//puntero al nodo siguente
 };

// TIPO DE PUNTERO A LOS NODOS DE LA LISTA, EL CUAL SE USA PARA RECORRER LA LISTA Y ACCEDER A SUS DATOS
 typedef NodoCalle *PtrNodoCalle;// puntero de la estructura nodo

// TIPO DE ESTRUCTURA DE LA LISTA
 struct ListaCalle{
 PtrNodoCalle primeroCalle;//declaro el PtrNodoCalle como el tipo de la variable primero
 };


//DEFINICION DE PRIMITIVAS
//**********************************************************************************************
/* CREAR LISTA CALLE
*PRE-CONDICION:La lista no debe haber sido creada.
*POST-CONDICION:La lista queda creada y preparada para ser usada.
*listaC : estructura de datos a ser creado.
*/
void crearListaCalle(ListaCalle &listaC);
//***********************************************************************************************
/* LISTA VACIA
*PRE-CONDICION:Lista Creada con crearListaCalle().
*POST-CONDICION: Devuelve true si lista esta vacia, sino devuelve false.
*listaC: lista sobre la cual se invoca la primitiva.
*/
bool listaVacia(ListaCalle &listaC);
//***********************************************************************************************
/* FINC
*PRE-CONDICION: Lista Creada con crearListaCalle().
*POST-CONDICION: Devuelve la representacion de lo Siguiente al último Nodo de la lista,
                 o sea el valor Null, que en esta implementacion representa el final de la lista.
*return representación del fin de la lista.
*/
PtrNodoCalle finC();
//***********************************************************************************************
/* PRIMERO
*PRE-CONDICION: Lista Creada con crearListaCalle().
*POST-CONDICION:Devuelve el puntero al primer elemento de la lista, o devuelve fin() si esta vacia
*listaC : lista sobre la cual se invoca la primitiva.
*return puntero al primer nodo.
*/
PtrNodoCalle primero(ListaCalle &listaC);
//***********************************************************************************************
/* SIGUIENTE
PRE-CONDICION: Lista Creada con crearListaCalle().
POST-CONDICION:Devuelve el puntero al nodo proximo del apuntado, o devuelve fin() si
               ptrNodoCalle apuntaba a fin() o si lista esta vacia.
*listaC : lista sobre la cual se invoca la primitiva.
*prtNodoCalle : puntero al nodo a partir del cual se requiere el siguiente.
*return puntero al nodo siguiente.
*/
PtrNodoCalle siguiente(ListaCalle &listaC,PtrNodoCalle ptrNodoCalle);
//************************************************************************************************
/* ANTERIOR
*PRE-CONDICION:Lista Creada con crearListaCalle().
               PtrNodoCalle es un puntero a un nodo de lista.
*POST-CONDICION: devuelve el puntero al nodo anterior del apuntado, o devuelve fin() si
                ptrNodo apuntaba al primero o si lista esta vacia.
*listaC :Lista sobre la cual se invoca la primitiva.
*prtNodoCalle : puntero al nodo a partir del cual se requiere el anterior.
*return puntero al nodo anterior.
*/
PtrNodoCalle anterior(ListaCalle &listaC, PtrNodoCalle ptrNodoC);
//*************************************************************************************************
/* ULTIMO
*PRE-CONDICION: lista creada con crearListaCalle().
*POST-CONDICION: devuelve el puntero al ultimo nodo de la lista, o devuelve fin() si ista esta vacia.
*listaC : lista sobre la cual se invoca la primitiva.
*return puntero al último nodo.
*/
PtrNodoCalle ultimo(ListaCalle &listaC);
//*************************************************************************************************
PtrNodoCalle crearNodoLista(ListPiso listPiso);
//*************************************************************************************************
/* ADICIONAR AL PRINCIPIO
*PRE-CONDICION: lista creada con crearListaCalle().
*POST-CONDICION: agrega un nodo nuevo al principio de la lista con el dato proporcionado
                y devuelve un puntero a ese elemento.
*listaC: lista sobre la cual se invoca la primitiva.
*listPiso: elemento a adicionar al principio de la lista.
*return puntero al nodo adicionado.
*/
PtrNodoCalle adicionarPrincipio(ListaCalle &listaC, ListPiso listPiso);
//*************************************************************************************************
/* ADICIONAR DESPUES
*PRE-CONDICION: lista creada con crearListaCalle().
*POST-CONDICION: agrega un nodo despues del apuntado por ptrNodoListaArt con el dato proporcionado y devuelve
                un puntero apuntado al elemento insertado.
                Si la lista esta vacía agrega un nodo al principio de esta y devuelve un puntero al
                nodo insertado. Si ptrNodo apunta a fin() no inserta nada y devuelve fin().
*listaC : lista sobre la cual se invoca la primitiva.
*listPiso: elemento a adicionar.
*ptrNodoCalle: puntero al nodo después del cual se quiere adicionar el dato.
*return puntero al nodo adicionado.
*/
PtrNodoCalle adicionarDespues(ListaCalle &listaC, ListPiso listPiso, PtrNodoCalle ptrNodoC);
//***************************************************************************************************
/* ADICIONAR FINAL
*PRE-CONDICION: lista creada con crearListaCalle().
*POST-CONDICION: agrega un nodo al final de la lista con el dato proporcionado y devuelve un puntero
                al nodo insertado.
*listaC: lista sobre la cual se invoca la primitiva.
*listPiso: elemento a adicionar al final de la lista.
*return puntero al nodo adicionado.
*/
PtrNodoCalle adicionarFinal(ListaCalle &listaC,ListPiso listPiso);
//**************************************************************************************************
/* ADICIONAR ANTES
*PRE-CONDICION: lista creada con crearListaCalle().
*POST-CONDICION: agrega un nodo con el dato proporcionado antes del apuntado por ptrNodo y devuelve
                un puntero al nodo insertado. Si la lista esta vacia no inserta nada y devuelve fin().
                Si ptrNodoCalle apunta al primero, el nodo insertado sera el nuevo primero.
*listaC : lista sobre la cual se invoca la primitiva.
*listPiso: elemento a adicionar.
*PtrNodoCalle: puntero al nodo antes del cual se quiere adicionar el dato.
return puntero al nodo adicionado.
*/
PtrNodoCalle adicionarAntes(ListaCalle &listaC, ListPiso listPiso, PtrNodoCalle ptrNodoC);
//**************************************************************************************************
/* COLOCAR DATO
*PRE-CONDICION: lista creada con crearListaCalle(), no vacia. ptrNodoCalle es distinto de fin().
*POST-CONDICION: coloca el dato proporcionado en el nodo apuntado por ptrNodoCalle.
*listaC: lista sobre la cual se invoca la primitiva.
*listPiso: elemento a colocar.
*ptrNodoCalle : puntero al nodo del cual se quiere colocar el dato.
*/
void colocarDato(ListaCalle &listaC,ListPiso listPiso, PtrNodoCalle ptrNodoC);
//***************************************************************************************************
/* OBTENER DATO
*PRE-CONDICION: lista creada con crearListaCalle(), no vacia. ptrNodo es distinto de fin().
*POST-CONDICION: devuelve el dato del nodo apuntado por ptrNodoCalle.
*listaC: lista sobre la cual se invoca la primitiva.
*listPiso: elemento obtenido.
*ptrNodoCalle : puntero al nodo del cual se quiere obtener el dato.
*/
void obtenerDato(ListaCalle &listaC, ListPiso listPiso, PtrNodoCalle ptrNodoC);
//****************************************************************************************************
/* ELIMINAR NODO
*PRE-CONDICION: lista creada con crearListaCalle().
*POST-CONDICION: elimina el nodo apuntado por ptrNodoCalle. No realiza accion si la lista
                esta vacia o si ptrNodo apunta a fin().
*listaC: lista sobre la cual se invoca la primitiva.
*ptrNodoCalle: puntero al nodo que se desea eliminar.
*/
void eliminarNodo(ListaCalle &listaC, PtrNodoCalle ptrNodoC);
//*****************************************************************************************************
/* ELIMINAR NODO PRIMERO
*PRE-CONDICION:Lista creada con crearListaCalle().
*POST-CONDICION:Si la lista no esta vacia, elimina su nodo primero, sino no realiza accion alguna.
*listaC : lista sobre la cual se invoca la primitiva.
*/
void eliminarNodoPrimero(ListaCalle &listaC);
//*****************************************************************************************************
/* ELIMINAR NODO ULTIMO
*PRE-CONDICION: lista creada con crearListaCalle().
*POST-CONDICION: si la lista no esta vacia elimina su nodo ultimo, sino no realiza accion.
*listaC : lista sobre la cual se invoca la primitiva.
*/
void eliminarNodoUltimo(ListaCalle &listaC);
//*****************************************************************************************************
/* ELIMINAR LISTA
*PRE-CONDICION:Lista creada con crearListaCalle().
*POST-CONDICION: Elimina todos los Nodos de la lista quedando destruida e inhabilitada para su uso.
*listaC: lista sobre la cual se invoca la primitiva.
*/
void eliminarLista(ListaCalle &listaC);
//*****************************************************************************************************
//DEFINICION DE OPERACIONES ADICIONALES

/* LOCALIZAR DATO
*PRE-CONDICION: lista fue creada con crearListaCalle().
*POST-CONDICION: si el dato se encuentra en la lista, devuelve el puntero al primer nodo que lo contiene.
                 Si el dato no se encuentra en la lista devuelve fin().
*listaC : lista sobre la cual se invoca la primitiva.
*listPiso: elemento a localizar.
return puntero al nodo localizado o fin().
*/
PtrNodoCalle localizarDato(ListaCalle &listaC , ListPiso listPiso);
//*****************************************************************************************************
/* INSERTAR DATO
*PRE-CONDICION: lista fue creada con crearListaCalle() y cargada con datos ordenados de menor a mayor
                respecto del sentido progresivo.
*POST-CONDICION: agrega a la lista el dato manteniendo el orden pero con multiples valores iguales y
                devuelve un puntero al nodo insertado.
*listaC : lista sobre la cual se invoca la primitiva.
*listPiso: elemento a insertar.
*return puntero al nodo insertado.
*/
PtrNodoCalle insertarDato(ListaCalle &listaC, ListPiso listPiso);
//*****************************************************************************************************
/* ELIMINAR DATO
*PRE-CONDICION: la lista fue creada con crearListaCalle().
*POST-CONDICION: elimina el dato de la lista, si el mismo se encuentra.
*listaC: lista sobre la cual se invoca la primitiva.
*listPiso: elemento a eliminar.
*/
void eliminarDato(ListaCalle &listaC, ListPiso listPiso);
//*****************************************************************************************************
/* REORDENAR
*PRE-CONDICION: la lista fue creada con crearListaCalle().
*POST-CONDICION: reordena la lista.
*listaC : lista sobre la cual se invoca la primitiva.
*/
void reordenar(ListaCalle &listaC);
//*****************************************************************************************************
/*
*PRE-CONDICION: la lista fue creada con crearListaCalle().
*POST-CONDICION: devuelve la cantidad de datos que tiene la lista.
*listaC: lista sobre la cual se invoca la primitiva.
*/
int longitud(ListaCalle &listaC);
//*****************************************************************************************************

#endif // __LISTACALLE_H__

