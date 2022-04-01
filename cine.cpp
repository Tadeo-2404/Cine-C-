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
}

// MUESTRA TODAS LAS PELICULAS DISPONIBLES
void Cine::mostrarCatalogo()
{
     for (int i = 0; i < counterSala; i++)
     {
       if(arregloSala[i]->getCounterPeliculasSala() == 0)
       {
         cout << "No hay funciones disponibles, intentalo de nuevo mas tarde" <<endl;
         return;
       }
     }
     
    cout << "-----------------------------------" << endl;
    cout << "Cartelera" << endl;
    cout << "-----------------------------------" << endl;
    cout << "-Salas Disponibles" << endl;
    for (int i = 0; i < counterSala; i++)
    {
      Sala *sala = arregloSala[i];
      cout << "\nSala Numero.- " << i + 1 << endl;
      sala->mostrarPelicula();
    }
    cout << "-----------------------------------" << endl;
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
    getline(cin, nombrePelicula);
    cout << "Ingrese director de pelicula: ";
    fflush(stdin);
    getline(cin, directorPelicula);
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

// Registra una pelicula de la cartelera a la sala
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
    fflush(stdin);
    cin >> getPeliID;

    if (getPeliID > 35 || getPeliID == 0)
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
        cout << "Sala Numero.- " << i + 1 << endl;
      }
      cout << "-----------------------------------" << endl;
      cout << "Selecciona una Sala" << endl;
      cout << "N.- ";
      fflush(stdin);
      cin >> getSalaID;

      if (getSalaID <= 7 && getSalaID > 0)
      {
        arregloSala[getSalaID - 1]->añadirPeliculas(peliculasArrayCine[getPeliID - 1]);
      }
      else
      {
        cout << "Error: valor no valido" << endl;
      }
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
        Sala *sala = arregloSala[i];
        cout << "\nSala Numero.- " << i + 1 << endl;
        sala->mostrarPelicula();
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

      Sala *sala = arregloSala[getSalaID - 1];

      switch (getSalaID - 1)
      {
      case 0:
      {
        SalaGrande *salaG1 = (SalaGrande *)arregloSala[0];
        cout << "Sala N.- 1 " << sala->getTipoSala() << endl;

        asiento = salaG1->escogerAsiento(getPeliID - 1);
        cout << "Asientos Sala 1: Actualizados!!" << endl;
        salaG1->mostrarAsientos(getPeliID - 1);
        peliculaEscogida = sala->mostrarPeliEscogida(getPeliID - 1);

        this->crearTicket(cliente, getSalaID, peliculaEscogida.getNombre(), peliculaEscogida.getHorario(), asiento);
        this->mostrarTicket(cliente);
        clientesArray[counterClientes] = cliente;
        counterClientes++;
        break;
      }
      case 1:
      {
        SalaGrande *salaG2 = (SalaGrande *)arregloSala[1];
        cout << "Sala N.- 2 " << sala->getTipoSala() << endl;

        asiento = salaG2->escogerAsiento(getPeliID - 1);
        cout << "Asientos Sala 2: Actualizados!!" << endl;
        salaG2->mostrarAsientos(getPeliID - 1);
        peliculaEscogida = sala->mostrarPeliEscogida(getPeliID - 1);

        this->crearTicket(cliente, getSalaID, peliculaEscogida.getNombre(), peliculaEscogida.getHorario(), asiento);
        this->mostrarTicket(cliente);
        clientesArray[counterClientes] = cliente;
        counterClientes++;
        break;
      }
      case 2:
      {
        SalaMediana *salaM1 = (SalaMediana *)arregloSala[2];
        cout << "Sala N.- 3 " << sala->getTipoSala() << endl;

        asiento = salaM1->escogerAsiento(getPeliID - 1);
        cout << "Asientos Sala 3: Actualizados!!" << endl;
        salaM1->mostrarAsientos(getPeliID - 1);
        peliculaEscogida = sala->mostrarPeliEscogida(getPeliID - 1);

        this->crearTicket(cliente, getSalaID, peliculaEscogida.getNombre(), peliculaEscogida.getHorario(), asiento);
        this->mostrarTicket(cliente);
        clientesArray[counterClientes] = cliente;
        counterClientes++;
        break;
      }
      case 3:
      {
        SalaMediana *salaM2 = (SalaMediana *)arregloSala[3];
        cout << "Sala N.- 4 " << sala->getTipoSala() << endl;

        asiento = salaM2->escogerAsiento(getPeliID - 1);
        cout << "Asientos Sala 4: Actualizados!!" << endl;
        salaM2->mostrarAsientos(getPeliID - 1);
        peliculaEscogida = sala->mostrarPeliEscogida(getPeliID - 1);

        this->crearTicket(cliente, getSalaID, peliculaEscogida.getNombre(), peliculaEscogida.getHorario(), asiento);
        this->mostrarTicket(cliente);
        clientesArray[counterClientes] = cliente;
        counterClientes++;
        break;
      }

      case 4:
      {
        SalaMediana *salaM3 = (SalaMediana *)arregloSala[4];
        cout << "Sala N.- 5 " << sala->getTipoSala() << endl;

        asiento = salaM3->escogerAsiento(getPeliID - 1);
        cout << "Asientos Sala 5: Actualizados!!" << endl;
        salaM3->mostrarAsientos(getPeliID - 1);
        peliculaEscogida = sala->mostrarPeliEscogida(getPeliID - 1);

        this->crearTicket(cliente, getSalaID, peliculaEscogida.getNombre(), peliculaEscogida.getHorario(), asiento);
        this->mostrarTicket(cliente);
        clientesArray[counterClientes] = cliente;
        counterClientes++;
        break;
      }
      case 5:
      {
        SalaMediana *salaM4 = (SalaMediana *)arregloSala[5];
        cout << "Sala N.- 6 " << sala->getTipoSala() << endl;

        asiento = salaM4->escogerAsiento(getPeliID - 1);
        cout << "Asientos Sala 6: Actualizados!!" << endl;
        salaM4->mostrarAsientos(getPeliID - 1);
        peliculaEscogida = sala->mostrarPeliEscogida(getPeliID - 1);

        this->crearTicket(cliente, getSalaID, peliculaEscogida.getNombre(), peliculaEscogida.getHorario(), asiento);
        this->mostrarTicket(cliente);
        clientesArray[counterClientes] = cliente;
        counterClientes++;
        break;
      }
      case 6:
      {
        SalaMediana *salaM5 = (SalaMediana *)arregloSala[6];
        cout << "Sala N.- 7 " << sala->getTipoSala() << endl;

        asiento = salaM5->escogerAsiento(getPeliID - 1);
        cout << "Asientos Sala 7: Actualizados!!" << endl;
        salaM5->mostrarAsientos(getPeliID - 1);
        peliculaEscogida = sala->mostrarPeliEscogida(getPeliID - 1);

        this->crearTicket(cliente, getSalaID, peliculaEscogida.getNombre(), peliculaEscogida.getHorario(), asiento);
        this->mostrarTicket(cliente);
        clientesArray[counterClientes] = cliente;
        counterClientes++;
        break;
      }

      default:
        cout << "ERORR: Opcion no valida" << endl;
        break;
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

void Cine::crearTicket(Cliente &cliente, int salaNumero, string peliculaNombre, string horario, string asiento)
{
  if (counterClientes < 2800)
  {
    cliente.setSalaNumero(salaNumero);
    cliente.setPeliculaNombre(peliculaNombre);
    cliente.setHorario(horario);
    cliente.setAsiento(asiento);
  }
  else
  {
    cout << "Ya no se pueden crear mas tickets" << endl;
  }
}

void Cine::mostrarTicket(Cliente &cliente)
{

  cout << "------------TICKET-------------" << endl;
  cout << "Nombre: " << cliente.getNombre() << endl;
  cout << "ID: " << cliente.getID() << endl;
  cout << "Pelicula: " << cliente.getPeliculaNombre() << endl;
  cout << "Horario: " << cliente.getHorario() << endl;
  cout << "Sala: " << cliente.getSalaNumero() << endl;
  cout << "Asiento: " << cliente.getAsiento() << endl;
  cout << "----------------------------------" << endl;
}

// MUESTRA T0DOS LOS CLIENTES EN EL ARREGLO
void Cine::mostrarCliente()
{
  cout << "-----------------------------------" << endl;
  cout << "Lista de Clientes" << endl;
  for (int i = 0; i < counterClientes; i++)
  {
    Cliente &cliente = clientesArray[i];
    cout << "Nombre: " << cliente.getNombre() << endl;
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
        this->mostrarTicket(clientesArray[i]);
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
        this->mostrarTicket(clientesArray[i]);
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

// Registra Salas del Tipo Sala (padre)
void Cine::registrarSala(Sala *sala)
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
    cout << "Sala Numero.- " << i + 1 << endl;
  }
  cout << "-----------------------------------" << endl;
}