#include "PilaArtUb.h"

void crearPila(PilaArtUb &pilaArtUb){
    pilaArtUb.top=finU();
}
void destruir(PilaArtUb &pilaArtUb){
    while(!pilaVacia(pilaArtUb)){
        pop(pilaArtUb);

    }
}
bool pilaVacia(PilaArtUb &pilaArtUb){
return pilaArtUb.top==finU();
}
void push(PilaArtUb &pilaArtUb,ArtUb datoArtUb){
PtrNodoPilaArtUb aux=new NodoPilaArtUb;
aux->datoArtUb=datoArtUb;
aux->sgteU=pilaArtUb.top;
pilaArtUb.top=aux;
}
ArtUb pop(PilaArtUb &pilaArtUb){

    PtrNodoPilaArtUb aux=pilaArtUb.top->sgteU;//podria ser cualquier ipo de de dato
        ArtUb datoArtUb=pilaArtUb.top->datoArtUb;
        delete pilaArtUb.top;
        pilaArtUb.top=aux;
        return datoArtUb;

}
PtrNodoPilaArtUb finU(){
    return NULL;
}

PtrNodoPilaArtUb top(PilaArtUb &pilaArtUb){
 return pilaArtUb.top;
}
