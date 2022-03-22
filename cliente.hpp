#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <iostream>
using namespace std;

class Cliente {
    string nombreCliente;
    int ID;

    //   struct ticket
    // {
    //   string nombre;
    //   int ID;
    //   int sala;
    //   string pelicula;
    //   string horario;
    //   string asiento;
    // }ticketArray[2800];
    //  size_t counterTicket = 0;

public:
    Cliente();
    Cliente(string, int);
    //  void crearTicket(string nombre, int id, int salaNumero, string peliculaNombre, string horario, string asiento);
    // void mostrarTicket();
    void setNombre(string);
    void setID(int);
    string getNombre();
    int getID();
};

#endif 
