#ifndef DATA_H_
#define DATA_H_


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>


typedef struct data{
    int dia,mes,ano;
}DATA;

typedef struct AluguelData{
    int clientid;
    DATA pagamento,inicio,fim;
    float valor;
} ALUGUELD;

typedef struct AluguelElem{
    
    ALUGUELD data;
    struct AluguelElem *proximo,*anterior;

} AluguelList;

typedef struct Imovel {
    char tipo[50],morada[100],cidade[50],freguesia[50],energiaclass[50],observacao[100];
    int area,banheiros,ano,ativo,id,totalugueis,animais;
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


int guardarclientes(CLIENTE clientes[],int tot); // Guarda as informações dos clientes da memoria RAM para o ficheiro
int carregarclientes(CLIENTE clientes[],int *tot); // Carrega as informações dos clientes do ficheiro para a memoria RAM
int guardarimoveis(IMOVEL imoveis[],int tot); // Guarda as informações dos imoveis e alugueis da memoria RAM para o ficheiro
int carregarimoveis(IMOVEL imoveis[],int *tot); // Carrega as informações dos imoveis e alugueis do ficheiro para a memoria RAM
void AdicionarAlugelNaLista(IMOVEL imoveis[], ALUGUELD info, int id); // Adciona um novo aluguel a lista ligada, sempre em ordem cresente das datas
void libertarAlugueis(IMOVEL imoveis[], int tot); // Função que liberta os a lugueis da memoria para evitar fuga de memoria
void removerAlugueisDoCliente(IMOVEL imoveis[],int tot, int id); // Função usada para remover todos os alugueis de um cliente quando o mesmo é removido
int Bissexto(int ano); // Verifica se um ano é Bissexto, retorna 1 caso sim e 0 caso não
int validardata(DATA data); // Verifica se a data é valida(exemplo de data invalida: 30 de fevereiro), retorna 1 caso sim e 0 caso não
int comparardatas(DATA data1, DATA data2); // Recebe duas datas e recebe o numero de dias de diferença entra a primeira e a segunda

#endif