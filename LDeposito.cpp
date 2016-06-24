#include "LDeposito.h"
//********************
void crearListaArtDeposito(ListaArtDeposito &listaArtDep){
listaArtDep.primerArtDeposito=finAD();
}
//********************
bool listaVacia(ListaArtDeposito &listaArtDep){
return (primero(listaArtDep)==finAD());
}
//********************
PtrNodoListaDeposito finAD(){
return NULL;
}
//********************
PtrNodoListaDeposito primero(ListaArtDeposito &listaArtDep){
return  listaArtDep.primerArtDeposito;
}
//********************
PtrNodoListaDeposito siguiente(ListaArtDeposito &listaArtDep,PtrNodoListaDeposito ptrNodoListaDep){
if ((! listaVacia(listaArtDep)) && (ptrNodoListaDep != finAD()))
    return ptrNodoListaDep->sgteAD;
  else
    return finAD();
}
//********************
PtrNodoListaDeposito anterior(ListaArtDeposito &listaArtDep,PtrNodoListaDeposito ptrNodoListaDep){
 PtrNodoListaDeposito ptrPrevio = finAD();
  PtrNodoListaDeposito ptrCursor = primero(listaArtDep);

  while (( ptrCursor != finAD()) && (ptrCursor != ptrNodoListaDep)) {
    ptrPrevio = ptrCursor;
    ptrCursor = siguiente(listaArtDep,ptrCursor);
  }
  return ptrPrevio;
}
//********************
PtrNodoListaDeposito ultimo(ListaArtDeposito &listaArtDep){
 return anterior(listaArtDep,finAD());
}
//********************
PtrNodoListaDeposito crearNodoLista(ArtDep datoArtDep){
PtrNodoListaDeposito ptrAux = new NodoListaDeposito;

  ptrAux->datoArtDep = datoArtDep;
  ptrAux->sgteAD = finAD();

  return ptrAux;
}
//********************
PtrNodoListaDeposito adicionarPrincipio(ListaArtDeposito &listaArtDep,ArtDep datoArtDep){
 /* crea el nodo */
  PtrNodoListaDeposito ptrNuevoNodo = crearNodoLista(datoArtDep);

  /* lo incorpora al principio de la lista */
  ptrNuevoNodo->sgteAD = listaArtDep.primerArtDeposito;
  listaArtDep.primerArtDeposito = ptrNuevoNodo;

  return ptrNuevoNodo;
}
//********************
PtrNodoListaDeposito adicionarDespues(ListaArtDeposito &listaArtDep,ArtDep datoArtDep, PtrNodoListaDeposito ptrNodoListaDep){
PtrNodoListaDeposito ptrNuevoNodo = finAD();

  /* si la lista está vacia se adiciona la principio */
  if (listaVacia(listaArtDep))
    ptrNuevoNodo = adicionarPrincipio(listaArtDep,datoArtDep);

  else {
    if (ptrNodoListaDep != finAD()) {

      /* crea el nodo y lo intercala en la lista */
      ptrNuevoNodo = crearNodoLista(datoArtDep);

      ptrNuevoNodo->sgteAD = ptrNodoListaDep->sgteAD;
      ptrNodoListaDep->sgteAD = ptrNuevoNodo;
    }
  }
  return ptrNuevoNodo;
}
//********************
PtrNodoListaDeposito adicionarFinal(ListaArtDeposito &listaArtDep, ArtDep datoArtDep){
return adicionarDespues(listaArtDep,datoArtDep,ultimo(listaArtDep));
}
//********************
void colocarDato(ListaArtDeposito &listaArtDep,ArtDep &datoArtDep, PtrNodoListaDeposito ptrNodoListaDep){
if ( (! listaVacia(listaArtDep)) && (ptrNodoListaDep != finAD()))
    ptrNodoListaDep->datoArtDep = datoArtDep;
}
//********************
void obtenerDato(ListaArtDeposito &listaArtDep,ArtDep &datoArtDep, PtrNodoListaDeposito ptrNodoListaDep){
if ((! listaVacia(listaArtDep)) && (ptrNodoListaDep != finAD()))
    datoArtDep = ptrNodoListaDep->datoArtDep;
}
//*******************
void eliminarNodo(ListaArtDeposito &listaArtDep,PtrNodoListaDeposito ptrNodoListaDep){
PtrNodoListaDeposito ptrPrevio;

  /* verifica que la lista no esté vacia y que nodo no sea fin*/
  if ((! listaVacia(listaArtDep)) && (ptrNodoListaDep != finAD())) {

    if (ptrNodoListaDep == primero(listaArtDep))
      listaArtDep.primerArtDeposito = siguiente(listaArtDep,primero(listaArtDep));

    else {
      ptrPrevio = anterior( listaArtDep , ptrNodoListaDep );
      ptrPrevio->sgteAD= ptrNodoListaDep->sgteAD;
    }
    // Si el dato es un TDA, acá habría que llamar al destructor.
  destruirArtDep(ptrNodoListaDep->datoArtDep);
    delete ptrNodoListaDep;
  }
}
//********************
void eliminarNodoPrimero(ListaArtDeposito &listaArtDep){
if (! listaVacia(listaArtDep))
    eliminarNodo(listaArtDep,primero(listaArtDep));
}
//********************
void eliminarNodoUltimo(ListaArtDeposito &listaArtDep){
if (! listaVacia(listaArtDep))
    eliminarNodo(listaArtDep,ultimo(listaArtDep));
}
//********************
void eliminarLista(ListaArtDeposito &listaArtDep){
 while (! listaVacia(listaArtDep))
    eliminarNodo(listaArtDep,primero(listaArtDep));
}
