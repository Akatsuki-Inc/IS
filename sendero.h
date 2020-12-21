#ifndef SENDERO_H
#define SENDERO_H
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Sendero{
private:
	string nombre_, descripcion_, dificultad_, disponibilidad_;
	float longitud_;
public:
	Sendero();

	inline string getNombre(){return nombre_;}

	void setNombre(string nombre){
		nombre_=nombre;
	}

	inline string getDescripcion(){return descripcion_;}

	void setDescripcion(string descripcion){
		descripcion_=descripcion;
	}

	inline string getDificultad(){return dificultad_;}

	void setDificultad(string dificultad){
		dificultad_=dificultad;
	}

	inline float getLongitud(){return longitud_;}

	void setLongitud(float longitud){
		longitud_=longitud;
	}

	inline string getDisponibilidad(){return disponibilidad_;}

	void setDisponibilidad(string disponibilidad){
		disponibilidad_=disponibilidad;
	}

	~Sendero();
};

#endif
