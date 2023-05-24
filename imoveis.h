#ifndef IMOVEIS_H_
#define IMOVEIS_H_

#include "data.h"

int AdicionarImoveis(IMOVEL imoveis[], int tot); // Lê as informações de um novo imóvel e o armazena tando na memoria Ram quanto em ficheiro
int removerImoveis(IMOVEL imoveis[],int tot); // Remove as informações de um imovel tanto da memoria Ram quanto do ficheiro
void alterarvalorAImovel(IMOVEL imoveis[],int tot); // Altera as informações(valor base do aluguel) de um imovel tanto da memoria Ram quanto do ficheiro
void alterarObsImovel(IMOVEL imoveis[],int tot); // Altera as informações(observações) de um imovel tanto da memoria Ram quanto do ficheiro
void alterarClasEneImovel(IMOVEL imoveis[],int tot); // Altera as informações(Classe Energetica) de um imovel tanto da memoria Ram quanto do ficheiro
void alterarTipoImovel(IMOVEL imoveis[],int tot); // Altera as informações(Tipo) de um imovel tanto da memoria Ram quanto do ficheiro
void alterarAreaImovel(IMOVEL imoveis[],int tot); // Altera as informações(Area) de um imovel tanto da memoria Ram quanto do ficheiro
int listarTodosImoveis(IMOVEL imoveis[],int tot); // Lista todos os imoveis
int listarImoveisOrdemVal(IMOVEL imoveis[],int tot); // Lista os imoveis por ordem cresente do Valor Do Aluguel
int listarImoveisOrdemAno(IMOVEL imoveis[],int tot); // Lista os imoveis por ordem decrescente de Ano de Construção
int DeReAtivarImoveis(IMOVEL imoveis[],int tot); // Desativa ou Reativa um imovil escolhido pelo utilizador
void listarUmImovel(IMOVEL imovel); // Lista um unico imovel(função usada como base para todas as outras funções de listar imoveis)
int filtrarImoveisAnimais(IMOVEL imoveis[],int tot); // Lista imoveis que permitem animais
int filtrarImoveisCidade(IMOVEL imoveis[],int tot); // Lista imoveis que sejam de uma cidade esolhida pelo utilizador
int filtrarImoveisTipo(IMOVEL imoveis[],int tot); // lista imoveis que sejam do tipo esolhido pelo utilizador
#endif