#include <iostream>
#include <stdio.h>


using namespace std;

struct NodoCola
{
    int info;
    NodoCola*sig;
};

void encolar(NodoCola*&pri,NodoCola*&ult, int nro)
{
    NodoCola*p=new NodoCola;
    p->info=nro;
    p->sig=NULL;
    if(ult!=NULL)
        ult->sig=p;
    else
        pri=p;
    ult=p;
}
void desencolar(NodoCola*&pri,NodoCola*&ult,int &nro)
{
    NodoCola*p=pri;
    nro=pri->info; //p->info
    pri=p->sig;
    delete p;
    if(pri==NULL)
        ult=NULL;
}

/*
bool desencolar(NodoCola*&pri,NodoCola*&ult,int &nro)
{
    if(pri!=NULL && ult!=NULL)
    {
        NodoCola*p=pri;
        nro=pri->info; //p->info
        pri=p->sig;
        delete p;
        if(pri==NULL)
            ult=NULL;
        return true;
    }
    else
        return false;
}
*/



















