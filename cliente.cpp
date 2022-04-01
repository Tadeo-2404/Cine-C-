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
    this->nombreCliente = nombre;
};

void Cliente::setID(int id)
{
    this->ID = id;
};

void Cliente::setSalaNumero(int salanumero)
{
    this->salaNumero = salanumero;
};

void Cliente::setPeliculaNombre(string peliculanombre)
{
    this->peliculaNombre = peliculanombre;
};

void Cliente::setHorario(string horario)
{
    this->horario = horario;
};

void Cliente::setAsiento(string asiento)
{
    this->asiento = asiento;
};

string Cliente::getNombre() {
    return nombreCliente;
}

int Cliente::getID() {
    return ID;
}

int Cliente::getSalaNumero() {
    return salaNumero;
}

string Cliente::getPeliculaNombre() {
    return peliculaNombre;
}

string Cliente::getHorario() {
    return horario;
}

string Cliente::getAsiento() {
    return asiento;
}

