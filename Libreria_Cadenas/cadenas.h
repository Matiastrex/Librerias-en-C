#ifndef CADENAS_H_INCLUDED
#define CADENAS_H_INCLUDED
#include <stddef.h>
#include <string.h>
#include <stdio.h>


#define ESLETRA(x) ((x)>='A' && (x)<='Z')||((x)>='a'&& (x)<='z')
#define ESALFANUM(x) ((x)>='A' && (x)<='Z')||((x)>='a'&& (x)<='z')||((x)>='0'&&(x)<='9')
#define AMAYUSCULA(x) ((x)>='a' && (x)<='z')? (x)-('a'-'A') : (x)
#define AMINUSCULA(x) ((x)>='A' && (x)<='Z')? (x)+('a'-'A') : (x)
#define CUADRADO(x) (x)*(x)
#define MAX(x,y) (x)>(y)? (x):(y)
#define MIN(x,y) (x)<(y)? (x):(y)
//#define REDONDEAR/TRUNCAR(x)
size_t miStrlen (const char* cad);
int miStrcmp (const char* a, const char* b); //CONTROLAR
int miStrcmpi (const char* a, const char* b);//CONTROLAR
void invertirCadena (char* cad);
int esPalindromo (const char* cad);
int proximaPalabra(char* cad,char** ini,char** fin);
void mostrarPalabra(char* cad,char* fin);
void cifradoCesar(char* cad);
void desofuscarPalabra(char* cad);
void desplazamiento(char* c, int pos, const char* grupo);










#endif // CADENAS_H_INCLUDED
