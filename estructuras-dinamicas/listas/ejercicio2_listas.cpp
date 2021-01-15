#include <iostream>
#include <stdio.h>
using namespace std;

struct Estudiante{
    char nombre[30];
    int dni;
};

struct NodoLista{
    Estudiante est;
    NodoLista *sig;
};

void insertar(NodoLista *&lista,Estudiante est);
void eliminar(NodoLista*&lista,unsigned dni);
void mostrarListaInversa(NodoLista *&pila, Estudiante estud);
void apilar( NodoLista *&pila, Estudiante estud );
void desapilar( NodoLista *&pila, Estudiante estud );
void mostrarLista(NodoLista *&lista, NodoLista *&pila);

int main()
{
    NodoLista *lista = NULL;
    Estudiante estud;
    NodoLista *pila = NULL;
    cout<<"INGRESE EL DNI"<<endl;
    cin>>estud.dni;
    while(estud.dni != 0){
        cout<<"INGRESE EL NOMBRE"<<endl;
        cin>>estud.nombre;
        insertar(lista, estud);
        cout<<"INGRESE EL DNI"<<endl;
        cin>>estud.dni;
    }
    cout<<"INGRESE EL NRO DNI PARA DAR DE BAJA. DE LO CONTRARIO INGRESE 0"<<endl;
    cin>>estud.dni;
    if(estud.dni != 0){
        eliminar(lista, estud.dni);
    }
    mostrarLista(lista, pila);

    mostrarListaInversa(pila, estud);
    return 0;
}

void insertar(NodoLista *&lista,Estudiante est)
{
    NodoLista*p=new NodoLista;
    p->est=est;
    NodoLista *ant, *r=lista;
    while(r!=NULL && r->est.dni< est.dni)
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

void eliminar(NodoLista*&lista,unsigned dni)
{
    NodoLista*ant,*r=lista;
    while(r!=NULL && r->est.dni<dni)
    {
        ant=r;
        r=r->sig;
    }
    if(r!=NULL && r->est.dni==dni)
    {
         if(r==lista)
            lista=r->sig;
         else
            ant->sig=r->sig;
         delete r;
    }
    else
        cout<<dni<<" no esta en la lista"<<endl;
}

void mostrarLista(NodoLista *&lista, NodoLista *&pila)
{
    NodoLista*r;
    r=lista;
    Estudiante estudian;
    cout<<"nom  "<<"dni      "<<endl;
    while(r!=NULL)
    {
        estudian = r->est;
        apilar(pila, estudian);
        cout<<r->est.nombre<<"   "<<r->est.dni<<endl;
        r=r->sig;
    }
}

//PARA MOSTRAR EN ORDEN INVERSO LO VAMOS APILANDO Y LUEGO LO DESAPILAMOS PARA MOSTRARLO.
//DE ESA FORMA NOS ASEGURAMOS QUE EL ÚLTIMO EN SALIR SEA EL PRIMERO EN ENTRAR LIFO(LAST IN FIRST OUT)
//ORDEN INVERSO
void mostrarListaInversa(NodoLista *&pila, Estudiante estud)
{
    while(pila!=NULL)
    {
        desapilar( pila, estud );

    }
}

void apilar( NodoLista *&pila, Estudiante estud )
{
    NodoLista *p= new NodoLista;
    p->est = estud;
    p->sig = pila;
    pila = p;
}

void desapilar( NodoLista *&pila, Estudiante estud )
{
    NodoLista*p=pila;
    estud=p->est;
    pila=p->sig;
    cout<<estud.nombre<<"   "<<estud.dni<<endl;
    delete p;
}
