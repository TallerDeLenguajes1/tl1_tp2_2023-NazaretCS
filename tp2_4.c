#include<stdio.h>
#include<stdlib.h>
#include<time.h>


struct PC {
    int velocidadProc; //entre 1 y 3
    int anioFabr; // entre 2015 y 2023
    int cantNucleos; // 1 y 8                          [MAX-MIN]+MIN
    char *tipProc; // 
} typedef PC;

char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

void CargarDatos( PC *pComputadoras, int cant);
void PresentarPC( PC *pComputadoras, int cant);
void PcMasVieja(PC *pComputadora, int cant);
void PcMasRapida(PC *pComputadora, int cant) ;

int main(){

    
    PC computadoras[5], *pCompus, *pAux;

    pCompus = computadoras;
    pAux = pCompus;

    CargarDatos(pAux, 5);

    pAux = pCompus;
    PresentarPC(pAux, 5);

    pAux = pCompus;
    PcMasVieja(pAux, 5);

    pAux = pCompus;
    PcMasRapida(pAux, 5);

    return 0;
}

void CargarDatos( PC *pComputadoras, int cant){
    int NumProc;
    char *puntTipo ;
    puntTipo = tipos;

    srand(time(NULL));

    for (int i = 0; i < cant; i++)
    {
        pComputadoras->anioFabr =  rand() % 8 + 2015;       //Valores aleatoreos Formula: [MAX-MIN]+MIN
        pComputadoras->cantNucleos = rand() % 7 + 1;    
        pComputadoras->velocidadProc = rand() % 2 + 1;
        NumProc = rand() % 6;
        pComputadoras->tipProc = (puntTipo + (NumProc * 1 + 6));
        printf("\nTipo:  ");
        /* puts(pComputadoras->tipProc); */
        puntTipo = tipos;    
        pComputadoras++;   
    }
    
}



void PresentarPC( PC *pComputadoras, int cant){

    for (int i = 0; i < cant; i++)
    {
        printf("\nPresentacion de las computadoras:\nPC %i:\n   Anio de Fabricacion: %d\n   Cantidad de Nucleos: %d\n   Velocidad de Procesador: %d\n   Tipo de Procesador:", i+1, pComputadoras->anioFabr, pComputadoras->cantNucleos, pComputadoras->velocidadProc);
        puts(pComputadoras->tipProc);
        pComputadoras++;
    }
    
}

void PcMasVieja(PC *pComputadora, int cant) {
    PC *computer;
    computer = pComputadora;
    int masVieja = 2024, posicion;

    for (int i = 0; i < cant; i++)
    {
        if (masVieja > pComputadora->anioFabr)
        {
            masVieja = pComputadora->anioFabr;
            printf("Ma Vieja: %d", masVieja );
            posicion = i;
        }
        pComputadora++;
    }
    
    pComputadora = computer;
    printf("\n\n\n---   PC con mas Antiguedad   --- \n");
    printf("Velocidad de la computadora: %d \n",pComputadora[posicion].velocidadProc);
    printf("Anio de la computadora: %d \n", pComputadora[posicion].anioFabr);
    printf("Cantidad de Nucleos del procesador: %d \n", pComputadora[posicion].cantNucleos);
    printf("Tipo del Procesador: ");
    puts(pComputadora[posicion].tipProc);
}


void PcMasRapida(PC *pComputadora, int cant) {
    PC *computer;
    computer = pComputadora;
    int masRapida = 1, posicion;

    for (int i = 0; i < cant; i++)
    {
        if (masRapida < pComputadora->velocidadProc)
        {
            masRapida = pComputadora->velocidadProc;
            printf("Ma Rapida: %d", masRapida );
            posicion = i;
        }
        pComputadora++;
    }
    
    pComputadora = computer;
    printf("\n\n\n---   PC con mas Rapida   --- \n");
    printf("Velocidad de la computadora: %d \n",pComputadora[posicion].velocidadProc);
    printf("Anio de la computadora: %d \n", pComputadora[posicion].anioFabr);
    printf("Cantidad de Nucleos del procesador: %d \n", pComputadora[posicion].cantNucleos);
    printf("Tipo del Procesador: ");
    puts(pComputadora[posicion].tipProc);
}