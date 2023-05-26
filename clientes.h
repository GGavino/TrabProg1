#ifndef CLIENTES_H_
#define CLIENTES_H_

#include "data.h"


int AdicionarCliente(CLIENTE clientes[], int tot); // L� as informa��es de um novo cliente e o armazena tando na memoria Ram quanto em ficheiro;
int listarTodosClientes(CLIENTE clientes[],int tot);// Lista Todos os clientes;
void listarUmCliente(CLIENTE clientes[],int id);// Lista um unico cliente(fun��o usada como base para todas as outras fun��es de listar clientes);
int listarClientesAlf(CLIENTE clientes[],int tot);// Lista Todos os clientes por ordem alfab�tica;
int listarClientesNif(CLIENTE clientes[],int tot);// Lista todos os clientes por ordem do NIF;
int filtrarClientePais(CLIENTE clientes[],int tot);// Lista todos os clientes de um determinado pais;
#endif