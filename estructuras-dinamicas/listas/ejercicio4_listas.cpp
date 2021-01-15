
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
int devolverStock(NodoLista*lista, unsigned cod_prod);
void cargarDatos(NodoLista *&lista);
NodoLista* recorrerLista(NodoLista*&lista, NodoLista *&listaMenos50);

int main()
{
    NodoLista *ListProdA = NULL;
    NodoLista *listaMenos50 = NULL;

    cargarDatos( ListProdA );
    NodoLista *ListProdMas50 = recorrerLista( ListProdA, listaMenos50  );
    cout<<"LISTA MAYOR A 50"<<endl;
    mostrarLista(ListProdMas50);
    cout<<"LISTA RESTANTE"<<endl;
    mostrarLista(listaMenos50);
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

NodoLista* recorrerLista(NodoLista*&lista, NodoLista*&listaMenos50 )
{
    NodoLista*listaMas50 = NULL;
    while(lista != NULL)
    {
        if(lista->product.stock > 50)
        {
            insertar(listaMas50, lista->product);

        }else{
            insertar(listaMenos50, lista->product);
        }
        lista = lista->sig;
    }
    return listaMas50;
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

