#ifndef PELICULA_HPP
#define PELICULA_HPP

#include <iostream>
using namespace std;

class Pelicula
{
	string nombre; //Nombre de la pelicula(titulo)
	string director; //Nombre del director
	float duracionMinutos;	//Duración de la película (minutos)
	string horario;
	
	public:
	//Constructores
		Pelicula();
		Pelicula(string nombre,string director, float duracionMinutos, string horario);
	//Métodos
		void setHorario(string);
		void setNombre(string);
		void setDirector(string);
		void setDuracion(float);
		string toString(); //Devuelve la información de la pelicula c/tipo: nombre,director,duracion
		string getNombre();
		string getDirector();
		string getHorario();
        float getDuracion();
};

#endif 
