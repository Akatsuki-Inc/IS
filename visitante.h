/*
 * visitante.h
 *
 *  Created on: 29 nov. 2020
 *      Author: Jose Manuel Flores Barranco
 */

#ifndef VISITANTE_H
#define VISITANTE_H
#include <iostream>
#include <string>

using namespace std;

class Visitante 
{
	private:
        string nombre_, DNI_, condiciones;
        int telefono;

	public:
		Visitante();

		inline string getNombre(){
            return nombre_;
        }
        inline void setNombre(string nombre){
            nombre_ = nombre;
        }
        
		inline string getDNI(){
            return nombre_;
        }
        inline void setDNI(string DNI){
            DNI_ = DNI;
        }

		inline int getTelefono(){
            return telefono_;
        }
        inline void setTelefono(int telefono){
            telefono_ = telefono;
        }

		inline string getFechaNacimiento(){
            return fechaNacimiento_;
        }
        inline void setFechaNacimiento(string fechaNacimiento){
            fechaNacimiento_ = fechaNacimiento;
        }

		inline string getCondiciones(){
            return condiciones_;
        }
        inline void setCondiciones(string condiciones){
            condiciones_ = condiciones;
        }

		virtual ~Visitante();
};

#endif VISITANTE_H