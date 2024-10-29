# Funções, passagem de parâmetros por referência e alocação dinâmica

## Pontuação

| Quesito | Nota |
|---------|------|
| Strings |      |
| Frações |      |
| Polinômios|      |
| TOTAL   |      |

## Objetivos

- Praticar o uso de passagem de parâmetros e alocação dinâmica no projeto de funções
- Exercitar duas estratégias: mutabilidade e imutabilidade nos parâmetros

A biblioteca `string` da Linguagem C usa a estratégia de mutabilidade.

Isso significa que um dos parâmetros é passado por referência, e o resultado
da função é retornado nos dados que o parâmetro aponta.

A versão imutável não modifica os dados acessíveis por meio dos parâmetros,
mas aloca sua própria área na memória, e registra o resultado lá.

Esse conceito pode ser visto no arquivo `mystring.c`.

Perguntas para orientar o exame do arquivo `mystring.c`. (Respostas no final da página)
1. Qual a diferença entre as duas variáveis abaixo? 
(Desenhe o _stack frame_ da pilha.)
```c
    char alocado[10];
    char* nao_alocado;
```
2. Qual a diferença das duas funções nas chamadas abaixo?
```c
    mystrcpy(alocado, b);  // Versao mutavel 
    nao_alocado = mystrcpy_imm(NULL, c);  // Versao imutavel (_immutable_)
```

## Atividades

1. Biblioteca de strings (`mystring`) (2 pontos)
   - Estude a funçâo `strcat` da biblioteca `string`. Escreva um trecho de programa (na função `main`) para observar seu funcionamento. 
   - Reimplemente a função com o nome `mystrcat` (consulte o ítem 4 no Capítulo 7 de _Linguagem C_, de Luís Damas, Editora LTC).
   - Implemente a função `mystrcat_imm`, que retorna um ponteiro para o resultado da concatenação das strings nos parâmetros.
2. Biblioteca de frações (`fra`) (5 pontos)
   - Escolha 1 função da biblioteca frações que resulte em uma fração e implemente uma versão imutável dela (veja o exemplo da função `somar`); se quiser e puder, implemente outras funções.
   - Implemente a versão mutável de 2 funções (pode incluir `somar`).
3. Biblioteca `polinomial` (2 pontos)
   - Escolha 1 função da biblioteca que resulte em um polinômio. Confira o arquivo de README correspondente.
   - Implemente as funções nas duas versões: mutável e imutável.
4. _Stack frame_ (1 ponto)
   - Desenhe os _stack frames_:
     a. de uma função que você implementou nos quesitos anteriores
     b. da função que invoca a função do item a


## Respostas

1. A variável `alocado` é um array de 10 inteiros (portanto, 20 bytes considerando uma arquitetura de 32 bits e um compilador C de 32 bits). A variável `nao_alocado` é apenas um ponteiro (portanto com 4 bytes, o necessário para caber um endereço de 32 bits). IMPORTANTE: `alocado` é, ao mesmo tempo, área de memória (com capacidade de comportar informação) **E** um ponteiro para acessar posições do array; já `nao_alocado` não é um array, portanto não se deve esperar que ele seja o alvo de escrita de informações.

2. `mystrcpy` recebe dois parâmetros: o primeiro aponta um array que é o destino do processo de cópia e o segundo aponta a string a ser copiada (pense aqui como um array). O primeiro parâmetro é preenchido (portanto, alterado). `mystrcpy_imm` aloca algum espaço de memória internamente e retorna apenas o endereço disso.
