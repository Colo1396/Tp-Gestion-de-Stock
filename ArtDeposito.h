#ifndef __ARTDEPOSITO_H__
#define __ARTDEPOSITO_H__
#include "ListaPiso.h"
typedef NodoPiso *PtrNodoPisoDep;
typedef struct ArtDeposito{
int codArt;
PtrNodoPisoDep pisoDep;
};
//********************************
void crearArtDep(ArtDeposito &artDep);
//********************************
void crearArtDep(ArtDeposito &artDep,int codart,PtrNodoPisoDep pisoDep);
//********************************
void destruirArtDep(ArtDeposito &artDep);
//********************************
void setCodArtDep(ArtDeposito &artDep,int codart);
//********************************
void setPisoDep(ArtDeposito &artDep,PtrNodoPisoDep pisoDep);
//********************************
int getCodArtDep(ArtDeposito &artDep);
//********************************
PtrNodoPisoDep getPisoDep(ArtDeposito &artDep);
#endif // __ARTDEPOSITO__H__
