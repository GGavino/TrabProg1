#include "alugueis.h"
#include "data.h"

int AdicionarAluguel(IMOVEL imoveis[], int tot){
    ALUGUELD aux;
    char auxchar;
    int res;
    int id=0;
    do{
        res=printf("Qual o id do Imóvel a qual este aluguel pertence?\n");scanf("%d",&id);
    }while(res!=1 || id < 1 || id > tot); // verifica se o id foi lido de maneira correta e se o mesmo é valido
    do{
        res=printf("Qual a data de inicio do aluguel?[dd/mm/aaaa]\n");scanf("%d/%d/%d",&aux.diaini,&aux.mesini,&aux.anoini);
        if(res != 3) printf("Resposta invalida\n\n");
        if(validardata(aux.diaini,aux.mesini,aux.anoini)) printf("Data invalida\n\n");
    }while(res!=3 || validardata(aux.diaini,aux.mesini,aux.anoini));// verifica se a data inicial foi lida de maneira correta e se a mesma é valida

    do{
        res=printf("Qual a data de fim do aluguel?[dd/mm/aaaa]\n");scanf("%d/%d/%d",&aux.diaini,&aux.mesini,&aux.anoini);
        if(res != 3) printf("Resposta invalida\n\n");
        if(validardata(aux.diafim,aux.mesfim,aux.anofim)) printf("Data invalida\n\n");
        if(comparardatas(aux.diaini,aux.mesini,aux.anoini,aux.diafim,aux.mesfim,aux.anofim) > -7) printf("O aluguel deve ser de pelo menos 7 dias\n\n");
    }while(res!=3 || validardata(aux.diafim,aux.mesfim,aux.anofim) || comparardatas(aux.diaini,aux.mesini,aux.anoini,aux.diafim,aux.mesfim,aux.anofim) > -7);// verifica se a data final foi lida de maneira correta e se a mesma é valida
    do{
        res=printf("Qual a data de fim do aluguel?[dd/mm/aaaa]\n");scanf("%d/%d/%d",&aux.diapag,&aux.mespag,&aux.anopag);
        if(res != 3) printf("Resposta invalida\n\n");
        if(validardata(aux.diapag,aux.mespag,aux.anopag)) printf("Data invalida\n\n");
    }while(res!=3 || validardata(aux.diapag,aux.mespag,aux.anopag));// verifica se a data do pagamento foi lida de maneira correta e se a mesma é valida
    AdicionarAlugelNaLista(imoveis,aux, id-1);
    do{
        res=0;
        printf("\n\nDeseja inserir outro Aluguel?\n");
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





int comparardatas(int dia1,int mes1,int ano1,int dia2,int mes2,int ano2){
    int dif=0;
    dif= dia2-dia1;
    for(dif=0; dia1!=dia2 || mes1!=mes2 || ano1!=ano2; ){
        if((12*ano1 + mes1 + dia1 / 100) < (12*ano2 + mes2 + dia2 / 100)){
            dia2--;
            if(dia2 < 1){
                int DiasEmUmMes[] = {31, 28 + Bissexto(ano2), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
                mes2--;
                if(mes2<1){
                    mes2=12;
                    ano2--;
                }
                dia2 = DiasEmUmMes[mes2 - 1];
                dif--;
            }
        } else {
            dia1--;
            if(dia1 < 1){
                int DiasEmUmMes[] = {31, 28 + Bissexto(ano1), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
                mes1--;
                if(mes1<1){
                    mes1=12;
                    ano1--;
                }
                dia1 = DiasEmUmMes[mes1 - 1];
                dif++;
            }
        }
    }

}

int Bissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int validardata(int dias, int mes, int ano) {
    if (ano < 1 || mes < 1 || mes > 12 || dias < 1) {
        return 0;
    }

    int DiasEmUmMes[] = {31, 28 + Bissexto(ano), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int diasmax = DiasEmUmMes[mes - 1];

    if (dias > diasmax) return 0;

    return 1;
}