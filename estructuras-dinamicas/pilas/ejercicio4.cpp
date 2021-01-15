
#include <iostream>
#include <stdio.h>

using namespace std;

struct Nodo {
    int valor;
    Nodo *sig;
};

void apilar( Nodo *&pila , int al );
void desapilar( Nodo *&pila , int &al );
void mostrarPila(Nodo *&pila);
void ReemplazarValorPila(Nodo *&pila, int valx, int valy );

int main()
{
    unsigned elements = 0;
    int val_x, val_y;
    int valor;
    Nodo *pila = new Nodo;
    cout<<"valor"<<endl;
    cin>>valor;
    while(valor != 0){
        cout<<"valor"<<endl;
        cin>>valor;
    }
    cout<<"Introduzca el valor y"<<endl;
    cin>>val_y;
    cout<<"Introduzca el valor x"<<endl;
    cin>>val_x;

    ReemplazarValorPila(pila, val_x, val_y );
    mostrarPila(pila);
    return 0;
}

void apilar( Nodo *&pila , int al ){
    Nodo *p= new Nodo;
    p->valor = al;
    p->sig = pila;
    pila = p;
}

void desapilar( Nodo *&pila , int &al ){
    Nodo*p=pila;
    cout<<pila->valor<<endl;
    al=p->valor;
    pila=p->sig;
    delete p;
}


void ReemplazarValorPila( Nodo *&pila, int valx, int valy ){
    Nodo *pilaAux = NULL;
    int nro;
    while(pila!=NULL){
        desapilar(pila, nro);
        if(nro==valy)
            apilar(pilaAux,valx);
        else
            apilar(pilaAux,nro);
    }
    while(pilaAux!=NULL){
        desapilar(pilaAux,nro);
        apilar(pila,nro);
    }
}
