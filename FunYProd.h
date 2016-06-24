#ifndef __FUNYPROD_H__
#define __FUNYPROD_H__
#include "ArtDeposito.h"
#include "Articulo.h"
#include "ArtUbicacion.h"
#include "Camion.h"
#include "Configuracion.h"
#include "Faltantes.h"
#include "FunYProd.h"
#include "LDeposito.h"
#include "ListaArticulo.h"
#include "ListaCalle.h"
#include "ListaFaltantes.h"
#include "ListaPesoAcumulado.h"
#include "ListaPiso.h"
#include "ListaVentas.h"
#include "PesoAcumulado.h"
#include "PilaArtUb.h"
#include "PilaCamion.h"
#include "Reposicion.h"
#include "Solicitud.h"
#include "Ventas.h"


//******CARGA MASTER***************************************
void cargaMaster(ListaArt &listArt);
void cargaConfig(Config &config);
//****COMPARACION******************************************
void leerIngreso(FILE *ptrING,Reposicion &reposicion);
void leerSolicitud(FILE *ptrSOL,Solicitud &solicitud);
int calcularTiempo(FILE *ptrING,FILE *ptrSOL,Solicitud &solicitud,Reposicion &reposicion);
//*****INGRESO*********************************************
Articulo buscarArticulo(ListaArt &listaArt, int codart);
void ingresoStock(Config &configuracion, ListaCalle &listaC, ListaArt &listaArt, ListaArtDeposito &listaArtDep,Reposicion &reposicion);
//******SOLICITUD******************************************
void solicitudStock(Config &configuracion,ListaCalle &listaCalle,ListaArt &listArt,ListaArtDeposito &listaArtDep,ListaFaltante &listaFaltante,Solicitud &solicitud,Camion &camion,PilaCamion &pilaCamion,ListaPesoAcum &listaPesoAcum,ListaVentas &listaVentas);
//***********CARGA*****************************************
void crearPesoAcumulado(ListaCalle &listaC,ListaPesoAcum &listaPesoAcum);
void cargarFaltante(ListaFaltante &listaFaltante,Faltantes &faltante);
void cargaVentas(ListaVentas &listaVentas,Solicitud &solicitud,float &monto);
void cargaCamiones(PilaCamion &pilacamion,Solicitud &solicitud,Config &config);
//*******ORDENAR*******************************************
void ordenamientoSaldosagrupados(ListaPesoAcum &listaPesoAcum);
void ordenarlista(ListaVentas &listaventas);
void ordenamientofaltantes(ListaFaltante &listaFaltante);
//******CARGA TXT******************************************
void crearSaldosDetalladosTxt(ListaCalle &listaC);
void crearPesoAcumuladoTxt(ListaPesoAcum &listaPesoAcum);
void crarFaltanteTxt(ListaFaltante &listaFaltante);
void crearVentaTxt(ListaVentas &listaVentas);
void crearCamionTxt(PilaCamion &pilaCamion);
//*********************************************************

#endif // __FUNYPROD_H__

