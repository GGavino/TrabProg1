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
        printf("\n\n1- Adicionar Clientes");
        printf("\n2- Excluir Clientes");
        printf("\n3- Alterar Clientes");
        printf("\n4- Listar Clientes");
        printf("\n5- Filtrar Clientes");
        printf("\n0- Voltar");
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

int menuListarClientes(){
   int i=100;
   while(i<0 || i>3){
        titulo("Clientes");
        printf("\n\n1- Listar clientes por ordem alfabética");
        printf("\n2- Listar clientes por ordem do NIF");
        printf("\n3- Listar clientes de um determinado país");
        printf("\n0- Voltar");
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
    if (i==0) return 1;
    return 140+i;
}


int menuimovel(){
    int i=100;
    while(i<0 || i>7){
        titulo("Imóveis");
        printf("\n\n1- Adcionar Imóveis");
        printf("\n2- Excluir Imóveis");
        printf("\n3- Alterar Imóveis");
        printf("\n4- Listar Imóveis");
        printf("\n5- Listar Imóveis por ordem");
        printf("\n6- Filtrar Imóveis");
        printf("\n7- Ativar/Desativar um Imóvel");
        printf("\n0- Voltar");
        printf("\n------------------------------\n");
        printf("\nOpção: ");
        fflush(stdin);
        scanf("%d",&i);
        if(i<0 || i>7)
        {
            system("CLS");
            printf("Opção invalida");
        }
    }
    return 20+i;
}

int menuAlterarImovel(){
    int i=100;
    while(i<0 || i>5){
        titulo("Alterar Imovel");
        printf("\n\n1- Alterar valor base do aluguel");
        printf("\n2- Alterar observações");
        printf("\n3- Alterar Classe Energetica");
        printf("\n4- Alterar tipo do Imóvel");
        printf("\n5- Alterar Area do Imóvel");
        printf("\n0- Voltar");
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
    if (i==0) return 2;
    return i +230;
}
int menuListarImoveisOrdem(){
    int i=100;
    while(i<0 || i>2){
        titulo("Listar Imoveis por ordem");
        printf("\n\n1- Listar por valo do aluguel");
        printf("\n2- Listar por ordem decrescente do ano de construção");
        printf("\n0- Voltar");
        printf("\n------------------------------\n");
        printf("\nOpção: ");
        fflush(stdin);
        scanf("%d",&i);
        if(i<0 || i>2)
        {
            system("CLS");
            printf("Opção invalida");
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
        printf("\nOpção: ");
        fflush(stdin);
        scanf("%d",&i);
        if(i<0 || i>3)
        {
            system("CLS");
            printf("Opção invalida");
        }
    }
    if (i==0) return 2;
    return i+260;
}
int menuAluguel(){
    int i=100;
    while(i<0 || i>8){
        titulo("Imóveis");
        printf("\n\n1- Adcionar Aluguel");
        printf("\n2- Listar Imóveis disponiveis");
        printf("\n3- Listar Alugueis de um Imóvel");
        printf("\n4- Listar Alugueis de um Cliente");
        printf("\n5- Listar Alugueis de todos os Imóveis");
        printf("\n6- Fecho do dia");
        printf("\n7- Fecho do mes");
        printf("\n8- Fecho do ano");
        printf("\n0- Voltar");
        printf("\n------------------------------\n");
        printf("\nOpção: ");
        fflush(stdin);
        scanf("%d",&i);
        if(i<0 || i>8)
        {
            system("CLS");
            printf("Opção invalida");
        }
    }
    return 30+i;
}