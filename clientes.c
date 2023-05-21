#include "clientes.h"
#include "data.h"


int AdicionarCliente(CLIENTE clientes[], int tot){
    int i=0,aux=0,dotcount,acount,atpos,dotpos;
    char res;
    printf("Qual o nome do cliente?\n");fflush(stdin); gets(clientes[tot].nome); printf("%s\n",clientes[tot].nome);
    printf("Qual a morada do cliente?\n");fflush(stdin); gets(clientes[tot].morada); printf("%s\n",clientes[tot].morada);
    printf("De qual país o cliente e?\n");fflush(stdin); gets(clientes[tot].pais); printf("%s\n",clientes[tot].pais);
    do{
        printf("Qual o nif do cliente?\n");fflush(stdin); gets(clientes[tot].nif); printf("%s\n",clientes[tot].nif);
        aux=0;
        for(i=0;i<tot && aux == 0;i++){
            if (clientes[tot].nif==clientes[i].nif){
                aux=1;
                printf("Já existe um cliente com esse nif, por favor insira um nif diferente\n");

            }
        }
        if(strlen(clientes[tot].nif)!=9){
            printf("Nif invalido, o nif deve ter 9 numeros\n");
            aux=1;
        }
        for(i=0; i<9 && aux==0;i++){
            if(!isdigit(clientes[tot].nif[0])) {
                printf("Nif invalido, o nif deve ter apenas numeros\n");
                aux=1;
            }
        }

        if(aux!=0) printf("\n\n");
    } while(aux!=0);
    do{
        printf("Qual o numero de passaporte do cliente?\n");fflush(stdin); gets(clientes[tot].passaporte); printf("%s\n",clientes[tot].passaporte);
        aux=0;
        for(i=0;i<tot && aux == 0;i++){
            if (clientes[tot].passaporte==clientes[i].passaporte){
                aux=1;
                printf("Já existe um cliente com esse numero de passaporte, por favor insira um diferente\n");

            }
        }
        if(strlen(clientes[tot].passaporte)!=7){
            aux=1;
            printf("Numero de passaporte invalido, o numero do passaporte deve ter um caractere seguido de 6 numeros\n");
        }else {
            if(isdigit(clientes[tot].passaporte[0])){
                    printf("Numero de passaporte invalido, o numero do passaporte deve ter um caractere seguido de 6 numeros\n");
                    aux=1;
            }else{
                for(i=1; i<7 && aux == 0;i++){
                    if(!isdigit(clientes[tot].passaporte[i])){
                        printf("Numero de passaporte invalido, o numero do passaporte deve ter um caractere seguido de 6 numeros\n");
                        aux=1;
                    }
                }
            }
        }
        if(aux!=0) printf("\n\n");
    } while(aux!=0);
    do{
        printf("Qual o email do cliente?\n");fflush(stdin); gets(clientes[tot].email); printf("%s\n",clientes[tot].email);
        aux=0;
        dotcount=0,acount=0,dotpos=-1,atpos=-1;
        for(i=0;i<tot && aux == 0;i++){
            if (clientes[tot].email==clientes[i].email){
                aux=1;
                printf("Já existe um cliente com esse email, por favor insira um diferente");

            }
        }
        for(i=0; i<strlen(clientes[tot].email); i++){
            if(clientes[tot].email[i]== '@'){
                acount++;
                atpos=i;
            }else if(clientes[tot].email[i]=='.'){
                dotcount++;
                dotpos=i;
            }
        }
        if (strlen(clientes[tot].email) < 5 ) {
            aux = 1;
            printf("O email deve ter pelo menos 5 caracteres");
        }else if(isdigit(clientes[tot].email[0])){
            printf("O primeiro caractere do email n pode ser um numero");
            aux=1;
        } else if (dotcount==0 || acount!=1){
            printf("O email deve ter exatamente um '@' e pelo menos 1 '.'");
            aux=1;
        } else if(dotpos==atpos+1 || dotpos<atpos){
            printf("Deve have pelo menos um caracter entre o '@' e o '.' e deve haver 1 '.' depois do '@'");
            aux=1;
        }
        if(aux!=0) printf("\n\n");
    } while(aux!=0);
    clientes[tot].id=tot;
    do{
        aux=0;
        printf("\n\nDeseja inserir outro cliente?\n");
        scanf("%c",&res);
        if(res== 'S' || res == 's'){
            return 11;
        }else if(res=='N' || res == 'n'){
            return 1;
        }else{
            printf("Resposta invalida");
            aux=1;
        }
        if(aux!=0) printf("\n\n");
    }while(aux!=0);
}
int listarTodosClientes(CLIENTE clientes[],int tot){
    char aux;
    printf("\
    ----------------------------------------\
                Lista de Clientes\n\n\
    ----------------------------------------\n\n\n");
    for(int i=0;i<tot;i++){
       listarUmCliente(clientes[i]);
    }
    printf("Digite qualquer coisa para voltar para o menu anterior\n");
    scanf("%c",&aux);
    return 1;
}

void listarUmCliente(CLIENTE cliente){

    printf("Clientes %d:\n\n");
    printf("Nome: %s\n",cliente.nome);
    printf("Nif: %s\n",cliente.nif);
    printf("Passaporte: %s\n",cliente.passaporte);
    printf("Morada: %s\n", cliente.morada);
    printf("País: %s\n", cliente.pais);
    printf("Email: %s\n", cliente.email);
    printf("\n--------------------------------------------------\n\n\n");
}