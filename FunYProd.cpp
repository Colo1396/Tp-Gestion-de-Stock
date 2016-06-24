#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <time.h>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include "Configuracion.h"
#include "FunYProd.h"
#include "LDeposito.h"
#include "ListaArticulo.h"
#include "ListaCalle.h"
#include "ListaFaltantes.h"
#include "ListaPesoAcumulado.h"
#include "ListaPiso.h"
#include "ListaVentas.h"
#include "PilaArtUb.h"
#include "PilaCamion.h"
#include "Reposicion.h"
#include "Solicitud.h"

using namespace std;
//**************************************************************
void cargaMaster(ListaArt &listArt){
    //1 recorrer el archivo
    //2 en variables aux guardamos el valr de la linea
    //3 creaamos un instacina de articulos
    //4 a esa instancia le pasamos loss datos comvertidos
    //5 mientras sea finde archivo adicccionar a la liszta
ifstream arcArticulos("articulos.db");
    Articulo artAux;
    constructorArt(artAux);

    char linea[128];
    char* cpToken2;

    if(arcArticulos.fail()){
    cerr << "Error al abrir el archivo articulos\n" << endl;}
    else{

    while(!arcArticulos.eof())
    {
        arcArticulos.getline(linea, sizeof(linea));
            cpToken2 = strtok (linea, ";");
            setCodArt(artAux,atoi(cpToken2));
            cpToken2= strtok(NULL,",");
            float ent=atof(cpToken2);
            cpToken2=strtok(NULL,";");
            float dec=atof(cpToken2);
            setPrecio(artAux,(ent+(dec/100)));
            cpToken2= strtok(NULL,"\n");
            strcpy(artAux.descripcion,cpToken2);
        adicionarFinal(listArt,artAux);
    }
}
arcArticulos.close();

}
//*************************************************
void cargaConfig(Config &config){
    ifstream archConfig("configuracion.conf");
      char linea[12];
    char* cpToken;

    if(archConfig.fail()){
    cerr << "Error al abrir el archivo CONFIGURACION\n" << endl;}
    else{

    while(!archConfig.eof())
    {
        archConfig.getline(linea, sizeof(linea));
            cpToken = strtok (linea, ";");
            setConfigP(config,atoi(cpToken));
            cpToken= strtok(NULL,";");
            setConfigU(config,atoi(cpToken));
            cpToken=strtok(NULL,"\n");
            setConfigKC(config,atof(cpToken));
    }
}
archConfig.close();
}
//***************************************************************
int calcularTiempo(FILE *ptrING,FILE *ptrSOL,Solicitud &solicitud,Reposicion &reposicion){
//Variables que se usan en el primer paso.
//cadenaI Se usa para guardar la linea que se lee del archivo.
//calTIEMPO se usa para guardar en forma de char, el tiempo. Ej: 08:00:00
char cadenaI[50],calTiempo[20];
char* cpToken; //cpToken se utiliza para guardar caracteres desde cierto punto hasta cierto punto en una linea de caracteres
int PosIniING,h,m,s,hh,mm,stingreso; //los POS(posicion del cursor), son antes y despues de leer en el archivo
//Variables que se usan en el segundo paso.
char cadenaS[18];
char* cpToken2;
int hh2,mm2,stsolicitud,pos2;


    PosIniING=ftell(ptrING);
    printf("************************************\n");


    //LEE LA PRIMER CADENA EN EL ARCHIVO INGRESO Y GUARDAMOS EN cadenaI
    fscanf (ptrING, "%s", cadenaI);
    cpToken = strtok (cadenaI, ";"); //Desde la cadenaI leemos del principio hasta ";"
    // obtiene el primer campo del registro y lo guarda en cpToken
    reposicion.cod_articulo= atoi(cpToken); //Transformamos en INT y guardamos en CodArt
    cpToken = strtok (NULL, ";"); //Continuamos leyendo en cadenaI pero ahora desde NULL.
    reposicion.cantidad= atoi(cpToken); //Transformamos en FLOAT
    cpToken = strtok (NULL, ";");
    strcpy (reposicion.hora, cpToken);
    // obtiene el tercer campo... HORA
    //***********************************
    ;//contiene en forma de cadena la hora
    strcpy (calTiempo, cpToken); // COPIA EL CONTENIDO DE CPTOKEN EN LA CADENA
    //printf("%s \n",calTiempo);
    cpToken= strtok(calTiempo,":");
    h=atoi(cpToken);
    cpToken= strtok (NULL,":");
    m=atoi(cpToken);
    cpToken= strtok (NULL,":");
    s=atoi(cpToken);
    hh=h*3600;
    mm=m*60;
    stingreso=hh+mm+s; //TRANSFORMA LA HORA EN SEGUNDOS EJ: 08:01:37 = 28897 SEGS.

//*****************************************FIN INGRESO***********************
    pos2=ftell(ptrSOL);

    fscanf (ptrSOL, "%s", cadenaS) ;
    cpToken2 = strtok (cadenaS, ";"); // obtiene el primer campo dela cadena y lo guarda en cpToken
    setCodSuc(solicitud,atoi(cpToken2));//Lo guarda en
    cpToken2 = strtok (NULL, ";");// Obtiene el CodART
    setCodArt(solicitud,atoi(cpToken2));

    cpToken2 = strtok (NULL, ";"); //obtiene el segundo campo... cantidad
    setCantidad(solicitud,atof(cpToken2)); //Lo guardo en la estructura
    cpToken2 = strtok (NULL, ";"); //Obtiene la HORA
    strcpy (solicitud.hora, cpToken2); //Lo guarda en la estructura.

    //***********************************

    strcpy (calTiempo, cpToken2); //En CalTiempo, guardamos la Hora que estaba en cptoken2 para trabajarla.
    cpToken2= strtok(calTiempo,":");
    h=atoi(cpToken2);
    cpToken2= strtok (NULL,":");
    m=atoi(cpToken2);
    cpToken2= strtok (NULL,":");
    s=atoi(cpToken2);
    hh2=h*3600;
    mm2=m*60;
    stsolicitud=hh2+mm2+s; //vALOR EN SEGUNDOS DE ESA HORA.

    if (stingreso<=stsolicitud){

        fseek(ptrSOL, pos2, SEEK_SET);
        return 1;
    }
    else
    {
        fseek( ptrING, PosIniING, SEEK_SET);
        return 2;
    }

}

void leerSolicitud(FILE *ptrSOL,Solicitud &solicitud){

char cadenaS[18];
char* cpToken2;

    fscanf (ptrSOL, "%s", cadenaS) ;
    cpToken2 = strtok (cadenaS, ";"); // obtiene el primer campo dela cadena y lo guarda en cpToken
    setCodSuc(solicitud,atoi(cpToken2));//Lo guarda en
    cpToken2 = strtok (NULL, ";");// Obtiene el CodART
    setCodArt(solicitud,atoi(cpToken2));

    cpToken2 = strtok (NULL, ";"); //obtiene el segundo campo... cantidad
    setCantidad(solicitud,atof(cpToken2)); //Lo guardo en la estructura
    cpToken2 = strtok (NULL, ";"); //Obtiene la HORA
    strcpy (solicitud.hora, cpToken2); //Lo guarda en la estructura.
    cout << solicitud.cod_articulo<< " " <<solicitud.cod_suc<< " " <<solicitud.cantidad<< " " <<solicitud.hora<<endl;

}

void leerIngreso(FILE *ptrING,Reposicion &reposicion){

char cadenaI[50];
char* cpToken;
    fscanf (ptrING, "%s", cadenaI);
    cpToken = strtok (cadenaI, ";");
    reposicion.cod_articulo= atoi(cpToken);
    cpToken = strtok (NULL, ";");
    reposicion.cantidad= atoi(cpToken);
    cpToken = strtok (NULL, ";");
    strcpy (reposicion.hora, cpToken);
    cout << reposicion.cod_articulo << " " << reposicion.cantidad << " " << reposicion.hora<< endl;

}
//***************************************************************
//BUSCA Y DEVUELVE EL ARTICULO DE LA LSTA ARTICULOS
Articulo buscarArticulo(ListaArt &listaArt, int codart){
	PrtNodoListaArt ptrArticulo = primero(listaArt);
	bool encontrado=false;
	while(ptrArticulo != NULL && encontrado != true){
		if (  getCodArt(ptrArticulo->datoLArt) == codart){
			encontrado = true;
		}
		else{
			ptrArticulo	= siguiente(listaArt,ptrArticulo);
		}
	}
	return (ptrArticulo->datoLArt);
}

void ingresoStock(Config &configuracion, ListaCalle &listaC, ListaArt &listaArt, ListaArtDeposito &listaArtDep,Reposicion &reposicion){
cout<<"INGRESO DE ARTICULO"<<endl;
cout<<"Cod. Articulo: "<< getCodArt(reposicion) <<endl;
cout<<"Cantidad: "<< getCant(reposicion) << endl;
int codArti=0;
if(listaVacia(listaArtDep)){
// SI ESE ARTICULO NUEVO, ES EL PRIMERO AGREGADO
        PrtNodoListaArt ptrArt= primero(listaArt);
        codArti=reposicion.cod_articulo;
        bool encont=false;
        while (ptrArt !=NULL && encont !=true){
            if (getCodArt(ptrArt->datoLArt)==codArti){          //COMPROBAR EXISTENCIA
                    encont=true;
                }
            else {
                    ptrArt=siguiente(listaArt, ptrArt);
                }
			}
		if(encont==true){
			Articulo art1 = buscarArticulo(listaArt,getCodArt(reposicion));
			ArtUbicacion articuloU1;
			constructorArtUb(articuloU1,art1,1,1,1,getCant(reposicion));
			PilaArtUb pilaA1;
			crearPila(pilaA1);
			push(pilaA1,articuloU1);
			ListaPiso piso1;
			crearListaPiso(piso1);
			adicionarFinal(piso1,pilaA1);
			adicionarFinal(listaC, piso1);
			ArtDeposito artDep1;
			crearArtDep(artDep1);
			//CORRECCION
			PtrNodoPisoDep pisoDep=primero(piso1);
            setPisoDep(artDep1,pisoDep);
            //
			setCodArtDep(artDep1, getCodArt(reposicion));
			//setPisoDep(artDep1, primero(primero(listaC)->piso1));
			adicionarFinal(listaArtDep,artDep1);
			cout<<"Primer articulo guardado exitosamente"<<endl;
		}
		else{
			cout<<"El articulo no se encuentra"<<endl;
		}
}
else{
    bool encontrado=false; //FLAG DE REFERENCIA DE ARTICULO ENCONTRADO
//DETERMINAR EN PRIMER LUGAR LA UBICACION EN EL DEPOSITO
    PtrNodoListaDeposito ptrNodoListaDeposito = primero(listaArtDep);                       //
    while(ptrNodoListaDeposito!= NULL && encontrado != true){                               // BUSCO EL ARTICULO
        if ( getCodArtDep(ptrNodoListaDeposito->datoArtDep) == getCodArt(reposicion)){      // PARA VER SI YA EXISTE
            encontrado = true;                                                              // EN DEPOSITO,
            }                                                                               // PERO REALIZO LA BUSQUEDA
        else{                                                                               // A TRAVES DEL INDICE
            ptrNodoListaDeposito = siguiente(listaArtDep,ptrNodoListaDeposito);             // (ListaArtDeposito)
			}                                                                               //
    }
//SI EL ARTICULO EXISTE, SE ALMACENARA LA CANTIDAD EN LA UBICACION YA UTILIZADA
    if (encontrado == true){
        PilaArtUb pilaAux;   //CREO UNA PILA AUXILIAR PARA GUARDAR LOS
        crearPila(pilaAux);  //ARTICULOS QUE VOY SACANDO DEL DEPOSITO
        bool encontradoP= false;   //FLAG DE REFERENCIA DE ENCONTRADO EN LA PILA

        PtrNodoPisoDep ptrPiso = getPisoDep(ptrNodoListaDeposito->datoArtDep);//NODO DE PISO DONDE ESTA EL ARTICULO
        Articulo artEnDep;
        constructorArt(artEnDep);
        while ( !pilaVacia(ptrPiso->pilUb) && encontradoP != true){    //ME POSICIONO EN EL NODO DEL ARTICULOUBICACION
            artEnDep = getDatoArt((top(ptrPiso->pilUb))->datoArtUb); //OBTENGO EL ARTICULO APUNTADO
            if( getCodArt(artEnDep) == getCodArt(reposicion) ) {                                        //SI EL COD DEL ARTICULO EN TOP
                float cantAct = getCantArtUb((top(ptrPiso->pilUb))->datoArtUb) + getCant(reposicion);   //COINCIDE CON EL DEL INGRESO
                setCantArtUb(((top(ptrPiso->pilUb))->datoArtUb),cantAct);                               //LE AGREGO LA CANTIDAD AL
                encontradoP= true;                                                                      //ARTICULO EXISTENTE
                cout<<"\tActualizacion de stock de articulo existente"<<endl;
                cout<<cantAct<<getCantArtUb((top(ptrPiso->pilUb))->datoArtUb)<<endl;
            }
            else{
					push(pilaAux, pop(ptrPiso->pilUb) );   //SACA LOS ARTICULOS Y LOS PONE EN LA PILA AUXILIAR
				}
			}
        while(!pilaVacia(pilaAux) ){
				push((ptrPiso->pilUb), pop(pilaAux));      //METE LOS ARTICULOS SACADOS
			}
    }
//SI EL ARTICULO NO EXISTE EN DEPOSITO: SE SOLICITARA UNA NUEVA POSICIÓN
		else{
		    bool aRegist = false; //FLAG PARA ARTICULO REGISTRADO
			int contadorC=0,contadorP=0; //POSTERIORMENTE SON UTILIZADOS DE CONTADORES DE CALLES Y DE PISOS
			int longUb=0;

			PrtNodoListaArt ptrArt= primero(listaArt);
			codArti=reposicion.cod_articulo;
			bool encont=false;
			while (ptrArt !=NULL && encont !=true){
                if (getCodArt(ptrArt->datoLArt)==codArti){          //COMPROBAR EXISTENCIA
                    encont=true;
                }
                else {
                    ptrArt=siguiente(listaArt, ptrArt);
                }
			}
			if(encont==true){
				Articulo artUbic = buscarArticulo(listaArt, getCodArt(reposicion));
				ArtUbicacion artNUb; //GUARDARA EL ARTUBIC QUE ES EL ARTICULO A UBICAR
				constructorArtUb(artNUb,artUbic,0,0,0,getCant(reposicion));  //VALORES
				ArtDeposito artDepNuevo;    //GUARDA LA POSICION DEL ARTICULO NUEVO
				crearArtDep(artDepNuevo);
				ListaPiso listPisoN;        //ESTO ES POR SI TENGO QUE INSERTAR UN PISO NUEVO
				crearListaPiso(listPisoN);
				PilaArtUb ubiNueva;        //Y ASI TAMBIEN POR SI NECESITO UNA NUEVA UBICACION
				crearPila(ubiNueva);
				PtrNodoCalle ptrC = primero(listaC);
				while(ptrC != NULL && !aRegist){
					contadorC++;
					PtrNodoPiso ptrP = primero(ptrC->listPiso);
					while(ptrP != NULL && !aRegist){  //RECORRO LISTA PISOS
						contadorP++;
						if (!pilaVacia(ptrP->pilUb)){
                        longUb=ptrP->pilUb.top->datoArtUb.u;
                     }
                          if (longUb < getConfigU(configuracion)&& !aRegist){  //MIENTRAS LA LONGITUD ES MENOR A LO DETERMINADO EN CONFIGURACION Y SEA DISTINYO DE AREGIST
								setC(artNUb,contadorC);
								setP(artNUb,contadorP);
								setU(artNUb,longUb+1);
								push(ptrP->pilUb,artNUb); //COLOCO EL ARTNUB EN LA PILA DE UBICACIONES

								setCodArtDep(artDepNuevo, getCodArt(reposicion));      //
								setPisoDep(artDepNuevo, ptrP);                         //PARA EL NUEVO INDICE
								adicionarFinal(listaArtDep,artDepNuevo);               //

								aRegist = true;   //CAMBIO EL FLAG
                                cout<<artNUb.datoArt.codart<<" "<<artNUb.c<<" "<<getP(artNUb)<<" "<<getU(artNUb)<<" "<<getCantArtUb(artNUb)<<endl;

								cout<<"Nuevo articulo guardado exitosamente"<<endl;
							}

					//}


					    ptrP = siguiente(ptrC->listPiso,ptrP);
					}
//SI NO HAY LUGAR, AÑADO UN NUEVO PISO PARA ESA CALLE
					if(aRegist==false && contadorP<getConfigP(configuracion)){
						setC(artNUb,contadorC);       //
						setP(artNUb,contadorP + 1);   //SETEO LAS COORDENADAS A INGRESAR
						setU(artNUb,1);               //
						push(ubiNueva,artNUb);
						PtrNodoPisoDep ptrP = adicionarFinal(ptrC->listPiso,ubiNueva); //AGREGO EL PISO
						setCodArtDep(artDepNuevo, getCodArt(reposicion));
						setPisoDep(artDepNuevo, ptrP);                      //AGREGO EL NUEVO ARTICULO AL INDICE
						adicionarFinal(listaArtDep,artDepNuevo);
						aRegist = true;
						cout<<"\tNuevo piso creado "<<contadorC<<", nuevo articulo guardado exitosamente"<<endl;
					}
					contadorP=0;
					ptrC = siguiente(listaC, ptrC);
				}

// SI NECESITO CREAR UNA NUEVA CALLE
				if(aRegist==false){
					setC(artNUb,contadorC + 1);    //SETEO LAS COORDENADAS DEL NUEVO ARTICULO
					setP(artNUb,1);
					setU(artNUb,1);
					push(ubiNueva,artNUb);

					PtrNodoPisoDep ptrPiso2 = adicionarFinal(listPisoN,ubiNueva);  //AGREGO UN NODO DE UBICACION A LA LISTPISON
                    adicionarFinal(listaC, listPisoN);

					setCodArtDep(artDepNuevo, getCodArt(reposicion));       //
					setPisoDep(artDepNuevo, ptrPiso2);                      //AGREGO EL NUEVO ARTICULO AL INDICE
					adicionarFinal(listaArtDep,artDepNuevo);                //
					cout<<"\Nueva calle: "<<contadorC+1<<". Nuevo articulo guardado exitosamente."<<endl;
				}
			}
			else{
				cout<<"El articulo no se encuentra"<<endl;
			}
		}
	}
	}
//***************************************************************
void solicitudStock(Config &configuracion,ListaCalle &listaCalle,ListaArt &listArt,ListaArtDeposito &listaArtDep,ListaFaltante &listaFaltante,Solicitud &solicitud,Camion &camion,PilaCamion &pilaCamion,ListaPesoAcum &listaPesoAcum,ListaVentas &listaVentas){
float monto=0;
int contador=0;
int cantidadCumplida=0;
int faltanteCantidad=0;
bool eliminarN = false;
ArtUbicacion artaux;
constructorArtUb(artaux);
PrtNodoListaArt ptr=primero(listArt);
PtrNodoListaDeposito ptrdep=primero(listaArtDep);

                        PtrNodoPiso nodo=ptrdep->datoArtDep.pisoDep;
                        PtrNodoPilaArtUb ptrPila=top(ptrdep->datoArtDep.pisoDep->pilUb);
                        PilaArtUb pilaAux;
                        crearPila(pilaAux);
                        bool articuloEnDep = false;
                        while(ptrdep != NULL && articuloEnDep != true){
                                if(getCodArt(solicitud) == ptrdep->datoArtDep.codArt){
                                    articuloEnDep = true;
                                }else{
                                    ptrdep = siguiente(listaArtDep,ptrdep);
                                }

                        }
                        if(articuloEnDep == true){
                                while(!pilaVacia(ptrdep->datoArtDep.pisoDep->pilUb )){

                                    artaux=pop(ptrdep->datoArtDep.pisoDep->pilUb);
                                    //cout << artaux.datoArt.codart <<"ACACACACA"<< solicitud.cod_articulo<<endl;
                                    //SI "SON IGUALES LAS ID" COMPROBAMOS QUE HAYA SUFIENTE EN STOCK
                                    if ((artaux.datoArt.codart == solicitud.cod_articulo)){
                                       // cout << "HAY COINCIDENCIA" << endl;//NOS ALCANZA? SI
                                        if (getCantArtUb(artaux)>solicitud.cantidad){
                                            //ENTONCES, HACEMOS LA RESTA.
                                            artaux.cantArtUb-=solicitud.cantidad;


                                            //VENTAS, CAMION, ETC.
                                            //Ya tenemos lo que falta, ahora enviamos lo que tenemos al camion.

                                            Solicitud solaux;
                                            crearSolicitud(solaux,solicitud.cod_suc,solicitud.cod_articulo,solicitud.cantidad,solicitud.hora);
                                            //Cargamos camion.
                                            cargaCamiones(pilaCamion,solaux,configuracion);
                                            //Cargamos la venta
                                            monto=solicitud.cantidad*artaux.datoArt.precio;
                                            cargaVentas(listaVentas,solaux,monto);

                                            //Pusheamos en la pila auxiliar con los datos ya modificados.
                                            push(pilaAux,artaux);
                                        }
                                        else if(getCantArtUb(artaux)<=solicitud.cantidad){
                                            printf("NO ALCANZA\n");

                                            //ENVIAR LO QUE TENEMOS.

                                            //Primero restamos para calcular DIFERENCIA FALTATE.
                                            faltanteCantidad=solicitud.cantidad-artaux.cantArtUb;
                                            cantidadCumplida=artaux.cantArtUb;



                                            //Ya tenemos lo que falta, ahora enviamos lo que tenemos al camion.
                                            Solicitud solaux;
                                            crearSolicitud(solaux,solicitud.cod_suc,solicitud.cod_articulo,cantidadCumplida,solicitud.hora);
                                            //Cargamos camion.

                                            cargaCamiones(pilaCamion,solaux,configuracion);

                                            //Cargamos la venta
                                            monto=artaux.cantArtUb*artaux.datoArt.precio;


                                            cargaVentas(listaVentas,solaux,monto);


                                            //Creo el faltante.
                                            float cantidadCumplida2=cantidadCumplida;
                                            float porcentaje=cantidadCumplida*100/solicitud.cantidad;

                                            //Añadimos el faltante a la lista.
                                            Faltante faltaaux;
                                            crearFaltante(faltaaux,solicitud.cod_suc,solicitud.cod_articulo,cantidadCumplida2,solicitud.cantidad,porcentaje);
                                            cargarFaltante(listaFaltante,faltaaux);
                                            //QUITAR ARTICULO DE LA PILA.


                                            //CAMBIAMOS CPU DE Los OTROS ARTICULO EN LA PILA.

                                           eliminarN = true;
                                        }
                                    }
                                    else{
                                        push(pilaAux,artaux);
                                    }

                                }
                            while(!pilaVacia(pilaAux)){
                                artaux=pop(pilaAux);

                                contador++;
                                setU(artaux,contador);
                                push(ptrdep->datoArtDep.pisoDep->pilUb,artaux);
                                cout << "Aca GUARDO un ARTICULO EN UBICACION "<< ptrdep->datoArtDep.pisoDep->pilUb.top->datoArtUb.u << endl;
                                //getCantArtUb(artaux) << endl;
                            }
                            if(eliminarN == true){
                               eliminarNodo(listaArtDep,ptrdep);
                            }

                        }

//******************************************************************************************
                if(articuloEnDep == false){
                    //NO ESTA EN DEPOSITO
                    cout << "NO ESTA EN DEPOSITO, AÑADIMOS A FALTANTES" << endl;
                    Faltante faltaux2;
                    crearFaltante(faltaux2,solicitud.cod_suc,solicitud.cod_articulo,0,solicitud.cantidad,0.00);
                    adicionarFinal(listaFaltante,faltaux2);
                }


}
//***************************************************************
void crearPesoAcumulado(ListaCalle &listaC,ListaPesoAcum &listaPesoAcum){
PtrNodoCalle ptrC=primero(listaC);
PtrNodoPiso ptrPiso=primero(ptrC->listPiso);
PtrNodoPilaArtUb ptrPila=top(ptrPiso->pilUb);
ArtUbicacion artAux;
constructorArtUb(artAux);
PilaArtUb pilAux;
crearPila(pilAux);
PesoAcum pesoAcumAux;
if(listaVacia(listaC)==true){
    cout<<"LISTA CAlle VACIA"<<endl;
}
else{
//RECORRO LA LISTA DE CALLE
while(!listaVacia(listaC)&&ptrC!=NULL){
    if (listaVacia(ptrC->listPiso)){
        cout<<"LISta PIso Vacia"<<endl;
    }
    else{
        //RECORRO LA LISTA DE PIso
        ptrPiso=primero(ptrC->listPiso);
        while(!listaVacia(ptrC->listPiso)&& ptrPiso!=NULL){

            //RECORRO LA PILA DE ARTICULOS
            if(pilaVacia(ptrPiso->pilUb)){
                cout<<"PILA ART VACIA"<<endl;
            }
            else{
                while(!pilaVacia(ptrPiso->pilUb)){
                    //hago el pop a la auxiliar
                    artAux=pop(ptrPiso->pilUb);
                    crearPesoAcum(pesoAcumAux,artAux.datoArt.codart,artAux.cantArtUb);
                    adicionarFinal(listaPesoAcum,pesoAcumAux);
                   push(pilAux,artAux);
                }
                while(!pilaVacia(pilAux)){
                    artAux=pop(pilAux);
                    push(ptrPiso->pilUb,artAux);
                }

            }
        ptrPiso=siguiente(ptrC->listPiso,ptrPiso);
        }

    }
    ptrC=siguiente(listaC,ptrC);

 }

}
}

void cargarFaltante(ListaFaltante &listaFaltante,Faltantes &faltante){
PtrNodoFaltante ptrF=primero(listaFaltante);
if(listaVacia(listaFaltante)){
    Faltantes f1;
    crearFaltante(f1,faltante.codsucursal,faltante.codArt,faltante.cantTot,faltante.cantEnv,faltante.porc);
    adicionarPrincipio(listaFaltante,f1);
}
else{
    Faltantes f2;
    crearFaltante(f2,faltante.codsucursal,faltante.codArt,faltante.cantTot,faltante.cantEnv,faltante.porc);
    adicionarFinal(listaFaltante,f2);
}
}

void cargaVentas(ListaVentas &listaVentas,Solicitud &solicitud,float &monto){
bool encontrado=false;
PtrNodoListaVentas ptrLV=primero(listaVentas);
if (listaVacia(listaVentas)){
    Venta v1;
    crearVentas(v1,solicitud.cod_suc,monto);
    adicionarPrincipio(listaVentas,v1);
}
else {
    while(ptrLV!=NULL && encontrado!=true){
        if(solicitud.cod_suc==ptrLV->datoVenta.codSucursal){
        encontrado=true;
        ptrLV->datoVenta.montoTotal+=monto;

        }
    ptrLV=siguiente(listaVentas,ptrLV);
}

if (encontrado==false){

    Venta v2;
    crearVentas(v2,solicitud.cod_suc,monto);
    adicionarFinal(listaVentas,v2);
}
}
}

void cargaCamiones(PilaCamion &pilacamion,Solicitud &solicitud,Config &config){
PtrNodoPilaCamion ptrPC=top(pilacamion);

float KxC=getConfigKC(config);//carga maxima del camion dado por la configuracion
float solCant=getCant(solicitud);//cantidad de la solicitud
Camion auxCam;
Camion auxCam1;
Camion auxCam2;
Camion auxCam3;
if (pilaVacia(pilacamion)){

        crearCamion(auxCam,1,solCant,((solCant*100)/KxC));
        push(pilacamion,auxCam);
        cout <<  "PILA CAMION VACIA Creamos un camion con la solicitud\n" << endl;
}
else {

    int IDAux=getId_Camion(ptrPC->datoCamion);
    if (getCarga_T(ptrPC->datoCamion)>=KxC){

                printf("No me alcanza");
                crearCamion(auxCam1,IDAux+1,solCant,((solCant)*100)/KxC);
                push(pilacamion,auxCam1);
                cout<<"Creamos un camion nuevo, el camion del top estaba lleno\n"<<endl;
    }
    else{
        if(getCarga_T(ptrPC->datoCamion)<KxC){
                cout<<"El camion del top de la pila estaba CASI lleno\n"<<endl;
            //saco el camion de la lista para utilizarlo
            Camion camAux;
            camAux=pop(pilacamion);
            float suma=solCant+getCarga_T(camAux);
            float sumaPorcentaje=((solCant*100)/KxC)+getPorcentaje(camAux);
            int idCamionPop=getId_Camion(camAux);

            //si la cantidad de la solicitud y la cantidad q ya tenia el camion no superan la cantidad maxima
                if(suma<=KxC){
                    //creo el camion y lo cargo
                    crearCamion(auxCam2,idCamionPop,suma,sumaPorcentaje);
                    push(pilacamion,auxCam2);
                    cout<<"Al camion que estaba en el top lo cargamos con otra solicitud \n"<<endl;
cout<<"****************************************************"<<endl;
                }
            //sinoi. si la suma de la cantidad de solicitud con lo cargado en el camion supera la carga maxima
            else {//sino  crear un nuevo camion y pushear el q saque
                if(suma>KxC){//si la suma es mayor a la que soporta un camion
                    //creo un camion un el mismo id del camion q saque, con la caga maxima y su porcentaje
                    push(pilacamion,camAux);
                    crearCamion(auxCam3,idCamionPop+1,solCant,((solCant*100)/KxC));
                    push(pilacamion,auxCam3);
                    // despacho un camion con el resto de la carga y su porcentaje
                    cout<<"Al camion que estaba en el top lo cargamos con otra solicitud y creamos uno nuevo porque excedio el limite\n"<<endl;
cout<<"****************************************************"<<endl;
                }
            }
        }
        }
    }
}

//***************************************************************
void ordenamientoSaldosagrupados(ListaPesoAcum &listaPesoAcum){

    NodoListaPAcum* temporalhead=primero(listaPesoAcum);

    int temporal;
    int contar;
    float temporal2;
    float temporal3;

    while (temporalhead != NULL)
  {
      temporalhead=temporalhead->sgtePA;
      contar++;
  }
    temporalhead= primero(listaPesoAcum);

    for (int i=0;i< contar ;i++)
    {
        while (temporalhead ->sgtePA)
        {
            if (temporalhead->datoPesoA.cant < temporalhead->sgtePA->datoPesoA.cant )
            {
               temporal = temporalhead->datoPesoA.codArt;
               temporalhead->datoPesoA.codArt=temporalhead->sgtePA->datoPesoA.codArt;
               temporalhead->sgtePA->datoPesoA.codArt=temporal;

               temporal2 = temporalhead->datoPesoA.cant;
               temporalhead->datoPesoA.cant=temporalhead->sgtePA->datoPesoA.cant;
               temporalhead->sgtePA->datoPesoA.cant=temporal2;
            }
            else temporalhead=temporalhead->sgtePA;
        }
        temporalhead = primero(listaPesoAcum);
    }

}

void ordenarlista(ListaVentas &listaventas){

    NodoListaVentas* temporalhead= primero(listaventas);

  int temporal;
  int contar=0;
  while (temporalhead != NULL)
  {
      temporalhead=temporalhead->sgteV;
      contar++;
  }
    temporalhead= primero(listaventas);

    for (int i=0;i< contar ;i++)
    {
        while (temporalhead ->sgteV)
        {
            if (temporalhead->datoVenta.montoTotal < temporalhead->sgteV->datoVenta.montoTotal)
            {
               temporal = temporalhead->datoVenta.codSucursal;
               temporalhead->datoVenta.codSucursal=temporalhead->sgteV->datoVenta.codSucursal;
               temporalhead->sgteV->datoVenta.codSucursal=temporal;

               temporal = temporalhead->datoVenta.montoTotal;
               temporalhead->datoVenta.montoTotal=temporalhead->sgteV->datoVenta.montoTotal;
               temporalhead->sgteV->datoVenta.montoTotal=temporal;
            }
            else temporalhead=temporalhead->sgteV;
        }
        temporalhead = primero(listaventas);
    }

}

void ordenamientofaltantes(ListaFaltante &listaFaltante){
     NodoFaltante* temporalhead= primero(listaFaltante);

  int temporal;
  int contar=0;
  float temporal1=0;
  float temporal2=0;
  bool  moverpuntero=false;
  while (temporalhead != NULL)
  {
      temporalhead=temporalhead->sgteF;
      contar++;
  }
    temporalhead= primero(listaFaltante);

    for (int i=0;i< contar ;i++)
    {
        while (temporalhead ->sgteF)
        {
            moverpuntero=false;
            if (temporalhead->datoFaltante.codsucursal >temporalhead->sgteF->datoFaltante.codsucursal)
            {
               temporal = temporalhead->datoFaltante.codsucursal;
               temporalhead->datoFaltante.codsucursal=temporalhead->sgteF->datoFaltante.codsucursal;
               temporalhead->sgteF->datoFaltante.codsucursal=temporal;

               temporal = temporalhead->datoFaltante.codArt;
               temporalhead->datoFaltante.codArt=temporalhead->sgteF->datoFaltante.codArt;
               temporalhead->sgteF->datoFaltante.codArt=temporal;

               temporal1 = temporalhead->datoFaltante.cantTot;
               temporalhead->datoFaltante.cantTot=temporalhead->sgteF->datoFaltante.cantTot;
               temporalhead->sgteF->datoFaltante.cantTot=temporal1;

               temporal2 = temporalhead->datoFaltante.cantEnv;
               temporalhead->datoFaltante.cantEnv=temporalhead->sgteF->datoFaltante.cantEnv;
               temporalhead->sgteF->datoFaltante.cantEnv=temporal2;

               temporal = temporalhead->datoFaltante.porc;
               temporalhead->datoFaltante.porc=temporalhead->sgteF->datoFaltante.porc;
               temporalhead->sgteF->datoFaltante.porc=temporal;
               moverpuntero =true;
            }
            else if (temporalhead->datoFaltante.codsucursal == temporalhead ->sgteF->datoFaltante.codsucursal)
                {
                    if (temporalhead->datoFaltante.codArt > temporalhead->sgteF->datoFaltante.codArt)
                    {
                        temporal = temporalhead->datoFaltante.codsucursal;
                temporalhead->datoFaltante.codsucursal=temporalhead->sgteF->datoFaltante.codsucursal;
               temporalhead->sgteF->datoFaltante.codsucursal=temporal;

               temporal = temporalhead->datoFaltante.codArt;
               temporalhead->datoFaltante.codArt=temporalhead->sgteF->datoFaltante.codArt;
               temporalhead->sgteF->datoFaltante.codArt=temporal;

               temporal1 = temporalhead->datoFaltante.cantTot;
               temporalhead->datoFaltante.cantTot=temporalhead->sgteF->datoFaltante.cantTot;
               temporalhead->sgteF->datoFaltante.cantTot=temporal1;

               temporal2 = temporalhead->datoFaltante.cantEnv;
               temporalhead->datoFaltante.cantEnv=temporalhead->sgteF->datoFaltante.cantEnv;
               temporalhead->sgteF->datoFaltante.cantEnv=temporal2;

               temporal = temporalhead->datoFaltante.porc;
               temporalhead->datoFaltante.porc=temporalhead->sgteF->datoFaltante.porc;
               temporalhead->sgteF->datoFaltante.porc=temporal;
               moverpuntero=true;
                    }
                }

            if (moverpuntero==false){
            temporalhead=temporalhead->sgteF;
            }

        }
        temporalhead = primero(listaFaltante);
      }

    }
//***************************************************************
void crearSaldosDetalladosTxt(ListaCalle &listaC){
PtrNodoCalle ptrC=primero(listaC);
PtrNodoPiso ptrPiso=primero(ptrC->listPiso);
PtrNodoPilaArtUb ptrPila=top(ptrPiso->pilUb);
ArtUbicacion artAux;
constructorArtUb(artAux);
PilaArtUb pilAux;
crearPila(pilAux);
ofstream SaldosDetalladosTxt("Saldos_Detallados.txt");
if(listaVacia(listaC)==true){
    cout<<"LISTA CAlle VACIA"<<endl;
}
else{
//RECORRO LA LISTA DE CALLE
while(!listaVacia(listaC)&&ptrC!=NULL){
    if (listaVacia(ptrC->listPiso)){
        cout<<"LISta PIso Vacia"<<endl;
    }
    else{
        //RECORRO LA LISTA DE PIso
        ptrPiso=primero(ptrC->listPiso);
        while(!listaVacia(ptrC->listPiso)&& ptrPiso!=NULL){

            //RECORRO LA PILA DE ARTICULOS
            if(pilaVacia(ptrPiso->pilUb)){
                cout<<"PILA ART VACIA"<<endl;
            }
            else{
                while(!pilaVacia(ptrPiso->pilUb)){
                    //hago el pop a la auxiliar
                    artAux=pop(ptrPiso->pilUb);

                   push(pilAux,artAux);
                }
                while(!pilaVacia(pilAux)){
                    artAux=pop(pilAux);
                    SaldosDetalladosTxt<<getC(artAux)<<", "<<getP(artAux)<<", "<<getU(artAux)<<", "<<getDatoArt(artAux).codart<<", "<<getCantArtUb(artAux)<<endl;
                    push(ptrPiso->pilUb,artAux);
                }

            }
        ptrPiso=siguiente(ptrC->listPiso,ptrPiso);
        }

    }
    ptrC=siguiente(listaC,ptrC);
 }
}
}

void crearPesoAcumuladoTxt(ListaPesoAcum &listaPesoAcum){
    PtrNodoListaPA ptrPA=primero(listaPesoAcum);
ofstream PesoAcumuladoTxt("PesoAcumulado.txt");
float pesoacumulado=0;
if(listaVacia(listaPesoAcum)==true){
    cout<<"LISTA peso acumulado VACIA"<<endl;
}
else{
while(!listaVacia(listaPesoAcum)&&ptrPA!=NULL){
pesoacumulado=getCant(ptrPA->datoPesoA)+pesoacumulado;
PesoAcumuladoTxt<<ptrPA->datoPesoA.codArt<<", "<<ptrPA->datoPesoA.cant<<", "<<pesoacumulado<<endl;
    ptrPA=siguiente(listaPesoAcum,ptrPA);
 }
}
PesoAcumuladoTxt.close();


}

void crarFaltanteTxt(ListaFaltante &listaFaltante){
PtrNodoFaltante ptrF=primero(listaFaltante);
ofstream FaltanteTxt("Faltante.txt");
if(listaVacia(listaFaltante)==true){
    cout<<"LISTA Ventas VACIA"<<endl;
}
else{
while(!listaVacia(listaFaltante)&&ptrF!=NULL){

FaltanteTxt<< ptrF->datoFaltante.codsucursal<< ", "<<ptrF->datoFaltante.codArt<<", "<<ptrF->datoFaltante.cantEnv<<", "<<ptrF->datoFaltante.cantTot<<", "<<ptrF->datoFaltante.porc <<"%"<<endl;
    ptrF=siguiente(listaFaltante,ptrF);
 }
}
FaltanteTxt.close();
}

void crearVentaTxt(ListaVentas &listaVentas){
PtrNodoListaVentas ptr=primero(listaVentas);
ofstream VentasTxt("Ventas.txt");
if(listaVacia(listaVentas)==true){
    cout<<"LISTA Ventas VACIA"<<endl;
}
else{
while(!listaVacia(listaVentas)&&ptr!=NULL){
VentasTxt<<ptr->datoVenta.codSucursal<<", "<<ptr->datoVenta.montoTotal <<endl;
    ptr=siguiente(listaVentas,ptr);
 }
}
VentasTxt.close();
}

void crearCamionTxt(PilaCamion &pilaCamion){
PtrNodoPilaCamion ptrPila=top(pilaCamion);
PilaCamion pilaAux;
crearPila(pilaAux);
Camion camionAux;
ofstream CamionTxt("Camion.txt");
if(pilaVacia(pilaCamion)==true){
    cout<<"Pila Vacia"<<endl;

}
else{
while(!pilaVacia(pilaCamion)&&ptrPila!=NULL){
    camionAux=pop(pilaCamion);
    CamionTxt<<getId_Camion(camionAux)<<", "<<getCarga_T(camionAux)<<", "<<getPorcentaje(camionAux)<<endl;
    push(pilaAux,camionAux);
    ptrPila=top(pilaCamion);
}
while(!pilaVacia(pilaAux)){
    camionAux=pop(pilaAux);
    push(pilaCamion,camionAux);
    }
}
CamionTxt.close();
}


//***************************************************************

