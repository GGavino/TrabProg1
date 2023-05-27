#include "clientes.h"
#include "data.h"

int AdicionarCliente(CLIENTE clientes[], int tot)
{
    int i = 0, aux = 0, dotcount, acount, atpos, dotpos;
    char res;
    printf("Qual o nome do cliente?\n");
    fflush(stdin);
    gets(clientes[tot].nome);
    printf("%s\n", clientes[tot].nome);
    printf("Qual a morada do cliente?\n");
    fflush(stdin);
    gets(clientes[tot].morada);
    printf("%s\n", clientes[tot].morada);
    printf("De qual país é o cliente?\n");
    fflush(stdin);
    gets(clientes[tot].pais);
    printf("%s\n", clientes[tot].pais);
    do
    {
        printf("Qual o nif do cliente?\n");
        fflush(stdin);
        gets(clientes[tot].nif);
        printf("%s\n", clientes[tot].nif);
        aux = 0;
        for (i = 0; i < tot && aux == 0; i++)
        {
            if (clientes[tot].nif == clientes[i].nif)
            {
                aux = 1;
                printf("Já existe um cliente com esse nif, por favor insira um nif diferente\n");
            }
        }
        if (strlen(clientes[tot].nif) != 9)
        {
            printf("Nif invalido, o nif deve ter 9 numeros\n");
            aux = 1;
        }
        for (i = 0; i < 9 && aux == 0; i++)
        {
            if (!isdigit(clientes[tot].nif[0]))
            {
                printf("Nif invalido, o nif deve ter apenas numeros\n");
                aux = 1;
            }
        }

        if (aux != 0)
            printf("\n\n");
    } while (aux != 0);
    do
    {
        printf("Qual o numero de telefone do cliente?\n");
        fflush(stdin);
        gets(clientes[tot].telefone);
        printf("%s\n", clientes[tot].telefone);
        aux = 0;
        for (i = 0; i < tot && aux == 0; i++)
        {
            if (clientes[tot].telefone == clientes[i].telefone)
            {
                aux = 1;
                printf("Já existe um cliente com esse numero, por favor insira um diferente\n");
            }
        }
        if (strlen(clientes[tot].telefone) != 9)
        {
            printf("Numero de telefone invalido, o telefone deve ter 9 numeros\n");
            aux = 1;
        }
        for (i = 0; i < 9 && aux == 0; i++)
        {
            if (!isdigit(clientes[tot].telefone[0]))
            {
                printf("Numero de telefone invalido, o telefone deve ter apenas numeros\n");
                aux = 1;
            }
        }

        if (aux != 0)
            printf("\n\n");
    } while (aux != 0);
    do
    {
        printf("Qual o numero de passaporte do cliente?\n");
        fflush(stdin);
        gets(clientes[tot].passaporte);
        printf("%s\n", clientes[tot].passaporte);
        aux = 0;
        for (i = 0; i < tot && aux == 0; i++)
        {
            if (clientes[tot].passaporte == clientes[i].passaporte)
            {
                aux = 1;
                printf("Já existe um cliente com esse numero de passaporte, por favor insira um diferente\n");
            }
        }
        if (strlen(clientes[tot].passaporte) != 7)
        {
            aux = 1;
            printf("Numero de passaporte invalido, o numero do passaporte deve ter um caractere seguido de 6 numeros\n");
        }
        else
        {
            if (isdigit(clientes[tot].passaporte[0]))
            {
                printf("Numero de passaporte invalido, o numero do passaporte deve ter um caractere seguido de 6 numeros\n");
                aux = 1;
            }
            else
            {
                for (i = 1; i < 7 && aux == 0; i++)
                {
                    if (!isdigit(clientes[tot].passaporte[i]))
                    {
                        printf("Numero de passaporte invalido, o numero do passaporte deve ter um caractere seguido de 6 numeros\n");
                        aux = 1;
                    }
                }
            }
        }
        if (aux != 0)
            printf("\n\n");
    } while (aux != 0);
    do
    {
        printf("Qual o email do cliente?\n");
        fflush(stdin);
        gets(clientes[tot].email);
        printf("%s\n", clientes[tot].email);
        aux = 0;
        dotcount = 0, acount = 0, dotpos = -1, atpos = -1;
        for (i = 0; i < tot && aux == 0; i++)
        {
            if (clientes[tot].email == clientes[i].email)
            {
                aux = 1;
                printf("Já existe um cliente com esse email, por favor insira um diferente");
            }
        }
        for (i = 0; i < strlen(clientes[tot].email); i++)
        {
            if (clientes[tot].email[i] == '@')
            {
                acount++;
                atpos = i;
            }
            else if (clientes[tot].email[i] == '.')
            {
                dotcount++;
                dotpos = i;
            }
        }
        if (strlen(clientes[tot].email) < 5)
        {
            aux = 1;
            printf("O email deve ter pelo menos 5 caracteres");
        }
        else if (isdigit(clientes[tot].email[0]))
        {
            printf("O primeiro caractere do email n pode ser um numero");
            aux = 1;
        }
        else if (dotcount == 0 || acount != 1)
        {
            printf("O email deve ter exatamente um '@' e pelo menos 1 '.'");
            aux = 1;
        }
        else if (dotpos == atpos + 1 || dotpos < atpos)
        {
            printf("Deve have pelo menos um caracter entre o '@' e o '.' e deve haver 1 '.' depois do '@'");
            aux = 1;
        }
        if (aux != 0)
            printf("\n\n");
    } while (aux != 0);
    clientes[tot].id = tot + 1;
    do
    {
        aux = 0;
        printf("\n\nDeseja inserir outro cliente?\n");
        fflush(stdin);
        scanf("%c", &res);
        if (res == 'S' || res == 's')
        {
            return 11;
        }
        else if (res == 'N' || res == 'n')
        {
            return 1;
        }
        else
        {
            printf("Resposta invalida");
            aux = 1;
        }
        if (aux != 0)
            printf("\n\n");
    } while (aux != 0);
}
int listarTodosClientes(CLIENTE clientes[], int tot)
{
    char aux, res;
    if (tot == 0)
    {
        printf("\nDeve Inserir clientes antes de usar esta função\n");
        printf("Digite qualquer coisa para voltar para o menu anterior\n");
        fflush(stdin);
        scanf("%c", &res);
        return 1;
    }
    printf("\n\n\
    ----------------------------------------\n\
                Lista de Clientes\n\n\
    ----------------------------------------\n\n\n");
    for (int i = 0; i < tot; i++)
    {
        listarUmCliente(clientes, i);
    }
    printf("Digite qualquer coisa para voltar para o menu anterior\n");
    fflush(stdin);
    scanf("%c", &aux);
    return 1;
}

void listarUmCliente(CLIENTE clientes[], int id)
{

    printf("Cliente %d:\n\n", clientes[id].id);
    printf("Nome: %s\n", clientes[id].nome);
    printf("Nif: %s\n", clientes[id].nif);
    printf("Numero de telefone: %s\n", clientes[id].telefone);
    printf("Passaporte: %s\n", clientes[id].passaporte);
    printf("Morada: %s\n", clientes[id].morada);
    printf("País: %s\n", clientes[id].pais);
    printf("Email: %s\n", clientes[id].email);
    printf("\n--------------------------------------------------\n\n\n");
}

/******************************************************************************************************************************************************************************
******************************************************************************** MUDANÇAS**************************************************************************************
******************************************************************************************************************************************************************************/

// ******************************************************************************ORDENAÇÃO*************************************************************************************

int listarClientesAlf(CLIENTE clientes[], int tot)
{
    char aux;
    int menor, ordem[tot], aux1;
    if (tot == 0)
    {
        printf("\nDeve Inserir clientes antes de usar esta função\n");
        printf("Digite qualquer coisa para voltar para o menu anterior\n");
        fflush(stdin);
        scanf("%c", &aux);
        return 1;
    }
    for (int i = 0; i < tot; i++)
        ordem[i] = i;
    for (int i = 0; i < tot; i++)
    {
        menor = i;
        for (int j = i + 1; j < tot; j++)
        {
            if (strcmp(clientes[ordem[j]].nome, clientes[ordem[menor]].nome) < 0)
                menor = j;
        }
        aux1 = ordem[i];
        ordem[i] = ordem[menor];
        ordem[menor] = aux1;
    }
    printf("\n\n\
    ----------------------------------------\n\
                Lista de clientes\n\n\
    ----------------------------------------\n\n\n");
    for (int i = 0; i < tot; i++)
    {
        listarUmCliente(clientes, ordem[i]);
    }
    printf("Digite qualquer coisa para voltar para o menu anterior\n");
    fflush(stdin);
    scanf("%c", &aux);
    return 15;
}

int listarClientesNif(CLIENTE clientes[], int tot)
{
    char aux;
    int menor, ordem[tot], aux1;
    if (tot == 0)
    {
        printf("\nDeve Inserir clientes antes de usar esta função\n");
        printf("Digite qualquer coisa para voltar para o menu anterior\n");
        fflush(stdin);
        scanf("%c", &aux);
        return 1;
    }
    for (int i = 0; i < tot; i++)
        ordem[i] = i;
    for (int i = 0; i < tot; i++)
    {
        menor = i;
        for (int j = i + 1; j < tot; j++)
        {
            if (strcmp(clientes[ordem[j]].nif, clientes[ordem[menor]].nif) < 0)
                menor = j;
        }
        aux1 = ordem[i];
        ordem[i] = ordem[menor];
        ordem[menor] = aux1;
    }
    printf("\n\n\
    ----------------------------------------\n\
                Lista de clientes\n\n\
    ----------------------------------------\n\n\n");
    for (int i = 0; i < tot; i++)
    {
        listarUmCliente(clientes, ordem[i]);
    }
    printf("Digite qualquer coisa para voltar para o menu anterior\n");
    fflush(stdin);
    scanf("%c", &aux);
    return 15;
}

int listarClientesPais(CLIENTE clientes[], int tot)
{
    char aux;
    int menor, ordem[tot], aux1;
    if (tot == 0)
    {
        printf("\nDeve Inserir clientes antes de usar esta função\n");
        printf("Digite qualquer coisa para voltar para o menu anterior\n");
        fflush(stdin);
        scanf("%c", &aux);
        return 1;
    }
    for (int i = 0; i < tot; i++)
        ordem[i] = i;
    for (int i = 0; i < tot; i++)
    {
        menor = i;
        for (int j = i + 1; j < tot; j++)
        {
            if (strcmp(clientes[ordem[j]].pais, clientes[ordem[menor]].pais) < 0)
                menor = j;
        }
        aux1 = ordem[i];
        ordem[i] = ordem[menor];
        ordem[menor] = aux1;
    }
    printf("\n\n\
    ----------------------------------------\n\
                Lista de clientes\n\n\
    ----------------------------------------\n\n\n");
    for (int i = 0; i < tot; i++)
    {
        listarUmCliente(clientes, ordem[i]);
    }
    printf("Digite qualquer coisa para voltar para o menu anterior\n");
    fflush(stdin);
    scanf("%c", &aux);
    return 15;
}

int listarClientesMorada(CLIENTE clientes[], int tot)
{
    char aux;
    int menor, ordem[tot], aux1;
    if (tot == 0)
    {
        printf("\nDeve Inserir clientes antes de usar esta função\n");
        printf("Digite qualquer coisa para voltar para o menu anterior\n");
        fflush(stdin);
        scanf("%c", &aux);
        return 1;
    }
    for (int i = 0; i < tot; i++)
        ordem[i] = i;
    for (int i = 0; i < tot; i++)
    {
        menor = i;
        for (int j = i + 1; j < tot; j++)
        {
            if (strcmp(clientes[ordem[j]].morada, clientes[ordem[menor]].morada) < 0)
                menor = j;
        }
        aux1 = ordem[i];
        ordem[i] = ordem[menor];
        ordem[menor] = aux1;
    }
    printf("\n\n\
    ----------------------------------------\n\
                Lista de clientes\n\n\
    ----------------------------------------\n\n\n");
    for (int i = 0; i < tot; i++)
    {
        listarUmCliente(clientes, ordem[i]);
    }
    printf("Digite qualquer coisa para voltar para o menu anterior\n");
    fflush(stdin);
    scanf("%c", &aux);
    return 15;
}

int listarClientesEmail(CLIENTE clientes[], int tot)
{
    char aux;
    int menor, ordem[tot], aux1;
    if (tot == 0)
    {
        printf("\nDeve Inserir clientes antes de usar esta função\n");
        printf("Digite qualquer coisa para voltar para o menu anterior\n");
        fflush(stdin);
        scanf("%c", &aux);
        return 1;
    }
    for (int i = 0; i < tot; i++)
        ordem[i] = i;
    for (int i = 0; i < tot; i++)
    {
        menor = i;
        for (int j = i + 1; j < tot; j++)
        {
            if (strcmp(clientes[ordem[j]].email, clientes[ordem[menor]].email) < 0)
                menor = j;
        }
        aux1 = ordem[i];
        ordem[i] = ordem[menor];
        ordem[menor] = aux1;
    }
    printf("\n\n\
    ----------------------------------------\n\
                Lista de clientes\n\n\
    ----------------------------------------\n\n\n");
    for (int i = 0; i < tot; i++)
    {
        listarUmCliente(clientes, ordem[i]);
    }
    printf("Digite qualquer coisa para voltar para o menu anterior\n");
    fflush(stdin);
    scanf("%c", &aux);
    return 15;
}

// ******************************************************************************* FILTRAGEM ***********************************************************************************

int filtrarClientePais(CLIENTE clientes[], int tot)
{
    char pais[100], res;
    if (tot == 0)
    {
        printf("\nDeve Inserir clientes antes de usar esta função\n");
        printf("Digite qualquer coisa para voltar para o menu anterior\n");
        fflush(stdin);
        scanf("%c", &res);
        return 1;
    }
    printf("Deseja visualizar os clientes de que pais?\n");
    fflush(stdin);
    gets(pais);
    printf("\n\n\
    ----------------------------------------\n\
                Lista de clientes\n\n\
    ----------------------------------------\n\n\n");
    for (int i = 0; i < tot; i++)
    {
        if (strcasecmp(pais, clientes[i].pais) == 0)
            listarUmCliente(clientes, i);
    }
    printf("Digite qualquer coisa para voltar para o menu anterior\n");
    fflush(stdin);
    scanf("%c", &res);
    return 16;
}

int filtrarClienteNome(CLIENTE clientes[], int tot)
{
    char nome[100], res;
    if (tot == 0)
    {
        printf("\nDeve Inserir clientes antes de usar esta função\n");
        printf("Digite qualquer coisa para voltar para o menu anterior\n");
        fflush(stdin);
        scanf("%c", &res);
        return 1;
    }
    printf("Deseja visualizar os clientes de que usuário?\n");
    fflush(stdin);
    gets(nome);
    printf("\n\n\
    ----------------------------------------\n\
                Lista de clientes\n\n\
    ----------------------------------------\n\n\n");
    for (int i = 0; i < tot; i++)
    {
        if (strcasecmp(nome, clientes[i].nome) == 0)
        {
            listarUmCliente(clientes, i);
        }
    }
    printf("Digite qualquer coisa para voltar para o menu anterior\n");
    fflush(stdin);
    scanf("%c", &res);
    return 16;
}

int filtrarClienteNif(CLIENTE clientes[], int tot)
{
    char nif[100], res;
    if (tot == 0)
    {
        printf("\nDeve Inserir clientes antes de usar esta função\n");
        printf("Digite qualquer coisa para voltar para o menu anterior\n");
        fflush(stdin);
        scanf("%c", &res);
        return 1;
    }
    printf("Deseja visualizar os clientes com qual nif?\n");
    fflush(stdin);
    gets(nif);
    printf("\n\n\
    ----------------------------------------\n\
                Lista de clientes\n\n\
    ----------------------------------------\n\n\n");
    for (int i = 0; i < tot; i++)
    {
        if (strcasecmp(nif, clientes[i].nif) == 0)
        {
            listarUmCliente(clientes, i);
        }
    }
    printf("Digite qualquer coisa para voltar para o menu anterior\n");
    fflush(stdin);
    scanf("%c", &res);
    return 16;
}

int filtrarClienteTelefone(CLIENTE clientes[], int tot)
{
    char telefone[100], res;
    if (tot == 0)
    {
        printf("\nDeve Inserir clientes antes de usar esta função\n");
        printf("Digite qualquer coisa para voltar para o menu anterior\n");
        fflush(stdin);
        scanf("%c", &res);
        return 1;
    }
    printf("Deseja visualizar os clientes com qual número de telefone?\n");
    fflush(stdin);
    gets(telefone);
    printf("\n\n\
    ----------------------------------------\n\
                Lista de clientes\n\n\
    ----------------------------------------\n\n\n");
    for (int i = 0; i < tot; i++)
    {
        if (strcasecmp(telefone, clientes[i].telefone) == 0)
        {
            listarUmCliente(clientes, i);
        }
    }
    printf("Digite qualquer coisa para voltar para o menu anterior\n");
    fflush(stdin);
    scanf("%c", &res);
    return 16;
}

int filtrarClientePassaporte(CLIENTE clientes[], int tot)
{
    char passaporte[100], res;
    if (tot == 0)
    {
        printf("\nDeve Inserir clientes antes de usar esta função\n");
        printf("Digite qualquer coisa para voltar para o menu anterior\n");
        fflush(stdin);
        scanf("%c", &res);
        return 1;
    }
    printf("Deseja visualizar os clientes com qual número de passaporte?\n");
    fflush(stdin);
    gets(passaporte);
    printf("\n\n\
    ----------------------------------------\n\
                Lista de clientes\n\n\
    ----------------------------------------\n\n\n");
    for (int i = 0; i < tot; i++)
    {
        if (strcasecmp(passaporte, clientes[i].passaporte) == 0)
        {
            listarUmCliente(clientes, i);
        }
    }
    printf("Digite qualquer coisa para voltar para o menu anterior\n");
    fflush(stdin);
    scanf("%c", &res);
    return 16;
}

int filtrarClienteEmail(CLIENTE clientes[], int tot)
{
    char email[100], res;
    if (tot == 0)
    {
        printf("\nDeve Inserir clientes antes de usar esta função\n");
        printf("Digite qualquer coisa para voltar para o menu anterior\n");
        fflush(stdin);
        scanf("%c", &res);
        return 1;
    }
    printf("Deseja visualizar os clientes com qual email?\n");
    fflush(stdin);
    gets(email);
    printf("\n\n\
    ----------------------------------------\n\
                Lista de clientes\n\n\
    ----------------------------------------\n\n\n");
    for (int i = 0; i < tot; i++)
    {
        if (strcasecmp(email, clientes[i].email) == 0)
        {
            listarUmCliente(clientes, i);
        }
    }
    printf("Digite qualquer coisa para voltar para o menu anterior\n");
    fflush(stdin);
    scanf("%c", &res);
    return 16;
}

// ******************************************************************************* ALTERAÇÕES **********************************************************************************

void alterarClienteTelefone(CLIENTE clientes[], int tot)
{
    int i, id, aux;
    char res;
    if (tot == 0)
    {
        printf("\nDeve Inserir clientes antes de usar esta função\n");
        printf("Digite qualquer coisa para voltar para o menu anterior\n");
        fflush(stdin);
        scanf("%c", &res);
        return;
    }
    do
    {
        printf("Qual o id do cliente que pretende alterar?\n");
        scanf("%d", &id);
        if (id < 1 || id > tot)
            printf("Id invalido, o id deve ser um numero entre 1 e %d\n", tot);
    } while (id < 1 || id > tot);
    id--;
    do
    {
        aux = 0;
        printf("Atualmente o número de telefone do cliente %d é \"%s\", tem certeza que deseja alterar o seu telefone?\n", id + 1, clientes[id].telefone);
        fflush(stdin);
        scanf("%c", &res);
        if (res == 'N' || res == 'n')
        {
            return;
        }
        else if (res != 'S' && res != 's')
        {
            printf("Resposta invalida\n\n");
            aux = 1;
        }
    } while (aux != 0);
    do
    {
        printf("Qual o numero de telefone do cliente?\n");
        fflush(stdin);
        gets(clientes[id].telefone);
        printf("%s\n", clientes[id].telefone);
        aux = 0;
        if (strlen(clientes[id].telefone) != 9)
        {
            printf("Numero de telefone invalido, o telefone deve ter 9 numeros\n");
            aux = 1;
        }
        for (i = 0; i < 9 && aux == 0; i++)
        {
            if (!isdigit(clientes[id].telefone[i]))
            {
                printf("Numero de telefone invalido, o telefone deve ter apenas numeros\n");
                aux = 1;
            }
        }
        if (aux != 0)
            printf("\n\n");
    } while (aux != 0);
    guardarclientes(clientes, tot);
    printf("\nAs Informações do cliente já foram atualizadas, digite qualquer coisa para continuar: ");
    fflush(stdin);
    scanf("%c", &res);
}