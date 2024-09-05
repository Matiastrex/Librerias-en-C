#include "cadenas.h"
size_t miStrlen (const char* cad)
{
    size_t tam = 0;
    while(*cad)
    {
        tam++;
        cad++;
    }
    return tam;
}

int miStrcmp (const char* a, const char* b)
{

    while(*a && *b && *a==*b)
    {
        a++;
        b++;
    }
    if(!*a&&!*b)
    {
        return 0;
    }
    if(*a>*b)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
int miStrcmpi (const char* a, const char* b)
{

    while(*a && *b && AMAYUSCULA(*a)==AMAYUSCULA(*b))
    {
        a++;
        b++;
    }
    if(!*a&&!*b)
    {
        return 0;
    }
    if(AMAYUSCULA(*a)>AMAYUSCULA(*b))
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
void invertirCadena (char* cad)
{
    char aux;
    char* fin = cad + miStrlen(cad)-1;
    while(cad<fin)
    {
        aux=*fin;
        *fin=*cad;
        *cad=aux;
        cad++;
        fin--;
    }
}
int esPalindromo (const char* cad)
{
    char* fin = (char*)(cad + miStrlen(cad)-1);
    while(cad<fin)
    {
        while(!(ESLETRA(*cad)))
        {
            cad++;
        }
        while(!(ESLETRA(*fin)))
        {
            fin--;
        }
        if((AMAYUSCULA(*cad))!=(AMAYUSCULA(*fin)))
        {
            return 1;
        }
        cad++;
        fin--;
    }
    return 0;
}
int proximaPalabra(char* cad,char** ini,char** fin)
{
    int ce = 0;

    while(*cad&&!(ESALFANUM(*cad)))
    {
        cad++;
    }
    if(!*cad)
    {
        *ini = NULL;
        *fin = NULL;
        return ce;
    }
    *ini=cad;
    while(*cad&&(ESALFANUM(*cad)))
    {
        cad++;
        ce++;
    }
    *fin=cad;
    return ce;
}
void mostrarPalabra(char* cad,char* fin)
{
    while(*cad&&cad<fin)
    {
        printf("%c",*cad);
        cad++;
    }
    printf(" ");
}
void desofuscarPalabra(char* cad)
{
    char* ini;
    char* fin;
    int i=1;
    int ce;
    char grupo[]="abcdghijkoqtuv";

    ce=proximaPalabra(cad,&ini,&fin);
    while(ce)
    {
        while(i<=ce)
        {
            desplazamiento(ini,i,grupo);
            ini++;
            i++;
        }
        i=1;
        ce=proximaPalabra(fin,&ini,&fin);
    }
}
void desplazamiento(char* c, int pos, const char* grupo)
{
    int tamGrupo = strlen(grupo);
    char* ubi;
    if(!(ubi=(strchr(grupo,*c))))
    {
        return;
    }
    int dist=ubi-grupo;
    *c=*(grupo+(dist+pos)%tamGrupo);
}

/*void cifradoCesar(char* cad,int clave)
{
    char* ini, fin;

    proximaPalabra(cad, &ini, &fin)
    while(ini!=NULL)
    {

        proximaPalabra(fin, &ini, &fin)
    }
}*/
