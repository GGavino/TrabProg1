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
        printf("\nOpção: ");
        fflush(stdin);
        scanf("%d",&i);
        if(i<0 || i>3)
        {
            system("CLS");
            printf("Opção invalida");
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
        fflush(stdin);
        scanf("%d",&i);
        if(i<0 || i>5)
        {
            system("CLS"); 
            printf("Opção invalida");
        }
    }

    return 10+i;
}


int menuimovel(){
    int i=100;
    while(i<0 || i>5){
        titulo("Imóveis");
        printf("\n\n1- Adcionar Imóveis");
        printf("\n2- Excluir Imóveis");
        printf("\n3- Alterar Imóveis");
        printf("\n4- Listar Imóveis");
        printf("\n5- Filtrar Imóveis");
        printf("\n0- Sair");
        printf("\n------------------------------\n");
        printf("\nOpção: ");
        fflush(stdin);
        scanf("%d",&i);
        if(i<0 || i>5)
        {
            system("CLS");
            printf("Opção invalida");
        }
    }
    return 20+i;
}
int menuAluguel(){
    int i=100;
    while(i<0 || i>5){
        titulo("Imóveis");
        printf("\n\n1- Adcionar Aluguel");
        printf("\n2- Listar Imóveis disponiveis");
        printf("\n3- Listar Alugueis de um Imóvel");
        printf("\n4- Listar Alugueis de todos os Imóveis");
        printf("\n0- Sair");
        printf("\n------------------------------\n");
        printf("\nOpção: ");
        fflush(stdin);
        scanf("%d",&i);
        if(i<0 || i>5)
        {
            system("CLS");
            printf("Opção invalida");
        }
    }
    return 30+i;
}