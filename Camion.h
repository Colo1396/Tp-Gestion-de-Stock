#ifndef __CAMION_H__
#define __CAMION_H__

//DEFINICION DE LOS TIPOS DE DATOS
typedef struct Camion{
 int id_camion;
 float carga_total;
 float porcentaje;
};

//DEFINICION DE PRIMITIVAS
//*****************************************************************************************************************
/*      CONSTRUCTOR
*PRE-CONDICIONES: La instancia del TDA Camion no debe estar creada con anterioridad.
                  Constructor solo acepta instancias de tipo Camion.
*POST-CONDICIONES: Instancia del TDA Camion creada y lista para ser utilizada. (VACIA)
*Camion: Estructura sobre la cual se aplica la primitiva.
*/
void crearCamion(Camion &camion);
//*****************************************************************************************************************
/*      CONSTRUCTOR
*PRE-CONDICIONES: La instancia no debe estar creada con anterioridad.
                  Constructor solo acepta instancias de tipo Camion, ademas de un entero y tres float.
*POST-CONDICIONES: Se creara la instancia de tipo Camion con los valores establecidos por el usuario.
*Camion: Estructura en la cual se invoca la primitiva.
*/
void crearCamion(Camion &camion,int idCamion,float Ct,float porc);
//******************************************************************************************************************
/* DESTRUCTOR
*PRE-CONDICIONES: La instancia TDA Camion tiene que estar creada y no tiene que estar destruida.
*POST-CONDICION: La instancia TDA Camion sera destruida y ya no podra utilizarse.
*Camion: Estructura sobre la cual se invoca la primitiva.
*/
void destruirCamion(Camion &camion);
//******************************************************************************************************************
/* GET GETID
*PRE-CONDICION: La instancia Camion debe ser creado y no debe estar destruida.
*POST-CONDICION:Devuelve el atributo id.
*Camion:Instancia sobre la que se invoca la primitiva.
*/
int getId_Camion(Camion &camion);
//******************************************************************************************************************
/* GET CARGA_T
*PRE-CONDICION: La instancia Camion debe ser creado y no debe estar destruida.
*POST-CONDICION:Devuelve el atributo carga_total.
*Camion:Instancia sobre la que se invoca la primitiva.
*/
float getCarga_T(Camion &camion);
//******************************************************************************************************************
/* GET PORCENTAJE
*PRE-CONDICION: La instancia Camion debe ser creado y no debe estar destruida.
*POST-CONDICION:Devuelve el atributo porcentaje.
*Camion:Instancia sobre la que se invoca la primitiva.
*/
float getPorcentaje(Camion &camion);
//******************************************************************************************************************
/* SET ID_CAMION
*PRE-CONDICION:La instancia Camion debe estar creada y no debe estar destruida.
*POST-CONDICION:El atributo idcamion en Camion queda seteado con el idcamion especificado.
*Camion: instancia sobre la que se invoca la primitiva.
*idcamion: valor a asignar de idcamion.
*/
void setId_Camion(Camion &camion,int idCamion);
//******************************************************************************************************************
/* SET CARGA_T
*PRE-CONDICION:La instancia Camion debe estar creada y no debe estar destruida.
*POST-CONDICION:El atributo ct en Camion queda seteado con la carga total especificada.
*Camion: instancia sobre la que se invoca la primitiva.
*ct: valor a asignar de ct.
*/
void setCarga_T(Camion &camion,float cT);
//******************************************************************************************************************
/* SET PORCENTAJE
*PRE-CONDICION:La instancia Camion debe estar creada y no debe estar destruida.
*POST-CONDICION:El atributo porc en Camion queda seteado con el porcentaje especificado.
*Camion: instancia sobre la que se invoca la primitiva.
*porc: valor a asignar de porcentaje.
*/
void setPorcentaje(Camion &camion,float porc);
//*******************************************************************************************************************

#endif // __CAMION_H__
