#include "ArtDeposito.h"
//********************************
void crearArtDep(ArtDeposito &artDep){
artDep.codArt=0;
//artDep.pisoDep=NULL;
}
//********************************
void crearArtDep(ArtDeposito &artDep,int codart,PtrNodoPisoDep pisoDep){
artDep.codArt=codart;
artDep.pisoDep=pisoDep;
}
//********************************
void destruirArtDep(ArtDeposito &artDep){
}
//********************************
void setCodArtDep(ArtDeposito &artDep,int codart){
artDep.codArt=codart;
}
//********************************
void setPisoDep(ArtDeposito &artDep,PtrNodoPisoDep pisoDep){
artDep.pisoDep=pisoDep;
}
//********************************
int getCodArtDep(ArtDeposito &artDep){
return artDep.codArt;
}
//********************************
PtrNodoPisoDep getPisoDep(ArtDeposito &artDep){
return artDep.pisoDep;
}
