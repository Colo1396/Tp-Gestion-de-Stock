#include "Configuracion.h"

 //**********************
void constructorConfig(Config &config){
config.configP=0;
config.configU=0;
config.configKC=0;
}
//**********************
void constructorConfig(Config &config,int p,int u, float kc){
config.configP=p;
config.configU=u;
config.configKC=kc;
}
//**********************
void setConfigP(Config &config,int p){
config.configP=p;
}
//**********************
void setConfigU(Config &config,int u){
config.configU=u;
}
//**********************
void setConfigKC(Config &config,float kc){
config.configKC=kc;
}
//**********************
int getConfigP(Config &config){
return config.configP;
}
//**********************
int getConfigU(Config &config){
return config.configU;
}
//**********************
float getConfigKC(Config &config){
return config.configKC;
}
//**********************
void destructorConfig(Config &config){
}


