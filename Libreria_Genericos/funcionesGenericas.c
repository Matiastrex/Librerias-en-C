#include "funcionesGenericas.h"
#include <string.h>
void mostrarEntero(void* a)
{
    printf("%d ",*(int*)a);
}
void duplicarEntero(void* a)
{
    *((int*)a) = (*(int*)a)*2;
}
void mostrarPalabra(void* a)
{
    printf("%s ",(char*)a);
}
int cmpEnt(const void* a, const void* b)
{
    int* pa = (int*)a;
    int* pb = (int*)b;
    return *pa-*pb; //return *(int*)a-*(int*)b;
}
int cmpStr(const void* a, const void* b)
{
    return strlen(a)-strlen(b); //return *(int*)a-*(int*)b;
}
void* acumularEnteros(void*a,void*b)
{
    int* resultado = (int*)a;
    int* valor = (int*)b;
    *resultado += *valor;
    return resultado;
}
void* concatenarCadenas(void*a,void*b)
{
    char* resultado = (char*)a;
    char* valor = (char*)b;
    strcat(resultado,valor);
    return resultado;
}
void* crearVector(size_t tam_max,size_t tamElem)
{
    void* vec = malloc(tam_max*tamElem);
    if(vec==NULL)
    {
        return NULL;
    }
    return vec;
}
void destruirVector(void* vec)
{
    free(vec);
}

void* buscarMenor(const void* vec, size_t ce, size_t tam, int cmp(const void* a, const void* b))
{
    int i;
    void* min = (void*)vec;
    for(i=0;i<ce;i++)
    {
        if(cmp(min,vec)>0)
        {
            min=(void*)vec;
        }
        vec+=tam;
    }
    return min;
}
void* buscarMayor(const void* vec, size_t ce, size_t tam, int cmp(const void* a, const void* b))
{
    int i;
    void* max = (void*)vec;
    for(i=0;i<ce;i++)
    {
        if(cmp(max,vec)<0)
        {
            max=(void*)vec;
        }
        vec+=tam;
    }
    return max;
}
void intercambio(void* pa, void* pb, size_t tam)
{
    char auxVec[tam];
    memcpy(auxVec,pa,tam);
    memcpy(pa,pb,tam);
    memcpy(pb,auxVec,tam);
}
void memcpyPropio(void* dest, const void* origen, size_t tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        *((char*)dest) = *((char*)origen);
        dest++;
        origen++;
    }
}
int filtrarPares(const void* a)
{
    return(*((int*)a)%2==0);
}

void ordenamientoPorSeleccionASC(void* vec, size_t ce, size_t tam, int cmp(const void* a,const void* b))
{
    int i;
    void* min=vec;
    for(i=0;i<ce-1;i++)
    {
        min=buscarMenor(vec,ce-i,tam,cmp);
        if(min!=vec)
        {
            intercambio(min,vec,tam);
        }
        vec+=tam;
    }
}
void ordenamientoPorSeleccionDESC(void* vec, size_t ce, size_t tam, int cmp(const void* a,const void* b))
{
    int i;
    void* max=vec;
    for(i=0;i<ce-1;i++)
    {
        max=buscarMayor(vec,ce-i,tam,cmp);
        if(max!=vec)
        {
            intercambio(max,vec,tam);
        }
        vec+=tam;
    }
}
void* recorrerVector(void* vec, size_t ce, size_t tam,void accion(void*))
{
    int i;
    void* ini = vec;
    for(i=0;i<ce;i++)
    {
        accion(vec);
        vec+=tam;
    }
    return ini;
}
void* filtrarVector(void* vec, size_t* ce, size_t tam,int filtro(const void*))
{
    void* pe = vec;
    void* pl = vec;
    size_t ceTemp = *ce;
    int i;
    for(i=0;i<*ce;i++)
    {
        if(filtro(pl))
        {
            memcpy(pe,pl,tam);
            pe += tam;
        }
        else
        {
            ceTemp--;
        }
        pl += tam;
    }
    *ce = ceTemp;
    return vec;
}
void* reducirVector(void* vec, size_t ce, size_t tam,void* operacion(void*,void*),void* inicial)
{
    void* resultado=inicial;
    int i;
    for(i=0;i<ce;i++)
    {
        resultado = operacion(resultado,vec);
        vec += tam;
    }
    return resultado;
}
void* busquedaBinariaASC(const void* key, const void* vec,size_t ce, size_t tam,int cmp(const void *, const void *))
{
    void* ini = (void*)vec;
    void* fin = (void*)vec + (ce-1)*tam;
    void* mid;

    while(ini<=fin)
    {
        mid = ini + (((fin-ini)/tam)/2)*tam;

        if(cmp(key,mid)==0)
            return mid;

        if(cmp(key,mid)<0)
            fin=mid-tam;
        else
            ini=mid+tam;
    }
    return NULL;
}
void* busquedaBinariaDESC(const void* key, const void* vec,size_t ce, size_t tam,int cmp(const void *, const void *))
{
    void* ini = (void*)vec;
    void* fin = (void*)vec + ce*tam;
    void* mid;

    while(ini<=fin)
    {
        mid = ini + ((fin-ini)/tam)/2*tam;

        if(cmp(key,mid)==0)
            return mid;

        if(cmp(key,mid)<0)
            ini=mid+tam;
        else
            fin=mid-tam;
    }
    return NULL;
}

