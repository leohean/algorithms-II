#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX 32
#define TOL 1.e-6

/*
 * Representação de polinomio
 * nome(x) = c_n . x^n + c_n-1 . x^(n-1) + ... + c_1 . x + c_0
 * - nome
 * - grau (n)
 * - coeficientes
 */
typedef struct {
    char nome;
    int grau;
    float* coefs;
} POLI;

POLI* make(char letra, int max_expoente, float* cs) {
    POLI* res = (POLI*) malloc(sizeof(POLI));
    res->nome = letra;
    res->grau = max_expoente;
    int i;
    res->coefs = (float*) malloc( (max_expoente + 1) * sizeof(float) );
    for (i=0; i<=max_expoente; i++)
        res->coefs[i] = cs[i];
    return res;
}

/*
 * Funções
 */

float avaliar(POLI* p, float a) {
    return 0.0; // TODO: calcular p(a)
}

float raiz(POLI* p) {
    return 0.0;
    // retorna uma raiz do polinomio; se houver 2 ou mais, retorna 1 qq
    // funciona para n == 1 e n == 2 (báskara)
}

// Imprime floats inteiros como inteiros e esconde o grau (ou o x) para x^1 (ou x^0)
void imprime_termo(float coef, int grau) {
    if (fabs(coef - round(coef)) < TOL) {                        // Caso float inteiro
        if ((int)round(coef) == 1) {                               // Caso float = 1
            if (grau == 0) {printf("1");}                            // Caso 1x^0
            else if (grau == 1) {printf("x");}                       // Caso 1x^1
            else {printf("x^%d", grau);}                             // Caso 1x^n
        } else {                                                   // Caso float != 1
            if (grau == 0) {printf("%d", (int)round(coef));}         // Caso cx^0
            else if (grau == 1) {printf("%dx", (int)round(coef));}   // Caso cx^1
            else {printf("%dx^%d", (int)round(coef), grau);}         // Caso cx^n
        }
    } else {                                                     // Caso float não inteiro 
        if (grau == 0) {printf("%.3f", coef);}                     // Caso .3cx^0
        else if (grau == 1) {printf("%.3fx", coef);}               // Caso .3cx^1
        else {printf("%.3fx^%d", coef, grau);}                     // Caso .3cx^n
    }
}

// Alteração: Faz uso de imprime_termo para as melhorias mencionadas
void pprint(POLI* p) {
    printf("%c(x) = ", p->nome);
    if (p->grau == 0){
        imprime_termo(p->coefs[0], 0);
        printf("\n");
        return;
    } 
    if (p->grau == 1){
        imprime_termo(p->coefs[1], 1);
        if (fabs(p->coefs[0]) > TOL) {
            if (p->coefs[0] < -TOL) {printf(" - ");}
            else {printf(" + ");}
            imprime_termo(fabs(p->coefs[0]), 0);
        }
        printf("\n");
        return;
    }

    imprime_termo(p->coefs[p->grau], p->grau);
    int i;
    for(i=p->grau-1; i >= 0; i = i - 1) {
        if (fabs(p->coefs[i]) > TOL) {
            if (p->coefs[i] < -TOL) {printf(" - ");}
            else {printf(" + ");}
            imprime_termo(fabs(p->coefs[i]), i);
        }
    }
    printf("\n");
}

bool normalizado(POLI* p) {
    return p->coefs[p->grau] > TOL;
}

void normalizar(POLI* p) {
    int i = p->grau; 
    while(p->coefs[i] < TOL) 
        i = i - 1;
    p->grau = i;
}

// somar

// derivar
void derivarMutavel(POLI* polinomio){
    int i;
    for(i = 0; i <= (polinomio -> grau - 1); i ++ ){
        polinomio -> coefs[i] = (i + 1) * (polinomio -> coefs[i+1]);
    }
    polinomio -> grau = polinomio -> grau - 1;
}

POLI* derivarImutavel(POLI* polinomio){
    int i;
    float aux[polinomio -> grau];
    for(i = 0; i <= (polinomio -> grau - 1); i ++ ){
        aux[i] = (i + 1) * (polinomio -> coefs[i+1]);
    }
    POLI* poli = make(polinomio->nome, polinomio ->grau-1,aux);
    return poli;
}
// multiplicar por escalar (constante)

// multiplicar por x

// multiplicar 2 polinomios

int main() {
    float cq[3] = {1.0,5.0,2.7};
    POLI* q = make('q', 2, cq);
    pprint(q);

    float cp1[2] = {4.7,0.575};
    POLI* p1 = make('k',1,cp1);
    pprint(p1);

    float cp2[3] = {3.5,0.5,0.0};
    POLI* p2 = make('w',3,cp2);
    pprint(p2);

    float cp3[1] = {0.0};
    POLI* p3 = make('z',1,cp3); 
    
    //**************************************
    // Funcao derivar polinomio Imutavel
    POLI* p6 = (derivarImutavel(p1));
    pprint(p6);
   
    // Funcao derivar polinomio mutavel
    derivarMutavel(q);
    pprint(q);
    //**************************************

    // Exemplo de polinomio normalizado
    puts("--------");
    pprint(p1);
    if (normalizado(p1))
        printf("O polinomio %c estah normalizado.\n", p1->nome);
    else
        printf("O polinomio %c nao estah normalizado\n", p1->nome);

    // Exemplo de polinomio nao normalizado
    puts("--------");
    float cp4[5] = {4.0,7.5,1.0,0.0,0.0};
    POLI* p4 = make('s',5,cp4);
    pprint(p4);
    if (normalizado(p4))
        printf("O polinomio %c estah normalizado.\n", p4->nome);
    else
        printf("O polinomio %c nao estah normalizado\n", p4->nome);

    // Normalizando
    puts("--------");
    normalizar(p4);
    pprint(p4);
    if (normalizado(p4))
        printf("O polinomio %c estah normalizado.\n", p4->nome);
    else
        printf("O polinomio %c nao estah normalizado\n", p4->nome);
}