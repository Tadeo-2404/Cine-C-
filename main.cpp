#include <iostream>
using namespace std;
#include "cliente.hpp"
#include "cine.hpp"
#include "sala.hpp"


int main() {
    int opc;
    int sel;
    int ch;
    int pos = 0;
    Cliente cliente;
    Cine cine;
    SalaGrande salaG1, salaG2;
    SalaMediana salaM1, salaM2, salaM3, salaM4, salaM5;
    string nombreClienteBuscado;
    cine.registrarSala(salaG1);
    cine.registrarSala(salaG2);
    cine.registrarSala(salaM1);
    cine.registrarSala(salaM2);
    cine.registrarSala(salaM3);
    cine.registrarSala(salaM4);
    cine.registrarSala(salaM5);

do {
    cout << "Bienvenid@ a CineMaxPolis" <<endl;
    cout << "1) Mostrar Catalogo" <<endl;
    cout << "2) Vender Ticket" <<endl;
    cout << "3) Buscar y mostrar cliente" <<endl;
    cout << "4) Agregar Pelicula a Sala" <<endl;
    cout << "5) Eliminar Pelicula de Sala" <<endl;
    cout << "Escoge una opcion: ";
    cin>>opc;

    switch (opc)
    {
    case 1:
        cout << "Mostrar Catalago" <<endl;
        cine.mostrarCatalogo();
        break;

    case 2:
        cout << "Vender Ticket" <<endl;
        cine.venderTicket();
        break;
    
    case 3:
        cout << "Buscar y mostrar clientes" <<endl;
        cout << "1) Mostrar Clientes" <<endl;
        cout << "2) Buscar Cliente por Nombre" <<endl;
        cout << "3) Buscar Cliente por ID" <<endl;
        cout << "0) Salir" <<endl;
        cin>>sel;

        switch (sel)
        {
        case 1:
            cout << "Mostrar Clientes" << endl;
            cine.mostrarCliente();
            break;

        case 2:
            cout << "Buscar Cliente por Nombre" << endl;
            cout << "Introduce el nombre del cliente" <<endl;
            cin>>nombreClienteBuscado;
            cine.buscarCliente(0, nombreClienteBuscado);
            break;

        case 3:
            cout << "Buscar Cliente por ID" << endl;
            cine.buscarClienteID();
            break;
        
        default: cout << "Error: Introduce Opcion Valida" <<endl;
            break;
        }
        break;

    case 4:
        cout << "Agregar Pelicula a Sala" <<endl;
        cout << "1) Agregar Pelicula a Cartelera" <<endl;
        cout << "2) Agregar Pelicula a Sala" <<endl;
        cout << "Escoge una opcion: " <<endl;
        cin>>ch;

        switch (ch)
        {
        case 1:
            cout << "Agregar Pelicula a Cartelera" <<endl;
            cine.registrarPelicula();
            break;

        case 2:
            cout << "Agregar Pelicula a Sala" <<endl;
            cine.registrarPeliculaSala();
            break;
        
        default: cout << "Escoge una opcion valida" <<endl;
            break;
        }
        break;

    case 5:
        cout << "Eliminar Pelicula de Sala" <<endl;
        salaG1.escogerAsiento(1);
        salaG1.mostrarAsientos(1);
        break;

    default:
        break;
    }


}while(opc < 6 || opc != 0);

    return 0;
}

