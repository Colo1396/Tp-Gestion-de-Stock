#ifndef __FALTANTES_H__
#define __FALTANTES_H__
typedef struct Faltantes{
int codsucursal;
int codArt;
float cantTot;
float cantEnv;
int porc;
};
void crearFaltante(Faltantes &faltantes);
void crearFaltante(Faltantes &faltantes,int codSucursal,int codart,float cantot,float cantenv,int porc);
void destructorFaltantes(Faltantes &faltantes);
int getCodArt(Faltantes &faltantes);
int getCodsucursal(Faltantes &faltantes);
float getCantTot(Faltantes &faltantes);
float getCantEnv(Faltantes &faltantes);
int getPorc(Faltantes &faltantes);
void setCodsuccursal(Faltantes &faltante,int codSucursal);
void setCodArt(Faltantes &faltantes,int codart);
void setCantTot(Faltantes &faltantes,float cantot);
void setCantEnv(Faltantes &faltantes,float cantenv);
void setPorc(Faltantes &faltantes,int porc);

#endif // __FALTANTES_H__
