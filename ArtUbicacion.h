#ifndef __ARTUBICACION_H__
#define __ARTUBICACION_H__
#include "Articulo.h"

typedef Articulo Art;

typedef struct ArtUbicacion{
Art datoArt;
int c;
int p;
int u;
float cantArtUb;
};
//**********************
void constructorArtUb(ArtUbicacion &artUbicacion);
//**********************
void constructorArtUb(ArtUbicacion &artUbicacion,int c,int p,int u,float cantArtUb);
//**********************
void constructorArtUb(ArtUbicacion &artUbicacion,Art &datoArtaux,int c,int p,int u,float cantArtUb);
//**********************
void setC(ArtUbicacion &artUbicacion,int c);
//**********************
void setP(ArtUbicacion &artUbicacion,int p);
//**********************
void setU(ArtUbicacion &artUbicacion,int u);
//**********************
void setDatoArt(ArtUbicacion &artUbicacion,Art &datoArt);
//**********************
void setCantArtUb(ArtUbicacion &artUbicacion,float cantArtUb);
//**********************
int getC(ArtUbicacion &artUbicacion);
//**********************
int getP(ArtUbicacion &artUbicacion);
//**********************
int getU(ArtUbicacion &artUbicacion);
//**********************
Art getDatoArt(ArtUbicacion &artUbicacion);
//**********************
float getCantArtUb(ArtUbicacion &artUbicacion);
//**********************
void destructorArtUb(ArtUbicacion &artUbicacion);

#endif // __ARTUBICACION_H__
