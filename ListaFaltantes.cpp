#include "ListaFaltantes.h"

//********************
void crearListaFaltante(ListaFaltante &listaF){
listaF.primerFaltante=finF();
}
//********************
bool listaVacia(ListaFaltante &listaF){
return (primero(listaF)==finF());
}
//********************
PtrNodoFaltante finF(){
return NULL;
}
//********************
PtrNodoFaltante primero(ListaFaltante &listaF){
return listaF.primerFaltante;}
//********************
PtrNodoFaltante siguiente(ListaFaltante &listaF,PtrNodoFaltante ptrNodoFaltante){
if ((! listaVacia(listaF)) && (ptrNodoFaltante != finF()))
    return ptrNodoFaltante->sgteF;
  else
    return finF();
    }
//********************
PtrNodoFaltante anterior(ListaFaltante &listaF,PtrNodoFaltante  ptrNodoFaltante){
  PtrNodoFaltante ptrPrevio = finF();
  PtrNodoFaltante ptrCursor = primero(listaF);

  while (( ptrCursor != finF()) && (ptrCursor != ptrNodoFaltante)) {
    ptrPrevio = ptrCursor;
    ptrCursor = siguiente(listaF,ptrCursor);
  }
  return ptrPrevio;
}
//********************
PtrNodoFaltante ultimo(ListaFaltante &listaF){
    return anterior(listaF,finF());
}
//********************
PtrNodoFaltante crearNodoLista(Faltante datoFaltante){
 PtrNodoFaltante ptrAux = new NodoFaltante;

  ptrAux->datoFaltante = datoFaltante;
  ptrAux->sgteF = finF();

  return ptrAux;
}
//********************
PtrNodoFaltante adicionarPrincipio(ListaFaltante &listaF,Faltante datoFaltante){
  /* crea el nodo */
  PtrNodoFaltante ptrNuevoNodo = crearNodoLista(datoFaltante);

  /* lo incorpora al principio de la lista */
  ptrNuevoNodo->sgteF = listaF.primerFaltante;
  listaF.primerFaltante = ptrNuevoNodo;

  return ptrNuevoNodo;
}
//********************
PtrNodoFaltante adicionarDespues(ListaFaltante &listaF,Faltante datoFaltante, PtrNodoFaltante ptrNodoFaltante){
PtrNodoFaltante ptrNuevoNodo = finF();

  /* si la lista está vacia se adiciona la principio */
  if (listaVacia(listaF))
    ptrNuevoNodo = adicionarPrincipio(listaF,datoFaltante);

  else {
    if (ptrNodoFaltante != finF()) {

      /* crea el nodo y lo intercala en la lista */
      ptrNuevoNodo = crearNodoLista(datoFaltante);

      ptrNuevoNodo->sgteF = ptrNodoFaltante->sgteF;
      ptrNodoFaltante->sgteF = ptrNuevoNodo;
    }
  }
  return ptrNuevoNodo;
}
//********************
PtrNodoFaltante adicionarFinal(ListaFaltante &listaF,Faltante datoFaltante){
  return adicionarDespues(listaF,datoFaltante,ultimo(listaF));
}
//********************
void colocarDato(ListaFaltante &listaF,Faltante &datoFaltante, PtrNodoFaltante ptrNodoFaltante){
if ( (! listaVacia(listaF)) && (ptrNodoFaltante != finF()))
    ptrNodoFaltante->datoFaltante = datoFaltante;
}
//********************
void obtenerDato(ListaFaltante &listaF, Faltante &datoFaltante, PtrNodoFaltante ptrNodoFaltante){
if ((! listaVacia(listaF)) && (ptrNodoFaltante != finF()))
    datoFaltante = ptrNodoFaltante->datoFaltante;
}
//********************
void eliminarNodo(ListaFaltante &listaF, PtrNodoFaltante ptrNodoFaltante){
PtrNodoFaltante ptrPrevio;

  /* verifica que la lista no esté vacia y que nodo no sea fin*/
  if ((! listaVacia(listaF)) && (ptrNodoFaltante != finF())) {

    if (ptrNodoFaltante == primero(listaF))
      listaF.primerFaltante= siguiente(listaF,primero(listaF));

    else {
      ptrPrevio = anterior( listaF , ptrNodoFaltante );
      ptrPrevio->sgteF= ptrNodoFaltante->sgteF;
    }
    // Si el dato es un TDA, acá habría que llamar al destructor.
    destructorFaltantes(ptrNodoFaltante->datoFaltante);
    delete ptrNodoFaltante;
  }
}
//********************
void eliminarNodoPrimero(ListaFaltante &listaF){
  if (! listaVacia(listaF))
    eliminarNodo(listaF,primero(listaF));
}
//********************
void eliminarNodoUltimo(ListaFaltante &listaF){
if (! listaVacia(listaF))
    eliminarNodo(listaF,ultimo(listaF));
}
//********************
void eliminarLista(ListaFaltante &listaF){
  while (! listaVacia(listaF))
    eliminarNodo(listaF,primero(listaF));
}

