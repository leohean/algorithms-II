# Biblioteca de funções em C para representação e manipulação de frações

Frações são representadas como registros com 2 campos: numerador e denominador.

## Funções auxiliares

- `mdc`
- `mmc`
- `pretty print`
- `normalizada`

Uma fração é normalizada é aquela cujos numerador e denominador são primos entre si.

## Funções principais

- `normalizar`
- `somar`

As funções que resultam em frações foram implementadas na versão imutável.

## Exercícios

- `inverter multiplicativamente`: a fração multiplicativamente inversa de a/b é b/a
  - Se o parâmetro recebido for zero, a operação não deve ser realizada: encerrar o programa
- `multiplicar` 
- `comparar`

A comparação pode retornar um valor codificado como inteiros. Sugestão:
```
#define EQ 0
#define GT 1
#define LT -1
```
`EQ` significa igual (_equal_); `GT`, maior do que (_greater than_); `LT`, menor do que (_less than_).