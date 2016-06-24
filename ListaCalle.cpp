#include "ListaCalle.h"
//****************
void crearListaCalle(ListaCalle &listaC){
listaC.primeroCalle=finC();
}
//****************
bool listaVacia(ListaCalle &listaC){
return (primero(listaC) == finC());
}
PtrNodoCalle finC(){
return NULL;
}
PtrNodoCalle primero(ListaCalle &listaC){
return listaC.primeroCalle;
}
PtrNodoCalle siguiente(ListaCalle &listaC,PtrNodoCalle ptrNodoCalle){
/* verifica si la lista está vacia o si ptrNodoCalle es el último */
  if ((! listaVacia(listaC)) && (ptrNodoCalle != finC()))
    return ptrNodoCalle->sgteC;
  else
    return finC();
}
// Definicion de Primitivas
PtrNodoCalle anterior(ListaCalle &listaC, PtrNodoCalle ptrNodoC){
PtrNodoCalle ptrPrevio = finC();
  PtrNodoCalle ptrCursor = primero(listaC);

  while (( ptrCursor != finC()) && (ptrCursor != ptrNodoC)) {
    ptrPrevio = ptrCursor;
    ptrCursor = siguiente(listaC,ptrCursor);
  }
  return ptrPrevio;
}
PtrNodoCalle ultimo(ListaCalle &listaC){
/* el último nodo de la lista es el anterior al fin() */
return anterior(listaC,finC());
}
PtrNodoCalle crearNodoLista(ListPiso listPiso) {

  /* reserva memoria para el nodo y luego completa sus datos */
  PtrNodoCalle ptrAux = new NodoCalle;

  ptrAux->listPiso = listPiso;
  ptrAux->sgteC = finC();

  return ptrAux;
}
PtrNodoCalle adicionarPrincipio(ListaCalle &listaC, ListPiso listPiso){

  /* crea el nodo */
  PtrNodoCalle ptrNuevoNodo = crearNodoLista(listPiso);

  /* lo incorpora al principio de la lista */
  ptrNuevoNodo->sgteC = listaC.primeroCalle;
  listaC.primeroCalle = ptrNuevoNodo;

  return ptrNuevoNodo;
}
PtrNodoCalle adicionarDespues(ListaCalle &listaC, ListPiso listPiso, PtrNodoCalle ptrNodoC){
  PtrNodoCalle ptrNuevoNodo = finC();

  /* si la lista está vacia se adiciona la principio */
  if (listaVacia(listaC))
    ptrNuevoNodo = adicionarPrincipio(listaC,listPiso);

  else {
    if (ptrNodoC != finC()) {

      /* crea el nodo y lo intercala en la lista */
      ptrNuevoNodo = crearNodoLista(listPiso);

      ptrNuevoNodo->sgteC = ptrNodoC->sgteC;
      ptrNodoC->sgteC = ptrNuevoNodo;
    }
  }
  return ptrNuevoNodo;
}
PtrNodoCalle adicionarFinal(ListaCalle &listaC,ListPiso listPiso){
  /* adiciona el dato después del último nodo de la lista */
  return adicionarDespues(listaC,listPiso,ultimo(listaC));
  }
PtrNodoCalle adicionarAntes(ListaCalle &listaC, ListPiso listPiso, PtrNodoCalle ptrNodoC){
 PtrNodoCalle ptrNuevoNodo = finC();

  if (! listaVacia(listaC)) {
    if (ptrNodoC != primero(listaC))
      ptrNuevoNodo = adicionarDespues(listaC,listPiso,anterior(listaC,ptrNodoC));
    else
      ptrNuevoNodo = adicionarPrincipio(listaC,listPiso);
   }
   return ptrNuevoNodo;
}
void colocarDato(ListaCalle &listaC,ListPiso listPiso, PtrNodoCalle ptrNodoC){
     if ( (! listaVacia(listaC)) && (ptrNodoC != finC()))
    ptrNodoC->listPiso = listPiso;
}
void obtenerDato(ListaCalle &listaC, ListPiso listPiso, PtrNodoCalle ptrNodoC){
     if ((! listaVacia(listaC)) && (ptrNodoC != finC()))
    listPiso = ptrNodoC->listPiso;
}
void eliminarNodo(ListaCalle &listaC, PtrNodoCalle ptrNodoC){

  PtrNodoCalle ptrPrevio;

  /* verifica que la lista no esté vacia y que nodo no sea fin*/
  if ((! listaVacia(listaC)) && (ptrNodoC != finC())) {

    if (ptrNodoC == primero(listaC))
      listaC.primeroCalle = siguiente(listaC,primero(listaC));

    else {
      ptrPrevio = anterior( listaC , ptrNodoC );
      ptrPrevio->sgteC = ptrNodoC->sgteC;
    }
    // Si el dato es un TDA, acá habría que llamar al destructor.

    delete ptrNodoC;
  }
}
void eliminarNodoPrimero(ListaCalle &listaC){
     if (! listaVacia(listaC))
    eliminarNodo(listaC,primero(listaC));
}
void eliminarNodoUltimo(ListaCalle &listaC){
  if (! listaVacia(listaC))
    eliminarNodo(listaC,ultimo(listaC));
}
void eliminarLista(ListaCalle &listaC){
  /* retira uno a uno los nodos de la lista */
  while (! listaVacia(listaC))
    eliminarNodo(listaC,primero(listaC));
}
// Definición de Operaciones Adicionales

int longitud(ListaCalle &listaC){
 PtrNodoCalle ptrCursor = primero(listaC);
  int longitud = 0;
  while ( ptrCursor != finC() ) {
        longitud++;
        ptrCursor = siguiente( listaC, ptrCursor);
  }
  return longitud;
}
