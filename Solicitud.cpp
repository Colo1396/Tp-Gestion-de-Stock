#include "Solicitud.h"
#include <iostream>
#include <string.h>

//********************************
void crearSolicitud(Solicitud &solicitud){
solicitud.cod_suc=0;
solicitud.cod_articulo=0;
solicitud.cantidad=0;
strcpy(solicitud.hora,"");
}
//********************************
void crearSolicitud(Solicitud &solicitud,int CodSuc,int CodArt,int cant,char hora[]){

solicitud.cod_suc=CodSuc;
solicitud.cod_articulo=CodArt;
solicitud.cantidad=cant;
strcpy(solicitud.hora,hora);
}
//********************************
void destruirSolicitud(Solicitud &solicitud){
}
//********************************
int getCodSuc(Solicitud &solicitud){
return solicitud.cod_suc;
}
//********************************
int getCodArt(Solicitud &solicitud){
return solicitud.cod_articulo;
}
//********************************
int getCant(Solicitud &solicitud){
return solicitud.cantidad;
}
//********************************
char* getHora(Solicitud &solicitud){
char * ch;
ch=solicitud.hora;
return ch;
}
//********************************
void setCodSuc(Solicitud &solicitud,int CodSuc){
solicitud.cod_suc=CodSuc;
}
//********************************
void setCodArt(Solicitud &solicitud,int CodArt){
solicitud.cod_articulo=CodArt;
}
//********************************
void setCantidad(Solicitud &solicitud,int Cant){
solicitud.cantidad=Cant;
}
//********************************
void setHora(Solicitud &solicitud,char h[]){
    strcpy(solicitud.hora,h);

}
//********************************
