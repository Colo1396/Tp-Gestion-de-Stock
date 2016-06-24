#include "ListaArticulo.h"
//********************
void crearListaArt(ListaArt &listaA){
listaA.primeroListaArt=finA();
}
//********************
bool listaVacia(ListaArt &listaA){
return (primero(listaA)==finA());
}
//********************
PrtNodoListaArt finA(){
return NULL;
}
//********************
PrtNodoListaArt primero(ListaArt &listaA){
return listaA.primeroListaArt;
}
//********************
PrtNodoListaArt siguiente(ListaArt &listaA,PrtNodoListaArt ptrNodoListaArt){
if ((! listaVacia(listaA)) && (ptrNodoListaArt != finA()))
    return ptrNodoListaArt->sgteArt;
  else
    return finA();
    }
//********************
PrtNodoListaArt anterior(ListaArt  &listaA,PrtNodoListaArt  ptrNodoListaArt){
  PrtNodoListaArt ptrPrevio = finA();
  PrtNodoListaArt ptrCursor = primero(listaA);

  while (( ptrCursor != finA()) && (ptrCursor != ptrNodoListaArt)) {
    ptrPrevio = ptrCursor;
    ptrCursor = siguiente(listaA,ptrCursor);
  }
  return ptrPrevio;
}
//********************
PrtNodoListaArt ultimo(ListaArt &listaA){
    return anterior(listaA,finA());
}
//********************
PrtNodoListaArt crearNodoLista(LArt datoArticulo){
 PrtNodoListaArt ptrAux = new NodoListaArt;

  ptrAux->datoLArt = datoArticulo;
  ptrAux->sgteArt = finA();

  return ptrAux;
}
//********************
PrtNodoListaArt adicionarPrincipio(ListaArt &listaA,LArt datoArticulo){
  /* crea el nodo */
  PrtNodoListaArt ptrNuevoNodo = crearNodoLista(datoArticulo);

  /* lo incorpora al principio de la lista */
  ptrNuevoNodo->sgteArt = listaA.primeroListaArt;
  listaA.primeroListaArt = ptrNuevoNodo;

  return ptrNuevoNodo;
}
//********************
PrtNodoListaArt adicionarDespues(ListaArt &listaA,LArt datoArticulo, PrtNodoListaArt ptrNodoListaArt){
PrtNodoListaArt ptrNuevoNodo = finA();

  /* si la lista está vacia se adiciona la principio */
  if (listaVacia(listaA))
    ptrNuevoNodo = adicionarPrincipio(listaA,datoArticulo);

  else {
    if (ptrNodoListaArt != finA()) {

      /* crea el nodo y lo intercala en la lista */
      ptrNuevoNodo = crearNodoLista(datoArticulo);

      ptrNuevoNodo->sgteArt = ptrNodoListaArt->sgteArt;
      ptrNodoListaArt->sgteArt = ptrNuevoNodo;
    }
  }
  return ptrNuevoNodo;
}
//********************
PrtNodoListaArt adicionarFinal(ListaArt  &listaA, LArt datoArticulo){
  return adicionarDespues(listaA,datoArticulo,ultimo(listaA));
}
//********************
void colocarDato(ListaArt  &listaA,LArt &datoArticulo,PrtNodoListaArt ptrNodoListaArt){
if ( (! listaVacia(listaA)) && (ptrNodoListaArt != finA()))
    ptrNodoListaArt->datoLArt = datoArticulo;
}
//********************
void obtenerDato(ListaArt  &listaA, LArt &datoArticulo,PrtNodoListaArt ptrNodoListaArt){
if ((! listaVacia(listaA)) && (ptrNodoListaArt != finA()))
    datoArticulo = ptrNodoListaArt->datoLArt;
}
//********************
void eliminarNodo(ListaArt  &listaA, PrtNodoListaArt ptrNodoListaArt){
PrtNodoListaArt ptrPrevio;

  /* verifica que la lista no esté vacia y que nodo no sea fin*/
  if ((! listaVacia(listaA)) && (ptrNodoListaArt != finA())) {

    if (ptrNodoListaArt == primero(listaA))
      listaA.primeroListaArt = siguiente(listaA,primero(listaA));

    else {
      ptrPrevio = anterior( listaA , ptrNodoListaArt );
      ptrPrevio->sgteArt= ptrNodoListaArt->sgteArt;
    }
    // Si el dato es un TDA, acá habría que llamar al destructor.
    destructorArt(ptrNodoListaArt->datoLArt);
    delete ptrNodoListaArt;
  }
}
//********************
void eliminarNodoPrimero(ListaArt  &listaA){
  if (! listaVacia(listaA))
    eliminarNodo(listaA,primero(listaA));
}
//********************
void eliminarNodoUltimo(ListaArt  &listaA){
if (! listaVacia(listaA))
    eliminarNodo(listaA,ultimo(listaA));
}
//********************
void eliminarLista(ListaArt  &listaA){
  while (! listaVacia(listaA))
    eliminarNodo(listaA,primero(listaA));
}
