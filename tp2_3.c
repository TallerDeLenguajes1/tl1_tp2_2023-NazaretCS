#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    
    #define N 5
    #define M 7

    int i,j, k, l;
    float mt[N][M], *puntM;


    srand(time(NULL));
    


    for(i = 0; i<N ; i++)
    {
        for(j = 0; j<M ; j++) {
            mt[i][j]=1+rand()%100;

            printf("%lf ", mt[i][j]);
        }

        printf("\n");
    }

    puntM = mt;
    printf("\n \n Print de separacion \n\n");

    for (l = 0; l < N; l++)
    {
        for ( k = 0; k < M; k++)
        {
            printf("%f ", *(puntM +(l * M + k)));
        }
        printf("\n");
    }
    
    return 0;
}