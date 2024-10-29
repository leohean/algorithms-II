#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *criaNome(char principal[], char secundario[], char dificuldade, char tipoQuest[], char opcao){

    int tamPrin=strlen(principal);
    int tamSec=strlen(secundario);
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

int main(){

    char sentenca[256];
    char str1[255], str2[255], str3, str4[255];
    int i=0, j=0, k=0,dificuldade;
    
    int numQuest;
    
    printf("Digite a quantidade de questões\n-> ");
    scanf("%d",&numQuest);

    FILE *prova=fopen("prova.txt","w");

    for(int i=1;i<=numQuest;i++){
        printf("\nDigite o assunto\n-> ");
        scanf("%s",str1);

        printf("\nDigite o sub-assunto\n-> ");
        scanf("%s",str2);

        printf("\nDigite a dificuldade\n-> ");
        scanf(" %c",&str3);

        printf("\nDigite o tipo\n-> ");
        scanf("%s",str4);

        if(strcmp(str4,"M")==0){
            srand(time(NULL));

            int num = 0;
            int aux=(rand() % 100);

            if(aux >= 0 && aux < 51){
                num = 5;
            }else if(aux >= 51 && aux < 67){
                num = 3;
            }else if(aux >= 67 && aux < 83){
                num = 4;
            }else if(aux >= 83 && aux < 100){
                num = 6;
            }

            int sortAux=(rand()%num);

            int resultado;
            printf("\nO enunciado pedirá a alternativa Correta ou a Falsa?\n1 - Correta\n0 - Falsa\n-> ");
            scanf("%d", &resultado);

            FILE *fpVM=fopen(criaNome(str1,str2,str3,"VF",'V'),"r");
            FILE *fpFM=fopen(criaNome(str1,str2,str3,"VF",'F'),"r");

            if(resultado==1){
                fprintf(prova,"%d -) Assinale a alternativa CORRETA:\n", i);

                for(int i=0;i<num;i++){
                    if(i==sortAux){
                        if(fgets(sentenca,255,fpVM)){
                            fprintf(prova,"( ) %s", sentenca);
                        }
                    }else{
                        if(fgets(sentenca,255,fpFM)){
                            fprintf(prova,"( ) %s", sentenca);
                        }
                    }
                }
            }else{
                fprintf(prova,"%d -) Assinale a alternativa FALSA:\n", i);

                for(int i=0;i<num;i++){
                    if(i==sortAux){
                        if(fgets(sentenca,255,fpFM)){
                            fprintf(prova,"( ) %s", sentenca);
                        }
                    }else{
                        if(fgets(sentenca,255,fpVM)){
                            fprintf(prova,"( ) %s", sentenca);
                        }
                    }
                }
            }

        }
        else if(strcmp(str4,"VF")==0){
            srand(time(NULL));

            int num=(rand()%6+3);

            FILE *fpV=fopen(criaNome(str1,str2,str3,str4,'V'),"r");
            FILE *fpF=fopen(criaNome(str1,str2,str3,str4,'F'),"r");

            int v, f; 
                fprintf(prova,"%d -) Indique se as seguintes sentenças são falsas ou verdadeiras." 
                            "Se a resposta for falsa, explique.\n", i);

                v = 0, f = 0;
                for(int i=0;i<num;i++){
                    int vf=(rand()%2); 
                    if(vf==1){
                        if(fpV == NULL){
                            printf("Combinação dos requisitos inválida. Tente novamente!1");
                            exit(13);
                        }
                        v++;
                        if(fgets(sentenca,255,fpV)){
                            fprintf(prova,"( ) %s", sentenca);
                        }
                    }else if(vf==0){
                        if(fpF == NULL){
                            printf("Combinação dos requisitos inválida. Tente novamente!2");
                            exit(13);
                        }
                        f++;
                        if(fgets(sentenca,255,fpF)){
                            fprintf(prova,"( ) %s", sentenca);
                        }
                    }
                }
            fclose(fpV);
            fclose(fpF);      
        }else if(strcmp(str4,"L")==0){
            srand(time(NULL));

            int num=(rand()%4+2);

            FILE *fp=fopen(criaNome(str1,str2,str3,str4, '0'),"r");

            if(fp == NULL){
                printf("Combinação dos requisitos inválida. Tente novamente!3");
                exit(12);
            }

            fprintf(prova,"%d -) Preencha os espaços em cada uma das sentenças:\n", i);

            for(int i=0;i<num;i++){
                if(fgets(sentenca,255,fp)){
                    fprintf(prova,"%s\n", sentenca);
                }
            }
        }
        printf("\n-----------------------------------------\n");
    }  
    fclose(prova); 
}