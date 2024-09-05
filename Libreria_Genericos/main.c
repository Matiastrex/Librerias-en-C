#include "funcionesGenericas.h"

int main()
{
    int vec[]={3,1,16,1,80,99,2,5,7,10,13,17,4,67,87,54,56,34,89,98};
    int* busqueda;
    int clave = 98;
    char cad[][MAX_PAL]={"San Andres","Argentina","Manzanas","Si"};

    ordenamientoPorSeleccionDESC(vec,sizeof(vec)/sizeof(int),sizeof(int),cmpEnt);
    recorrerVector(vec,sizeof(vec)/sizeof(int),sizeof(int),mostrarEntero);

    puts("");

    ordenamientoPorSeleccionDESC(cad,sizeof(cad)/MAX_PAL,MAX_PAL,cmpStr);
    recorrerVector(cad,sizeof(cad)/MAX_PAL,MAX_PAL,mostrarPalabra);

    busqueda=busquedaBinariaDESC(&clave,vec,sizeof(vec)/sizeof(int),sizeof(int),cmpEnt);
    printf("Se encontro la clave %d en la direccion %p",*busqueda,busqueda);

    puts("");
    size_t ce = sizeof(vec)/sizeof(int);
    filtrarVector(vec,&ce,sizeof(int),filtrarPares);
    recorrerVector(vec,ce,sizeof(int),mostrarEntero);

    puts("");
    char pals[MAX_PAL]={""};
    char palResultado[MAX_PAL];
    strcpy(palResultado,(char*)reducirVector(cad,sizeof(cad)/MAX_PAL,MAX_PAL,concatenarCadenas,&pals));
    printf("%s",palResultado);

    int i;
    int* vector;
    vector=crearVector(40,sizeof(int));
    destruirVector(vector);






}
