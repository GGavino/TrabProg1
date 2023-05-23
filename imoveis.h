#ifndef IMOVEIS_H_
#define IMOVEIS_H_

#include "data.h"

int AdicionarImoveis(IMOVEL imoveis[], int tot);
void removerImoveis(IMOVEL imoveis[],int tot);
void alterarvalorAImovel(IMOVEL imoveis[],int tot);
void alterarObsImovel(IMOVEL imoveis[],int tot);
void alterarClasEneImovel(IMOVEL imoveis[],int tot);
void alterarTipoImovel(IMOVEL imoveis[],int tot);
void alterarAreaImovel(IMOVEL imoveis[],int tot);
int listarTodosImoveis(IMOVEL imoveis[],int tot);
int listarImoveisOrdemVal(IMOVEL imoveis[],int tot);
int listarImoveisOrdemAno(IMOVEL imoveis[],int tot);
void listarUmImovel(IMOVEL imovel);
#endif