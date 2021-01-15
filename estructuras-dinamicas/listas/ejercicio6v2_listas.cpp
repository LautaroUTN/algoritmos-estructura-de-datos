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

void insertar(NodoLista *&lista,Producto prod);
void eliminar(NodoLista*&lista, Producto prod);
void mostrarLista(NodoLista *&lista);
void corteControl(NodoLista*&lista);

int main()
{
    NodoLista *ListProd = NULL;
    NodoLista *repetido = NULL;
    Producto prod;
    int elem, cod_prod = 0;
    cout<<"INGRESA EL CODIGO DEL PRODUCTO"<<endl;
    cin>>prod.cod_prod;
    while(prod.cod_prod != 0){
        cout<<"INGRESA LA DESCRIPCION DEL PRODUCTO"<<endl;
        cin>>prod.descripcion;
        cout<<"INGRESA EL IMPORTE DEL PRODUCTO"<<endl;
        cin>>prod.importe;
        cout<<"INGRESA EL STOCK DEL PRODUCTO"<<endl;
        cin>>prod.stock;
        insertar(ListProd, prod);
        cout<<"INGRESA EL CODIGO DEL PRODUCTO"<<endl;
        cin>>prod.cod_prod;
    }
    mostrarLista(ListProd);
    cout<<"LISTA ACTUALIZADA"<<endl;
    corteControl(ListProd);
    mostrarLista(ListProd);
    return 0;
}

void mostrarLista(NodoLista *&lista)
{
    NodoLista*r;
    r=lista;
    cout<<"COD PROD        "<<"IMPORTE      "<<"DESCRIPCION          "<<"STOCK "<<endl;
    while(r!=NULL)
    {
        cout<<r->product.cod_prod<<"   "<<r->product.importe<<"   "<<r->product.descripcion<<"   "<<r->product.stock<<endl;
        r=r->sig;
    }
}

void corteControl(NodoLista*&lista)
{
    NodoLista* listAuxA = lista;
    NodoLista* listAuxB = lista->sig;
    NodoLista* listAuxC = NULL;
    NodoLista* def = NULL;
    while(listAuxA != NULL)
    {
        unsigned stock = listAuxA->product.stock;
        while(listAuxB != NULL)
        {
            if(listAuxA->product.cod_prod == listAuxB->product.cod_prod)
            {
                 stock += listAuxB->product.stock;
                 eliminar(listAuxA, listAuxB->product);
            }
            listAuxB = listAuxB->sig;
        }
        listAuxA->product.stock = stock;
        insertar(def, listAuxA->product);
        listAuxA = listAuxA->sig;
    }
    lista = def;
}

void eliminar(NodoLista*&lista, Producto prod)
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
