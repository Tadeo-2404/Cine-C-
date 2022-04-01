#include <iostream>
#include <iomanip>
using namespace std;
#include "sala.hpp"

// PROTOTIPOS
string conversionHoraMinutos(string valorDeseado);

// CONTRUCTORES
Sala::Sala()
{
  counterPeliculasSala = 0;
  counterHorarioString = 0;
}

string Sala::getTipoSala()
{
  return tipoSala;
}

void Sala::setTipoSala(string tipo)
{
  this->tipoSala = tipo;
}

SalaMediana::SalaMediana()
{
  this->setTipoSala("SalaMediana");
}

SalaGrande::SalaGrande()
{
  this->setTipoSala("SalaGrande");
}

int Sala::getCounterPeliculasSala() 
{
  return counterPeliculasSala;
}

// METODOS

// Mostramos asietnos sala grande
void SalaGrande::mostrarAsientos(int position)
{
    for (int k = position; k < position + 1; k++)
    {
      for (int i = 0; i < 10; i++)
      {
        for (int j = 0; j < 14; j++)
        {
          cout << " " << asientos[k][i][j] << " ";
        }
        cout << "\n";
      }
      cout << "\n";
    }
};

// Escogemos un asiento de sala Grande
string SalaGrande::escogerAsiento(int position)
{
  string buscado;

  for (int k = position; k < position + 1; k++)
  {
    for (int i = 0; i < 10; i++)
    {
      for (int j = 0; j < 14; j++)
      {
        cout << " " << asientos[k][i][j] << " ";
      }
      cout << "\n";
    }
  }

  cout << "Escoge un asiento" << endl;
  fflush(stdin);
  cin >> buscado;
  int flag = 0, row, col, block;

  for (int k = position; k < position + 1; k++)
  {
    for (int i = 0; i < 10; i++)
    {
      for (int j = 0; j < 14; j++)
      {
        if (asientos[k][i][j] == buscado)
        {
          flag = 1;
          row = i;
          col = j;
          block = k;
        }
      }
    }
  }

  // Display position of the search Element
  if (flag == 1)
  {
    cout << "Su asiento: " << buscado << " se encuenta en "
         << "bloque[" << block << "] "
         << "fila[" << row << "] columna[" << col << "]" << endl;
    for (int k = position; k < position + 1; k++)
    {
      for (int i = 0; i < 10; i++)
      {
        for (int j = 0; j < 14; j++)
        {
          asientos[block][row][col] = asientos[block][row + 1][col + 1];
          asientos[block][row][col] = "N.D";
        }
      }
    }

    for (int k = position; k < position + 1; k++)
    {
      for (int i = 0; i < 10; i++)
      {
        for (int j = 0; j < 14; j++)
        {
          cout << " " << asientos[k][i][j] << " ";
        }
        cout << "\n";
      }
      cout << "\n";
    }
  }
  else
  {
    cout << "Asiento No valido" << endl;
  }

  return buscado;
}

// Escogemos un asiento de sala Mediana
string SalaMediana::escogerAsiento(int position)
{
  string buscado;
  for (int k = position; k < position + 1; k++)
  {
    for (int i = 0; i < 7; i++)
    {
      for (int j = 0; j < 8; j++)
      {
        cout << " " << asientos[k][i][j] << " ";
      }
      cout << "\n";
    }
  }
  cout << "Escoge un asiento" << endl;
  fflush(stdin);
  cin >> buscado;
  int flag = 0, row, col, block;

  for (int k = 0; k < 5; k++)
  {
    for (int i = 0; i < 7; i++)
    {
      for (int j = 0; j < 8; j++)
      {
        if (asientos[k][i][j] == buscado)
        {
          flag = 1;
          row = i;
          col = j;
          block = k;
        }
      }
    }
  }

  // Display position of the search Element
  if (flag == 1)
  {
    cout << "Su asiento: " << buscado << " se encuenta en "
         << "bloque[" << block << "]"
         << "fila[" << row << "] columna[" << col << "]" << endl;
    for (int k = 0; k < position; k++)
    {
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 8; j++)
        {
          asientos[block][row][col] = asientos[block][row + 1][col + 1];
          asientos[block][row][col] = "N.D";
        }
      }
    }

    for (int k = 0; k < position; k++)
    {
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 8; j++)
        {
          cout << " " << asientos[k][i][j] << " ";
        }
        cout << "\n";
      }
      cout << "\n";
    }
  }
  else
  {
    cout << "Asiento No valido" << endl;
  }

  return buscado;
}


// Mostramos asientos sala Mediana
void SalaMediana::mostrarAsientos(int position)
{
  for (int k = position; k < position + 1; k++)
  {
    for (int i = 0; i < 7; i++)
    {
      for (int j = 0; j < 8; j++)
      {
        cout << " " << asientos[k][i][j] << " ";
      }
      cout << "\n";
    }
  }
}

// Agregamos peliculas a la sala
void Sala::añadirPeliculas(Pelicula &pelicula)
{
  Pelicula nuevaPelicula; // Creamos una copia de pelicula para no dañar el objeto general de pelicula
  nuevaPelicula.setNombre(pelicula.getNombre());
  nuevaPelicula.setDirector(pelicula.getDirector());
  nuevaPelicula.setDuracion(pelicula.getDuracion());

  if (counterPeliculasSala < 5) // Validamos que haya espacio en la sala
  {
    if (counterPeliculasSala == 0) // Si es la primera pelicula de la sala se ejcuta esto...
    {
      string horarioPelicula;
      float horaInicio;
      float horafinal;
      cout << "A que hora empieza la pelicula?" << endl;
      fflush(stdin);
      cin >> horaInicio;

      if (horaInicio < 9.00 || horaInicio + nuevaPelicula.getDuracion() > 22.00 || horaInicio > 22.0) // Si la hora de es menor o mayor a la apertura, retorna error
      {
        cout << "Error: Hora no valida" << endl;
        return;
      }

      horafinal = nuevaPelicula.getDuracion() + horaInicio;

      string horaInicioStr = to_string(horaInicio); // Metodo usado para eliminar decimales de las horas
      string horafinalStr = to_string(horafinal);
      string horaInicioStrND = "hora";
      string horafinalStrND = "hora";

      horaInicioStrND[0] = horaInicioStr[0];
      horaInicioStrND[1] = horaInicioStr[1];
      horaInicioStrND[2] = horaInicioStr[2];
      horaInicioStrND[3] = horaInicioStr[3];

      horafinalStrND[0] = horafinalStr[0];
      horafinalStrND[1] = horafinalStr[1];
      horafinalStrND[2] = horafinalStr[2];
      horafinalStrND[3] = horafinalStr[3];

      string newhoraInicioStrND = conversionHoraMinutos(horaInicioStrND);
      string newhoraFinalStrND = conversionHoraMinutos(horafinalStrND);

      horarioPelicula = newhoraInicioStrND + " a " + newhoraFinalStrND; // Creamos el string de horario

      arrayHorarioString[counterHorarioString] = horarioPelicula; // Se agrega el horario al arreglo de horarios
      counterHorarioString++;                                     // Se incrementa en uno

      nuevaPelicula.setHorario(horarioPelicula);
      arrayPeliculaSala[counterPeliculasSala] = nuevaPelicula; // Se agrega la copia al objeto de Pelis en Sala
      counterPeliculasSala++;

      horario = horafinal;

      cout << "Pelicula Agrega a la sala exitosamente" << endl
           << endl;
    }
    else if (counterPeliculasSala > 0) // Si hay no es la primera pelicula que se agrega se ejecuta esto...
    {
      bool noEsIgual = false;
      for (size_t i = 0; i < counterPeliculasSala; i++)
      {
        if (arrayPeliculaSala[i].getNombre() != nuevaPelicula.getNombre() ||
            arrayPeliculaSala[i].getDirector() != nuevaPelicula.getDirector() ||
            arrayPeliculaSala[i].getDuracion() != nuevaPelicula.getDuracion())
        {
          noEsIgual = true;
        }
        else
        {
          noEsIgual = false;
        }
      }

      if (noEsIgual == false)
      {
        string horarioPelicula;
        float horaInicio;
        float horafinal;

        cout << "A que hora empieza la pelicula?" << endl;
        cin >> horaInicio;

        if (horaInicio < 9.00 || horaInicio + nuevaPelicula.getDuracion() > 22.0 || horaInicio > 22.0) // Si la hora de es menor o mayor a la apertura, retorna error
        {
          cout << "Error: Hora no valida" << endl;
          return;
        }

        if (horaInicio <= horario + 0.30)
        {
          cout << "La Sala neceista ser limpiada, prueba con otra hora" << endl;
          return;
        }

        horafinal = nuevaPelicula.getDuracion() + horaInicio;

        string horaInicioStr = to_string(horaInicio);
        string horafinalStr = to_string(horafinal);
        string horaInicioStrND = "hora";
        string horafinalStrND = "hora";

        horaInicioStrND[0] = horaInicioStr[0];
        horaInicioStrND[1] = horaInicioStr[1];
        horaInicioStrND[2] = horaInicioStr[2];
        horaInicioStrND[3] = horaInicioStr[3];

        horafinalStrND[0] = horafinalStr[0];
        horafinalStrND[1] = horafinalStr[1];
        horafinalStrND[2] = horafinalStr[2];
        horafinalStrND[3] = horafinalStr[3];

        string newhoraInicioStrND = conversionHoraMinutos(horaInicioStrND);
        string newhoraFinalStrND = conversionHoraMinutos(horafinalStrND);

        horarioPelicula = newhoraInicioStrND + " a " + newhoraFinalStrND; // Creamos el string de horario

        for (size_t i = 0; i < 5; i++)
        {
          if (arrayHorarioString[i] == horarioPelicula)
          {
            cout << "Error: Horario ya ocupado, pelicula no agregada" << endl;
            return;
          }
        }

        nuevaPelicula.setHorario(horarioPelicula);
        arrayPeliculaSala[counterPeliculasSala] = nuevaPelicula;
        arrayHorarioString[counterHorarioString] = horarioPelicula;
        counterHorarioString++;
        counterPeliculasSala++;
        horario = horafinal;

        cout << "Pelicula Agregada a la sala exitosamente" << endl
             << endl;
      }
      else
      {
        cout << "Error: No se pueden tener 2 peliculas diferentes en una Sala" << endl;
        return;
      }
    }
  }
  else
  {
    cout << "Error: Maximo limite de Peliculas por Sala Alcanzado" << endl;
    return;
  }
}

// Mostramos las peliculas del arreglo de x sala
void Sala::mostrarPelicula()
{
  cout << "N.-" << setw(15) << "Nombre" << setw(15) << "Director" << setw(15) << "Duracion" << setw(15) << "Horario" << endl;
  for (size_t i = 0; i < counterPeliculasSala; i++)
  {
    Pelicula &pelicula = arrayPeliculaSala[i];
    cout << i + 1 << setw(15) << pelicula.getNombre() << setw(15) << pelicula.getDirector() << setw(15) << pelicula.getDuracion() << setw(15) << pelicula.getHorario() << endl;
  }
}

Pelicula Sala::mostrarPeliEscogida(int position)
{
  Pelicula &pelicudaEscogida = arrayPeliculaSala[position];
  return pelicudaEscogida;
}

// FUNCIONES
string conversionHoraMinutos(string valorDeseado)
{
  string myString = valorDeseado;
  string newString = "ho";
  newString[0] = myString[3]; // h = 8
  newString[1] = myString[4]; // o = 9
  string condicionS = "S";
  condicionS[0] = myString[3];
  int condicion = stoi(condicionS);

  if (condicion >= 6)
  {
    int auxConversor, minutosSobrantes;
    string nuevaHora = "ec";
    nuevaHora[0] = myString[0];
    nuevaHora[1] = myString[1];

    auxConversor = stoi(newString);
    minutosSobrantes = auxConversor - 60;
    auxConversor = stoi(nuevaHora);
    nuevaHora = to_string(++auxConversor);

    myString[0] = nuevaHora[0];
    myString[1] = nuevaHora[1];
    newString = to_string(minutosSobrantes);
    myString[3] = newString[0];
    myString[4] = newString[1];
  }
  return myString;
}
