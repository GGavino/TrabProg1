#include "imoveis.h"
#include "data.h"


int AdicionarImoveis(IMOVEL imoveis[], int tot){
    int aux=0;
    char res;

    printf("Qual a morada do imovel?\n");fflush(stdin); gets(imoveis[tot].morada); printf("%s\n",imoveis[tot].morada);
    printf("Em qual cidde é o imovel?\n");fflush(stdin); gets(imoveis[tot].cidade); printf("%s\n",imoveis[tot].cidade);
    printf("A qual freguesia pertence o imovel?\n");fflush(stdin); gets(imoveis[tot].freguesia); printf("%s\n",imoveis[tot].freguesia);
    printf("Qual o tipo de imovel?[T1,T2 etc]\n");fflush(stdin); gets(imoveis[tot].tipo); printf("%s\n",imoveis[tot].tipo);
    printf("Qual a area do imovel?[em metros quadrados]\n");fflush(stdin); scanf("%d",imoveis[tot].area); printf("%d\n",imoveis[tot].area);
    printf("Qual o numero de banheiros no imovel?\n");fflush(stdin); scanf("%d",imoveis[tot].banheiros); printf("%d\n",imoveis[tot].banheiros);
    printf("Em que ano o imovel foi construido?\n");fflush(stdin); scanf("%d",imoveis[tot].ano); printf("%d\n",imoveis[tot].ano);
    printf("Qual o preço base do aluguel deste imovel?\n");fflush(stdin); scanf("%d",imoveis[tot].valaluguel); printf("%d\n",imoveis[tot].valaluguel);
    printf("Qual a clase energetica do imovel?\n");fflush(stdin); gets(imoveis[tot].energiaclass); printf("%s\n",imoveis[tot].energiaclass);
    do{
        aux=0;
        printf("Alguma obsevacao a fazer sobre o imovel?\n");fflush(stdin);scanf("%c", &res);
        if(res == 'S' || res == 's'){
            printf("Qual?\n");fflush(stdin);gets(imoveis[tot].observacao);printf("%s\n",imoveis[tot].observacao);
        }else if(res == 'N' || res == 'n'){
            strcpy(imoveis[tot].observacao,"Nenhuma observacao");
        }else{
            printf("Resposta invalida\n\n");
            aux=1;
        }
    }while(aux!=0);    
    
    do{
        aux=0;
        printf("\n\nDeseja inserir outro imovel?\n");
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
