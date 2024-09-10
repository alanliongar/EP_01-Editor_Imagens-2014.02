<h1>Universidade de São Paulo - 16/09/2014<br>
MAC122 - Princípios de Desenvolvimento de Algoritmos<br>
Segundo Semestre de 2014<br>
Profs. Paulo Miranda<br>
Primeiro Exercício-Programa (EP1) - Parte I<br>
Editor de Imagens</h1><br><br>

**Introdução**

Neste exercício-programa, você vai desenvolver um programa de manipulação de imagens, codificadas no formato PGM. Este formato será utilizado pela sua simplicidade.

**Representação de Imagens**

Cada ponto (pixel) que compõe a imagem é representado por um valor, que representa uma tonalidade de cinza. Os extremos da escala são o número zero, que representa o preto, e o número 255, que representa o branco. Uma imagem é representada por uma matriz de números inteiros, que correspondem a um nível de cinza de cada ponto.

**Indexação de Imagens**

Os pontos da imagem são numerados (indexados) a partir do canto superior esquerdo, da esquerda para a direita, de cima para baixo. Assim, uma imagem de 200 linhas e 300 colunas possui a indexação ilustrada a seguir:
<pre>
(0,0) (0,1) ... (0,299)
(1,0) (1,1) ... (1,299)
...
(199,0) (199,1) ... (199,299)
</pre>

**Funções de Transformação**

### Funções de Edição

#### Negativo

Fazer o negativo de uma imagem consiste em inverter os valores dos pixels em relação à média dos valores possíveis. Os valores próximos de branco se transformam em próximos de preto e vice-versa. Se a imagem está armazenada na matriz M, o negativo é calculado da seguinte forma: 255 - M[i][j]

#### Corte

O corte de uma imagem significa definir uma área retangular dentro da imagem como sendo a própria imagem. Seu programa deve ler as coordenadas do canto superior esquerdo da área de corte (xSup, ySup) e do canto inferior direito (xInf, yInf) e considerar a nova imagem de trabalho como sendo a imagem contida no retângulo definido por estes pontos.

#### Rebatimento

Seu programa deve fazer o espelhamento vertical ou horizontal da imagem.

#### Rotação

Seu programa deve fazer a rotação da imagem em 90 graus, sentido horário. Tenha atenção especial no caso das figuras retangulares.

### Funções de Filtro

Filtros são transformações com a finalidade de melhorar uma imagem, dar mais nitidez, etc. Todas as funções de filtro irão funcionar baseadas no mesmo princípio. Cada ponto (i, j) da imagem resultante será uma função dos valores de sua vizinhança.

#### Filtro da Mediana

O filtro da mediana é uma transformação bastante comum para suavizar ruídos do tipo impulso em sinais e imagens digitais. Cada ponto da matriz após a aplicação do filtro é a mediana dos valores da vizinhança do ponto.

#### Filtro da Média

No filtro da média, o valor de cada ponto deve ser a média dos valores da vizinhança.

#### Filtro de Erosão

Neste filtro, o valor de cada ponto em (i, j) será o valor mínimo de seus vizinhos em (k, l).

#### Filtro de Dilatação

Neste filtro, o valor de cada ponto em (i, j) será o valor máximo de seus vizinhos em (k, l).

#### Filtros de Borda

Filtros de borda procuram zerar posições semelhantes aos seus vizinhos e isolar aquelas diferentes. Vamos implementar três algoritmos diferentes para identificar as bordas.

* borda1: utiliza a matriz resultante da subtração da matriz de dilatação pela matriz de erosão.
* borda2: utiliza a matriz resultante da subtração da matriz original pela matriz de erosão. M(i, j) − E(i, j)
* borda3: utiliza a matriz resultante da subtração da matriz de dilatação pela matriz original. D(i, j) − M(i, j)<br>
Para que os resultados sejam melhor visualizados, torna-se necess´ario aplicar uma outra tranformação, definida a seguir:

*limiarização. A limiarização de uma matriz M na altura k > 0 (inteiro) é dada por uma matriz binária Lk, definida como segue:
IMAGEM

Você deve aplicar em cada filtro de borda, a limiarização para um k fornecido pelo usuario (O valor das posições da matriz resultante ´e definido em geral como 0 ou 1. Colocamos os valores 0
ou 255 para melhor visualização dos resultados). Desta maneira teremos:
IMAGEM

2 O que o seu programa deve fazer
Ao executar o programa, ele deve solicitar o prefixo do nome de um arquivo .pgm (sem a extens˜ao .pgm). Caso seja fornecido um nome de arquivo inv´alido, o programa deve continuar a perguntar o nome do arquivo, at´e ser fornecido um nome v´alido e os dados terem sido carregados. Ap´os a carga do arquivo, o programa deve apresentar um menu de op¸c˜oes e deve solicitar um comando:


* c - carga. Seu programa deve ler um novo arquivo. Deve ser solicitado o prefixo do nome de um arquivo .pgm (sem a extens˜ao) e ler os dados nele contido. Caso seja fornecido um nome de arquivo inválido, o programa deve continuar a perguntar o nome do arquivo, até ser fornecido um nome válido e os dados terem sido carregados.
* t - exibição na tela. Seu programa deve mostrar na tela a matriz correspondente à imagem. Utilize o formato ”%3d” para impressão dos núumeros.
* n - negativo. Seu programa deve calcular o negativo da imagem.
* r - rota¸c˜ao. Seu programa deve fazer a rota¸c˜ao da imagem.
* v - rebatimento vertical. Seu programa deve fazer o rebatimento vertical da imagem.
* h - rebatimento horizontal. Seu programa deve fazer o rebatimento horizontal da imagem.
* x - corte. Seu programa deve ler os quatro valores das coordenadas e fazer o corte da imagem.
* e - erosão. Seu programa deve aplicar o filtro de mínimo à imagem.
* d - dilatação. Seu programa deve aplicar o filtro de máximo à imagem.
* m - mediana. Seu programa deve aplicar o filtro da mediana.
* M - média. Seu programa deve aplicar o filtro da média.
* 1, 2 ou 3 - filtro de bordas. Seu programa deve aplicar o filtro de borda apropriado (veja a descrição de filtros), com a limiarizacão para k dado pelo usuário.
* g - gravacão. Seu programa deve gravar em um arquivo a imagem que está sendo transformada. O nome do arquivo deve ser o nome do arquivo original, seguido dos comandos de transformacão da imagem que foram executados na imagem. Por exemplo, se o arquivo chamado xyz.pgm for transformado pelos comandos r e 2, o arquivo gravado deve ser xyz-r2.pgm
* C - comparação. Seu programa deve ler o prefixo do nome de um arquivo de imagem, ler a imagem e comparar com a imagem atual, informando se são iguais ou diferentes. Esta opção é útil para comparar as imagens que seu programa gera com as imagens geradas pelo programa executável entregue.
* a - ajuda. Seu programa deve exibir novamente o menu de opções.
* s - sair. Seu programa deve ser encerrado.

OBS: Ao carregar um novo arquivo ou reverter para o original, a memória dos comandos de modificação utilizados deve ser zerada, de modo que ao salvar a imagem sejam registrados no nome do arquivo somente os comandos dados daquele momento para frente.

OBS2: Considere o tamanho máximo de janela como sendo 50 e o mínimo como sendo
3. Caso o usuário digite uma valor inválido, avise-o e leia novamente o valor até que ele digite um valor válido.

**Formato dos Arquivos**

Para este programa vamos utilizar arquivos em formato PGM, que são fáceis de decodificar. Segundo este formato, o arquivo contém um cabeçalho e a matriz correspondente à imagem. Veja exemplo a seguir.

P2
5 5
16
9  4  5 0  8
10 3  2 1  7
9  1  6 3  15
0  3  8 10 1
1  16 9 12 7

A primeira linha contém uma palavra-chave “P2” que identifica o tipo de arquivo. Será sempre “P2” no nosso caso. A segunda linha contém dois números que correspondem ao número de colunas (primeiro) e linhas (segundo). A terceira linha contém um número que é o maior número da matriz. As demais linhas do arquivo correspondem às linhas da matriz (imagem). Opcionalmente, o arquivo pode conter uma linha com comentários iniciada com o caractere ’#’. Por questões de simplicidade, considere que as imagens que iremos trabalhar não possuem esta linha (se você pegar um arquivo pgm na internet ou gerado de um aplicativo, você pode editar o arquivo em um editor de texto simples e remover a linha de comentário).

Resumindo, um arquivo PGM possui a seguinte estrutura interna:
P2
Largura Altura
Valor máximo de intensidade
Valor pixel (0,0)
Valor pixel (1,0)
Valor pixel (2,0)
...
Valor pixel (x,y)
...
Valor pixel (Largura - 1, Altura - 1)

[IMAGEM]

Gere arquivos pequenos para testar seu programa antes de trabalhar com as imagens reais. Para visualizar as imagens você pode usar algum programa, como o IrfanView. O programa GIMP (para Linux) é um transformador de imagens bastante completo, que implementa as transformações pedidas neste EP e inúmeras outras. Com ele você pode, entre muitas outras coisas, converter para o formato PGM imagens que estão em outros formatos.

**Estrutura de seu Programa**<br><br>

Seu programa deve obrigatoriamente implementar as funções com os protótipos descritos abaixo:<br><br>

int** AlocaMatriz(int m, int n);<br>
void LiberaMatriz(int** M, int m, int n);<br>
int** AbreImagem(char filename[], int* m, int* n);<br>
void GravaImagem(char filename[], int** M, int m, int n);<br>
void negativo(int** M, int m, int n);<br>
void rebatimentoVertical(int** M, int m, int n);<br>
void rebatimentoHorizontal(int** M, int m, int n);<br>
int** rotacao(int **M, int* m, int* n);<br>
int** corte(int** M, int* m, int* n, int xsup, int ysup, int xinf, int yinf);<br>
void filtroMediana(int** M, int m, int n, int larguraJanela);<br>
void filtroMedia(int** M, int m, int n, int larguraJanela);<br>
void filtroErosao(int** M, int m, int n, int larguraJanela);<br>
void filtroDilatacao(int** M, int m, int n, int larguraJanela);<br>
void limiarizacao(int** M, int m, int n, int k);<br>
void filtroBorda1(int** M, int m, int n, int larguraJanela, int k);<br>
void filtroBorda2(int** M, int m, int n, int larguraJanela, int k);<br>
void filtroBorda3(int** M, int m, int n, int larguraJanela, int k);<br>

**Observações**

1. Todas as matrizes utilizadas para guardar os dados das imagens devem ser alocadas dinamicamente.
2. Caso seu programa seja finalizado por violações de tamanho de memória, verifique se você não está utilizando matrizes auxiliares desnecessárias que possam estar excedendo o espaço disponível na memória. O programa se comporta bem com até três matrizes de 400x400 na memória ao mesmo tempo.
3. Várias das operações exigem que você faça uma cópia da matriz, pois as novas posições dependem do valor das vizinhas antigas.

**Exemplo**

Segue abaixo um exemplo de execução do programa. Você pode simular outros comportamentos a partir do executável de referencia entregue junto com o enunciado. Teste também com as figuras fornecidas.
<br><br>
Digite o nome do arquivo de entrada: entrada<br>
Arquivo entrada.pgm carregado com sucesso.<br>
c - carga<br>
t - exibicao na tela<br>
n - negativo<br>
r - rotacao<br>
v - espelhamento vertical<br>
h - espelhamento horizontal<br>
x - corte<br>
e - filtro da erosao<br>
d - filtro da dilatacao<br>
m - filtro da mediana<br>
M - filtro da media<br>
1 - filtro de bordas 1<br>
2 - filtro de bordas 2<br>
3 - filtro de bordas 3<br>
g - gravacao<br>
C - comparacao<br>
a - ajuda<br>
s - sair
<pre>
Digite um comando: t
9  4  5  0  8
1  3 10  3  2
1  7  5  7  9
1  6  3 15  2
2  0  3  8 10
1  0  0  1 16
9 12  7  1  2
  
Digite um comando: r
Operacao realizada com sucesso.
Digite um comando: t
 9  1  2  1  1  1 9
12  0  0  6  7  3 4
 7  0  3  3  5 10 5
 1  1  8 15  7  3 0
 2 16 10  2  9  2 8
  
Digite um comando: h
Operacao realizada com sucesso.
Digite um comando: t
 2 16 10  2  9  2 8
 1  1  8 15  7  3 0
 7  0  3  3  5 10 5
12  0  0  6  7  3 4
 9  1  2  1  1  1 9
  
Digite um comando: v
Operacao realizada com sucesso.
Digite um comando: t
8  2 9  2 10 16  2
0  3 7  15 8  1  1
5 10 5  3  3  0  7
4  3 7  6  0  0 12
9  1 1  1  2  1  9
  
Digite um comando: e
Digite o tamanho da janela: 3
Operacao realizada com sucesso.
Digite um comando: t
0 0 2 2 1 1 1
0 0 2 2 0 0 0
0 0 3 0 0 0 0
1 1 1 0 0 0 0
1 1 1 0 0 0 0
  
Digite um comando: c
Digite o nome do arquivo de entrada: entrada
Arquivo entrada.pgm carregado com sucesso.
Digite um comando: d
Digite o tamanho da janela: 3
Operacao realizada com sucesso.
Digite um comando: t
9  10 10 10  8
9  10 10 10  9
7  10 15 15 15
7   7 15 15 15
6   6 15 16 16
12 12 12 16 16
12 12 12 16 16
  
Digite um comando: c
Digite o nome do arquivo de entrada: entrada
Arquivo entrada.pgm carregado com sucesso.
Digite um comando: m
Digite o tamanho da janela: 3
Operacao realizada com sucesso.
Digite um comando: t
4 5 4 5  3
4 5 5 5  7
3 3 6 5  7
2 3 6 7  9
1 1 3 3 10
2 2 1 3  8
9 7 1 2  2
  
Digite um comando: c
Digite o nome do arquivo de entrada: entrada
Arquivo entrada.pgm carregado com sucesso.
Digite um comando: M
Digite o tamanho da janela: 3
Operacao realizada com sucesso.
Digite um comando: t
4 5 4 4 3
4 5 4 5 4
3 4 6 6 6
2 3 6 6 8
1 1 4 6 8
4 3 3 5 6
5 4 3 4 5
  
Digite um comando: x
Informe x superior: 1
Informe y superior: 3
Informe x inferior: 5
Informe y inferior: 5
Limites invalidos
Digite um comando: x
Informe x superior: 1
Informe y superior: 3
Informe x inferior: 4
Informe y inferior: 4
Operacao realizada com sucesso.
Digite um comando: t
5 4
6 6
6 8
6 8
  
Digite um comando: n
Operacao realizada com sucesso.
Digite um comando: t
250 251
249 249
249 247
249 247
  
Digite um comando: c
Digite o nome do arquivo de entrada: entrada
Arquivo entrada.pgm carregado com sucesso.
Digite um comando: 1
Digite o tamanho da janela: 3
Informe o valor de k: 1
Operacao realizada com sucesso.
Digite um comando: t
255 255 255 255 255
255 255 255 255 255
255 255 255 255 255
255 255 255 255 255
255 255 255 255 255
255 255 255 255 255
255 255 255 255 255
  
Digite um comando: c
Digite o nome do arquivo de entrada: entrada
Arquivo entrada.pgm carregado com sucesso.
Digite um comando: 2
Digite o tamanho da janela: 3
Informe o valor de k: 1
Operacao realizada com sucesso.
Digite um comando: t
255 255 255   0 255
  0 255 255 255 255
  0 255 255 255 255
255 255 255 255   0
255   0 255 255 255
255   0   0 255 255
255 255 255 255 255
  
Digite um comando: c
Digite o nome do arquivo de entrada: entrada
Arquivo entrada.pgm carregado com sucesso.
Digite um comando: 3
Digite o tamanho da janela: 3
Informe o valor de k: 1
Operacao realizada com sucesso.
Digite um comando: t
  0 255 255 255   0
255 255   0 255 255
255 255 255 255 255
255 255 255   0 255
255 255 255 255 255
255 255 255 255   0
255   0 255 255 255
  
</pre>
