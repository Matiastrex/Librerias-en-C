#include "Matrices.h"
int main()
{
    int mat[][MAX_COL]={{1,7,4},
                       {5,3,2},
                       {3,9,5}};
    int matI[][MAX_COL]={{1,0,0,0},
                         {0,1,0,0},
                         {0,0,1,0},
                         {0,0,0,1}};
    int mat2[][MAX_COL]={{1,6,9,3,5,2,3},
                         {5,3,9,0,1,2,3},
                         {2,4,7,2,3,5,0},
                         {8,2,3,8,1,0,9}};
    int mat3[][MAX_COL]={{0,1,1,1,0},
                         {2,0,1,0,3},
                         {2,2,0,3,3},
                         {2,0,4,0,3},
                         {0,4,4,4,0}};
    int mat4[][MAX_COL]={{0,1,1,0},
                         {2,0,0,3},
                         {2,0,0,3},
                         {0,4,4,0}};
    int mat5[][MAX_COL]={{0,2,2,2,2,0},
                         {3,0,2,2,0,1},
                         {3,3,0,0,1,1},
                         {3,3,0,0,1,1},
                         {3,0,4,4,0,1},
                         {0,4,4,4,4,0}};
    mostrarMatriz(mat5,6,6);
    printf("suma DP: %d\n", sumarDiagonalPrincipal(mat2,4,7));
    printf("suma DS: %d\n", sumarDiagonalSecundaria(mat2,4,7));
    printf("es Identidad: %d\n",esIdentidad(matI,4));
    printf("suma triangular inferior sin Diag: %d\n", sumarTriangularInferior(mat2,4,7,0));
    printf("suma triangular inferior con Diag: %d\n", sumarTriangularInferior(mat2,4,7,1));
    printf("suma triangular superior sin Diag: %d\n", sumarTriangularSuperior(mat2,4,7,1));
    printf("suma triangular superior con Diag: %d\n", sumarTriangularSuperior(mat2,4,7,0));
    printf("suma triangulo superior entre Diagonales: %d\n", sumarTrianguloEntreDiagonalesSuperior(mat5,6));
    printf("suma triangulo izquierdo entre Diagonales: %d\n", sumarTrianguloEntreDiagonalesIzquierdo(mat5,6));
    printf("suma triangulo derecho entre Diagonales: %d\n", sumarTrianguloEntreDiagonalesDerecho(mat5,6));
    printf("suma triangulo inferior entre Diagonales: %d\n", sumarTrianguloEntreDiagonalesInferior(mat4,4));




    return 0;
}

