#include "imoveis.h"
#include "data.h"


int AdicionarImoveis(IMOVEL imoveis[], int tot){
    int aux=0;
    char res;

    printf("Qual a morada do imóvel?\n");fflush(stdin); gets(imoveis[tot].morada); printf("%s\n",imoveis[tot].morada);
    printf("De qual cidade é o imóvel?\n");fflush(stdin); gets(imoveis[tot].cidade); printf("%s\n",imoveis[tot].cidade);
    printf("A qual freguesia pertence o imóvel?\n");fflush(stdin); gets(imoveis[tot].freguesia); printf("%s\n",imoveis[tot].freguesia);
    printf("Qual o tipo de imóvel?[T1,T2 etc]\n");fflush(stdin); gets(imoveis[tot].tipo); printf("%s\n",imoveis[tot].tipo);
    printf("Qual a area do imóvel?[em metros quadrados]\n");fflush(stdin); scanf("%d",&imoveis[tot].area); printf("%d\n",imoveis[tot].area);
    printf("Qual o numero de banheiros no imóvel?\n");fflush(stdin); scanf("%d",&imoveis[tot].banheiros); printf("%d\n",imoveis[tot].banheiros);
    printf("Em que ano o imóvel foi construido?\n");fflush(stdin); scanf("%d",&imoveis[tot].ano); printf("%d\n",imoveis[tot].ano);
    printf("Qual a clase energetica do imóvel?\n");fflush(stdin); gets(imoveis[tot].energiaclass); printf("%s\n",imoveis[tot].energiaclass);
    do{
        aux=0;
        printf("É permitido animais neste imóvel?\n");fflush(stdin); scanf("%c",&res); printf("%c\n",&res);
        if(res == 'S' || res == 's'){
            imoveis[tot].animais=1;
        }else if(res == 'N' || res == 'n'){
            imoveis[tot].animais=0;
        }else{
            printf("Resposta invalida\n\n");
            aux=1;
        }
    }while(aux!=0);    
    printf("Qual o preço base do aluguel diario deste imóvel?\n");fflush(stdin); scanf("%f",&imoveis[tot].valaluguel); printf("%f\n",imoveis[tot].valaluguel);
    do{
        aux=0;
        printf("Alguma observação a fazer sobre o imóvel?\n");fflush(stdin);scanf("%c", &res);
        if(res == 'S' || res == 's'){
            printf("Qual?\n");fflush(stdin);gets(imoveis[tot].observacao);printf("%s\n",imoveis[tot].observacao);
        }else if(res == 'N' || res == 'n'){
            strcpy(imoveis[tot].observacao,"Nenhuma observação");
        }else{
            printf("Resposta invalida\n\n");
            aux=1;
        }
    }while(aux!=0);    
    
    do{
        aux=0;
        printf("\n\nDeseja inserir outro imóvel?\n");
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
    imoveis[tot].totalugueis=0;
    imoveis[tot].id=tot+1;

}
void removerImoveis(IMOVEL imoveis[],int tot){
    int id,aux;
    char res;
    AluguelList *aux2=NULL,*aux3=NULL;
    do{
        printf("Qual o id do Imóvel que pretende remover?\n");
        scanf("%d",&id);
        id;
        if(id < 1 || id > tot) printf("Id invalido, o id deve ser um numero entre 1 e %d\n", tot);
    }while(id < 1 || id > tot);
    id--;
    do{
        aux=0;
        listarUmImovel(imoveis[id]);
        printf("Tem certeza que deseja remover este Imóvel?\n");
        fflush(stdin);
        scanf("%c",&res);
        if(res=='N' || res == 'n'){
            return;
        }else if(res != 'S' && res != 's'){
            printf("Resposta invalida\n\n");
            aux=1;
        }
    }while(aux!=0);
    for(aux3 = imoveis[id].alugueis->proximo; aux3->proximo != NULL; aux3=aux3->proximo) {
        if(aux3->anterior!=NULL) aux2 = aux3->anterior;
        if(aux2!=NULL) free(aux2);
    }
    aux2 = aux3->anterior;
    free(aux2);
    free(aux3);
    for(int i = id; i < tot - 1; i++){
        imoveis[i]=imoveis[i+1];
    }
}

void alterarvalorAImovel(IMOVEL imoveis[],int tot){
    int id,aux;
    char res;
    do{
        printf("Qual o id do Imovel que pretende alterar?\n");
        scanf("%d",&id);
        id;
        if(id < 1 || id > tot) printf("Id invalido, o id deve ser um numero entre 1 e %d\n", tot);
    }while(id < 1 || id > tot);
    id--;
    do{
        aux=0;
        printf("Atualmente o valor base do Aluguel do imovel %d é %d, tem certeza que deseja alterar esse valor?\n",id+1,imoveis[id].valaluguel);
        fflush(stdin);
        scanf("%c",&res);
        if(res=='N' || res == 'n'){
            return;
        }else if(res != 'S' && res != 's'){
            printf("Resposta invalida\n\n");
            aux=1;
        }
    }while(aux!=0);
    printf("Qual sera o novo valor base do aluguel do imovel %d?", id+1);fflush(stdin);scanf("%f", imoveis[id].valaluguel);
    guardarimoveis(imoveis,tot);
    printf("\nAs Informações do imovel já foram atualizadas, digite qualqur coisa para continuar: ");fflush(stdin); scanf("%c",&res);
}
void alterarObsImovel(IMOVEL imoveis[],int tot){
    int id,aux;
    char res;
    do{
        printf("Qual o id do Imovel que pretende alterar?\n");
        scanf("%d",&id);
        id;
        if(id < 1 || id > tot) printf("Id invalido, o id deve ser um numero entre 1 e %d\n", tot);
    }while(id < 1 || id > tot);
    id--;
    do{
        aux=0;
        printf("Atualmente a observação do imovel %d é \"%s\",\n tem certeza que deseja alterar essa observação?\n",id+1,imoveis[id].observacao);
        fflush(stdin);
        scanf("%c",&res);
        if(res=='N' || res == 'n'){
            return;
        }else if(res != 'S' && res != 's'){
            printf("Resposta invalida\n\n");
            aux=1;
        }
    }while(aux!=0);
    printf("Qual sera a nova observação do imovel %d?", id+1);fflush(stdin);gets(imoveis[id].observacao);
    guardarimoveis(imoveis,tot);
    printf("\nAs Informações do imovel já foram atualizadas, digite qualqur coisa para continuar: ");fflush(stdin); scanf("%c",&res);

}
void alterarClasEneImovel(IMOVEL imoveis[],int tot){
    int id,aux;
    char res;
    do{
        printf("Qual o id do Imovel que pretende alterar?\n");
        scanf("%d",&id);
        id;
        if(id < 1 || id > tot) printf("Id invalido, o id deve ser um numero entre 1 e %d\n", tot);
    }while(id < 1 || id > tot);
    id--;
    do{
        aux=0;
        printf("Atualmente a classe energetica do imovel %d é \"%s\",\n tem certeza que deseja alterar a sua classe?\n",id+1,imoveis[id].energiaclass);
        fflush(stdin);
        scanf("%c",&res);
        if(res=='N' || res == 'n'){
            return;
        }else if(res != 'S' && res != 's'){
            printf("Resposta invalida\n\n");
            aux=1;
        }
    }while(aux!=0);
    printf("Qual sera a nova classe energetica do imovel %d?", id+1);fflush(stdin);gets(imoveis[id].energiaclass);
    guardarimoveis(imoveis,tot);
    printf("\nAs Informações do imovel já foram atualizadas, digite qualqur coisa para continuar: ");fflush(stdin); scanf("%c",&res);

}
void alterarTipoImovel(IMOVEL imoveis[],int tot){
    int id,aux;
    char res;
    do{
        printf("Qual o id do Imovel que pretende alterar?\n");
        scanf("%d",&id);
        id;
        if(id < 1 || id > tot) printf("Id invalido, o id deve ser um numero entre 1 e %d\n", tot);
    }while(id < 1 || id > tot);
    id--;
    do{
        aux=0;
        printf("Atualmente imovel %d é de tipo %s,\n tem certeza que deseja alterar o seu tipo?\n",id+1,imoveis[id].tipo);
        fflush(stdin);
        scanf("%c",&res);
        if(res=='N' || res == 'n'){
            return;
        }else if(res != 'S' && res != 's'){
            printf("Resposta invalida\n\n");
            aux=1;
        }
    }while(aux!=0);
    printf("Qual sera o novo tipo do imovel %d?", id+1);fflush(stdin);gets(imoveis[id].tipo);
    guardarimoveis(imoveis,tot);
    printf("\nAs Informações do imovel já foram atualizadas, digite qualqur coisa para continuar: ");fflush(stdin); scanf("%c",&res);

}
void alterarAreaImovel(IMOVEL imoveis[],int tot){
    int id,aux;
    char res;
    do{
        printf("Qual o id do Imovel que pretende alterar?\n");
        scanf("%d",&id);
        id;
        if(id < 1 || id > tot) printf("Id invalido, o id deve ser um numero entre 1 e %d\n", tot);
    }while(id < 1 || id > tot);
    id--;
    do{
        aux=0;
        printf("Atualmente imovel %d tem area de %dm2,\n tem certeza que deseja alterar o seu tipo?\n",id+1,imoveis[id].area);
        fflush(stdin);
        scanf("%c",&res);
        if(res=='N' || res == 'n'){
            return;
        }else if(res != 'S' && res != 's'){
            printf("Resposta invalida\n\n");
            aux=1;
        }
    }while(aux!=0);
    printf("Qual sera o novo tipo do imovel %d?", id+1);fflush(stdin);scanf("%d",imoveis[id].area);
    guardarimoveis(imoveis,tot);
    printf("\nAs Informações do imovel já foram atualizadas, digite qualqur coisa para continuar: ");fflush(stdin); scanf("%c",&res);

}



int listarTodosImoveis(IMOVEL imoveis[],int tot){
    char aux;
    printf("\n\n\
    ----------------------------------------\n\
                Lista de imoveis\n\n\
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
    int menor;
    IMOVEL imoveisordem[tot],aux1;
    for(int i=0;i<tot;i++) imoveisordem[i] = imoveis[i];
    for(int i=0;i<tot;i++){
        menor =i;
        for(int j = i+1; i < tot; i++){
            if(imoveis[j].valaluguel<imoveis[menor].valaluguel) menor = j;
        }
        aux1 = imoveis[i];
        imoveis[i] = imoveis[menor];
        imoveis[menor] = aux1;
    }
    printf("\n\n\
    ----------------------------------------\n\
                Lista de imoveis\n\n\
    ----------------------------------------\n\n\n");
    for(int i=0;i<tot;i++){
        listarUmImovel(imoveisordem[i]);
    }
    printf("Digite qualquer coisa para voltar para o menu anterior\n");
    fflush(stdin);
    scanf("%c",&aux);
    return 2;
}

int listarImoveisOrdemAno(IMOVEL imoveis[],int tot){
    char aux;
    int maior;
    IMOVEL imoveisordem[tot],aux1;
    for(int i=0;i<tot;i++) imoveisordem[i] = imoveis[i];
    for(int i=0;i<tot;i++){
        maior =i;
        for(int j = i+1; i < tot; i++){
            if(imoveis[j].ano>imoveis[maior].ano) maior = j;
        }
        aux1 = imoveis[i];
        imoveis[i] = imoveis[maior];
        imoveis[maior] = aux1;
    }
    printf("\n\n\
    ----------------------------------------\n\
                Lista de imoveis\n\n\
    ----------------------------------------\n\n\n");
    for(int i=0;i<tot;i++){
        listarUmImovel(imoveisordem[i]);
    }
    printf("Digite qualquer coisa para voltar para o menu anterior\n");
    fflush(stdin);
    scanf("%c",&aux);
    return 2;
}

void listarUmImovel(IMOVEL imovel){

    if(imovel.ativo){
        printf("Imóvel %d:\n\n", imovel.id);
        printf("Morada: %s\n",imovel.morada);
        printf("Cidade: %s\n",imovel.cidade);
        printf("Freguesia: %s\n",imovel.freguesia);
        printf("Animais: ");
        if(imovel.animais){
            printf("Permitidos");
        }else{
            printf("Proibidos");
        }
        printf("Tipo: %s\n", imovel.tipo);
        printf("Area: %dm2\n", imovel.area);
        printf("Banheiros: %d\n", imovel.banheiros);
        printf("Ano: %d\n", imovel.ano);
        printf("Valor do aluguel diario: %.2f\n", imovel.valaluguel);
        printf("Classe energetica: %s\n", imovel.energiaclass);
    }else{
        printf("Imovel desativado");
    }
    printf("\n--------------------------------------------------\n\n\n");
}
