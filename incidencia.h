/*
* incidencia.h
*
*  Created on: 29 nov. 2020
*      Author: Alberto Adamuz Priego
*/

#ifndef INCIDENCIA_H_
#define INCIDENCIA_H_
#include <iostream>
#include <string>

using namespace std;

struct Ubicacion
{
	float latitud;
	float longitud;
};

class Incidencia 
{
	private:
		int identificador_;
		string sendero_;
		string descripcion_;
		Ubicacion ubicacion_;

	public:
		Incidencia();
		int inline getIdentificador() const {return identificador_;}
		int inline setIdentificador(int identificador){identificador_==identificador;}
		string inline getSendero() const {return sendero_;}
		void inline setSendero(string sendero){sendero_=sendero;}
		string inline getDescripcion() const {return descripcion_;}
		void inline setDescripcion(string descripicion){descripcion_=descripicion;}
		Ubicacion inline getUbicacion() const {return ubicacion_;}
		void inline setUbicacion(Ubicacion ubicacion){ubicacion_=ubicacion;}  
		virtual ~Incidencia();
};

#endif /* INCIDENCIA_H_ */
