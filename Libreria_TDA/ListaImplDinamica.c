#ifndef LISTA_H
#define LISTA_H

#include "ListaImplDinamica.h"
bool listaCrear(Lista* pl)
{
    pl->vec = malloc(8 * sizeof(int)); //memoria para 8 enteros (bytes)
    if(!pl->vec)
        return false;
    pl->ce=0;
    pl->cap=8;
    return true;
}
bool listaCrearRandom(Lista* pl, int ce)
{
    if(!listaCrear(pl))
        return false;

    srand(time(NULL));

    for(int i=0; i<ce;i++)
        ListaInsertarAlFinal(pl,rand());
    return true;
}
void ListaDestruir(Lista* pl) //--> debería ir siempre al final del programa, o donde ya no haga uso de la memoria reservada ListaDestruir(&l); //
{
    free(pl->vec);
}
void listaVaciar(Lista* pl) //Aunque es similar a listaCrear, se supone que hacen algo distinto, por lo que es mejor diferenciarlas
{
    pl->ce=0;
}
void estadoOperacion(int est)
{
    if(est==SIN_MEM)
        printf("\n Sin memoria disponible...");
    if(est==DUPLICADO)
        printf("\n Elemento duplicado...");
    if(est==TODO_OK)
        printf("\n Todo salio correctamente...");
}
int listaInsertarEnOrdAsc(Lista* pl, int elem) //aritmetica de punteros//
{
    if(pl->ce==CAP)
    {
        size_t nuevaCap = pl->cap * 2; //Amplia la capacidad del vector si está lleno
        int* nuevoVec = realloc(pl->vec, nuevaCap *sizeof(int)); //Se usan variables nuevas en caso de que falle el realloc y se pierda la direccion original

        if(nuevoVec == NULL)
            return SIN_MEM;
        pl->vec = nuevoVec;
        pl->cap = nuevaCap;
    }

    int* i=pl->vec;
    int* ult=pl->vec+pl->ce-1;

    while(i<=ult && elem>*i)
        i++;

    if(i<=ult && elem==*i)
        return DUPLICADO;

    for(int* j=ult;j>=i;j--)
        *(j+1)=*j;

    *i=elem;

    pl->ce++;
    return TODO_OK;
}
int listaInsertarEnOrdDesc(Lista* pl, int elem)
{
    if(pl->ce==CAP)
    {
        size_t nuevaCap = pl->cap * 2; //Amplia la capacidad del vector si está lleno
        int* nuevoVec = realloc(pl->vec, nuevaCap *sizeof(int)); //Se usan variables nuevas en caso de que falle el realloc y se pierda la direccion original

        if(nuevoVec == NULL)
            return SIN_MEM;
        pl->vec = nuevoVec;
        pl->cap = nuevaCap;
    }

    int* i=pl->vec;
    int* ult=pl->vec+pl->ce-1;

    while(i<=ult && elem<*i)
        i++;

    if(i<=ult && elem==*i)
        return DUPLICADO;

    for(int* j=ult;j>=i;j--)
        *(j+1)=*j;

    *i=elem;

    pl->ce++;
    return TODO_OK;
}
int ListaInsertarAlInicio(Lista* pl, int elem)
{
    if(pl->ce==CAP)
    {
        size_t nuevaCap = pl->cap * 2; //Amplia la capacidad del vector si está lleno
        int* nuevoVec = realloc(pl->vec, nuevaCap *sizeof(int)); //Se usan variables nuevas en caso de que falle el realloc y se pierda la direccion original

        if(nuevoVec == NULL)
            return SIN_MEM;
        pl->vec = nuevoVec;
        pl->cap = nuevaCap;
    }

    int* i=pl->vec;
    int* ult=pl->vec+pl->ce-1;

    if(i<=ult && elem==*i) // la parte i<=ult podría estar de más en este, puesto que solo tiene que pararse al inicio, y siempre i deberia ser menor o igual a ult
        return DUPLICADO;

    for(int* j=ult;j>=i;j--)
        *(j+1)=*j;

    *i=elem;
    pl->ce++;

    return TODO_OK;
}
int ListaInsertarAlFinal(Lista* pl, int elem)
{
    if(pl->ce==CAP)
    {
        size_t nuevaCap = pl->cap * 2; //Amplia la capacidad del vector si está lleno
        int* nuevoVec = realloc(pl->vec, nuevaCap *sizeof(int)); //Se usan variables nuevas en caso de que falle el realloc y se pierda la direccion original

        if(nuevoVec == NULL)
            return SIN_MEM;
        pl->vec = nuevoVec;
        pl->cap = nuevaCap;
    }

    int* ult=pl->vec+pl->ce;

    if(elem==*ult)
        return DUPLICADO;

    *ult=elem;
    pl->ce++;

    return TODO_OK;
}
int ListaInsertarEnPos(Lista* pl, int elem, int pos)
{
    if(pl->ce==CAP)
    {
        size_t nuevaCap = pl->cap * 2; //Amplia la capacidad del vector si está lleno
        int* nuevoVec = realloc(pl->vec, nuevaCap *sizeof(int)); //Se usan variables nuevas en caso de que falle el realloc y se pierda la direccion original

        if(nuevoVec == NULL)
            return SIN_MEM;
        pl->vec = nuevoVec;
        pl->cap = nuevaCap;
    }

    int* i=pl->vec+pos-1;
    int* ult=pl->vec+pl->ce-1;

    if(elem==*i)
        return DUPLICADO;

    for(int* j=ult;j>=i;j--)
        *(j+1)=*j;

    *i=elem;
    pl->ce++;

    return TODO_OK;

}
bool listaEliminarOrd(Lista* pl, int elem) //bool para indicar si se pudo o no eliminar//
{
    int* i = pl->vec;
    int* ult = pl->vec+pl->ce-1;
    while(i<=ult&&elem>*i)
        i++;
    if(i>ult || elem<*i)
        return false;
    for(int* j = i; j<ult;j++)
        *j=*(j+1);
    pl->ce--;
    if(pl->ce * 3 >= pl->cap)
    {
        pl->cap = max(pl->cap/2,8); // Hago que la redfinicion nunca baje de 8//
        pl->vec = realloc(pl->vec, pl->cap);
    }
    return true;
}
bool listaEliminarDesord(Lista* pl, int elem)
{
    int* i=pl->vec;
    int* ult=pl->vec+pl->ce-1;

    while(i<=ult && elem!=*i)
        i++;
    if(i==pl->vec+CAP)
        return false; //SALIO MAL//
    if(elem==*i)
        for(int* j=i;j<ult;j++)
            *j=*(j+1);

    pl->ce--;

    if(pl->ce * 3 <= pl->cap)
    {
        pl->cap = max(pl->cap/2,8); // Hago que la redfinicion nunca baje de 8//
        pl->vec = realloc(pl->vec, pl->cap);
    }
    return true; //SALIO BIEN//
}
/*bool listaBuscarOrd(const Lista* pl, int elem)
bool listaBuscarDesord(const Lista* pl, int elem)
void listaOrdenarAsc(Lista* pl)
void listaOrdenarDesc(Lista* pl)
void desplazarElemento(int* subVec,int* i)
int eliminarDuplicadosOrd(Lista* pl)
int eliminarDuplicadosDesord(Lista* pl)*/
void listaOrdenarAscAlt(Lista* pl, int metodo)
{
    switch(metodo){
        case 1:
            listaOrdenarAscBurbujeo(pl);
            break;
        case 2:
            listaOrdenarAscSeleccion(pl);
            break;
        case 3:
            listaOrdenarAscInsercion(pl);
            break;
    }
}
void listaOrdenarAscBurbujeo(Lista* pl)
{
    bool huboIntercambio = true;
    int i=1;

    while(huboIntercambio && i<pl->ce)
    {
        huboIntercambio = false;
        for(int j=0;j<pl->ce-i;j++)
        {
            if(pl->vec[j]>pl->vec[j+1])
            {
                intercambiar(&pl->vec[j],&pl->vec[j+1]);
                huboIntercambio = true;
            }
        }
        i++;
    }
}
void listaOrdenarAscSeleccion(Lista* pl)
{
    int* ult=pl->vec+pl->ce-1;
    int* m;
    for(int*i=pl->vec;i<ult;i++)
    {
        m = buscarMenor(i,ult);
        intercambiar(i,m);
    }

}
void listaOrdenarAscInsercion(Lista* pl)
{
    int* ult = pl->vec+pl->ce-1;
    int elemAInsertar;
    int* j;

    for(int* i=pl->vec+1;i<=ult;i++)
    {
        elemAInsertar=*i;
        j=i-1;
        while(j>=pl->vec && elemAInsertar<*j)
        {
            *(j+1)=*j;
            j--;
        }
        if(i!=j+1)
            *(j+1)=elemAInsertar;
    }
}
void listaOrdenarDescAlt(Lista* pl, int metodo)
{
    switch(metodo){
        case 1:
            listaOrdenarDescBurbujeo(pl);
            break;
        case 2:
            listaOrdenarDescSeleccion(pl);
            break;
        case 3:
            listaOrdenarDescInsercion(pl);
            break;
    }
}
void listaOrdenarDescBurbujeo(Lista* pl)
{
    bool huboIntercambio = true;
    int i=1;

    while(huboIntercambio && i<pl->ce)
    {
        huboIntercambio = false;
        for(int j=0;j<pl->ce-i;j++)
        {
            if(pl->vec[j]<pl->vec[j+1])
            {
                intercambiar(&pl->vec[j],&pl->vec[j+1]);
                huboIntercambio = true;
            }
        }
        i++;
    }
}
void listaOrdenarDescSeleccion(Lista* pl)
{
    int* ult=pl->vec+pl->ce-1;
    int* m;
    for(int*i=pl->vec;i<ult;i++)
    {
        m = buscarMayor(i,ult);
        if(i!=m)
            intercambiar(i,m);
    }

}
void listaOrdenarDescInsercion(Lista* pl)
{
    int* ult = pl->vec+pl->ce-1;
    int elemAInsertar;
    int* j;

    for(int* i=pl->vec+1;i<=ult;i++)
    {
        elemAInsertar=*i;
        j=i-1;
        while(j>=pl->vec && elemAInsertar>*j)
        {
            *(j+1)=*j;
            j--;
        }
        if(i!=j+1)
            *(j+1)=elemAInsertar;
    }
}
void intercambiar(int* a, int* b)
{
    int aTemp = *a;
    *a=*b;
    *b=aTemp;
}
int* buscarMenor(const int* ini, const int* fin)
{
    int* m = (int*)ini; //m antes inicializada como const ini*//

    for(int* j=(int*)ini+1;j<=fin;j++)
    {
        if(*j<*m)
            m = j;
    }

    return (int*)m;
}
int* buscarMayor(const int* ini, const int* fin)
{
    const int* m = ini;

    for(int* j=(int*)ini+1;j<=fin;j++)
    {
        if(*j>*m)
            m = j;
    }

    return (int*)m;
}
void listaMostrar(const Lista* pl)
{
    for(int i=0;i<pl->ce;i++)
    {
        printf("%d", pl->vec[i]);
        putchar('\n');
    }
}

#endif // LISTA_H
