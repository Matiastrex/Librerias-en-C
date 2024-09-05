#include "Matrices.h"
void** crearMatriz(int fil, int col, size_t tamElem)
{
    int i,j;
    void** mat = malloc(fil*sizeof(void*));
    if(mat==NULL)
        return NULL;
    for(i=0;i<fil;i++)
    {
        mat[i] = malloc(col*tamElem);
        if(mat[i]==NULL)
        {
            for(j=0;j<i;j++)
                free(mat[j]);
            free(mat);
            return NULL;
        }
    }
    return mat;
}
void destruirMatriz(void** matriz, int filas)
{
    int i;
    for(i=0;i<filas;i++)
        free(matriz[i]);
    free(matriz);
}
void mostrarMatriz(int mat[][MAX_COL],unsigned cf, unsigned cc)
{
    int i,j;
    for(i=0;i<cf;i++)
    {
        for(j=0;j<cc;j++)
        {
            printf("%2d ",mat[i][j]);
        }
        puts("\n");
    }
}
int sumarDiagonalPrincipal(int mat[][MAX_COL],unsigned cf, unsigned cc)
{
    int i;
    int min = MIN(cf,cc);
    int sum = 0;
    for(i=0;i<min;i++)
    {
        sum+=mat[i][i];
    }
    return sum;
}
int sumarDiagonalSecundaria(int mat[][MAX_COL],unsigned cf, unsigned cc)
{
    int i,min,sum;
    sum=0;
    min = MIN(cf,cc);

    for(i=0;i<min;i++)
    {
        sum+=mat[i][cc-i-1];
    }
    return sum;
}
int esIdentidad(int mat[][MAX_COL],unsigned ce)
{
    int i,j;
    for(i=0;i<ce;i++)
    {
        if(mat[i][i]!=1)
        {
            return 1;
        }
        for(j=i+1;j<ce;j++)
        {
            if(mat[i][j]!=0 || mat[j][i]!=0)
            {
                return 1;
            }
        }
    }
    return 0;
}
int sumarTriangularInferior(int mat[][MAX_COL],unsigned cf, unsigned cc, unsigned diag)
{
    int i,j,sum;
    sum = 0;

    for(i=0;i<cf;i++)
    {
        for(j=0;j<i+diag;j++)
        {
            sum+=mat[i][j];
        }
    }
    return sum;
}
int sumarTriangularSuperior(int mat[][MAX_COL],unsigned cf, unsigned cc, unsigned diag)
{
    int i,j,sum;
    sum = 0;

    for(i=0;i<cf;i++)
    {
        for(j=i+diag;j<cc;j++)
        {
            sum+=mat[i][j];
        }
    }
    return sum;
}
int sumarTrianguloEntreDiagonalesSuperior(int mat[][MAX_COL],unsigned tam)
{
    int i,j,impar,sum;
    sum = 0;
    impar = tam%2;
    for(i=0;i<tam/2+impar;i++)
    {
        for(j=i+1;j<tam-i-1;j++)
            {
                sum+=mat[i][j];
            }
    }
    return sum;
}
int sumarTrianguloEntreDiagonalesIzquierdo(int mat[][MAX_COL],unsigned tam)
{
    int i,j,impar,sum;
    sum = 0;
    impar = tam%2;
    for(i=0;i<tam/2+impar;i++)
    {
        for(j=i+1;j<tam-i-1;j++)
            {
                sum+=mat[j][i];
            }
    }
    return sum;
}
int sumarTrianguloEntreDiagonalesDerecho(int mat[][MAX_COL],unsigned tam)
{
    int i,j,sum;
    sum = 0;
    for(i=tam/2;i<tam;i++)
    {
        for(j=(tam-i);j<=i-1;j++)
            {
                sum+=mat[j][i];
            }
    }
    return sum;
}
int sumarTrianguloEntreDiagonalesInferior(int mat[][MAX_COL],unsigned tam)
{
    int i,j,sum;
    sum = 0;
    for(i=tam/2;i<tam;i++)
    {
        for(j=(tam-i);j<=i-1;j++)
            {
                sum+=mat[i][j];
            }
    }
    return sum;
}
//int** multiplicarMatriz(int mat1[][MAX_COL],int mat2[][MAX_COL],unsigned cf1,unsigned cc1,unsigned cf2, unsigned cc2)
//{
//    int i,j,k;
//    int sum = 0;
//    int** matResult = crearMatriz(cf1,cc2,sizeof(int));
//    for(i=0;i<cf1;i++)
//    {
//        for(j=0;j<cc2;j++)
//        {
//            for(k=0;k<cf2;k++)
//            {
//                sum += mat1[i][k]*mat2[k][j];
//            }
//        }
//    }
//}

