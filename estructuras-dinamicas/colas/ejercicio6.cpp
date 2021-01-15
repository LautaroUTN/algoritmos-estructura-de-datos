
#include <iostream>
#include <stdio.h>


using namespace std;
struct Persona{
    int dni;
    char nombre[21];
};

struct NodoCola
{
    Persona person;
    NodoCola*sig;
};

void encolar(NodoCola*&pri,NodoCola*&ult, Persona person);
void desencolar(NodoCola*&pri,NodoCola*&ult,Persona &person);
void EncolaAlFinalSiExiste(NodoCola*&pri,NodoCola*&ult, Persona &person, int dniPerson);
void cargarPilaUsuario(NodoCola*&pri,NodoCola*&ult, Persona &person);
void mostrarElementosCola(NodoCola*&pri,NodoCola*&ult, Persona &person);

int main(){
    NodoCola *pri = NULL;
    NodoCola *ult = NULL;
    Persona person;
    int dni = 0;
    cargarPilaUsuario( pri, ult, person );
    cout<<"Ingrese el dni buscado"<<endl;
    cin>>dni;
    if(dni > 0){
        EncolaAlFinalSiExiste(pri, ult, person, dni);
        mostrarElementosCola(pri, ult, person);
    }else
        cout<<"DNI INVALIDO"<<endl;
    return 0;
}

void mostrarElementosCola(NodoCola*&pri,NodoCola*&ult, Persona &person){
    cout<<"MOSTRAMOS LA COLA"<<endl;
    while(pri != NULL){
        desencolar(pri, ult, person);
        cout<<"DNI: "<<person.dni<<" NOMBRE: "<<person.nombre<<endl;
    }
}
void cargarPilaUsuario( NodoCola*&pri,NodoCola*&ult, Persona &person ){
    cout<< "INGRESA EL DNI"<<endl;
    cin>>person.dni;
    while(person.dni != 0){
        cout<< "INGRESA EL NOMBRE"<<endl;
        cin>>person.nombre;
        encolar(pri, ult, person);
        cout<< "INGRESA EL DNI"<<endl;
        cin>>person.dni;
    }
}

void EncolaAlFinalSiExiste(NodoCola*&pri,NodoCola*&ult, Persona &person, int dniBuscado){
    Persona personaEnCola;
    NodoCola *priAux = NULL;
    NodoCola *ultAux = NULL;
    while( pri != NULL){
        desencolar(pri, ult, person);
        if(person.dni == dniBuscado){
            personaEnCola = person;
            cout<<"ENCONTRAMOS EL DNI BUSCADO. DNI: "<<person.dni<<" NOMBRE: "<<person.nombre<<endl;
        }else{
            encolar(priAux, ultAux, person);
        }
    }
    //ACÁ VERIFICAMOS QUE EL PRINCIPIO DEL NODO NO SEA NULL.
    //ESO SIGNIFICA QUE LA COLA ESTA VACIA.
    while( priAux != NULL ){
        desencolar( priAux, ultAux, person );
        encolar( pri, ult, person );
    }
    encolar( pri, ult, personaEnCola );
}

void encolar(NodoCola*&pri,NodoCola*&ult, Persona person)
{
    NodoCola*p=new NodoCola;
    p->person=person;
    p->sig=NULL;
    if(ult!=NULL)
        ult->sig=p;
    else
        pri=p;
    ult=p;
}
void desencolar(NodoCola*&pri,NodoCola*&ult,Persona &person)
{
    NodoCola*p=pri;
    person=pri->person; //p->info
    pri=p->sig;
    delete p;
    if(pri==NULL)
        ult=NULL;
}









