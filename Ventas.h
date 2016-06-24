#ifndef __VENTAS_H__
#define __VENTAS_H__


/* Tipo de Estructura de los Nodos de la Lista. */
typedef struct Ventas{
int codSucursal;
float montoTotal;
};

//********************************
/*
  pre : la Venta no haya sido creada
  post: venta queda creada y preparada para ser usada.
  Venta : estructura de datos a ser creado.
*/
void crearVentas(Ventas &ventas);
//********************************
/*
  pre : la venta no debe haber sido creada.
  post: venta queda creada y preparada para ser usada.
  Venta : estructura de datos a ser creado.
*/
void crearVentas(Ventas &ventas,int codSuc,float montTot);
//********************************
/*
  pre : la venta no debe haber sido destruida.
  post:  La venta es eliminada completamente.
  Venta : estructura de datos a ser creado.
  codsuc, montot: variables a utilizar
*/
void destruirVentas(Ventas &ventas);
//********************************
/*
  pre : El Codigo sucursal no esta seteado
  post: codigo sucursal queda seteado
  Venta : estructura de datos a ser creado.
  codsuc: entero con el cual se setea el codigo sucursal
*/
void setCodSuc(Ventas &ventas,int codsuc);
//********************************
/*
  pre : El Monto total no esta seteado
  post: Monto total queda seteado
  venta : estructura de datos a ser creado.
  monTot: entero con el cual se setea el monto
*/
void setMonTot(Ventas &ventas,float monTot);
//********************************
/*
  pre : se quiere obtener el codigo sucursal de la estructura
  post: codigo sucursal obtenido
  venta : estructura de datos a ser creado.
*/
int getCodSuc(Ventas &ventas);
//********************************
/*
  pre : se quiere obtener el codigo sucursal de la estructura
  post: Monto total obtenido
  venta : estructura de datos a ser creado.
*/
float getMonTot(Ventas &ventas);

#endif // __VENTAS_H__
