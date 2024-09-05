#ifndef LISTAIMPLDINAMICA_H_INCLUDED
#define LISTAIMPLDINAMICA_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
typedef struct
{
    int* vec;
    int ce;
    size_t cap;
}
Lista;

#define max(x,y) ((x) > (y)? (x) : (y))
#define TODO_OK 0 //Por convención 0 significa que salió todo bien si la funcion no es booleana//
#define SIN_MEM 1
#define DUPLICADO 2
#define CAP 15

///////////////////////////////////////////////////////////////////////////////////////// PRIMITIVAS DE CREACION Y BORRADO
bool listaCrear(Lista* p1);
bool listaCrearRandom(Lista* pl, int ce); ////////////
void ListaDestruir(Lista* pl);
void listaVaciar(Lista* pl);
void estadoOperacion(int est);
///////////////////////////////////////////////////////////////////////////////////////
int listaInsertarEnOrdAsc(Lista* pl, int elem);
int listaInsertarEnOrdDesc(Lista* pl, int elem);
int ListaInsertarAlInicio(Lista* pl, int elem);
int ListaInsertarAlFinal(Lista* pl, int elem);
int ListaInsertarEnPos(Lista* pl, int elem, int pos);
bool listaEliminarOrd(Lista* pl, int elem);
bool listaEliminarDesord(Lista* pl, int elem);
bool listaBuscarOrd(const Lista* pl, int elem);
bool listaBuscarDesord(const Lista* pl, int elem);
/*int eliminarDuplicadosOrd(Lista* pl);
int eliminarDuplicadosDesord(Lista* pl);*/
//////////////////////////////////////////////////////////////////////////// ORDENAMIENTO ASCENDENTE //1 para BURBUJEO; 2 para SELECCION; 3 para INSERCION
void listaOrdenarAscAlt(Lista* pl, int metodo);
void listaOrdenarAscBurbujeo(Lista* pl);
void listaOrdenarAscSeleccion(Lista* pl);
void listaOrdenarAscInsercion(Lista* pl);
/////////////////////////////////////////////////////////////////////////// ORDENAMIENTO DESCENDENTE
void listaOrdenarDescAlt(Lista* pl, int metodo);
void listaOrdenarDescBurbujeo(Lista* pl);
void listaOrdenarDescSeleccion(Lista* pl);
void listaOrdenarDescInsercion(Lista* pl);
///////////////////////////////////////////////////////////////////////// ALGUNAS PRIMITIVAS
void intercambiar(int* a, int* b);
int* buscarMenor(const int* ini, const int* fin);
int* buscarMayor(const int* ini, const int* fin);
void listaMostrar(const Lista* pl);

#endif // LISTAIMPLDINAMICA_H_INCLUDED
