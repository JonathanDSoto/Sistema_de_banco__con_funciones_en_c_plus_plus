#include <iostream>
#include <math.h>
#include <cstring>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <sstream>

using namespace std;

void menu(){
    cout << "<======Opciones del sistema======>"<<endl;
    cout << "       1.- Aperturar unacuenta"<<endl;
    cout << "       2.- Depositrar dinero"<<endl;
    cout << "       3.- Retirar dinero"<<endl;
    cout << "       4.- Estado de cuenta"<<endl;
    cout << "       Otra para salir "<<endl;
}

int aperturar(string nombres[10],int clientesC,string apellidos[10],
              string fechaNacimiento[10], string direcciones[10], string telefonos[10],
              float saldos[10])
{


    cout << "Ingrese el nombre"<<endl;
    cin >> nombres[clientesC];

    cout << "Ingrese el apellidos"<<endl;
    cin >> apellidos[clientesC];

    cout << "Ingrese el fecha nacimiento"<<endl;
    cin >> fechaNacimiento[clientesC];

    cout << "Ingrese el dirección"<<endl;
    cin >> direcciones[clientesC];

    cout << "Ingrese el teléfono"<<endl;
    cin >> telefonos[clientesC];

    cout << "Ingrese el monto de apertura"<<endl;
    cin >> saldos[clientesC];

    if(saldos[clientesC]<500){
        saldos[clientesC] = 500;
    }

    clientesC++;
    return clientesC;
}

void estadoDeCuenta(string nombres[10],int cliente,string apellidos[10],
              string fechaNacimiento[10], string direcciones[10], string telefonos[10],
              float saldos[10])
{

   cout << endl<<endl<<"<==========Información de la cuenta==========>"<<endl<<endl;
   cout << "               Nombre:"<<nombres[cliente]<<endl;
   cout << "               Apellidos: "<<apellidos[cliente]<<endl;
   cout << "               Fecha de nacimiento: "<<fechaNacimiento[cliente]<<endl;
   cout << "               Direcciones: "<<direcciones[cliente]<<endl;
   cout << "               Teléfono: "<< telefonos[cliente]<<endl;
   cout << "               Saldo: "<< saldos[cliente]<<endl;
   cout << endl<<endl;
}

void deposito(int cliente, float saldos[10], int cantidad){
    saldos[cliente]+= cantidad;
}

void retiro(int cliente, float saldos[10], int cantidad){

    if(saldos[cliente]>=cantidad){
        cout << "Saldo retirado correctamente"<<endl;
        saldos[cliente]-=cantidad;
    }else{
        cout << "Saldos insuficiente"<<endl;
        cout << "Recibe una multa de $20.00"<<endl;
        saldos[cliente]-=20;
    }
}

int main()
{
    string nombres[10],apellidos[10],fechaNacimiento[10],direcciones[10],telefonos[10];
    float saldos[10]={0};
    int clientesC = 0, cliente, cantidad;
    int op=0;bool power = true;

    while(power){
        menu();
        cin >> op;

        switch (op) {
            case 1:
                clientesC = aperturar(nombres,clientesC,apellidos,fechaNacimiento,direcciones,telefonos,saldos);
                break;
            case 2:
                cout << "Qué cliente desea consultar"<<endl;
                cin >> cliente;

                cout << "Cuanto desea depositar"<<endl;
                cin >> cantidad;

                deposito(cliente,saldos,cantidad);
                break;
            case 3:
                cout << "Qué cliente desea consultar"<<endl;
                cin >> cliente;

                cout << "Cuanto desea retirar"<<endl;
                cin >> cantidad;

                retiro(cliente,saldos,cantidad);
                break;
            case 4:
                cout << "Qué cliente desea consultar"<<endl;
                cin >> cliente;

                estadoDeCuenta(nombres,cliente,apellidos,fechaNacimiento,direcciones,telefonos,saldos);
                break;
            default:
                power = false;
        }

    }
}