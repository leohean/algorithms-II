#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STOP 0
#define ESPERA_AB 1
#define ESPERA_CDEF 2

int main(){
    

    int resposta;
    do{ 
        int est=ESPERA_AB, cont=0;
        char str[256];
        bool exprVal=false;

        printf("Deseja testar mais alguma expressao regular?\n1 - Sim\n0 - Encerrar\n-> ");
        scanf("%d",&resposta);

        if(resposta==1){

            printf("\nDigite a expressao regular\n-> ");
            scanf("%s",str);

            while(est!=STOP){
                switch(est){
                    case 1:
                        if(str[cont]=='a'||str[cont]=='b'){
                            est=ESPERA_CDEF;
                            cont++;
                        }else{
                            est=STOP;
                        }
                    break;
                    case 2:
                        if(str[cont]=='c'){
                            est=ESPERA_CDEF;
                            cont++;
                        }else if(str[cont]=='d'||str[cont]=='e'||str[cont]=='f'){
                            exprVal=true;
                            est=STOP;
                        }else{
                            est=STOP;
                        }
                    break;
                }
            }

            if(exprVal){
                printf("\nA expressao eh valida\n\n");
            }else{
                printf("\nA expressao nao eh valida\n\n");
            }
            
        }
    }while(resposta!=0);
}