#include "menu.h"
#include "data.h"
#include "clientes.h"
#include "imoveis.h"
#include "alugueis.h"

int main (int argc, char *argv[]) {
    int op=0,numimoveis=0,numclientes=0;
    CLIENTE clientes[500];
    IMOVEL imoveis[200];
    setlocale(LC_ALL,"Portuguese_Brazil");
    carregarclientes(clientes, &numclientes);
    carregarimoveis(imoveis, &numimoveis);
    do{
        system("CLS");
        switch (op)
        {
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
            op=menuAluguel();
            break;
        case 11:
            op=AdicionarCliente(clientes,numclientes);
            numclientes++;
            guardarclientes(clientes,numclientes);
            break;
        case 14:
            op=listarTodosClientes(clientes,numclientes);
            break;
        case 21:
            op=AdicionarImoveis(imoveis,numimoveis);
            numimoveis++;
            guardarimoveis(imoveis,numimoveis);
            break;
        case 22:
            removerImoveis(imoveis,numimoveis);
            numimoveis--;
            op = 2;
            guardarimoveis(imoveis,numimoveis);
        case 23:
            op=menuAlterarImovel();
            break;
        case 231:
            alterarvalorAImovel(imoveis,numimoveis);
            op = 2;
            break;
        case 232:
            alterarObsImovel(imoveis,numimoveis);
            op = 2;
            break;
        case 233:
            alterarClasEneImovel(imoveis,numimoveis);
            op = 2;
            break;
        case 234:
            alterarTipoImovel(imoveis,numimoveis);
            op = 2;
            break;
        case 235:
            alterarAreaImovel(imoveis,numimoveis);
            op = 2;
            break;
        case 24:
            op=listarTodosImoveis(imoveis,numimoveis);
            break;
        case 25:
            op=menuListarImoveisOrdem();
            break;
        case 251:
            op=listarImoveisOrdemVal(imoveis,numimoveis);
            break;
        case 252:
            op=listarImoveisOrdemAno(imoveis,numimoveis);
            break;
        case 31:
            op= AdicionarAluguel(imoveis,numimoveis);
            break;
        default:
            
            break;
        }
        
    } while(op!=0);
    libertarAlugueis(imoveis, numimoveis);
    return 0;
}