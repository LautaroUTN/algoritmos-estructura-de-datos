#include <iostream>
#include <stdio.h>


using namespace std;

struct NodoCola
{
    int info;
    NodoCola*sig;
};

void encolar(NodoCola*&pri,NodoCola*&ult, int nro);
bool desencolar(NodoCola*&pri,NodoCola*&ult,int &nro);
void eliminarCantidadCola(NodoCola*&pri,NodoCola*&ult, int nro);
int main(){
    NodoCola *pri = NULL;
    NodoCola *ult = NULL;
    int val = 0;
    cout<<"Ingrese el valor"<<endl;
    cin>>val;
    while(val != 0){
        cout<<"Ingrese el valor"<<endl;
        cin>>val;
        encolar(pri, ult, val);
    }
    cout<<"ELIMINANDO 4 VALORES"<<endl;
    eliminarCantidadCola(pri, ult, 4);
    return 0;
}
void eliminarCantidadCola(NodoCola*&pri, NodoCola*&ult, int nro){
    int i = 0;
    while( i < 4 && pri != NULL){
        desencolar(pri, ult, nro);
        cout<<"true"<<endl;
        i++;
    }
    if( i < 4){
        cout<<"HAY MENOS DE 4 EN LA COLA. SE ELMINARON: "<<i<<" DE LA COLA"<<endl;
    }
    if(pri != NULL){
        cout<<"HAY MAS DE 4 EN LA COLA"<<endl;
    }
}
void encolar(NodoCola*&pri,NodoCola*&ult, int nro){
    NodoCola*p=new NodoCola;
    p->info=nro;
    p->sig=NULL;
    if(ult!=NULL)
        ult->sig=p;
    else
        pri=p;
    ult=p;
}

bool desencolar(NodoCola*&pri,NodoCola*&ult,int &nro){
    if(pri!=NULL)
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

















