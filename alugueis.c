#include "alugueis.h"
#include "data.h"
#include "imoveis.h"

int AdicionarAluguel(IMOVEL imoveis[], int tot,int totclientes){
    ALUGUELD aux;
    AluguelList *aux2;
    char auxchar;
    int res,passou,repetido;
    int id=0;
    if(tot==0){
        printf("\nDeve Inserir imoveis antes de usar esta função\n");
        if(totclientes==0){
            printf("\nDeve Inserir clientes antes de usar esta função\n");
            printf("Digite qualquer coisa para voltar para o menu anterior\n");
            fflush(stdin);
            scanf("%c",&res);
            return 3;
        }
        printf("Digite qualquer coisa para voltar para o menu anterior\n");
        fflush(stdin);
        scanf("%c",&res);
        return 3;
    }
    if(totclientes==0){
        printf("\nDeve Inserir clientes antes de usar esta função\n");
        printf("Digite qualquer coisa para voltar para o menu anterior\n");
        fflush(stdin);
        scanf("%c",&res);
        return 3;
    }
    do{
        res=0;
        printf("Qual o id do Imóvel ao qual este aluguel pertence?\n");fflush(stdin);res=scanf("%d",&id);
    }while(res!=1 || id < 1 || id > tot); // verifica se o id foi lido de maneira correta e se o mesmo é valido
    do{
        res=0;
        printf("Qual o id do Cliente ao qual este aluguel pertence?\n");res=scanf("%d",&aux.clientid);
        if(res!=1) printf("Reposta invalida\n");
        if(aux.clientid < 1 || aux.clientid > totclientes) printf("O id do cliente deve ser um numero entre 1 e %d", totclientes);
    }while(res!=1 || aux.clientid < 1 || aux.clientid > totclientes); // verifica se o id foi lido de maneira correta e se o mesmo é valido
    do{
        res=0;
        printf("Qual a data de inicio do aluguel?[dd/mm/aaaa]\n");fflush(stdin);res=scanf("%d/%d/%d",&aux.inicio.dia,&aux.inicio.mes,&aux.inicio.ano);
        if(res != 3) printf("Resposta invalida\n\n");
        passou=0,repetido=0;
        for(aux2=imoveis[id].alugueis; aux2 != NULL && passou == 0 && repetido == 0; aux2 = aux2->proximo){
            if(comparardatas(aux2->data.inicio,aux.inicio) > 0 && comparardatas(aux2->data.fim,aux.fim) < 0 ){
                repetido = 1;
            } else if(comparardatas(aux2->data.inicio,aux.inicio) < 0){
                passou = 1;
            }
        }
        if(!validardata(aux.inicio)) printf("Data invalida\n\n");
    }while(res!=3 || !validardata(aux.inicio) || repetido == 1);// verifica se a data inicial foi lida de maneira correta e se a mesma é valida

    do{
        res=0,repetido = 0,passou = 0;
        printf("Qual a data de fim do aluguel?[dd/mm/aaaa]\n");fflush(stdin);res=scanf("%d/%d/%d",&aux.fim.dia,&aux.fim.mes,&aux.fim.ano);
        if(res != 3) {
            printf("Resposta invalida\n\n");
        }else if(!validardata(aux.fim)){
            printf("Data invalida\n\n");
        }else if(comparardatas(aux.inicio,aux.fim) < 7) {
            printf("O o fim aluguel deve ser de pelo menos 7 dias depois do seu inicio\n\n");
        }
        printf("%d",comparardatas(aux.inicio,aux.fim));
        for(aux2=imoveis[id].alugueis; aux2 != NULL && passou == 0 && repetido == 0; aux2 = aux2->proximo){
            if(comparardatas(aux2->data.inicio,aux.fim) > 0 && comparardatas(aux2->data.fim,aux.fim) < 0 ){
                repetido = 1;
            } else if(comparardatas(aux2->data.inicio,aux.fim) < 0){
                passou = 1;
            }
        }
    }while(res!=3 || !validardata(aux.fim) || comparardatas(aux.inicio,aux.fim) < 7 || repetido);// verifica se a data final foi lida de maneira correta e se a mesma é valida
    do{
        res=0;
        printf("Qual a data de pagamento do aluguel?[dd/mm/aaaa]\n");res=scanf("%d/%d/%d",&aux.pagamento.dia,&aux.pagamento.mes,&aux.pagamento.ano);
        if(res != 3) printf("Resposta invalida\n\n");
        if(!validardata(aux.pagamento)) printf("Data invalida\n\n");
    }while(res!=3 || !validardata(aux.pagamento));// verifica se a data do pagamento foi lida de maneira correta e se a mesma é valida
    printf("Qual sera o valor pago para o aluguel?(valor base é de %.2f)\n", imoveis[id-1].valaluguel);fflush(stdin);scanf("%f",&aux.valor);
    
    
    
    AdicionarAlugelNaLista(imoveis,aux, id-1);
    imoveis[id-1].totalugueis++;
    do{
        res=0;
        printf("\n\nDeseja inserir outro Aluguel?\n");
        fflush(stdin);
        scanf("%c",&auxchar);
        if(auxchar== 'S' || auxchar == 's'){
            return 31;
        }else if(auxchar=='N' || auxchar == 'n'){
            return 3;
        }else{
            printf("Resposta invalida");
            res=1;
        }
        if(res!=0) printf("\n\n");
    }while(res!=0);
}

int listarImoveisDisponiveis(IMOVEL imoveis[],int tot){
    int aux,passou;
    char res;
    DATA pesquisa;
    AluguelList *auxlist;
    if(tot==0){
        printf("\nDeve Inserir imoveis antes de usar esta função\n");
        printf("Digite qualquer coisa para voltar para o menu anterior\n");
        fflush(stdin);
        scanf("%c",&res);
        return 3;
    }
    do{
        printf("Qual data pretende verificar?[dd/mm/aaaa]\n");aux=scanf("%d/%d/%d",&pesquisa.dia,&pesquisa.mes,&pesquisa.ano);
        if(aux != 3) printf("Resposta invalida\n\n");
        if(!validardata(pesquisa)) printf("Data invalida\n\n");
    }while(aux!=3 || !validardata(pesquisa));
    printf("\n\n\
    ----------------------------------------\n\
                Lista de iméveis\n\n\
    ----------------------------------------\n\n\n");
    for(int i = 0; i < tot; i++){
        aux=1, passou = 0;
        for(auxlist=imoveis[i].alugueis; auxlist!=NULL && aux == 1 && passou == 0; auxlist=auxlist->proximo){
            if(comparardatas(auxlist->data.inicio, pesquisa) > 0 && comparardatas(auxlist->data.fim, pesquisa) <0 )   aux = 0;
            if(comparardatas(auxlist->data.inicio, pesquisa) < 0) passou = 1;
        }
        if(aux) listarUmImovel(imoveis[i]);
    }
    printf("Digite qualquer coisa para voltar para o menu anterior\n");
    fflush(stdin);
    scanf("%c",&res);
    return 3;
}

int listarTodosAlugueis(IMOVEL imoveis[], int tot){
    char res;
    AluguelList *auxlist;
    if(tot==0){
        printf("\nDeve Inserir imoveis antes de usar esta função\n");
        printf("Digite qualquer coisa para voltar para o menu anterior\n");
        fflush(stdin);
        scanf("%c",&res);
        return 3;
    }
    printf("\n\n\
    ----------------------------------------\n\
                Lista de Alugueis\n\n\
    ----------------------------------------\n\n\n");
    for(int i = 0; i < tot; i++){
        printf("Alugueis do Imóvel %d:\n\n", i+1);
        for(auxlist=imoveis[i].alugueis; auxlist!=NULL; auxlist=auxlist->proximo){
            listarUmAluguel(auxlist->data);
            printf("\n");
        }
    }
    printf("Digite qualquer coisa para voltar para o menu anterior\n");
    fflush(stdin);
    scanf("%c",&res);
    return 3;
}

int listarAlugueisImovel(IMOVEL imoveis[], int tot){
    int id;
    char res;
    AluguelList *auxlist; 
    if(tot==0){
        printf("\nDeve Inserir imoveis antes de usar esta função\n");
        printf("Digite qualquer coisa para voltar para o menu anterior\n");
        fflush(stdin);
        scanf("%c",&res);
        return 3;
    }
    do{
        printf("Qual o id do imovel que pretende ver os alugueis?\n");
        scanf("%d",&id);
        if(id < 1 || id > tot) printf("Id invalido, o id deve ser um numero entre 1 e %d\n", tot);
    }while(id < 1 || id > tot);
    id--;
    printf("\n\n\
    ----------------------------------------\n\
                Lista de Alugueis\n\n\
    ----------------------------------------\n\n\n");
    printf("Alugueis do Imóvel %d:\n\n", id+1);
    for(auxlist=imoveis[id].alugueis; auxlist!=NULL; auxlist=auxlist->proximo){
        listarUmAluguel(auxlist->data);
        printf("\n");
    }
    printf("Digite qualquer coisa para voltar para o menu anterior\n");
    fflush(stdin);
    scanf("%c",&res);
    return 3;
}

int listarAlugueisCliente(IMOVEL imoveis[], int totimoveis,CLIENTE clientes[], int totclientes){
    
    int aux,id;
    char nif[50];
    char res;
    AluguelList *auxlist;
    if(totimoveis==0){
        printf("\nDeve Inserir imoveis antes de usar esta função\n");
        if(totclientes==0){
            printf("\nDeve Inserir clientes antes de usar esta função\n");
            printf("Digite qualquer coisa para voltar para o menu anterior\n");
            fflush(stdin);
            scanf("%c",&res);
            return 3;
        }
        printf("Digite qualquer coisa para voltar para o menu anterior\n");
        fflush(stdin);
        scanf("%c",&res);
        return 3;
    }
    if(totclientes==0){
        printf("\nDeve Inserir clientes antes de usar esta função\n");
        printf("Digite qualquer coisa para voltar para o menu anterior\n");
        fflush(stdin);
        scanf("%c",&res);
        return 3;
    }
     do{
        printf("Qual o nif do cliente que pretende ver os alugueis?\n");fflush(stdin); gets(nif); printf("%s\n",nif);
        aux=0;
        if(strlen(nif)!=9){
            printf("Nif invalido, o nif deve ter 9 numeros\n");
            aux=1;
        }
        for(int i=0; i<9 && aux==0;i++){
            if(!isdigit(nif[0])) {
                printf("Nif invalido, o nif deve ter apenas numeros\n");
                aux=1;
            }
        }
        if(aux==0){
            for(int i=0;i<totclientes && aux == 0;i++){
                    aux =1;
                if (nif==clientes[i].nif){
                    aux=0;
                    id=i;
                }
            }
            if(aux == 1) printf("Néo ha nenhum cliente registrado com esse Nif");
        }
        if(aux!=0) printf("\n\n");
    } while(aux!=0);
    printf("\n\n\
    ----------------------------------------\n\
                Lista de Alugueis\n\n\
    ----------------------------------------\n\n\n");
    for(int i = 0; i < totimoveis; i++){
        aux=0;
        for(auxlist=imoveis[i].alugueis; auxlist!=NULL; auxlist=auxlist->proximo){
            if(auxlist->data.clientid==id){
                if(!aux){
                    printf("Alugueis do Imóvel %d:\n\n", i+1);
                    aux =1;
                }
                listarUmAluguel(auxlist->data);
                printf("\n");
            }
        }
    }
    printf("Digite qualquer coisa para voltar para o menu anterior\n");
    fflush(stdin);
    scanf("%c",&res);
    return 3;
}

int fechoDia(IMOVEL imoveis[], int tot){
    DATA data;
    AluguelList *auxlist;
    char nomeficheiro[100];
    FILE *fp=NULL;
    int res,passou,aux;
    char c;
    do{
        res=printf("Qual data pretende fechar?[dd/mm/aaaa]\n");res=scanf("%d/%d/%d",data.dia,data.mes,data.ano);
        if(res != 3) printf("Resposta invalida\n\n");
        if(!validardata(data)) printf("Data invalida\n\n");
    }while(res!=3 || !validardata(data));
    sprintf(nomeficheiro,"FechoDia_%d_%d_%d.txt");
    fp = fopen(nomeficheiro,"w");
    if (fp == NULL){
        printf("Falha ao criar o ficheiro");
        printf("Digite qualquer coisa para voltar para o menu anterior\n");
        fflush(stdin);
        scanf("%c",&c);
        return 3;
    }
    for(int i = 0; i < tot; i++){
        passou=0,aux=0;
        for(auxlist=imoveis[i].alugueis; auxlist!=NULL && passou == 0; auxlist=auxlist->proximo){
            if(comparardatas(auxlist->data.pagamento,data)==0){
                if(!aux){
                    fprintf(fp,"Alugueis do Imovel %d:\n",i);
                    aux=1;
                }
                fprintf(fp,"ID do Cliente que alugou o imovel: %d\nData de pagamento: %d/%d/%d\nData de inicio do aluguel: %d/%d/%d\nData de fim do aluguel: %d/%d/%d\n\n\n",auxlist->data.clientid,auxlist->data.pagamento.dia,auxlist->data.pagamento.mes,auxlist->data.pagamento.ano,auxlist->data.inicio.dia,auxlist->data.inicio.mes,auxlist->data.inicio.ano,auxlist->data.fim.dia,auxlist->data.fim.mes,auxlist->data.fim.ano);            
            }
            if(aux) fprintf(fp,"\n\n");
        }
    }     
}
int fechoMes(IMOVEL imoveis[], int tot){
    DATA data;
    AluguelList *auxlist;
    char nomeficheiro[100];
    FILE *fp=NULL;
    char c;
    int res,passou,aux;
    data.dia=1;
    do{
        res=printf("Qual o mes pretende fechar?[mm/aaaa]\n");res=scanf("%d/%d",data.mes,data.ano);
        if(res != 2) printf("Resposta invalida\n\n");
        if(!validardata(data)) printf("Data invalida\n\n");
    }while(res!=2 || !validardata(data));
    sprintf(nomeficheiro,"FechoMes_%d_%d.txt");
    fp = fopen(nomeficheiro,"w");
    if (fp == NULL){
        printf("Falha ao criar o ficheiro");
        printf("Digite qualquer coisa para voltar para o menu anterior\n");
        fflush(stdin);
        scanf("%c",&c);
        return 3;
    }
    for(int i = 0; i < tot; i++){
        passou=0,aux=0;
        for(auxlist=imoveis[i].alugueis; auxlist!=NULL && passou == 0; auxlist=auxlist->proximo){
            if(auxlist->data.pagamento.mes==data.mes && auxlist->data.pagamento.ano==data.ano){
                if(!aux){
                    fprintf(fp,"Alugueis do Imovel %d:\n",i);
                    aux=1;
                }
                fprintf(fp,"ID do Cliente que alugou o imovel: %d\nData de pagamento: %d/%d/%d\nData de inicio do aluguel: %d/%d/%d\nData de fim do aluguel: %d/%d/%d\n\n\n",auxlist->data.clientid,auxlist->data.pagamento.dia,auxlist->data.pagamento.mes,auxlist->data.pagamento.ano,auxlist->data.inicio.dia,auxlist->data.inicio.mes,auxlist->data.inicio.ano,auxlist->data.fim.dia,auxlist->data.fim.mes,auxlist->data.fim.ano);            
            }
            if(aux) fprintf(fp,"\n\n");
        }
    }     
}
int fechoAno(IMOVEL imoveis[], int tot){
    DATA data;
    AluguelList *auxlist;
    char nomeficheiro[100];
    FILE *fp=NULL;
    int passou,aux;
    char res;
    data.dia=1;
    printf("Qual o ano pretende fechar?[mm/aaaa]\n");scanf("%d",data.ano);
    sprintf(nomeficheiro,"FechoAno_%d.txt");
    fp = fopen(nomeficheiro,"w");
    if (fp == NULL){
        printf("Falha ao criar o ficheiro");
        printf("Digite qualquer coisa para voltar para o menu anterior\n");
        fflush(stdin);
        scanf("%c",&res);
        return 3;
    }
    for(data.mes=1;data.mes<=12; data.mes++){
        fprintf(fp,"--------------------------------\nALUGUEIS DO MES %d: \n\n",data.mes);
        for(int i = 0; i < tot; i++){
            passou=0,aux=0;
            for(auxlist=imoveis[i].alugueis; auxlist!=NULL && passou == 0; auxlist=auxlist->proximo){
                if(auxlist->data.pagamento.mes==data.mes && auxlist->data.pagamento.ano==data.ano){
                    if(!aux){
                        fprintf(fp,"Alugueis do Imovel %d:\n",i);
                        aux=1;
                    }
                    fprintf(fp,"ID do Cliente que alugou o imovel: %d\nData de pagamento: %d/%d/%d\nData de inicio do aluguel: %d/%d/%d\nData de fim do aluguel: %d/%d/%d\n\n\n",auxlist->data.clientid,auxlist->data.pagamento.dia,auxlist->data.pagamento.mes,auxlist->data.pagamento.ano,auxlist->data.inicio.dia,auxlist->data.inicio.mes,auxlist->data.inicio.ano,auxlist->data.fim.dia,auxlist->data.fim.mes,auxlist->data.fim.ano);            
                }
                if(aux) fprintf(fp,"\n\n");
            }
        }
    }
}

void listarUmAluguel(ALUGUELD aluguel){
    
    printf("\nID do Cliente que alugou o imovel: %d\n",aluguel.clientid);
    printf("Data de pagamento: %d/%d/%d\n", aluguel.pagamento.dia,aluguel.pagamento.mes,aluguel.pagamento.ano);
    printf("Data de inicio do aluguel: %d/%d/%d\n", aluguel.inicio.dia,aluguel.inicio.mes,aluguel.inicio.ano);
    printf("Data de fim do aluguel: %d/%d/%d\n", aluguel.fim.dia,aluguel.fim.mes,aluguel.fim.ano);
    printf("Valor do aluguel: %.2f$\n",aluguel.valor);

}

