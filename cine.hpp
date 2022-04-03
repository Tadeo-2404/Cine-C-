#ifndef CINE_HPP
#define CINE_HPP
#include "cliente.hpp"
#include "pelicula.hpp"
#include "sala.hpp"

class Cine
{
    Cliente clientesArray[2800];      // Guarda objetos tipo Cliente
    Cliente clientesArrayCopia[2800];      // Guarda objetos tipo Cliente
    Pelicula peliculasArrayCine[35];  // Guarda Peliculas en general
    Sala* arregloSala[7];              // Guarda Salas del tipo Sala (padre)

    size_t counterClientes;      // Cuenta cuantos clientes hay en el cine
    size_t counterClientesB;
    size_t counterPeliculasCine; // Cuenta cuantas pelis hemos añadido al cine
    size_t counterSala;          // Cuenta cuantas salas hemos añadido

public:
    Cine();
    void venderTicket();                          // Crea un objeto del tipo cliente
    void buscarCliente(int, string);              // Busca un cliente por Nombre;
    void buscarClienteID();                       // Busca cliente por ID
    void mostrarCliente();                        // Muestra todos los clientes
    void crearTicket(Cliente& cliente, int salaNumero, string peliculaNombre, string horario, string asiento);
    void mostrarTicket(Cliente& cliente);
    void registrarPelicula();                     // Registra una pelicula en el cine
    void registrarPeliculaSala();                 // Registra una pelicula a una Sala
    void eliminarPeliculaSala();                  // Elimina una pelicula de una sala
    void eliminarCliente(int pos);
    void mostrarCatalogo();                       // Muestra el catalogo de peliculas
    void registrarSala(Sala* sala);               // Registra Sala Mediana al arreglo
    void mostrarSalas();                          // Muestra todas las salas
};

#endif
