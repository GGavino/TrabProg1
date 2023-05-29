#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "alugueis.h"

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
    fclose(fp);
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
            listarUmAluguel(aluguelinfo);
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
        printf("Erro ao carregar os imoveis e alugueis em ficheiro");
        return -1;
    }
    fread(tot,sizeof(int),1,fp);
    for(int i=0;i<*tot;i++){
        printf("i=%d\n",i);
        fread(&imoveis[i],sizeof(IMOVEL),1,fp);
        imoveis[i].alugueis=NULL;
        printf("%d",imoveis[i].totalugueis);
        for(int j=0;j<imoveis[i].totalugueis;j++){
            fread(&aluguelinfo,sizeof(ALUGUELD),1,fp);
            listarUmAluguel(aluguelinfo);
            AdicionarAlugelNaLista(imoveis, aluguelinfo, i);
            printf("teste1");
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
    }else if(comparardatas(info.inicio,imoveis[id].alugueis->data.inicio)> 0){
        newAluguel->proximo = imoveis[id].alugueis;
        imoveis[id].alugueis->anterior=newAluguel;
        imoveis[id].alugueis = newAluguel;
    } else {
        while (current->proximo != NULL && comparardatas(info.inicio,current->data.inicio)> 0) {
            current = current->proximo;
        }
        if(current->proximo ==NULL){
            newAluguel->anterior= current;
            current->proximo = newAluguel;
        }else{
            newAluguel->proximo = current;
            newAluguel->anterior= current->anterior;
            current->anterior->proximo = newAluguel;
            current->anterior = newAluguel;
        }
    }
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
                aux2->proximo->anterior=aux2->anterior;
                aux2->anterior->proximo=aux2->proximo;
                imoveis[i].totalugueis--;
                free(aux2);
            }else if(aux2->data.clientid > id) aux2->data.clientid--;
        }
        aux2 = aux->anterior;
        if(aux2->data.clientid == id ) {
            aux2->proximo->anterior=aux2->anterior;
            aux2->anterior->proximo=aux2->proximo;
            imoveis[i].totalugueis--;
            free(aux2);
        }else if(aux2->data.clientid > id) aux2->data.clientid--;
        if(aux->data.clientid == id ) {
            aux->proximo->anterior=aux->anterior;
            aux->anterior->proximo=aux->proximo;
            imoveis[i].totalugueis--;
            free(aux);
         }else if(aux->data.clientid > id) aux->data.clientid--;
    }
}


int DiasDeUmMes(int mes, int ano) {
    int Diames[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (mes == 2 && Bissexto(ano))
        return 29;

    return Diames[mes - 1];
}

int comparardatas(DATA data1, DATA data2) {
    int days1 = 0, days2 = 0;

    for (int i = 1; i < data1.mes; i++)
        days1 += DiasDeUmMes(i, data1.ano);

    for (int i = 1; i < data2.mes; i++)
        days2 += DiasDeUmMes(i, data2.ano);

    days1 += data1.dia;
    days2 += data2.dia;

    for (int i = 1; i < data1.ano; i++)
        days1 += Bissexto(i) ? 366 : 365;

    for (int i = 1; i < data2.ano; i++)
        days2 += Bissexto(i) ? 366 : 365;

    return days2 - days1;
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
