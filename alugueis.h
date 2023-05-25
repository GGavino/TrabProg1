#ifndef ALUGUEIS_H_
#define ALUGUEIS_H_

#include "data.h"


int AdicionarAluguel(IMOVEL imoveis[], int tot,int totclientes); // Lê as informações de um aluguel e o adciona a lista ligada de seu respectivo imovel invocando a fução AdicionarAlugelNaLista
int listarImoveisDisponiveis(IMOVEL imoveis[],int tot); // Lista os imoveis que ainda estão disponiveis em uma determinada data fornecida pelo utilizador
int listarTodosAlugueis(IMOVEL imoveis[], int tot); // Lista todos os Alugueis de todos os imoveis
int listarAlugueisImovel(IMOVEL imoveis[], int tot); // Lista todos os alugueis de um Imovel escolhido pelo utilizador
int listarAlugueisCliente(IMOVEL imoveis[], int totimoveis,CLIENTE clientes[], int totclientes); // Lista todos os alugueis associados a um escolhido pelo utilizador
void listarUmAluguel(ALUGUELD aluguel); // lista as informações de um aluguel expecifico(função usada como base para todas as outras funções de listar alugueis)
int fechoDia(IMOVEL imoveis[],int tot);
int fechoMes(IMOVEL imoveis[],int tot);
int fechoAno(IMOVEL imoveis[],int tot);

#endif 
