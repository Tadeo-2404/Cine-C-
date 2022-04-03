#ifndef SALA_HPP
#define SALA_HPP
#include "pelicula.hpp"

class Sala {
   Pelicula arrayPeliculaSala[5]; //Arreglo de Sala donde se almacena la pelicula
   size_t counterPeliculasSala; //Contador que lleva el registro de la cantidad de peliculas
   size_t counterHorarioString; //Contador que lleva el registro de la cantidad de horarios 
   size_t counterHoraFinal;
   size_t counterHoraInicio;
   string tipoSala;
   string arrayHorarioString[5]; //Guarda los horarios peliculas de la sala
   float arrayHoraFinal[5];
   float arrayHorarInicio[5];
   float horario = 9.00;

public:
    Sala(); //Constructor sala
    Pelicula mostrarPeliEscogida(int position);
    void añadirPeliculas(Pelicula &x); //Añade una pelicula a la sala
    void mostrarPelicula(); //Muestra que pelicula hay en la sala
    void eliminarPelicula(int pos); //Elimina la pelicula de la sala
    void setTipoSala(string);
    string getTipoSala();
    int getCounterPeliculasSala();
};

class SalaMediana : public Sala {
    string asientos[5][7][8] = {
        {
         {"A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8"},
         {"B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8"},
         {"C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8"},
         {"D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8"},
         {"E1", "E2", "E3", "E4", "E5", "E6", "E7", "E8"},
         {"F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8"},
         {"G1", "G2", "G3", "G4", "G5", "G6", "G7", "G8"}
        },
        {
         {"A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8"},
         {"B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8"},
         {"C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8"},
         {"D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8"},
         {"E1", "E2", "E3", "E4", "E5", "E6", "E7", "E8"},
         {"F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8"},
         {"G1", "G2", "G3", "G4", "G5", "G6", "G7", "G8"}
        },
        {
         {"A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8"},
         {"B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8"},
         {"C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8"},
         {"D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8"},
         {"E1", "E2", "E3", "E4", "E5", "E6", "E7", "E8"},
         {"F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8"},
         {"G1", "G2", "G3", "G4", "G5", "G6", "G7", "G8"}
        },
        {
         {"A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8"},
         {"B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8"},
         {"C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8"},
         {"D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8"},
         {"E1", "E2", "E3", "E4", "E5", "E6", "E7", "E8"},
         {"F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8"},
         {"G1", "G2", "G3", "G4", "G5", "G6", "G7", "G8"}
        },
        {
         {"A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8"},
         {"B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8"},
         {"C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8"},
         {"D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8"},
         {"E1", "E2", "E3", "E4", "E5", "E6", "E7", "E8"},
         {"F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8"},
         {"G1", "G2", "G3", "G4", "G5", "G6", "G7", "G8"}
        }
};
public:
    SalaMediana();
    void mostrarAsientos(int position);
    string escogerAsiento(int position);
    void reiniciarAsientos(int position);
};

class SalaGrande : public Sala {
    string asientos[5][10][14] = {
        {
         {"A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "A10", "A11", "A12", "A13", "A14"},
         {"B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "B10", "B11", "B12", "B13", "B14"},
         {"C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13", "C14"},
         {"D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13", "D14"},
         {"E1", "E2", "E3", "E4", "E5", "E6", "E7", "E8", "E9", "E10", "E11", "E12", "E13", "E14"},
         {"F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "F13", "F14"},
         {"G1", "G2", "G3", "G4", "G5", "G6", "G7", "G8", "G9", "G10", "G11", "G12", "G13", "G14"},
         {"H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13", "H14"},
         {"I1", "I2", "I3", "I4", "I5", "I6", "I7", "I8", "I9", "I10", "I11", "I12", "I13", "I14"},
         {"J1", "J2", "J3", "J4", "J5", "J6", "J7", "J8", "J9", "J10", "J11", "J12", "J13", "J14"} 
        }, 
        {
         {"A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "A10", "A11", "A12", "A13", "A14"},
         {"B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "B10", "B11", "B12", "B13", "B14"},
         {"C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13", "C14"},
         {"D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13", "D14"},
         {"E1", "E2", "E3", "E4", "E5", "E6", "E7", "E8", "E9", "E10", "E11", "E12", "E13", "E14"},
         {"F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "F13", "F14"},
         {"G1", "G2", "G3", "G4", "G5", "G6", "G7", "G8", "G9", "G10", "G11", "G12", "G13", "G14"},
         {"H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13", "H14"},
         {"I1", "I2", "I3", "I4", "I5", "I6", "I7", "I8", "I9", "I10", "I11", "I12", "I13", "I14"},
         {"J1", "J2", "J3", "J4", "J5", "J6", "J7", "J8", "J9", "J10", "J11", "J12", "J13", "J14"} 
        },
        {
         {"A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "A10", "A11", "A12", "A13", "A14"},
         {"B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "B10", "B11", "B12", "B13", "B14"},
         {"C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13", "C14"},
         {"D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13", "D14"},
         {"E1", "E2", "E3", "E4", "E5", "E6", "E7", "E8", "E9", "E10", "E11", "E12", "E13", "E14"},
         {"F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "F13", "F14"},
         {"G1", "G2", "G3", "G4", "G5", "G6", "G7", "G8", "G9", "G10", "G11", "G12", "G13", "G14"},
         {"H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13", "H14"},
         {"I1", "I2", "I3", "I4", "I5", "I6", "I7", "I8", "I9", "I10", "I11", "I12", "I13", "I14"},
         {"J1", "J2", "J3", "J4", "J5", "J6", "J7", "J8", "J9", "J10", "J11", "J12", "J13", "J14"} 
        }, 
        {
         {"A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "A10", "A11", "A12", "A13", "A14"},
         {"B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "B10", "B11", "B12", "B13", "B14"},
         {"C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13", "C14"},
         {"D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13", "D14"},
         {"E1", "E2", "E3", "E4", "E5", "E6", "E7", "E8", "E9", "E10", "E11", "E12", "E13", "E14"},
         {"F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "F13", "F14"},
         {"G1", "G2", "G3", "G4", "G5", "G6", "G7", "G8", "G9", "G10", "G11", "G12", "G13", "G14"},
         {"H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13", "H14"},
         {"I1", "I2", "I3", "I4", "I5", "I6", "I7", "I8", "I9", "I10", "I11", "I12", "I13", "I14"},
         {"J1", "J2", "J3", "J4", "J5", "J6", "J7", "J8", "J9", "J10", "J11", "J12", "J13", "J14"} 
        },
        {
         {"A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "A10", "A11", "A12", "A13", "A14"},
         {"B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "B10", "B11", "B12", "B13", "B14"},
         {"C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13", "C14"},
         {"D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13", "D14"},
         {"E1", "E2", "E3", "E4", "E5", "E6", "E7", "E8", "E9", "E10", "E11", "E12", "E13", "E14"},
         {"F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "F13", "F14"},
         {"G1", "G2", "G3", "G4", "G5", "G6", "G7", "G8", "G9", "G10", "G11", "G12", "G13", "G14"},
         {"H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13", "H14"},
         {"I1", "I2", "I3", "I4", "I5", "I6", "I7", "I8", "I9", "I10", "I11", "I12", "I13", "I14"},
         {"J1", "J2", "J3", "J4", "J5", "J6", "J7", "J8", "J9", "J10", "J11", "J12", "J13", "J14"} 
        }
};
    
public:
    SalaGrande();
    void mostrarAsientos(int position);
    string escogerAsiento(int position);
    void reiniciarAsientos(int position);
};

#endif