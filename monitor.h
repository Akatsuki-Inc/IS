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
#include <ctime>
#include "ruta.h"
#include "parque.h"

using namespace std;

class Monitor 
{
	private:
        string nombre_, DNI_, fechaNacimiento_, direccion_, correo_,
        parque_, contraseña_;
        int telefono_;
        list <Ruta> rutas_;
        list <Ruta>::iterator r_;

        bool buscarRuta(int identificador,Ruta &ruta);
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

		inline string getContraseña(){
            return contraseña_;
        }
        inline void setContraseña(string contraseña){
            contraseña_ = contraseña;
        }

        void crearRuta();

        void actualizarRuta(int identificador);

        bool cancelaRuta(int identificador);

        Incidencia crearIncidencia();

        string generarContraseña(int size);

        void añadirRuta(Ruta ruta){rutas_.push_back(ruta);}

		virtual ~Monitor();
};

#endif MONITOR_H
