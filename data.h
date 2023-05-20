#ifndef DATA_H_
#define DATA_H_


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>


typedef struct AluguelData{
    int diaini,mesini,anoini,diafim,mesfim,anofim,clientid;
    float valor;
} ALUGUELD;

typedef struct AluguelElem{
    
    ALUGUELD data;
    struct AluguelElem *proximo,*anterior;

} AluguelList;

typedef struct Imovel {
    char tipo[5],morada[100],cidade[50],freguesia[50],energiaclass[5],observacao[100];
    int area,banheiros,ano,ativo,id,totalugueis;
    float valaluguel;
    AluguelList *alugueis;

} IMOVEL;

typedef struct Cliente {
    char nome[100],nif[9],passaporte[7],morada[100],pais[50],email[254];
    int id;
}CLIENTE;


int guardarclientes(CLIENTE clientes[],int tot);
int carregarclientes(CLIENTE clientes[],int *tot);
int guardarimoveis(IMOVEL imoveis[],int tot);
int carregarimoveis(IMOVEL imoveis[],int *tot);
void AdicionarNovoAlugel(IMOVEL imoveis[], ALUGUELD info, int id);

#endif