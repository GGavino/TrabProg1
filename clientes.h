#ifndef CLIENTES_H_
#define CLIENTES_H_

#include "data.h"


int AdicionarCliente(CLIENTE clientes[], int tot); // Lista as informa��es de um novo cliente e o armazena tando na memoria Ram quanto em ficheiro;
int listarTodosClientes(CLIENTE clientes[],int tot);// Lista Todos os clientes;
void listarUmCliente(CLIENTE clientes[],int id);// Lista um unico cliente(fun��o usada como base para todas as outras fun��o de listar clientes);
int listarClientesAlf(CLIENTE clientes[],int tot);// Lista Todos os clientes por ordem alfab�tica;
int listarClientesNif(CLIENTE clientes[],int tot);// Lista todos os clientes por ordem do NIF;
int listarClientesPais(CLIENTE clientes[],int tot);// Lista todos os clientes por ordem do Pa�s;
int listarClientesMorada(CLIENTE clientes[],int tot);// Lista todos os clientes por ordem da morada;
int listarClientesEmail(CLIENTE clientes[],int tot);// Lista todos os clientes por ordem do email;
void alterarClienteTelefone(CLIENTE clientes[], int tot);// Altera o n�mero de telefone do cliente;
void alterarClienteEmail(CLIENTE clientes[], int tot);// Altera o email do cliente;
void alterarClienteNome(CLIENTE clientes[], int tot);// Altera o nome do cliente;
void alterarClientePais(CLIENTE clientes[], int tot);// Altera o cliente do pa�s;
int deletarCliente(IMOVEL imoveis[], int totimo,CLIENTE clientes[], int tot);// Remove um cliente;
int filtrarClientePais(CLIENTE clientes[],int tot);// Filtra todos os clientes de um determinado pais;
int filtrarClienteNome(CLIENTE clientes[],int tot);// Filtra todos os clientes de um determinado usu�rio;
int filtrarClienteNif(CLIENTE clientes[],int tot);// Filtra todos os clientes com um determinado nif;
int filtrarClienteTelefone(CLIENTE clientes[],int tot);// Filtra todos os clientes com um determinado n�mero de telefone;
int filtrarClientePassaporte(CLIENTE clientes[],int tot);// Filtra todos os clientes com um determinado passaporte;
int filtrarClienteEmail(CLIENTE clientes[],int tot);// Filtra todos os clientes com um determinado email;
#endif