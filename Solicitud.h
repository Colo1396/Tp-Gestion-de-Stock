#ifndef __SOLICITUD_H__
#define __SOLICITUD_H__

/* Tipo de Estructura de los Nodos de la Lista. */
typedef struct Solicitud{
int cod_suc;
int cod_articulo;
int cantidad;
char hora[150];
};
//********************************
/* pre : la Solicitus no haya sido creada
  post: Solicitud queda creada y preparada para ser usada.
  Solicitud : estructura de datos a ser creado.
*/
void crearSolicitud(Solicitud &solicitud);
//********************************
 /*pre : Solicitud no haya sido creada
  post: Solicitud queda creada y preparada para ser usada.
  Solicitud : estructura de datos a ser creado.
  codsuc,codart,cant,hora variables que se van a utilizar
*/
void crearSolicitud(Solicitud &solicitud,int CodSuc,int CodArt,int cant,char hora[]);
//********************************
/*
  pre : La solicitud no debe haber sido destruida.
  post: La solicitud es eliminada completamente.
  Solicitud : estructura de datos a ser creado.
  codsuc,codart,cant,hora variables que se van a utilizar
*/
void destruirSolicitud(Solicitud &solicitud);
//********************************
/*
  pre : se quiere obtener el codigo sucursal de la estructura
  post: codigo de sucursal obtenido
 solicitud : estructura de datos a ser creado.
*/
int getCodSuc(Solicitud &solicitud);
//********************************
/*
  pre : se quiere obtener el codigo articulo de la estructura
  post: codigo articulo obtenido
  solicitud : estructura de datos a ser creado.
*/
int getCodArt(Solicitud &solicitud);
//********************************
/*
  pre : se quiere obtener la cantidad de la estructura
  post: cantidad obtenido
  solicitud : estructura de datos a ser creado.
*/
int getCant(Solicitud &solicitud);
//********************************
/*
  pre : se quiere obtener la hora de la estructura
  post: hora obtenido
  solicitud : estructura de datos a ser creado.
*/
char* getHora(Solicitud &solicitud);
//********************************
/*
  pre : codigo de sucursal no debe haber sido seteada.
  post: codigo de sucursal seteado
  Solicitud : estructura de datos a ser creado.
  codsuc  variabla a utilizar
*/
void setCodSuc(Solicitud &solicitud,int CodSuc);
//********************************
/*
  pre : codigo de articulo no debe haber sido seteada.
  post: codigo de articulo seteado
  Solicitud : estructura de datos a ser creado.
  codart variable a utilizar
*/
void setCodArt(Solicitud &solicitud,int CodArt);
//********************************
/*
  pre : cantidad no debe haber sido seteada.
  post: cantidad seteado
  Solicitud : estructura de datos a ser creado.
  cant  variable a utilizar
*/
void setCantidad(Solicitud &Solicitud,int Cant);
//********************************
/*
  pre : Hora no debe ser seteada
  post: Hora queda seteada
  Solicitud : estructura de datos a ser creado.
  h variable a utilizar
*/
void setHora(Solicitud &solicitud,char h[]);

#endif // __SOLICITUD_H__
