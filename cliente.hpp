#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <iostream>
using namespace std;

class Cliente {
    string nombreCliente;
    int ID;
    int salaNumero;
    string peliculaNombre;
    string horario;
    string asiento;

public:
    Cliente();
    Cliente(string, int);

    void setNombre(string);
    void setID(int);
    void setSalaNumero(int);
    void setPeliculaNombre(string);
    void setHorario(string);
    void setAsiento(string);

    string getNombre();
    int getID();
    int getSalaNumero();
    string getPeliculaNombre();
    string getHorario();
    string getAsiento();
};

#endif 
