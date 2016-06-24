#include "Ventas.h"
//********************************
void crearVentas(Ventas &ventas){
ventas.codSucursal=0;
ventas.montoTotal=0;
}
//********************************
void crearVentas(Ventas &ventas,int codSuc,float montTot){
ventas.codSucursal=codSuc;
ventas.montoTotal=montTot;
}
//********************************
void destruirVentas(Ventas &ventas){
}
//********************************
void setCodSuc(Ventas &ventas,int codsuc){
ventas.codSucursal=codsuc;
}
//********************************
void setMonTot(Ventas &ventas,float monTot){
ventas.montoTotal=monTot;
}
//********************************
int getCodSuc(Ventas &ventas){
return ventas.codSucursal;
}
//********************************
float getMonTot(Ventas &ventas){
return ventas.montoTotal;
}
