#ifndef __SOLICITUD_H__
#define __SOLICITUD_H__

typedef struct Solicitud{
int cod_suc;
int cod_articulo;
int cantidad;
char hora[150];
};
//********************************
void crearSolicitud(Solicitud &solicitud);
//********************************
void crearSolicitud(Solicitud &solicitud,int CodSuc,int CodArt,int cant,char hora[]);
//********************************
void destruirSolicitud(Solicitud &solicitud);
//********************************
int getCodSuc(Solicitud &solicitud);
//********************************
int getCodArt(Solicitud &solicitud);
//********************************
int getCant(Solicitud &solicitud);
//********************************
char* getHora(Solicitud &solicitud);
//********************************
void setCodSuc(Solicitud &solicitud,int CodSuc);
//********************************
void setCodArt(Solicitud &solicitud,int CodArt);
//********************************
void setCantidad(Solicitud &Solicitud,int Cant);
//********************************
void setHora(Solicitud &solicitud,char h[]);

#endif // __SOLICITUD_H__
