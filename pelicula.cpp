#include <iostream>
using namespace std;
#include "pelicula.hpp"


Pelicula::Pelicula()
{

}
//parametrizado
Pelicula::Pelicula(string nombre,string director, float duracionMinutos, string horario)
{
	this->nombre=nombre;
	this->director=director;
	this->duracionMinutos=duracionMinutos;
	this->horario = horario;
}

string Pelicula::toString()
{
	string cadena;  
    float duracion;
    string duracionStr;

    duracion = getDuracion();
    duracionStr = to_string(duracion);
	
	cadena = "";
	cadena+="Nombre: ";
	cadena+=getNombre();
	cadena+="Director: ";
	cadena+=getDirector();
    cadena+="Duracion:";
    cadena+= duracionStr;
	cadena+= getHorario();
	
		for(int i=0;i<6;i++)
		{
			cadena += "Funcion ";
			cadena += to_string(i+1);
			cadena += " ";
			cadena += "\n";		
		}
	
	return cadena;
}

void Pelicula::setHorario(string horario)
{
	this->horario = horario;
}

void Pelicula::setNombre(string nombre)
{
	this->nombre = nombre;
}

void Pelicula::setDirector(string director)
{
	this->director = director;
}

void Pelicula::setDuracion(float duracion)
{
	this->duracionMinutos = duracion;
}

string Pelicula::getDirector()
{
	return director;
}

float Pelicula::getDuracion() 
{
    return duracionMinutos;
}

string Pelicula::getNombre()
{
	return nombre;
}

string Pelicula::getHorario()
{
	return horario;
}

