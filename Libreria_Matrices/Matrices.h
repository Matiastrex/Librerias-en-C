#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define TAM_COL 3
#define MAX_COL 50
#define MIN(x,y) (x<y)? x : y

void** crearMatriz(int filas, int columnas, size_t tamElem);
void destruirMatriz(void** matriz, int filas);
void mostrarMatriz(int mat[][MAX_COL],unsigned cf, unsigned cc);
int sumarDiagonalPrincipal(int mat[][MAX_COL],unsigned cf, unsigned cc);
int sumarDiagonalSecundaria(int mat[][MAX_COL],unsigned cf, unsigned cc);
int esIdentidad(int mat[][MAX_COL],unsigned ce);
int sumarTriangularInferior(int mat[][MAX_COL],unsigned cf, unsigned cc, unsigned diag); ///// enviar 1 a diag para incluir diagonal principal
int sumarTriangularSuperior(int mat[][MAX_COL],unsigned cf, unsigned cc, unsigned diag); ///// enviar 1 a diag para NO incluir diagonal principal
int sumarTrianguloEntreDiagonalesSuperior(int mat[][MAX_COL],unsigned tam);
int sumarTrianguloEntreDiagonalesDerecho(int mat[][MAX_COL],unsigned tam);
int sumarTrianguloEntreDiagonalesInferior(int mat[][MAX_COL],unsigned tam);
int sumarTrianguloEntreDiagonalesIzquierdo(int mat[][MAX_COL],unsigned tam);
//int** multiplicarMatriz(int mat[][MAX_COL],int mat1[][MAX_COL],int mat2[][MAX_COL],int cf1,int cc1,int cf2, int cc2);

#endif // MATRICES_H_INCLUDED
