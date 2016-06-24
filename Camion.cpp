#include "Camion.h"
#include    <iostream>
using namespace std;
//creamos el constructor del camion.
void crearCamion(Camion &camion){
camion.id_camion=1;
camion.carga_total=0;
camion.porcentaje=0;
}
//********************************
void crearCamion(Camion &camion,int idCamion,float Ct,float porc){
camion.id_camion=idCamion;
camion.carga_total=Ct;
camion.porcentaje=porc;
}
//********************************
//obtenemos el ID del camion
int getId_Camion(Camion &camion){
 return camion.id_camion;
}
//********************************
//obtenemos la carga del camion
float getCarga_T(Camion &camion){
 return camion.carga_total;
 }
//********************************
//obtenemos el porcentaje del camion
float getPorcentaje(Camion &camion){
 return camion.porcentaje;
 }
//********************************
//********************************
//modificamos el id del camion
void setId_Camion(Camion &camion,int idCamion){
 camion.id_camion=idCamion;
}
//********************************
//modificamos la carga del camion
void setCarga_T(Camion &camion,float cT){
 camion.carga_total=cT;
 }
//********************************
//modificamos el porcentaje
void setPorcentaje(Camion &camion,float porc){
 camion.porcentaje=porc;
}
//********************************
void destruirCamion(Camion &camion){
}
