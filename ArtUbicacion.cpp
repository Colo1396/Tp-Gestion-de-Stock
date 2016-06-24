#include "ArtUbicacion.h"
//**********************
void constructorArtUb(ArtUbicacion &artUbicacion){
Articulo artAux;
constructorArt(artAux);
artUbicacion.datoArt=artAux;
artUbicacion.c=0;
artUbicacion.p=0;
artUbicacion.u=0;
artUbicacion.cantArtUb=0;
}
//**********************
void constructorArtUb(ArtUbicacion &artUbicacion,int c,int p,int u,float cantArtUb){
Articulo artAux;
constructorArt(artAux);
artUbicacion.datoArt=artAux;
artUbicacion.c=c;
artUbicacion.p=p;
artUbicacion.u=u;
artUbicacion.cantArtUb=cantArtUb;
}
//**********************
void constructorArtUb(ArtUbicacion &artUbicacion,Art &datoArtaux,int c,int p,int u,float cantArtUb){
artUbicacion.datoArt=datoArtaux;
artUbicacion.c=c;
artUbicacion.p=p;
artUbicacion.u=u;
artUbicacion.cantArtUb=cantArtUb;
}
//**********************
void setC(ArtUbicacion &artUbicacion,int c){
    artUbicacion.c=c;
}
//**********************
void setP(ArtUbicacion &artUbicacion,int p){
    artUbicacion.p=p;
}
//**********************
void setU(ArtUbicacion &artUbicacion,int u){
    artUbicacion.u=u;
}
//**********************
void setDatoArt(ArtUbicacion &artUbicacion,Art &datoArt){
    artUbicacion.datoArt=datoArt;
}
//**********************
void setCantArtUb(ArtUbicacion &artUbicacion,float cantArtUb){
    artUbicacion.cantArtUb=cantArtUb;
}
//**********************
int getC(ArtUbicacion &artUbicacion){
    return artUbicacion.c;
}
//**********************
int getP(ArtUbicacion &artUbicacion){
    return artUbicacion.p;
}
//**********************
int getU(ArtUbicacion &artUbicacion){
    return artUbicacion.u;
}
//**********************
Art getDatoArt(ArtUbicacion &artUbicacion){
    return artUbicacion.datoArt;
}
//**********************
float getCantArtUb(ArtUbicacion &artUbicacion){
    return artUbicacion.cantArtUb;
}
//**********************
void destructorArtUb(ArtUbicacion &artUbicacion){
    destructorArt(artUbicacion.datoArt);
}
