#include <stdio.h>
#include <stdlib.h>
#include "cadenas.h"
#define TAM 10
#define TAM_GRANDE 90

int main()
{
    /*
    char cad1[TAM_GRANDE]="  Anita   - Lava33 La ti,,,na  ";
    char cad2[TAM_GRANDE]="a mama.. Roma ++<<le av,,iva el amor222 a ma  ma  ";
    char cad3[TAM_GRANDE]="##Un   DIA()ME  ENCONTRE$#$/(#$UN#PERRO//";

    char* ptr1;
    char* ptr2;
    int result1=ESALFANUM('a');
    int result2=ESALFANUM('0');
    int result3=ESALFANUM('x');
    int result4=ESALFANUM('S');
    int result5=ESALFANUM('¬');
    int result6=ESALFANUM('@');
    int result7=ESALFANUM(' ');
    int cant = proximaPalabra(cad2,&ptr1,&ptr2);
    while(ptr1!=NULL)
    {
        mostrarPalabra(ptr1,ptr2);
        proximaPalabra(ptr2,&ptr1,&ptr2);
    }
    */

    char cad4[TAM_GRANDE]="Nj  --,  qemh v ljs  kraenkqbres; lj oqe qemh es oqevorme sgn ellhs --lstqt Asdmgj";
    desofuscarPalabra(cad4);
    printf("%s",cad4);

}

