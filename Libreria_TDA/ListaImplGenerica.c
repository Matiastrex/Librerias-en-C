#include "ListaImplGenerica.h"
bool listaCrear(Lista* pl, size_t tamElem) //necesario el tamElem pese a estar en pl porque todavia no fue inicializado
{
    pl->vec = malloc(8*tamElem);
    if(!pl->vec)
        return false;
    pl->ce=0;
    pl->cap=8;
    pl->tamElem=tamElem;

    return true;
}
void ListaDestruir(Lista* pl)
{
    free(pl->vec);
}
void listaVaciar(Lista* pl)
{
    pl->ce=0;
}
void listaRecorrer(Lista* pl, Accion accion, void* extra)
{
    void* ult = pl->vec+(pl->ce-1)*pl->tamElem;
    for(void*i = pl->vec;i<=ult;i+=pl->tamElem )
    {
        accion(i,extra);
    }
}
int listaInsertarEnOrdAsc(Lista* pl, void* elem, Cmp cmp)
{
    if(pl->ce==pl->cap)
    {
        size_t nuevaCap = pl->cap * 2;
        void* nuevoVec = realloc(pl->vec, nuevaCap * pl->tamElem); //Se usan variables nuevas en caso de que falle el realloc y se pierda la direccion original

        if(nuevoVec == NULL)
            return SIN_MEM;
        pl->vec = nuevoVec;
        pl->cap = nuevaCap;
    }

    void* i=pl->vec;
    void* ult=pl->vec+(pl->ce-1)*pl->tamElem;

    while(i<=ult && cmp(elem,i)>0)
        i+=pl->tamElem;

    if(i<=ult && cmp(elem,i)==0)
        return DUPLICADO;

    for(void* j=ult;j>=i;j-=pl->tamElem)
        memcpy(j+pl->tamElem,j,pl->tamElem);

    memcpy(i,elem,pl->tamElem);

    pl->ce++;
    return TODO_OK;
}
int listaInsertarEnOrdDesc(Lista* pl, void* elem, Cmp cmp)
{
    if(pl->ce==pl->cap)
    {
        size_t nuevaCap = pl->cap * 2;
        void* nuevoVec = realloc(pl->vec, nuevaCap * pl->tamElem); //Se usan variables nuevas en caso de que falle el realloc y se pierda la direccion original

        if(nuevoVec == NULL)
            return SIN_MEM;
        pl->vec = nuevoVec;
        pl->cap = nuevaCap;
    }

    void* i=pl->vec;
    void* ult=pl->vec+(pl->ce-1)*pl->tamElem;

    while(i<=ult && cmp(elem,i)<0)
        i+=pl->tamElem;

    if(i<=ult && cmp(elem,i)==0)
        return DUPLICADO;

    for(void* j=ult;j>=i;j-=pl->tamElem)
        memcpy(j+pl->tamElem,j,pl->tamElem);

    memcpy(i,elem,pl->tamElem);

    pl->ce++;
    return TODO_OK;
}
int ListaInsertarAlInicio(Lista* pl, void* elem, Cmp cmp)
{
    if(pl->ce==pl->cap)
    {
        size_t nuevaCap = pl->cap * 2;
        void* nuevoVec = realloc(pl->vec,nuevaCap*pl->tamElem);

        if(nuevoVec==NULL)
            return SIN_MEM;
        pl->vec = nuevoVec;
        pl->cap = nuevaCap;
    }
    if(cmp(elem,pl->vec)==0)
        return DUPLICADO;

    memmove(pl->vec+pl->tamElem,pl->vec,pl->tamElem*pl->ce);
    memcpy(pl->vec,elem,pl->tamElem);
    pl->ce++;
    return TODO_OK;
}
int ListaInsertarAlFinal(Lista* pl, void* elem, Cmp cmp)
{
    if(pl->ce==pl->cap)
    {
        size_t nuevaCap = pl->cap * 2;
        void* nuevoVec = realloc(pl->vec,nuevaCap*pl->tamElem);

        if(nuevoVec==NULL)
            return SIN_MEM;
        pl->vec = nuevoVec;
        pl->cap = nuevaCap;
    }
    if(cmp(elem,pl->vec+(pl->ce-1)*pl->tamElem)==0)
        return DUPLICADO;

    memcpy(pl->vec+(pl->ce)*pl->tamElem,elem,pl->tamElem);
    pl->ce++;
    return TODO_OK;
}
int ListaInsertarEnPos(Lista* pl, void* elem, int pos, Cmp cmp)
{
    if(pl->ce==pl->cap)
    {
        size_t nuevaCap = pl->cap * 2;
        void* nuevoVec = realloc(pl->vec,nuevaCap*pl->tamElem);

        if(nuevoVec==NULL)
            return SIN_MEM;
        pl->vec = nuevoVec;
        pl->cap = nuevaCap;
    }
    if(pos>pl->ce+1)
        return FUERA_RANGO;
    void* vecPos = pl->vec+(pl->tamElem*pos)-pl->tamElem;
    if(cmp(elem,vecPos)==0)
        return DUPLICADO;
    memmove(vecPos+pl->tamElem,vecPos,pl->tamElem*(pl->ce-pos+1));
    memcpy(vecPos,elem,pl->tamElem);
    pl->ce++;
    return TODO_OK;
}
bool listaEliminarOrd(Lista* pl, void* elem, Cmp cmp)
{
    void* i = pl->vec;
    void* ult = pl->vec+pl->tamElem*(pl->ce-1);

    while(i<=ult&&cmp(elem,i)>0)
        i+=pl->tamElem;
    if(i>ult || cmp(elem,i)<0)
        return false;

    for(void*j=i;j<ult;j+=pl->tamElem)
        memcpy(j,j+pl->tamElem,pl->tamElem);

    pl->ce--;

    if(pl->ce * 3 <= pl->cap)
    {
        pl->cap = max(pl->cap/2,8); // Hago que la redefinicion nunca baje de 8//
        pl->vec = realloc(pl->vec, pl->cap*pl->tamElem);
    }
    return true;
}
bool listaEliminarDesord(Lista* pl, void* elem,Cmp cmp)
{
    void* i = pl->vec;
    void* ult = pl->vec+(pl->ce-1)*pl->tamElem;
    int pos=1; // Para saber luego cuánto correr el vector

    while(i<=ult&&cmp(elem,i)!=0)
    {
        i+=pl->tamElem;
        pos++;
    }
    if(i==ult+pl->tamElem)
        return false;
    if(i==ult)
    {
        pl->ce--;
        return true;
    }

    memmove(i,i+pl->tamElem,(pl->ce-pos+1)*pl->tamElem);
    pl->ce--;

    if(pl->ce * 3 <= pl->cap)
    {
        pl->cap = max(pl->cap/2,8); // Hago que la redefinicion nunca baje de 8//
        pl->vec = realloc(pl->vec, pl->cap*pl->tamElem);
    }
    return true;

}
void* listaBuscarOrdAsc(const Lista* pl, void* elem, Cmp cmp)
{
    void* i = pl->vec;
    void* ult = pl->vec+(pl->ce-1)*pl->tamElem;

    if(cmp(elem,ult)>0)
        return NULL;

    while(i<ult&&cmp(elem,i)!=0)
        i+=pl->tamElem;
    if(cmp(elem,i)!=0)
        return NULL;

    return i;
}
void* listaBuscarOrdDesc(const Lista* pl, void* elem, Cmp cmp)
{
    void* i = pl->vec;
    void* ult = pl->vec+(pl->ce-1)*pl->tamElem;

    if(cmp(elem,i)>0)
        return NULL;

    while(i<ult&&cmp(elem,i)!=0)
        i+=pl->tamElem;
    if(cmp(elem,i)!=0)
        return NULL;

    return i;
}
void* listaBuscarDesord(const Lista* pl, void* elem, Cmp cmp)
{
    void* i = pl->vec;
    void* ult = pl->vec+(pl->ce-1)*pl->tamElem;

    while(i<=ult && cmp(elem,i)!=0)
        i+=pl->tamElem;
    if(i==ult+pl->tamElem)
        return NULL;
    else
        return i;
}
int obtenerPosicionElem(const Lista* pl, void* elem, Cmp cmp)
{
    void* i = pl->vec;
    void* ult = pl->vec+(pl->ce-1)*pl->tamElem;
    int pos=1;

    while(i<=ult && cmp(elem,i)!=0)
    {
        i+=pl->tamElem;
        pos++;
    }
    if(i==ult+pl->tamElem)
        return -1;
    else
        return pos;
}
int cantidadDeRepeticionesElem(const Lista* pl, void* elem, Cmp cmp)
{
    void* i = listaBuscarDesord(pl,elem,cmp)+pl->tamElem;
    void* ult = pl->vec+(pl->ce-1)*pl->tamElem;
    int rep=0;

    while(i<=ult)
    {
        if(cmp(elem,i)==0)
            rep++;
        i+=pl->tamElem;
    }
    return rep;
}
int eliminarDuplicadosOrdAsc(Lista* pl, void* elem, Cmp cmp)
{
    void* ult = pl->vec+(pl->ce-1)*pl->tamElem;
    if(cmp(elem,ult)>0)
        return 0;

    int rep=cantidadDeRepeticionesElem(pl,elem,cmp);
    if(rep==0)
        return 0;

    void* i = listaBuscarOrdAsc(pl,elem,cmp)+pl->tamElem;
    int pos = obtenerPosicionElem(pl,i+pl->tamElem*rep,cmp); //posicion del siguiente elemento no repetido
    memcpy(i,i+pl->tamElem*rep,(pl->ce-pos+1)*pl->tamElem);
    pl->ce-=rep;

    if(pl->ce * 3 <= pl->cap)
    {
        pl->cap = max(pl->cap/2,8); // Hago que la redefinicion nunca baje de 8//
        pl->vec = realloc(pl->vec, pl->cap*pl->tamElem);
    }
    return rep;
}
int eliminarDuplicadosOrdDesc(Lista* pl, void* elem, Cmp cmp)
{
    void* ini = pl->vec;
    if(cmp(elem,ini)>0)
        return 0;

    int rep=cantidadDeRepeticionesElem(pl,elem,cmp);
    if(rep==0)
        return 0;

    void* i = listaBuscarOrdDesc(pl,elem,cmp)+pl->tamElem;
    int pos = obtenerPosicionElem(pl,i+pl->tamElem*rep,cmp); //posicion del siguiente elemento no repetido
    memcpy(i,i+pl->tamElem*rep,(pl->ce-pos+1)*pl->tamElem);
    pl->ce-=rep;

    if(pl->ce * 3 <= pl->cap)
    {
        pl->cap = max(pl->cap/2,8); // Hago que la redefinicion nunca baje de 8//
        pl->vec = realloc(pl->vec, pl->cap*pl->tamElem);
    }
    return rep;
}
void listaOrdenarAscBurbujeo(Lista* pl, Cmp cmp)
{
    void*ptr=pl->vec;
    int i=0,j;
    while(i<pl->ce)
    {
        for(j=0;j<pl->ce-i;j++)
            if(cmp(ptr+j*pl->tamElem,ptr+(j+1)*pl->tamElem)>0)
                intercambiar(ptr+j*pl->tamElem,ptr+(j+1)*pl->tamElem,pl->tamElem);
        i++;
    }
}
void listaOrdenarAscSeleccion(Lista* pl, Cmp cmp) // Cmp es tipo de dato para la funcion, cmp es la funcion generica para comparar en buscarMenor
{
    void* ult=pl->vec+(pl->ce-1)*pl->tamElem;
    void* m;
    for(void*i=pl->vec;i<ult;i+=pl->tamElem) // i pasa a ser void* para ser generico ; i suma tamElem cada iteracion ya que sumaria de a 1 byte si dejo i++
    {
        m = buscarMenor(i,ult, pl->tamElem, cmp);
        intercambiar(i,m, pl->tamElem);
    }
}
void listaOrdenarAscInsercion(Lista* pl, Cmp cmp)
{
    void* ult = pl->vec+(pl->ce-1)*pl->tamElem;
    char elemAInsertar[pl->tamElem];

    for(void* i=pl->vec+pl->tamElem;i<=ult;i+=pl->tamElem)
    {
        memcpy(elemAInsertar,i,pl->tamElem);
        void* j = i-pl->tamElem;

        while(j>=pl->vec && cmp(elemAInsertar,j)<0)
        {
            memcpy(j+pl->tamElem,j,pl->tamElem);
            j-=pl->tamElem;
        }
        if(i!=j+pl->tamElem)
            memcpy(j+pl->tamElem,elemAInsertar,pl->tamElem);
    }
}
void listaOrdenarDescBurbujeo(Lista* pl, Cmp cmp)
{
    void*ptr=pl->vec;
    int i=1,j;
    while(i<pl->ce)
    {
        for(j=0;j<pl->ce-i;j++)
            if(cmp(ptr+j*pl->tamElem,ptr+(j+1)*pl->tamElem)<0)
                intercambiar(ptr+j*pl->tamElem,ptr+(j+1)*pl->tamElem,pl->tamElem);
        i++;
    }
}
void listaOrdenarDescSeleccion(Lista* pl, Cmp cmp)
{
    void* ult=pl->vec+(pl->ce-1)*pl->tamElem;
    void* m;
    for(void*i=pl->vec;i<ult;i+=pl->tamElem)
    {
        m = buscarMayor(i,ult, pl->tamElem, cmp);
        intercambiar(i,m, pl->tamElem);
    }
}
void listaOrdenarDescInsercion(Lista* pl, Cmp cmp)
{
    void* ult = pl->vec+(pl->ce-1)*pl->tamElem;
    char elemAInsertar[pl->tamElem];

    for(void* i=pl->vec+pl->tamElem;i<=ult;i+=pl->tamElem)
    {
        memcpy(elemAInsertar,i,pl->tamElem);
        void* j = i-pl->tamElem;

        while(j>=pl->vec && cmp(elemAInsertar,j)>0)
        {
            memcpy(j+pl->tamElem,j,pl->tamElem);
            j-=pl->tamElem;
        }
        if(i!=j+pl->tamElem)
            memcpy(j+pl->tamElem,elemAInsertar,pl->tamElem);
    }
}
void intercambiar(void* a, void* b, size_t tamElem)
{
    void* aTemp = malloc(tamElem); //Surge ahora el problema de inicializar la auxiliar igualandola a alguno de los dos parametros (que son void), por eso la hago void* y le doy con malloc
    memcpy(aTemp,a,tamElem); //aTemp=*a   //También existe memmove, que se puede utilizar si se solapan las regiones de memoria.
    memcpy(a,b,tamElem); //*a=*b                 //memcpy (elem1,elem2,cant bytes)
    memcpy(b,aTemp,tamElem); //*b=aTem;
    free(aTemp);
}
void intercambiar2(void* a, void* b, size_t tamElem)
{
    char aTemp[tamElem]; // Otra variante con vector de char
    memcpy(aTemp,a,tamElem); //aTemp=*a
    memcpy(a,b,tamElem); //*a=*b
    memcpy(b,aTemp,tamElem); //*b=aTem;
}
void* buscarMenor(void* ini, void* fin, size_t tamElem, Cmp cmp)
{
    void* m = ini;

    for(void* j=ini+tamElem;j<=fin;j+=tamElem)
    {
        if(cmp(j,m)<0) // no se puede hacer directamente *j < *m ya que no se puede desreferenciar void*, ni tampoco comparar algo que no sé que es, voy a necesitar una funcion por parámetro
            m = j;
    }
    return m;
}
void* buscarMayor(void* ini, void* fin, size_t tamElem, Cmp cmp)
{
    void* m = ini;

    for(void* j=ini+tamElem;j<=fin;j+=tamElem)
    {
        if(cmp(j,m)>0) // no se puede hacer directamente *j < *m ya que no se puede desreferenciar void*, ni tampoco comparar algo que no sé que es, voy a necesitar una funcion por parámetro
            m = j;
    }
    return m;
}
int cmpProdxCod (const void* a, const void* b)
{
    Producto* p1 = (Producto*)a;
    Producto* p2 = (Producto*)b;
    return p1->cod-p2->cod;
}
int cmpProdxPrec (const void* a, const void* b)
{
    Producto* p1 = (Producto*)a;
    Producto* p2 = (Producto*)b;
    return p1->pUnit-p2->pUnit;
}
void mostrarProd(void*a,void*b)
{
    Producto* prod = (Producto*)a;
    printf("%3d -  %-12s - $%.2f \n",prod->cod,prod->desc,prod->pUnit);
}
