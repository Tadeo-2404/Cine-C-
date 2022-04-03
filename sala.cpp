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
  counterHoraFinal = 0;
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
    return 0;
  }

  return buscado;
}

// Reiniciamos asientos de sala
void SalaGrande::reiniciarAsientos(int position)
{
    string newAsientos[1][10][14] = {
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

    for (int k = 0; k < 5; k++)
    {
      for (int i = 0; i < 10; i++)
      {
        for (int j = 0; j < 14; j++)
        {
          asientos[position][i][j] = asientos[k][i][j];
        }
      }
    }
};

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

  for (int k = position; k < position + 1; k++)
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
         << "bloque[" << block << "] "
         << "fila[" << row << "] columna[" << col << "]" << endl;
    for (int k = position; k < position + 1; k++)
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
      cout << "\n";
    }
  }
  else
  {
    cout << "Asiento No valido" << endl;
    return 0;
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

// Reiniciamos asientos de sala
void SalaMediana::reiniciarAsientos(int position)
{
  string newAsientos[1][7][8] = {
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

    for (int k = 0; k < 5 ; k++)
    {
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 8; j++)
        {
          asientos[position][i][j] = newAsientos[1][i][j];
        }
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
      string horafinalStrND = "horas";

      horaInicioStrND[0] = horaInicioStr[0];
      horaInicioStrND[1] = horaInicioStr[1];
      horaInicioStrND[2] = horaInicioStr[2];
      horaInicioStrND[3] = horaInicioStr[3];

      if(horafinalStr.size() > 4) {
        horafinalStrND[0] = horafinalStr[0];
        horafinalStrND[1] = horafinalStr[1];
        horafinalStrND[2] = horafinalStr[2];
        horafinalStrND[3] = horafinalStr[3];
        horafinalStrND[4] = horafinalStr[4];
      } else {
        horafinalStrND[0] = horafinalStr[0];
        horafinalStrND[1] = horafinalStr[1];
        horafinalStrND[2] = horafinalStr[2];
        horafinalStrND[3] = horafinalStr[3];
      }

      string newhoraInicioStrND = conversionHoraMinutos(horaInicioStrND);
      string newhoraFinalStrND = conversionHoraMinutos(horafinalStrND);

      horarioPelicula = newhoraInicioStrND + " a " + newhoraFinalStrND; // Creamos el string de horario

      // arrayHoraFinal[counterHoraFinal] = horafinal;
      // counterHoraFinal++;

      // arrayHorarInicio[counterHoraInicio] = horaInicio;
      // counterHoraInicio++;

      arrayHorarioString[counterHorarioString] = horarioPelicula; // Se agrega el horario al arreglo de horarios
      counterHorarioString++;                                     // Se incrementa en uno

      nuevaPelicula.setHorario(horarioPelicula);
      arrayPeliculaSala[counterPeliculasSala] = nuevaPelicula; // Se agrega la copia al objeto de Pelis en Sala
      counterPeliculasSala++;

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

        horafinal = nuevaPelicula.getDuracion() + horaInicio;

        for (int i = 0; i < counterHoraFinal; i++)
        {
          if (horaInicio <= arrayHoraFinal[i] + 0.30 && horafinal + 0.30 >= arrayHorarInicio[i])
          {
            cout << "La Sala neceista ser limpiada, prueba con otra hora" << endl;
            return;
          }
        }

        string horaInicioStr = to_string(horaInicio);
        string horafinalStr = to_string(horafinal);
        string horaInicioStrND = "hora";
        string horafinalStrND = "horas";

      horaInicioStrND[0] = horaInicioStr[0];
      horaInicioStrND[1] = horaInicioStr[1];
      horaInicioStrND[2] = horaInicioStr[2];
      horaInicioStrND[3] = horaInicioStr[3];

      if(horafinalStr.size() > 4) {
        horafinalStrND[0] = horafinalStr[0];
        horafinalStrND[1] = horafinalStr[1];
        horafinalStrND[2] = horafinalStr[2];
        horafinalStrND[3] = horafinalStr[3];
        horafinalStrND[4] = horafinalStr[4];
      } else {
        horafinalStrND[0] = horafinalStr[0];
        horafinalStrND[1] = horafinalStr[1];
        horafinalStrND[2] = horafinalStr[2];
        horafinalStrND[3] = horafinalStr[3];
      }

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

        // arrayHoraFinal[counterHoraFinal] = horafinal;
        // counterHoraFinal++;

        // arrayHorarInicio[counterHoraInicio] = horaInicio;
        // counterHoraInicio++;

        arrayHorarioString[counterHorarioString] = horarioPelicula;
        counterHorarioString++;
        counterPeliculasSala++;

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

void Sala::eliminarPelicula(int posPelicula)
{
    if (posPelicula < counterPeliculasSala)
    {
      for (int x = posPelicula; x < counterPeliculasSala; x++)
      {
        arrayPeliculaSala[x] = arrayPeliculaSala[x + 1];
      }
      counterPeliculasSala--;
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
