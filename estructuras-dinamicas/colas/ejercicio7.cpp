
#include <iostream>
#include <stdio.h>
#define TopeAsientosAvion = 5

using namespace std;

struct Pasajero{
    int dni;
    char nombre[21];
    char apellido[21];
};

struct NodoCola{
    Pasajero pasaj;
    NodoCola*sig;
};

void encolar(NodoCola*&pri,NodoCola*&ult, Pasajero pasaj);
void desencolar(NodoCola*&pri,NodoCola*&ult,Pasajero &pasaj);
void EncolaAlFinalSiExiste(NodoCola*&pri,NodoCola*&ult, Pasajero &pasaj, int dniPerson);
void cargarColaUsuario(NodoCola*&pri, NodoCola*&ult, Pasajero pasaj);
void mostrarElementosCola(NodoCola*&pri,NodoCola*&ult, Pasajero &person);
void verficarAsientoLibre(NodoCola *&pri,NodoCola *&ult, int destino, int  asientosLibres, Pasajero person);

int main(){
    int destino = 0;
    Pasajero pasaj;
    cout<< "INGRESA EL DESTINO"<<endl;
    cout<< "1- MAR DEL PLATA"<<endl;
    cout<< "2- PUNTA DEL ESTE"<<endl;
    cout<< "3- MONTEVIDEO"<<endl;
    cin>>destino;
    while(destino < 1 || destino > 3){
        cout<< "INGRESA UN DESTINO VALIDO"<<endl;
        cout<< "1- MAR DEL PLATA"<<endl;
        cout<< "2- PUNTA DEL ESTE"<<endl;
        cout<< "3- MONTEVIDEO"<<endl;
        cin>>destino;
    }
    switch(destino){
        case 1:

            {
                NodoCola *priMDP = NULL;
                NodoCola *ultMDP = NULL;
                cargarColaUsuario(priMDP, ultMDP, pasaj);
                mostrarElementosCola(priMDP, ultMDP, pasaj);
                verficarAsientoLibre(priMDP, ultMDP, destino, 3, pasaj);
            }

        break;
        case 2:
            {
                NodoCola *priPDE = NULL;
                NodoCola *ultPDE = NULL;
                cargarColaUsuario(priPDE, ultPDE, pasaj);
                mostrarElementosCola(priPDE, ultPDE, pasaj);
                verficarAsientoLibre(priPDE, ultPDE, destino, 3, pasaj);
            }
        break;
        case 3:
            {
                NodoCola *priMON = NULL;
                NodoCola *ultMON = NULL;
                cargarColaUsuario(priMON, ultMON, pasaj);
                mostrarElementosCola(priMON, ultMON, pasaj);
                verficarAsientoLibre(priMON, ultMON, destino, 3, pasaj);
            }
        break;
    }
    return 0;
}

void mostrarElementosCola( NodoCola*&pri, NodoCola*&ult, Pasajero &person){
    NodoCola *priAux = NULL;
    NodoCola *ultAux = NULL;
    cout<<"MOSTRAMOS LA COLA DEL DESTINO"<<endl;
    while(pri != NULL){
        desencolar(pri, ult, person);
        cout<<"DNI: "<<person.dni<<" NOMBRE: "<<person.nombre<<" APELLIDO: "<<person.apellido<<endl;
        encolar(priAux,ultAux, person);
    }
    while(priAux != NULL){
        desencolar(priAux, ultAux, person);
        encolar(pri,ult, person);
    }
}

void cargarColaUsuario(NodoCola *&pri, NodoCola *&ult, Pasajero pasaj){
    cout<< "INGRESA EL DNI"<<endl;
    cin>>pasaj.dni;
    while(pasaj.dni != 0){
        cout<< "INGRESA EL NOMBRE"<<endl;
        cin>>pasaj.nombre;
        cout<< "INGRESA EL APELLIDO"<<endl;
        cin>>pasaj.apellido;
        encolar(pri, ult, pasaj);
        cout<< "INGRESA EL DNI"<<endl;
        cin>>pasaj.dni;
    }
}

void encolar(NodoCola*&pri,NodoCola*&ult, Pasajero person){
    NodoCola*p=new NodoCola;
    p->pasaj=person;
    p->sig=NULL;
    if(ult!=NULL)
        ult->sig=p;
    else
        pri=p;
    ult=p;
}

void desencolar(NodoCola*&pri,NodoCola*&ult,Pasajero &person){
    NodoCola*p=pri;
    person=pri->pasaj; //p->info
    pri=p->sig;
    delete p;
    if(pri==NULL)
        ult=NULL;
}

void verficarAsientoLibre(NodoCola *&pri,NodoCola *&ult, int destino, int  asientosLibres, Pasajero person ){
    int i = 0;
    cout<<"HAY ASIENTOS LIBRES. INGRESARON AL AVIÓN "<<asientosLibres<<" PERSONAS"<<endl;
    while(i < asientosLibres){
        desencolar(pri,ult, person);
        i++;
    }
    cout<<"COLA ACTUAL: "<<endl;
    mostrarElementosCola(pri, ult, person);
}






