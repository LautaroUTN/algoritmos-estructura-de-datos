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

void mostrarLista(NodoLista *&lista);
void selectElement(NodoLista *&lista, unsigned k);
NodoLista* busquedaSec(NodoLista*lista,unsigned cod_prod);
int devolverStock(NodoLista*lista, unsigned cod_prod);

int main()
{
    NodoLista *ListProd = NULL;
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
    cout<<"INGRESA ELEMENTO A MOSTRAR"<<endl;
    cin>>elem;
    selectElement(ListProd, elem);
    cout<<"INGRESAR COD_PRODUCTO A AUMENTAR"<<endl;
    cin>>cod_prod;
    NodoLista *elementIncrementar = busquedaSec(ListProd, cod_prod);
    if(elementIncrementar != NULL){
        elementIncrementar->product.importe = elementIncrementar->product.importe + ((elementIncrementar->product.importe * 10) / 100);
    }
    mostrarLista(ListProd);
    cout<<"INGRESAR EL COD_PROD PARA OBTENER EL STOCK"<<endl;
    cin>>cod_prod;
    cout<<"EL STOCK ES DE : "<<devolverStock(ListProd, cod_prod);
    return 0;
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
        cout<<r->product.cod_prod<<"   "<<r->product.importe<<"   "<<r->product.descripcion<<"   "<<r->product.stock<<endl;
        r=r->sig;
    }
}

void selectElement(NodoLista *&lista, unsigned k)
{
    NodoLista*r;
    r=lista;
    int cont = 0;
    k = k-1;
    while(r!=NULL && cont <= k)
    {
        if(cont == k){
            cout<<"EL "<<k<<" elemento es:"<<endl;
            cout<<r->product.cod_prod<<"   "<<r->product.importe<<"   "<<r->product.descripcion<<"   "<<r->product.stock<<endl;
        }
        r=r->sig;
        cont++;
    }
    if(cont < k){
        cout<<"NO SE ENCONTRO EL ELEMENTO"<<endl;
    }
}

NodoLista* busquedaSec(NodoLista*lista,unsigned cod_prod)
{
    NodoLista*r=lista;
    while(r!=NULL && r->product.cod_prod!=cod_prod)
        r=r->sig;
    return r;
}

int devolverStock(NodoLista*lista, unsigned cod_prod)
{
    NodoLista*r=lista;
    while(r!=NULL && r->product.cod_prod!=cod_prod)
        r=r->sig;

    if(r == NULL)
        return -1;
    else
        return r->product.stock;
}
