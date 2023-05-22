#ifndef DATA_H_
#define DATA_H_


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>


typedef struct AluguelData{
    int diapag,mespag,anopag,diaini,mesini,anoini,diafim,mesfim,anofim,clientid;
    float valor;
} ALUGUELD;

typedef struct AluguelElem{
    
    ALUGUELD data;
    struct AluguelElem *proximo,*anterior;

} AluguelList;

typedef struct Imovel {
    char tipo[50],morada[100],cidade[50],freguesia[50],energiaclass[50],observacao[100];
    int area,banheiros,ano,ativo,id,totalugueis;
    float valaluguel;
    AluguelList *alugueis;

} IMOVEL;

typedef struct Cliente {
    char nome[100];
    char passaporte[100];
    char telefone[100];
    char nif[100];
    char pais[50];
    char email[254];
    char morada[100];
    int id;
}CLIENTE;


int guardarclientes(CLIENTE clientes[],int tot);
int carregarclientes(CLIENTE clientes[],int *tot);
int guardarimoveis(IMOVEL imoveis[],int tot);
int carregarimoveis(IMOVEL imoveis[],int *tot);
void AdicionarAlugelNaLista(IMOVEL imoveis[], ALUGUELD info, int id);
void libertarAlugueis(IMOVEL imoveis[], int tot);   

#endif