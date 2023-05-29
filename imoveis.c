#include "imoveis.h"
#include "data.h"


int AdicionarImoveis(IMOVEL imoveis[], int tot){
    int aux=0;
    char res;

    printf("Qual a morada do im�vel?\n");fflush(stdin); gets(imoveis[tot].morada); printf("%s\n",imoveis[tot].morada);
    printf("De qual cidade � o im�vel?\n");fflush(stdin); gets(imoveis[tot].cidade); printf("%s\n",imoveis[tot].cidade);
    printf("A qual freguesia pertence o im�vel?\n");fflush(stdin); gets(imoveis[tot].freguesia); printf("%s\n",imoveis[tot].freguesia);
    printf("Qual o tipo de im�vel?[T1,T2 etc]\n");fflush(stdin); gets(imoveis[tot].tipo); printf("%s\n",imoveis[tot].tipo);
    printf("Qual a area do im�vel?[em metros quadrados]\n");fflush(stdin); scanf("%d",&imoveis[tot].area); printf("%d\n",imoveis[tot].area);
    printf("Qual o numero de banheiros no im�vel?\n");fflush(stdin); scanf("%d",&imoveis[tot].banheiros); printf("%d\n",imoveis[tot].banheiros);
    printf("Em que ano o im�vel foi construido?\n");fflush(stdin); scanf("%d",&imoveis[tot].ano); printf("%d\n",imoveis[tot].ano);
    printf("Qual a clase energetica do im�vel?\n");fflush(stdin); gets(imoveis[tot].energiaclass); printf("%s\n",imoveis[tot].energiaclass);
    do{
        aux=0;
        printf("� permitido animais neste im�vel?\n");fflush(stdin); scanf("%c",&res); printf("%c\n",res);
        if(res == 'S' || res == 's'){
            imoveis[tot].animais=1;
        }else if(res == 'N' || res == 'n'){
            imoveis[tot].animais=0;
        }else{
            printf("Resposta invalida\n\n");
            aux=1;
        }
    }while(aux!=0);    
    printf("Qual o pre�o base do aluguel diario deste im�vel?\n");fflush(stdin); scanf("%f",&imoveis[tot].valaluguel); printf("%f\n",imoveis[tot].valaluguel);
    do{
        aux=0;
        printf("Alguma observa��o a fazer sobre o im�vel?\n");fflush(stdin);scanf("%c", &res);
        if(res == 'S' || res == 's'){
            printf("Qual?\n");fflush(stdin);gets(imoveis[tot].observacao);printf("%s\n",imoveis[tot].observacao);
        }else if(res == 'N' || res == 'n'){
            strcpy(imoveis[tot].observacao,"Nenhuma observa��o");
        }else{
            printf("Resposta invalida\n\n");
            aux=1;
        }
    }while(aux!=0);     
    imoveis[tot].totalugueis=0;
    imoveis[tot].id=tot+1;
    imoveis[tot].ativo=1;
    do{
        aux=0;
        printf("\n\nDeseja inserir outro im�vel?\n");
        fflush(stdin);
        scanf("%c",&res);
        if(res== 'S' || res == 's'){
            return 21;
        }else if(res=='N' || res == 'n'){
            return 2;
        }else{
            printf("Resposta invalida\n\n");
            aux=1;
        }
    }while(aux!=0);

}
int removerImoveis(IMOVEL imoveis[],int tot){
    int id,aux;
    char res;
    AluguelList *aux2=NULL,*aux3=NULL;
    if (tot == 0)
    {
        printf("\nDeve Inserir im�veis antes de usar esta fun��o\n");
        printf("Digite qualquer coisa para voltar para o menu anterior\n");
        fflush(stdin);
        scanf("%c", &aux);
        return 1;
    }
    do{
        printf("Qual o id do Im�vel que pretende remover?\n");
        scanf("%d",&id);
        if(id < 1 || id > tot) printf("Id invalido, o id deve ser um numero entre 1 e %d\n", tot);
    }while(id < 1 || id > tot);
    id--;
    do{
        aux=0;
        listarUmImovel(imoveis[id]);
        printf("Tem certeza que deseja remover este Im�vel?\n");
        fflush(stdin);
        scanf("%c",&res);
        if(res=='N' || res == 'n'){
            return 0;
        }else if(res != 'S' && res != 's'){
            printf("Resposta invalida\n\n");
            aux=1;
        }
    }while(aux!=0);
    if(imoveis[id].alugueis==NULL) {
        for(int i = id; i < tot - 1; i++){
        imoveis[i]=imoveis[i+1];
        }
        printf("\nAs Informa��es do imovel j� foram atualizadas, digite qualqur coisa para continuar: ");fflush(stdin); scanf("%c",&res);
        return 1;
    }
    if(imoveis[id].alugueis->proximo==NULL) {
        free(imoveis[id].alugueis);
        for(int i = id; i < tot - 1; i++){
        imoveis[i]=imoveis[i+1];
        }
        printf("\nAs Informa��es do imovel j� foram atualizadas, digite qualqur coisa para continuar: ");fflush(stdin); scanf("%c",&res);
        return 1;
    }
    for(aux3 = imoveis[id].alugueis->proximo; aux3->proximo != NULL; aux3=aux3->proximo) {
        if(aux3->anterior!=NULL) aux2 = aux3->anterior;
        if(aux2!=NULL) free(aux2);
    }
    aux2 = aux3->anterior;
    if(aux2!=NULL)free(aux2);
    if(aux3!=NULL)free(aux3);
    for(int i = id; i < tot - 1; i++){
        imoveis[i]=imoveis[i+1];
    }
    printf("\nAs Informa��es do imovel j� foram atualizadas, digite qualqur coisa para continuar: ");fflush(stdin); scanf("%c",&res);
    return 1;
}

void alterarvalorAImovel(IMOVEL imoveis[],int tot){
    int id,aux;
    char res;
    if(tot==0){
        printf("\nDeve Inserir imoveis antes de usar esta fun��o\n");
        printf("Digite qualquer coisa para voltar para o menu anterior\n");
        fflush(stdin);
        scanf("%c",&res);
        return;
    }
    do{
        printf("Qual o id do Imovel que pretende alterar?\n");
        scanf("%d",&id);
        if(id < 1 || id > tot) printf("Id invalido, o id deve ser um numero entre 1 e %d\n", tot);
    }while(id < 1 || id > tot);
    id--;
    do{
        aux=0;
        printf("Atualmente o valor base do Aluguel do imovel %d � %.2f, tem certeza que deseja alterar esse valor?\n",id+1,imoveis[id].valaluguel);
        fflush(stdin);
        scanf("%c",&res);
        if(res=='N' || res == 'n'){
            return;
        }else if(res != 'S' && res != 's'){
            printf("Resposta invalida\n\n");
            aux=1;
        }
    }while(aux!=0);
    printf("Qual sera o novo valor base do aluguel do imovel %d?\n", id+1);fflush(stdin);scanf("%f", &imoveis[id].valaluguel);
    guardarimoveis(imoveis,tot);
    printf("\nAs Informa��es do imovel j� foram atualizadas, digite qualqur coisa para continuar: ");fflush(stdin); scanf("%c",&res);
}
void alterarObsImovel(IMOVEL imoveis[],int tot){
    int id,aux;
    char res;
    if(tot==0){
        printf("\nDeve Inserir imoveis antes de usar esta fun��o\n");
        printf("Digite qualquer coisa para voltar para o menu anterior\n");
        fflush(stdin);
        scanf("%c",&res);
        return;
    }
    do{
        printf("Qual o id do Imovel que pretende alterar?\n");
        scanf("%d",&id);
        if(id < 1 || id > tot) printf("Id invalido, o id deve ser um numero entre 1 e %d\n", tot);
    }while(id < 1 || id > tot);
    id--;
    do{
        aux=0;
        printf("Atualmente a observa��o do imovel %d � \"%s\",\n tem certeza que deseja alterar essa observa��o?\n",id+1,imoveis[id].observacao);
        fflush(stdin);
        scanf("%c",&res);
        if(res=='N' || res == 'n'){
            return;
        }else if(res != 'S' && res != 's'){
            printf("Resposta invalida\n\n");
            aux=1;
        }
    }while(aux!=0);
    printf("Qual sera a nova observa��o do imovel %d?\n", id+1);fflush(stdin);gets(imoveis[id].observacao);
    guardarimoveis(imoveis,tot);
    printf("\nAs Informa��es do imovel j� foram atualizadas, digite qualqur coisa para continuar: ");fflush(stdin); scanf("%c",&res);

}
void alterarClasEneImovel(IMOVEL imoveis[],int tot){
    int id,aux;
    char res;
    if(tot==0){
        printf("\nDeve Inserir imoveis antes de usar esta fun��o\n");
        printf("Digite qualquer coisa para voltar para o menu anterior\n");
        fflush(stdin);
        scanf("%c",&res);
        return;
    }
    do{
        printf("Qual o id do Imovel que pretende alterar?\n");
        scanf("%d",&id);
        if(id < 1 || id > tot) printf("Id invalido, o id deve ser um numero entre 1 e %d\n", tot);
    }while(id < 1 || id > tot);
    id--;
    do{
        aux=0;
        printf("Atualmente a classe energetica do imovel %d � \"%s\",\n tem certeza que deseja alterar a sua classe?\n",id+1,imoveis[id].energiaclass);
        fflush(stdin);
        scanf("%c",&res);
        if(res=='N' || res == 'n'){
            return;
        }else if(res != 'S' && res != 's'){
            printf("Resposta invalida\n\n");
            aux=1;
        }
    }while(aux!=0);
    printf("Qual sera a nova classe energetica do imovel %d?\n", id+1);fflush(stdin);gets(imoveis[id].energiaclass);
    guardarimoveis(imoveis,tot);
    printf("\nAs Informa��es do imovel j� foram atualizadas, digite qualqur coisa para continuar: ");fflush(stdin); scanf("%c",&res);

}
void alterarTipoImovel(IMOVEL imoveis[],int tot){
    int id,aux;
    char res;
    if(tot==0){
        printf("\nDeve Inserir imoveis antes de usar esta fun��o\n");
        printf("Digite qualquer coisa para voltar para o menu anterior\n");
        fflush(stdin);
        scanf("%c",&res);
        return;
    }
    do{
        printf("Qual o id do Imovel que pretende alterar?\n");
        scanf("%d",&id);
        if(id < 1 || id > tot) printf("Id invalido, o id deve ser um numero entre 1 e %d\n", tot);
    }while(id < 1 || id > tot);
    id--;
    do{
        aux=0;
        printf("Atualmente imovel %d � de tipo %s,\n tem certeza que deseja alterar o seu tipo?\n",id+1,imoveis[id].tipo);
        fflush(stdin);
        scanf("%c",&res);
        if(res=='N' || res == 'n'){
            return;
        }else if(res != 'S' && res != 's'){
            printf("Resposta invalida\n\n");
            aux=1;
        }
    }while(aux!=0);
    printf("Qual sera o novo tipo do imovel %d?\n", id+1);fflush(stdin);gets(imoveis[id].tipo);
    guardarimoveis(imoveis,tot);
    printf("\nAs Informa��es do imovel j� foram atualizadas, digite qualqur coisa para continuar: ");fflush(stdin); scanf("%c",&res);

}
void alterarAreaImovel(IMOVEL imoveis[],int tot){
    int id,aux;
    char res;
    if(tot==0){
        printf("\nDeve Inserir imoveis antes de usar esta fun��o\n");
        printf("Digite qualquer coisa para voltar para o menu anterior\n");
        fflush(stdin);
        scanf("%c",&res);
        return;
    }
    do{
        printf("Qual o id do Im�vel que pretende alterar?\n");
        scanf("%d",&id);
        if(id < 1 || id > tot) printf("Id invalido, o id deve ser um numero entre 1 e %d\n", tot);
    }while(id < 1 || id > tot);
    id--;
    do{
        aux=0;
        printf("Atualmente im�vel %d tem area de %dm2,\n tem certeza que deseja alterar o seu tipo?\n",id+1,imoveis[id].area);
        fflush(stdin);
        scanf("%c",&res);
        if(res=='N' || res == 'n'){
            return;
        }else if(res != 'S' && res != 's'){
            printf("Resposta invalida\n\n");
            aux=1;
        }
    }while(aux!=0);
    printf("Qual sera o novo tipo do im�vel %d?\n", id+1);fflush(stdin);scanf("%d",imoveis[id].area);
    guardarimoveis(imoveis,tot);
    printf("\nAs Informa��es do im�vel j� foram atualizadas, digite qualqur coisa para continuar: ");fflush(stdin); scanf("%c",&res);

}



int listarTodosImoveis(IMOVEL imoveis[],int tot){
    char aux;
    if(tot==0){
        printf("\nDeve Inserir imoveis antes de usar esta fun��o\n");
        printf("Digite qualquer coisa para voltar para o menu anterior\n");
        fflush(stdin);
        scanf("%c",&aux);
        return 2;
    }
    printf("\n\n\
    ----------------------------------------\n\
                Lista de im�veis\n\n\
    ----------------------------------------\n\n\n");
    for(int i=0;i<tot;i++){
        listarUmImovel(imoveis[i]);
    }
    printf("Digite qualquer coisa para voltar para o menu anterior\n");
    fflush(stdin);
    scanf("%c",&aux);
    return 2;
}
int listarImoveisOrdemVal(IMOVEL imoveis[],int tot){
    char aux;
    int menor,ordem[tot],aux1;
    if(tot==0){
        printf("\nDeve Inserir imoveis antes de usar esta fun��o\n");
        printf("Digite qualquer coisa para voltar para o menu anterior\n");
        fflush(stdin);
        scanf("%c",&aux);
        return 25;
    }
    for(int i=0;i<tot;i++) ordem[i]=i;
    for(int i=0;i<tot;i++){
        menor =i;
        for(int j = i+1; j < tot; j++){
            if(imoveis[ordem[j]].valaluguel < imoveis[ordem[menor]].valaluguel) menor = j;
        }
        aux1 = ordem[i];
        ordem[i] = ordem[menor];
        ordem[menor] = aux1;
    }
    printf("\n\n\
    ----------------------------------------\n\
                Lista de im�veis\n\n\
    ----------------------------------------\n\n\n");
    for(int i=0;i<tot;i++){
        listarUmImovel(imoveis[ordem[i]]);
    }
    printf("Digite qualquer coisa para voltar para o menu anterior\n");
    fflush(stdin);
    scanf("%c",&aux);
    return 25;
}

int listarImoveisOrdemAno(IMOVEL imoveis[],int tot){
    char aux;
    int maior,ordem[tot],aux1;
    if(tot==0){
        printf("\nDeve Inserir imoveis antes de usar esta fun��o\n");
        printf("Digite qualquer coisa para voltar para o menu anterior\n");
        fflush(stdin);
        scanf("%c",&aux);
        return 25;
    }
    for(int i=0;i<tot;i++) ordem[i]=i;  
    for(int i=0;i<tot;i++){
        maior=i;
        for(int j = i+1; j < tot; j++){
            if(imoveis[ordem[j]].ano > imoveis[ordem[maior]].ano) maior = j;
        }
        aux1 = ordem[i];
        ordem[i] = ordem[maior];
        ordem[maior] = aux1;
    }
    printf("\n\n\
    ----------------------------------------\n\
                Lista de im�veis\n\n\
    ----------------------------------------\n\n\n");
    for(int i=0;i<tot;i++){
        listarUmImovel(imoveis[ordem[i]]);
    }
    printf("Digite qualquer coisa para voltar para o menu anterior\n");
    fflush(stdin);
    scanf("%c",&aux);
    return 25;
}
int filtrarImoveisAnimais(IMOVEL imoveis[],int tot){
    char res;
    if(tot==0){
        printf("\nDeve Inserir imoveis antes de usar esta fun��o\n");
        printf("Digite qualquer coisa para voltar para o menu anterior\n");
        fflush(stdin);
        scanf("%c",&res);
        return 26;
    }
    printf("\n\n\
    ----------------------------------------\n\
                Lista de im�veis\n\n\
    ----------------------------------------\n\n\n");
    for(int i=0;i<tot;i++){
        if(imoveis[i].animais) listarUmImovel(imoveis[i]);
    }
    printf("Digite qualquer coisa para voltar para o menu anterior\n");
    fflush(stdin);
    scanf("%c",&res);
    return 2;
}
int filtrarImoveisCidade(IMOVEL imoveis[],int tot){
    char cidade[100],res;
    if(tot==0){
        printf("\nDeve Inserir imoveis antes de usar esta fun��o\n");
        printf("Digite qualquer coisa para voltar para o menu anterior\n");
        fflush(stdin);
        scanf("%c",&res);
        return 26;
    }
    printf("Deseja visualizar os imoveis de que cidade?\n");fflush(stdin);gets(cidade);
    printf("\n\n\
    ----------------------------------------\n\
                Lista de im�veis\n\n\
    ----------------------------------------\n\n\n");
    for(int i=0;i<tot;i++){
        if(strcmp(cidade,imoveis[i].cidade)==0) listarUmImovel(imoveis[i]);
    }
    printf("Digite qualquer coisa para voltar para o menu anterior\n");
    fflush(stdin);
    scanf("%c",&res);
    return 2;
}
int filtrarImoveisTipo(IMOVEL imoveis[],int tot){
    char res,tipo[20];
    if(tot==0){
        printf("\nDeve Inserir imoveis antes de usar esta fun��o\n");
        printf("Digite qualquer coisa para voltar para o menu anterior\n");
        fflush(stdin);
        scanf("%c",&res);
        return 26;
    }
    printf("Deseja visualizar os imoveis de que tipo?\n");fflush(stdin);gets(tipo);
    printf("\n\n\
    ----------------------------------------\n\
                Lista de im�veis\n\n\
    ----------------------------------------\n\n\n");
    for(int i=0;i<tot;i++){
        if(strcmp(tipo,imoveis[i].tipo)==0) listarUmImovel(imoveis[i]);
    }
    printf("Digite qualquer coisa para voltar para o menu anterior\n");
    fflush(stdin);
    scanf("%c",&res);
    return 2;
}

int DeReAtivarImoveis(IMOVEL imoveis[],int tot){
    int id,aux;
    char res;
    if(tot==0){
        printf("\nDeve Inserir imoveis antes de usar esta fun��o\n");
        printf("Digite qualquer coisa para voltar para o menu anterior\n");
        fflush(stdin);
        scanf("%c",&res);
        return 2;
    }
    do{
        printf("Qual o id do Im�vel que pretende ativar ou desativar?\n");
        scanf("%d",&id);
        if(id < 1 || id > tot) printf("Id invalido, o id deve ser um numero entre 1 e %d\n", tot);
    }while(id < 1 || id > tot);
    id--;
    do{
        aux=0;
        listarUmImovel(imoveis[id]);
        if(imoveis[id].ativo) 
        {
            printf("Tem certeza que deseja desativar este Im�vel?\n");
        } else
        {
            printf("Tem certeza que deseja reativar este Im�vel?\n");
        }
        fflush(stdin);
        scanf("%c",&res);
        if(res=='N' || res == 'n'){
            return 2;
        }else if(res != 'S' && res != 's'){
            printf("Resposta invalida\n\n");
            aux=1;
        }
    }while(aux!=0);
    if(imoveis[id].ativo) 
    {
        imoveis[id].ativo=0;
    } else
    {
        imoveis[id].ativo=1;
    }
    printf("Im�vel desativado/reativado, digite qualquer coisa para continuar: ");
    fflush(stdin);
    scanf("%c",&res);
    return 2;
}
void listarUmImovel(IMOVEL imovel){

    if(imovel.ativo){
        printf("Im�vel %d:\n\n", imovel.id);
        printf("Morada: %s\n",imovel.morada);
        printf("Cidade: %s\n",imovel.cidade);
        printf("Freguesia: %s\n",imovel.freguesia);
        printf("Animais: ");
        if(imovel.animais){
            printf("Permitidos\n");
        }else{
            printf("Proibidos\n");
        }
        printf("Tipo: %s\n", imovel.tipo);
        printf("Area: %dm2\n", imovel.area);
        printf("Banheiros: %d\n", imovel.banheiros);
        printf("Ano: %d\n", imovel.ano);
        printf("Valor do aluguel diario: %.2f\n", imovel.valaluguel);
        printf("Classe energetica: %s\n", imovel.energiaclass);
    }else{
        printf("Im�vel desativado");
    }
    printf("\n--------------------------------------------------\n\n\n");
}
