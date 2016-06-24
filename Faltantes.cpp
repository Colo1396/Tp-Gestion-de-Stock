#include "Faltantes.h"
void crearFaltante(Faltantes &faltantes){
faltantes.codArt=0;
faltantes.codsucursal=0;
faltantes.cantTot=0;
faltantes.cantEnv=0;
faltantes.porc=0;
}
void crearFaltante(Faltantes &faltantes,int codsuc,int codart,float cantot,float cantenv,int porc){
faltantes.codArt=codart;
faltantes.codsucursal=codsuc;
faltantes.cantTot=cantot;
faltantes.cantEnv=cantenv;
faltantes.porc=porc;
}
void destructorFaltantes(Faltantes &faltantes){
}
int getCodArt(Faltantes &faltantes){
return faltantes.codArt;
}
float getCantTot(Faltantes &faltantes){
return faltantes.cantTot;
}
float getCantEnv(Faltantes &faltantes){
return faltantes.cantEnv;
}
int getPorc(Faltantes &faltantes){
return faltantes.porc;
}
void setCodArt(Faltantes &faltantes,int codart){
faltantes.codArt=codart;
}
void setCantTot(Faltantes &faltantes,float cantot){
faltantes.cantTot=cantot;
}
void setCantEnv(Faltantes &faltantes,float cantenv){
faltantes.cantEnv=cantenv;
}
void setPorc(Faltantes &faltantes,int porc){
faltantes.porc=porc;
}

int getCodSuc(Faltantes &faltantes){
return faltantes.codsucursal;
}

void setCodSuc(Faltantes &faltantes,int codsuc){
faltantes.codsucursal=codsuc;
}
