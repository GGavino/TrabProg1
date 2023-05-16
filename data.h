#ifndef DATA_H_
#define DATA_H_
typedef struct AluguelData{
    int diaini,mesini,anoini,diafim,mesfim,anofim,clientid;
    float valor;
} ALUGUELD;

typedef struct AluguelElem{
    
    ALUGUELD data;
    struct AluguelElem *proximo;
    struct AluguelElem *anterior;

} AluguelList;

typedef struct Imovel {
    char tipo[50],morada[100],cidade[50],freguesia[50],energiaclass[5];
    int area,banheiros,ano,valaluguel,ativo,id;
    AluguelList aluguel;

} IMOVEL;

typedef struct Cliente {
    char nome[100],nif[9],passaporte[7],morada[100],pais[50],email[254];
    int id;
}CLIENTE;


int guardarclientes(CLIENTE clientes[],int tot);
int carregarclientes(CLIENTE clientes[],int *tot);
#endif