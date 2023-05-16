#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void titulo(char titulo[]) {
    printf("------------------------------\n");
    printf("   %s\n", titulo);
    printf("------------------------------\n");

}



int menuini(){
    int i=100;
    while(i<0 || i>3){
        titulo("Inicio");
        printf("\n\n1- Gerenciar Clientes");
        printf("\n2- Gerenciar Moveis");
        printf("\n3- Alugueis");
        printf("\n0- Sair");
        printf("\n------------------------------\n");
        printf("\nOpcao: ");
        scanf("%d",&i);
        if(i<0 || i>3)
        {
            system("CLS");
            printf("Opcao invalida");
        }
    }
    return i;



}


int menuclientes(){
   int i=100;
   while(i<0 || i>5){
        titulo("Clientes");
        printf("\n\n1- Adcionar Clientes");
        printf("\n2- Excluir Clientes");
        printf("\n3- Alterar Clientes");
        printf("\n4- Listar Clientes");
        printf("\n5- Filtrar Clientes");
        printf("\n0- Sair");
        printf("\n------------------------------\n");
        printf("\nOpção: ");
        scanf("%d",&i);
        if(i<0 || i>5)
        {
            system("CLS"); 
            printf("Opcao invalida");
        }
    }

    return 10+i;
}


int menuimovel(){
    int i=100;
    while(i<0 || i>5){
        titulo("Imoveis");
        printf("\n\n1- Adcionar Imoveis");
        printf("\n2- Excluir Imoveis");
        printf("\n3- Alterar Imoveis");
        printf("\n4- Listar Imoveis");
        printf("\n5- Filtrar Imoveis");
        printf("\n0- Sair");
        printf("\n------------------------------\n");
        printf("\nOpção: ");
        scanf("%d",&i);
        if(i<0 || i>5)
        {
            system("CLS");
            printf("Opcao invalida");
        }
    }
    return 20+i;
}