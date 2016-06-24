#ifndef __FALTANTES_H__
#define __FALTANTES_H__

//DEFINICION DE LOS TIPOS DE DATOS
typedef struct Faltantes{
int codsucursal;
int codArt;
float cantTot;
float cantEnv;
int porc;
};

//DEFINICION DE PRIMITIVAS
//*****************************************************************************************************************
/*      CONSTRUCTOR
*PRE-CONDICIONES: La instancia del TDA Faltantes no debe estar creada con anterioridad.
                 Constructor solo acepta instancias de tipo Faltantes.
*POST-CONDICIONES: Instancia del TDA Faltantes creada y lista para ser utilizada. (VACIA)
*Faltantes: Estructura sobre la cual se aplica la primitiva.
*/
void crearFaltante(Faltantes &faltantes);
//*****************************************************************************************************************
/*      CONSTRUCTOR
*PRE-CONDICIONES: La instancia no debe estar creada con anterioridad.
                  Constructor solo acepta instancias de tipo Faltantes, ademas de tres enteros y dos float.
*POST-CONDICIONES: Se creara la instancia de tipo Faltantes con los valores establecidos por el usuario.
*Faltantes: Estructura en la cual se invoca la primitiva.
*/
void crearFaltante(Faltantes &faltantes,int codSucursal,int codart,float cantot,float cantenv,int porc);
//*******************************************************************************************************************
/* DESTRUCTOR
*PRE-CONDICIONES: La instancia TDA Faltantes tiene que estar creada y no tiene que estar destruida.
* POST-CONDICION: La instancia TDA Faltantes sera destruida y ya no podra utilizarse.
* Faltantes: Estructura sobre la cual se invoca la primitiva.
*/
void destructorFaltantes(Faltantes &faltantes);
//*******************************************************************************************************************
/* GET CODART
*PRE-CONDICION: La instancia Faltantes debe ser creado y no debe estar destruida.
*POST-CONDICION:Devuelve el atributo codart de Faltantes.
*Faltantes:Instancia sobre la que se invoca la primitiva.
*/
int getCodArt(Faltantes &faltantes);
//*******************************************************************************************************************
/* GET CODSUCURSAL
*PRE-CONDICION: La instancia Faltantes debe ser creado y no debe estar destruida.
*POST-CONDICION:Devuelve el atributo codsucursal de Faltantes.
*Faltantes:Instancia sobre la que se invoca la primitiva.
*/
int getCodsucursal(Faltantes &faltantes);
//*******************************************************************************************************************
/* GET CANTTOT
*PRE-CONDICION: La instancia Faltantes debe ser creado y no debe estar destruida.
*POST-CONDICION:Devuelve el atributo cantTot de Faltantes.
*Faltantes:Instancia sobre la que se invoca la primitiva.
*/
float getCantTot(Faltantes &faltantes);
//*******************************************************************************************************************
/* GET CANTENV
*PRE-CONDICION: La instancia Faltantes debe ser creado y no debe estar destruida.
*POST-CONDICION:Devuelve el atributo cantenv de Faltantes.
*Faltantes:Instancia sobre la que se invoca la primitiva.
*/
float getCantEnv(Faltantes &faltantes);
//*******************************************************************************************************************
/* GET PORC
*PRE-CONDICION: La instancia Faltantes debe ser creado y no debe estar destruida.
*POST-CONDICION:Devuelve el atributo porc de Faltantes.
*Faltantes:Instancia sobre la que se invoca la primitiva.
*/
int getPorc(Faltantes &faltantes);
//*****************************************************************************************************************
/* SET DEL CODSUCURSAL
*PRE-CONDICION:La instancia Faltantes debe estar creada y no debe estar destruida.
*POST-CONDICION:El atributo codSucursal en Faltantes queda seteado con el codsucursal especificado.
*Faltantes: instancia sobre la que se invoca la primitiva.
*codsucursal: valor a asignar de codSucursal.
*/
void setCodsuccursal(Faltantes &faltante,int codSucursal);
//*****************************************************************************************************************
/* SET DEL CODART
*PRE-CONDICION:La instancia Faltantes debe estar creada y no debe estar destruida.
*POST-CONDICION:El atributo codart en Faltantes queda seteado con el codart especificado.
*Faltantes: instancia sobre la que se invoca la primitiva.
*codart: valor a asignar de codArt.
*/
void setCodArt(Faltantes &faltantes,int codart);
//*****************************************************************************************************************
/* SET DEL CANTTOT
*PRE-CONDICION:La instancia Faltantes debe estar creada y no debe estar destruida.
*POST-CONDICION:El atributo cantot en Faltantes queda seteado con el canttot especificado.
*Faltantes: instancia sobre la que se invoca la primitiva.
*cantot: valor a asignar de cantot.
*/
void setCantTot(Faltantes &faltantes,float cantot);
//*****************************************************************************************************************
/* SET DE CANTENV
*PRE-CONDICION:La instancia Faltantes debe estar creada y no debe estar destruida.
*POST-CONDICION:El atributo cantenv en Faltantes queda seteado con el cantenv especificado.
*Faltantes: instancia sobre la que se invoca la primitiva.
*cantenv: valor a asignar de cantenv.
*/
void setCantEnv(Faltantes &faltantes,float cantenv);
//*****************************************************************************************************************
/* SET DEL PORC
*PRE-CONDICION:La instancia Faltantes debe estar creada y no debe estar destruida.
*POST-CONDICION:El atributo porc en Faltantes queda seteado con el porc especificado.
*Faltantes: instancia sobre la que se invoca la primitiva.
*porc: valor a asignar de porc.
*/
void setPorc(Faltantes &faltantes,int porc);
//******************************************************************************************************************
#endif // __FALTANTES_H__
