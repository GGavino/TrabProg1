#ifndef ALUGUEIS_H_
#define ALUGUEIS_H_

#include "data.h"


int AdicionarAluguel(IMOVEL imoveis[], int tot);
int comparardatas(int dia1,int mes1,int ano1,int dia2,int mes2,int ano2);
int Bissexto(int ano);
int validardata(int dias, int mes, int ano);

#endif 
