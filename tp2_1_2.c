#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 20


int main(){

    int i;
    double vt[N], *punt; 
    srand(time(NULL));
    
    for(i = 0;i<N; i++){
        
        vt[i] = 1 + rand() % 100;
        printf( "\n%f \n",  vt[i] );
        
    }

    punt = vt;

    printf("\nPrint de separacion: \n");

    for (int j = 0; j < N; j++)
    {
        *(punt+j) = 1 + rand() % 100;
        printf( "\n%f \n",  *(punt+j) );
        punt++;
    }
    

    return 0;
}

