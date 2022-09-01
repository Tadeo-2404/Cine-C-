#include <iostream>
using namespace std;
#include "cliente.hpp"
#include "pelicula.hpp"

// Constructor cliente sin parametros
Cliente::Cliente() {

}; 


// Constructor cliente con parametros
Cliente::Cliente(string nombre, int ID) {
   this->nombreCliente = nombre;
   this->ID = ID;
};

// Setter nombre
void Cliente::setNombre(string nombre)
{
    this->nombreCliente = nombre;
};

// Setter id
void Cliente::setID(int id)
{
    this->ID = id;
};

// Setter salaNumero
void Cliente::setSalaNumero(int salanumero)
{
    this->salaNumero = salanumero;
};

// Setter peliculaNombre
void Cliente::setPeliculaNombre(string peliculanombre)
{
    this->peliculaNombre = peliculanombre;
};

// Setter horario
void Cliente::setHorario(string horario)
{
    this->horario = horario;
};

// Setter Asiento
void Cliente::setAsiento(string asiento)
{
    this->asiento = asiento;
};

// Getter Nombre
string Cliente::getNombre() {
    return nombreCliente;
}

// Getter ID
int Cliente::getID() {
    return ID;
}

// Getter SalaNumero
int Cliente::getSalaNumero() {
    return salaNumero;
}

// Getter PeliculaNombre
string Cliente::getPeliculaNombre() {
    return peliculaNombre;
}

// Getter horario
string Cliente::getHorario() {
    return horario;
}

// Getter Asiento
string Cliente::getAsiento() {
    return asiento;
}

