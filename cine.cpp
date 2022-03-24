#include <iostream>
using namespace std;
#include "cliente.hpp"
#include "cine.hpp"
#include "sala.hpp"
#include "pelicula.hpp"
#include <iomanip>

// CONSTRUCTOR CINE
Cine::Cine()
{
  counterClientes = 0;
  counterPeliculasCine = 0;
  counterSala = 0;
  counterSalaGrande = 0;
  counterSalaMediana = 0;
}

// MUESTRA TODAS LAS PELICULAS DISPONIBLES
void Cine::mostrarCatalogo()
{
  if (counterPeliculasCine == 0)
  {
    cout << "No hay peliculas disponibles para mostrar, intenta agregando una" << endl;
  }
  else
  {
    cout << "-----------------------------------" << endl;
    cout << "Cartelera" << endl;
    cout << "-----------------------------------" << endl;
    cout << "-Salas Disponibles" << endl;
    for (int i = 0; i < counterSala; i++)
    {
      Sala &sala = arregloSala[i];
      cout << "\nSala Numero.- " << i + 1 << endl;
      sala.mostrarPelicula();
    }
    cout << "-----------------------------------" << endl;
  }
}

// Registra una pelicula en el cine
void Cine::registrarPelicula()
{
  if (counterPeliculasCine < 35)
  {
    string nombrePelicula;
    string directorPelicula;
    string horario;
    float duracionPelicula;
    cout << "Ingrese nombre de pelicula: ";
    fflush(stdin);
    cin >> nombrePelicula;
    cout << "Ingrese director de pelicula: ";
    fflush(stdin);
    cin >> directorPelicula;
    cout << "Ingrese duracion de pelicula (eje: 2.50 h): ";
    fflush(stdin);
    cin >> duracionPelicula;

    Pelicula peliculaCreada(nombrePelicula, directorPelicula, duracionPelicula, horario);

    peliculasArrayCine[counterPeliculasCine] = peliculaCreada;
    counterPeliculasCine++;

    cout << "===================================" << endl;
    cout << "Pelicula N.-: " << counterPeliculasCine << endl;
    cout << "Nombre: " << nombrePelicula << endl;
    cout << "Director: " << directorPelicula << endl;
    cout << "Duracion: " << duracionPelicula << endl;
    cout << "===================================" << endl;
  }
  else
  {
    cout << "Arreglo de peliculas lleno...";
  }
}

// Registra una pelicula de la cartelera en la sala
void Cine::registrarPeliculaSala()
{
  if (counterPeliculasCine > 0)
  {
    int getPeliID;
    int getSalaID;

    // Mostramos pelis
    cout << "-----------------------------------" << endl;
    cout << "Cartelera" << endl;
    cout << "N.-";
    cout << setw(20) << "Nombre";
    cout << setw(20) << "Director";
    cout << setw(20) << "Duracion" << endl;
    for (size_t i = 0; i < counterPeliculasCine; i++)
    {
      Pelicula &pelicula = peliculasArrayCine[i];
      cout << left;
      cout << setw(20) << i + 1;
      cout << setw(20) << pelicula.getNombre();
      cout << setw(20) << pelicula.getDirector();
      cout << setw(20) << pelicula.getDuracion() << endl;
    }
    cout << "-----------------------------------" << endl;

    // Agregar Peli a Sala
    cout << "Selecciona que pelicula quieres agregar" << endl;
    cout << "N: ";
    cin >> getPeliID;

    if (getPeliID > 7 || getPeliID == 0)
    {
      cout << "Pelicula no valida, intenta de nuevo" << endl;
      return;
    }
    else
    {

      // MostrarSalas
      cout << "-----------------------------------" << endl;
      cout << "Salas Disponibles" << endl;
      for (int i = 0; i < counterSala; i++)
      {
        Sala &sala = arregloSala[i];
        cout << "Sala Numero.- " << i + 1 << endl;
      }
      cout << "-----------------------------------" << endl;
      cout << "Selecciona una Sala" << endl;
      cout << "N.- ";
      cin >> getSalaID;

      arregloSala[getSalaID - 1].añadirPeliculas(peliculasArrayCine[getPeliID - 1]);
    }
  }
  else
  {
    cout << "No hay peliculas en Cartelera: Agrega una" << endl;
    return;
  }
}

// RECIBE LA INFORMACION DEL USUARIO Y CREA UN OBJETO DE TIPO CLIENTE
void Cine::venderTicket()
{
  if (counterClientes < 2800)
  {
    srand(time(NULL));
    Cliente cliente;
    Pelicula peliculaEscogida;
    SalaMediana salamediana;
    SalaGrande salagrande;
    string nombreCliente;
    string asiento;
    int ID;
    ID = rand() % 2800 + 1;

    cout << "Ingresa tu Nombre: ";
    fflush(stdin);
    cin >> nombreCliente;

    cliente.setNombre(nombreCliente);
    cliente.setID(ID);

    if (counterPeliculasCine > 0)
    {
      int getSalaID;
      int getPeliID;
      cout << "-----------------------------------" << endl;
      cout << "Cartelera" << endl;
      cout << "-----------------------------------" << endl;
      cout << "-Salas Disponibles" << endl;
      for (int i = 0; i < counterSala; i++)
      {
        Sala &sala = arregloSala[i];
        cout << "\nSala Numero.- " << i + 1 << endl;
        sala.mostrarPelicula();
      }
      cout << "-----------------------------------" << endl;
      cout << "Selecciona la Sala donde quieres ver tu pelicula" << endl;
      cout << "N.- ";
      fflush(stdin);
      cin >> getSalaID;

      cout << "Selecciona la Pelicula que quieres ver" << endl;
      cout << "N.- ";
      fflush(stdin);
      cin >> getPeliID;

      Sala &sala = arregloSala[getSalaID -1];
      if(sala.getTipoSala() == "SalaGrande") {
        
        cout << "Estas en: SalaGrande" <<endl;
        salagrande.mostrarAsientos();
        salagrande.escogerAsiento(getPeliID -1);
        peliculaEscogida = sala.mostrarPeliEscogida(getPeliID - 1);
        cout << "Asiento: " << asiento <<endl;

      } else if(sala.getTipoSala() == "SalaMediana") {

        cout << "Estas en: SalaMediana" <<endl;
        salamediana.mostrarAsientos();
        asiento = salamediana.escogerAsiento(getPeliID -1);
        peliculaEscogida = sala.mostrarPeliEscogida(getPeliID - 1);
        cout << "Asiento: " << asiento <<endl;
      } 
    }
    else
    {
      cout << "No hay peliculas disponibles, regresa mas tarde" << endl;
    }
  }
  else
  {
    cout << "No puedes agregar mas clientes" << endl;
  }
};

// MUESTRA T0DOS LOS CLIENTES EN EL ARREGLO
void Cine::mostrarCliente()
{
  cout << "-----------------------------------" << endl;
  cout << "Lista de Clientes" << endl;
  for (int i = 0; i < counterClientes; i++)
  {
    Cliente &cliente = clientesArray[i];
    cout << "Nombre:" << cliente.getNombre() << endl;
    cout << "ID: " << cliente.getID() << endl;
    cout << "-----------------------------------" << endl;
  }
};

// BUSCA CLIENTE POR NOMBRE
void Cine::buscarCliente(int inicio, string nombreCliente)
{
  int total = 0;
  int sel;
  int confirmar;

  for (int i = inicio; i < counterClientes; i++)
  {
    Cliente &cliente = clientesArray[i];
    if (clientesArray[i].getNombre() == nombreCliente)
    {
      cout << "========================================" << endl;
      cout << "N:" << i << "\nNombre: " << clientesArray[i].getNombre() << "\nID: " << clientesArray[i].getID() << endl;
      total++;

      cout << "1) Acceder   0) Seguir Buscando" << endl;
      fflush(stdin);
      cin >> confirmar;

      if (confirmar == 0)
      {
        if (sizeof(clientesArray) < i)
        {
          buscarCliente(i + 1, nombreCliente);
        }
      }

      else if (confirmar == 1)
      {
        cout << "Cliente Encontrado!!" << endl;
        cout << "N:" << i << "\nNombre: " << clientesArray[i].getNombre() << "\nID: " << clientesArray[i].getID() << endl;
        return;
      }
    }
  }

  if (total == 0)
  {
    return;
    cout << "\n Cliente: Jugador no Encontrado" << endl;
  }
}

// BUSCA CLIENTE POR ID
void Cine::buscarClienteID()
{
  int Id;
  int ch;
  int total;

  cout << "Introduce tu ID" << endl;
  fflush(stdin);
  cin >> Id;

  for (int i = 0; i < counterClientes; i++)
  {
    if (clientesArray[i].getID() == Id)
    {
      cout << "========================================" << endl;
      cout << "N: " << i << "\nNombre: " << clientesArray[i].getNombre() << "\nID: " << clientesArray[i].getID() << endl;
      total++;

      cout << "1) Acceder   0) Continuar Buscando" << endl;
      cin >> ch;

      if (ch == 0)
      {
        buscarClienteID();
      }
      else if (ch == 1)
      {
        cout << "Cliente Encontrado!!" << endl;
        cout << "N:" << i << "\nNombre: " << clientesArray[i].getNombre() << "\nID: " << clientesArray[i].getID() << endl;
        return;
      }
    }
  }

  if (total == 0)
  {
    cout << "\nError: Cliente no Encontrado" << endl;
    return;
  }
}

// Registra Salas del Tipo Mediana
void Cine::registrarSalaMediana(SalaMediana &sala)
{
  if (counterSalaMediana < 5)
  {
    arregloSalaMedian[counterSalaMediana] = sala;
    counterSalaMediana++;
  }
  else
  {
    cout << "Maximo limite de Salas Alcanzado" << endl;
  }
}

// Registra Salas del Tipo Grande
void Cine::registrarSalaGrande(SalaGrande &sala)
{
  if (counterSalaGrande < 2)
  {
    arregloSalaGrande[counterSalaGrande] = sala;
    counterSalaGrande++;
  }
  else
  {
    cout << "Maximo limite de Salas Alcanzado" << endl;
  }
}

// Registra Salas del Tipo Sala (padre)
void Cine::registrarSala(Sala &sala)
{
  if (counterSala < 7)
  {
    arregloSala[counterSala] = sala;
    counterSala++;
  }
  else
  {
    cout << "Maximo limite de Salas Alcanzado" << endl;
  }
}

// Muestra las Salas en el Arreglo Salas
void Cine::mostrarSalas()
{
  cout << "-----------------------------------" << endl;
  cout << "Salas Disponibles" << endl;
  for (int i = 0; i < counterSala; i++)
  {
    Sala &Sala = arregloSala[i];
    cout << "Sala Numero.- " << i + 1 << endl;
  }
  cout << "-----------------------------------" << endl;
}