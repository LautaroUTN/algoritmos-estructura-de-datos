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
NodoLista* busquedaSec(NodoLista*lista,unsigned cod_prod);
int miBusqueda(NodoLista*lista, unsigned cod_prod, int &cont);
void verificarRepetido(NodoLista*lista);

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
    verificarRepetido(ListProd);
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

NodoLista* busquedaSec(NodoLista*lista,unsigned cod_prod)
{
    NodoLista*r=lista;
    while(r!=NULL && r->product.cod_prod!=cod_prod)
        r=r->sig;
    return r;
}

void verificarRepetido(NodoLista*lista)
{
   NodoLista *puntStock = NULL;
   NodoLista *lis = lista;
   int cantRep = 0;
   int cantStock = 0;
   while(lis != NULL){
        cantStock = miBusqueda(lista, lis->product.cod_prod, cantRep);
        if(cantRep > 1)
        {
            cantRep = cantRep - 1;
            int i = 0;
            while(i < cantRep)
            {
                eliminar(lista, lis->product);
                i++;
            }
            puntStock = busquedaSec(lista, lis->product.cod_prod);
            if(puntStock != NULL)
                puntStock->product.stock = cantStock;

            cantRep = 0;
            cantStock = 0;
        }
   }
}

int miBusqueda(NodoLista*lista, unsigned cod_prod, int &cont)
{
    NodoLista*r=lista;
    int cantStock;
    while(r!=NULL)
    {
        if(r->product.cod_prod==cod_prod)
        {
             cont++;
             cantStock += r->product.stock;
        }
        r=r->sig;
    }
    return cantStock;
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
