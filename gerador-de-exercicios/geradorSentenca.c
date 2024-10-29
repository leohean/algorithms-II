#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char *criaNome(char principal[], char secundario[], char dificuldade, char tipoQuest[], char opcao){

    int tamPrin=strlen(principal)-1;
    int tamSec=strlen(secundario)-1;
    int tamTipQuest=strlen(tipoQuest);

    int tamTot=tamPrin+tamSec+tamTipQuest;

    char *nome;
    if(strcmp(tipoQuest,"L")==0){
        nome=(char*)malloc((tamTot+4)*sizeof(char));
    }else if(strcmp(tipoQuest,"VF")==0){
        nome=(char*)malloc((tamTot+6)*sizeof(char));
    }     

    int cont=0;
    for(int i=0;i<tamPrin;i++){
        *(nome+cont)=principal[i];
        cont++;
    }

    *(nome+cont)='-';
    cont++;

    for(int j=0;j<tamSec;j++){
        *(nome+cont)=secundario[j];
        cont++;
    }

    *(nome+cont)='-';
    cont++;

    *(nome+cont)=dificuldade;
    cont++;

    *(nome+cont)='-';
    cont++;

    for(int k=0;k<tamTipQuest;k++){
        *(nome+cont)=tipoQuest[k];
        cont++;
    }

    if(strcmp(tipoQuest,"VF")==0){
        *(nome+cont)='-';
        cont++;

        *(nome+cont)=opcao;
        cont++;
    } 

    strcat(nome,".txt");

    return nome;
}

struct sentencaVF{
    char principal[256];
    char secundario[256];
    char dificuldade;

    char sentenca[256];
    int verdade;
}typedef VF;

struct sentencaLacuna{
    char principal[256];
    char secundario[256];
    char dificuldade;

    int qtdLacunas;
    char sentenca[256];
    char respostas[256][256];
}typedef Lacuna;

int main(){

    int resposta;

    do{
        printf("Deseja criar mais uma sentença?\n1 para Sim\n0 para Não\n-> ");
        scanf("%d",&resposta);
        
        char principal[256], secundario[256], dificuldade;

        if(resposta==1){
            int tipoQuest;
            printf("\nA sentença vai ser de Verdadeiro/Falso ou de Lacuna?\n1 para Verdadeiro/Falso\n2 para Lacuna\n-> ");
            scanf("%d",&tipoQuest);
        
            getchar();
            printf("\nQual o assunto principal?\n-> "); 
            fgets(principal, 255, stdin);
            printf("\nQual o assunto secundário?\n-> ");
            fgets(secundario, 255, stdin);
            printf("\nDe 1 a 3, qual a dificuldade?\n-> ");
            scanf("%c",&dificuldade);

            char *nome;

            if(tipoQuest==1){
                VF vf;

                strcpy(vf.principal,principal);
                strcpy(vf.secundario,secundario);
                vf.dificuldade=dificuldade;

                getchar();

                printf("\nDigite a sentença do tipo Verdadeiro/Falsa\n->");
                fgets(vf.sentenca, 255, stdin);

                printf("\nDigite se ela é verdadeira ou falsa\n1 para verdadeira\n0 para falsa\n->");
                scanf("%d",&vf.verdade);

                if(vf.verdade==1){
                    nome=criaNome(principal, secundario, dificuldade, "VF",'V');
                }else{
                    nome=criaNome(principal, secundario, dificuldade, "VF",'F');
                }

                printf("%s",nome);

                FILE *fp=fopen(nome,"a+");
                if(fp!=NULL){
                    fprintf(fp,"%s",vf.sentenca);
                    fclose(fp);
                }
                    

            }else if(tipoQuest==2){
                Lacuna lacuna;

                strcpy(lacuna.principal, principal);
                strcpy(lacuna.secundario, secundario);
                lacuna.dificuldade=dificuldade;

                printf("\nDigite o número de lacunas da sentença\n->");
                scanf("%d",&lacuna.qtdLacunas);

                getchar();

                printf("\nDigite a sentença do tipo Lacuna\n->");
                fgets(lacuna.sentenca, 255, stdin);

                for(int i=0;i<lacuna.qtdLacunas;i++){
                    printf("\nDigite a resposta da lacuna %d\n->",(i+1));
                    fgets(lacuna.respostas[i], 255, stdin);
                }

                nome=criaNome(principal, secundario, dificuldade, "L", '0');

                FILE *fp=fopen(nome,"a+");
                if(fp!=NULL){
                    fprintf(fp,"%s",lacuna.sentenca);
                    fclose(fp);
                }
            
            }

            printf("\n");
            

        }
    }while(resposta!=0);
}