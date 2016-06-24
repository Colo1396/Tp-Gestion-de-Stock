#include "ListaPesoAcumulado.h"
//ListaPesoAcum &listaPA,PesoA datoPesoA, PtrNodoListaPA ptrNodoListaPA
#include "ListaArticulo.h"
//********************
void crearListaPesoAcum(ListaPesoAcum &listaPA){
listaPA.primerPesoAcum=finPA();
}
//********************
bool listaVacia(ListaPesoAcum &listaPA){
return (primero(listaPA)==finPA());
}
//********************
PtrNodoListaPA finPA(){
return NULL;
}
//********************
PtrNodoListaPA primero(ListaPesoAcum &listaPA){
return listaPA.primerPesoAcum;
}
//********************
PtrNodoListaPA siguiente(ListaPesoAcum &listaPA,PtrNodoListaPA ptrNodoListaPA){
if ((! listaVacia(listaPA)) && (ptrNodoListaPA != finPA()))
    return ptrNodoListaPA->sgtePA;
  else
    return finPA();
    }
//********************
PtrNodoListaPA anterior(ListaPesoAcum  &listaPA,PtrNodoListaPA  ptrNodoListaPA){
  PtrNodoListaPA ptrPrevio = finPA();
  PtrNodoListaPA ptrCursor = primero(listaPA);

  while (( ptrCursor != finPA()) && (ptrCursor != ptrNodoListaPA)) {
    ptrPrevio = ptrCursor;
    ptrCursor = siguiente(listaPA,ptrCursor);
  }
  return ptrPrevio;
}
//********************
PtrNodoListaPA ultimo(ListaPesoAcum &listaPA){
    return anterior(listaPA,finPA());
}
//********************
PtrNodoListaPA crearNodoLista(PesoA datoPesoA){
 PtrNodoListaPA ptrAux = new NodoListaPAcum;

  ptrAux->datoPesoA = datoPesoA;
  ptrAux->sgtePA = finPA();

  return ptrAux;
}
//********************
PtrNodoListaPA adicionarPrincipio(ListaPesoAcum &listaPA,PesoA datoPesoA){
  /* crea el nodo */
  PtrNodoListaPA ptrNuevoNodo = crearNodoLista(datoPesoA);

  /* lo incorpora al principio de la lista */
  ptrNuevoNodo->sgtePA = listaPA.primerPesoAcum;
  listaPA.primerPesoAcum = ptrNuevoNodo;

  return ptrNuevoNodo;
}
//********************
PtrNodoListaPA adicionarDespues(ListaPesoAcum &listaPA,PesoA datoPesoA, PtrNodoListaPA ptrNodoListaPA){
PtrNodoListaPA ptrNuevoNodo = finPA();

  /* si la lista está vacia se adiciona la principio */
  if (listaVacia(listaPA))
    ptrNuevoNodo = adicionarPrincipio(listaPA,datoPesoA);

  else {
    if (ptrNodoListaPA != finPA()) {

      /* crea el nodo y lo intercala en la lista */
      ptrNuevoNodo = crearNodoLista(datoPesoA);

      ptrNuevoNodo->sgtePA = ptrNodoListaPA->sgtePA;
      ptrNodoListaPA->sgtePA = ptrNuevoNodo;
    }
  }
  return ptrNuevoNodo;
}
//********************
PtrNodoListaPA adicionarFinal(ListaPesoAcum  &listaPA, PesoA datoPesoA){
  return adicionarDespues(listaPA,datoPesoA,ultimo(listaPA));
}
//********************
void colocarDato(ListaPesoAcum  &listaPA,PesoA &datoPesoA,PtrNodoListaPA ptrNodoListaPA){
if ( (! listaVacia(listaPA)) && (ptrNodoListaPA != finPA()))
    ptrNodoListaPA->datoPesoA = datoPesoA;
}
//********************
void obtenerDato(ListaPesoAcum  &listaPA, PesoA &datoPesoA,PtrNodoListaPA ptrNodoListaPA){
if ((! listaVacia(listaPA)) && (ptrNodoListaPA != finPA()))
    datoPesoA = ptrNodoListaPA->datoPesoA;
}
//********************
void eliminarNodo(ListaPesoAcum  &listaPA, PtrNodoListaPA ptrNodoListaPA){
PtrNodoListaPA ptrPrevio;

  /* verifica que la lista no esté vacia y que nodo no sea fin*/
  if ((! listaVacia(listaPA)) && (ptrNodoListaPA != finPA())) {

    if (ptrNodoListaPA == primero(listaPA))
      listaPA.primerPesoAcum = siguiente(listaPA,primero(listaPA));

    else {
      ptrPrevio = anterior( listaPA , ptrNodoListaPA );
      ptrPrevio->sgtePA= ptrNodoListaPA->sgtePA;
    }
    // Si el dato es un TDA, acá habría que llamar al destructor.
    destruirPesoAcum(ptrNodoListaPA->datoPesoA);
    delete ptrNodoListaPA;
  }
}
//********************
void eliminarNodoPrimero(ListaPesoAcum  &listaPA){
  if (! listaVacia(listaPA))
    eliminarNodo(listaPA,primero(listaPA));
}
//********************
void eliminarNodoUltimo(ListaPesoAcum  &listaPA){
if (! listaVacia(listaPA))
    eliminarNodo(listaPA,ultimo(listaPA));
}
//********************
void eliminarLista(ListaPesoAcum  &listaPA){
  while (! listaVacia(listaPA))
    eliminarNodo(listaPA,primero(listaPA));
}
