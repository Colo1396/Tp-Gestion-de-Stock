#ifndef __PESOACUMULADO_H__
#define __PESOACUMULADO_H__
typedef struct PesoAcum{
int codArt;
float cant;
};
//*****************
void crearPesoAcum(PesoAcum &pesoAcum);
//*****************
void crearPesoAcum(PesoAcum &pesoAcum,int codart,float cant);
//*****************
void destruirPesoAcum(PesoAcum &pesoAcum);
//*****************
void setCodArt(PesoAcum &pesoAcum,int codart);
//*****************
void setCant(PesoAcum &pesoAcum,float cant);
//*****************
int getCodArt(PesoAcum &pesoAcum);
//*****************
float getCant(PesoAcum &pesoAcum);


#endif // __PESOACUMULADO_H__
