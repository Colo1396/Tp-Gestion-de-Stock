#ifndef __ARTDEPOSITO_H__
#define __ARTDEPOSITO_H__
#include "ListaPiso.h"

//TIPO DE INFORMACION CONTENIDA EN LA ESTRUCTURA NODOPISO IDENTIFICADA COMO PTRNODOPISODEP
typedef NodoPiso *PtrNodoPisoDep;

//DEFINICION DE LOS TIPOS DE DATOS
typedef struct ArtDeposito{
int codArt;
PtrNodoPisoDep pisoDep;
};


//DEFINICION DE PRIMITIVAS
//*****************************************************************************************************************
/*      CONSTRUCTOR
*PRE-CONDICIONES: La instancia del TDA ArtDeposito no debe estar creada con anterioridad.
                  Constructor solo acepta instancias de tipo ArtDeposito.
*POST-CONDICIONES: Instancia del TDA ArtDeposito creada y lista para ser utilizada. (VACIA)
*ArtDeposito: Estructura sobre la cual se aplica la primitiva.
*/
void crearArtDep(ArtDeposito &artDep);
//*****************************************************************************************************************
/*      CONSTRUCTOR
*PRE-CONDICIONES: La instancia no debe estar creada con anterioridad.
                  Constructor solo acepta instancias de tipo ArtDeposito, ademas de un entero y un puntero.
*POST-CONDICIONES: Se creara la instancia de tipo ArtDeposito con los valores establecidos por el usuario.
*ArtDeposito: Estructura en la cual se invoca la primitiva.
*/
void crearArtDep(ArtDeposito &artDep,int codart,PtrNodoPisoDep pisoDep);
//******************************************************************************************************************
/* DESTRUCTOR
*PRE-CONDICIONES: La instancia TDA ArtDeposito tiene que estar creada y no tiene que estar destruida.
*POST-CONDICION: La instancia TDA ArtDeposito sera destruida y ya no podra utilizarse.
*ArtDeposito: Estructura sobre la cual se invoca la primitiva.
*/
void destruirArtDep(ArtDeposito &artDep);
//******************************************************************************************************************
/* SET DEL CODARTDEP
*PRE-CONDICION:La instancia ArtDeposito debe estar creada y no debe estar destruida.
*POST-CONDICION:El atributo codart en ArtDeposito queda seteado con el codigo especificado.
*ArtDeposito: instancia sobre la que se invoca la primitiva.
*codart: valor a asignar de codArt del articulo.
*/
void setCodArtDep(ArtDeposito &artDep,int codart);
//******************************************************************************************************************
/* SET PISODEP
*PRE-CONDICION:La instancia ArtDeposito debe estar creada y no debe estar destruida.
*POST-CONDICION:El puntero piso en ArtDeposito queda seteado con el piso especificado.
*ArtDeposito: instancia sobre la que se invoca la primitiva.
*pisoDep: valor a asignar del piso.
*/
void setPisoDep(ArtDeposito &artDep,PtrNodoPisoDep pisoDep);
//******************************************************************************************************************
/* GET CODARTDEP
*PRE-CONDICION: La instancia ArtDeposito debe ser creado y no debe estar destruida.
*POST-CONDICION:Devuelve el atributo codart de Articulo.
*ArtDeposito:Instancia sobre la que se invoca la primitiva.
*/
int getCodArtDep(ArtDeposito &artDep);
//******************************************************************************************************************
/* GET PISODEP
*PRE-CONDICION: la instancia stock debe ser creado y no debe estar destruida..
*POST-CONDICION:  devuelve el puntero al piso donde del articulo indicado en ArtDeposito
*ArtDeposito: instancia sobre la que se invoca la primitiva
*/
PtrNodoPisoDep getPisoDep(ArtDeposito &artDep);
//******************************************************************************************************************

#endif // __ARTDEPOSITO__H__
