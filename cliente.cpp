#include <iostream>
using namespace std;
#include "cliente.hpp"
#include "pelicula.hpp"

Cliente::Cliente() {

}; 

Cliente::Cliente(string nombre, int ID) {
   this->nombreCliente = nombre;
   this->ID = ID;
};


void Cliente::setNombre(string nombre)
{
    nombreCliente = nombre;
};

void Cliente::setID(int id)
{
    ID = id;
};


string Cliente::getNombre() {
    return nombreCliente;
}

int Cliente::getID() {
    return ID;
}

// void Cliente::crearTicket(string nombre, int id, int salaNumero, string peliculaNombre, string horario, string asiento)
// {
//     if(counterTicket < 2800)
//     {
//       ticketArray[counterTicket].nombre = nombre;
//       ticketArray[counterTicket].ID = ID;
//       ticketArray[counterTicket].pelicula = peliculaNombre;
//       ticketArray[counterTicket].horario = horario;
//       ticketArray[counterTicket].sala = salaNumero;
//       ticketArray[counterTicket].asiento = asiento;
//       counterTicket++;
//     } else {
//         cout << "Ya no se pueden crear mas tickets" <<endl;
//     }
// }

// void Cliente::mostrarTicket() {
//     for (size_t i = 0; i < counterTicket; i++)
//     {
//       cout << "------------TICKET-------------" <<endl;
//       cout << "Nombre:" << ticketArray[i].nombre <<endl;
//       cout << "ID:" << ticketArray[i].ID <<endl;
//       cout << "Pelicula:" << ticketArray[i].pelicula <<endl;
//       cout << "Horario:" << ticketArray[i].horario <<endl;
//       cout << "Sala:" << ticketArray[i].sala <<endl;
//       cout << "Asiento:" << ticketArray[i].asiento <<endl;
//       cout << "----------------------------------" <<endl;
//     }
    
// }