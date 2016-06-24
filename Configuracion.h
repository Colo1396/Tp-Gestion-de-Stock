#ifndef __CONFIGURACION_H__
#define __CONFIGURACION_H__

//DEFINICION DE LOS TIPOS DE DATOS
 typedef struct Config{
 int configP;
 int configU;
 float configKC;
 };

//DEFINICION DE PRIMITIVAS
//*****************************************************************************************************************
/*      CONSTRUCTOR
*PRE-CONDICIONES: La instancia del TDA Config no debe estar creada con anterioridad.
                  Constructor solo acepta instancias de tipo Config.
*POST-CONDICIONES: Instancia del TDA Config creada y lista para ser utilizada. (VACIA)
*Config: Estructura sobre la cual se aplica la primitiva.
*/
void constructorConfig(Config &config);
//*****************************************************************************************************************
/*      CONSTRUCTOR
*PRE-CONDICIONES: La instancia no debe estar creada con anterioridad.
                  Constructor solo acepta instancias de tipo Config, ademas de dos entero y un float.
*POST-CONDICIONES: Se creara la instancia de tipo Config con los valores establecidos por el usuario.
*Config: Estructura en la cual se invoca la primitiva.
*/
void constructorConfig(Config &config,int p,int u, float kc);
//******************************************************************************************************************
/* SET CONFIGP
*PRE-CONDICION:La instancia Config debe estar creada y no debe estar destruida.
*POST-CONDICION:El atributo p en Config queda seteado con la cantidad de pisos especificado.
*Config: instancia sobre la que se invoca la primitiva.
*p: valor a asignar de pisos.
*/
void setConfigP(Config &config,int p);
//******************************************************************************************************************
/* SET CONFIGU
*PRE-CONDICION:La instancia Config debe estar creada y no debe estar destruida.
*POST-CONDICION:El atributo u en Config queda seteado con la cantidad de ubicaciones especificado.
*Config: instancia sobre la que se invoca la primitiva.
*u: valor a asignar de ubicaciones.
*/
void setConfigU(Config &config,int u);
//******************************************************************************************************************
/* SET CONFIGKC
*PRE-CONDICION:La instancia Config debe estar creada y no debe estar destruida.
*POST-CONDICION:El atributo kc en Config queda seteado con la cantidad de kilos por camion especificado.
*Config: instancia sobre la que se invoca la primitiva.
*kc: valor a asignar de kilos por camion.
*/
void setConfigKC(Config &config,float kc);
//******************************************************************************************************************
/* GET CONFIGP
*PRE-CONDICION: La instancia Config debe ser creado y no debe estar destruida.
*POST-CONDICION:Devuelve el atributo p.
*Config:Instancia sobre la que se invoca la primitiva.
*/
int getConfigP(Config &config);
//******************************************************************************************************************
/* GET CONFIGU
*PRE-CONDICION: La instancia Config debe ser creado y no debe estar destruida.
*POST-CONDICION:Devuelve el atributo u.
*Config:Instancia sobre la que se invoca la primitiva.
*/
int getConfigU(Config &config);
//******************************************************************************************************************
/* GET CONFIGKC
*PRE-CONDICION: La instancia Config debe ser creado y no debe estar destruida.
*POST-CONDICION:Devuelve el atributo kc.
*Config:Instancia sobre la que se invoca la primitiva.
*/
float getConfigKC(Config &config);
//******************************************************************************************************************
/* DESTRUCTOR
*PRE-CONDICIONES: La instancia TDA Config tiene que estar creada y no tiene que estar destruida.
*POST-CONDICION: La instancia TDA Config sera destruida y ya no podra utilizarse.
*Config: Estructura sobre la cual se invoca la primitiva.
*/
void destructorConfig(Config &config);
//******************************************************************************************************************


#endif // __CONFIGURACION_H__
