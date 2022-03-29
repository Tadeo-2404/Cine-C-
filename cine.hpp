#ifndef CINE_HPP
#define CINE_HPP
#include "cliente.hpp"
#include "pelicula.hpp"
#include "sala.hpp"

class Cine
{
    Cliente clientesArray[2800];      // Guarda objetos tipo Cliente
    Pelicula peliculasArrayCine[35];  // Guarda Peliculas en general
    SalaGrande arregloSalaGrande[2];  // Guarda Salas del tipo Grande
    SalaMediana arregloSalaMedian[5]; // Guarda Salas del tipo Mediana
    Sala arregloSala[7];              // Guarda Salas del tipo Sala (padre)

    size_t counterClientes;      // Cuenta cuantos clientes hay en el cine
    size_t counterPeliculasCine; // Cuenta cuantas pelis hemos añadido al cine
    size_t counterSala;          // Cuenta cuantas salas hemos añadido
    size_t counterSalaMediana;   // Cuenta cuentas salas medianas hemos añadido
    size_t counterSalaGrande;    // Cuenta cuentas salas grandes hemos añadido

public:
    Cine();
    void venderTicket();                          // Crea un objeto del tipo cliente
    void buscarCliente(int, string);              // Busca un cliente por Nombre;
    void buscarClienteID();                       // Busca cliente por ID
    void mostrarCliente();                        // Muestra todos los clientes
    void registrarPelicula();                     // Registra una pelicula en el cine
    void registrarPeliculaSala();                 // Registra una pelicula a una Sala
    void mostrarCatalogo();                       // Muestra el catalogo de peliculas
    void registrarSalaMediana(SalaMediana &sala); // Registra Sala Mediana al arreglo
    void registrarSalaGrande(SalaGrande &sala);   // Registra Sala Grande al arreglo
    void registrarSala(Sala &sala);               // Registra Sala Mediana al arreglo
    void mostrarSalas();                          // Muestra todas las salas
};

#endif
