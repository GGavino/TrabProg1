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
        case 13:
            op=menuAlterarClientes(clientes,numclientes);
            break;
        case 131:
            alterarClienteTelefone(clientes,numclientes);
            op = 1;
            break;
        case 132:
            alterarClienteEmail(clientes,numclientes);
            op = 1;
            break;
        case 14:
            op=listarTodosClientes(clientes,numclientes);
            break;
        case 15:
            op=menuListarClientesOrdem();
            break;
        case 151:
            op=listarClientesAlf(clientes,numclientes);
            break;
        case 152:
            op=listarClientesNif(clientes,numclientes);
            break;
        case 153:
            op=listarClientesPais(clientes,numclientes);
            break;
        case 154:
            op=listarClientesMorada(clientes,numclientes);
            break;
        case 155:
            op=listarClientesEmail(clientes,numclientes);
            break;
        case 16:
            op=menuFiltrarClientes();
            break;
        case 161:
            op=filtrarClientePais(clientes,numclientes);
            break;
        case 162:
            op=filtrarClienteNome(clientes,numclientes);
            break;
        case 163:
            op=filtrarClienteNif(clientes,numclientes);
            break;
        case 164:
            op=filtrarClienteTelefone(clientes,numclientes);
            break;
        case 165:
            op=filtrarClientePassaporte(clientes,numclientes);
            break;
        case 166:
            op=filtrarClienteEmail(clientes,numclientes);
            break;
        case 21:
            op=AdicionarImoveis(imoveis,numimoveis);
            numimoveis++;
            guardarimoveis(imoveis,numimoveis);
            break;
        case 22:
            numimoveis= numimoveis-removerImoveis(imoveis,numimoveis);
            op = 2;
            guardarimoveis(imoveis,numimoveis);
            break;
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
        case 26:
            op=menuFiltrarImoveis();
            break;
        case 261:
            op=filtrarImoveisAnimais(imoveis,numimoveis);
            break;
        case 262:
            op=filtrarImoveisCidade(imoveis,numimoveis);
            break;
        case 263:
            op=filtrarImoveisTipo(imoveis,numimoveis);
            break;
        case 27:
            op=DeReAtivarImoveis(imoveis,numimoveis);
            guardarimoveis(imoveis,numimoveis);
            break;
        case 31:
            op= AdicionarAluguel(imoveis,numimoveis,numclientes);
            guardarimoveis(imoveis,numimoveis);
            break;
        case 32:
            op=listarImoveisDisponiveis(imoveis,numimoveis);
            break;
        case 33:
            op=listarAlugueisImovel(imoveis,numimoveis);
            break;
        case 34:
            op=listarAlugueisCliente(imoveis,numimoveis,clientes,numclientes);
            break;
        case 35:
            op=listarTodosAlugueis(imoveis,numimoveis);
            break;
        case 36:
            op=fechoDia(imoveis,numimoveis);
            break;
        case 37:
            op=fechoMes(imoveis,numimoveis);
            break;
        case 38:
            op=fechoAno(imoveis,numimoveis);
            break;
        default:
            op = menuini();
            break;
        }
        
    } while(op!=0);
    libertarAlugueis(imoveis, numimoveis);
    return 0;
}