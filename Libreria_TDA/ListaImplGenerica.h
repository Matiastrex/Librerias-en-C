#ifndef LISTAIMPLGENERICA_H_INCLUDED
#define LISTAIMPLGENERICA_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <string.h>

#define max(x,y) ((x) > (y)? (x) : (y))

#define TODO_OK 0 //Por convención 0 significa que salió todo bien si la funcion no es booleana//
#define SIN_MEM 1
#define DUPLICADO 2
#define FUERA_RANGO 3
#define CAP 15

typedef struct
{
    void* vec;
    int ce;
    size_t cap;
    size_t tamElem; // CAMPO NECESARIO PARA HACERSE GENERICO, PARA SABER CUÁNTO OCUPA CADA ELEMENTO //
}
Lista;
typedef struct
{
    int cod;
    char desc[25];
    float pUnit;
}
Producto;

typedef int (*Cmp) (const void*, const void*); //Los parentesis y el asterico rodeando el nombre del tipo de dato(la funcion) son necesarios porque asi está definido por el lenguaje.
typedef void (*Accion) (void*, void*);
///////////////////////////////////////////////////////////////////////////////////////// PRIMITIVAS DE CREACION, BORRADO E INTERACCION
bool listaCrear(Lista* pl, size_t tamElem); //generica
bool listaCrearRandom(Lista* pl, int ce);
void ListaDestruir(Lista* pl); //generica
void listaVaciar(Lista* pl); //generica
void listaRecorrer(Lista* pl, Accion accion, void* extra); //generica
int obtenerPosicionElem(const Lista* pl, void* elem, Cmp cmp); //generica
int cantidadDeRepeticionesElem(const Lista* pl, void* elem, Cmp cmp); //generica
/////////////////////////////////////////////////////////////////////////////////////////
int listaInsertarEnOrdAsc(Lista* pl, void* elem, Cmp cmp); //generica
int listaInsertarEnOrdDesc(Lista* pl, void* elem, Cmp cmp); //generica
int ListaInsertarAlInicio(Lista* pl, void* elem, Cmp cmp); //generica
int ListaInsertarAlFinal(Lista* pl, void* elem, Cmp cmp); //generica
int ListaInsertarEnPos(Lista* pl, void* elem, int pos, Cmp cmp); //generica
bool listaEliminarOrd(Lista* pl, void* elem, Cmp cmp); //generica
bool listaEliminarDesord(Lista* pl, void* elem, Cmp cmp); //generica
void* listaBuscarOrdAsc(const Lista* pl, void* elem, Cmp cmp); //generica
void* listaBuscarOrdDesc(const Lista* pl, void* elem, Cmp cmp); //generica
void* listaBuscarDesord(const Lista* pl, void* elem, Cmp cmp); //generica
int eliminarDuplicadosOrdAsc(Lista* pl, void* elem, Cmp cmp); //generica
int eliminarDuplicadosOrdDesc(Lista* pl, void* elem, Cmp cmp); //generica
int eliminarDuplicadosDesord(Lista* pl, void* elem, Cmp cmp);
////////////////////////////////////////////////////////////////////////////////////////ORDENAMIENTO ASCENDENTE //
void listaOrdenarAscBurbujeo(Lista* pl, Cmp cmp); //generica
void listaOrdenarAscSeleccion(Lista* pl, Cmp cmp); //generica
void listaOrdenarAscInsercion(Lista* pl, Cmp cmp); //generica
////////////////////////////////////////////////////////////////////////////////////////ORDENAMIENTO DESCENDENTE
void listaOrdenarDescBurbujeo(Lista* pl, Cmp cmp); //generica
void listaOrdenarDescSeleccion(Lista* pl, Cmp cmp); //generica
void listaOrdenarDescInsercion(Lista* pl, Cmp cmp); //generica
////////////////////////////////////////////////////////////////////////////////////////ALGUNAS PRIMITIVAS
void intercambiar(void* a, void* b, size_t tamElem); //generica 1 malloc
void intercambiar2(void* a, void* b, size_t tamElem); //generica 2 no malloc
void* buscarMenor(void* ini, void* fin, size_t tamElem, Cmp cmp); //generica
void* buscarMayor(void* ini, void* fin, size_t tamElem, Cmp cmp); //generica
//////////////////////////////////////////////////////////////////////////////////////// SON ESPECIFICAS, NO DEBERIAN SER DE ESTA BIBLIOTECA
int cmpProdxCod (const void* a, const void* b);
int cmpProdxPrec (const void* a, const void* b);
void mostrarProd(void*a,void*b);

#endif // LISTAIMPLGENERICA_H_INCLUDED
