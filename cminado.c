
/*Faça um programa em linguagem C que leia uma matriz Campo[9][9] de inteiros contendo 1 para representar posições com minas e 0 para representar posições
 que não estão minadas. Após o programa deverá gerar uma matriz Minas[9][9] de inteiros contendo, 
 para cada posição que não contém minas, o número de minas existentes nas posições adjacentes (considerar as oito posições adjacentes).  
 As posições que contém minas deverão receber o valor -1.*/

 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 
 #define N 9

 int modifica(int m[N][N], int a, int b)
 {
    int i,j;
    int soma;

    soma=0;
    for(i=a-1;i<=a+1;i++)
    {
        for(j=b-1;j<=b+1;j++)
        {
            if(i>=0 && j>=0 && j<N && i<N) soma+=m[i][j];
        }
    }
    return soma;
 }

 void mostra(int m[N][N])
 {
    int i,j;

    printf("\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("% 2d  ",m[i][j]);
        }
        printf("\n");
    }
 }

 int main()
 {
    int i,j;
    int Campo[N][N];
    int Cmina[N][N]={0,0,1,0,0,0,0,0,0,
                     0,1,0,0,0,0,1,1,0,
                     1,0,0,0,0,0,1,0,0,
                     0,0,0,0,0,0,0,0,0,
                     0,1,0,0,0,0,0,0,0,
                     0,0,0,0,0,0,1,0,0,
                     1,0,0,0,0,0,0,0,0,
                     0,0,0,0,1,0,0,0,0,
                     1,0,0,0,0,0,0,0,0};


    mostra(Cmina);
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(Cmina[i][j]!=1) Campo[i][j]=modifica(Cmina,i,j);
            else Campo[i][j]=-1;
        }
    }
    mostra(Campo);
    
 }
