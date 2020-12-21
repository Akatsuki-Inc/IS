/*
 * monitor.h
 *
 *  Created on: 29 nov. 2020
 *      Author: Jose Manuel Flores Barranco
 */
#ifndef MONITOR_H
#define MONITOR_H
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include "ruta.h"
#include "incidencia.h"

using namespace std;

class Monitor 
{
	private:
        list <Ruta> rutas_;
        list <Ruta>::iterator r_;
		string nombre_;
		string DNI_;
		string fechaNacimiento_;
		string direccion_, correo_;
		string parque_,contrasena_;
        int telefono_;
        
	public:
		Monitor();

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

   		inline string getFechaNacimiento(){
            return fechaNacimiento_;
        }
        inline void setFechaNacimiento(string fechaNacimiento){
            fechaNacimiento_ = fechaNacimiento;
        }

		inline int getTelefono(){
            return telefono_;
        }
        inline void setTelefono(int telefono){
            telefono_ = telefono;
        }

		inline string getDireccion(){
            return direccion_;
        }
        inline void setDireccion(string direccion){
            direccion_ = direccion;
        }

		inline string getCorreo(){
            return correo_;
        }
        inline void setCorreo(string correo){
            correo_ = correo;
        }

        inline list <Ruta> getRuta(){
            return rutas_;
        }

		inline string getParque(){
            return parque_;
        }
        inline void setParque(string parque){
            parque_ = parque;
        }

		inline string getContrasena(){
            return contrasena_;
        };
        inline void setContrasena(string contrasena){
            contrasena_ = contrasena;
        };

        void crearRuta();

        void actualizarRuta(int identificador);

        bool cancelaRuta(int identificador);

        Incidencia crearIncidencia();

        string generarContrasena(int size);

        void anadirRuta(Ruta ruta){rutas_.push_back(ruta);}

        bool buscarRuta(int identificador,Ruta &ruta);

		virtual ~Monitor();
};

#endif
