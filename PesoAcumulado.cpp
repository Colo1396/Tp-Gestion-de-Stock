
#include "PesoAcumulado.h"
//*****************
void crearPesoAcum(PesoAcum &pesoAcum){
pesoAcum.codArt=0;
pesoAcum.cant=0;
}
//*****************
void crearPesoAcum(PesoAcum &pesoAcum,int codart,float cant){
pesoAcum.codArt=codart;
pesoAcum.cant=cant;
}
//*****************
void destruirPesoAcum(PesoAcum &pesoAcum){
}
//*****************
void setCodArt(PesoAcum &pesoAcum,int codart){
pesoAcum.codArt=codart;
}
//*****************
void setCant(PesoAcum &pesoAcum,float cant){
pesoAcum.cant=cant;
}
//*****************
int getCodArt(PesoAcum &pesoAcum){
return pesoAcum.codArt;
}
//*****************
float getCant(PesoAcum &pesoAcum){
return pesoAcum.cant;
}
