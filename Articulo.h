//TDA DE LOS ARTICULOS
#ifndef __ARTICULO_H__
#define __ARTICULO_H__

//DEFINICION DE LOS TIPOS DE DATOS
typedef struct Articulo{
int codart;
float precio;
char descripcion[30];
};


//DEFINICION DE PRIMITIVAS
//*****************************************************************************************************************
/*      CONSTRUCTOR
*PRE-CONDICIONES: La instancia del TDA Articulo no debe estar creada con anterioridad.
                 Constructor solo acepta instancias de tipo Articulo.
*POST-CONDICIONES: Instancia del TDA Articulo creada y lista para ser utilizada. (VACIA)
*Articulo: Estructura sobre la cual se aplica la primitiva.
*/

void constructorArt(Articulo &articulo);
//*****************************************************************************************************************
/*      CONSTRUCTOR
*PRE-CONDICIONES: La instancia no debe estar creada con anterioridad.
                  Constructor solo acepta instancias de tipo Articulo, ademas de un char, un entero y un float.
*POST-CONDICIONES: Se creara la instancia de tipo Articulo con los valores establecidos por el usuario.
*Articulo: Estructura en la cual se invoca la primitiva.
*/
void constructorArt(Articulo &articulo,int codart,float precio, char descripcion[]);
//*****************************************************************************************************************
/* SET DEL CODART
*PRE-CONDICION:La instancia Articulo debe estar creada y no debe estar destruida.
*POST-CONDICION:El atributo codart en Articulo queda seteado con el codigo especificado.
*Articulo: instancia sobre la que se invoca la primitiva.
*codart: valor a asignar de codArt del articulo.
*/
void setCodArt(Articulo &articulo,int codart);
//******************************************************************************************************************
/* SET DEL PRECIO
*PRE-CONDICION:La instancia Articulo debe estar creada y no debe estar destruida.
*POST-CONDICION:El atributo precio en Articulo queda seteado con el precio especificado.
*Articulo: instancia sobre la que se invoca la primitiva.
*precio: valor a asignar de precio del articulo.
*/

void setPrecio(Articulo &articulo,float precio);
//******************************************************************************************************************
/* SET DE DESCRIPCION
*PRE-CONDICION:La instancia Articulo debe estar creada y no debe estar destruida.
*POST-CONDICION:El atributo descripcion en Articulo queda seteado con la descripcion especificada.
*Articulo: instancia sobre la que se invoca la primitiva.
*descripcion: valor a asignar de descripcion del articulo.
*/
void setDescripcion(Articulo &articulo,char descripcion);
//*******************************************************************************************************************
/* GET CODART
*PRE-CONDICION: La instancia articulo debe ser creado y no debe estar destruida.
*POST-CONDICION:Devuelve el atributo codart de Articulo.
*Articulo:Instancia sobre la que se invoca la primitiva.
*/
int getCodArt(Articulo &articulo);
//*******************************************************************************************************************
/* GET PRECIO
*PRE-CONDICION: La instancia articulo debe ser creado y no debe estar destruida.
*POST-CONDICION:Devuelve el atributo precio de Articulo.
*Articulo:Instancia sobre la que se invoca la primitiva.
*/
float getPrecio(Articulo &articulo);
//*******************************************************************************************************************
/* GET DESCRIPCION
*PRE-CONDICION: La instancia articulo debe ser creado y no debe estar destruida..
*POST-CONDICION:Devuelve el atributo descripcion de Articulo
*Articulo:Instancia sobre la que se invoca la primitiva
*/
char* getDescripcion(Articulo &articulo);
//*******************************************************************************************************************
/* DESTRUCTOR
*PRE-CONDICIONES: La instancia TDA Articulo tiene que estar creada y no tiene que estar destruida.
* POST-CONDICION: La instancia TDA Articulo sera destruida y ya no podra utilizarse.
* Articulo: Estructura sobre la cual se invoca la primitiva.
*/
void destructorArt(Articulo &articulo);
//*******************************************************************************************************************

#endif // __ARTICULO_H__
