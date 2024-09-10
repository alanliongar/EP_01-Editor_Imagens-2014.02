//AO PREENCHER ESSE CABEÇALHO COM O MEU NOME E O MEU NÚMERO USP,
//DECLARO QUE SOU O ÚNICO AUTOR E RESPONSÁVEL POR ESSE PROGRAMA.
//Nome: Alan Lucindo Gomes
//NUSP: 7572130
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct ImagemRGB{
int **R;
int **G;
int **B;
int m;
int n;
};typedef struct ImagemRGB *RGB;

struct Descritor{
char filename[512];
float *hist;
struct Descritor *prox;
};typedef struct Descritor *ListaDescritores;

struct Ranking{
char filename[512];
float dist;
struct Ranking *prox;
};typedef struct Ranking *ListaRanking;

int **AlocaMatriz(int m, int n){
int **p,i;
p=(int **)malloc(m*sizeof(int *));
for(i=0;i<m;i++)
    p[i]=(int *)malloc(3*n*sizeof(int));
return p;
}

void LiberaMatriz(int **M, int m){
    int i;
        for(i=0;i<m;i++)
        free(M[i]);
        free(M);
}

struct ImagemRGB *AlocaImagemRGB(int m, int n){
struct ImagemRGB *imagem;
int **R,**G,**B,i;

R=(int **)malloc(m*sizeof(int *));
for(i=0;i<m;i++)
    R[i]=(int *)malloc(n*sizeof(int));

//return R;
G=(int **)malloc(m*sizeof(int *));
for(i=0;i<m;i++)
    G[i]=(int *)malloc(n*sizeof(int));

B=(int **)malloc(m*sizeof(int *));
for(i=0;i<m;i++)
    B[i]=(int *)malloc(n*sizeof(int));

imagem->R=R;
imagem->G=G;
imagem->B=B;
return imagem;
}

void LiberaImagemRGB(struct ImagemRGB *I){
    int i;
        for(i=0;i<(I->m);i++)
        free(I->R[i]);
        free(I->R);
        for(i=0;i<(I->m);i++)
        free(I->G[i]);
        free(I->G);
        for(i=0;i<(I->m);i++)
        free(I->G[i]);
        free(I->G);
}

struct ImagemRGB *AbreImagemRGB(char filename[]){
struct ImagemRGB *imagem;
int m,n,i,j,cormax;
char pd[3];
FILE *arquivo;
arquivo=fopen(filename, "r");
fscanf("%c %c %c\n",&pd[0],&pd[1],&pd[2]);
fscanf("%d %d\n",&m,&n,&cormax);
imagem=AlocaImagemRGB(m,n);
for(i=0;i<n;i++){
for(j=0;j<m;j++){
fscanf("%d", imagem->R[i][j]);
fscanf("%d", imagem->G[i][j]);
fscanf("%d", imagem->B[i][j]);
}}
imagem->m=m;
imagem->n=n;
fclose(arquivo);
return imagem;
}

float *HistogramaCores(struct ImagemRGB *I){
float *c,a,b,d;
int k,m,n,o,i,j;
m=I->m;
n=I->n;
o=m*n;
c=(float *)malloc(64*sizeof(float));
for(k=0;k<64;k++){
c[k]=0;
}

for(i=0;i<n;i++){
for(j=0;j<m;j++){
if(((float)I->R[i][j]/64)<1)
    a=0;
if(((float)I->R[i][j]/64)>=1 && ((float)I->R[i][j]/64)<2)
    a=1;
if(((float)I->R[i][j]/64)>=2 && ((float)I->R[i][j]/64)<3)
    a=2;
if(((float)I->R[i][j]/64)>3)
    a=3;

if(((float)I->G[i][j]/64)<1)
    b=0;
if(((float)I->G[i][j]/64)>=1 && ((float)I->R[i][j]/64)<2)
    b=1;
if(((float)I->G[i][j]/64)>=2 && ((float)I->R[i][j]/64)<3)
    b=2;
if(((float)I->G[i][j]/64)>3)
    b=3;

if(((float)I->B[i][j]/64)<1)
    d=0;
if(((float)I->B[i][j]/64)>=1 && ((float)I->R[i][j]/64)<2)
    d=1;
if(((float)I->B[i][j]/64)>=2 && ((float)I->R[i][j]/64)<3)
    d=2;
if(((float)I->B[i][j]/64)>3)
    d=3;

k=a+4*b+16*d;
c[k]=c[k]+1;

}}
for(k=0;k<64;k++)
    c[k]=c[k]/o;

return c;
}

float DistanciaHistogramas(float *hist1, float *hist2){
float a,b,c;
int k;
a=0;
for(k=0;k<64;k++){
b=0;
b=(hist1[k]-hist2[k])*(hist1[k]-hist2[k]);
a=b+a;
}
c=pow(a,0.5);
return c;
}

void LiberaDescritores(ListaDescritores L){
//LiberaDescritores P;
while(L->filename[0]!='\0' && L->filename[0]!='\n'){
//P=L->prox;
free(L);
L=L->prox;
}
L=L->prox;
free(L);
}

void LiberaRanking(ListaRanking L){
//LiberaRanking P;
while(L->filename[0]!='\0' && L->filename[0]!='\n'){
//P=L->prox;
free(L);
L=L->prox;
}
free(L);
L=L->prox;
free(L);
}

ListaRanking InsereNoRanking(ListaRanking R, float d, char filename[]){
ListaRanking P, A, B;
P=(ListaRanking *)malloc(sizeof(ListaRanking));
P->dist=d;
strcpy(P->filename, filename);
A=R;
B=R->prox;
while(d > B->dist){
A=B;
B=B->prox;
}
P->prox=B;
A->prox=P;
return R;
}

int main(){
    char nomearquivo[200],pd[3],pz[3];
    float *c,distans,*d;
    int **M,m,n,max,zmax,aa,bb,i,j;
    ListaDescritores imagens;
    ListaDescritores p;
    RGB o,O;
    ListaRanking A,R;
    imagens=(ListaDescritores)malloc(sizeof(ListaDescritores));
    printf("Digite o nome do arquivo texto, incluindo a extensao:");
    fgets(nomearquivo, 200, stdin);
    printf("\n\na\n\n");
    //printf("%s", nomearquivo);
    //sprintf(imagens->filename,nomearquivo); biblioteca string.h
    FILE *arquivo,*sarq,*zarq;
    arquivo=fopen(nomearquivo, "r");
    p=imagens;
    while(1){
    fgets(imagens->filename,sizeof(imagens->filename),arquivo);
    if(imagens->filename[0]=='\n' || imagens->filename[0]=='\0'){
    break;
    }
    //printf("%s",imagens->filename);
    imagens->prox=(ListaDescritores)malloc(sizeof(ListaDescritores));
    imagens=imagens->prox;
    }
    imagens->prox=p;//'circulando' a lista;
    printf("\n Agora digite o nome do arquivo a buscar: ");
    fgets(nomearquivo,200,stdin); //scanf("%s", &nome2);
    zarq=fopen(nomearquivo,"r");
    fgets(pz[0],3,zarq);
    fscanf(zarq,"%d %d\n%d\n", &aa, &bb, &zmax);
    O=AlocaImagemRGB(bb,aa);
    O->n=bb;
    O->m=aa;
    for(i=0;i<bb;i++){
    for(j=0;j<3*aa;j++){
    if(j%3==0){fscanf(zarq,"%d", &(O->R[i][j]));}
    if(j%3==1){fscanf(zarq,"%d", &(O->G[i][j]));}
    if(j%3==2){fscanf(zarq,"%d", &(O->B[i][j]));}
    }
    }
    d=HistogramaCores(O);
    while(1){
    if(imagens->filename[0]=='\n' || imagens->filename[0]=='\0'){
    break;
    }
    sarq=fopen(imagens->filename, "r");
    fgets(pd[0],3,sarq);
    fscanf(sarq,"%d %d\n%d\n", &m,&n,&max);
    M=AlocaMatriz(3*n,m);
    LiberaMatriz(M,3*n);

    //carregar cada um dos arquivos da lista na memória, calcular suas distancias e imprimir seus nomes e distancias;
    o=AlocaImagemRGB(n,m);
    o->n=n;
    o->m=m;
for(i=0;i<n;i++){
for(j=0;j<3*m;j++){
if(j%3==0){fscanf(sarq,"%d", &(o->R[i][j]));}
if(j%3==1){fscanf(sarq,"%d", &(o->G[i][j]));}
if(j%3==2){fscanf(sarq,"%d", &(o->B[i][j]));}
}
}
c=HistogramaCores(o);
distans=DistanciaHistogramas(c,d);
A=InsereNoRanking(R,distans,imagens->filename);
LiberaImagemRGB(o);
fclose(sarq);
imagens=imagens->prox;
}
while(1){
    if(R->filename[0]=='\n' || R->filename[0]=='\0'){
    break;
    printf("%s, %f", R->filename, R->dist);
}
}
LiberaDescritores(imagens);
LiberaRanking(R);
fclose(arquivo);
return 0;
}
