#include <iostream>
#include <stdio.h>

using namespace std;


struct Nodo
{
    int dato;
    Nodo*sig;
    Nodo*ant;
};


int main()
{
    Nodo*listaD1=NULL,*listaD2=NULL;
    int valor = 0;
    cout<<"INTRODUZCA UN VALOR"<<endl;
    cin>>valor;
    while(valor != 0)
    {
        insertar(listaD1, listaD2, valor);
    }
    return 0;
}

void insertar(Nodo*&lis1,Nodo*&lis2, int nro)
{
    Nodo*p,*r;
    p=new Nodo;
    p->dato=nro;
    if(lis1==NULL && lis2==NULL) //p no va a tener ni sucesor ni antecesor (agrega a lista vacía)
    {
        p->sig=p->ant=NULL;
        lis1=lis2=p;
    }
    else
    {
        r=lis1;
        while(r!=NULL&&r->dato<nro)
            r=r->sig;
        p->sig=r;
        if(r==lis1) //p va a tener sucesor y no antecesor
        {
            p->ant=NULL;
            //p->sig=r;
            r->ant=p;
            lis1=p;
        }
        else
        {
            if(r==NULL) //p va a tener antecesor y no sucesor
            {
                p->ant=lis2;
                //p->sig=r;
                lis2->sig=p;
                lis2=p;
            }
            else
            {   //p va a tener sucesor y antecesor
                p->ant=r->ant;
                //p->sig=r;
                //Nodo*anterior=r->ant;
                //anterior->sig=p;
                r->ant->sig=p;
                r->ant=p;
            }
        }
    }
}
