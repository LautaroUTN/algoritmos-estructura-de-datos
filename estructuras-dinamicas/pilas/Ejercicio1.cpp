
#include <iostream>
#include <stdio.h>


using namespace std;

struct Alumno {
    int legajo;
    char nombre[90];
    int nota;
};

struct Nodo {
    Alumno infor;
    Nodo *sig;
};

void sacarElementosPila( Nodo *&pila , Alumno &al, int cantElementSacar);
void apilar( Nodo *&pila , Alumno al );
void desapilar( Nodo *&pila , Alumno &al );

int main()
{
    unsigned elements = 0;
    Alumno al;
    Nodo *pila;
    cout<<"legajo"<<endl;
    cin>>al.legajo;
    while(al.legajo != 0){
        cout<<"nombre"<<endl;
        cin>>al.nombre;
        cout<<"nota"<<endl;
        cin>>al.nota;
        apilar(pila, al);
        cout<<"legajo"<<endl;
        cin>>al.legajo;
    }
    cout<<"Elementos a sacar"<<endl;
    cin>>elements;
    sacarElementosPila(pila ,al, elements);
    cout<<"Desea agregar otro más ? 0 sacar, 1 agregar"<<endl;
    cin>>elements;
    if(elements == 1){
        cout<<"legajo"<<endl;
        cin>>al.legajo;
        cout<<"nombre"<<endl;
        cin>>al.nombre;
        cout<<"nota"<<endl;
        cin>>al.nota;
        apilar(pila, al);
    }
    return 0;
}

void apilar( Nodo *&pila , Alumno al ){
    Nodo *p= new Nodo;
    p->infor = al;
    p->sig = pila;
    pila = p;
}
void desapilar( Nodo *&pila , Alumno &al ){
    Nodo*p=pila;
    cout<<pila->infor.nombre<<endl;
    al=p->infor; //pila->info
    pila=p->sig;
    delete p;
}
void sacarElementosPila( Nodo *&pila , Alumno &al, int cantElementSacar)
{
    int i = 0;
    while(i < cantElementSacar){
        desapilar(pila, al);
        i++;
    }
}
