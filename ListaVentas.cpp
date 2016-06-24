#include "ListaVentas.h"

//********************
void crearListaVenta(ListaVentas &listaV){
listaV.primeroListaVentas=finV();
}
//********************
bool listaVacia(ListaVentas &listaV){
return (primero(listaV)==finV());
}
//********************
PtrNodoListaVentas finV(){
return NULL;
}
//********************
PtrNodoListaVentas primero(ListaVentas &listaV){
return listaV.primeroListaVentas;
}
//********************
PtrNodoListaVentas siguiente(ListaVentas &listaV,PtrNodoListaVentas ptrNodoListaVent){
if ((! listaVacia(listaV)) && (ptrNodoListaVent != finV()))
    return ptrNodoListaVent->sgteV;
  else
    return finV();
    }
//********************
PtrNodoListaVentas anterior(ListaVentas &listaV,PtrNodoListaVentas ptrNodoListaVent){
  PtrNodoListaVentas ptrPrevio = finV();
  PtrNodoListaVentas ptrCursor = primero(listaV);

  while (( ptrCursor != finV()) && (ptrCursor != ptrNodoListaVent)) {
    ptrPrevio = ptrCursor;
    ptrCursor = siguiente(listaV,ptrCursor);
  }
  return ptrPrevio;
}
//********************
PtrNodoListaVentas ultimo(ListaVentas &listaV){
    return anterior(listaV,finV());
}
//********************
PtrNodoListaVentas crearNodoLista(Venta datoVenta){
 PtrNodoListaVentas ptrAux = new NodoListaVentas;

  ptrAux->datoVenta = datoVenta;
  ptrAux->sgteV = finV();

  return ptrAux;
}
//********************
PtrNodoListaVentas adicionarPrincipio(ListaVentas &listaV,Venta datoVenta){
  /* crea el nodo */
  PtrNodoListaVentas ptrNuevoNodo = crearNodoLista(datoVenta);

  /* lo incorpora al principio de la lista */
  ptrNuevoNodo->sgteV = listaV.primeroListaVentas;
  listaV.primeroListaVentas = ptrNuevoNodo;

  return ptrNuevoNodo;
}
//********************
PtrNodoListaVentas adicionarDespues(ListaVentas &listaV,Venta datoVenta, PtrNodoListaVentas ptrNodoListaVent){
PtrNodoListaVentas ptrNuevoNodo = finV();

  /* si la lista está vacia se adiciona la principio */
  if (listaVacia(listaV))
    ptrNuevoNodo = adicionarPrincipio(listaV,datoVenta);

  else {
    if (ptrNodoListaVent != finV()) {

      /* crea el nodo y lo intercala en la lista */
      ptrNuevoNodo = crearNodoLista(datoVenta);

      ptrNuevoNodo->sgteV = ptrNodoListaVent->sgteV;
      ptrNodoListaVent->sgteV = ptrNuevoNodo;
    }
  }
  return ptrNuevoNodo;
}
//********************
PtrNodoListaVentas adicionarFinal(ListaVentas &listaV,Venta datoVenta){
  return adicionarDespues(listaV,datoVenta,ultimo(listaV));
}
//********************
void colocarDato(ListaVentas &listaV,Venta &datoVenta,PtrNodoListaVentas ptrNodoListaVent){
if ( (! listaVacia(listaV)) && (ptrNodoListaVent != finV()))
    ptrNodoListaVent->datoVenta= datoVenta;
}
//********************
void obtenerDato(ListaVentas &listaV, Venta &datoVenta,PtrNodoListaVentas ptrNodoListaVent){
if ((! listaVacia(listaV)) && (ptrNodoListaVent != finV()))
    datoVenta = ptrNodoListaVent->datoVenta;
}
//********************
void eliminarNodo(ListaVentas &listaV, PtrNodoListaVentas ptrNodoListaVent){
PtrNodoListaVentas ptrPrevio;

  /* verifica que la lista no esté vacia y que nodo no sea fin*/
  if ((! listaVacia(listaV)) && (ptrNodoListaVent != finV())) {

    if (ptrNodoListaVent == primero(listaV))
      listaV.primeroListaVentas = siguiente(listaV,primero(listaV));

    else {
      ptrPrevio = anterior( listaV , ptrNodoListaVent );
      ptrPrevio->sgteV= ptrNodoListaVent->sgteV;
    }
    // Si el dato es un TDA, acá habría que llamar al destructor.
    destruirVentas(ptrNodoListaVent->datoVenta);
    delete ptrNodoListaVent;
  }
}
//********************
void eliminarNodoPrimero(ListaVentas &listaV){
  if (! listaVacia(listaV))
    eliminarNodo(listaV,primero(listaV));
}
//********************
void eliminarNodoUltimo(ListaVentas &listaV){
if (! listaVacia(listaV))
    eliminarNodo(listaV,ultimo(listaV));
}
//********************
void eliminarLista(ListaVentas &listaV){
  while (! listaVacia(listaV))
    eliminarNodo(listaV,primero(listaV));
}
