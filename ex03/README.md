# Exercícios EX03

| Questão | Pontuação |
|---------|-----------|
|  1      |           |
|  2      |           | 
|  3      |           | 
|  4      |           | 
|  5      |           |

1. `myprintf.c`
   - Revise as [notas da Aula 1](https://github.com/aespiral/central-atp-ii-2022/tree/main/aulas/01-22AGO) sobre representação em computação
   - Analise os arquivos `myprintf.c` e `DOCUM.md`
   - Implemente a função `myprintf` 
     - O primeiro parâmetro é uma string que tem, no máximo, um _placeholder_ 
       - O _placeholder_ `%d` é substituído pela representação `dec2display` do 2o parâmetro
       - Para `%b`, idem com `bin2display`
       - Para `%x`, idem com `hex2display`
    - O segundo parâmetro é um ponteiro para um MYUINT ou NULL

2. `MYFLOAT_DEC`
   - Implemente a _struct_ `MYFLOAT_DEC` conforme especificado, incluindo a função makeFLOAT_DEC
   - Implemente a função `somaFLOAT_DEC` conforme a especificado a seguir:
```c
MYFLOAT_DEC* somaFLOAT_DEC(MYFLOAT_DEC* f1, MYFLOAT_DEC* f2);
// A soma é retornada como uma nova alocação 
// Considere apenas valores positivos
```
```
algoritmo:
|  leia: dois argumentos do tipo MYFLOAT_DEC
|  determine qual argumento de menor expoente (menor ou igual)
|  repita:
|  |  se expoentes iguais:
|  |  |  então: interrompa
|  |  fim_se
|  |  incremente o expoente do argumento de menor expoente
|  |  divida a mantissa por 10
|  fim_repita
|  crie MYFLOAT_DEC
|  preencha mantissa do novo como a soma das mantissas dos argumentos
|  preencha expoente com o expoente dos argumentos (são iguais)
|  preencha sinal como +
|  normalize o valor criado 
|  retorne: referência do valor criado
end_algoritmo
```
Normalizar significa ajustar a mantissa para ficar na faixa válida. Se o número somado extrapola para mais da faixa válida, então a mantissa é dividida por 10 e o expoente é incrementado até voltar para a faixa. Com valores negativos, a soma poderia ser um número pequeno (menor que 1), daí a normalização seria o inverso: multiplicar a mantissa por 10, decrementando o expoente.

3. Sobre processamento de _strings_ (possivelmente, com MEF)
   - `char* empacota(char* s)`
     - Recebe uma _string_ e resume a um caracter qualquer sequência repetida consecutiva desse caracter.
     - `empacota("Brrrroooommmmmmmm!!!!!!!    Tttooomm....");`   - >  `"Brom! Ttom."

4. Expressões regulares
   - Considere a seguinte expressão regular `/ \[ab\]c*\[def\] /`
   - Ela descreve, entre infinitos outras possibilidades, os seguintes exemplos:
     - `accccd`
     - `bccf`
     - `bcccccccf`
     - `ad`
     - `bccce`
   - Quando uma lista de signos aparece entre colchetes, significa que toda a expressão entre colchetes pode ser substituída por um único signo, escolhido daquela relação
     - \[xyz\] vale apenas x ou vale apenas y ou vale apenas z
     - o asterisco significa a repetição de 0 ou mais vezes do signo que o precede
   - Desenhe uma máquina de estados que identifica sentenças que pertencem à linguagem especificada pela expressão regular
   - Implemente como programa que aceita digitações de sentenças e informa se elas são da linguagem; o programa deve solicitar em loop até o usuário optar por encerrar

5. Arquivos
Implemente o utilitário **numera.c** que imprime na tela o conteúdo de um arquivo texto, numerando as linhas. O nome do arquivo deve ser passado pela linha de comando.
