
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

void apilar( Nodo *&pila , Alumno al );
void desapilar( Nodo *&pila , Alumno &al );
void apilarPosicion(Nodo *&pila, Alumno &al, int pos);
void mostrarPila(Nodo *&pila);

int main()
{
    unsigned elements = 0;
    Alumno al;
    Nodo *pila;
    cout<<"legajo"<<endl;
    cin>>al.legajo;
    int cantPil = 0;
    while(al.legajo != 0){
        cout<<"nombre"<<endl;
        cin>>al.nombre;
        cout<<"nota"<<endl;
        cin>>al.nota;
        apilar(pila, al);
        cout<<"legajo"<<endl;
        cin>>al.legajo;
        cantPil++;
    }
    cout<<"Cant Elemento a agregar"<<endl;
    cin>>elements;
    if(elements > 0){
        apilarPosicion(pila, al,elements);
    }
    mostrarPila(pila);
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

void mostrarPila(Nodo *&pila){
    Nodo *reco = new Nodo;
    reco = pila;

    cout << "Listado de todos los elementos de la pila.\n";
    while(reco != NULL){
        cout<<reco->infor.legajo<<endl;
        cout<<reco->infor.nombre<<endl;
        cout<<reco->infor.nota<<endl;
        reco = reco->sig;
    }
    cout << "\n";
}
void apilarPosicion(Nodo *&pila, Alumno &al, int pos){
    Alumno alum;
    Alumno alumVec[pos-1];
    int i = 0;
    while(i < pos){
        alumVec[i] = al;
        desapilar(pila, al);
        i++;
    }
    int k = 0;
    while(k < pos){
        cout<<"Legajo"<<endl;
        cin>>alum.legajo;
        cout<<"Nombre nuevo"<<endl;
        cin>>alum.nombre;
        cout<<"Nota"<<endl;
        cin>>alum.nota;
        apilar(pila, alum);
        k++;
    }
    i = 0;
    while(i < pos){
        apilar(pila, alumVec[i]);
        i++;
    }
}

