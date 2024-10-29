#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define STOP 0
#define LETRA 1

int main(){
    char nome[256];
    printf("Digite o nome do arquivo\n-> ");
    scanf("%s",nome);

    strcat(nome,".txt");

    FILE *fp=fopen(nome,"r");

    int est=LETRA;

    int cont=1;
    
    printf("\n%d ", cont);
    while(est!=STOP){
        char ch;
        ch=fgetc(fp);

        if(ch=='\n'){
            printf("%c", ch);

            cont++;
            printf("%d ", cont);
        }
        else if(ch!=EOF){
            printf("%c", ch);
        }else{
            est=STOP;
        }
    }

    printf("\n");
}