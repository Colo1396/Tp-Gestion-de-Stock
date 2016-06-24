#ifndef __ARTUBICACION_H__
#define __ARTUBICACION_H__
#include "Articulo.h"

//TIPO DE INFORMACION CONTENIDA EN LA ESTRUCTURA ARTICULO IDENTIFICADA COMO ART
typedef Articulo Art;

//DEFINICION DE LOS TIPOS DE DATOS
typedef struct ArtUbicacion{
Art datoArt;
int c;
int p;
int u;
float cantArtUb;
};

//DEFINICION DE PRIMITIVAS
//*****************************************************************************************************************
/*      CONSTRUCTOR
*PRE-CONDICIONES: La instancia del TDA ArtUbicacion no debe estar creada con anterioridad.
                  Constructor solo acepta instancias de tipo Artubicacion.
*POST-CONDICIONES: Instancia del TDA ArtUbicacion creada y lista para ser utilizada. (VACIA)
*ArtUbicacion: Estructura sobre la cual se aplica la primitiva.
*/
void constructorArtUb(ArtUbicacion &artUbicacion);
//*****************************************************************************************************************
/*      CONSTRUCTOR
*PRE-CONDICIONES: La instancia no debe estar creada con anterioridad.
                  Constructor solo acepta instancias de tipo ArtUbicacion, ademas de tres enteros y un float.
*POST-CONDICIONES: Se creara la instancia de tipo ArtUbicacion con los valores establecidos por el usuario.
*ArtUbicacion: Estructura en la cual se invoca la primitiva.
*/
void constructorArtUb(ArtUbicacion &artUbicacion,int c,int p,int u,float cantArtUb);
//*****************************************************************************************************************
/*      CONSTRUCTOR
*PRE-CONDICIONES: La instancia no debe estar creada con anterioridad.
                  Constructor solo acepta instancias de tipo ArtUbicacion, ademas de tres enteros y un float.
*POST-CONDICIONES: Se creara la instancia de tipo ArtUbicacion con los valores establecidos por el usuario y un articulo.
*ArtUbicacion: Estructura en la cual se invoca la primitiva.
*/
void constructorArtUb(ArtUbicacion &artUbicacion,Art &datoArtaux,int c,int p,int u,float cantArtUb);
//******************************************************************************************************************
/* SET C
*PRE-CONDICION:La instancia ArtUbicacion debe estar creada y no debe estar destruida.
*POST-CONDICION:El atributo c en ArtUbicacion queda seteado con el c (calle) especificado.
*ArtUbicacion: instancia sobre la que se invoca la primitiva.
*c: valor a asignar de c (calle).
*/
void setC(ArtUbicacion &artUbicacion,int c);
//******************************************************************************************************************
/* SET P
*PRE-CONDICION:La instancia ArtUbicacion debe estar creada y no debe estar destruida.
*POST-CONDICION:El atributo p en ArtUbicacion queda seteado con el p (piso) especificado.
*ArtUbicacion: instancia sobre la que se invoca la primitiva.
*p: valor a asignar de p(piso).
*/
void setP(ArtUbicacion &artUbicacion,int p);
//******************************************************************************************************************
/* SET U
*PRE-CONDICION:La instancia ArtUbicacion debe estar creada y no debe estar destruida.
*POST-CONDICION:El atributo u en ArtUbicacion queda seteado con el u (ubicacion) especificado.
*ArtUbicacion: instancia sobre la que se invoca la primitiva.
*u: valor a asignar de u(ubicacion).
*/
void setU(ArtUbicacion &artUbicacion,int u);
//******************************************************************************************************************
/* SET DATOART
*PRE-CONDICION:La instancia ArtUbicacion debe estar creada y no debe estar destruida.
*POST-CONDICION:El atributo datoArt en ArtUbicacion queda seteado con el datoArt especificado.
*ArtUbicacion: instancia sobre la que se invoca la primitiva.
*datoArt: valor a asignar de datoArt.
*/
void setDatoArt(ArtUbicacion &artUbicacion,Art &datoArt);
//******************************************************************************************************************
/* SET CANTARTUB
*PRE-CONDICION:La instancia ArtUbicacion debe estar creada y no debe estar destruida.
*POST-CONDICION:El atributo cantArtUb en ArtUbicacion queda seteado con el cantArtUb especificado.
*ArtUbicacion: instancia sobre la que se invoca la primitiva.
*cantArtUb: valor a asignar de cantArtUb.
*/
void setCantArtUb(ArtUbicacion &artUbicacion,float cantArtUb);
//******************************************************************************************************************
/* GET C
*PRE-CONDICION: La instancia ArtDUbicacion debe ser creado y no debe estar destruida.
*POST-CONDICION:Devuelve el atributo c.
*ArtDeposito:Instancia sobre la que se invoca la primitiva.
*/
int getC(ArtUbicacion &artUbicacion);
//******************************************************************************************************************
/* GET P
*PRE-CONDICION: La instancia ArtDUbicacion debe ser creado y no debe estar destruida.
*POST-CONDICION:Devuelve el atributo p.
*ArtDeposito:Instancia sobre la que se invoca la primitiva.
*/
int getP(ArtUbicacion &artUbicacion);
//******************************************************************************************************************
/* GET U
*PRE-CONDICION: La instancia ArtDUbicacion debe ser creado y no debe estar destruida.
*POST-CONDICION:Devuelve el atributo u.
*ArtDeposito:Instancia sobre la que se invoca la primitiva.
*/
int getU(ArtUbicacion &artUbicacion);
//******************************************************************************************************************
/* GET DATOART
*PRE-CONDICION: La instancia ArtDUbicacion debe ser creado y no debe estar destruida.
*POST-CONDICION:Devuelve el atributo datoart.
*ArtDeposito:Instancia sobre la que se invoca la primitiva.
*/
Art getDatoArt(ArtUbicacion &artUbicacion);
//******************************************************************************************************************
/* GET CANTARTUB
*PRE-CONDICION: La instancia ArtDUbicacion debe ser creado y no debe estar destruida.
*POST-CONDICION:Devuelve el atributo cantArtUb.
*ArtDeposito:Instancia sobre la que se invoca la primitiva.
*/
float getCantArtUb(ArtUbicacion &artUbicacion);
//******************************************************************************************************************
/* DESTRUCTOR
*PRE-CONDICIONES: La instancia TDA ArtUbicacion tiene que estar creada y no tiene que estar destruida.
*POST-CONDICION: La instancia TDA ArtUbicacion sera destruida y ya no podra utilizarse.
*ArtUbicacion: Estructura sobre la cual se invoca la primitiva.
*/
void destructorArtUb(ArtUbicacion &artUbicacion);
//******************************************************************************************************************

#endif // __ARTUBICACION_H__
