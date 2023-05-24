#ifndef CLIENTES_H_
#define CLIENTES_H_

#include "data.h"


int AdicionarCliente(CLIENTE clientes[], int tot); // Lê as informações de um novo cliente e o armazena tando na memoria Ram quanto em ficheiro
int listarTodosClientes(CLIENTE clientes[],int tot);// Lista Todos os clientes
void listarUmCliente(CLIENTE clientes[],int id);// Lista um unico cliente(função usada como base para todas as outras funções de listar clientes)


#endif 
