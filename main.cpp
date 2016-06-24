#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <time.h>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <ctype.h>
#include "FunYProd.h"

using namespace std;

int main(){
//***********INSTANCIAS DE TDA*************
Config configuracion;
constructorConfig(configuracion);

ListaArt listArt;//lista de articulos para cargar el maestro
crearListaArt(listArt);

ListaCalle listaCalle;//lista de calles la cual contendra lista de pisos y pila de ubicaciones con diferentes articulos
crearListaCalle(listaCalle);

ListaArtDeposito listaArtDep;//lista de articulos cargados en el deposito
crearListaArtDeposito(listaArtDep);

ListaFaltante listaFaltante;//lista de articulos faltanes con las que no se pudieron responder a las solicitudes
crearListaFaltante(listaFaltante);

Reposicion reposicion;//instacia de ingreso,estructura para almacenar datos de ingreso
crearReposicion(reposicion);

Solicitud solicitud;//instancia de solicitud,estructura para almacenar datos de SOLICITUD
crearSolicitud(solicitud);

Camion camion;//camion que lleve la solicitud
crearCamion(camion);

PilaCamion pilaCamion;//pila de camiones q fueron despachados
crearPila(pilaCamion);

ListaPesoAcum listaPesoAcum;
crearListaPesoAcum(listaPesoAcum);

ListaVentas listaVentas;
crearListaVenta(listaVentas);
//*********************************************//

//***************CARGA CONFIGURACION************
cargaConfig(configuracion);//CARGA ARCHIVO CONFIGURACION
//**********************************************

//************CARGA MASTER******************************
cargaMaster(listArt);//CARGA EL MASTER DE ARTICULOS
//******************************************************


//***********COMPARACION*******************
FILE *ptrING; //Puntero de archivo INGRESO.
    FILE *ptrSOL; //Puntero de archivo SOLICITUDES.
    ptrING=fopen("ingresos.db","r"); // LOS ABRIMOS EN EL MAIN PARA CERRARLOS
    ptrSOL=fopen("solicitudes.db","r"); // DENTRO DEL MISMO.
    int contador=0;
    int paso=0;
    bool sinfin=true;
    //A modo de prueba, leemos la primer linea de cada archivo.
while(sinfin==true){
while (!feof(ptrING) && !feof(ptrSOL))  {
    contador++;
    paso=calcularTiempo(ptrING,ptrSOL,solicitud,reposicion);
    if(paso==1){

        ingresoStock(configuracion,listaCalle,listArt,listaArtDep,reposicion);
    }
    else{

        solicitudStock(configuracion,listaCalle,listArt,listaArtDep,listaFaltante,solicitud,camion,pilaCamion,listaPesoAcum,listaVentas); //listaVentast
    }

cout <<" "<< contador << endl;
}

if (!feof(ptrSOL) && feof(ptrING)){

        contador++;

        cout <<" "<< contador << endl;
        leerSolicitud(ptrSOL,solicitud);
        solicitudStock(configuracion,listaCalle,listArt,listaArtDep,listaFaltante,solicitud,camion,pilaCamion,listaPesoAcum,listaVentas); //listaVentast
    }


if (feof(ptrSOL) && !feof(ptrING)){
        contador++;
        cout <<" "<< contador << endl;
        leerIngreso(ptrING,reposicion);
        ingresoStock(configuracion,listaCalle,listArt,listaArtDep,reposicion);
}


if((feof(ptrING)) && (feof(ptrSOL))){
     sinfin=false;
}

}//WHILE SINFIN
    printf("TERMINO EL PROGRAMA. Cerrando archivos\n");
    fclose(ptrING);// CERRAMOS LOS ARCHIVOS AL FINAL DEL PROGRAMA
    fclose(ptrSOL);// //
    printf("Archivos cerrados\n");
system("cls");

//***********************************************

//********ARCHIVOS DE TEXTO*********
crearSaldosDetalladosTxt(listaCalle);

ordenamientofaltantes(listaFaltante);

crearPesoAcumulado(listaCalle,listaPesoAcum);
ordenamientoSaldosagrupados(listaPesoAcum);
crearPesoAcumuladoTxt(listaPesoAcum);

ordenarlista(listaVentas);
crearVentaTxt(listaVentas);

crearCamionTxt(pilaCamion);

crarFaltanteTxt(listaFaltante);
//*************************************
    eliminarLista(listaCalle);
	eliminarLista(listaArtDep);
	eliminarLista(listArt);
	eliminarLista(listaPesoAcum);
	eliminarLista(listaFaltante);
	eliminarLista(listaVentas);
	destruir(pilaCamion);
    return 0;
}
