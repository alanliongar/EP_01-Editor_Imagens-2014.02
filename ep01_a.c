#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int **AlocaMatriz(int m, int n);
void LiberaMatriz(int** M, int m, int n);
int **AbreImagem(char filename[], int* m, int* n);
void GravaImagem(char filename[], int** M, int m, int n);
void negativo(int** M, int m, int n);
void rebatimentoVertical(int** M, int m, int n);
void rebatimentoHorizontal(int** M, int m, int n);
int **rotacao(int **M, int* m, int* n);
int** corte(int** M, int* m, int* n, int xsup, int ysup, int xinf, int yinf);
void filtroMediana(int** M, int m, int n, int larguraJanela);
void filtroMedia(int** M, int m, int n, int larguraJanela);
void filtroErosao(int** M, int m, int n, int larguraJanela);
void filtroDilatacao(int** M, int m, int n, int larguraJanela);
void limiarizacao(int** M, int m, int n, int k);
void filtroBorda1(int** M, int m, int n, int larguraJanela, int k);
void filtroBorda2(int** M, int m, int n, int larguraJanela, int k);
void filtroBorda3(int** M, int m, int n, int larguraJanela, int k);
int calculamediana(int **M, int larguraJanela, int i, int j,int m, int n);
int main();

int main(){
    int a,c,i,j,LIM=100,**p
    char filename[LIM],b;
    cl=1;
    cc=0;
    b='Z';
    FILE *file;
    while(1){
    printf("Digite o nome do arquivo de entrada:\n");
    if(b=='Z'||b=='c'){
    while(1){
    fgets(filename,LIM,stdin);
    filename[strlen(filename)-1]='\0';
    for(i=0;i<100;i++){
        if(filename[i]=='\0'){
            filename[i]='.';filename[i+1]='p';filename[i+2]='g';filename[i+3]='m';filename[i+4]='\0';break;}};
        file=fopen(filename,"r");
        if(file==NULL)){
            printf("Problema! O arquivo %s nao existe! Digite um nome de arquivo de entrada valido:\n", filename);
            }
        else if(file!=NULL){
            p=AbreImagem(filename[], &cc, &cl);
        }
            printf("c - carga\nt - exibicao na tela\nn - negativo\nr - rotacao\nv - espelhamento vertical\nh - espelhamento horizontal\nx - corte\ne - filtro da erosao\nd - filtro da dilatacao\nm - filtro da mediana\nM - filtro da media\n1 - filtro de bordas 1\n2 - filtro de bordas 2\n3 - filtro de bordas 3\ng - gravacao\nC - comparacao\na - ajuda\ns - sair\n");
            scanf("%c%*c", &b);//tirando o \n do final só pra não ter problema de releitura do arquivo....
        if(b=='c'){
            LiberaMatriz(p,cc,cl);
            break;
        }
        if(b=='t'){
                printf("\n");
        for(i=0;i<cl;i++){
                for(j=0;j<cc;j++){
            printf("%3d", p[i][j]);
            }
            printf("\n");
            }
        }
        }
        if(b=='n'){
        negativo(p, cc, cl);//como mandar apontador duplo como parametro?
        }
        if(b=='r'){}
        if(b=='v'){}
        if(b=='h'){}
        if(b=='x'){}
        if(b=='e'){}
        if(b=='d'){}
        if(b=='m'){}
        if(b=='M'){}
        if(b=='1'){}
        if(b=='2'){}
        if(b=='3'){}
        if(b=='g'){}
        if(b=='C'){}
        if(b=='a'){}
        if(b=='s'){}
        }
        }


/*        while((fscanf(file,"%d",&a))!=EOF){
        fscanf(file,"%c",&b);
        if(b=='\n'||b=='\0')
            cl++;
            }
            fclose(file);
            file=fopen(filename,"r");
            while((fscanf(file,"%c",&b))!=EOF){
        fscanf(file,"%d",&a);
        cc++;
            }*/
            fclose(file);
    printf("%d %d %d", cc, cl, cormax);
    return 0;
}


int **AlocaMatriz(int m, int n){
int **p,i;
p=(int **)malloc(m*sizeof(int *));
for(i=0;i<m;i++)
    p[i]=(int *)malloc(n*sizeof(int));
return p;
}

void LiberaMatriz(int **M, int m, int n){
    int i;
        for(i=0;i<m;i++)
        free(M[i]);
        free(M);
}

int **AbreImagem(char filename[], int *m, int *n){
    int i,j,cormax,**p;
    char pd[2];
            for(i=0;i<3;i++){
            fscanf(file,"%c",&pd[i]);
            if(pd[0]=='P' && pd[1]=='2' && pd[2]=='\n'){
            fscanf(file,"%d %d %d",&m,&n,&cormax);
            p = AlocaMatriz(n, m);
            for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                fscanf(file,"%d",&p[i][j]);
                }}
        }
            printf("\nArquivo %s carregado com sucesso.\n", filename);
}
return p;
}

void GravaImagem(char filename[], int **M, int m, int n){

}

void negativo(int **M, int m, int n){
    int a, i, j;
for(i=0;i<n;i++){
    for(j=0;j<m;j++){
    a=M[i][j];
    M[i][j]=(255-a)
    }
}
}

void rebatimentoVertical(int **M, int m, int n){
int i,j,a;
for(i=0;i<n/2;i++){
    for(j=0;j<m;j++){
    a=M[i][j];
    M[i][j]=M[n-i][j];
    M[n-i][j]=a;
}}
}

void rebatimentoHorizontal(int** M, int m, int n){
int i,j,a;
for(i=0;i<n;i++){
    for(j=0;j<m/2;j++){
    a=M[i][j];
    M[i][j]=M[i][m-j];
    M[i][m-j]=a;
}}
}

int **rotacao(int **M, int *m, int *n){
int **R;
R=AlocaMatriz(n,m);
for(i=0;i<n;i++){
   for(j=0;j<m;j++){
        R[j][n-1-i]=M[i][j];
}
}
for(i=0;i<m;i++){
   for(j=0;j<n;j++){
        R[i][j]=M[i][j];
}
}
LiberaMatriz(R,n,m);
}

int **corte(int **M, int *m, int *n, int xsup, int ysup, int xinf, int yinf){
int a,b,**C,i,j;
a=(ysup-yinf);
b=(xinf-xsup);
/*Alocar matriz completa a.b*/
C=AlocaMatriz(a,b);
    for(i=ysup;i<a;i++){
        for(j=xsup;j<b;j++)
        C[i][j]=M[i][j];
    }
LiberaMatriz(M,m,n);
return C;
}

void filtroMediana(int **M, int m, int n, int larguraJanela){
int a,i,j,c;
b=(larguraJanela*larguraJanela);
a=b%2;
for(i=0;i<n;i++){
    for(j=0;j<m;j++){
        c=M[i]{j};
        M[i][j]=calculamediana(M,larguraJanela,i,j,m,n);
    }

}

if (a==1){

}
if(a==0){

}
}

void filtroMedia(int** M, int m, int n, int larguraJanela){

}

void filtroErosao(int** M, int m, int n, int larguraJanela){

}

void filtroDilatacao(int** M, int m, int n, int larguraJanela){

}

void limiarizacao(int** M, int m, int n, int k){

}

void filtroBorda1(int** M, int m, int n, int larguraJanela, int k){

}

void filtroBorda2(int** M, int m, int n, int larguraJanela, int k){

}

void filtroBorda3(int** M, int m, int n, int larguraJanela, int k){

}

int medianaimpar(int **M, int m, int n, int larguraJanela, int k){
int b,c,*p;
b=((k-1)/2);
c=k*k;
p=(int *)malloc(c*sizeof(int));
for(i=0;i<n;i++){
    for(j=0;j<m;j++){
        p[k*i+j]=M[i][j];
    }
}




}


int calculamediana(int **M, int larguraJanela, int i, int j);{
int k,b,c,*p;
k
b=((k-1)/2);
c=larguraJanela*larguraJanela;
p=(int *)malloc(c*sizeof(int));


}
