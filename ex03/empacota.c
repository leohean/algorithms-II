#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void empacota(char* s){
    int est=1, cont=0;
    char aux;
    while(est!=0){
        switch(est){
            case 1:
                printf("%c",*(s+cont));
                aux=*(s+cont);
                cont++;

                if(*(s+cont)!='\0')
                    est=2;
                else
                    est=0;
            break;
            case 2:
                if(aux==*(s+cont)){
                    cont++;
                    if(*(s+cont)=='\0')
                        est=0;
                }else{
                    est=1;
                }
            break;
        }
    }
}

int main(){
    char *str=(char*)malloc(41*sizeof(char));
    str="Brrrroooommmmmmmm!!!!!!!    Tttooomm....";
    


    empacota(str);
}