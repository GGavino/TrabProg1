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
        printf("\n2- Gerenciar Imoveis");
        printf("\n3- Alugueis");
        printf("\n0- Sair");
        printf("\n------------------------------\n");
        printf("\nOp��o: ");
        fflush(stdin);
        scanf("%d",&i);
        if(i<0 || i>3)
        {
            system("CLS");
            printf("Op��o invalida");
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
        printf("\n0- Voltar");
        printf("\n------------------------------\n");
        printf("\nOp��o: ");
        fflush(stdin);
        scanf("%d",&i);
        if(i<0 || i>5)
        {
            system("CLS"); 
            printf("Op��o invalida");
        }
    }

    return 10+i;
}


int menuimovel(){
    int i=100;
    while(i<0 || i>7){
        titulo("Im�veis");
        printf("\n\n1- Adcionar Im�veis");
        printf("\n2- Excluir Im�veis");
        printf("\n3- Alterar Im�veis");
        printf("\n4- Listar Im�veis");
        printf("\n5- Listar Im�veis por ordem");
        printf("\n6- Filtrar Im�veis");
        printf("\n7- Ativar/Desativar um Im�vel");
        printf("\n0- Voltar");
        printf("\n------------------------------\n");
        printf("\nOp��o: ");
        fflush(stdin);
        scanf("%d",&i);
        if(i<0 || i>7)
        {
            system("CLS");
            printf("Op��o invalida");
        }
    }
    return 20+i;
}

int menuAlterarImovel(){
    int i=100;
    while(i<0 || i>5){
        titulo("Alterar Imovel");
        printf("\n\n1- Alterar valor base do aluguel");
        printf("\n2- Alterar observa��es");
        printf("\n3- Alterar Classe Energetica");
        printf("\n4- Alterar tipo do Im�vel");
        printf("\n5- Alterar Area do Im�vel");
        printf("\n0- Voltar");
        printf("\n------------------------------\n");
        printf("\nOp��o: ");
        fflush(stdin);
        scanf("%d",&i);
        if(i<0 || i>5)
        {
            system("CLS");
            printf("Op��o invalida");
        }
    }
    if (i==0) return 2;
    return i +230;
}
int menuListarImoveisOrdem(){
    int i=100;
    while(i<0 || i>2){
        titulo("Listar Imoveis por ordem");
        printf("\n\n1- Listar por valo do aluguel");
        printf("\n2- Listar por ordem decrescente do ano de constru��o");
        printf("\n0- Voltar");
        printf("\n------------------------------\n");
        printf("\nOp��o: ");
        fflush(stdin);
        scanf("%d",&i);
        if(i<0 || i>2)
        {
            system("CLS");
            printf("Op��o invalida");
        }
    }
    if (i==0) return 2;
    return i+250;
}
int menuFiltrarImoveis(){
    int i=100;
    while(i<0 || i>3){
        titulo("Filtrar Imoveis por");
        printf("\n\n1- Permitir Animais");
        printf("\n2- Cidade");
        printf("\n3- Tipo");
        printf("\n0- Voltar");
        printf("\n------------------------------\n");
        printf("\nOp��o: ");
        fflush(stdin);
        scanf("%d",&i);
        if(i<0 || i>3)
        {
            system("CLS");
            printf("Op��o invalida");
        }
    }
    if (i==0) return 2;
    return i+260;
}
int menuAluguel(){
    int i=100;
    while(i<0 || i>7){
        titulo("Im�veis");
        printf("\n\n1- Adcionar Aluguel");
        printf("\n2- Listar Im�veis disponiveis");
        printf("\n3- Listar Alugueis de um Im�vel");
        printf("\n4- Listar Alugueis de um Cliente");
        printf("\n5- Listar Alugueis de todos os Im�veis");
        printf("\n6- Fecho do dia");
        printf("\n7- Fecho do mes");
        printf("\n8- Fecho do ano");
        printf("\n0- Voltar");
        printf("\n------------------------------\n");
        printf("\nOp��o: ");
        fflush(stdin);
        scanf("%d",&i);
        if(i<0 || i>7)
        {
            system("CLS");
            printf("Op��o invalida");
        }
    }
    return 30+i;
}