#include "imoveis.h"
#include "data.h"


int AdicionarImoveis(IMOVEL imoveis[], int tot){
    int aux=0;
    char res;

    printf("Qual a morada do im�vel?\n");fflush(stdin); gets(imoveis[tot].morada); printf("%s\n",imoveis[tot].morada);
    printf("Em qual cidade � o im�vel?\n");fflush(stdin); gets(imoveis[tot].cidade); printf("%s\n",imoveis[tot].cidade);
    printf("A qual freguesia pertence o im�vel?\n");fflush(stdin); gets(imoveis[tot].freguesia); printf("%s\n",imoveis[tot].freguesia);
    printf("Qual o tipo de im�vel?[T1,T2 etc]\n");fflush(stdin); gets(imoveis[tot].tipo); printf("%s\n",imoveis[tot].tipo);
    printf("Qual a area do im�vel?[em metros quadrados]\n");fflush(stdin); scanf("%d",imoveis[tot].area); printf("%d\n",imoveis[tot].area);
    printf("Qual o numero de banheiros no im�vel?\n");fflush(stdin); scanf("%d",imoveis[tot].banheiros); printf("%d\n",imoveis[tot].banheiros);
    printf("Em que ano o im�vel foi construido?\n");fflush(stdin); scanf("%d",imoveis[tot].ano); printf("%d\n",imoveis[tot].ano);
    printf("Qual o pre�o base do aluguel deste im�vel?\n");fflush(stdin); scanf("%f",imoveis[tot].valaluguel); printf("%f\n",imoveis[tot].valaluguel);
    printf("Qual a clase energetica do im�vel?\n");fflush(stdin); gets(imoveis[tot].energiaclass); printf("%s\n",imoveis[tot].energiaclass);
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
    
    do{
        aux=0;
        printf("\n\nDeseja inserir outro im�vel?\n");
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

int listarTodosImoveis(IMOVEL imoveis[],int tot){
    char aux;
    printf("\
    ----------------------------------------\
                Lista de imoveis\n\n\
    ----------------------------------------\n\n\n");
    for(int i=0;i<tot;i++){
        listarUmImovel(imoveis[i]);
    }
    printf("Digite qualquer coisa para voltar para o menu anterior\n");
    scanf("%c",&aux);
    return 2;
}

void listarUmImovel(IMOVEL imovel){

    printf("Im�vel %d:\n\n");
    printf("Morada: %s\n",imovel.morada);
    printf("Cidade: %s\n",imovel.cidade);
    printf("Freguesia: %s\n",imovel.freguesia);
    printf("Tipo: %s\n", imovel.tipo);
    printf("Area: %dm2\n", imovel.area);
    printf("Banheiros: %d\n", imovel.banheiros);
    printf("Ano: %d", imovel.ano);
    printf("Valor do aluguel: %f\n", imovel.valaluguel);
    printf("Classe energetica: %d\n", imovel.energiaclass);
    printf("\n--------------------------------------------------\n\n\n");
}