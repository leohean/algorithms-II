# Biblioteca de funções em C para representação e manipulação de polinômios


## Funções a serem implementadas

- somar dois polinômios

Na soma de dois polinômios, os termos de maior grau podem se cancelar, 
resultando num polinômio cujo grau real é menor do que o representado
pelo campo específico no registro. Para isso, deve haver uma operação
de normalização, que busca ajustar o campo correspondente ao grau de
acordo com os valores que constam efetivamente no polinômio.

- derivar um polinômio
```
2 x^5 + x^4 + 7 x^2 + 100   - - - >  10 x^4 + 4 x^3 + 14 x
```
- multiplicar um polinômio por uma constante:
```
4 x^3 + 2 x + 10   ,  5   - - - >   20 x^3 + 10 x + 50
```
- multiplicar um polinômio por um monômio de algum grau
```
7 x^2 + 3 , 2 (=x^2) - - - >  7 x^4 + 3 x^2
```
- multiplicar dois polinômios
  - exercício extenso
  - utliza as multiplicações por constante e por polinômio
- etc.
 
## Documentação

Um polinômio tem sua representação gráfica em textos de Matemática, 
e também nos cadernos e nos quadros-negros. 
Mas, o que seria a representação de um polinômio em um programa?

A memória de um computador não é exatamente uma superfície sobre a qual se faz riscos. 

Quando estamos num editor de texto, escrevendo em uma linguagem de programação, 
o que temos são as formas básicas de representar dados: variáveis, registros, arrays. 
(Essa é a perspectiva da linguagem C)

Para chegar à representação de um polinômio num programa, é preciso se
perguntar: que informações definem um polinômio? Seu nome e os valores
dos coeficientes dos diversos termos. Obviamente, o polinômio é finito,
e existe o termo de maior grau.

Para representar os coeficientes, a escolha é direta: um array de floats. Armazenar o grau do polinômio agiliza as operações (algoritmos). 

A ordem de disposição dos coeficientes dentro do array importa.
Existe uma ordem mais fácil: consiste em começar o array com o
termo de menor grau (o termo independente, que é apenas uma constante,
ou seja, correspondente ao termo `x^0`).

Para agregar em um só ponto todas as informações (o array de coeficientes,
o maior grau e o nome), usamos um registro (struct em C).

Toda a manipulação de polinômios agora passa a ser uma função sobre
algum registro desses, que representam polinômios.

Há uma variedade de manipulações possíveis:
- obter o valor (avaliar) de um polinômio para um dado valor de `x`;
- somar dois polinômios;
- calcular a derivada do polinômio;
- etc.

Na soma de dois polinômios, os termos de maior grau podem se cancelar, 
resultando num polinômio cujo grau real é menor do que o representado
pelo campo específico no registro. Para isso, deve haver uma operação
de normalização, que busca ajustar o campo correspondente ao grau de
acordo com os valores que constam efetivamente no polinômio.
