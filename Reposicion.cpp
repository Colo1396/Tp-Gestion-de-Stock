#include "Reposicion.h"
#include <iostream>
#include <string.h>
//********************************
void crearReposicion(Reposicion &reposicion){
reposicion.cod_articulo=0;
reposicion.cantidad=0;
strcpy(reposicion.hora,"");
}
//********************************
void crearReposicion(Reposicion &reposicion,int CodArt,int Cant,char hora[]){
reposicion.cod_articulo=CodArt;
reposicion.cantidad=Cant;
strcpy(reposicion.hora,hora);
}
//********************************
void destruirReposicion(Reposicion &reposicion){
}
//********************************
int getCodArt(Reposicion &reposicion){
 return reposicion.cod_articulo;
}
//********************************
int getCant(Reposicion &reposicion){
 return reposicion.cantidad;
}
//********************************
char* getHora(Reposicion &reposicion){
char* ch;
ch=reposicion.hora;
return ch;
}
//********************************
void setCodArt(Reposicion &reposicion,int codart){
reposicion.cod_articulo=codart;
}
//********************************
void setCant(Reposicion &reposicion,int cant){
reposicion.cantidad=cant;
}
//********************************
void setHora(Reposicion &reposicion,char hora[]){
strcpy(reposicion.hora,hora);
}

