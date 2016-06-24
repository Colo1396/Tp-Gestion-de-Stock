#ifndef __ARTICULO_H__
#define __ARTICULO_H__

typedef struct Articulo{
int codart;
float precio;
char descripcion[30];
};
//**********************
void constructorArt(Articulo &articulo);
//**********************
void constructorArt(Articulo &articulo,int codart,float precio, char descripcion[]);
//**********************
void setCodArt(Articulo &articulo,int codart);
//**********************
void setPrecio(Articulo &articulo,float precio);
//**********************
void setDescripcion(Articulo &articulo,char descripcion);
//**********************
int getCodArt(Articulo &articulo);
//**********************
float getPrecio(Articulo &articulo);
//**********************
char* getDescripcion(Articulo &articulo);
//**********************
void destructorArt(Articulo &articulo);
#endif // __ARTICULO_H__
