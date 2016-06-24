#ifndef __CAMION_H__
#define __CAMION_H__
//********************************
typedef struct Camion{
 int id_camion;
 float carga_total;
 float porcentaje;
};
//********************************
void crearCamion(Camion &camion);
//********************************
void crearCamion(Camion &camion,int idCamion,float Ct,float porc);
//********************************
void destruirCamion(Camion &camion);
//********************************
int getId_Camion(Camion &camion);
//********************************
float getCarga_T(Camion &camion);
//********************************
float getPorcentaje(Camion &camion);
//********************************
int getId_Suc(Camion &camion);
//********************************
void setId_Camion(Camion &camion,int idCamion);
//********************************
void setCarga_T(Camion &camion,float cT);
//********************************
void setPorcentaje(Camion &camion,float porc);
//********************************
#endif // __CAMION_H__
