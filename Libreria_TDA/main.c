#include "ListaImplGenerica.h"

int main()
{
    Lista pl;
    listaCrear(&pl,sizeof(Producto));
    printf("\nCE: %d CAP: %d, TamElem: %d\n\n",(int)pl.ce,(int)pl.cap,(int)pl.tamElem);
    Producto prod1 = {15,"Azucar",5.5};
    ListaInsertarAlInicio(&pl,&prod1,cmpProdxCod);
    Producto prod2 = {22,"Arroz",3.5};
    ListaInsertarAlInicio(&pl,&prod2,cmpProdxCod);
    Producto prod3 = {21,"Harina",3.7};
    ListaInsertarAlInicio(&pl,&prod3,cmpProdxCod);
    Producto prod4 = {24,"Bebida",4.2};
    ListaInsertarAlInicio(&pl,&prod4,cmpProdxCod);
    Producto prod5 = {18,"Pan",3.2};
    ListaInsertarAlInicio(&pl,&prod5,cmpProdxCod);
    Producto prod6 = {25,"Carne",7.6};
    ListaInsertarAlInicio(&pl,&prod6,cmpProdxCod);
    Producto prod7 = {22,"Leche",2.9};
    ListaInsertarAlInicio(&pl,&prod7,cmpProdxCod);
    Producto prod8 = {12,"Yerba",2.9};
    ListaInsertarAlInicio(&pl,&prod8,cmpProdxCod);
    Producto prod9 = {10,"Cigarrillos",2.9};
    ListaInsertarAlInicio(&pl,&prod9,cmpProdxCod);
    Producto prod10 = {25,"Caramelos",2.9};
    ListaInsertarAlInicio(&pl,&prod10,cmpProdxCod);
    Producto prod11 = {30,"Juguetes",2.9};
    ListaInsertarAlInicio(&pl,&prod11,cmpProdxCod);
    Producto prod12 = {87,"Caramelos",2.9};
    ListaInsertarAlInicio(&pl,&prod12,cmpProdxCod);
    Producto prod13 = {22,"Juguetes",2.9};
    ListaInsertarAlInicio(&pl,&prod13,cmpProdxCod);
    Producto prod14 = {15,"Pedigree",4.7};
    ListaInsertarAlInicio(&pl,&prod14,cmpProdxCod);
    listaRecorrer(&pl,mostrarProd,NULL);

    printf("\nCE: %d CAP: %d, TamElem: %d\n\n",(int)pl.ce,(int)pl.cap,(int)pl.tamElem);
    listaOrdenarDescInsercion(&pl,cmpProdxCod);
    listaRecorrer(&pl,mostrarProd,NULL);

    return 0;
}
