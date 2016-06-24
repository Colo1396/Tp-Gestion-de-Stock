#include "ListaPiso.h"
void crearListaPiso(ListaPiso &listaP){
listaP.primeroPiso=finP();
}
bool listaVacia(ListaPiso &listaP){
return (primero(listaP) == finP());
}
PtrNodoPiso finP(){
return NULL;
}
PtrNodoPiso primero(ListaPiso &listaP){
return listaP.primeroPiso;
}
PtrNodoPiso siguiente(ListaPiso &listaP, PtrNodoPiso ptrNodoP){
/* verifica si la lista está vacia o si ptrNodo es el último */
  if ((! listaVacia(listaP)) && (ptrNodoP != finP()))
    return ptrNodoP->sgteP;
  else
    return finP();
}
PtrNodoPiso anterior(ListaPiso &listaP, PtrNodoPiso ptrNodoP){
PtrNodoPiso ptrPrevio = finP();
PtrNodoPiso ptrCursor = primero(listaP);

  while (( ptrCursor != finP()) && (ptrCursor != ptrNodoP)) {
    ptrPrevio = ptrCursor;
    ptrCursor = siguiente(listaP,ptrCursor);
  }
  return ptrPrevio;

}
PtrNodoPiso ultimo(ListaPiso &listaP){
return anterior(listaP,finP());
}
PtrNodoPiso crearNodoLista(PilUb pilUb){
  /* reserva memoria para el nodo y luego completa sus datos */
  PtrNodoPiso ptrAux = new NodoPiso;

  ptrAux->pilUb = pilUb;
  ptrAux->sgteP = finP();

  return ptrAux;

}
PtrNodoPiso adicionarPrincipio(ListaPiso &listaP, PilUb pilUb){
/* crea el nodo */
  PtrNodoPiso ptrNuevoNodo = crearNodoLista(pilUb);

  /* lo incorpora al principio de la lista */
  ptrNuevoNodo->sgteP = listaP.primeroPiso;
  listaP.primeroPiso = ptrNuevoNodo;

  return ptrNuevoNodo;
}
PtrNodoPiso adicionarDespues(ListaPiso &listaP, PilUb pilUb, PtrNodoPiso ptrNodoP){
  PtrNodoPiso ptrNuevoNodo = finP();

  /* si la lista está vacia se adiciona la principio */
  if (listaVacia(listaP))
    ptrNuevoNodo = adicionarPrincipio(listaP,pilUb);

  else {
    if (ptrNodoP != finP()) {

      /* crea el nodo y lo intercala en la lista */
      ptrNuevoNodo = crearNodoLista(pilUb);

      ptrNuevoNodo->sgteP = ptrNodoP->sgteP;
      ptrNodoP->sgteP = ptrNuevoNodo;
    }
  }
  return ptrNuevoNodo;
}
PtrNodoPiso adicionarFinal(ListaPiso &listaP, PilUb pilUb){
  /* adiciona el dato después del último nodo de la lista */
  return adicionarDespues(listaP,pilUb,ultimo(listaP));
}
PtrNodoPiso adicionarAntes(ListaPiso &listaP, PilUb pilUb, PtrNodoPiso ptrNodoP){
  PtrNodoPiso ptrNuevoNodo = finP();

  if (! listaVacia(listaP)) {
    if (ptrNodoP != primero(listaP))
      ptrNuevoNodo = adicionarDespues(listaP,pilUb,anterior(listaP,ptrNodoP));
    else
      ptrNuevoNodo = adicionarPrincipio(listaP,pilUb);
   }
   return ptrNuevoNodo;
}
void colocarDato(ListaPiso &listaP, PilUb &pilUb, PtrNodoPiso ptrNodoP){
  if ( (! listaVacia(listaP)) && (ptrNodoP != finP()))
    ptrNodoP->pilUb = pilUb;
}
void obtenerDato(ListaPiso &listaP, PilUb &pilUb, PtrNodoPiso ptrNodoP){
 if ((! listaVacia(listaP)) && (ptrNodoP != finP()))
    pilUb = ptrNodoP->pilUb;
}
void eliminarNodo(ListaPiso &listaP, PtrNodoPiso ptrNodoP){
  PtrNodoPiso ptrPrevio;

  /* verifica que la lista no esté vacia y que nodo no sea fin*/
  if ((! listaVacia(listaP)) && (ptrNodoP != finP())) {

    if (ptrNodoP == primero(listaP))
      listaP.primeroPiso = siguiente(listaP,primero(listaP));

    else {
      ptrPrevio = anterior( listaP , ptrNodoP );
      ptrPrevio->sgteP = ptrNodoP->sgteP;
    }
    // Si el dato es un TDA, acá habría que llamar al destructor.
    destruir(ptrNodoP->pilUb);
    delete ptrNodoP;
  }
}
void eliminarNodoPrimero(ListaPiso &listaP){
  if (! listaVacia(listaP))
    eliminarNodo(listaP,primero(listaP));
}
void eliminarNodoUltimo(ListaPiso &listaP){
  if (! listaVacia(listaP))
    eliminarNodo(listaP,ultimo(listaP));
}
void eliminarLista(ListaPiso &listaP){
while (! listaVacia(listaP))
    eliminarNodo(listaP,primero(listaP));
}
