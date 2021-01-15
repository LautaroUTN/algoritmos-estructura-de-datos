
#include <iostream>
#include <stdio.h>
using namespace std;


struct Producto{
    int cod_prod;
    char descripcion[30];
    float importe;
    int stock;
};

struct NodoLista{
    Producto product;
    NodoLista *sig;
};

void eliminar(NodoLista*&lista, Producto prod);
void insertar(NodoLista *&lista,Producto prod);
void mostrarLista(NodoLista *&lista);
void cargarDatos(NodoLista *&lista);
NodoLista* apareo(NodoLista *&lista1, NodoLista *&lista2);
int main()
{
    NodoLista *ListProdA = NULL;
    NodoLista *listProdB = NULL;
    cout<<"LISTA A"<<endl;
    cargarDatos( ListProdA );
    cout<<"LISTA B"<<endl;
    cargarDatos( listProdB );
    cout<<"LISTA A"<<endl;
    mostrarLista(ListProdA);
    cout<<"LISTA B"<<endl;
    mostrarLista(listProdB);
    NodoLista *ListTotal = apareo( ListProdA, listProdB  );
    mostrarLista(ListTotal);
    return 0;
}

void cargarDatos(NodoLista *&lista)
{
    Producto prod;
    cout<<"INGRESA EL CODIGO DEL PRODUCTO"<<endl;
    cin>>prod.cod_prod;
    while(prod.cod_prod != 0){
        cout<<"INGRESA LA DESCRIPCION DEL PRODUCTO"<<endl;
        cin>>prod.descripcion;
        cout<<"INGRESA EL IMPORTE DEL PRODUCTO"<<endl;
        cin>>prod.importe;
        cout<<"INGRESA EL STOCK DEL PRODUCTO"<<endl;
        cin>>prod.stock;
        insertar(lista, prod);
        cout<<"INGRESA EL CODIGO DEL PRODUCTO"<<endl;
        cin>>prod.cod_prod;
    }
}

void insertar(NodoLista *&lista,Producto prod)
{
    NodoLista*p=new NodoLista;
    p->product=prod;
    NodoLista *ant, *r=lista;
    while(r!=NULL && r->product.cod_prod< prod.cod_prod)
    {
        ant=r;
        r=r->sig;
    }
    p->sig=r;
    if(r!=lista)
        ant->sig=p;
    else
        lista=p;
}

void eliminar(NodoLista*&lista,Producto prod)
{
    NodoLista*ant,*r=lista;
    while(r!=NULL && r->product.cod_prod<prod.cod_prod)
    {
        ant=r;
        r=r->sig;
    }
    if(r!=NULL && r->product.cod_prod==prod.cod_prod)
    {
         if(r==lista)
            lista=r->sig;
         else
            ant->sig=r->sig;
         delete r;
    }
    else
        cout<<prod.cod_prod<<" no esta en la lista"<<endl;
}

void mostrarLista(NodoLista *&lista)
{
    NodoLista*r;
    r=lista;
    cout<<"COD PROD        "<<"IMPORTE      "<<"DESCRIPCION          "<<"STOCK "<<endl;
    while(r!=NULL)
    {
        cout<<r->product.cod_prod<<"                       "<<r->product.importe<<"              "<<r->product.descripcion<<"                         "<<r->product.stock<<endl;
        r=r->sig;
    }
}

NodoLista* apareo(NodoLista *&lista1, NodoLista *&lista2)
{
    NodoLista *lis1 = lista1;
    NodoLista *lis2 = lista2;
    NodoLista *lisTotal = NULL;
    while(lis1 != NULL && lis2 != NULL)
    {
        if(lis1->product.cod_prod < lis2->product.cod_prod)
        {
            insertar(lisTotal, lis1->product);
            lis1 = lis1->sig;
        }else{
            if(lis1->product.cod_prod > lis2->product.cod_prod)
            {
                insertar(lisTotal, lis2->product);
                lis2 = lis2->sig;
            }else
            {
                /*SIGNIFICA QUE SON IGUALES
                GUARDAMOS ALGUNO DE LOS DOS (YA QUE TIENEN EL MISMO CODIGO)
                Y AVANZAMOS EN AMBAS LISTAS
                */
                insertar(lisTotal, lis1->product);
                lis1 = lis1->sig;
                lis2 = lis2->sig;
            }
        }
    }
    while(lis1 != NULL)
    {
        insertar(lisTotal, lis1->product);
        lis1 = lis1->sig;

    }
    while(lis2 != NULL)
    {
        insertar(lisTotal, lis2->product);
        lis2 = lis2->sig;
    }
    return lisTotal;
}
