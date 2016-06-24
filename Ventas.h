#ifndef __VENTAS_H__
#define __VENTAS_H__

typedef struct Ventas{
int codSucursal;
float montoTotal;
};
//********************************
void crearVentas(Ventas &ventas);
//********************************
void crearVentas(Ventas &ventas,int codSuc,float montTot);
//********************************
void destruirVentas(Ventas &ventas);
//********************************
void setCodSuc(Ventas &ventas,int codsuc);
//********************************
void setMonTot(Ventas &ventas,float monTot);
//********************************
int getCodSuc(Ventas &ventas);
//********************************
float getMonTot(Ventas &ventas);

#endif // __VENTAS_H__
