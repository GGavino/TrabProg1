#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

int guardarclientes(CLIENTE clientes[],int tot){
    FILE *fp;
    fp= fopen("clientes.dat", "wb");
    if (fp==NULL){
        printf("Erro ao guardar os cientes em ficheiro");
        return -1;
    }
    fwrite(&tot,sizeof(int),1,fp);
    fwrite(clientes,sizeof(CLIENTE),tot,fp);
    fclose(fp);
}

int carregarclientes(CLIENTE clientes[],int *tot){
    FILE *fp;
    fp= fopen("clientes.dat", "rb");
    if (fp==NULL){
        printf("Erro ao carregar os cientes do ficheiro");
        return -1;
    }
    fread(tot,sizeof(int),1,fp);
    fread(clientes,sizeof(CLIENTE), *tot,fp);
}


int guardarimoveis(IMOVEL imoveis[],int tot){
    FILE *fp;
    ALUGUELD aluguelinfo;
    AluguelList *aluguellista;
    fp= fopen("imoveis.dat", "wb");
    if (fp==NULL){
        printf("Erro ao guardar os imoveis e alugueis em ficheiro");
        return -1;
    }
    fwrite(&tot,sizeof(int),1,fp);
    for(int i=0;i<tot;i++){
        fwrite(&imoveis[i],sizeof(IMOVEL),1,fp);
        for(aluguellista = imoveis[i].alugueis; aluguellista != NULL; aluguellista=aluguellista->proximo) {
            aluguelinfo=aluguellista->data;
            fwrite(&aluguelinfo,sizeof(ALUGUELD),1,fp);
        }
    }
    fclose(fp);
}
int carregarimoveis(IMOVEL imoveis[],int *tot){
    FILE *fp;
    ALUGUELD aluguelinfo;
    fp= fopen("imoveis.dat", "rb");
    if (fp==NULL){
        printf("Erro ao guardar os imoveis e alugueis em ficheiro");
        return -1;
    }
    fread(tot,sizeof(int),1,fp);
    for(int i=0;i<*tot;i++){
        fread(&imoveis[i],sizeof(IMOVEL),1,fp);
        for(int j=0;j<imoveis[i].totalugueis;j++){
            fread(&aluguelinfo,sizeof(ALUGUELD),1,fp);
            AdicionarAlugelNaLista(imoveis, aluguelinfo, j);
        }
    }
    fclose(fp);
}

void AdicionarAlugelNaLista(IMOVEL imoveis[], ALUGUELD info, int id){
    AluguelList *newAluguel = (AluguelList*)calloc(1,sizeof(AluguelList));
    newAluguel->data = info;
    newAluguel->proximo = NULL;
    newAluguel->anterior = NULL;
    AluguelList *current = imoveis[id].alugueis;

    if (imoveis[id].alugueis == NULL) {
        imoveis[id].alugueis = newAluguel;
    }else if(comparardatas(info.inicio,imoveis[id].alugueis->data.inicio)< 0){
        newAluguel->proximo = imoveis[id].alugueis;
        imoveis[id].alugueis = newAluguel;
    } else {
        while (current->proximo != NULL && comparardatas(info.inicio,current->data.inicio)< 0) {
            current = current->proximo;
        }
        newAluguel->proximo = current;
        newAluguel->anterior= current->anterior;
        current->anterior->proximo = newAluguel;
        current->anterior = newAluguel;
    }

    imoveis[id].totalugueis++;
}
void libertarAlugueis(IMOVEL imoveis[], int tot){
    AluguelList *aux=NULL,*aux2=NULL;
    
    for(int i=0;i<tot;i++){
        for(aux = imoveis[i].alugueis->proximo; aux->proximo != NULL; aux=aux->proximo) {
            if(aux->anterior!=NULL) aux2 = aux->anterior;
            if(aux2!=NULL) free(aux2);
        }
        aux2 = aux->anterior;
        free(aux2);
        free(aux);
    }

}
void removerAlugueisDoCliente(IMOVEL imoveis[],int tot, int id){
    AluguelList *aux=NULL,*aux2=NULL;
    
    for(int i=0;i<tot;i++){
        for(aux = imoveis[i].alugueis->proximo; aux->proximo != NULL; aux=aux->proximo) {
            aux2 = aux->anterior;
            if(aux2->data.clientid == id ) {
                free(aux2);
            }else if(aux2->data.clientid > id) aux2->data.clientid--;
        }
        aux2 = aux->anterior;
        if(aux2->data.clientid == id ) {
            free(aux2);
        }else if(aux2->data.clientid > id) aux2->data.clientid--;
        if(aux->data.clientid == id ) {
            free(aux);
         }else if(aux->data.clientid > id) aux->data.clientid--;
    }
}


int comparardatas(DATA data1, DATA data2){
    int dif=0;
    dif= data2.dia-data1.dia;
    for(dif=0; data1.dia!=data2.dia || data1.mes!=data2.mes || data1.ano!=data2.ano; ){
        if((12*data1.ano + data1.mes + data1.dia / 100) < (12*data2.ano + data2.mes + data2.dia / 100)){
            data2.dia--;
            if(data2.dia < 1){
                int DiasEmUmMes[] = {31, 28 + Bissexto(data2.ano), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
                data2.mes--;
                if(data2.mes<1){
                    data2.mes=12;
                    data2.ano--;
                }
                data2.dia = DiasEmUmMes[data2.mes - 1];
                dif--;
            }
        } else {
            data1.dia--;
            if(data1.dia < 1){
                int DiasEmUmMes[] = {31, 28 + Bissexto(data1.ano), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
                data1.mes--;
                if(data1.mes<1){
                    data1.mes=12;
                    data1.ano--;
                }
                data1.dia = DiasEmUmMes[data1.mes - 1];
                dif++;
            }
        }
    }

}

int Bissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int validardata(DATA data) {
    if (data.ano < 1 || data.mes < 1 || data.mes > 12 || data.dia < 1) {
        return 0;
    }

    int DiasEmUmMes[] = {31, 28 + Bissexto(data.ano), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int diasmax = DiasEmUmMes[data.mes - 1];

    if (data.dia > diasmax) return 0;

    return 1;
}
