#include <iostream>
#include <stdio.h>


using namespace std;

struct Alumno
{
    unsigned leg;
    char nom[21];
    unsigned nota;
};

struct Nodo
{
    Alumno info;
    Nodo*sig;
};

void listar(Nodo*lista);
void insertar(Nodo*&lista,Alumno alu);
Nodo* busquedaSec(Nodo*lista,unsigned unLeg);

int main()
{
    Nodo*listaK1021=NULL;
    Alumno alumno;
    cin>>alumno.leg;
    while(alumno.leg!=0)
    {
        cin>>alumno.nom;
        cin>>alumno.nota;
        insertar(listaK1021,alumno);
        cin>>alumno.leg;
    }
    listar(listaK1021);
    Nodo*p=busquedaSec(listaK1021,34);
    if(p!=NULL)
        p->info.nota=8;
    else
        cout<<"el legajo 34 no existe"<<endl;
}

void listar(Nodo*lista)
{
    Nodo*r;
    r=lista;
    while(r!=NULL)
    {
        cout<<r->info.leg<<r->info.nom<<r->info.nota<<endl;
        r=r->sig;
    }
}

Nodo* busquedaSec(Nodo*lista,unsigned unLeg)
{
    Nodo*r=lista;
    while(r!=NULL && r->info.leg!=unLeg)
        r=r->sig;
    return r;
}

Nodo* busquedaSecM(Nodo*lista,unsigned unLeg)
{
    Nodo*r=lista;
    while(r!=NULL && r->info.leg<unLeg)
        r=r->sig;
    if(r!=NULL && r->info.leg==unLeg)
        return r;
    else
        return NULL;
}

void insertar(Nodo*&lista,Alumno alu)
{
    Nodo*p=new Nodo;
    p->info=alu;
    Nodo *ant, *r=lista;
    while(r!=NULL && r->info.leg<alu.leg)
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

Nodo*buscarInsertar(Nodo*&lista,Alumno alu)
{
    Nodo *ant, *r=lista;
    while(r!=NULL && r->info.leg<alu.leg)
    {
        ant=r;
        r=r->sig;
    }
    if(r!=NULL && r->info.leg==alu.leg)
        return r;
    else
    {
        Nodo*p=new Nodo;
        p->info=alu;
        p->sig=r;
        if(r!=lista)
            ant->sig=p;
        else
            lista=p;
        return p;
    }
}

void eliminar(Nodo*&lista,unsigned unLeg)
{
    Nodo*ant,*r=lista;
    while(r!=NULL && r->info.leg<unLeg)
    {
        ant=r;
        r=r->sig;
    }
    if(r!=NULL && r->info.leg==unLeg)
    {
         if(r==lista)
            lista=r->sig;
         else
            ant->sig=r->sig;
         delete r;
    }
    else
        cout<<unLeg<<" no esta en la lista"<<endl;
}
Alumno sacarPrim(Nodo*&lista)
{
    Alumno a=lista->info;
    p=lista;
    lista=lista->sig;
    delete p;
    return a;
}
void mostrarAprobados(Nodo*lista)
{
    Nodo*r;
    r=lista;
    while(r!=NULL)
    {
        if(r->info.nota>=6)
            cout<<r->info.leg<<r->info.nom<<r->info.nota<<endl;
        r=r->sig;
    }
}

float promedioCurso(Nodo*lista)
{
    unsigned cont=0,suma=0;
    Nodo*r;
    r=lista;
    while(r!=NULL)
    {
        suma+=r->info.nota;
        cont++;
        r=r->sig;
    }
    if(cont>0)
        return (float)suma/cont;
    else
        return 0;
}










