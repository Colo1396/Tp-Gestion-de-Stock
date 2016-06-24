#ifndef __PESOACUMULADO_H__
#define __PESOACUMULADO_H__

/*Definición del Tipo de Dato*/
typedef struct PesoAcum{
int codArt;
float cant;
};

//*****************
/*
  pre: la instancia no debe ser creado ni estar destruido.
  post: Crea la instancia con los datos en 0.
  pesoAcum: instancia sobre la que se invoca la primitiva
*/
void crearPesoAcum(PesoAcum &pesoAcum);
//*****************
/*
  pre: la instancia no debe ser creado ni estar destruido.
  post: Crea la instancia con los datos seteados segun lo que se le ingresa.
  pesoAcum: instancia sobre la que se invoca la primitiva
  codart,cant. Variables que se utilizan en la funcion
*/
void crearPesoAcum(PesoAcum &pesoAcum,int codart,float cant);
//*****************
/*
  pre: la instancia debe existir.
  post: elimina la instancia.
  pesoAcum: instancia sobre la que se invoca la primitiva
*/
void destruirPesoAcum(PesoAcum &pesoAcum);
//*****************
/*
  pre: la instancia debe existir.
  post: Se le setea un valor asignado a codart.
  pesoAcum: instancia sobre la que se invoca la primitiva
  cordart: Variable que se utiliza en la funcion.
*/
void setCodArt(PesoAcum &pesoAcum,int codart);
//*****************
/*
  pre: la instancia debe existir.
  post: Se le setea un valor asignado a cant
  pesoAcum: instancia sobre la que se invoca la primitiva
  cant: Variable que se utiliza en la funcion.
*/
void setCant(PesoAcum &pesoAcum,float cant);
//*****************
/*
  pre: la instancia debe existir.
  post: obtenemos el valor de codart, de la instancia.
  pesoAcum: instancia sobre la que se invoca la primitiva

*/
int getCodArt(PesoAcum &pesoAcum);
//*****************
/*
  pre: la instancia debe existir.
  post: obtenemos el valor de cantidad, de la instancia.
  pesoAcum: instancia sobre la que se invoca la primitiva

*/
float getCant(PesoAcum &pesoAcum);


#endif // __PESOACUMULADO_H__
