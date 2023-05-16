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
    fp= fopen("clientes.dat", "wb");
    if (fp==NULL){
        printf("Erro ao guardar os imoveis e alugueis em ficheiro");
        return -1;
    }
    fwrite(&tot,sizeof(int),1,fp);
    for(int i=0;i<tot;i++){
        fwrite(&imoveis[i],sizeof(IMOVEL),1,fp);
        aluguellista = imoveis[i].alugueis;
        aluguelinfo=aluguellista->data;
        for(int j=0;j<imoveis[i].totalugueis;j++){
            fwrite(&aluguelinfo,sizeof(ALUGUELD),1,fp);
        }
    }
    fclose(fp);
}
int carregarimoveis(IMOVEL imoveis[],int *tot){
    FILE *fp;
    ALUGUELD aluguelinfo;
    fp= fopen("clientes.dat", "rb");
    if (fp==NULL){
        printf("Erro ao guardar os imoveis e alugueis em ficheiro");
        return -1;
    }
    fread(tot,sizeof(int),1,fp);
    for(int i=0;i<*tot;i++){
        fread(&imoveis[i],sizeof(IMOVEL),1,fp);
        for(int j=0;j<imoveis[i].totalugueis;j++){
            fread(&aluguelinfo,sizeof(ALUGUELD),1,fp);
            AdicionarNovoAlugel(imoveis, aluguelinfo, j);
        }
    }
    fclose(fp);
}

void AdicionarNovoAlugel(IMOVEL imoveis[], ALUGUELD info, int id){
    AluguelList *newAluguel = (AluguelList*)calloc(1,sizeof(AluguelList));
    newAluguel->data = info;
    newAluguel->proximo = NULL;
    newAluguel->anterior = NULL;
    AluguelList *current = imoveis[id].alugueis;

    if (imoveis[id].alugueis == NULL) {
        imoveis[id].alugueis = newAluguel;
    }else if((12*info.anoini + info.mesini + info.diaini / 100) < (12*imoveis[id].alugueis->data.anoini + imoveis[id].alugueis->data.mesini + imoveis[id].alugueis->data.diaini / 100)){
        newAluguel->proximo = imoveis[id].alugueis;
        imoveis[id].alugueis = newAluguel;
    } else {
        while (current->proximo != NULL && (12*info.anoini + info.mesini + info.diaini / 100) < (12*current->data.anoini + current->data.mesini + current->data.diaini / 100)) {
            current = current->proximo;
        }
        current->anterior = newAluguel;
        newAluguel->proximo = current;
        newAluguel->anterior= current->anterior->anterior;
        current->anterior->proximo = newAluguel;
    }

    imoveis[id].totalugueis++;
}

