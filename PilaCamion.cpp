#include "PilaCamion.h"

void crearPila(PilaCamion &pilaCamion){
    pilaCamion.top=finCa();
}
void destruir(PilaCamion &pilaCamion){
    while(!pilaVacia(pilaCamion)){
        pop(pilaCamion);
    }
}
bool pilaVacia(PilaCamion &pilaCamion){
return pilaCamion.top==finCa();
}
void push(PilaCamion &pilaCamion,Cam datoCamion){
PtrNodoPilaCamion aux=new NodoPilaCamion;
aux->datoCamion=datoCamion;
aux->sgteCa=pilaCamion.top;
pilaCamion.top=aux;
}
Cam pop(PilaCamion &pilaCamion){

    PtrNodoPilaCamion aux=pilaCamion.top->sgteCa;//podria ser cualquier ipo de de dato
        Cam datoCamion=pilaCamion.top->datoCamion;
        delete pilaCamion.top;
        pilaCamion.top=aux;
        return datoCamion;

}
PtrNodoPilaCamion finCa(){
    return NULL;
}
PtrNodoPilaCamion top(PilaCamion &pilaCamion){
    return pilaCamion.top;
}
