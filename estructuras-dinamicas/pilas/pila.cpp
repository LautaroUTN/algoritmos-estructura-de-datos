#include <iostream>

using namespace std;

struct Libro
{
    unsigned codigo;
    string titulo;

};

struct Nodo
{
    Libro info;
    Nodo *sig;
};

void apilar(Nodo *&pila, Libro lib)
{
    Nodo *p=new Nodo;
    p->info=lib;
    p->sig=pila;
    pila=p;
}

void desapilar(Nodo*&pila,Libro&lib)
{
    Nodo*p=pila;
    lib=p->info; //pila->info
    pila=p->sig;
    delete p;
}

int main()
{
    Libro libro;
    Nodo*pilaLibros;
    pilaLibros=NULL;
    for(int i=1;i<=3;i++)
    {
        cin>>libro.codigo;
        cin>>libro.titulo;
        apilar(pilaLibros,libro);
    }
    while(pilaLibros!=NULL)
    {
        desapilar(pilaLibros,libro);
        cout<<libro.codigo<<libro.titulo<<endl;
    }

    return 0;
}





