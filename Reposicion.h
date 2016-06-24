#ifndef __REPOSICION_H__
#define __REPOSICION_H__
/* Tipo de Estructura de los Nodos de la Lista. */
typedef struct Reposicion{
int cod_articulo;
int cantidad;
char hora[150];
};



//********************************
/* pre : la reposicion no haya sido creada
  post: la reposicion queda creada y preparada para ser usada.
  reposicion : estructura de datos a ser creado.
*/
void crearReposicion(Reposicion &reposicion);
//********************************
 /*pre : reposicion no haya sido creada
  post: reposicion queda creada y preparada para ser usada.
  reposicion : estructura de datos a ser creado.
  cod_articulo,cantidad,hora variables que se van a utilizar
*/
void crearReposicion(Reposicion &reposicion,int CodArt,int Cant,char hora[]);
//********************************
/*pre : Que no se haya destruido la reposicion
post:reposicion destruida
reposicion : estructura de datos a ser creado.*/
void destruirReposicion(Reposicion &reposicion);
//********************************
/*
  pre : se quiere obtener el codigo articulo de la estructura
  post: codigo de articulo  obtenido
  reposicion : estructura de datos a ser creado.
*/
int getCodArt(Reposicion &reposicion);
//********************************
/*
  pre : se quiere obtener el cantidad de la estructura
  post: cantidad  obtenido
  reposicion : estructura de datos a ser creado.
*/
int getCant(Reposicion &reposicion);
//********************************
/*
  pre : se quiere obtener la hora de la estructura
  post: hora  obtenido
  reposicion : estructura de datos a ser creado.
*/
char* getHora(Reposicion &reposicion);
//********************************
/*
  pre : se quiere setear codigo articulo  de la estructura
  post: codigo de articulo  seteado
  reposicion : estructura de datos a ser creado.
*/
void setCodArt(Reposicion &reposicion,int codart);
//********************************
/*
  pre : se quiere setear cantidad de la estructura
  post: cantidad  seteado
  reposicion : estructura de datos a ser creado.
*/
void setCant(Reposicion &reposicion,int cant);

#endif // __REPOSICION_H__
