#include "Articulo.h"
#include <stdio.h>
#include <string.h>
//**********************
void constructorArt(Articulo &articulo){
articulo.codart=0;
articulo.precio=0;
strcpy(articulo.descripcion,"-");
}
//**********************
void constructorArt(Articulo &articulo,int codart,float precio, char d[]){
articulo.codart=codart;
articulo.precio=precio;
strcpy(articulo.descripcion,d);
}
//**********************
void setCodArt(Articulo &articulo,int codart){
articulo.codart=codart;
}
//**********************
void setPrecio(Articulo &articulo,float precio){
articulo.precio=precio;
}
//**********************
void setDescripcion(Articulo &articulo,char d[]){
strcpy(articulo.descripcion,d);
}
//**********************
int getCodArt(Articulo &articulo){
return articulo.codart;
}
//**********************
float getPrecio(Articulo &articulo){
return articulo.precio;
}
//**********************
char* getDescripcion(Articulo &articulo){
char* c;
return c=articulo.descripcion;
}
//**********************
void destructorArt(Articulo &articulo){
}
