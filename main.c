#include <string.h>
#include "menu.h"
#include "data.h"
#include "clientes.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

int main (int argc, char *argv[]) {
    int op=0,numimoveis=0,numclientes=0;
    CLIENTE clientes[500];
    IMOVEL imoveis[200];
    setlocale(LC_ALL,"Portuguese");
    carregarclientes(clientes, &numclientes);
    // printf("Teste: ãçàá");
    do{
        switch (op)
        {
            system("CLS"); 
        case 0:
        case 10:
        case 20:
        case 30:
            op = menuini();
            break;
        case 1:
            op = menuclientes();
            break;
        case 2:
            op = menuimovel();
            break;

        case 3:

            break;
        case 11:
            op=AdicionarCliente(clientes,numclientes);
            numclientes++;
            break;
        default:
            
            break;
        }
        
    } while(op!=0);
    return 0;
}