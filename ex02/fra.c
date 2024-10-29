#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int nu; // NUmerador
    int de; // DEnominador
} FR;

FR* make(int numerador, int denominador) {
    FR* res = (FR*) malloc(sizeof(FR));
    res->nu = numerador;
    res->de = denominador;
    return res;
}

/* 
 * Funcoes auxiliares
 */
int mdc(int m, int n) {
    if (m == 0 || n == 0) {
        printf("ERRO: zero como divisor\n");
        exit(1);
    }
    if (m < 0 || n <0) {
        printf("Versao nao atende números negativos\n");
        exit(2);
    }
    int dendo, sor; // diviDENDO, diviSOR
    if (m > n) {
        dendo = m; sor = n;   
    } else {
        dendo = n; sor = m;
    }
    int quoc = dendo / sor, resto = dendo % sor;
    
    while(resto != 0) {
        dendo = sor; sor = resto;
        quoc = dendo / sor; resto = dendo % sor;
    }
    return sor;
}

int mmc(int m, int n) {
    return m * (n / mdc(m, n));
}

// calcula quantos algarismos tem a representacao decimal de n
int largura_dec(int n) {
    int aux = n;

    int i;
    for (i = 0; aux != 0; i = i + 1, aux = aux / 10);
    return i;
}

// Pretty Print
void pprint(FR* f) { 
    int larg_num = largura_dec(f->nu);
    int larg_den = largura_dec(f->de);

    int larg = larg_num > larg_den ? larg_num : larg_den;
    int marg_num = (larg - larg_num) / 2 + 1;
    int marg_den = (larg - larg_den) / 2 + 1;

    int i;
    for (i = 0; i< marg_num; i = i + 1)
        putchar(' ');
    printf("%d\n", f->nu);
    for (i = 0; i<larg+2; i = i + 1)
        putchar('-');
    putchar('\n');
    for (i = 0; i< marg_den; i = i + 1)
        putchar(' ');
    printf("%d\n", f->de);

}

bool normalizada(FR* f) {
    return mdc(f->nu, f->de) == 1;
}

/*
 * Funcoes sobre fracoes
 */
FR* normalizar(FR* f) {
    int d = mdc(f->nu,f->de);
    FR* res = (FR*) malloc(sizeof(FR));
    res->nu = f->nu/d; res->de = f->de/d;
    return res;
}

FR* somar(FR* f, FR* g) {
    int d = mmc(f->de, g->de);

    FR aux;
    aux.nu = (f->nu * d) / f->de + (g->nu * d) / g->de;
    aux.de = d;

    return normalizar(&aux);
}

// funcao multiplicar mutavel e imutavel
void multiplicar(FR* f, FR* g){
  f->nu = f->nu * g->nu;
  f->de = f->de * g->de;
  normalizar(f);
}
FR* multiplicar_imm(FR* f, FR* g){
  FR* h = make((f->nu * g->nu),(f->de * g->de));
  return h;
}
// funcao inverter multiplicavelmente mutavel e imutavel
void inverter_mult(FR* f){
  int aux;
  if(f->nu == 0 || f->de == 0){
    printf("impossivel realizar a inversao\n");
    exit(1);
  }else{
    aux = f->nu;
    f->nu = f->de;
    f->de = aux;
  }
}
FR* inverter_mult_imm(FR* f){
  FR* h = make(f->nu,f->de);
  if(f->nu == 0 || f->de == 0){
    printf("impossivel realizar a inversao\n");
    exit(1);
  }else{
    h->nu = f->de;
    h->de = f->nu;
  }
  return h;
}

int main() {
    printf("O M.D.C. de 144 e 96 eh %d\n", mdc(144,96));
    printf("O M.D.C. de 3 e 2 eh %d\n", mdc(2,3));
    puts("");

    FR * f1 = make(6,9);
    pprint(f1); 
    puts("");
    if (normalizada(f1))
        puts("A fracao eh normalizada\n");
    else
        puts("A fracao não eh normalizada\n");
    
    puts("Após normalizar:\n");
    pprint(normalizar(f1));
    puts("");

    FR * f2 = make(1024, 15);
    pprint(f2);
    puts("");
    if (normalizada(f2))
        puts("A fracao eh normalizada\n");
    else
        puts("A fracao não eh normalizada\n");
    
    puts("Soma de 1/6 e 2/9:\n");
    pprint(somar(make(1,6), make(2,9)));
    puts("");

    // testando funcoes
    /*
    puts("Multiplicando mutavel");
    multiplicar(f1,f1);
    pprint(f1);

    puts("Multiplicando imutavel");
    FR* f5 = multiplicar_imm(f1,f2);
    pprint(f5);
    */ 
    /*
    pprint(f1);
    printf("\n");
    inverter_mult(f1);
    pprint(f1);
    */
    
    puts("imutavel");
    pprint(f1);
    FR* f5 = inverter_mult_imm(f1);
    printf("\n");
    pprint(f5);
    printf("\n");
    pprint(f1);   
    
}