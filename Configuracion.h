#ifndef __CONFIGURACION_H__
#define __CONFIGURACION_H__

 typedef struct Config{
 int configP;
 int configU;
 float configKC;
 };
 //**********************
void constructorConfig(Config &config);
//**********************
void constructorConfig(Config &config,int p,int u, float kc);
//**********************
void setConfigP(Config &config,int p);
//**********************
void setConfigU(Config &config,int u);
//**********************
void setConfigKC(Config &config,float kc);
//**********************
int getConfigP(Config &config);
//**********************
int getConfigU(Config &config);
//**********************
float getConfigKC(Config &config);
//**********************
void destructorConfig(Config &config);
#endif // __CONFIGURACION_H__
