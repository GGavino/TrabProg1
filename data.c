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