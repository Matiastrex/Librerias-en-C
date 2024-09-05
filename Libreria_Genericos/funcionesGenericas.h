#ifndef FUNCIONESGENERICAS_H_INCLUDED
#define FUNCIONESGENERICAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PAL 250

void* crearVector(size_t tam_max,size_t tamElem);
void destruirVector(void* vec);

void insertarOrdenado(void* vec, size_t* ce, size_t tam,void* elem, int cmp(const void* a, const void* b));////HACER//
void eliminarElemento(void* vec, size_t* ce, size_t tam,void* elem, int cmp(const void* a, const void* b)); ////HACER//

void* buscarMenor(const void* vec, size_t ce, size_t tam, int cmp(const void* a, const void* b));
void* buscarMayor(const void* vec, size_t ce, size_t tam, int cmp(const void* a, const void* b));
void intercambio(void* pa, void* pb, size_t tam);
void memcpyPropio(void* dest, const void* origen, size_t tam);

void* recorrerVector(void* vec, size_t ce, size_t tam,void accion(void*));
void* filtrarVector(void* vec, size_t* ce, size_t tam,int filtro(const void*));
void* reducirVector(void* vec, size_t ce, size_t tam,void* operacion(void*,void*),void* inicial);

void ordenamientoPorSeleccionASC(void* vec, size_t ce, size_t tam, int cmp(const void* a,const void* b));
void ordenamientoPorSeleccionDESC(void* vec, size_t ce, size_t tam, int cmp(const void* a,const void* b));
void* busquedaBinariaASC(const void* key, const void* vec,size_t ce, size_t tam,int cmp(const void *, const void *));
void* busquedaBinariaDESC(const void* key, const void* vec,size_t ce, size_t tam,int cmp(const void *, const void *));

int cmp(const void* a, const void* b); //PUNTERO A FUNCION (PARA UTILIZAR LAS DE DEBAJO) //
int cmpEnt(const void* a, const void* b);
int cmpStr(const void* a, const void* b);

void accion(void* a); //PUNTERO A FUNCION (PARA UTILIZAR LAS DE DEBAJO) //
void mostrarPalabra(void* a);
void mostrarEntero(void* a);
void duplicarEntero(void* a);

int filtro(const void* a); //PUNTERO A FUNCION (PARA UTILIZAR LAS DE DEBAJO) //
int filtrarPares(const void* a);

void* operacion(void*,void*);
void* acumularEnteros(void*a,void*b);
void* concatenarCadenas(void*a,void*b);

#endif // FUNCIONESGENERICAS_H_INCLUDED
