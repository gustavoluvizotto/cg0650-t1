Este trabalho visa comparar três abordagens de conversão matricial de circunferências, permitindo identificar quando é mais vantajoso (rápido) utilizar cada método. Considere circunferências centradas na origem, e o tamanho do raio deve ser um parâmetro de entrada do programa. Este tamanho de raio será variável, e deverá ser medido o tempo para cada tamanho de raio especificado para as duas abordagens.

1. Implementar o algoritmo de conversão matricial de circunferências utilizando a técnica do Meio-Ponto, utilizando somente aritmética inteira e incrementos constantes, segundo Foley.

2. Implementar a conversão matricial de circunferências utilizando coordenadas esféricas (x=R.cos teta, y=R.sin Teta).

3. Implementar a abordagem tradicional, calculando y=+- SQRT(x2- [R2](https://code.google.com/p/cg0650-t1/source/detail?r=2)).

Não se esqueça que medidas de tempo não devem ser feitas para apenas uma execução do algoritmo. Assim, desenhe a circunferência pelo menos 100 vezes, meça o tempo e calcule a média do tempo. Esse procedimento deve ser feito para cada algoritmo.

A saída deverá ser uma tabela de tempos medidos para cada raio (pelo menos 10 medidas de raios significativos), desenhando as circunferências. A escolha da linguagem de programação deve ser entre: Java, C,C++ com Qt ou OpenGL.

OBS:
1. O trabalho pode ser feito em grupos de 2 alunos.
2. Entregar o arquivo fonte e executável, bem como um guia/relatório de funcionamento do sistema e como compilar.