#ifndef __REPOSICION_H__
#define __REPOSICION_H__

typedef struct Reposicion{
int cod_articulo;
int cantidad;
char hora[150];
};
//********************************
void crearReposicion(Reposicion &reposicion);
//********************************
void crearReposicion(Reposicion &reposicion,int CodArt,int Cant,char hora[]);
//********************************
void destruirReposicion(Reposicion &reposicion);
//********************************
int getCodArt(Reposicion &reposicion);
//********************************
int getCant(Reposicion &reposicion);
//********************************
char* getHora(Reposicion &reposicion);
//********************************
void setCodArt(Reposicion &reposicion,int codart);
//********************************
void setCant(Reposicion &reposicion,int cant);

#endif // __REPOSICION_H__
