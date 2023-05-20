#include "menu.h"
#include "data.h"
#include "clientes.h"
#include "imoveis.h"

int main (int argc, char *argv[]) {
    int op=0,numimoveis=0,numclientes=0;
    CLIENTE clientes[500];
    IMOVEL imoveis[200];
    setlocale(LC_ALL,"Portuguese_Brazil");
    carregarclientes(clientes, &numclientes);
    carregarimoveis(imoveis, &numimoveis);
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
        case 12:
            op=listarClientes(clientes,numclientes);
            break;
        case 21:
            op=AdicionarImoveis(imoveis,numimoveis);
            numimoveis++;
            break;
        case 22:
            op=listarImoveis(imoveis,numimoveis);
            break;
        default:
            
            break;
        }
        
    } while(op!=0);
    return 0;
}