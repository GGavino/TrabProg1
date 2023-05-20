#include "imoveis.h"
#include "data.h"


int AdicionarImoveis(IMOVEL imoveis[], int tot){
    int aux=0;
    char res;

    printf("Qual a morada do imóvel?\n");fflush(stdin); gets(imoveis[tot].morada); printf("%s\n",imoveis[tot].morada);
    printf("Em qual cidade é o imóvel?\n");fflush(stdin); gets(imoveis[tot].cidade); printf("%s\n",imoveis[tot].cidade);
    printf("A qual freguesia pertence o imóvel?\n");fflush(stdin); gets(imoveis[tot].freguesia); printf("%s\n",imoveis[tot].freguesia);
    printf("Qual o tipo de imóvel?[T1,T2 etc]\n");fflush(stdin); gets(imoveis[tot].tipo); printf("%s\n",imoveis[tot].tipo);
    printf("Qual a area do imóvel?[em metros quadrados]\n");fflush(stdin); scanf("%d",imoveis[tot].area); printf("%d\n",imoveis[tot].area);
    printf("Qual o numero de banheiros no imóvel?\n");fflush(stdin); scanf("%d",imoveis[tot].banheiros); printf("%d\n",imoveis[tot].banheiros);
    printf("Em que ano o imóvel foi construido?\n");fflush(stdin); scanf("%d",imoveis[tot].ano); printf("%d\n",imoveis[tot].ano);
    printf("Qual o preço base do aluguel deste imóvel?\n");fflush(stdin); scanf("%f",imoveis[tot].valaluguel); printf("%f\n",imoveis[tot].valaluguel);
    printf("Qual a clase energetica do imóvel?\n");fflush(stdin); gets(imoveis[tot].energiaclass); printf("%s\n",imoveis[tot].energiaclass);
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

int listarImoveis(IMOVEL imoveis[],int tot){
    char aux;
    printf("\
    ----------------------------------------\
                Lista de imoveis\n\n\
    ----------------------------------------\n\n\n");
    for(int i=0;i<tot;i++){
        printf("Imóvel %d:\n\n");
        printf("Morada: %s\n",imoveis[i].morada);
        printf("Cidade: %s\n",imoveis[i].cidade);
        printf("Freguesia: %s\n",imoveis[i].freguesia);
        printf("Tipo: %s\n", imoveis[i].tipo);
        printf("Area: %dm²\n", imoveis[i].area);
        printf("Banheiros: %d\n", imoveis[i].banheiros);
        printf("Ano: %d", imoveis[i].ano);
        printf("Valor do aluguel: %f\n", imoveis[i].valaluguel);
        printf("Classe energetica: %d\n", imoveis[i].energiaclass);

        printf("\n--------------------------------------------------\n\n\n");
    }
    printf("Digite qualquer coisa para voltar para o menu anterior\n");
    scanf("%c",&aux);
    return 2;
}