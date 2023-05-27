#ifndef CLIENTES_H_
#define CLIENTES_H_

#include "data.h"


int AdicionarCliente(CLIENTE clientes[], int tot); // Lista as informações de um novo cliente e o armazena tando na memoria Ram quanto em ficheiro;
int listarTodosClientes(CLIENTE clientes[],int tot);// Lista Todos os clientes;
void listarUmCliente(CLIENTE clientes[],int id);// Lista um unico cliente(função usada como base para todas as outras função de listar clientes);
int listarClientesAlf(CLIENTE clientes[],int tot);// Lista Todos os clientes por ordem alfabética;
int listarClientesNif(CLIENTE clientes[],int tot);// Lista todos os clientes por ordem do NIF;
int listarClientesPais(CLIENTE clientes[],int tot);// Lista todos os clientes por ordem do País;
int listarClientesMorada(CLIENTE clientes[],int tot);// Lista todos os clientes por ordem da morada;
int listarClientesEmail(CLIENTE clientes[],int tot);// Lista todos os clientes por ordem do email;
void alterarClienteTelefone(CLIENTE clientes[], int tot);// Altera o número de telefone do cliente;
int filtrarClientePais(CLIENTE clientes[],int tot);// Filtra todos os clientes de um determinado pais;
int filtrarClienteNome(CLIENTE clientes[],int tot);// Filtra todos os clientes de um determinado usuário;
int filtrarClienteNif(CLIENTE clientes[],int tot);// Filtra todos os clientes com um determinado nif;
int filtrarClienteTelefone(CLIENTE clientes[],int tot);// Filtra todos os clientes com um determinado número de telefone;
int filtrarClientePassaporte(CLIENTE clientes[],int tot);// Filtra todos os clientes com um determinado passaporte;
int filtrarClienteEmail(CLIENTE clientes[],int tot);// Filtra todos os clientes com um determinado email;
#endif